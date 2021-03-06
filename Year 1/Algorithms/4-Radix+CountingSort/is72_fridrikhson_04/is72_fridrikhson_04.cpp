#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void radixsort(int*, int, int);
void countingsort(int*, int, int);
int* GenerateArr(int, int);
int GetMax(int*, int);
int* ReadFile(char[100], int&, int&);
void WriteFile(int*, char[100], int);
int main()
{
	int *input;
	int n, d;
	char namei[100], nameo[100];
	//cout << "Input number of elements in array: ";
	//cin >> n;
	//cout << "Input number of digits in each element: ";
	//cin >> d;
	cout << "Input name of the input file: ";
	cin >> namei;
	input = ReadFile(namei, n, d);
	cout << "Before sorting: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << input[i] << endl;
	}
	radixsort(input, n, d);
	cout << "After sorting: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << input[i] << endl;
	}
	cout << "Input name of the output file: ";
	cin >> nameo;
	WriteFile(input, nameo, n);
	system("pause");
	return 0;
}
void radixsort(int *input, int n, int maxrank)
{
	int max = GetMax(input, n);
	int j = 1;
	for (int i = 0; i < maxrank; i++, j = j * 10)
	{
		countingsort(input, n, j);
	}
}
void countingsort(int *arr, int n, int rank)
{
	int values[10];
	int *temp = new int[n];
	for (int i = 0; i < 10; i++)
	{
		values[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		values[(arr[i] / rank) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		values[i] = values[i] + values[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		temp[values[(arr[i] / rank) % 10] - 1] = arr[i];
		values[(arr[i] / rank) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}
int* GenerateArr(int n, int d)
{
	int *arr = new int[n];
	int k = pow(10, d + 1), num;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % k;
	}
	return arr;
}
int GetMax(int* arr, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
void WriteFile(int* arr, char name[100], int n)
{
	FILE *file;
	fopen_s(&file, name, "w");
	char buff[100], str[100];
	for (int i = 0; i < n; i++)
	{
		_itoa_s(arr[i], str, 100, 10);
		fputs(str, file);
		fputc('\n', file);
	}
	fclose(file);
}
int* ReadFile(char name[100], int &n, int &d)
{
	FILE *file;
	fopen_s(&file, name, "r");
	char temp[500];
	char matr[500] = "";
	int count = 0, innercount = 0, *arr, i = 0;
	char delim[] = "\n ";
	char *next_token = NULL;
	fgets(temp, 100, file);
	char *p = strtok_s(temp, delim, &next_token);
	while (!feof(file))
	{
		if (count == 0)
		{
			while (innercount < 2)
			{

				if (innercount == 0)
					n = atoi(p);
				if (innercount == 1)
				{
					d = atoi(p);
					arr = new int[n];
				}
				p = strtok_s(NULL, delim, &next_token);
				innercount++;
			}
		}
		else
		{
			fgets(temp, 100, file);
			arr[i] = atoi(temp);
			i++;
		}
		count++;
	}
	return arr;
}