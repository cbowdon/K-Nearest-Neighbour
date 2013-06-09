#include "KNN.hpp"
#include <cassert>
#include <iostream>
#include <ostream>

// KNN::Impl
struct ml::KNN::Impl {

	void train (const std::vector<Cf>& input);
	const Cf classify (const Uf& classified, const size_t k);

	std::vector<Cf> data;
};

void ml::KNN::Impl::train (const std::vector<Cf>& input) {

	assert(input.size() > 0);

	size_t dimensions = input[0].data.size();

	std::for_each(begin(input), end(input), [this, &dimensions](const Classified<float>& i) { 
		assert(dimensions == i.data.size());
		data.push_back(i); 
	});

	std::copy(begin(data), end(data), std::ostream_iterator<Cf>(std::cout, "\n"));
}

const Cf ml::KNN::Impl::classify (const Uf& unclassified, const size_t k) {
	assert(data.size() > 0);

	std::vector<float> euclidean_distances(data.size());
	std::transform(begin(data), end(data), begin(euclidean_distances), [this, &unclassified](const Cf& cf) {
		return 0;
	});

	return Cf("test", { 0.0 });
}


// KNN
ml::KNN::KNN () : pimpl(new ml::KNN::Impl) {}
ml::KNN::~KNN () {}

void ml::KNN::train (const std::vector<Cf>& data) {
	pimpl->train(data);
}

const Cf ml::KNN::classify (const Uf& unclassified, const size_t k) const {
	return pimpl->classify(unclassified, k);
}
