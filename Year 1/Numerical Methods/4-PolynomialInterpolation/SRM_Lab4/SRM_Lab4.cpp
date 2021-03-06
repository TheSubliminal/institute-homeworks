#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <vector>
using namespace std;

double Lagrange(double*, double*, double, int);
double Newton(double*, double*, double, double, int);
double SplineInterpolation(double*, double*, double, int);
double* TridiagMatrAlg(double**, double*, int);
double* ReadFile(char[100], int&);
int main()
{
	int n;
	double* inputX, *inputY, h;
	double x, e, Lagr, Newt, Spline;
	char nameX[100], nameY[100];
	strcpy_s(nameX, "inputX.txt");
	strcpy_s(nameY, "inputY.txt");
	//cout << "Please input the name of the file with vector X: ";
	//cin >> nameX;
	inputX = ReadFile(nameX, n);
	//cout << "Please input the name of the file with vector Y: ";
	//cin >> nameY;
	inputY = ReadFile(nameY, n);
	h = abs(inputX[1] - inputX[0]);
	cout << "Input \"x\": ";
	cin >> x;
	double fx = (pow(x,2)/15 + cos(x+2));
	cout << "Lagrange:\n";
	Lagr = Lagrange(inputX, inputY, x, n);
	cout << "Result: " << setprecision(8) << Lagr << endl;
	e = abs(Lagr - fx);
	cout << "The \"e\" is: " << e << endl << endl;
	cout << "Newton:\n";
	Newt = Newton(inputX, inputY, x, h, n);
	cout << "Result: " << setprecision(8) << Newt << endl;
	e = abs(Newt - fx);
	cout << "The \"e\" is: " << e << endl << endl;
	cout << "Spline interpolation:\n";
	Spline = SplineInterpolation(inputX, inputY, x, n);
	cout << "Result: " << setprecision(8) << Spline << endl;
	e = abs(Spline - fx);
	cout << "The \"e\" is: " << e << endl;
	system("pause");
    return 0;
}
double* ReadFile(char name[100], int &n)
{
	FILE *file;
	char str[100];
	char delim[] = "\n ";
	char *next_token = NULL;
	char *p = NULL;
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	n = atoi(str);
	double *result = new double[n];
	fgets(str, 100, file);
	p = strtok_s(str, delim, &next_token);
	for (int i = 0; i < n; i++)
	{
		result[i] = atof(p);
		p = strtok_s(NULL, delim, &next_token);
	}
	fclose(file);
	return result;
}
double Lagrange(double* vectx, double* vecty, double x, int n)
{
	double result = 0, numir = 1, denom = 1;
	for (int i = 0; i < n; i++)
	{
		numir = 1;
		denom = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				numir *= (x - vectx[j]);
				denom *= (vectx[i] - vectx[j]);
			}
		}
		if (i == 0)
		{
			cout << (numir / denom)*vecty[i] << "x";
		}
		else
		{
			if ((numir / denom)*vecty[i] < 0 || (numir / denom)*vecty[i] == -0.0)
			{
				cout << " - " << setprecision(8) << abs((numir / denom)*vecty[i]) << "x";
			}
			else
			{
				cout << " + " << setprecision(8) << (numir / denom)*vecty[i] << "x";
			}
		}
		result += (numir / denom)*vecty[i];
	}
	cout << endl;
	return result;
}
double Newton(double* vectx, double* vecty, double x, double h, int n)
{
	double result = 0, q, numir;
	int fact = 1;
	vector<vector<double>> alldifs;
	vector<double> currdifs;
	for (int i = 0; i < n - 1; i++)
	{
		currdifs = {};
		for (int j = 0; j < n - i - 1; j++)
		{
			if (i == 0)
			{
				currdifs.push_back(vecty[j + 1] - vecty[j]);
			}
			else
			{
				currdifs.push_back(alldifs[i - 1][j + 1] - alldifs[i - 1][j]);
			}
		}
		alldifs.push_back(currdifs);
	}
	q = (x - vectx[0]) / h;
	numir = q;
	result += vecty[0];
	cout << vecty[0] << "x";
	for (int i = 0; i < n - 1; i++)
	{
		if (i != 0)
		{
			fact *= i + 1;
			numir *= (q - i);
		}
		if (((numir*alldifs[i][0]) / fact) < 0 || ((numir*alldifs[i][0]) / fact) == -0.0)
		{
			cout << " - " << setprecision(8) << abs(((numir*alldifs[i][0]) / fact)) << "x";
		}
		else
		{
			cout << " + " << setprecision(8) << ((numir*alldifs[i][0]) / fact) << "x";
		}
		result += ((numir*alldifs[i][0]) / fact);
	}
	cout << endl;
	return result;
}
double* TridiagMatrAlg(double **matr, double *vectf, int n)
{
	double *a = new double[n];
	double *b = new double[n];
	double *x = new double[n];
	double temp;
	a[0] = 0;
	b[0] = 0;
	for (int i = 1; i < n - 1; i++)
	{
		temp = (matr[i][0] * a[i - 1]) + matr[i][1];
		a[i] = -1 * matr[i][2] / temp;
		b[i] = (vectf[i] - matr[i][0] * b[i - 1]) / temp;
	}
	x[n - 1] = (vectf[n - 2] - matr[n - 2][0] * b[n - 2]) / (matr[n - 2][1] + matr[n - 2][0] * a[n - 2]);
	for (int i = n - 2; i >= 0; i--)
	{
		x[i] = (a[i] * x[i + 1]) + b[i];
	}
	return x;
}
double SplineInterpolation(double* vectx, double* vecty, double x, int n)
{
	double *h = new double[n];
	double *a = new double[n];
	double *b = new double[n];
	double *c = new double[n];
	double *d = new double[n];
	double *f = new double[n];
	double *spline = new double[4];
	double **matr = new double*[n];
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[3];
	}
	for (int i = 1; i < n; i++)
	{
		h[i] = vectx[i] - vectx[i - 1];
	}
	for (int i = 1; i < n - 1; i++)
	{
		f[i] = 6 * (((vecty[i + 1] - vecty[i]) / h[i + 1]) - ((vecty[i] - vecty[i - 1]) / h[i]));
		matr[i][0] = h[i];
		matr[i][1] = 2 * (h[i] + h[i + 1]);
		matr[i][2] = h[i + 1];
	}
	f[0] = 0;
	c = TridiagMatrAlg(matr, f, n);
	for (int i = n - 1; i > 0; i--)
	{
		d[i] = (c[i] - c[i - 1]) / h[i];
		b[i] = (h[i] * (2 * c[i] + c[i - 1]) / 6) + ((vecty[i] - vecty[i - 1]) / h[i]);
	}
	int s = 0;
	if (x <= vectx[0])
	{
		s = 0;
	}
	else if (x >= vectx[n - 1])
	{
		s = n - 1;
	}
	else
	{
		int i = 0, j = n - 1;
		while (i + 1 < j)
		{
			int k = i + (j - i) / 2;
			if (x <= vectx[k])
			{
				j = k;
			}
			else
			{
				i = k;
			}
		}
		s = j;
	}
	double multipl = (x - vectx[s]);
	result = vecty[s] + (b[s] + (c[s] / 2 + d[s] * multipl / 6) * multipl) * multipl;
	spline[0] = vecty[s]; spline[1] = b[s]; spline[2] = c[s]; spline[3] = d[s];
	for (int i = 0; i < 4; i++)
	{
		cout << spline[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
	return result;
}