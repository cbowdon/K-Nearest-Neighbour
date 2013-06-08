#ifndef KNN_H
#define KNN_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace ml {

	class KNN {

		public:
			KNN ();
			~KNN ();
		
			vector<float> classify (const vector<float> unclassified) const;
			void train (const string data_path);

		private:
			struct Impl;
			unique_ptr<Impl> pimpl;
	};
}

#endif
