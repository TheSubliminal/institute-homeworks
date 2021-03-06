#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int* readFile(FILE*, int);
void writeFile(FILE*, int*, int);
int* sort(int*, int);
void printarr(int*, int);
int main()
{
	FILE *input, *output; //вказівники на вхідний та вихідний файли
	int n; //к-сть елементів масиву
	int *arr, *res;
	char namei[20], nameo[20], num[20];
	cout << "Input name of the input file: ";
	cin >> namei;
	fopen_s(&input, namei, "r"); //відкриття вхідного файлу
	fgets(num, 20, input); //зчитування першого рядка з к-стю елементів
	n = atoi(num); 
	arr = readFile(input, n);//зчитування вхідного масиву
	fclose(input);
	printarr(arr, n);
	cout << "Sorted array: " << endl;
	res = sort(arr, n);//сортування вхідного масиву
	printarr(res, n);
	cout << "Input name of the output file: ";
	cin >> nameo;
	fopen_s(&output, nameo, "w"); //відкриття вихідного файлу
	writeFile(output, res, n); //запис відсортованого масиву у файл
	fclose(output);
	system("pause");
	return 0;
}
void printarr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl;
}
int* sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] % 2 == 0)
			{
				if (arr[j - 1] % 2 != 0)//якщо число парне і перед ним знаходиться непарне, то поміняти місцями
					swap(arr[j - 1], arr[j]);
				else if (arr[j - 1] > arr[j])//якщо перед ним парне - порівняти
					swap(arr[j - 1], arr[j]);
			}
			else
			{
				if (arr[j - 1] < arr[j] && arr[j - 1] % 2 != 0) //якщо перед непарним числом знаходиться непрарне, то порівняти
					swap(arr[j - 1], arr[j]);
			}
		}
	}
	return arr;
}
int* readFile(FILE* file, int n)
{
	char str[100];
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fgets(str, 100, file);
		arr[i] = atoi(str);
	}
	return arr;
}
void writeFile(FILE* file, int* arr, int n)
{
	char str[100];
	for (int i = 0; i < n; i++)
	{
		_itoa_s(arr[i], str, 100, 10);
		fputs(str, file);
		fputc('\n', file);
	}
}
