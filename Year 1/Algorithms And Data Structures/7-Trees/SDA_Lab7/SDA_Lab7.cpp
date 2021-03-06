#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

struct Node //структура типу дерево
{
	int num;//інформаційне поле
	Node *left, *right;//покажчики на ліве та праве піддерева
};
Node *root;//покажчик на корінь дерева
void InsertData(char[100]);//додавання данних з файлу у дерево
void CreateTree(Node**, int*, int, int&);//створення дерева
void PrintTree(Node**, int);//вивід дерева на екран
void MinMaxSwap(Node**, int&, int&, int**, int**, int&, int&, int);//зміна місцями максимального та мінімального елементів
void remove(Node**, int);
int main()
{
	
	int key, min, max, maxlevel, minlevel;//вибір пункта меню; максимальний та мінімальний елементи, номери рівнів на яких вони знаходяться
	int *MaxPtr, *MinPtr;//покажчики на максимальний та мінімальний елементи дерева
	char name[100], value[10];//назва файлу з вхідними даними
	cout << "Lab #7\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора
	cout << "Tree" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "		MENU		" << endl;//вивід меню
		cout << "1. Insert data to the tree." << endl;
		cout << "2. Print the tree." << endl;
		cout << "3. Find and swap max and min elements in the tree." << endl;
		cout << "4. Exit." << endl;
		cout << "5. Remove node." << endl;
		cout << "Chosen menu item: ";
		cin >> key;//введення пункта меню
		system("cls");
		switch (key)
		{
		case 1:
		{
			cout << "Input the name of the file: ";//введення назви файлу
			cin >> name;
			InsertData(name);//створення дерева за данними з файлу
			cout << "Data was successfully inserted" << endl;
			_getch();
			break;
		}
		case 2:
		{
			if (root != NULL)//якщо дерево не пусте
			{
				cout << "Tree: " << endl;
				PrintTree(&root, 0);//вивести на екран
			}
			else
			{
				cout << "Tree is empty" << endl;//вивести повідомлення
			}
			_getch();
			break;
		}
		case 3:
		{
			if (root != NULL)//якщо дерево не пусте
			{
				cout << "Tree before swap: " << endl;
				PrintTree(&root, 0);//вивести на екран дерево до зміни
				min = root->num;//призначити значення кореневого елемента дерева 
				max = root->num;
				MinMaxSwap(&root, min, max, &MaxPtr, &MinPtr, maxlevel, minlevel, 1);//визначити значення мінімального та максимального елемента, встановити на них покажчики
				cout << "Max value is " << max << " at level " << maxlevel << endl;//вивести їх значення та позиції
				cout << "Min value is " << min << " at level " << minlevel << endl;
				swap(*MinPtr, *MaxPtr);//поміняти місцями ці елементи
				cout << "Tree after swap: " << endl;
				PrintTree(&root, 0);//вивести на екран дерево після зміни
			}
			else
			{
				cout << "Tree is empty" << endl;//вивести повідомлення
			}
			_getch();
			break;
		}
		case 4:
		{
			exit(0);//вихід з програми
		}
		case 5:
		{
			cout << "Input the value of node to delete: ";
			cin >> value;
			remove(&root, atoi(value));
			cout << "Node was deleted" << endl;
			_getch();
			break;
		}
		default:
		{
			cout << "Choose another menu member" << endl;
			_getch();
			break;
		}
		}
	}
	system("pause");
    return 0;
}
void CreateTree(Node **ptr, int *values, int nodeamount, int &current)//створення дерева
{
	int LeftNodes, RightNodes;//к-сть вузлів у лівому та правому піддеревах
	if (nodeamount == 0)//якщо вузлів немає 
	{
		*ptr = 0;//тоді дерево порожнє
	}
	else
	{
		LeftNodes = nodeamount / 2;//визначення к-сті вузлів у піддеревах
		RightNodes = nodeamount - LeftNodes - 1;
		*ptr = new Node;//виділення пам'яті для вузла дерева
		(*ptr)->num = values[current];//занести значення у вузол
		(*ptr)->left = 0;//обнулити покажчики на піддерева
		(*ptr)->right = 0;
		current++;//перейти до наступного введеного значення
		CreateTree(&((*ptr)->left), values, LeftNodes, current);//стуворити ліве піддерево
		CreateTree(&((*ptr)->right), values, RightNodes, current);//створити праве піддерево
	}
}
void PrintTree(Node **TreeRoot, int level)//вивід дерева на екран
{
	if ((*TreeRoot != NULL))//якщо дерево не порожнє
	{
		PrintTree(&((*TreeRoot)->left), level + 1);//вивести ліве піддерево
		for (int i = 0; i < level; i++)//форматувати виведення дерева
		{
			cout << "     ";
		}
		cout << (*TreeRoot)->num << endl;//вивести значення вузла
		PrintTree(&((*TreeRoot)->right), level + 1);//вивести праве піддерево
	}
}
void remove(Node **TreeRoot, int value)
{
	if ((*TreeRoot) != NULL) {
		if ((*TreeRoot)->num == value) {
			Node* ptr = (*TreeRoot);
			if ((*TreeRoot)->left == NULL && (*TreeRoot)->right == NULL)
			{
				(*TreeRoot) = NULL;
			}
			else if ((*TreeRoot)->left == NULL)
			{
				(*TreeRoot) = ptr->right;
			}
			else if ((*TreeRoot)->right == NULL)
			{
				(*TreeRoot) = ptr->left;
			}
			else
			{
				(*TreeRoot) = ptr->right;
				Node** ptr1;
				ptr1 = TreeRoot;
				while (*ptr1 != NULL)
					ptr1 = &((*ptr1)->left);
				(*ptr1) = ptr->left;
			}
			delete(ptr);
			remove(TreeRoot, value);
		}
		else {
			remove(&((*TreeRoot)->left), value);
			remove(&((*TreeRoot)->right), value);
		}
	}
}
void InsertData(char name[100])//додавання данних з файлу у дерево
{
	FILE *file;//покажчик на файл
	char str[100];//рядок файлу
	char delim[] = " ";//роділяючі символи
	char *next_token = NULL, *p;//покажчик на наступний та поточний елемент рядка
	int size, i = 0, current = 0;//к-сть елементів дерева, лічильник елемента, поточний елемент масиву значень 
	fopen_s(&file, name, "r");//відкриття файлу
	fgets(str, 100, file);//зчитати перший рядок файлу
	size = atoi(str);//визначити к-сть елементів дерева
	int *values = new int[size];//створити масив значень
	fgets(str, 100, file);//зчитати наступний рядок файлу
	p = strtok_s(str, delim, &next_token);//розділити рядок на окремі значення
	while (p != NULL)//доки не буде досягнуто кінця рядка
	{
		values[i] = atoi(p);//занести значення у масив
		p = strtok_s(NULL, delim, &next_token);//перейти до наступного елементу рядка
		i++;//перейти до наступної комірки масиву
	}
	CreateTree(&root, values, size, current);//створити дерево відповідно до значень з масиву
	fclose(file);//закрити файл
}
void MinMaxSwap(Node **TreeRoot, int &min, int &max, int **MaxPtr, int **MinPtr, int &maxlevel, int &minlevel, int currentlevel)
{
	if ((*TreeRoot != NULL))//якщо дерево не пусте
	{
		MinMaxSwap(&((*TreeRoot)->left), min, max, MaxPtr, MinPtr, maxlevel, minlevel, currentlevel+1);//розпочати пошук у лівому піддереві
		if ((*TreeRoot)->num > max)//якщо поточний елемент більше за максимальний
		{
			max = (*TreeRoot)->num;//визначити його як максимальний
			*MaxPtr = new int;//виділити пам'ять для покажчика на елемент
			*MaxPtr = &(*TreeRoot)->num;//встановити покажчик на елемент
			maxlevel = currentlevel;//записати позицію елемента
		}
		if ((*TreeRoot)->num < min)//якщо поточний елемент менше за мінімальний
		{
			min = (*TreeRoot)->num;//визначити його як мінімальний
			*MinPtr = new int;//виділити пам'ять для покажчика на елемент
			*MinPtr = &(*TreeRoot)->num;//встановити покажчик на елемент
			minlevel = currentlevel;//записати позицію елемента
		}
		MinMaxSwap(&((*TreeRoot)->right), min, max, MaxPtr, MinPtr, maxlevel, minlevel, currentlevel+1);//розпочати пошук у правому піддереві
	}
}