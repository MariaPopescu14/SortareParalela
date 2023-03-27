#include "data_generator.h"
#include <fstream>


void DataSetGenerator::Generate(string file_name, int data_set_size, int minimum_number, int maximum_number) {
	ofstream file(file_name);
	int random_number;

	for (int i = 0; i < data_set_size; i++) {
		random_number = minimum_number + (rand() % (maximum_number - minimum_number + 1));
		file << random_number << " ";
	}
}