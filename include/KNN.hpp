#ifndef KNN_H
#define KNN_H

#include <memory>
#include <string>
#include <vector>
#include "Classified.hpp"

namespace ml {

	class KNN {

		public:
			KNN ();
			~KNN ();
		
			Classified<float> classify (const Unclassified<float> unclassified) const;
			void train (const std::vector<Classified<float>> classified);

		private:
			struct Impl;
			std::unique_ptr<Impl> pimpl;
	};
}

#endif
