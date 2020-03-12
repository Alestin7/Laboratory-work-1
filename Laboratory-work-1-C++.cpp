#include <iostream>
#include <string>
#include <Windows.h>

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Product {
	char Name[256];
	short Number;
	short Price;
	char Manufacturer[256];
	Date date;
};

using namespace std;

void BaseTask()
{
	cout << "Базовый уровень:" << endl;
	const int N = 4;
	Product group[N];
	int a = 0;

	for (size_t i = 1; i < N; i++)
	{
		cout << "Товар №" << i << ":" << endl;

		cout << "\nВведите название товара: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Name, 256);

		cout << "Введите количество товара: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Number;

		cout << "Введите цену товара: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Price;

		a += group[i].Price;

		cout << "Введите производителя: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Manufacturer, 256);

		do
		{
			cout << "Введите дату поступления на склад: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].date.day >> group[i].date.month >> group[i].date.year;
		} while (!group[i].date.isCorrect());

		cout << endl;

		cin.clear();
	}

	a = a / N;

	cout << endl;

	for (size_t i = 1; i < N; i++)
	{
		if (a < group[i].Price)
		{
			cout << "Товар №" << i << ":" << endl;

			cout << "\nНаименование: " << group[i].Name << endl;
			cout << "Количество: " << group[i].Number << endl;
			cout << "Цена за 1 товар: " << group[i].Price << endl;
			cout << "Производитель: " << group[i].Manufacturer << endl;
			cout << "Дата поступления на склад: " << group[i].date.day << "." << group[i].date.month << "." << group[i].date.year << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

struct Car {
	string Mark;
	char Manufacturer[256];
	char Type[256];
	short Release;
	Date Registration;
};

void MediumTask()
{
	cout << "Средний уровень:" << endl;
	const int N = 4;
	Car car[N];

	for (size_t i = 1; i < N; i++)
	{
		cout << "Автомобиль №" << i << ":" << endl;

		cout << "\nВведите марку автомобиля: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		getline(cin, car[i].Mark);

		cout << "Введите производителя автомобиля: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(car[i].Manufacturer, 256);


		cout << "Введите тип автомобиля: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(car[i].Type, 256);

		cout << "Введите год выпуска автомобиля: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> car[i].Release;

		do
		{
			cout << "Введите дату регистрации автомобиля: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> car[i].Registration.day >> car[i].Registration.month >> car[i].Registration.year;
		} while (!car[i].Registration.isCorrect());

		cout << endl;

		cin.clear();
	}

	for (size_t i = 1; i < N; i++)
	{
		if ((car[i].Mark == "Ford") && (car[i].Registration.year < 2000))
		{
			cout << "Автомобиль №" << i << ":" << endl;

			cout << "\nМарка автомобиля: " << car[i].Mark << endl;
			cout << "Производитель: " << car[i].Manufacturer << endl;
			cout << "Тип: " << car[i].Type << endl;
			cout << "Год выпуска: " << car[i].Release << endl;
			cout << "Дата регистрации: " << car[i].Registration.day << "." << car[i].Registration.month << "." << car[i].Registration.year << endl;
		}
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Сложный уровень:" << endl;
}

struct datetime {
	unsigned short Year;
	unsigned short Month;
	unsigned short Day;
	unsigned short Hour;
	unsigned short Minute;
	unsigned short Second;
}NewYear;

/*Таким образом, объект типа datetime в памяти будет занимать 6(элементов) х 2(байта) = 12 байт.
Нетрудно заметить, что в описании такой структуры присутствует значительная избыточность,
так как год может принимать значения от 0 до 2020 (задействуется всего 11 бит),
месяц - от 1 до 12 (4 бита), дата - от 1 до 31 (5 бит), часы - от 0 до 24 (5 бит), минуты и секунды - от 0 до 59
(по 6 бит на каждый элемент). Применяя битовые структуры, приведенная выше структура примет вид:*/

struct ByteStruct_DataTime
{
	unsigned short Year : 11;
	unsigned short Month : 4;
	unsigned short Day : 5;
	unsigned short Hour : 5;
	unsigned short Minute : 6;
	unsigned short Second : 6;
}ProgramistDay;

/*Экземпляр модифицированного типа datetime будет занимать не 12,
а 6 байт(так как 37 бита могут быть размещены только в шести байтах).*/

void HardTask()
{
	datetime NewYear{ 2020, 12, 365, 24, 60, 60 };
	cout << "Размер предложенной структуры в байтах:" << sizeof(NewYear);

	ByteStruct_DataTime ProgramistDay{ 2020, 12, 365, 24, 60, 60 };
	cout << endl << "Размер битовой структуры в байтах:" << sizeof(ProgramistDay) << endl;
}

/*В итоге мы сравнили структуры datetime и ByteStruct_DataTime. Записывая предложенную
структуру datetime в виде битовой структуры ByteStruct_DataTime мы сэкономили 6 байт.*/

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	BaseTask();
	MediumTask();
	HardTask();
}