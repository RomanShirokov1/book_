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
		cout << "1 " << "�������� �����" << endl;
		cout << "2 " << "������� �����" << endl;
		cout << "3 " << "����� ���������� �� ����� � ���������, ������� ����� (�� �������������� �����)" << endl;
		cout << "4 " << "����� ����� � �������� �� �������� � �� ������ � ������� ��������������" << endl;
		cout << "5 " << "������ ����� ��������" << endl;
		cout << "6 " << "������� ����� ���������" << endl;
		cout << "7 " << "����� ������ ���������, �� ��������� ����� � ������� ����" << endl;
		cout << "8 " << "�����" << endl;

		cin >> variant;
		system("cls");
		switch (variant)
		{
		case 1:
			cout << "������� �������� �����: \n";
			cin >> BookName;
			cout << "\n������� ���������� ������� �����:\n";
			cin >> Number;
			cout << "\n������� ������ �����:\n";
			for (int i = 1; i <= Number; i++)
			{
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << "\n������� ��� ������������ �����:\n";
			cin >> Year;
			cout << "\n������� ������������ �����:\n";
			cin >> Publisher;
			cout << "\n������� ���������� ������� �����:\n";
			cin >> Pages;
			cout << "\n������� ID �����:\n";
			cin >> ID;
			cout << "\n������� ����� ���������� ����:\n";
			cin >> Quantity;
			cout << "\n������� ���������� ��������� ����:\n";
			cin >> Instances;
			cout << endl;
			user.AddBook(BookName, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			system("cls");
			break;
		case 2:
			cout << "������� ������ �� ��������� �����\n" << "������� �������� �����: \n";
			cin >> BookName;
			cout << endl;
			user.DeleteBook(BookName);
			break;
		case 3:
			cout << "������� ID �����\n";
			cin >> ID;
			cout << endl;
			user.TakenInfo(ID);
			break;
		case 4:
			cout << "������� ������ � ������������ �����\n" << "������� �������� �����: \n";
			cin >> BookName;
			cout << "������� ������\n";
			cin >> Name;
			cout << endl;
			user.BookSearch(BookName, Name);
			break;
		case 5:
			cout << "������� ������ � ������������ �����\n" << "������� �������� �����: \n";
			cin >> BookName;
			cout << "������� ���: ";
			cin >> Name;
			cout << "������� ����������� ����(�������� ����, ����� � ���)\n";
			cin >> Day >> Month >> Year;
			cout << endl;
			user.BookIssuance(BookName, Name, Day, Month, Year);
			break;
		case 6:
			cout << "������� ������ � ������������ �����\n" << "������� �������� �����: \n";
			cin >> BookName;
			cout << "������� ��� �������������: ";
			cin >> Name;
			cout << endl;
			user.BookReturn(BookName, Name);
			break;
		case 7:
			cout << "������� ����������� ����(�������� ����, ����� � ���)\n";
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