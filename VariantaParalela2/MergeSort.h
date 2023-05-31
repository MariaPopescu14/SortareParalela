#pragma once
#include <iostream>
#include <vector>
#include <mpi.h>
#include <algorithm>
#include <fstream>
#include <time.h> 
#include <string>
using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right);
vector<int> mergeSort(const vector<int>& arr);
vector<int> readVectorFromFile(string file_name);