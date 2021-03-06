#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <ctime>
#include <string>
using namespace std;

char letter;//поточний символ 
void getdel(char&); //видалення та збереження елемента з черги
void add(char&); //додавання елемента у чергу
void Visualise(); //візуалізація роботи черги
struct Letters { //структура, яка містить літеру та покажчик на наступний елемент черги
	char alpha;
	Letters* next;
};
Letters *head, *current, *last;//покажчики на початковий, поточний, та останній елементи черги
int main()
{
	int key;//вибір пункта меню
	cout << "Lab #5\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора
	cout << "Queue" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "		MENU		" << endl;//вивід меню
		cout << "1. Start visualisation of the queue." << endl;
		cout << "2. Exit" << endl;
		cout << "Chosen menu item: ";
		cin >> key;//введення пункта меню
		system("cls");
		switch (key)
		{
		case 1:
		{
			Visualise();//візуалізація роботи черги
			break;
		}
		case 2:
		{
			exit(0);//вихід з програми
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
void add(char &letter)//додавання елемента у чергу
{
	current = new Letters;//виділити пам’ять для нового елемента черги
	current->alpha = letter;//запис символа
	current->next = NULL;//встановити ознаку кінця черги
	if (last == NULL)//якщо створюється перший елемент,
	{				 //ініціалізувати покажчик на початок черги
		head = current;
	}
	else//якщо ні, зв'язати колишній кінець черги із новим елементом
	{
		last->next = current;
	}
	last = current;//новий елемент вважати останнім
}
void getdel(char &letter)//видалення та збереження елемента з черги
{
	current = head; //зберегти адресу вершини черги
	letter = head->alpha; //зберегти значення, що виводяться
	head = current->next; //перемістити вершину черги на інший елемент
	if (head == NULL) //якщо черга стала порожньою,
	{				  //порожнім має стати і кінець черги
		last = NULL;
	}
	delete current; //звільнити пам'ять
}
void Visualise()//візуалізація роботи черги
{
	srand(time(0));//ініціаалізація генератора випадкових чисел
	int ascii, rnd1, rnd2;//змінні для коду символа та результатів роботи rand 
	string str;//рядок з символами черги
	while (1)
	{
		system("cls");
		rnd1 = rand() % 2;//визначення операції видалення або додавання
		rnd2 = rand() % 3;//визначення к-сті лементів, які будуть видалятись\додаватись
		if (rnd1 == 0 && last != NULL)//якщо черга не пуста та визначена операція видалення
		{
			for (int i = 0; i < rnd2 + 1; i++)//для визначеної к-сті елементів 
			{
				if (last == NULL)//якщо черга пуста закінчити роботу
				{
					break;
				}
				else
				{
					getdel(letter);//видалити елемент черги
					str.erase(0, 1);//видалити елемент з рядка
					str.erase(0, 1);
				}
			}
			cout << str << endl;//вивести рядок
		}
		else
		{
			for (int i = 0; i < rnd2 + 1; i++)//для визначеної к-сті елементів 
			{
				ascii = 97 + rand() % (122 - 97);//згенерувати випадкове число в діапазоні від 122 до 97
				letter = (char)ascii;//конвертувати код ASCII у символ
				add(letter);//додати елемент до стеку
				str += letter;//додати елемент до рядка
				str += " ";
			}
			cout << str << endl;//вивести рядок
		}
		cout << "To exit press any button" << endl;
		Sleep(500);//затримати наступну ітерацію на 0.5 секунди
		if (_kbhit())//якщо відбулося натиснення на клавішу клавіатури
		{
			return;//закінчити роботу функції
		}
	}
}

