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

	const vector<Cf> classified = csv::load_classified<float>(training_data);
	const vector<Uf> unclassified = csv::load_unclassified<float>(test_data);

	vector<Cf> results(unclassified.size());

	ml::KNN knn;

	knn.train(classified);

	const function<Cf(Uf)> cl = [&knn, &k](const Uf& u) { return knn.classify(u, k); };

	transform(begin(unclassified), end(unclassified), begin(results), cl);

	return EXIT_SUCCESS;
}
