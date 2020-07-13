#pragma once

void Read(int** array, const int lines, const int columns);
void CreateManual(int** array, const int lines, const int columns);
void CreateRand(int **array, const int lines, const int columns);            // 1. ��������� ������. ++
void Sort(int** array, const int lines, const int columns);			        // 2. ���������� �������. +
void Insert(int** array, const int lines, const int columns, int number);  // 3. ������� �������� � ��������������� ������. +
void Search(int** array, const int lines, const int columns, int number); // 4. ����� �������� � ��������������� �������. +
void Union(int** array, int** array2, int lines, int columns, int lines2, int columns2); // 5. ����������� ���� ��������������� ��������. ++
void Intersection(int** array, int** array2, int lines, int columns, int lines2, int columns2);// 6. �����������  ���� ��������������� ��������. ++