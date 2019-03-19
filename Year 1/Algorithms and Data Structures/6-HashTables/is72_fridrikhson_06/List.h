#pragma once
#include <iostream>
using namespace std;

struct List
{
	int num;
	int size;
	List *next;//покажчик на наступний елемент списку
};
List* InitList(int);
List* Add(List*, int);
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