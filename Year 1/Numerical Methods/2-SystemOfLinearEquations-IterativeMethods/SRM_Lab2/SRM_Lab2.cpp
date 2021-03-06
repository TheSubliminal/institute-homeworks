#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int n = 0;
float** ReadMatr(char[100]);
float** ReadVector(char[100]);
float** CreateMatr(int, int);
float** Seidel(float**, float**, int, float);
float** Vector(float**, float**, float**, int);
void PrintMatr(float**, int, int);
void DeleteMatr(float**, int);
int main()
{
	char namem[100], namev[100];
	float** input, **vector, **result;
	float e;
	cout << "Enter the name of the file with matrix: ";
	cin >> namem;
	cout << "Enter the name of the file with vector: ";
	cin >> namev;
	cout << "Input the value of \"e\": ";
	cin >> e;
	input = ReadMatr(namem);
	cout << "Input matrix:" << endl;
	PrintMatr(input, n, n);
	cout << "Input vector:" << endl;
	vector = ReadVector(namev);
	PrintMatr(vector, n, 1);
	result = Seidel(input, vector, n, e);
	cout << "Result vector:" << endl;
	PrintMatr(result, n, 1);
	cout << "Final vector of discrepancy:" << endl;
	PrintMatr(Vector(input, vector, result, n), n, 1);
	system("pause");
	return 0;
}
float** ReadMatr(char name[100])
{
	FILE *file;
	fopen_s(&file, name, "r");
	char temp[500], t[100];
	char matr[500] = "";
	int r, c;
	int count = 0, innercount = 0;
	char delim[] = "\n ";
	char *next_token = NULL;
	fgets(t, 100, file);
	char *p = strtok_s(t, delim, &next_token);
	while (!feof(file))
	{
		if (count == 0)
		{
			while (innercount < 2)
			{
				if (innercount == 0)
					r = atoi(p);
				if (innercount == 1)
				{
					c = atoi(p);
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
	if (c != r)
	{
		cout << "Invalid parameters" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		n = r;
		p = strtok_s(matr, delim, &next_token);
		float **arr = CreateMatr(r, r);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
			{
				arr[i][j] = atof(p);
				p = strtok_s(NULL, delim, &next_token);
			}
		}
		return arr;
	}
	fclose(file);
}
float** ReadVector(char name[100])
{
	FILE *file;
	fopen_s(&file, name, "r");
	char temp[500], t[100];
	char matr[500] = "";
	int r, c;
	int count = 0, innercount = 0;
	char delim[] = "\n ";
	char *next_token = NULL;
	fgets(t, 100, file);
	char *p = strtok_s(t, delim, &next_token);
	while (!feof(file))
	{
		if (count == 0)
		{
			while (innercount < 2)
			{
				if (innercount == 0)
					r = atoi(p);
				if (innercount == 1)
				{
					c = atoi(p);
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
	n = r;
	p = strtok_s(matr, delim, &next_token);
	float **arr = CreateMatr(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = atof(p);
			p = strtok_s(NULL, delim, &next_token);
		}
	}
	return arr;
	fclose(file);
}
void PrintMatr(float** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(12) << setprecision(8) << matr[i][j];
		}
		cout << endl;
	}
}
float** CreateMatr(int n, int m)
{
	float **matr = new float*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new float[m];
	}
	return matr;
}
void DeleteMatr(float** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
float** Seidel(float** matr, float** vector, int n, float e)
{
	float** matrc = CreateMatr(n, n);
	float** vectorb = CreateMatr(n, 1);
	float** vectorx = CreateMatr(n, 1);
	float** newvectorx = CreateMatr(n, 1);
	float difference = 0;
	int count = 0; 
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrc[i][j] = 0;
			}
			else
			{
				matrc[i][j] = (matr[i][j] / matr[i][i]) * -1;
			}
		}
		vectorb[i][0] = vector[i][0] / matr[i][i];
		vectorx[i][0] = vectorb[i][0];
	}
	cout << "Matrix C:" << endl;
	PrintMatr(matrc, n, n);
	do
	{
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j >= i)
				{
					sum += vectorx[j][0] * matrc[i][j];
				}
				else
				{
					sum += newvectorx[j][0] * matrc[i][j];
				}
			}
			newvectorx[i][0] = sum + vectorb[i][0];
		}
		difference = 0;
		for (int i = 0; i < n; i++)
		{
			if (abs(vectorx[i][0] - newvectorx[i][0]) > difference)
			{
				difference = abs(vectorx[i][0] - newvectorx[i][0]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			vectorx[i][0] = newvectorx[i][0];
		}
		if (count == 0 || count == 1 || count == 2)
		{
			cout << count + 1 << " iteration:" << endl;
			PrintMatr(vectorx, n, 1);
		}
		cout << "Vector of discrepancy:" << endl;
		PrintMatr(Vector(matr, vector, vectorx, n), n , 1);
		count++;
	} while (difference > e && count < 100);
	cout << "Number of iterations: " << count << endl;
	return vectorx;
}
float** Vector(float** A, float** B, float** X, int n)
{
	float** result = CreateMatr(n, 1);
	float** AmultX = CreateMatr(n, 1);
	float c1, c, c2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			result[i][j] = 0;
			AmultX[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int k = 0; k < n; k++)
			{
				AmultX[i][j] += (A[i][k] * X[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		c = B[i][0];
		c1 = AmultX[i][0];
		c2 = (B[i][0] - AmultX[i][0]);
		result[i][0] = (B[i][0] - AmultX[i][0]);
	}
	return result;
}