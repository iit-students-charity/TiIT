#include <iostream>
#include "array.h"

using namespace std;

int main() {

	cout << "Firstly you should create an array, enter some info" << endl << endl;

	int lines;

	int columns;

	cout << "Input number of lines (1): ";

	cin >> lines;

	cout << "Input number of columns (1): ";

	cin >> columns;

	int** array = new int* [lines];

	for (int i = 0; i < lines; i++) {

		array[i] = new int[columns];

	}

	cout << "Choose, how to fill in an array (1): \n1). Random \n2). Manual" << endl << "\t";

	int create;

	cin >> create;

	if (create == 1) {

		CreateRand(array, lines, columns);

		cout << endl << "Here your Array (1): " << endl;

		Read(array, lines, columns);

	}

	else if (create == 2) {

		cout << endl << "Enter the elements (1): " << endl;

		CreateManual(array, lines, columns);

		cout << endl << "Here your Array (1): " << endl;

		Read(array, lines, columns);

	}

	cout << "Secondly you should create another array, enter some info" << endl << endl;

	int lines2;

	int columns2;

	cout << "Input number of lines (2): ";

	cin >> lines2;

	cout << "Input number of columns (2): ";

	cin >> columns2;

	int** array2 = new int* [lines2];

	for (int i = 0; i < lines2; i++) {

		array2[i] = new int[columns2];

	}

	cout << "Choose, how to fill in an array (2): \n1). Random \n2). Manual" << endl << "\t";

	int create2;

	cin >> create2;

	if (create2 == 1) {

		CreateRand(array2, lines2, columns2);

		cout << endl << "Here your Array (2) : " << endl;

		Read(array2, lines2, columns2);

	}

	else if (create2 == 2) {

		cout << endl << "Enter the elements (2): " << endl;

		CreateManual(array2, lines2, columns2);

		cout << endl << "Here your Array (2): " << endl;

		Read(array2, lines2, columns2);

	}

	int key = -1;

	int key2 = -1;

	int key3 = -1;

	while (key2 != 0) {

		cout << "Choose an array you want to work with: \n0). Exit \n1). Array 1 \n2). Array 2" << endl;

		cin >> key2;

		if (key2 == 1) {

			key = -1;

			while (key != 7) {

				cout << endl << "Choose, what to do: \n\n1). Show the array (1) \n2). Sort (1) \n3). Insert the element (1) \n4). Search (1) \n5). Intersection of sets (1 and 2) \n6). Union of sets (1 and 2) \n7). Go to the second array / exit " << endl << "\t";

				cin >> key;

				if (key == 1) {

					Read(array, lines, columns);

				}

				else if (key == 2) {

						cout << endl << "Sorted Array (1)! " << endl;

						Sort(array, lines, columns);

						Read(array, lines, columns);
				}

				else if (key == 3) {

						int number, line, column;

						cout << "Enter the number you want to Insert (1): ";

						cin >> number;

						cout << "Enter the line (1): ";

						cin >> line;

						cout << "And the column of the number (1): ";

						cin >> column;

						Sort(array, lines, columns);

						Insert(array, line, column, number);

						Sort(array, lines, columns);

				}

				else if (key == 4) {

						int number;

						cout << endl << "Enter the number you want to search (1): ";

						cin >> number;

						cout << endl;

						Search(array, lines, columns, number);

				}

				else if (key == 5) {

					Intersection(array, array2, lines, columns, lines2, columns2);

				}

				else if (key == 6) {

					Union(array, array2, lines, columns, lines2, columns2);

				}

			}

		}

		if (key2 == 2) {

			key3 = -1;

			while (key3 != 7) {

				cout << endl << "Choose, what to do: \n\n1). Show the array (2) \n2). Sort (2) \n3). Insert the element (2) \n4). Search (2) \n5). Intersection of sets (1 and 2) \n6). Union of sets  (2 and 1) \n7). Go to the first array / exit " << endl << "\t";

				cin >> key3;

				if (key3 == 1) {

					Read(array2, lines2, columns2);

				}

				else if (key3 == 2) {

					cout << endl << "Sorted Array (2)! " << endl;

					Sort(array2, lines2, columns2);

					Read(array2, lines2, columns2);
				}

				else if (key3 == 3) {

					int number, line, column;

					cout << "Enter the number you want to Insert (2): ";

					cin >> number;

					cout << "Enter the line (2): ";

					cin >> line;

					cout << "And the column of the number (2): ";

					cin >> column;

					Sort(array2, lines2, columns2);

					Insert(array2, line, column, number);

					Sort(array2, lines2, columns2);
					
				}

				else if (key3 == 4) {

					int number;

					cout << endl << "Enter the number you want to search (2): ";

					cin >> number;

					cout << endl;

					Search(array2, lines2, columns2, number);

				}

				else if (key3 == 5) {

					Intersection(array, array2, lines, columns, lines2, columns2);

				}

				else if (key3 == 6) {

					Union(array, array2, lines, columns, lines2, columns2);

				}

			}

		}

	}



	for (int i = 0; i < lines; i++) {

		delete[]array[i];
	}

	delete[]array;

	for (int i = 0; i < lines2; i++) {

		delete[]array2[i];
	}

	delete[]array2;

	return 0;

}