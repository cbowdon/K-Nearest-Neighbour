#ifndef KNN_H
#define KNN_H

#include <memory>
#include <string>
#include <vector>
#include "Classified.hpp"

typedef ml::Classified<float> Cf;
typedef ml::Unclassified<float> Uf;

namespace ml {

	class KNN {

		public:
			KNN ();
			~KNN ();

			void train (const std::vector<Cf>& classified);
			const Cf classify (const Uf& unclassified, const size_t k) const;

		private:
			struct Impl;
			std::unique_ptr<Impl> pimpl;
	};
}

#endif
