#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

struct Date {
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
};

struct Record {
	char a[20];
	char b;
	float c;
	int d;
	struct Date e;
};

void printDate(unsigned short int day, unsigned short int month, unsigned short int year) {
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
}

void out(struct Record l) {
	cout << left;
	cout << '|'; cout.width(21); cout << l.a;
	cout << '|'; cout.width(12); cout << l.b;
	cout.precision(2);  cout << '|'; cout.width(20); cout << l.c;
	cout << '|'; cout.width(33); cout << l.d;
	cout << '|'; printDate(l.e.day, l.e.month, l.e.year);
	cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');
}

void MyCentr(const char* s, int wLine) {
	int w = strlen(s);
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta); cout << " ";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record l[3];

	l[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	l[1] = { "Бумага", 'К', 13.9, 10000, {03,04,2021} };
	l[2] = { "Калькулятор", 'О', 411.000, 1, {04,03,2022} };

	unsigned short int d; cin >> d;
	unsigned short int m; cin >> m;
	unsigned short int y; cin >> y;
	struct Date z = { d, m, y };

	int x = 4;
	for (int i = 0; i < 3; i++)
		if (z.month == l[i].e.month)
			if (z.day == l[i].e.day)
				if (z.year == l[i].e.year)
					x = i;

	cout << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << "|" << endl;
	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Прайс-лист"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

	cout << "|"; MyCentr("Наименование товара", 21);
	cout << "|"; MyCentr("Тип товара", 12);
	cout << "|"; MyCentr("Цена за 1 шт (грн)", 20);
	cout << "|"; MyCentr("Минимальное количество в партии", 33);
	cout << "|"; MyCentr("Дата", 10);
	cout << "|" << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << right; cout << "|" << endl;
	cout.fill(' ');

	for (int i = 0; i < 3; i++)
		if (i != x)
			out(l[i]);

	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Примечание: К – канцтовары, О - оргтехника"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

}