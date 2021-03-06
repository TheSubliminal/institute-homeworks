#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdarg.h>
using namespace std;

int gcd(int, int);//НСД для двух чисел
int gcdforn(int, ...);//НСД для невизначеної кількості чисел
int main()
{
	cout << "Lab #3\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//Вивід інформації про автора та програму
	cout << "Using macros and preprocessing directive." << endl;
	system("pause");
	system("cls");
	int gcdn = 0, n1 = 0, num = 0;//створення змінних
	gcdn = gcdforn(5, 27, 9, 63, 45, 81);//обчислення НСД для заданих аргументів(перший аргумент - к-сть аргументів)
	cout << "Result: " << gcdn << endl;//виведеня знайденого НСД
	system("pause");
}
int gcdforn(int num, ...)
 {
	va_list argptr;//створення змінних
	va_start(argptr, num);//ініціалізація списку аргументів
	int current, gcdn = 0;
	cout << "Input list:";
	while (num--)//поки список аргументів не скінчиться
	{
		current = va_arg(argptr, int);//присвоєння значень елементів змінній
		cout << setw(4) << current;
		gcdn = gcd(gcdn, current);//визначення НСД попередніх чисел та наступного
	}
	cout << endl;
	va_end(argptr);//закриття списку аргументів
	return gcdn;
}
int gcd(int a, int b)
{
	if (b == 0) 
	{
		if (a == 0)//якщо перший та другий елемент дорівнуює нулю, то повернути 0
			return 0;
		else 
			return a;//якщо тільки другий аргумент дорівнює нулю, то повернути перший 
	}
	else abs(gcd(b, a % b));//рекурсивне виконяння алгоритму Евкліда
}
