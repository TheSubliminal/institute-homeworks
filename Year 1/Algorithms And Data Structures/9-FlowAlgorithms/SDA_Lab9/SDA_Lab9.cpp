#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;

int** throughput;
int** ReadFile(char[100], int&, int&, int&, int&);//зчитування файла
void PrintData(int**, int, int);//вивід інформації
void WriteFile(char[100], int*);//запис результатів у файл
int** CreateMatr(int, int);//створення матриці
void FindPaths(int, int, int&, map<int, vector<int>>&, map<int, vector<int>>&, vector<int> path);//пошук усіх шляхів від однієї вершини до іншої
int* MaxStud(int, int, int**, int**, int);//пошук максимальної к-сті студентів за вартості навчання, що не перевищює 1000$
void FillMatr(int**, int, int);//заповнення матриці нульовими значеннями
int main()
{
	int **costs, n, m, s, t, *result;//матриця вартостей навчання, к-сті підкурсів, початкова та кінцева вершина графа, результати пошуку
	char namei[100], nameo[100];//назва вхідного файлу
	cout << "Lab #9\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора та роботу
	cout << "Flows" << endl;
	system("pause");
	system("cls");
	cout << "Input name of the input file: ";//введення назви вхідного файлу
	cin >> namei;
	costs = ReadFile(namei, n, m, s, t);//зчитування інформації
	cout << "Adjacency matrix of costs per student" << endl;//виведення інформації про вартість
	PrintData(costs, n, n);
	cout << "Max number of students in group" << endl;//к-сть студентів
	PrintData(throughput, n, n);
	result = MaxStud(s, t, costs, throughput, n);//пошук максимальної к-сті студентів за вартості навчання, що не перевищює 1000$
	cout << "Max students " << result[0] << " For cost of " << result[1] << "$" << endl;//виведення результатів
	cout << "Input name of the output file: ";//введення назви вихідного файлу
	cin >> nameo;
	WriteFile(nameo, result);//запис у файл відповіді
	system("pause");
    return 0;
}
void FindPaths(int s, int t,int &i, map<int, vector<int>> &graph, map<int, vector<int>> &paths, vector<int> path)
{
	path.push_back(s);//додавання поточного вузла до шляху
	if (s == t)//якщо ми знаходимось у кінцевій вершині
	{
		paths.insert(pair<int, vector<int>>(i,path));//додавання отриманого шляху до інших
		i++;//перехід до наступного шляху
		return;
	}
	/*if (graph[s].empty())//якщо шлях не знайдено, тоді рекурсивно продовжуємо пошук в суміжних вузлах
	{
		return;
	}*/
	for (auto subnode : graph[s])//рекурсивний пошук шляху у всіх суміжних вершинах поточного вузла
	{
		FindPaths(subnode, t, i, graph, paths, path);
	}
	return;
}
int* MaxStud(int s, int t, int** costs, int** throughput, int n)
{
	map<int, vector<int>> graph;//списки суміжних вершин
	map<int, vector<int>> paths;//отримані шляхи
	int* curflow = new int[n];//поточна к-сть студентів
	vector<int> path, best;//змінна для поточного шляху
	int i = 0, j = 0, fullcost = 0, maxflow = 0, value;//лічильники, повна вартість навчання, максимальна к-сть студентів, вартість навчання
	int *result = new int[2];//змінна для результату
	for (int i = 0; i < n; i++)
	{
		curflow[i] = 0;
		for (int j = 0; j < n; j++)//заповнення списків суміжних вершин для кожної вершини
		{
			if (costs[i][j] > 0)
			{
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (throughput[s - 1][i] > curflow[s - 1])
		{
			curflow[s - 1] = throughput[s - 1][i];//визначення максимального початкового потоку студентів
		}
	}
	FindPaths(s - 1, t - 1, i, graph, paths, path);//пошук усіх шляхів на графі від вершини s до вершини t
	for (const auto &kvp : paths)//пошук максимальної к-сті студентів, які пройдуть курс навчання за вартістю < 1000$
	{
		i = s - 1;//встановлення початкової вершини
		for (auto v : kvp.second)//прохід по всім отриманим шляхам
		{
			j = v;//отримання наступної вершини
			fullcost += costs[i][j];//додавання до загальної вартості курсу
			if (throughput[i][j] >= curflow[i])//визначити поточну к-сть студентів для поточного етапу
			{
				curflow[j] = curflow[i];//якщо макс к-сть студентів для наступного етапу курсу більша за поточну,
			}								   //тоді всі студенту проходять далі
			else if ( j!= s - 1)
			{
				curflow[j] = throughput[i][j];//якщо ні, тоді тільки максимальна для заданого етапу
			}
			i = j;//перемістити вершину на наступну
		}
		if (fullcost < 1000 && curflow[t - 1] > maxflow)//якщо вартість курсу не перевищує 1000 та к-сть студентів, 
		{												//що може його пройти більша за визаену максимальну
			maxflow = curflow[t - 1];//визначити цю к-сть максимальної
			value = fullcost;//визначити вартість даного курсу
			best = kvp.second;
		}
		fullcost = 0;//обнулити усі значення 
		for (int i = 0; i < n; i++)
		{
			curflow[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			if (throughput[s - 1][i] > curflow[s - 1])
			{
				curflow[s - 1] = throughput[s - 1][i];//визначення максимального початкового потоку студентів
			}
		}
	}
	/*cout << "Selected path" << endl;
	for (auto v : best)
	{
		cout << v + 1 << " ";
	}
	cout << endl;*/
	result[0] = maxflow;//записати результат
	result[1] = value;
	return result;
}
int** ReadFile(char name[100], int &n, int &m, int &s, int &t)
{
	FILE *file;//покажчик на файл
	int count = 0, innercount = 0, **cost, a, b, students, value; //покажчики на символи у файлі, лічильник індексу символа, матриця суміжності, допоміжні змінні для данних
	char delim[] = "\n ", str[100];//роздільники та зчитуваний рядок
	char *next_token = NULL, *p;//покажчик на наступне число, поточне число
	fopen_s(&file, name, "r");//відкриття файлу
	fgets(str, 100, file);//зчитує перший рядок файлу
	p = strtok_s(str, delim, &next_token); //покажчик на числа
	while (!feof(file)) //зчитування інформації з файлу
	{
		if (count == 0)//якщо це перший рядок файлу
		{
			while (innercount < 4)
			{
				if (innercount == 0)//якщо перше число рядка
				{
					n = atoi(p);//визначити його як к-сть етапів
				}
				if (innercount == 1)//якщо друге
				{
					m = atoi(p);//як к-сть ребер графу
				}
				if (innercount == 2)//якщо третє
				{
					s = atoi(p);//як початкову вершину
				}
				if (innercount == 3)//якщо четверте
				{
					t = atoi(p);//як кінцеву вершину
				}
				p = strtok_s(NULL, delim, &next_token);//перейти до наступного числа
				innercount++;//збільшити лічильник
			}
			cost = CreateMatr(n, n);//створити матрицю суміжності за заданими розмірами
			throughput = CreateMatr(n, n);//створити матрицю пропускних здатностей
			FillMatr(cost, n, n);//заповинити їх нульовими значеннями
			FillMatr(throughput, n, n);
		}
		else
		{
			innercount = 0;//обнулити лічильник
			fgets(str, 100, file);//зчитати рядок файлу
			p = strtok_s(str, delim, &next_token);//розділити його на числа
			while (innercount < 4)
			{
				if (innercount == 0)//якщо це перше число рядка
				{
					a = atoi(p);//визначити його як першу вершину
				}
				if (innercount == 1)//якщо друге
				{
					b = atoi(p);//як другу вершину
				}
				if (innercount == 2)//якщо третє
				{
					students = atoi(p);//як макс к-сть студентів
				}
				if (innercount == 3)//якщо четверте
				{
					value = atoi(p);//як вартість етапу
					cost[a - 1][b - 1] = value;//записати дані у матрицю суміжності
					throughput[a - 1][b - 1] = students;//та у матрицю пропускних здатностей
				}
				p = strtok_s(NULL, delim, &next_token);//перейти до наступного числа
				innercount++;//збільшити лічильник
			}
		}
		count++;//збільшити лічильник
	}
	fclose(file);//закрити файл
	return cost;//повернути матрицю суміжності
}
void WriteFile(char name[100], int* result)
{
	FILE *file;//покажчик на файл
	char str[100], buff[100];//зчитаний рядок та буфер для функції itoa()
	fopen_s(&file, name, "w");//відкриття файлу для запису
	_itoa_s(result[0], str, 20, 10);//конвертація першого числа у символьний тип
	strcat_s(str, " ");
	_itoa_s(result[1], buff, 20, 10);//конвертація другого числа у символьний тип
	strcat_s(str, buff);//додавання другого числа до рядка
	strcat_s(str, "\n");
	fputs(str, file);//запис у файл
	fclose(file);//закриття файлу
}
int** CreateMatr(int n, int m) //створення матриці
{
	int **matr = new int*[n];//виділити пам'ять під двомірний масив
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];//виділити пам'ять під кожен елемент
	}
	return matr;
}
void FillMatr(int** matr, int n, int m) //заповнення матриці нульовими значеннями
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = 0;//записати 0
		}
	}
}
void PrintData(int** data, int n, int m) //виведення матриці
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(5) << data[i][j];//форматоване виведення даних
		}
		cout << endl;
	}
}