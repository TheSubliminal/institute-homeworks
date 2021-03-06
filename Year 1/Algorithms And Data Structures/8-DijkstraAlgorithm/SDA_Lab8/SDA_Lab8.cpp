#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int** ReadFile(char[100], int&, int&, int&);//зчитування данних з файлу
void WriteFile(char[100], int**, int);//запис результатів у файл
int** CreateMatr(int, int);//створення матриці
void PrintData(int**, int, int);//виведення данних
void FillMatr(int**, int, int);//заповнення матриці нульовими значеннями
void SortResult(int**, int);//сортування результатів за зростанням
int** Dijkstra(int**, int, int, int, int&);//алгоритм пошуку найкоротших шляхів
int main()
{
	int **data, **result, n, m, c, num = 0;//матриці вхідних та вихідних данних, к-сть міст, доріг, номер столиці, к-сть вихідних данних
	char namei[100], nameo[100];//назви вхідного та вихідного файлів
	cout << "Lab #8\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора та роботу
	cout << "Paths" << endl;
	system("pause");
	system("cls");
	cout << "Please, enter the name of the input file: ";//введення назви вхідного файлу
	cin >> namei;
	data = ReadFile(namei, n, m, c);//запис данних у матрицю суміжності
	cout << "Adjacency matrix" << endl;//друк матриці
	PrintData(data, n, n);
	result = Dijkstra(data, n, m, c, num);//пошук найкоротших шляхів
	SortResult(result, num);//сортування результатів за збільшенням часу на дорогу
	cout << "Result of the algorithm" << endl;//друк результатів
	PrintData(result, num, 2);
	cout << "Please, enter the name of the output file: ";//введення назви вихідного файлу
	cin >> nameo;
	WriteFile(nameo, result, num);//запис файлу
	system("pause");
	return 0;
}
void SortResult(int** matr, int n)//сортування результатів за зростанням
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (matr[i][1] > matr[j][1])//якщо і-ий елемент більше за j-ий 
			{
				swap(matr[i][1], matr[j][1]);//поміняти місцями час на дорогу
				swap(matr[i][0], matr[j][0]);//та номери міст
			}
		}
	}
}
int** Dijkstra(int** data, int n, int m, int c, int &num)//алгоритм пошуку найкоротших шляхів
{
	int* dist = new int[n];//масив відстаней
	int **result = CreateMatr(n - 1, 2);//матриця результатів
	bool* visited = new bool[n];//масив в якому записуються відвідані міста
	int current = c - 1, minid, counter = 0, disconected;//номер поточного міста, індекс міста з мінімальною відстанню, номер недосяжного міста
	bool flag = true;//перевірка на связність міст
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data[i][j] == 0)//якщо місто не має зв'язку з одним із міст
				counter++;//збільшити лічильник
		}
		if (counter == n)//якщо лічильник дорівнює к-сті міст
		{
			disconected = i + 1;//вказати номер недосяжного міста
			flag = false;//вказати що міста не зв'язні
			break;//зупинити подальшу перевірку
		}
		else
		{
			counter = 0;//обнулити лічильник
		}
	}
	if (flag == true)//якщо всі міста зв'язні
	{
		for (int i = 0; i < n; i++)//заповнення масива відстаней до міст максимальним значеннями
		{
			if (i != current)//якщо поточне місто не є столицею
			{
				dist[i] = INT_MAX;//встановити відстань до нього максимально великою
			}
			else
			{
				dist[i] = 0;//якщо місто - столиця, то встановити нульову відстань
			}
			visited[i] = false;//вказати, що всі міста не відвідані
		}
		for (int i = 0; i < n; i++)//для кожного міста
		{
			int min = INT_MAX;
			for (int k = 0; k < n; k++)
			{
				if (visited[k] != true && dist[k] < min)//якщо місто не відвідане і відстань до нього менше за мінімальну визначену
				{
					minid = k;//вказати номер міста
					min = dist[k];//встановити цю відстань мінімальною
				}
			}
			visited[minid] = true;//вказати, що це місто відвідане
			for (int j = 0; j < n; j++)
			{
				if (visited[j] != true && dist[minid] + data[minid][j] < dist[j] && data[minid][j] != 0)//якщо сусіднє місто не відвідане і сума значення найближчого міста та відстані
				{																						//до найближчого менша за значення поточного міста та існує зв'язок з сусіднім містом
					dist[j] = data[minid][j] + dist[minid];//тоді встановити значення поточного міста як суму відстані до найближчого міста та значення найближчого
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i != c - 1 && dist[i] != INT_MAX)//якщо місто не є столицею
			{
				result[num][0] = i + 1;//записати його номер та мінімальну відстань до нього у результат
				result[num][1] = dist[i];
				num++;//перейти до наступного елемента
			}
		}
		return result;
	}
	else
	{
		cout << "City " << disconected << " is disconected from others" << endl;//вказати номер недосяжного міста
		system("pause");
		exit(0);//вийти з програми
	}
}
int** ReadFile(char name[100], int &n, int &m, int &c)
{
	FILE *file;//покажчик на файл
	int count = 0, innercount = 0, **data, a, b, l; //покажчики на символи у файлі, лічильник індексу символа, матриця суміжності, допоміжні змінні для данних
	char delim[] = "\n ", str[100];//роздільники та зчитуваний рядок
	char *next_token = NULL, *p;//покажчик на наступне число, поточне число
	fopen_s(&file, name, "r");//відкриття файлу
	fgets(str, 100, file);//зчитує перший рядок файлу
	p = strtok_s(str, delim, &next_token); //покажчик на числа
	while (!feof(file)) //зчитування інформації з файлу
	{
		if (count == 0)//якщо це перший рядок файлу
		{
			while (innercount < 3)
			{
				if (innercount == 0)//якщо перше число рядка
				{
					n = atoi(p);//визначити його як к-сть міст
				}
				if (innercount == 1)//якщо друге
				{
					m = atoi(p);//як к-сть доріг
				}
				if (innercount == 2)//якщо третє
				{
					c = atoi(p);//як номер столиці
				}
				p = strtok_s(NULL, delim, &next_token);//перейти до наступного числа
				innercount++;//збільшити лічильник
			}
			data = CreateMatr(n, n);//створити матрицю суміжності за заданими розмірами
			FillMatr(data, n, n);//заповинити її нульовими значеннями
		}
		else
		{
			innercount = 0;//обнулити лічильник
			fgets(str, 100, file);//зчитати рядок файлу
			p = strtok_s(str, delim, &next_token);//розділити його на числа
			while (innercount < 3)
			{
				if (innercount == 0)//якщо це перше число рядка
				{
					a = atoi(p);//визначити його як перше місто
				}
				if (innercount == 1)//якщо друге
				{
					b = atoi(p);//як друге місто
				}
				if (innercount == 2)//якщо третє
				{
					l = atoi(p);//як відстань між містами
					data[a - 1][b - 1] = l;//записати дані у матрицю суміжності
					data[b - 1][a - 1] = l;
				}
				p = strtok_s(NULL, delim, &next_token);//перейти до наступного числа
				innercount++;//збільшити лічильник
			}
		}
		count++;//збільшити лічильник
	}
	fclose(file);//закрити файл
	return data;//повернути матрицю суміжності
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
			cout << data[i][j] << " ";//форматоване виведення даних
		}
		cout << endl;
	}
}
void WriteFile(char name[100], int** result, int n)
{
	FILE *file;//покажчик на файл
	char str[100], buff[100];//зчитаний рядок та буфер для функції itoa()
	fopen_s(&file, name, "w");//відкриття файлу для запису
	for (int i = 0; i < n; i++)
	{
		_itoa_s(result[i][0], str, 20, 10);//конвертація першого числа у символьний тип
		strcat_s(str, " ");
		_itoa_s(result[i][1], buff, 20, 10);//конвертація другого числа у символьний тип
		strcat_s(str, buff);//додавання другого числа до рядка
		strcat_s(str, "\n");
		fputs(str, file);//запис у файл
	}
	fclose(file);//закриття файлу
}