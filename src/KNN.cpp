#include "KNN.hpp"

// KNN::Impl
struct ml::KNN::Impl {
	Impl () {};
};


// KNN
ml::KNN::KNN () : pimpl(new ml::KNN::Impl) {}
ml::KNN::~KNN () {}

void ml::KNN::train (const std::vector<Classified<float>> data) {
};

ml::Classified<float>  ml::KNN::classify (const Unclassified<float> unclassified) const {
	return Classified<float>("test", { 0.0 });
};
