#pragma once
#include "number_sorting.h"

void Merge(int array[], int const left, int const mid, int const right) {
    auto const subarray_one = mid - left + 1;
    auto const subarray_two = right - mid;

    auto* left_array = new int[subarray_one],
        * right_array = new int[subarray_two];

    for (auto i = 0; i < subarray_one; i++)
        left_array[i] = array[left + i];
    for (auto j = 0; j < subarray_two; j++)
        right_array[j] = array[mid + 1 + j];

    auto index_of_subarray_one = 0,
        index_of_subarray_two = 0;
    int index_of_merged_array = left;

    while (index_of_subarray_one < subarray_one && index_of_subarray_two < subarray_two) {
        if (left_array[index_of_subarray_one] <= right_array[index_of_subarray_two]) {
            array[index_of_merged_array] = left_array[index_of_subarray_one];
            index_of_subarray_one++;
        }
        else {
            array[index_of_merged_array] = right_array[index_of_subarray_two];
            index_of_subarray_two++;
        }
        index_of_merged_array++;
    }

    while (index_of_subarray_one < subarray_one) {
        array[index_of_merged_array] = left_array[index_of_subarray_one];
        index_of_subarray_one++;
        index_of_merged_array++;
    }

    while (index_of_subarray_two < subarray_two) {
        array[index_of_merged_array]
            = right_array[index_of_subarray_two];
        index_of_subarray_two++;
        index_of_merged_array++;
    }
    delete[] left_array;
    delete[] right_array;
}

void MergeSort(int array[], int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    auto mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}


int* SortFromFile(string file_name, int dimension) {
	int* numbers = new int[dimension];

    ifstream file(file_name);

    for (int i = 0; i < dimension; i++) {
		file >> numbers[i];
    }

    MergeSort(numbers, 0, dimension - 1);

	return numbers;
}

void Print(int* numbers, int dimension) {
	cout << "\n\n Sorted: \n";
	for (int i = 0; i < dimension; i++) {
		cout << numbers[i] << " ";
	}
}

