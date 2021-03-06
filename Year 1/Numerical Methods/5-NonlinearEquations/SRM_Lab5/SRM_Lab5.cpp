#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void PrintArr(double*, int);
void PrintIntervals(double**, int);
double* ReadFunc(char[100], int&);
double** ReadIntervals(char[100], int&);
double funcfromX(double*, double, int);
double* bisection(double*, int, double, double**, int, int&);
double* secants(double*, int, double, double**, int, int&);
double* Newton(double*, int, double, double**, int, int&, double);
double derivative(double*, double, double, double);
int main()
{
	int nf, ni, iterations = 0;
	char namef[100], namei[100];
	double e, approx;
	double *func, *bisect, *secant, *Newt;
	double **intervals;
	cout << "Input the name of file with function: ";
	cin >> namef;
	cout << "Input the name of file with intervals: ";
	cin >> namei;
	cout << "Input the \"e\": ";
	cin >> e;
	func = ReadFunc(namef, nf);
	cout << "Input function:" << endl;
	PrintArr(func, nf);
	intervals = ReadIntervals(namei, ni);
	cout << "Intervals of the roots:" << endl;
	PrintIntervals(intervals, ni);
	bisect = bisection(func, nf, e, intervals, ni, iterations);
	cout << "Bisection:" << endl;
	PrintArr(bisect, ni);
	cout << "Number of iterations: " << iterations << endl;
	iterations = 0;
	secant = secants(func, nf, e, intervals, ni, iterations);
	cout << "Secants:" << endl;
	PrintArr(secant, ni);
	cout << "Number of iterations: " << iterations << endl;
	iterations = 0;
	cout << "Input starting approximation for Newton's method: ";
	cin >> approx;
	Newt = Newton(func, nf, e, intervals, ni, iterations, approx);
	cout << "Newton's method:" << endl;
	PrintArr(Newt, ni);
	cout << "Number of iterations: " << iterations << endl;
	system("pause");
    return 0;
}
double* bisection(double* func, int nf, double e, double** intervals, int ni, int &iterations)
{
	double sum1, sum2, x, l, r;
	double* result = new double[ni];
	for (int i = 0; i < ni; i++)
	{
		sum1 = funcfromX(func, intervals[i][0], nf);
		sum2 = funcfromX(func, intervals[i][1], nf);
		if (sum1*sum2 > 0)
		{
			cout << "Wrong intervals" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			l = intervals[i][0];
			r = intervals[i][1];
			do
			{
				x = (r + l) / 2;
				if (funcfromX(func, x, nf) == 0)
				{
					break;
				}
				sum1 = funcfromX(func, l, nf);
				sum2 = funcfromX(func, x, nf);
				if (sum1*sum2 < 0)
				{
					r = x;
				}
				else
				{
					l = x;
				}
				iterations++;
			} while (abs(r - l) > e && abs(funcfromX(func, x, nf)) > e);
			result[i] = x;
		}
	}
	return result;
}
double* ReadFunc(char name[100], int &size)
{
	FILE *file;
	char str[100];
	char delim[] = " ";
	char *next_token = NULL, *p;
	int i = 0;
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	size = atoi(str);
	fgets(str, 100, file);
	p = strtok_s(str, delim, &next_token);
	double* func = new double[size];
	while (p != NULL)
	{
		func[i] = atof(p);
		p = strtok_s(NULL, delim, &next_token);
		i++;
	}
	fclose(file);
	return func;
}
void PrintArr(double* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(12) << arr[i];
	}
	cout << endl;
}
void PrintIntervals(double** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				cout << "From" << setw(4) << setprecision(8) << matr[i][j] << setw(4) << "to";
			}
			else
			{
				cout << setw(4) << setprecision(8) << matr[i][j];
			}

		}
		cout << endl;
	}
}
double** ReadIntervals(char name[100], int &n)
{
	FILE *file;
	char str[100];
	char delim[] = "\n ";
	char *next_token = NULL, *p;
	int i = 0, count = 0;
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	p = strtok_s(str, delim, &next_token);
	n = atoi(str);
	fgets(str, 100, file);
	double** func = new double*[n];
	for (int i = 0; i < n * 2; i++)
	{
		func[i] = new double[2];
	}
	for (int i = 0; i < n; i++)
	{
		p = strtok_s(str, delim, &next_token);
		func[i][0] = atof(p);
		p = strtok_s(NULL, delim, &next_token);
		func[i][1] = atof(p);
		fgets(str, 100, file);
	}
	fclose(file);
	return func;
}
double funcfromX(double* func, double x, int n)
{
	double sum = 0;
	for (int i = 0, j = n - 1; i < n; i++, j--)
	{
		sum += func[i] * pow(x, j);
	}
	return sum;
}
double* secants(double* func, int nf, double e, double** intervals, int ni, int &iterations)
{
	double sum1, sum2, x, prevx = 0, xdiff, l, r;
	double* result = new double[ni];
	for (int i = 0; i < ni; i++)
	{
		sum1 = funcfromX(func, intervals[i][0], nf);
		sum2 = funcfromX(func, intervals[i][1], nf);
		if (sum1*sum2 > 0)
		{
			cout << "Wrong intervals" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			l = intervals[i][0];
			r = intervals[i][1];
			do 
			{
				x = (l*funcfromX(func, r, nf) - r * funcfromX(func, l, nf))/(funcfromX(func, r, nf)- funcfromX(func, l, nf));
				if (funcfromX(func, x, nf) == 0)
				{
					break;
				}
				sum1 = funcfromX(func, l, nf);
				sum2 = funcfromX(func, x, nf);
				xdiff = x - prevx;
				if (sum1*sum2 < 0)
				{
					r = x;
					prevx = x;
				}
				else
				{
					l = x;
					prevx = x;
				}
				iterations++;
			} while (abs(xdiff) > e && abs(funcfromX(func, x, nf)) > e);
			result[i] = x;
		}
	}
	return result;
}
double* Newton(double* func, int nf, double e, double** intervals, int ni, int &iterations, double approx)
{
	double sum1, sum2, x = 0, prevx = 0, xdiff, l, r;
	double* result = new double[ni];
	for (int i = 0; i < ni; i++)
	{
		sum1 = funcfromX(func, intervals[i][0], nf);
		sum2 = funcfromX(func, intervals[i][1], nf);
		if (sum1*sum2 > 0)
		{
			cout << "Wrong intervals" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			l = intervals[i][0];
			r = intervals[i][1];
			do
			{
				x = r - funcfromX(func, r, nf) / derivative(func, r, approx, nf);
				if (funcfromX(func, x, nf) == 0)
				{
					break;
				}
				sum1 = funcfromX(func, l, nf);
				sum2 = funcfromX(func, x, nf);
				xdiff = x - prevx;
				if (sum1*sum2 < 0)
				{
					r = x;
					prevx = x;
				}
				else
				{
					l = x;
					prevx = x;
				}
				iterations++;
			} while (abs(xdiff) > e && abs(funcfromX(func, x, nf)) > e);
			result[i] = x;
		}
	}
	return result;
}
double derivative(double* func, double x, double approx, double n)
{
	return (funcfromX(func, x + approx, n) - funcfromX(func, x - approx, n)) / (2 * approx);
}