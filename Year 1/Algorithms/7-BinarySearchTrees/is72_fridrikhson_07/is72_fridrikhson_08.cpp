#include "stdafx.h"
#include <iostream>
using namespace std;

int MaxValue(int**, int, int);
int** ReadFile(char[100], int&, int&);
void WriteFile(char[100], int);
int max(int, int);
int main()
{
	int W, n, **input, result;
	char namei[100], nameo[100];
	strcpy_s(nameo, "is72_fridrikhson_08_output.txt");
	cout << "Input name of the input file: ";
	cin >> namei;
	input = ReadFile(namei, W, n);
	cout << "Max volume: " << W << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Value: " << input[i][0] << " Volume: " << input[i][1] << endl;
	}
	result = MaxValue(input, n, W);
	//result = MaxValue(input, n - 1, W);
	cout << "Result: " << result << endl;
	WriteFile(nameo, result);
	for (int i = 0; i < n; i++)
	{
		delete[] input[i];
	}
	delete input;
	system("pause");
	return 0;
}
int MaxValue(int** data, int n, int W)
{
	int** currvals = new int*[2];
	currvals[0] = new int[W];
	currvals[1] = new int[W];
	currvals[0][0] = 0; currvals[1][0] = 0;
	for (int i = 0; i < W; i++)
	{
		if (i < data[0][1] - 1)
		{
			currvals[0][i] = 0;
		}
		else
		{
			currvals[0][i] = data[0][0];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (data[i][1] <= j)
			{
				currvals[1][j] = max(currvals[0][j], currvals[0][j - data[i][1]] + data[i][0]);
			}
			else
			{
				currvals[1][j] = currvals[0][j];
			}
		}
		for (int k = 0; k < W; k++)
		{
			currvals[0][k] = currvals[1][k];
		}
	}
	delete[] currvals[0];
	delete[] currvals[1];
	delete[] currvals;
	return currvals[1][W - 1];/*
	if (i == 0)
	{
		if (data[i][1] > x)
		{
			return 0;
		}
		else
			return data[i][0];
	}
	else
	{
		if (data[i][1] > x)
		{
			return MaxValue(data, i - 1, x);
		}
		else
		{
			return max(MaxValue(data, i - 1, x), MaxValue(data, i - 1, x - data[i][1]) + data[i][0]);
		}
	}*/
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int** ReadFile(char name[100], int &W, int &n)
{
	FILE *file;
	char str[100], *p;
	char delim[] = "\n ";
	char *next_token = NULL;
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	p = strtok_s(str, delim, &next_token);
	W = atoi(p);
	p = strtok_s(NULL, delim, &next_token);
	n = atoi(p);
	int** input = new int*[n];
	for (int i = 0; i < n; i++)
	{
		input[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		fgets(str, 100, file);
		p = strtok_s(str, delim, &next_token);
		input[i][0] = atoi(p);
		p = strtok_s(NULL, delim, &next_token);
		input[i][1] = atoi(p);
	}
	fclose(file);
	return input;
}
void WriteFile(char name[100], int result)
{
	FILE* file;
	char str[100];
	fopen_s(&file, name, "w");
	_itoa_s(result, str, 100, 10);
	fputs(str, file);
	fclose(file);
}