#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <ctime>
using namespace std;

void input(FILE*);//введення файлу
void read(FILE*);//зчитування з файлу
void overwrite(FILE*);//перезапис полів файлу
void deleteinfo(FILE*);//видалення полів
void findbybook(FILE*);//пошук читача за книгою, яку він взяв
void addinfo(FILE*);//додавання інформації
void findbydate(FILE*);//пошук книги за терміном повернення
void finddebtor(FILE*);//пошук боржників
struct reader //структура читача
{
	char surname[100];
	char adress[100];
	char date[100];
	int bookn = 0;
};
struct book //структура книги
{
	char title[100];
	char author[100];
	int year;
};
struct library //збірна структура
{
	book books[10];
	reader reader;
};
int main()
{
	FILE *file = NULL;
	int key;
	cout << "Lab #2\nName: Michael Fridrikhson\nGroup: IS-72\nFaculty: FIOT\nVariant: 23\n";
	cout << "Readers database" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "		MENU		" << endl;//вивід меню
		cout << "1. Database input" << endl;
		cout << "2. Read data from file" << endl;
		cout << "3. Search readers by taken book" << endl;
		cout << "4. Search book by the date of returning" << endl;
		cout << "5. Find the debtors" << endl;
		cout << "6. Add info to file" << endl;
		cout << "7. Overwrite info" << endl;
		cout << "8. Delete info" << endl;
		cout << "9. Exit" << endl;
		cout << "Chosen menu item: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
		{
			input(file); //введення інформації
			break;
		}
		case 2:
		{
			read(file); //зчитування інформації
			break;
		}
		case 3:
		{
			findbybook(file);//пошук читача, який має задану книгу
			break;
		}
		case 4:
		{
			findbydate(file); //пошук книги заданого автора, яку забрали до заданого терміну
			break;
		}
		case 5:
		{
			finddebtor(file); //пошук боржників
			break;
		}
		case 6:
		{
			addinfo(file); //додавання інформації у файл
			break;
		}
		case 7:
		{
			overwrite(file); //перезапис інформації файлу
			break;
		}
		case 8:
		{
			deleteinfo(file); //видалення інформації файлу
			break;
		}
		case 9:
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
void input(FILE *file)//введення інформації
{
	library visitors[10];//створення масиву структур
	char ans_reader, ans_book;//змінні  відповіді для продовженння або завершення циклів
	int i, j;
	fseek(stdin, 0, SEEK_END); //встановлення покажчика в потоці вводу в кінець
	if (file != NULL)//якщо файл не пустий, видалити існуючий
	{
		remove("file.dat");
	}
	else
	{
		fopen_s(&file, "file.dat", "wb");//створення файлу для запису
		i = 0;
		do//заповнення полів структур
		{
			cout << "Reader's surname: ";
			cin.getline(visitors[i].reader.surname, 100, '\n');
			cout << "Reader's adress: ";
			cin.getline(visitors[i].reader.adress, 100, '\n');
			cout << "Return book by(DD.MM.YYYY): ";
			cin.getline(visitors[i].reader.date, 100, '\n');
			j = 0;
			do
			{
				cout << "Book's title: ";
				cin.getline(visitors[i].books[j].title, 100, '\n');
				cout << "Book's author: ";
				cin.getline(visitors[i].books[j].author, 100, '\n');
				cout << "Year of publication: ";
				cin >> visitors[i].books[j].year;
				j++;
				cout << "Continue input of books? y/n" << endl;
				ans_book = _getch();
				cin.ignore();
			} while (ans_book != 'n');
			visitors[i].reader.bookn = j;
			fwrite(&visitors[i], sizeof(library), 1, file);//запис структури у файл
			cout << "Continue input of readers? y/n" << endl;
			ans_reader = _getch();//продовження або завершення
			i++;
		} while (ans_reader != 'n');
		fclose(file);
	}
}
void read(FILE *file)//зчитування інформації
{
	library visitor;
	fopen_s(&file, "file.dat", "rb");//відкриття файлу для читання
	cout << "File: " << endl;
	fread(&visitor, sizeof(library), 1, file);//зчитування першого рядка
	while (!feof(file))//виведення полів структур
	{
		cout << "Reader" << endl;
		cout.setf(ios::left);
		cout << "Surname-----Adress----------Date" << endl;
		cout << setw(12) << visitor.reader.surname << setw(16) << visitor.reader.adress << setw(18) << visitor.reader.date << endl;
		cout << "Books" << endl;
		cout.setf(ios::left);
		cout << "Author------Title-----------------Year" << endl;
		for (int j = 0; j < visitor.reader.bookn; j++)
		{
			cout.setf(ios::left);
			cout << setw(12) << visitor.books[j].author << setw(18) << visitor.books[j].title << setw(18) << visitor.books[j].year << endl;
		}
		cout << endl;
		fread(&visitor, sizeof(library), 1, file);//зчитування наступного рядка
	}
	fclose(file);//закриття файлу
	_getch();
}
void findbybook(FILE* file)//пошук читача, який має задану книгу
{
	library visitor;
	char title[100];
	fseek(stdin, 0, SEEK_END);//встановлення покажчика в потоці вводу в кінець
	fopen_s(&file, "file.dat", "rb");//відкриття файлу для читання
	cout << "Enter title of the book: ";
	cin.getline(title, 100, '\n');//ведення назви книги
	cout << "Readers with this book:" << endl;
	while (!feof(file))
	{
		for (int i = 0; i < visitor.reader.bookn; i++)
		{
			if (strcmp(title, visitor.books[i].title) == 0)//якщо данні поля збігаються з заданою назвою,то вивести прізвище читача на екран
			{
				cout << visitor.reader.surname << endl;
			}
		}
		fread(&visitor, sizeof(library), 1, file);
	}
	fclose(file);//закриття файлу
	_getch();
}
void findbydate(FILE* file)//пошук книги заданого автора, яку забрали до заданого терміну
{
	library visitor;
	char author[100], date[100];//змінні для дати та автора
	fseek(stdin, 0, SEEK_END);//встановлення покажчика в потоці вводу в кінець
	fopen_s(&file, "file.dat", "rb");//відкриття файлу для читання
	cout << "Enter author of the book: ";//введення дати та автора
	cin.getline(author, 100, '\n');
	cout << "It should be brought back by(DD.MM.YYYY): ";
	cin.getline(date, 100, '\n');
	cout << "Selected books: " << endl;
	while (!feof(file))
	{
		for (int i = 0; i < visitor.reader.bookn; i++)//пошук книги
		{
			if (strcmp(author, visitor.books[i].author) == 0 && strcmp(date, visitor.reader.date) == 0)
			{
				cout << "Taken by: " << visitor.reader.surname << " Book: " << visitor.books[i].title << endl;
			}
		}
		fread(&visitor, sizeof(library), 1, file);
	}
	fclose(file);
	_getch();
}
void finddebtor(FILE* file)//пошук боржників
{
	library visitor;
	char date[100], count = 0;
	int datei[3], day, month, year;
	fseek(stdin, 0, SEEK_END);//встановлення покажчика в потоці вводу в кінець
	fopen_s(&file, "file.dat", "rb");
	time_t now = time(0);//отримання поточної дати
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
	day = timeinfo.tm_mday;//конвертація в цілочсельний тип
	month = timeinfo.tm_mon + 1;
	year = timeinfo.tm_year + 1900;
	cout << "Debtors are: " << endl;
	while (!feof(file))//пошук боржників
	{
		int k = 0;
		char delimiter[] = ". ";
		char *p;
		char *np = NULL;
		p = strtok_s(visitor.reader.date, delimiter, &np);//розділення поля дати у структурі на окремі числа
		while (p != NULL)//представлення у вигляді масиву чисел
		{
			datei[k] = atoi(p);
			k++;
			p = strtok_s(NULL, delimiter, &np);
		}
		if (year > datei[2] && count > 0)//якщо рік у полі структури менше поточного, тобі вивести прізвище боржника
		{
			cout << visitor.reader.surname << endl;
		}
		else if (year == datei[2] && count > 0) //якщо рік дорівнює поточному, тоді продовжити порівняння за місяцем
		{
			if (month > datei[1])//якщо номер місяця менше поточного, то вивести прізвище боржника
			{
				cout << visitor.reader.surname << endl;
			}
			else if (month == datei[1])//якщо дорівнює поточному, то перевірити день
			{
				if (day > datei[0])
				{
					cout << visitor.reader.surname << endl;
				}
			}
		}
		fread(&visitor, sizeof(library), 1, file);
		count++;
	}
	fclose(file);
	_getch();
}
void addinfo(FILE* file)//додавання інформації у файл
{
	library visitors[10];
	fopen_s(&file, "file.dat", "ab");//відкриття файлу для додавання інформації
	char ans_reader, ans_book;
	int i, j;
	fseek(stdin, 0, SEEK_END);//встановлення покажчика в потоці вводу в кінець
	i = 0;
	do//заповнення полів значеннями
	{
		cout << "Reader's surname: ";
		cin.getline(visitors[i].reader.surname, 100, '\n');
		cout << "Reader's adress: ";
		cin.getline(visitors[i].reader.adress, 100, '\n');
		cout << "Return book by(DD.MM.YYYY): ";
		cin.getline(visitors[i].reader.date, 100, '\n');
		j = 0;
		do
		{
			cout << "Book's title: ";
			cin.getline(visitors[i].books[j].title, 100, '\n');
			cout << "Book's author: ";
			cin.getline(visitors[i].books[j].author, 100, '\n');
			cout << "Year of publication: ";
			cin >> visitors[i].books[j].year;
			j++;
			cout << "Continue input of books? y/n" << endl;
			ans_book = _getch();
			cin.ignore();
		} while (ans_book != 'n');
		visitors[i].reader.bookn = j;
		fwrite(&visitors[i], sizeof(library), 1, file);//запис у файл
		cout << "Continue input of readers? y/n" << endl;
		ans_reader = _getch();
		i++;
	} while (ans_reader != 'n');
	fclose(file);
}
void overwrite(FILE* file)//перезапис інформації файлу
{
	FILE *newf;//показник на новий файл
	library visitors1, visitors2[10];//початкова структура з файлу, масив нових структур
	char surn[100], field[100], newval[100], ans;
	int count = 0, k;
	fopen_s(&file, "file.dat", "rb");//відкриття почтаткового файлу для читання
	fopen_s(&newf, "newf.dat", "wb");//відкриття нового файлу для запису інформації
	cout << "Surname of reader to edit info of: ";
	cin >> surn;//вибір прізвища читача для перезапису його інформації
	while (!feof(file))
	{
		fread(&visitors1, sizeof(library), 1, file);//зчитування інформації
		if (feof(file))
			break;
		if (strcmp(visitors1.reader.surname, surn) == 0)//якщо прізвище читача дорівнює задаому, тоді вивести інформації про нього
		{
			cout << "Surname-----Adress----------Date" << endl;
			cout << setw(12) << visitors1.reader.surname << setw(16) << visitors1.reader.adress << setw(18) << visitors1.reader.date << endl;
			cout << "Books" << endl;
			cout.setf(ios::left);
			cout << "Author------Title-----------------Year" << endl;
			for (int j = 0; j < visitors1.reader.bookn; j++)
			{
				cout.setf(ios::left);
				cout << setw(12) << visitors1.books[j].author << setw(18) << visitors1.books[j].title << setw(18) << visitors1.books[j].year << endl;
			}
			k = count;//записати порядковий номер структури
		}
		visitors2[count].reader = visitors1.reader;//копіювання значень зі структури у нову
		strcpy_s(visitors2[count].reader.surname, visitors1.reader.surname);
		strcpy_s(visitors2[count].reader.adress, visitors1.reader.adress);
		strcpy_s(visitors2[count].reader.date, visitors1.reader.date);
		visitors2[count].reader.bookn = visitors1.reader.bookn;
		for (int i = 0; i < visitors1.reader.bookn; i++)
		{
			visitors2[count].books[i] = visitors1.books[i];
			strcpy_s(visitors2[count].books[i].title, visitors1.books[i].title);
			strcpy_s(visitors2[count].books[i].author, visitors1.books[i].author);
			visitors2[count].books[i].year = visitors1.books[i].year;
		}
		count++;
	}
	do
	{
		cout << "Which field to edit? ";
		cin >> field;
		fseek(stdin, 0, SEEK_END);//встановлення покажчика в потоці вводу в кінець
		cout << "Input new value: ";
		cin.getline(newval, 100, '\n');//вибір поля для зміни
		for (int i = 0; i < strlen(field); i++)
		{
			field[i] = tolower(field[i]);
		}
		if (strcmp(field, "surname") == 0)//заміна обраного поля новим значенням
		{
			strcpy_s(visitors2[k].reader.surname, newval);
		}
		else if (strcmp(field, "adress") == 0)
		{
			strcpy_s(visitors2[k].reader.adress, newval);
		}
		else if (strcmp(field, "date") == 0)
		{
			strcpy_s(visitors2[k].reader.date, newval);
		}
		cout << "Continue overwriting? y/n" << endl;
		ans = _getch();
	} while (ans != 'n');
	for (int i = 0; i < count; i++)
	{
		fwrite(&visitors2[i], sizeof(library), 1, newf);//запис структури у новий файл
	}
	fclose(file);//закритя файлів
	fclose(newf);
	remove("file.dat");//видалення старого файлу
	rename("newf.dat", "file.dat");//перейменування нового файлу іменем старого
}
void deleteinfo(FILE* file)//видалення інформації файлу
{
	FILE *newf;//показник на новий файл
	library visitors1, visitors2[10];//початкова структура з файлу, масив нових структур
	char surn[100], ans;//змінні для прізвища, символ відповіді
	int count = 0, k;//лічильники
	fopen_s(&file, "file.dat", "rb");//відкриття файлів
	fopen_s(&newf, "newf.dat", "wb");
	cout << "Surname of reader to delete info of: ";
	cin >> surn;//вибір прізвища читача для видалення його інформації
	while (!feof(file))
	{
		fread(&visitors1, sizeof(library), 1, file);
		if (strcmp(visitors1.reader.surname, surn) == 0)
		{
			k = count;//порядковий новер структури з обраним читачем
		}
		visitors2[count].reader = visitors1.reader;//запис зі старої структури у нову
		strcpy_s(visitors2[count].reader.surname, visitors1.reader.surname);
		strcpy_s(visitors2[count].reader.adress, visitors1.reader.adress);
		strcpy_s(visitors2[count].reader.date, visitors1.reader.date);
		visitors2[count].reader.bookn = visitors1.reader.bookn;
		for (int i = 0; i < visitors1.reader.bookn; i++)
		{
			visitors2[count].books[i] = visitors1.books[i];
			strcpy_s(visitors2[count].books[i].title, visitors1.books[i].title);
			strcpy_s(visitors2[count].books[i].author, visitors1.books[i].author);
			visitors2[count].books[i].year = visitors1.books[i].year;
		}
		count++;
	}
	for (int i = 0; i < count - 1; i++)//запис у новий файл
	{
		if (i == k)   //якщо лічильник циклу дорівнює порядковому номеру читача,
			continue; //інформацію про якого треба видалити, тоді не записувати його у файл
		else
			fwrite(&visitors2[i], sizeof(library), 1, newf);//якщо ні, то записати у файл
	}
	fclose(file);//закритя файлів
	fclose(newf);
	remove("file.dat");//видалення старого файлу
	rename("newf.dat", "file.dat");//перейменування нового файлу іменем старого
}