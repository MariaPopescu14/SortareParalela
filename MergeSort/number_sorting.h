#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

void Merge(int array[], int const left, int const mid,int const right);

void MergeSort(int array[], int const begin, int const end);

int* SortFromFile(string file_name, int dimension);

void Print(int* numbers, int dimension);