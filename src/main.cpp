#include <iostream>
#include <string>
#include "KNN.hpp"
#include "CSV.hpp"
#include "Classified.hpp"

using namespace std;
using namespace ml;

int main (int argc, char** argv) {

	const string training_data = argc > 0 ? argv[0] : "/data/classified.csv";
	const string test_data = argc > 1 ? argv[1] : "/data/unclassified.csv";

	vector<Classified<float>> classified = csv::load_classified<float>(training_data);
	vector<Unclassified<float>> unclassified = csv::load_unclassified<float>(test_data);

	ml::KNN knn;

	knn.train(classified);

	for_each(begin(unclassified), end(unclassified),[&knn](const Unclassified<float> u) {
		cout << knn.classify(u) << endl;
	});

	return EXIT_SUCCESS;
}
