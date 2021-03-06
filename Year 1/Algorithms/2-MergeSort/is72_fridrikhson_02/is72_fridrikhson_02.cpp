// is72_fridrikhson_02.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int users, films;
int** SortSimilar(int**, int, int, int, int ,int);
int** ReadFile(char[100]);
void WriteFile(int**, int, char[100], int , int);
void PrintFile(char[100]);
int** CreateMatr(int, int);
int CountInv(int*, int);
int SortAndCount(int*, int*, int, int);
int MergeAndCount(int*, int*, int, int, int);
void SortMatr(int**, int);


int main()
{
	int k = 5 / 2;
	char namei[100], nameo[100];
	int** input;
	int userid;
	cout << "Write the name of the input file: " << endl;
	cin >> namei;
	PrintFile(namei);
	input = ReadFile(namei);
	cout << "Input the number of user to count inversions: ";
	cin >> userid;
	strcpy_s(nameo,"is72_fridrikhson_02_output.txt");
	WriteFile(input, userid-1, nameo, users, films);
	system("pause");
    return 0;
}
int** ReadFile(char name[100])
{
	FILE *file;
	fopen_s(&file, name, "r");
	char temp[500];
	char matr[500] = "";
	int count = 0, innercount = 0; 
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
					users = atoi(p);
				if (innercount == 1)
				{
					films = atoi(p);
				}
				p = strtok_s(NULL, delim, &next_token);
				innercount++;
			}
		}
		else
		{
			fgets(temp, 100, file);
			strcat_s(matr, 500, temp);
		}
		count++;
	}
	p = NULL;
	next_token = NULL;
	p = strtok_s(matr, delim, &next_token); 
	int **arr = CreateMatr(users, films); 
	for (int i = 0; i < users; i++) 
	{
		count = 0;
		for (int j = 0; j < films+1; j++)
		{
			if (count > 0)
			{
				arr[i][j-1] = atoi(p);
			}
			count++;
			p = strtok_s(NULL, delim, &next_token);
		}
	}
	fclose(file);
	return arr;
}
void WriteFile(int** matr, int userid, char name[100], int users, int films)
{
	FILE *file;
	int **res;
	char useridc[20], matrc[20];
	fopen_s(&file, name, "w");
	res = CreateMatr(users, 2);
	res = SortSimilar(matr, users, films, userid, users, films);
	_itoa_s(userid+1, useridc, 20, 10);
	fputs(useridc, file);
	fputc('\n', file);
	for (int i = 0; i < users-1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			_itoa_s(res[i][j], matrc, 20, 10);
			fputs(matrc, file);
			fputs(" ", file);
		}
		if (i != users - 1)
			fputc('\n', file);
	}
	fclose(file);
}
int** SortSimilar(int** matr, int n, int m, int userid, int users, int films)
{
	int* arr = new int[films];
	int** res;
	res = CreateMatr(users-1, 2);
	int countinv = 0;
	for (int i = 0; i < n; i++)
	{
		countinv = 0;
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (matr[userid][k] == matr[i][j])
				{
					arr[j] = k + 1;
					break;
				}
			}
		}
		countinv = CountInv(arr, films);
		if (i != userid)
		{
			if (i > userid)
			{
				res[i - 1][0] = i + 1;
				res[i - 1][1] = countinv;
				cout << res[i - 1][0] << " " << res[i - 1][1] << endl;
			}
			else {
				res[i][0] = i + 1;
				res[i][1] = countinv;
				cout << res[i][0] << " " << res[i][1] << endl;
			}

		}
		
	}
	SortMatr(res, users-1);
	cout << endl;
	for (int i = 0; i < users-1; i++)
	{
		cout << res[i][0] << " " << res[i][1] << endl;
	}
	return res;
}
int** CreateMatr(int n, int m) 
{
	int **matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
	}
	return matr;
}
void PrintFile(char name[100])
{
	FILE *file;
	fopen_s(&file, name, "r");
	char row[100]; 
	while (!feof(file))
	{
		fgets(row, 100, file);
		cout << row;
	}
	cout << endl;
	fclose(file);
}
void SortMatr(int** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (matr[i][1] > matr[j][1])
			{
				swap(matr[i][1], matr[j][1]);
				swap(matr[i][0], matr[j][0]);
			}
		}
	}
}
int CountInv(int* arr, int length)
{
	int *temp = new int[length];
	return SortAndCount(arr, temp, 0, length - 1);
}
int SortAndCount(int* arr, int* temp, int l, int r)
{
	int m, inv_count = 0;
	if (r > l)
	{
		m = (r + l) / 2;
		inv_count = SortAndCount(arr, temp, l, m);
		inv_count += SortAndCount(arr, temp, m + 1, r);
		inv_count += MergeAndCount(arr, temp, l, m + 1, r);
	}
	return inv_count;
}
int MergeAndCount(int* arr, int* temp, int l, int m, int r)
{
	int i, j, k, inv_count = 0;
	i = l; 
	j = m;
	k = l;
	while ((i <= m - 1) && (j <= r))
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i]; 
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
			inv_count += (m - i);
		}
	}
	while (i <= m - 1)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= r)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	for (i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
	return inv_count;
}
