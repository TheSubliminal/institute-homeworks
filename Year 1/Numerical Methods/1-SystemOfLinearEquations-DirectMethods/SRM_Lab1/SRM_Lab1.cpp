#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int n = 0;
float** CreateMatr(int, int);
float** ReadMatr(char[100]);
float** ReadVector(char[100]);
float** TriangleMatr(float**, int);
void PrintMatr(float**, int, int);
void DeleteMatr(float**, int);
float** TransponateMatr(float**, int);
float** FindY(float**, float**, int);
float** FindX(float**, float**, int);
float** Vector(float**, float**, float**, int);
int main()
{
	char namem[100], namev[100];
	float** input, **triangle, **transponated, **vector, **vectorY, **vectorX, **vectorR;
	//cout << "Enter the name of the file with matrix: ";
	//cin >> namem;
	//cout << "Enter the name of the file with vector: ";
	//cin >> namev;
	strcpy_s(namem, "input.txt");
	strcpy_s(namev, "input_vector.txt");
	input = ReadMatr(namem);
	cout << "Input matrix:" << endl;
	PrintMatr(input, n, n);
	cout << "Input vector:" << endl;
	vector = ReadVector(namev);
	PrintMatr(vector, n, 1);
	cout << "Upper triangular matrix:" << endl;
	triangle = TriangleMatr(input, n);
	PrintMatr(triangle, n, n);
	cout << "Transponated matrix:" << endl;
	transponated = TransponateMatr(triangle, n);
	PrintMatr(transponated, n, n);
	cout << "Y-vector:" << endl;
	vectorY = FindY(transponated, vector, n);
	PrintMatr(vectorY, n, 1);
	cout << "Result vector:" << endl;
	vectorX = FindX(triangle, vectorY, n);
	PrintMatr(vectorX, n, 1);
	cout << "Vector of discrepancy:" << endl;
	vectorR = Vector(input, vector, vectorX, n);
	PrintMatr(vectorR, n, 1);
	DeleteMatr(input, n);
	DeleteMatr(triangle, n);
	DeleteMatr(transponated, n);
	DeleteMatr(vector, n);
	DeleteMatr(vectorY, n);
	DeleteMatr(vectorX, n);
	DeleteMatr(vectorR, n);
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
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					cout << "Matrix is not symetric" << endl;
					system("pause");
					exit(0);
				}
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
float** TriangleMatr(float** matr, int n)
{
	float res = 0;
	float** result = CreateMatr(n, n);
	float sumsqr = 0, summult = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (matr[i][j] < 0)
					{
						cout << "Unsolveble matrix" << endl;
						system("pause");
						exit(0);
						break;
					}
					else
						result[i][j] = sqrt(matr[i][j]);
				}
				else
				{
					result[i][j] = matr[i][j] / result[0][0];
				}
			}
			else if (i == j)
			{
				for (int l = 0; l < i; l++)
				{
					sumsqr += pow(result[l][j], 2);
				}
				if ((matr[i][j] - sumsqr) < 0)
				{
					cout << "Unsolveble matrix" << endl;
					system("pause");
					exit(0);
					break;
				}
				else
				{
					result[i][j] = sqrt(matr[i][j] - sumsqr);
					sumsqr = 0;
				}
			}
			else if (i < j)
			{
				for (int f = 0; f < i; f++)
				{
					summult += (result[f][i] * result[f][j]);
				}
				result[i][j] = (matr[i][j] - summult) / result[i][i];
				summult = 0;
			}
		}
	}
	int k = 1;
	for (int i = k; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			result[i][j] = 0;
		}
		k++;
	}
	return result;
}
float** TransponateMatr(float** matr, int n)
{
	float **result = CreateMatr(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[j][i] = matr[i][j];
		}
	}
	return result;
}
void PrintMatr(float** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(12) << setprecision(7) << matr[i][j];
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
float** FindY(float** matr, float** vector, int n)
{
	float** result = CreateMatr(n, 1);
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			result[i][0] = vector[i][0] / matr[i][i];
		}
		else
		{
			for (int j = 0; j < i; j++)
			{
				sum += (matr[i][j] * result[j][0]);
			}
			result[i][0] = (vector[i][0] - sum) / matr[i][i];
		}
		sum = 0;
	}
	return result;
}
float** FindX(float** matr, float** vector, int n)
{
	float** result = CreateMatr(n, 1);
	float sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
		{
			result[i][0] = vector[i][0] / matr[i][i];
		}
		else
		{
			for (int j = i + 1; j <= n - 1; j++)
			{
				sum += (matr[i][j] * result[j][0]);
			}
			result[i][0] = (vector[i][0] - sum) / matr[i][i];
		}
		sum = 0;
	}
	return result;
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


