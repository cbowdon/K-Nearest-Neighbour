#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include <fstream>
#include "Classified.hpp"

namespace csv {

	template<class T>
		ml::Classified<T> parse_classified(std::string data) {
			return ml::Classified<T>("test", { 1.0 });
		}

	template<class T>
		ml::Unclassified<T> parse_unclassified(std::string data) {
			return ml::Unclassified<T>({ 1.0 });
		}


	template<class D, class F>
		std::vector<D> load (std::string path, F parse) {
			std::vector<D> data;

			std::fstream file;
			try {
				file = std::fstream(path, std::fstream::in);

				std::string temp;
				while(std::getline(file, temp)) {
					data.push_back(parse(temp));
				}
			} catch (...) {
			}
			file.close();

			return data;
		}

	template<class T>
		std::vector<ml::Classified<T>> load_classified (std::string path) {

			std::vector<ml::Classified<T>> data;

			std::fstream file;
			try {
				file = std::fstream(path, std::fstream::in);

				std::string temp;
				while(std::getline(file, temp)) {
					data.push_back(parse_classified<T>(temp));
				}
			} catch (...) {
			}
			file.close();

			return data;
		}

	template<class T>
		std::vector<ml::Unclassified<T>> load_unclassified (std::string path) {
			return load<ml::Unclassified<T>>(path, parse_unclassified<T>);
		}
}

#endif
