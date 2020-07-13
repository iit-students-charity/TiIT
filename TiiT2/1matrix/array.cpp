#include "array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRand(int **array, const int lines, const int columns)
{
	srand(time(NULL));

	for (int i = 0; i < lines; i++)
	{
		for (int k = 0; k < columns; k++) {

			array[i][k] = rand() % 30 - 15;

		}
	}

}

void CreateManual(int** array, const int lines, const int columns)
{

	for (int i = 0; i < lines; i++)
	{
		cout << endl;

		for (int k = 0; k < columns; k++) {

			cin >> array[i][k];

		}
	}

}

void Read(int** array, const int lines, const int columns) {

	for (int i = 0; i < lines; i++)
	{
		cout << endl << endl;

		for (int k = 0; k < columns; k++) {

			cout << array[i][k] << "\t";

		}
	}

	cout << endl << endl;

}

void Sort(int **array, const int lines, const int columns) {

	bool unsorted = true;

	while (unsorted) {

		unsorted = false;

		int i_pre = 0, j_pre = 0;

		for (int j = 0; j < columns; ++j) {

			for (int i = (j ? 0 : 1); i < lines; ++i) {

				if (array[i][j] < array[i_pre][j_pre]) {

					int t = array[i][j];

					array[i][j] = array[i_pre][j_pre];

					array[i_pre][j_pre] = t;

					unsorted = true;
				}

				i_pre = i;

				j_pre = j;
			}

		}
		
	}
}

void Search(int** array, const int lines, const int columns, int number) {

	bool exception = true;

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++) {

			if (array[i][j] == number) {

				cout << "Your number is on the " << i + 1 << " line and " << j + 1 << " column" << endl << endl;

				exception = false;

			}
		}
	}

	if (exception) {

		cout << "There is no such element in the array " << endl << endl;

	}

}

void Insert(int** array, int line, int column, int number) {

	array[line - 1][column - 1] = number;

}

void Intersection(int** array, int** array2, int lines, int columns, int lines2, int columns2) {
	
	int size = lines * columns;

	int* arr = new int[size];

	int i = 0;

	for (int j = 0; j < lines; j++) {

		for (int k = 0; k < columns; k++) {

			arr[i++] = array[j][k];

		}

	}

	int size2 = lines2 * columns2;

	int* arr2 = new int[size2];

	int b = 0;

	for (int j = 0; j < lines2; j++) {

		for (int k = 0; k < columns2; k++) {

			arr2[b++] = array2[j][k];

		}

	}

	int sizeB = 0;

	for (int p = 0; p < size; p++) {

		for (int r = 0; r < size2; r++) {

			if (arr[p] == arr2[r]) {

				sizeB++;

				continue;
			}

		}

	}

	int* buff = new int[sizeB];

	int h = 0;

	for (int p = 0; p < size; p++) {

		for (int r = 0; r < size2; r++) {

			if (arr[p] == arr2[r]) {

				buff[h++] = arr[p];

				continue;
			}

		}

	}

	for (int i = 0; i < sizeB; i++) {

		for (int j = i + 1; j < sizeB; j++) {

			if (buff[i] == buff[j]) {

				buff[j] = buff[sizeB - 1];

				sizeB--;

			}

		}

	}
	
	int lines3 = 0;

	int columns3 = 0;

	if (sizeB == 0) {

		cout << endl << "There is no same elements " << endl;

	}

	else if (sizeB == 1) {

		columns3 = 1;

		lines3 = 1;

	}

	for (int z = 2; z < sqrt(sizeB) + 1; z++) {

		if ((size % z) != 0) {

			lines3 = sizeB;

			columns3 = 1;

		}

	}

	for (int z = 2; z < sqrt(sizeB) + 1; z++) {

		if ((sizeB % z) == 0) {

			lines3 = z;

			columns3 = sizeB / z;

		}

		break;

	}

	int** array3 = new int* [lines3];

	for (int i = 0; i < lines3; i++) {

		array3[i] = new int[columns3];

	}

	int m = 0;

	for (int i = 0; i < lines3; i++) {

		for (int j = 0; j < columns3; j++) {

			array3[i][j] = buff[m++];

		}

	}

	Sort(array3, lines3, columns3);

	Read(array3, lines3, columns3);

	for (int i = 0; i < lines3; i++) {

		delete[]array3[i];
	}

	delete[] buff;

	delete[] arr;

	delete[] arr2;
}

void Union(int** array, int** array2, int lines, int columns, int lines2, int columns2) {

	int sizeB = lines * columns + lines2 * columns2;

	int* buff = new int[sizeB];

	int h = 0;

	int i = 0;

	for (int j = 0; j < lines; j++) {

		for (int k = 0; k < columns; k++) {

			buff[i++] = array[j][k];

		}

	}

	for (int j = 0; j < lines2; j++) {

		for (int k = 0; k < columns2; k++) {

			buff[i++] = array2[j][k];

		}

	}

	for (int i = 0; i < sizeB; i++) {

		for (int j = i + 1; j < sizeB; j++) {

			if (buff[i] == buff[j]) {

				buff[j] = buff[sizeB - 1];

				sizeB--;

			}

		}

	}

	int lines3 = 0;

	int columns3 = 0;

	if (sizeB == 0) {

		cout << endl << "There is no different elements " << endl;

	}

	else if (sizeB == 1) {

		columns3 = 1;

		lines3 = 1;

	}

	for (int z = 2; z < sqrt(sizeB) + 1; z++) {

		if ((sizeB % z) != 0) {

			lines3 = sizeB;

			columns3 = 1;

		}

	}

	for (int z = 2; z < sqrt(sizeB) + 1; z++) {

		if ((sizeB % z) == 0) {

			lines3 = z;

			columns3 = sizeB / z;

		}

		break;

	}

	int** array3 = new int* [lines3];

	for (int i = 0; i < lines3; i++) {

		array3[i] = new int[columns3];

	}

	int m = 0;

	for (int i = 0; i < lines3; i++) {

		for (int j = 0; j < columns3; j++) {

			array3[i][j] = buff[m++];

		}

	}

	Sort(array3, lines3, columns3);

	Read(array3, lines3, columns3);

	for (int i = 0; i < lines3; i++) {

		delete[]array3[i];
	}

	delete[] buff;


}
