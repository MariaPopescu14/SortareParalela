#include <iostream>
#include <vector>
#include <time.h> 
#include "MergeSort.h"
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    vector<int> numbers;
    if (rank == 0) {
        numbers = readVectorFromFile("data_set_19.txt");
    }

    clock_t start = clock();
    vector<int> sorted = mergeSort(numbers);
    clock_t stop = clock();

    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Pentru setul de date de dimensiune " << sorted.size() << " a durat " << elapsed << " ms.";

    if (rank == 0) {
        cout << "\nVectorul a fost sortat ";
    }

    MPI_Finalize();
    return 0;
}


