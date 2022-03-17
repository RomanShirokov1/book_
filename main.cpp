#include "book.h"
#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	actions user;
	int variant;
	string BookName, Name, Publisher;
	unsigned int Day, Month, Year, ID, Pages, Quantity, Instances, Number;
	vector <string> Authors;

	do
	{
		system("cls");
		cout << "1 " << "ƒобавьте книгу" << endl;
		cout << "2 " << "”далите книгу" << endl;
		cout << "3 " << "¬ывод информации по книге и читател€м, вз€вшим книгу (по идентификатору книги)" << endl;
		cout << "4 " << "ѕоиск книги в каталоге по названию и по автору с выдачей идентификатора" << endl;
		cout << "5 " << "¬ыдача книги читателю" << endl;
		cout << "6 " << "¬озврат книги читателем" << endl;
		cout << "7 " << "¬ывод списка читателей, не вернувших книги в течение года" << endl;
		cout << "8 " << "¬ыход" << endl;

		cin >> variant;
		system("cls");
		switch (variant)
		{
		case 1:
			cout << "¬ведите название книги: \n";
			cin >> BookName;
			cout << "\n¬ведите количество авторов книги:\n";
			cin >> Number;
			cout << "\n¬ведите автора книги:\n";
			for (int i = 1; i <= Number; i++)
			{
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << "\n¬ведите год издательства книги:\n";
			cin >> Year;
			cout << "\n¬ведите издательство книги:\n";
			cin >> Publisher;
			cout << "\n¬ведите количество страниц книги:\n";
			cin >> Pages;
			cout << "\n¬ведите ID книги:\n";
			cin >> ID;
			cout << "\n¬ведите общее количество книг:\n";
			cin >> Quantity;
			cout << "\n¬ведите количество свободных книг:\n";
			cin >> Instances;
			cout << endl;
			user.AddBook(BookName, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			system("cls");
			break;
		case 2:
			cout << "¬ведите данные об удал€емой книге\n" << "¬ведите название книги: \n";
			cin >> BookName;
			cout << endl;
			user.DeleteBook(BookName);
			break;
		case 3:
			cout << "¬ведите ID книги\n";
			cin >> ID;
			cout << endl;
			user.TakenInfo(ID);
			break;
		case 4:
			cout << "¬ведите данные о возвращаемой книге\n" << "¬ведите название книги: \n";
			cin >> BookName;
			cout << "¬ведите автора\n";
			cin >> Name;
			cout << endl;
			user.BookSearch(BookName, Name);
			break;
		case 5:
			cout << "¬ведите данные о возвращаемой книге\n" << "¬ведите название книги: \n";
			cin >> BookName;
			cout << "¬ведите им€: ";
			cin >> Name;
			cout << "¬ведите сегодн€шнюю дату(отдельно день, мес€ц и год)\n";
			cin >> Day >> Month >> Year;
			cout << endl;
			user.BookIssuance(BookName, Name, Day, Month, Year);
			break;
		case 6:
			cout << "¬ведите данные о возвращаемой книге\n" << "¬ведите название книги: \n";
			cin >> BookName;
			cout << "¬ведите им€ возвращающего: ";
			cin >> Name;
			cout << endl;
			user.BookReturn(BookName, Name);
			break;
		case 7:
			cout << "¬ведите сегодн€шнюю дату(отдельно день, мес€ц и год)\n";
			cin >> Day >> Month >> Year;
			cout << endl;
			user.Debtors(Day, Month, Year);
			break;

		}
		if (variant != 8)
		{
			system("pause");
		}
	} while (variant != 8);
	return 0;
}