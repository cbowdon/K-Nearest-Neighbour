#include "KNN.hpp"
#include <cassert>
#include <iostream>
#include <ostream>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <utility>
#include <unordered_map>

typedef std::vector<float> vecFlo;
typedef std::pair<size_t, float> pair;
typedef std::vector<pair> vecPair;
typedef std::vector<size_t> vecSizeT;
typedef std::pair<std::string, size_t> wordCount;

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

	const auto build = [this, &dimensions](const Cf& i) {
		assert(dimensions == i.data.size());
		data.push_back(i); 
	};
	std::for_each(begin(input), end(input), build);
}

const Cf ml::KNN::Impl::classify (const Uf& unclassified, const size_t k) {
	assert(data.size() > 0);

	// TODO refactor into smaller methods

	// Get indices
	vecSizeT indices(data.size());
	std::iota(begin(indices), end(indices), 0);

	// Create list of pairs (original index, dist)
	vecPair euclidean_distances(data.size());
	std::transform(begin(data), end(data), begin(indices), begin(euclidean_distances), [this, &unclassified](const Cf& cf, const size_t i) {
		return std::make_pair(i, euclidean_distance(unclassified.data, cf.data));
	});

	// Partial sort to find smallest k
	auto middle = begin(euclidean_distances);
	middle += k;
	const auto comp_dists = [](const pair& p0, const pair& p1) { return std::get<1>(p0) < std::get<1>(p1); };
	std::nth_element(begin(euclidean_distances), middle, end(euclidean_distances), comp_dists);

	// Find modal
	std::unordered_map<std::string, size_t> counts;
	const auto count_occurs = [this, &counts](const pair& p) {
		size_t index = std::get<0>(p);
		Cf cf = data[index];
		++counts[data[index].label];
	};
	std::for_each(begin(euclidean_distances), middle, count_occurs);

	const auto comp_counts = [](const wordCount& kv0, const wordCount& kv1) {
		return std::get<1>(kv0) < std::get<1>(kv1);
	};
	const auto it_max = std::max_element(begin(counts), end(counts), comp_counts);

	const auto top_label = std::get<0>(*it_max);

	return Cf(top_label, unclassified.data);
}

const float ml::KNN::Impl::euclidean_distance (const vecFlo& pt0, const vecFlo& pt1) const {

	const size_t n = pt0.size();
	assert(n == pt1.size());

	vecFlo dists(n);
	
	const auto dist = [](const float x0, const float y0) { return (x0 - y0) * (x0 - y0); };

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
