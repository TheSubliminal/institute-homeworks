#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int number, counter = 0; //поточний елемент стеку, к-сть елементів
bool CheckTriangle(int, int, int); //первеірка чи прямокутний трикутник
int radius(int, int, int);//розрахунок радіусу вписаного кола
int max(int, int);//визначення максимального з двох чисел
void CheckAndCalc(char[100]);//переверіка трикутників, обчислення радусів вписаних кіл, запис до стеку
void input(char[100]);//введення чисел до стеку з файлу
void push(int&);//додавання елемента у стек
void pop(int&);//отримання елемента зі стеку
struct Numbers //структура, яка містить розміри трикутників,
{              //радіуси їх вписаних кіл та покажчик на наступний елемент стеку
	int num;
	Numbers* next;
};
Numbers *head, *current;//покажчики на верхній та поточний елемент стеку
int main()
{
	int key;//пункт меню
	char name[100];//назва файлу
	cout << "Lab #4\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора
	cout << "Stack" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "		MENU		" << endl;//вивід меню
		cout << "1. Read data from file and write to stack" << endl;
		cout << "2. Print contents of the stack" << endl;
		cout << "3. Check triangles and calculate radiuses" << endl;
		cout << "4. Exit" << endl;
		cout << "Chosen menu item: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
		{
			cout << "Input the name of the file: ";
			cin >> name;
			input(name); //заповнення стеку значеннями з файлу
			break;
		}
		case 2:
		{
			cout << "Stack contents" << endl;
			while (head != NULL)//доки покажчик на голову не буде пустим
			{
				pop(number);//виводити елементи стеку
				cout << number << " ";
			}
			cout << endl;
			cout << "Stack is empty" << endl;
			counter = 0;//к-сть елементів = 0
			_getch();
			break;
		}
		case 3:
		{
			if (counter % 3 == 0 && counter != 0)//якщо к-сть елементів кратна 3 та не дорівнює 0
			{
				CheckAndCalc(name);//перевірити трикутники та обрахувати радіуси їх вписаних кіл
			}
			else if (counter != 0)
			{
				cout << "Number of numbers is not dividable by 3" << endl;
				_getch();
			}
			else
			{
				cout << "Please fill the stack" << endl;
				_getch();
			}
			break;
		}
		case 4:
		{
			exit(0); //закриття програми
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
	return 0;
}
bool CheckTriangle(int a, int b, int c)//первеірка чи прямокутний трикутник
{
	if ((a + b) > c && (b + c) > a && (a + c) > b)//якщо кожна сума двох сторін більша за третю
	{
		if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(c, 2) + pow(b, 2) == pow(a, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2))//якщо теорема Піфагора справджується
		{
			cout << "Triangle is right" << endl;
			return true;
		}
		else
		{
			cout << "Unable to build right triangle" << endl;
			return false;
		}
	}
	else
	{
		cout << "Unable to build triangle" << endl;
		return false;
	}
}
void input(char name[100])//введення чисел до стеку з файлу
{
	FILE *file;
	char buff[100];//буфер для поточного рядка файлу
	fopen_s(&file, name, "r");//відкриття файлу для читання
	while (!feof(file))//якщо не кінець файлу
	{
		fgets(buff, 100, file);//зчитати рядок з файлу
		number = atoi(buff);//конвертувати у цілочисельний тип
		push(number);//додати до стеку
		counter++;//збільшити лічильник елементів на 1
	}
	fclose(file);//закрити файл
}
void push(int &number)//додавання елемента у стек
{
	current = new Numbers;//виділити пам’ять для нового елемента стеку
	current->num = number;//запис числа 
	current->next = head;//зв’язати допоміжний елемент із вершиною
	head = current;//встановити вершину стеку на новостворений елемент
}
void pop(int &number)//отримання елемента зі стеку
{
	current = head;//створити копію покажчика на вершину стеку
	number = head->num;//замінити верхній елемент елементом з голови стеку
	head = current->next;//перемістити покажчик на вершину стеку на наступний елемент
	delete current;//звільнити пам’ять із-під колишньої вершини стеку
}
int max(int a, int b)//визначення максимального з двох чисел
{
	return (a < b) ? b : a;
}
int radius(int a, int b, int c)//розрахунок радіусу вписаного кола
{
	int Max = max(max(a, b), c);//пошук гіпотенузи трикутника
	if (Max == a)
		return ((b + c - a) / 2);
	else if (Max == b)
		return ((a + c - b) / 2);
	else if (Max == c)
		return ((a + b - c) / 2);
}
void CheckAndCalc(char name[100])//переверіка трикутників, обчислення радуіів вписаних кіл, запис до стеку
{
	int innercounter = 0, i = 0;//лічильник кількості трикутників
	int a, b, c, r;
	bool flag = true;//перевірка чи всі трикутники прямокутні
	while (head != NULL)//доки стек не пустий
	{
		pop(number);//вивід сторін трикутників зі стеку
		a = number;
		pop(number);
		b = number;
		pop(number);
		c = number;
		innercounter++;
		if (CheckTriangle(a, b, c))//якщо трикутник правильний продовжувати перевірку
			continue;
		else//якщо ні, то вивести повідомлення на екран, закінчити перевірку
		{
			cout << "Problem with triangle: #" << innercounter << endl;
			flag = false;
			_getch();
			break;
		}
	}
	if (flag == true)//якщо всі трикутники прямокутні
	{
		int* radiuses = new int[innercounter];//масив з радіусами трикутників
		input(name);//повторне заповнення стеку
		while (head != NULL)//доки стек не пустий
		{
			pop(number);//отримання чисел зі стеку
			a = number;
			pop(number);
			b = number;
			pop(number);
			c = number;
			radiuses[i] = radius(a, b, c);//обрахунок радіусів
			i++;
		}
		input(name);//повторне заповнення стеку
		for (int i = innercounter - 1; i >= 0; i--)//додавання радіусів до стеку
		{
			push(radiuses[i]);
		}
	}
}