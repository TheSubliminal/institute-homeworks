#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

double* ReadFile(char[100]);
double Simpson(double, double, int);
double Gauss(double, double, int);
double func(double);
int main()
{
	char name[100];
	double *interval, simps, gaus, a, b, b1, e;
	int n = 2, m = 2;
	strcpy_s(name, "input.txt");
	//cout << "Input name of the input file: ";
	//cin >> name;
	interval = ReadFile(name);
	a = interval[0];
	b = interval[1];
	b1 = b - ((b - a) / 2);
	e = abs(func(b1) - func(a));
	while (e > 0.0001)
	{
		b1 -= (b1 - a) / 2;
		n *= 2;
		e = abs(func(b1) - func(a));
	}
	a = interval[0];
	b = interval[1];
	b1 = b - ((b - a) / 2);
	e = abs(func(b1) - func(a));
	while (e > 0.0001)
	{
		b1 -= (b1 - a) / 2;
		m++;
		e = abs(func(b1) - func(a));
	}
	//cout << "Number of segments for which the interval of integration will be divided for Simson's method: " << n << endl;
	simps = Simpson(a, b, n);
	gaus = Gauss(a, b, m);
	cout << "Simpson's method: ";
	cout << setprecision(8) << simps << endl;
	cout << "Gauss' method: ";
	cout << setprecision(8) << gaus << endl;
	system("pause");
	delete[] interval;
    return 0;
}
double func(double x)
{
	return log10(pow(x, 2) + 1) / x;
}
double Simpson(double a, double b, int n)
{
	double result, sum1 = 0, sum2 = 0, h = (b - a) / n;
	double *y = new double[n];
	double *x = new double[n];
	x[0] = a;
	y[0] = func(x[0]);
	for (int i = 1; i < n; i++)
	{
		x[i] = x[i - 1] + h;
		y[i] = func(x[i]);
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (i % 2 == 0)
		{
			sum1 += y[i];
		}
		else
		{
			sum2 += y[i];
		}
	}
	result = (h / 3) * (y[0] + y[n - 1] + 2 * sum1 + 4 * sum2);
	delete[] x;
	delete[] y;
	return result;
}
double Gauss(double a, double b, int m)
{
	int n = 4;
	double result = 0, a1 = a, b1 = a + (b - a) / m, sum = 0, curr;
	double *x = new double[n];
	double xn[4] = { -0.8611363, -0.3399810, 0.3399810, 0.8611363 };
	double cn[4] = { 0.3478548, 0.6521451, 0.6521451, 0.3478548 };
	for (int i = 0; i < m; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			curr = ((a1 + b1) / 2) + ((b1 - a1) / 2)*xn[j];
			sum += cn[j] * func(curr);
		}
		result += ((b1 - a1) / 2)*sum;
		a1 += (b - a) / m;
		b1 += (b - a) / m;
	}
	return result;
}
double* ReadFile(char name[100])
{
	FILE *file;
	double *num = new double[2];
	char str[100];
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	num[0] = atof(str);
	fgets(str, 100, file);
	num[1] = atof(str);
	fclose(file);
	return num;
}