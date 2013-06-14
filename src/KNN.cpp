#include "KNN.hpp"
#include <cassert>
#include <iostream>
#include <ostream>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <utility>

typedef std::vector<float> vecFlo;
typedef std::pair<size_t, float> pair;
typedef std::vector<pair> vecPair;
typedef std::vector<size_t> vecSizeT;

//**********
// KNN::Impl
//**********
struct ml::KNN::Impl {

	void train (const std::vector<Cf>& input);
	const Cf classify (const Uf& unclassified, const size_t k);
	const float euclidean_distance (const vecFlo& pt0, const vecFlo& pt1) const;

	std::vector<Cf> data;
};

void ml::KNN::Impl::train (const std::vector<Cf>& input) {

	assert(input.size() > 0);

	size_t dimensions = input[0].data.size();

	std::for_each(begin(input), end(input), [this, &dimensions](const Classified<float>& i) { 
		assert(dimensions == i.data.size());
		data.push_back(i); 
	});

//	std::copy(begin(data), end(data), std::ostream_iterator<Cf>(std::cout, "\n"));
}

const Cf ml::KNN::Impl::classify (const Uf& unclassified, const size_t k) {
	assert(data.size() > 0);

	vecSizeT indices(data.size());
	std::iota(begin(indices), end(indices), 0);

	vecPair euclidean_distances(data.size());

	std::transform(begin(data), end(data), begin(indices), begin(euclidean_distances), [this, &unclassified](const Cf& cf, const size_t i) {
		return pair(i, euclidean_distance(unclassified.data, cf.data));
	});

	auto middle = begin(euclidean_distances);
	middle += 5;
	std::function<bool(pair, pair)> compare = [](const pair& p0, const pair& p1) { return std::get<1>(p0) < std::get<1>(p1); };
	std::partial_sort(begin(euclidean_distances), middle, end(euclidean_distances), compare);

	std::cout << "Unclassified: " << unclassified << std::endl;

	std::for_each(begin(euclidean_distances), middle, [this](const pair& p) {
		std::cout << std::get<1>(p) << "\t" << data[std::get<0>(p)] << std::endl;
	});

	return Cf("test", { 0.0 });
}

const float ml::KNN::Impl::euclidean_distance (const vecFlo& pt0, const vecFlo& pt1) const {

	const size_t n = pt0.size();
	assert(n == pt1.size());

	vecFlo dists(n);
	
	std::function<float(float, float)> dist = [](const float x0, const float y0) { return (x0 - y0) * (x0 - y0); };

	std::transform(begin(pt0), end(pt0), begin(pt1), begin(dists), dist);

	return std::accumulate(begin(dists), end(dists), 0.0);
}

//****
// KNN
//****
ml::KNN::KNN () : pimpl(new ml::KNN::Impl) {}
ml::KNN::~KNN () {}

void ml::KNN::train (const std::vector<Cf>& data) {
	pimpl->train(data);
}

const Cf ml::KNN::classify (const Uf& unclassified, const size_t k) const {
	return pimpl->classify(unclassified, k);
}
