#pragma once
#include <iostream>
#include "list.h"
#include <vector>
#include <cmath>
using namespace std;

int** OpenAddrLinear(int*, int*, int, int, int&);
int** OpenAddrQuadratic(int*, int*, int, int, int&);
int** OpenAddrDouble(int*, int*, int, int, int&);

int** OpenAddrLinear(int* arr, int* sums, int n, int m, int &colisions)
{
	int M = n * 3, hk, hk1, i;
	vector<int> hashtable(n * 3);
	int** result = new int*[m];
	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		result[i] = new int[2];
	}
	for (int k = 0; k < n; k++)
	{
		i = 0;
		hk1 = arr[k] % M;
		hk = (hk1 + i) % M;
		while (hashtable[hk] != 0 && i != M - 1)
		{
			i++;
			if (hashtable[hk] != arr[k])
			{
				colisions++;
			}
			hk = (hk1 + i) % M;
		}
		hashtable[hk] = arr[k];
	}
	for (int k = 0; k < m; k++)
	{
		flag = false;
		for (int j = 0; j < n && flag != true; j++)
		{
			i = 0;
			hk1 = (sums[k] - arr[j]) % M;
			hk = (hk1 + i) % M;
			if (hk > 0 && hk < M)
			{
				if (hashtable[hk] == 0)
				{
					result[k][0] = 0;
					result[k][1] = 0;
				}
				else
				{
					while (hashtable[hk] != 0 && i != M - 1)
					{
						if (hashtable[hk] == (sums[k] - arr[j]))
						{
							flag = true;
							result[k][0] = arr[j];
							result[k][1] = hashtable[hk];
							break;
						}
						i++;
						hk = (hk1 + i) % M;
					}
				}
			}
			else
			{
				result[k][0] = 0;
				result[k][1] = 0;
			}
		}
		cout << result[k][0] << " " << result[k][1] << endl;
	}
	return result;
}
int** OpenAddrQuadratic(int* arr, int* sums, int n, int m, int &colisions)
{
	int M = n * 3, hk, hk1, i, c1 = 1, c2 = 3;
	vector<int> hashtable(n * 3);
	int** result = new int*[m];
	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		result[i] = new int[2];
	}
	for (int k = 0; k < n; k++)
	{
		i = 0;
		hk1 = arr[k] % M;
		hk = (hk1 + c1 * i + c2 * i * i) % M;
		while (hashtable[hk] != 0 && i != M - 1)
		{
			i++;
			if (hashtable[hk] != arr[k])
			{
				colisions++;
			}
			hk = (hk1 + c1 * i + c2 * i * i) % M;
		}
		hashtable[hk] = arr[k];
	}
	for (int k = 0; k < m; k++)
	{
		flag = false;
		for (int j = 0; j < n && flag != true; j++)
		{
			i = 0;
			hk1 = (sums[k] - arr[j]) % M;
			hk = (hk1 + c1 * i + c2 * i * i) % M;
			if (hk > 0 && hk < M)
			{
				if (hashtable[hk] == 0)
				{
					result[k][0] = 0;
					result[k][1] = 0;
				}
				else
				{
					while (hashtable[hk] != 0 && i != M - 1)
					{
						if (hashtable[hk] == (sums[k] - arr[j]))
						{
							flag = true;
							result[k][0] = arr[j];
							result[k][1] = hashtable[hk];
							break;
						}
						i++;
						hk = (hk1 + c1 * i + c2 * i * i) % M;
					}
				}
			}
			else
			{
				result[k][0] = 0;
				result[k][1] = 0;
			}
		}
		cout << result[k][0] << " " << result[k][1] << endl;
	}
	return result;
}
int** OpenAddrDouble(int* arr, int* sums, int n, int m, int &colisions)
{
	int M = n * 3, hk, hk1, hk2, i;
	vector<int> hashtable(n * 3);
	int** result = new int*[m];
	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		result[i] = new int[2];
	}
	for (int k = 0; k < n; k++)
	{
		i = 0;
		hk1 = arr[k] % M;
		hk2 = 1 + (arr[k] % (M - 1));
		hk = (hk1 + i * hk2) % M;
		while (hashtable[hk] != 0 && i != M - 1)
		{
			i++;
			if (hashtable[hk] != arr[k])
			{
				colisions++;
			}
			hk = (hk1 + i * hk2) % M;
		}
		hashtable[hk] = arr[k];
	}
	for (int k = 0; k < m; k++)
	{
		flag = false;
		for (int j = 0; j < n && flag != true; j++)
		{
			i = 0;
			hk1 = (sums[k] - arr[j]) % M;
			hk = (hk1 + i * hk2) % M;
			if (hk > 0 && hk < M)
			{
				if (hashtable[hk] == 0)
				{
					result[k][0] = 0;
					result[k][1] = 0;
				}
				else
				{
					while (hashtable[hk] != 0 && i != M - 1)
					{
						if (hashtable[hk] == (sums[k] - arr[j]))
						{
							flag = true;
							result[k][0] = arr[j];
							result[k][1] = hashtable[hk];
							break;
						}
						i++;
						hk = (hk1 + i * hk2) % M;
					}
				}
			}
			else
			{
				result[k][0] = 0;
				result[k][1] = 0;
			}
		}
		cout << result[k][0] << " " << result[k][1] << endl;
	}
	return result;
}