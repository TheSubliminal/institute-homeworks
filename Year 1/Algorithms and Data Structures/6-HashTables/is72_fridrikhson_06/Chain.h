#pragma once
#include <iostream>
#include "list.h"
#include <vector>
#include <cmath>
using namespace std;

int** ChainedDivide(int*, int*, int, int, int&);
int** ChainedMultiply(int*, int*, int, int, int&);
int** ChainedDivide(int* arr, int* sums, int n, int m, int &colisions)
{
	int M = n * 3, hk;
	bool flag = false;
	vector<List*> hashtable(n * 3);
	int** result = new int*[m];
	for (int i = 0; i < m; i++)
	{
		result[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		hk = arr[i] % M;
		hashtable[hk] = Add(hashtable[hk], arr[i]);
	}
	for (int i = 0; i < n * 3; i++)
	{
		if (hashtable[i] != NULL)
		{
			if (hashtable[i]->size > 1)
			{
				colisions += hashtable[i]->size - 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		flag = false;
		for (int j = 0; j < n && flag != true; j++)
		{
			hk = (sums[i] - arr[j]) % M;
			if (hk < n * 3 && hk > 0)
			{
				if (hashtable[hk] != NULL)
				{
					List *curr = hashtable[hk];
					while (curr != NULL)
					{
						if (curr->num == (sums[i] - arr[j]))
						{
							flag = true;
							result[i][0] = arr[j];
							result[i][1] = curr->num;
							break;
						}
						curr = curr->next;
					}
				}
				else
				{
					result[i][0] = 0;
					result[i][1] = 0;
				}
			}
			else
			{
				result[i][0] = 0;
				result[i][1] = 0;
			}
		}
		cout << result[i][0] << " " << result[i][1] << endl;
	}
	return result;
}
int** ChainedMultiply(int* arr, int* sums, int n, int m, int &colisions)
{
	int M = n * 3, hk;
	bool flag = false;
	double A = (sqrt(5) - 1) / 2;
	vector<List*> hashtable(n * 3);
	int** result = new int*[m];
	for (int i = 0; i < m; i++)
	{
		result[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		hk = floor(M * fmod(arr[i] * A, 1));
		hashtable[hk] = Add(hashtable[hk], arr[i]);
	}
	for (int i = 0; i < n * 3; i++)
	{
		if (hashtable[i] != NULL)
		{
			if (hashtable[i]->size > 1)
			{
				colisions += hashtable[i]->size - 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		flag = false;
		for (int j = 0; j < n && flag != true; j++)
		{
			hk = floor(M * fmod((sums[i] - arr[j]) * A, 1));
			if (hk < n * 3 && hk > 0)
			{
				if (hashtable[hk] != NULL)
				{
					List *curr = hashtable[hk];
					while (curr != NULL)
					{
						if (curr->num == (sums[i] - arr[j]))
						{
							flag = true;
							result[i][0] = arr[j];
							result[i][1] = curr->num;
							break;
						}
						curr = curr->next;
					}
				}
				else
				{
					result[i][0] = 0;
					result[i][1] = 0;
				}
			}
			else
			{
				result[i][0] = 0;
				result[i][1] = 0;
			}
		}
		cout << result[i][0] << " " << result[i][1] << endl;
	}
	return result;
}