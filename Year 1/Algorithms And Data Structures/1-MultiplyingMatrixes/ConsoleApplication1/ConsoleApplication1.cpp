#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int** CreateMatr(int, int); //створення матриці
void FillMatr(int**, int, int); //заповнення матриці
void PrintMatr(int**, int, int); //виведення матриці
void ChooseName(char*);//іменування файлу
void CreateFile(FILE*, int, int);//створення файлу
int** Multiply(FILE*, FILE*);//множення матриць, збережених у двох файлах
void PrintFile(char*);
char name1[100], name2[100], name3[100];//змінні імен файлів

int main()
{
	FILE *matr1, *matr2, *result; //покажчики на два початкових файли, та файл з результатом множення матриць								
	int** res; //результуюча матриця		 
	int n1, m1, n2, m2; //кількість рядків(N) та ствопців(M) першої та другої матриць
	char str1[100],str2[100];//рядки, що використовуються при виводі файлів
	cout << "Lab #1\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 22\n";
	cout << "Multiplying matrixes" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "			MENU			" << endl;
		cout << "1. Create first file with the matrix" << endl;
		cout << "2. Create second file with the matrix" << endl;
		cout << "3. Multiply matrixes from files" << endl;
		cout << "4. Write matrix into a file" << endl;
		cout << "5. Print matrix from file" << endl;
		cout << "6. Exit" << endl;
		cout << endl;
		int key; //номер варіанту відповіді
		cout << "Choosen menu item: ";
		cin >> key;
		system("cls");
		switch (key) //вибір функцій з меню
		{
			case 1:
			{
				ChooseName(name1); //назва другого файлу
				fopen_s(&matr1, name1, "w"); //відкриття(створення) другого файлу
				cout << "Enter number of rows in 1st matrix: ";
				cin >> n1;
				cout << "Enter number of columns in 1st matrix: ";
				cin >> m1;
				CreateFile(matr1, n1, m1); //створення першого файлу
				break;
			}
			case 2:
			{
				ChooseName(name2); //назва другого файлу
				fopen_s(&matr2, name2, "w"); //відкриття(створення) другого файлу
				cout << "Enter number of rows in 1st matrix: ";
				cin >> n2;
				cout << "Enter number of columns in 1st matrix: ";
				cin >> m2;
				CreateFile(matr2, n2, m2); //створення першого файлу
				break;
			}
			case 3:
			{
				fopen_s(&matr1, name1, "r");
				fopen_s(&matr2, name2, "r");
				res = Multiply(matr1, matr2);
				fclose(matr1); //закриття файлів
				fclose(matr2);
				system("pause");
				break;
			}
			case 4:
			{
				ChooseName(name3);//назва файла з результатом
				fopen_s(&result, name3, "w"); //створення файлу
				char buff[20]; //буфер для функції _itoa_s
				for (int i = 0; i < n1; i++)
				{
					for (int j = 0; j < m2; j++)
					{
						_itoa_s(res[i][j], buff, 20, 10); //конвертація чисел матриці у символи
						fputs(buff, result); //запис у файл
						fputs(" ", result);
					}
					if (i != m2 - 1)
						fputc('\n', result);
				}
				fclose(result);
				break;
			}
			case 5:
			{
				char file[20]; //ім'я файлу та рядок файлу
				ChooseName(file);
				PrintFile(file);
				system("pause");
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
			default:
			{
				cout << "Try another time...";
				_getch();
				break;
			}
			
		}
	}
    return 0;
}
void CreateFile(FILE* file, int n, int m)
{
	fflush(stdin);
	char n1[20], m1[20], z[20], name[100];
	int** matr;
	matr = CreateMatr(n,m);
	FillMatr(matr, n, m);//генерація матриці
	_itoa_s(n, n1, 20, 10); //форматування цілочислених значень кількості рядків та 
	_itoa_s(m, m1, 20, 10); //стовпчиків у символи для запису у перший рядок файлу
	fputs(n1, file); //запис кількості рядків та стовпчиків у файл
	fputs(" ", file);
	fputs(m1, file);
	fputc('\n', file);
	for (int i = 0; i < n; i++) //запис матриці у файл
	{
		for (int j = 0; j < m; j++)
		{
			_itoa_s(matr[i][j], z, 20, 10);
			fputs(z, file);
			fputs(" ", file);
		}
		if (i != n-1)
			fputc('\n', file);
	}
	fclose(file);
}
void ChooseName(char* name)
{
	cout << "Enter the name of the file: ";
	cin >> name;
	strcat_s(name, 40, ".txt"); //додавання до імені приставки з форматом
}

int** Multiply(FILE* file1, FILE* file2)
{
	char temp1[500], temp2[500], t1[100], t2[100]; //буфери для функцій
	char matr1[500] = "", matr2[500] = ""; //масиви з матрицями
	int r1, c1, r2, c2; //кількість рядків(R) та стовпчиків(C) матриць
	int count = 0, innercount = 0; //покажчики на символи у файлі, лічильник індексу символа
	char delim[] = "\n "; //роздільники
	char *next_token1 = NULL; //покажчики на наступне число
	char *next_token2 = NULL;
	fgets(t1, 100, file1); //зчитує перші рядки файлів
	fgets(t2, 100, file2);
	char *p1 = strtok_s(t1, delim, &next_token1); //покажчики на числа
	char *p2 = strtok_s(t2, delim, &next_token2);
	while (!feof(file1)) //зчитування матриці з першого файлу
	{
		
		if (count == 0)
		{
			
			while (innercount < 2)
			{
				
				if (innercount == 0)//визначення кількості рядків та стовпчиків матриці
					r1 = atoi(p1);
				if (innercount == 1)
				{
					c1 = atoi(p1);
				}
				p1 = strtok_s(NULL, delim, &next_token1); 
				innercount++;
			}
		}
		else
		{
			fgets(temp1, 100, file1); //копіювання матриці
			strcat_s(matr1, 500, temp1);
		}
		count++;
	}
	count = 0;
	innercount = 0;
	while (!feof(file2)) //зчитування матриці з другого файлу
	{
		
		if (count == 0)
		{
			while (innercount < 2)
			{
				if (innercount == 0)//визначення кількості рядків та стовпчиків матриці
					r2 = atoi(p2);
				if (innercount == 1)
				{
					c2 = atoi(p2);
				}
				p2 = strtok_s(NULL, delim, &next_token2);
				innercount++;
			}
		}
		else
		{
			fgets(temp2, 100, file2);//копіювання матриці
			strcat_s(matr2, 500, temp2);
		}
		count++;
	}
	p1 = NULL; //очищення покажчиків
	p2 = NULL;
	next_token1 = NULL;
	next_token2 = NULL;
	if (c1 != r2) //якщо кількість стовпців першого файла не дорівнює
	{			  //кількості рядків другого, тоді множення неможливе
		cout << "Invalid parameters" << endl;
	}
	else
	{
		p1 = strtok_s(matr1, delim, &next_token1); //встановлення нових покажчиків
		p2 = strtok_s(matr2, delim, &next_token2);
		int **arr1 = CreateMatr(r1, c1); //створення масива для першої матриці
		int **arr2 = CreateMatr(r2, c2);//для другої
		for (int i = 0; i < r1; i++) //поділ матриць на окремі числа, запис значень у цілочислені матриці
		{ 
			for (int j = 0; j < c1; j++)
			{
				arr1[i][j] = atoi(p1);
				p1 = strtok_s(NULL, delim, &next_token1);
			}
		}
		for (int i = 0; i < r2; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				arr2[i][j] = atoi(p2);
				p2 = strtok_s(NULL, delim, &next_token2);
			}
		}
		int **arr3 = CreateMatr(r1,c2);//створення матриці для результатів множення двух даних матриць
		for (int i = 0; i < r1; i++) //ініціалізація значень
		{
			for (int j = 0; j < c2; j++)
			{
				arr3[i][j] = 0;
			}
		}
		for (int i = 0; i < r1; i++) //отримання матриці, утвореної множенням даних двух
		{
			for (int j = 0; j < c2; j++)
			{
				for (int k = 0; k < c1; k++) //кількість доданків дорівнює кількості стовпців першої матриці
				{
					arr3[i][j] += (arr1[i][k] * arr2[k][j]);
				}
			}
		}
		cout << "Result matrix:" << endl;
		PrintMatr(arr3, r1, c2); //виведення результуючої матриці
		return arr3;
	}
}
int** CreateMatr(int n, int m) //створення матриці
{
	int **matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
	}
	return matr;
}
void PrintMatr(int** matr, int n, int m) //виведення матриці
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}
void FillMatr(int** matr, int n, int m) //заповнення матриці довільним значеннями
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			matr[i][j] = rand() % 20 - 10;
		}
	}
}
void PrintFile(char* file)
{
	FILE* selected;
	char row[100];
	fopen_s(&selected, file, "r");
	while (!feof(selected))
	{
		fgets(row, 100, selected);
		cout << row;
	}
	cout << endl;
	fclose(selected);
}