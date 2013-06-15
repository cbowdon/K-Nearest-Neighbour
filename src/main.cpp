#include <iostream>
#include <string>
#include "KNN.hpp"
#include "CSV.hpp"
#include "Classified.hpp"

using namespace std;
using namespace ml;

int main (int argc, char** argv) {

	const string training_data = argc > 1 ? argv[1] : "data/classified.csv";
	const string test_data = argc > 2 ? argv[2] : "data/unclassified.csv";
	const size_t k = argc > 3 ? stoul(argv[3]) : 5;

	const auto classified = csv::load_classified<float>(training_data);
	const auto unclassified = csv::load_unclassified<float>(test_data);

	vector<Cf> results;

	ml::KNN knn;

	knn.train(classified);

//	for (auto u : unclassified) {
//		auto c = knn.classify(u, k);
//		cout << c << endl;
//		results.push_back(c);
//	}
	knn.classify(unclassified[0], k);

	return EXIT_SUCCESS;
}
