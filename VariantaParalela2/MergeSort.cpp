#include "MergeSort.h"


vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            i++;
        }
        else {
            merged.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements_per_proc = arr.size() / size;
    int remainder = arr.size() % size;

    int local_size = elements_per_proc;
    if (rank < remainder) {
        local_size++;
    }

    vector<int> local_data(local_size);
    MPI_Scatter(arr.data(), local_size, MPI_INT, local_data.data(), local_size, MPI_INT, 0, MPI_COMM_WORLD);

    vector<int> sorted_local = local_data;
    sort(sorted_local.begin(), sorted_local.end());

    int level = 1;
    while (level < size) {
        if (rank % (2 * level) == 0) {
            vector<int> received(local_size);
            MPI_Recv(received.data(), local_size, MPI_INT, rank + level, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            vector<int> merged = merge(sorted_local, received);
            sorted_local = merged;
        }
        else if (rank % level == 0) {
            int send_rank = rank - level;
            MPI_Send(sorted_local.data(), sorted_local.size(), MPI_INT, send_rank, 0, MPI_COMM_WORLD);
            break;
        }
        level *= 2;
    }

    if (rank == 0) {
        vector<int> sorted(arr.size());
        MPI_Gather(sorted_local.data(), sorted_local.size(), MPI_INT, sorted.data(), sorted_local.size(), MPI_INT, 0, MPI_COMM_WORLD);
        return sorted;
    }

    return vector<int>();
}

vector<int> readVectorFromFile(string file_name) {
    vector<int> numbers;

    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Nu s-a putut deschide fisierul: " << file_name << endl;
        return numbers;
    }

    int number;
    while (file >> number) {
        numbers.push_back(number);
    }

    file.close();

    return numbers;
}