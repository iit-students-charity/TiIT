#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "set.h"

using namespace std;

int main()
{
	int power1;
	int power2;
	int element1;
	int posit1;
	int buffer;

	cout << "Enter the power of set: " << endl;
	cin >> power1;
	Set <int> n1;
	cout << "Enter the set: " << endl;
	for (int i = 0; i < power1; i++)
	{
		cin >> buffer;
		n1.set(buffer);
	}
	system("pause");
	system("cls");
/////////////////////////////////////////////////////////////////////////////
	cout << "Now you'll be shown a function of deleting an element from the set." << endl;
	cout << "Enter the the element to delete: " << endl;
	cin >> element1;
	n1.del(element1);
	cout << "Now your set is:" << endl;
	for (int i = 0; i < power1 - 1; i++)
	{
		cout << n1.get(i) << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
//////////////////////////////////////////////////////////////////////////////
	cout << "Now you'll be shown a function of searching." << endl;
	cout << "Enter the element to search: ";
	cin >> element1;
	cout << "Is there?: ";
	cout << n1.is_there(element1) << endl;
	system("pause");
	system("cls");
/////////////////////////////////////////////////////////////////////////////
	cout << "Enter the power of set: " << endl;
	cin >> power2;
	Set <int> n2;
	cout << "Enter the set: " << endl;
	buffer = 0;
	for (int i = 0; i < power2; i++)
	{
		cin >> buffer;
		n2.set(buffer);
	}
	system("cls");
/////////////////////////////////////////////////////////////////////////////
	cout << "Now you'll у shown a function of union." << endl;
	Set <int> n3;
	n3.uni(n1, n2);
	cout << "The result is:" << endl;
	for (int i = 0; i < n3.get_da_power(); i++)
	{
		cout << n3.get(i) << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
	/////////////////////////////////////////////////////////////////////////////
	cout << "Now you'll у shown a function of intersection." << endl;
	Set <int> n4;
	n4.inter(n1, n2);
	cout << "The result is:" << endl;
	for (int i = 0; i < n4.get_da_power(); i++)
	{
		cout << n4.get(i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}