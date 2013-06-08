#include "KNN.hpp"

// KNN::Impl
struct ml::KNN::Impl {
	Impl () {};
};


// KNN
ml::KNN::KNN () : pimpl(new ml::KNN::Impl) {}
ml::KNN::~KNN () {}

void ml::KNN::train (const std::string data_path) {
};

std::vector<float> ml::KNN::classify (const std::vector<float> unclassified) const {
};
