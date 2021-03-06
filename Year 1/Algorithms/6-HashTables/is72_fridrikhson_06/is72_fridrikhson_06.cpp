#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "OpenAddr.h"
#include "Chain.h"
#include "List.h"
using namespace std;

int* ReadFile(char[100], int&, int&);
int** ChainedDivide(int*, int*, int, int, int&);
int** ChainedMultiply(int*, int*, int, int, int&);
int** OpenAddrLinear(int*, int*, int, int, int&);
int** OpenAddrQuadratic(int*, int*, int, int, int&);
int** OpenAddrDouble(int*, int*, int, int, int&);
void WriteFile(char[100], int**, int, int);

int main()
{
	char namei[100], nameo[100];
	int key, m, n, colisions = 0;
	int* arr, *sums, *input, **result;
	cout << "Input name of the input file: ";
	cin >> namei;
	input = ReadFile(namei, n, m);
	arr = new int[n];
	sums = new int[m];
	strcpy_s(nameo, "is72_fridrikhson_06_output.txt");
	for (int i = 0; i < n + m; i++)
	{
		if (i < n)
		{
			arr[i] = input[i];
		}
		else
		{
			sums[i - n] = input[i];
		}
	}
	cout << "ID of hash-function type: ";
	cin >> key;
	switch (key)
	{
	case 1:
	{
		result = ChainedDivide(arr, sums, n, m, colisions);
		WriteFile(nameo, result, colisions, m);
		break;
	}
	case 2:
	{
		result = ChainedMultiply(arr, sums, n, m, colisions);
		WriteFile(nameo, result, colisions, m);
		break;
	}
	case 3:
	{
		result = OpenAddrLinear(arr, sums, n, m, colisions);
		WriteFile(nameo, result, colisions, m);
		break;
	}
	case 4:
	{
		result = OpenAddrQuadratic(arr, sums, n, m, colisions);
		WriteFile(nameo, result, colisions, m);
		break;
	}
	case 5:
	{
		result = OpenAddrDouble(arr, sums, n, m, colisions);
		WriteFile(nameo, result, colisions, m);
		break;
	}
	default:
	{
		exit(0);
	}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] result[i];
	}
	delete[] result;
	system("pause");
	return 0;
}
/*
List* InitList(int data)
{
	List *head;
	head = new List;	
	head->num = data;	
	head->next = NULL;	
	head->size = 1;
	return head;
}
List* Add(List* head, int data)
{
	if (head == NULL)
		head = InitList(data);
	else
	{
		List *newElement;
		newElement = head;
		if (newElement->next != NULL)
		{
			do
				newElement = newElement->next;
			while (newElement->next->next != NULL);
		}
		newElement = new List;	
		newElement->next = newElement;	
		newElement->num = data;	
		head->size++;
	}
	return head;	
}
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
	double A = (sqrt(5) - 1)/2;
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
}*/
int* ReadFile(char name[100], int &n, int &m)
{
	FILE *file;
	char str[100];
	char delim[] = "\n ";
	char *next_token = NULL;
	int count = 0, i = 0;
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	char *p = strtok_s(str, delim, &next_token);
	n = atoi(p);
	p = strtok_s(NULL, delim, &next_token);
	m = atoi(p);
	int *arr = new int[m+n];
	while(!(feof(file)))
	{
		fgets(str, 100, file);
		arr[i] = atoi(str);
		i++;
	}
	fclose(file);
	return arr;
}
void WriteFile(char name[100], int** result, int colisions, int m)
{
	FILE *file;
	fopen_s(&file, name, "w");
	char str[100], buff[100];
	_itoa_s(colisions, str, 100, 10);
	fputs(str, file);
	fputc('\n', file);
	for (int i = 0; i < m; i++)
	{
		_itoa_s(result[i][0], str, 100, 10);
		strcat_s(str, " ");
		_itoa_s(result[i][1], buff, 100, 10);
		strcat_s(str, buff);
		if (i != m - 1)
			strcat_s(str, "\n");
		fputs(str, file);
	}
	fclose(file);
}