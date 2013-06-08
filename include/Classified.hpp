#ifndef CLASSIFIED_H
#define CLASSIFIED_H

#include <string>
#include <ostream>

namespace ml {

	template<class T>
		struct Unclassified {

			Unclassified (std::vector<T> points) : data(points) {}

			const std::vector<T> data;
		};

	template<class T>
		struct Classified {

			Classified (std::string name, std::vector<T> points) : label(name), data(points) {}

			const std::string label;
			const std::vector<T> data;
		};

	template<class T>
		std::ostream& operator<< (std::ostream &ostr, const Classified<T> &classified) {

			ostr << classified.label << " { ";
			std::copy(begin(classified.data), end(classified.data), std::ostream_iterator<T>(ostr, " "));
			ostr << "}";

			return ostr;
		}

	template<class T>
		std::ostream& operator<< (std::ostream &ostr, const Unclassified<T> &unclassified) {

			ostr << unclassified.label << " { ";
			std::copy(begin(unclassified.data), end(unclassified.data), std::ostream_iterator<T>(ostr, " "));
			ostr << "}";

			return ostr;
		}

}

#endif
