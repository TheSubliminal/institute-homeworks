#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional> 
#include <iomanip>
#include <algorithm>
using namespace std;

int* ReadFile(char[100]);//зчитування інформації з файлу
void WriteFile(char[100], vector<pair<int, int>>, int, int);//запис інформації у файл
int** CreateMatr(int, int);//створення матриці
void FillMatr(int**, int, int, int);//заповнення матриці нульовими значеннями
vector<pair<int, int>> Kruskal(int**, int, int&);//алгоритм пошуку мінімального кістякового дерева
int findind(int, vector<vector<int>>);//пошук набору вершин в якому знаходиться задана вершина
int main()
{
	int n, val, *input, **city, totalcost = 0, totallength = 0;//коеф. N, вартість одного метру покриття, матриця суміжності міста,
	char namei[100], nameo[100];							   //кінцева вартість покриття і довжина шляху
	vector<pair<int, int>> resultedges;//дуги мінімального кістякового дерева
	cout << "Lab #10\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора та роботу
	cout << "Minimum spanning tree" << endl;
	system("pause");
	system("cls");
	cout << "Input name of the input file: ";
	cin >> namei;
	input = ReadFile(namei);//зчитування інформації з файлу
	n = input[0];
	val = input[1];
	cout << "Coefficient \"n\": " << n << " Cost of asphalt per meter: " << val << endl;//виведення інформації
	city = CreateMatr(pow(n + 1, 2), pow(n + 1, 2));//створення матриці суміжності
	FillMatr(city, pow(n + 1, 2), n + 1, val*100);//заповнення матриці суміжності
	resultedges = Kruskal(city, pow(n + 1, 2), totalcost);//пошук мінімального кістякового дерева
	cout << "Asphalted quarters:" << endl;
	for (unsigned int i = 0; i < resultedges.size(); i++)//виведення отриманих дуг графу
	{
		cout << resultedges[i].first+1 << "-" << resultedges[i].second+1 << endl;
	}
	totallength = 100 * resultedges.size();//визначення загальної довжини покриття
	cout << "Total lenght of asphalted quarters:" << endl;//виведення інформації
	cout << totallength << endl;
	cout << "Total minimal cost for the work:" << endl;
	cout << totalcost << endl;
	cout << "Input name of the output file: ";
	cin >> nameo;
	WriteFile(nameo, resultedges, totallength, totalcost);//запис інформації у файл
	system("pause");
	return 0;
}
int* ReadFile(char name[100])//зчитування інформації з файлу
{
	FILE *file;//покажчик на файл
	int result[2];//масив для отриманих значень
	char str[100];//зчитуваний рядок
	fopen_s(&file, name, "r");//відкриття файлу
	fgets(str, 100, file);//зчитування першого рядку файлу
	result[0] = atoi(str);//запис у масив
	fgets(str, 100, file);//зчитування другого рядку файлу
	result[1] = atoi(str);//запис у масив
	fclose(file);//закриття файлу
	return result;
}
vector<pair<int, int>> Kruskal(int **graph, int n, int &sum)//алгоритм пошуку мінімального кістякового дерева
{
	vector<pair<int, pair<int, int>>> edges;//вектор значень усіх дуг та самі дуги
	vector<vector<int>> sets;//вектор наборів вершин
	vector<pair<int, int>> resultedges;//отримані дуги
	int setind1, setind2;//індекси наборів вершин
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)//заповнення вектору дуг
		{
			if (graph[i][j] != 0)
				edges.push_back({ graph[i][j], {i,j} });
		}
	}
	sort(edges.rbegin(), edges.rend(), greater<pair<int, pair<int, int>>>());//сортування вектора ребер
	for (unsigned int i = 0; i < edges.size(); i++)//прохід по всім дугам графу
	{
		setind1 = findind(edges[i].second.first, sets);//пошук індексів наборів вершин, у яких знаходяться вершини ребра
		setind2 = findind(edges[i].second.second, sets);
		if (setind1 == -1 && setind2 == -1)//якщо вони не знаходяться в жодному наборі
		{
			sets.push_back({edges[i].second.first, edges[i].second.second});//тоді створити новий
			sum += edges[i].first;//додати вартість до загальної
			resultedges.push_back(edges[i].second);//додати ребро до відповіді
		}
		else if (setind1 != -1 && setind2 == -1)//якщо перша вершина дуги знаходиться у наборі
		{
			sets[setind1].push_back(edges[i].second.second);//тоді додати до цього набор другу
			sum += edges[i].first;
			resultedges.push_back(edges[i].second);
		}
		else if (setind2 != -1 && setind1 == -1)//якщо друга знаходиться у наборі
		{
			sets[setind2].push_back(edges[i].second.first);//тоді першу
			sum += edges[i].first;
			resultedges.push_back(edges[i].second);
		}
		else if (setind1 != setind2 && setind1 != -1 && setind2 != -1)//якщо вершини знаходяться в різних наборах
		{
			for (unsigned int i = 0; i < sets[setind2].size(); i++)//тоді додати другий набір вершин до першого
			{
				sets[setind1].push_back(sets[setind2][i]);
			}
			sets.erase(sets.begin() + setind2);//видалити другий набір
			sum += edges[i].first;
			resultedges.push_back(edges[i].second);
		}
		else if (setind1 == setind2)//якщо обидві вершини знаходяться в одному наборі
		{
			continue;//тоді продовжити перебіпр вершин
		}
	}
	return resultedges;//пеоврнути набір дуг мінімального кістякового дерева
}
int findind(int node, vector<vector<int>> sets)//пошук індекса набору, в якму знаходиться задана вершина
{
	for (unsigned int i = 0; i < sets.size(); i++)
	{
		for (unsigned int j = 0; j < sets[i].size(); j++)
		{
			if (sets[i][j] == node || sets[i][j] == node)//якщо вершину знайдено
			{
				return i;//тоді повернути індекс набору
			}
		}
	}
	return -1;//якщо не знайдено, тоді повернути -1
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
void FillMatr(int** matr, int n, int m, int valueperedge) //заповнення матриці нульовими значеннями
{
	int counter = 0;//лічильник
	for (int i = 0; i < n; i++)//заповнення матриці нулями
	{
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (!(i + m > n - 1))//якщо вершина не кутова
		{
			if (counter == m - 1)//якщо вершина бічна
			{
				matr[i][i + m] = valueperedge;
				matr[i + m][i] = valueperedge;
				counter = 0;
			}
			else
			{
				matr[i][i + 1] = valueperedge;
				matr[i + 1][i] = valueperedge;
				matr[i][i + m] = valueperedge;
				matr[i + m][i] = valueperedge;
				counter++;
			}
		}
		else
		{
			matr[i][i + 1] = valueperedge;
			matr[i + 1][i] = valueperedge;
			counter++;
		}
		
	}
}
void WriteFile(char name[100], vector<pair<int, int>> resultedges, int totallength, int totalcost)
{
	FILE *file;//покажчик на файл
	char str[300], buff[100];//зчитаний рядок та буфер для функції itoa()
	fopen_s(&file, name, "w");//відкриття файлу для запису
	fputs("Total lenght of asphalted quarters : ", file);//запис довжини покриття
	_itoa_s(totallength, buff, 20, 10);
	fputs(buff, file);
	fputc('\n',file);
	fputs("Total minimal cost for the work : ", file);//запис вартості покриття
	_itoa_s(totalcost, buff, 20, 10);
	fputs(buff, file);
	fputs("\nAsphalted quarters:\n", file);
	for (unsigned int i = 0; i < resultedges.size(); i++)//запис ребер графу, покритих асфальтом
	{
		_itoa_s(resultedges[i].first + 1, str, 20, 10);
		strcat_s(str, " - ");
		_itoa_s(resultedges[i].second + 1, buff, 20, 10);
		strcat_s(str, buff);
		strcat_s(str, "\n");
		fputs(str, file);
	}
	fclose(file);//закриття файлу
}