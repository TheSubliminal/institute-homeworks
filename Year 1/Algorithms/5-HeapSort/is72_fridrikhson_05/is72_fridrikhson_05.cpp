#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void MaxHeapify(vector<int>&, int);
void BuildMaxHeap(vector<int>&);
void MinHeapify(vector<int>&);
void BuildMinHeap(vector<int>&);
int HeapExtractMin(vector<int>&);
int HeapExtractMax(vector<int>&);
vector<int> ReadFile(char[100]);
vector<vector<int>> MedianSearch(vector<int>);
void WriteFile(char[100], vector<vector<int>>);
void PrintArr(vector<int>);
int main()
{
	char namei[100], nameo[100];
	vector<int> input;
	vector<vector<int>> result;
	cout << "Input name of the input file: ";
	cin >> namei;
	input = ReadFile(namei);
	PrintArr(input);
	result = MedianSearch(input);
	cout << "Input name of the output file: ";
	cin >> nameo;
	WriteFile(nameo, result);
	system("pause");
	return 0;
}
vector<vector<int>> MedianSearch(vector<int> values)
{
	vector<int> maxheap = { values[0] }, minheap, current;
	vector<vector<int>> result;
	int min, max, diff1, diff2;
	cout << maxheap[0] << endl;
	current.push_back(maxheap[0]);
	result.push_back(current);
	current = {};
	for (unsigned int i = 1; i < values.size(); i++)
	{
		if (values[i] < maxheap[0])
		{
			maxheap.push_back(values[i]);
			BuildMaxHeap(maxheap);
		}
		else
		{
			minheap.push_back(values[i]);
			BuildMinHeap(minheap);
		}
		diff1 = maxheap.size() - minheap.size();
		diff2 = minheap.size() - maxheap.size();
		if (diff1 > 1)
		{
			max = HeapExtractMax(maxheap);
			minheap.push_back(max);
			BuildMinHeap(minheap);
		}
		else if (diff2 > 1)
		{
			min = HeapExtractMin(minheap);
			maxheap.push_back(min);
			BuildMaxHeap(maxheap);
		}
		if (i % 2 != 0)
		{
			cout << maxheap[0] << " " << minheap[0] << endl;
			current.push_back(maxheap[0]);
			current.push_back(minheap[0]);
			result.push_back(current);
		}
		else
		{
			if (maxheap.size() > minheap.size())
			{
				cout << maxheap[0] << endl;
				current.push_back(maxheap[0]);
				result.push_back(current);
			}
			else
			{
				cout << minheap[0] << endl;
				current.push_back(minheap[0]);
				result.push_back(current);
			}
		}
		current = {};
	}
	return result;
}
void MaxHeapify(vector<int> &values, int current)
{
	int left = 2 * current + 1;
	int right = 2 * current + 2;
	int max = current;
	if (left < values.size() && values[left] > values[max])
	{
		max = left;
	}
	if (right < values.size() && values[right] > values[max])
	{
		max = right;
	}
	if (max != current)
	{
		swap(values[current], values[max]);
		MaxHeapify(values, max);
	}
}
void BuildMaxHeap(vector<int> &values)
{
	for (int i = (values.size() / 2) - 1; i >= 0; i--)
	{
		MaxHeapify(values, i);
	}
}
void MinHeapify(vector<int> &values, int current)
{
	int left = 2 * current + 1;
	int right = 2 * current + 2;
	int min = current;
	if (left < values.size() && values[left] < values[min])
	{
		min = left;
	}
	if (right < values.size() && values[right] < values[min])
	{
		min = right;
	}
	if (min != current)
	{
		swap(values[current], values[min]);
		MinHeapify(values, min);
	}
}
void BuildMinHeap(vector<int> &values)
{
	for (int i = (values.size() / 2) - 1; i >= 0; i--)
	{
		MinHeapify(values, i);
	}
}
int HeapExtractMax(vector<int> &heap)
{
	int max = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	MaxHeapify(heap, 0);
	return max;
}
int HeapExtractMin(vector<int> &heap)
{
	int min = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	MinHeapify(heap, 0);
	return min;
}
vector<int> ReadFile(char name[100])
{
	FILE *file;
	char str[100];
	fopen_s(&file, name, "r");
	fgets(str, 100, file);
	int n = atoi(str);
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		fgets(str, 100, file);
		result.push_back(atoi(str));
	}
	fclose(file);
	return result;
}
void WriteFile(char name[100], vector<vector<int>> result)
{
	FILE *file;
	char str[100] = "", buff[100];
	fopen_s(&file, name, "w");
	for (unsigned int i = 0; i < result.size(); i++)
	{
		for (unsigned int j = 0; j < result[i].size(); j++)
		{
			_itoa_s(result[i][j], buff, 100, 10);
			strcat_s(str, buff);
			if (j != result[i].size() - 1)
			{
				strcat_s(str, " ");
			}
			else if (i != result.size() - 1)
			{
				strcat_s(str, "\n");
			}
		}
		fputs(str, file);
		strcpy_s(str, "");
	}
	fclose(file);
}
void PrintArr(vector<int> arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}