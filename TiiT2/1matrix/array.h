#pragma once

void Read(int** array, const int lines, const int columns);
void CreateManual(int** array, const int lines, const int columns);
void CreateRand(int **array, const int lines, const int columns);            // 1. Двумерный массив. ++
void Sort(int** array, const int lines, const int columns);			        // 2. Сортировка массива. +
void Insert(int** array, const int lines, const int columns, int number);  // 3. Вставка элемента в отсортированный массив. +
void Search(int** array, const int lines, const int columns, int number); // 4. Поиск элемента в отсортированном массиве. +
void Union(int** array, int** array2, int lines, int columns, int lines2, int columns2); // 5. Объединение двух отсортированных массивов. ++
void Intersection(int** array, int** array2, int lines, int columns, int lines2, int columns2);// 6. Пересечение  двух отсортированных массивов. ++