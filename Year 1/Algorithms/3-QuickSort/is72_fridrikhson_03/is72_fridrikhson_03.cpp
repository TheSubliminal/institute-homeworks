#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int counter = 0;
int part(int*, int, int);
void qsort1(int*, int, int);
void qsort2(int*, int, int);
void qsort3(int*, int, int);
int* readFile(FILE*, int&);
void writeFile(FILE*, int, int, int);
void printarr(int*, int);
void parttriple(int*, int, int, int&, int&, int&);
int partmed(int*, int, int);
int median(int, int, int);
int main()
{
	FILE* file;
	int* input;
	int n = 0, q1 = 0, q2 = 0, q3 = 0;
	fopen_s(&file, "input_06_100.txt", "r");
	input = readFile(file, n);
	int *arr1 = new int[n];
	int *arr2 = new int[n];
	int *arr3 = new int[n];
	fclose(file);
	for (int i = 0; i < n; i++)
	{
		arr1[i] = input[i];
		arr2[i] = input[i];
		arr3[i] = input[i];
	}
	cout << "Input array:" << endl;
	printarr(input, n);
	qsort1(arr1, 0, n-1);
	cout << "Output array:" << endl;
	printarr(arr1, n);
	q1 = counter;
	counter = 0;
	cout << "Comparisons for simple Qsort: ";
	cout << q1 << endl;
	qsort2(arr2, 0, n - 1);
	q2 = counter;
	counter = 0;
	cout << "Output array:" << endl;
	printarr(arr2, n);
	cout << "Comparisons for Qsort with median: ";
	cout << q2 << endl;
	qsort3(arr3, 0, n - 1);
	q3 = counter;
	cout << "Output array:" << endl;
	printarr(arr3, n);
	cout << "Comparisons for Qsort with 3 pivots: ";
	cout << q3 << endl;
	//fopen_s(&file, "output_01_10.txt", "w");
	//writeFile(file, q1, q2, q3);
	//fclose(file);
	system("pause");
    return 0;
}
void qsort1(int* arr, int p, int r)
{
	if (p < r)
	{
		int pi = part(arr, p, r);
		qsort1(arr, p, pi - 1);
		qsort1(arr, pi + 1, r);
	}
}
int part(int* arr, int p, int r)
{
	int pivot = arr[r];
	int i = p-1;
	for (int j = p; j <= r - 1; j++)
	{
		counter++;
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}
void qsort2(int* arr, int p, int r)
{
	if ((r - p) >= 3)
	{
		int pi = partmed(arr, p, r);
		qsort2(arr, p, pi - 1);
		qsort2(arr, pi + 1, r);
	}
	else
	{
		int pi = part(arr, p, r);
		qsort1(arr, p, pi - 1);
		qsort1(arr, pi + 1, r);
	}
}
int partmed(int* arr, int p, int r)
{
	int med = median(arr[p], arr[r], arr[(r + p) / 2]);
	if (med == arr[p])
		swap(arr[p], arr[r]);
	else if (med == arr[(r + p) / 2])
		swap(arr[(r + p) / 2], arr[r]);
	return part(arr, p, r);
}
void qsort3(int* arr, int p, int r)
{
	int pi1, pi2, pi3;
	if ((r - p) >= 3)
	{
		parttriple(arr, p, r, pi1, pi2, pi3);
		qsort3(arr, p, pi1-1);
		qsort3(arr, pi1 + 1, pi2 - 1);
		qsort3(arr, pi2 + 1, pi3 - 1);
		qsort3(arr, pi3 + 1, r);
	}
	else
	{
		int pi = part(arr, p, r);
		qsort1(arr, p, pi - 1);
		qsort1(arr, pi + 1, r);
	}
}
void parttriple(int* arr, int p, int r, int &pi1, int &pi2, int &pi3)
{
	int a = p + 2;
	int b = a;
	int c = r - 1;
	int d = c;
	int e1 = arr[p];
	int e2 = arr[p + 1];
	int e3 = arr[r];
	while (b <= c)
	{
		while (arr[b] < e2 && b <= c)
		{
			if (arr[b] < e1)
			{
				swap(arr[a], arr[b]);
				a++;
			}
			b++;
		}
		while (arr[c] > e2 && b <= c)
		{
			if (arr[c] > e3)
			{
				swap(arr[c], arr[d]);
				d--;
			}
			c--;
		}
		if (b <= c)
		{
			if (arr[b] > e3)
			{
				if (arr[c] < e1)
				{
					swap(arr[b], arr[a]);
					swap(arr[a], arr[c]);
					a++;
				}
				else
				{
					swap(arr[b], arr[c]);
				}
				swap(arr[c], arr[d]);
				b++;
				c--;
				d--;
			}
			else
			{
				if (arr[c] < e1)
				{
					swap(arr[b], arr[a]);
					swap(arr[a], arr[c]);
					a++;
				}
				else
				{
					swap(arr[b], arr[c]);
				}
				b++;
				c--;
			}
		}
	}
	a--;
	b--;
	c++;
	d++;
	swap(arr[p + 1], arr[a]);
	swap(arr[a], arr[b]);
	a--;
	swap(arr[p], arr[a]);
	swap(arr[r], arr[d]);
	pi1 = 1;
	pi2 = b;
	pi3 = d;
}
int* readFile(FILE* file, int &n)
{
	char str[100];
	fgets(str, 100, file);
	n = atoi(str);
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fgets(str, 100, file);
		arr[i] = atoi(str);
	}
	return arr;
}
void writeFile(FILE* file, int q1, int q2, int q3)
{
	char str[100];
	char result[30];
	_itoa_s(q1, str, 100, 10);
	strcat_s(result, str);
	strcat_s(result, " ");
	_itoa_s(q2, str, 100, 10);
	strcat_s(result, str);
	strcat_s(result, " ");
	_itoa_s(q3, str, 100, 10);
	strcat_s(result, str);
	fputs(result, file);
}
void printarr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl;
}
int median(int a, int b, int c)
{
	if (a > b)
	{
		if (c > a)
		{
			return a;
		}
		else
		{
			return (b > c) ? b : c;
		}
	}
	if (c > b)
	{
		return b;
	}
	else
	{
		return (a > c) ? a : c;
	}
}