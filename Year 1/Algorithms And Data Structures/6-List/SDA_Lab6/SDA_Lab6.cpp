#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

void insertfromconsole(int&);//введення інформації з консолі
void CreateFirstItem();//створення першого елемента списку
void InsertInBegining();//додавання елемента в початок списку
void outlist();//виведення значень елементів списку
void Tournament(int&);//відтворити змагання команд
void bubblesort(int*, int);//сортування бульбашкою
void insertfromfile(int&);//введення інформації з файлу
void DelMiddle();//видалення елемента з середини списку
void DelFirst();//видалення першого елемента списку
void deletelist(int);//видалення елементу зі списку
bool SearchPlaceDelete(int value);//пошук видаляємого елемента
bool SearchInsertAt(char[100]);
void insertat();
struct Team
{
	char name[100];//назва команди
	int score;//бали команди
	Team *next;//покажчик на наступний елемент списку
};
Team *head, *newptr, *current, *previous;//покажчики на перший, поточний, попередній та новостворенний елемент списку
int main()
{
	int key1, key2, counter = 0;//вибір пункта меню, способу введення інформації, лічильник елементів
	srand(time(0));//ініціалізація генератора випадкових чисел
	cout << "Lab #6\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";//інформація про автора
	cout << "List" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "		MENU		" << endl;//вивід меню
		cout << "1. Insert data to the list of teams." << endl;
		cout << "2. Output the list of teams." << endl;
		cout << "3. Start the tournament." << endl;
		cout << "4. Exit." << endl;
		cout << "Chosen menu item: ";
		cin >> key1;//введення пункта меню
		system("cls");
		switch (key1)
		{
		case 1:
		{
			head = NULL;//звільнення списку
			current = NULL;
			counter = 0;//обнулення к-сті елементів
			cout << "Input from console(1) or from file(2)? ";
			cin >> key2;//вибір варіанту введенння інформації
			if (key2 == 1)
			{
				insertfromconsole(counter);//через консоль
			}
			else
			{
				insertfromfile(counter);//через файл
			}
			break;
		}
		case 2:
		{
			cout << "Participating teams:" << endl;//виведення інформації про команди
			outlist();
			_getch();
			break;
		}
		case 3:
		{
			if (!((counter != 0) && ((counter & (counter - 1)) == 0)))
			{
				cout << "Number of teams must be a power of 2" << endl;;//якщо число команд не є степенем двійки, то вивести повідомлення про помилку
			}
			else
			{
				Tournament(counter);//розпочати змагання
			}
			_getch();
			break;
		}
		case 4:
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
void CreateFirstItem()//створення першого елементу списку
{
	head = newptr;//покажчик на вершину списку перемістити на перший елемент
	head->next = NULL;//покажчик на наступний елемент має значення NULL
}
void InsertInBegining()//додавання елемента в початок списку
{
	newptr->next = head;//зв'язати новий елемент з вершиною списку
	head = newptr;//перемістити вершину списку на елемент, що додається
}
void insertat()
{
	previous->next = newptr;
	newptr->next = current;
}
bool SearchInsertAt(char value[100])
{
	bool flag = false;//ознака успішного пошуку елементу
	current = head;
	do
	{
		previous = current;//перемістити покажчик від попереднього до поточного елемента
		current = current->next;
		if (strcmp(current->name, value) == 0)
		{
			flag = true;//якщо елемент знайдено повернути істину
		}
		else
		{
			flag = false;
		}
	} while ((flag != true) && (current->next != NULL));//виконувати доки не знайдено потрібний елемент або кінець списку
	return flag;
}
void insertfromconsole(int &counter)//введення інформації з консолі
{
	char newname[100], name[100];//назва команди
	bool flag = true;//перевіряє чи продовжувати введення інформації
	char key;//відповідь
	int key1 = 0;
	while (flag)
	{
		cout << "Input name of the team: ";
		cin >> newname;//введення назви команди
		counter++;//збільшення лічильника елементів на 1
		newptr = new Team;//виділення пам'яті для нового елементу списку
		strcpy_s(newptr->name, newname);//введення назви команди до нового елементу
		newptr->score = rand() % 15;//введення балів команди до елемента
		if (head == NULL)//якщо список порожній,сформувати перший елемент списку
		{
			CreateFirstItem();
		}
		else//додавання елмента в початок списку
		{
			cout << "Input in beginning(1) or in the middle(2)?" << endl;
			cin >> key1;
			if (key1 == 1)
			{
				InsertInBegining();
			}
			if (key1 == 2)
			{
				cout << "Input the name of team to input after: ";
				cin >> name;
				SearchInsertAt(name);
				insertat();
			}
		}
		cout << "Continue input?(y/n) ";
		cin >> key;//перевірка чи потрібно продовжувати введення
		if (key == 'n')
			flag = false;
	}
}
void DelFirst()//видалення першого елемента списку
{
	cout << "Team: " << current->name << " Score: " << current->score << endl;//виведення значення видаляємого елементу
	head = current->next;//перемістити вершину на наступний елмент
	delete current;//звільнити пам'ять
}
void DelMiddle()//видалення елемента з середини списку
{
	cout << "Team: " << current->name << " Score: " << current->score << endl;//виведення значення видаляємого елементу
	previous->next = current->next;//наступний елемент для поточного стає наступним для попереднього
	delete current;//звільнити пам'ять
}
bool SearchPlaceDelete(int value)//пошук видаляємого елемента
{
	bool flag = false;//ознака успішного пошуку елементу
	do
	{
		previous = current;//перемістити покажчик від попереднього до поточного елемента
		current = current->next;
		if (current->score == value)
		{
			flag = true;//якщо елемент знайдено повернути істину
		}
		else
		{
			flag = false;
		}
	} while ((flag != true) && (current->next != NULL));//виконувати доки не знайдено потрібний елемент або кінець списку
	return flag;
}

void deletelist(int value)//видалення елементу зі списку
{
	current = head;//покажчик на початок списку
	if (current->score == value)//якщо шуканий елемент є першим
	{
		DelFirst();//видалити перший елемент
	}
	else
	{
		if (SearchPlaceDelete(value) == true)//якщо елемент знайдено
			DelMiddle();//видалити із середини
	}
}
void outlist()//виведення значень елементів списку
{
	current = head;//покажчик на початок списку
	if (current == NULL)//якщо список пустий
	{
		cout << "List of teams is empty" << endl;
	}
	else
	{
		do
		{
			cout << "Team: " << current->name << " Score: " << current->score << endl;//вивести інформацію
			current = current->next;// перемістити покажчик на наступний елемент
		} while (current != NULL);//поки не кінець списку
	}
}
void Tournament(int &count)//відтворити змагання команд
{
	int stages = 1, stage = 2, num = count;//кількість етапів змагання, кількість команд
	while (num != 1)//виконувати ділення поки num не буде дорівнювати 1
	{
		num /= 2;
		stages++;//збільшувати лічильник етапів
	}
	cout << "The tournament will be held in " << stages << " stages" << endl;
	int teams = count;//кількість команд
	cout << setw(20) << "Stage 1" << endl;
	cout << "Participating teams:" << endl;
	outlist();//виведення списку команд
	while (teams != 1)//поки не залишить одна команда
	{
		if (teams > 2)//якщо це не останній етап змагань
		{
			cout << setw(20) << "Stage " << stage << endl;
		}
		current = head;//встановлення покажчика на початок списку
		int *scores = new int[teams];//масив балів команд
		for (int i = 0; i < teams; i++)//заповнення масиву з балами команд
		{
			scores[i] = current->score;
			current = current->next;
		}
		bubblesort(scores, teams);//сортування масиву
		cout << "Eliminated teams: " << endl;
		for (int i = 0; i < (teams / 2); i++)//половина команд з меншими балами видаляється зі змагання
		{
			deletelist(scores[i]);
		}
		current = head;//встановлення покажчика на початок списку
		for (int i = 0; i < (teams / 2); i++)//друга половина команд отримає додаткові бали
		{
			current->score += rand() % 10;
			current = current->next;
		}
		teams = teams / 2;//зменшення к-сті команд
		if (teams == 1)
			cout << "Winner, winner, chicken dinner!" << endl;//вивести повідомлення про переможця
		else
		{
			cout << "Participating teams:" << endl;
		}
		stage++;
		outlist();//виведення команд що залишились
	}
	count = 1;//к-сть команд дорівнює одній
}
void bubblesort(int* arr, int n)//сортування бульбашкою
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
void insertfromfile(int &counter)//введення інформації з файлу
{
	FILE *file;
	char namei[100];
	cout << "Input name of the file: ";
	cin >> namei;//введення назви файлу
	fopen_s(&file, namei, "r");//відриття файлу для читання
	char temp[500];
	char delim[] = "\n ";
	char *next_token = NULL;
	char *p;
	while (!feof(file))//поки не кінець файлу
	{
		fgets(temp, 100, file);//зчитати рядок файлу
		p = strtok_s(temp, delim, &next_token);//розділити йогу
		newptr = new Team;//видлити пам'ять для нового елементу списку
		strcpy_s(newptr->name, p);//скопіювати назву команди
		p = strtok_s(NULL, delim, &next_token);//втсановлення покажчика на бали команди
		newptr->score = atoi(p);//скопіювати їх у елемент
		if (head == NULL)
		{
			CreateFirstItem();//якщо список порожній створити перший елемент
		}
		else
		{
			InsertInBegining();//додавання елмента в початок списку
		}
		counter++;//збільшення к-сті елементів на 1
	}
	fclose(file);
}