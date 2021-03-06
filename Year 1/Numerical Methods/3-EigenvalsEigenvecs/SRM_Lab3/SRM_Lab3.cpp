#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

double** CreateMatr(int, int);
void DeleteMatr(double**, int);
double** ReadMatr(char[100], int&);
void PrintMatr(double**, int, int);
double** Multiplying(double**, double**, int);
void Frobenius(double**, double**, int);
int main()
{
	int n;
	double** input, **b, sum = 0, mod;
	char name[100];
	cout << "Please input the name of the input file: ";
	cin >> name;
	input = ReadMatr(name, n);
	double** y = CreateMatr(n, 1);
	double** x = CreateMatr(n, 1);
	double *polinom = new double[n];
	b = CreateMatr(n, n);
	double result[4] = { 2.65890017, 4.34625491, 5.69197086, 9.26287406 };
	PrintMatr(input, n, n);
	Frobenius(input, b, n);
	cout << "Resulting polinom:" << endl;
	for (int i = n - 1, j = 0; i >= 0, j < n; i--, j++)
	{
		polinom[j] = input[0][j];
		if (i == n - 1)
		{
			cout << "x^" << i + 1;
		}
		if (polinom[j] < 0)
		{
			cout << " + ";
		}
		else
		{
			cout << " - ";
		}
		if (i == 0)
			cout << setprecision(12) << abs(polinom[j]);
		else
			cout << "x^" << i << "*" << setprecision(12) << abs(polinom[j]);
	}
	cout << endl;
	for (int k = 0; k < n; k++)
	{
		for (int i = n - 1, j = 0; i >= 0, j < n; i--, j++)
		{
			y[j][0] = pow(result[k], i);
		}
		x = Multiplying(b, y, n);
		for (int i = 0; i < n; i++)
		{
			sum += pow(x[i][0], 2);
		}
		mod = sqrt(sum);
		for (int i = 0; i < n; i++)
		{
			x[i][0] = x[i][0] / mod;
		}
		cout << "Vector " << k + 1 << endl;
		PrintMatr(x, n, 1);
		sum = 0;
	}
	DeleteMatr(input, n);
	DeleteMatr(b, n);
	DeleteMatr(y, n);
	DeleteMatr(x, n);
	system("pause");
	return 0;
}
void Frobenius(double** matr, double** b, int n)
{
	double **temp = CreateMatr(n, n);
	double **M2A = CreateMatr(n, n);
	double **AM1 = CreateMatr(n, n);
	double **m1 = CreateMatr(n, n);
	double **m2 = CreateMatr(n, n);
	double **b1 = CreateMatr(n, n);
	double **b2 = CreateMatr(n, n);
	double **b3 = CreateMatr(n, n);
	double **b12 = CreateMatr(n, n);
	double **b123 = CreateMatr(n, n);
	int incr = n, r = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		cout << "Iteration " << abs(i - n + 1) << endl;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j == k)
				{
					m1[j][k] = 1;
					m2[j][k] = 1;
				}
				else
				{
					m1[j][k] = 0;
					m2[j][k] = 0;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (matr[i + 1][i] == 0)
			{
				cout << "Unable to solve this matrix" << endl;
				system("pause");
				exit(0);
			}
			else
			{
				if (j == n - incr)
				{
					m1[i][j] = 1 / matr[i + 1][i];
				}
				else
				{
					m1[i][j] = (-1)*matr[i + 1][j] / matr[i + 1][i];
				}
				m2[i][j] = matr[i + 1][j];
			}
		}
		cout << "M" << endl;
		PrintMatr(m1, n, n);
		cout << "M^-1" << endl;
		PrintMatr(m2, n, n);
		M2A = Multiplying(m2, matr, n);
		AM1 = Multiplying(M2A, m1, n);
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				if (r == 0)
				{
					b1[k][j] = m1[k][j];
				}
				if (r == 1)
				{
					b2[k][j] = m1[k][j];
				}
				if (r == 2)
				{
					b3[k][j] = m1[k][j];
				}
				matr[k][j] = AM1[k][j];
			}
		}
		cout << "Basic matr" << endl;
		PrintMatr(matr, n, n);
		incr++;
		r++;
	}
	b12 = Multiplying(b1, b2, n);
	b123 = Multiplying(b12, b3, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = b123[i][j];
		}
	}
}
double** Multiplying(double** matr1, double** matr2, int n)
{
	double **matr3 = CreateMatr(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr3[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) 
			{
				matr3[i][j] += (matr1[i][k] * matr2[k][j]);
			}
		}
	}
	return matr3;
}
double** CreateMatr(int n, int m)
{
	double **matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	return matr;
}
void PrintMatr(double** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(12) << setprecision(10) << matr[i][j];
		}
		cout << endl;
	}
}
void DeleteMatr(double** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
double** ReadMatr(char name[100], int &n)
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
				{
					r = atoi(p);
				}
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
		double **arr = CreateMatr(r, r);
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