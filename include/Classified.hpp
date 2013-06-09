#ifndef CLASSIFIED_H
#define CLASSIFIED_H

#include <string>
#include <ostream>

namespace ml {

	template<class T>
		struct Unclassified {

			Unclassified (const std::vector<T>& points) : data(points) {}

			const std::vector<T> data;
		};

	template<class T>
		struct Classified {

			Classified () = default;
			Classified<T> (const Classified<T>& c) = default;
			Classified<T>& operator=(const Classified<T>& c) = default;

			Classified (const std::string& name, const std::vector<T>& points) : label(name), data(points) {}

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

			ostr << " { ";
			std::copy(begin(unclassified.data), end(unclassified.data), std::ostream_iterator<T>(ostr, " "));
			ostr << "}";

			return ostr;
		}

}

#endif
