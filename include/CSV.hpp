#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Classified.hpp"

namespace csv {

	template<class T>
		ml::Classified<T> parse_classified(const std::string& input) {
			// TODO refactor for DRYness with parse_unclassified

			std::stringstream line(input);
			std::string cell;
			std::vector<std::string> cells;
			std::vector<T> data;

			while (std::getline(line, cell, ',')) {
				cells.push_back(cell);
			}

			size_t len = cells.size();

			for (int i = 0; i + 1 < len; i++) {
				long double ld = std::stold(cells[i]);
				data.push_back(static_cast<T>(ld));
			};

			return ml::Classified<T>(cells[len - 1], data);
		}

	template<class T>
		ml::Unclassified<T> parse_unclassified(const std::string& input) {
			// TODO refactor for DRYness with parse_classified

			std::stringstream line(input);
			std::string cell;
			std::vector<std::string> cells;
			std::vector<T> data;

			while (std::getline(line, cell, ',')) {
				cells.push_back(cell);
			}

			size_t len = cells.size();

			for (int i = 0; i + 1 < len; i++) {
				long double ld = std::stold(cells[i]);
				data.push_back(static_cast<T>(ld));
			};

			return ml::Unclassified<T>(data);
		}


	template<class D, class F>
		std::vector<D> load (const std::string& path, F parse) {
			std::vector<D> data;

			std::fstream file;
			try {
				file = std::fstream(path, std::fstream::in);

				std::string temp;
				while(std::getline(file, temp)) {
					data.push_back(parse(temp));
				}

				file.close();
			} catch (...) {
				// TODO refactor all this for RAII
				if (file.is_open()) {
					file.close();
				}
				std::cout << "Error was thrown reading file: " << path << std::endl;
			}

			return data;
		}

	template<class T>
		std::vector<ml::Classified<T>> load_classified (const std::string& path) {
			return load<ml::Classified<T>>(path, parse_classified<T>);
		}

	template<class T>
		std::vector<ml::Unclassified<T>> load_unclassified (const std::string& path) {
			return load<ml::Unclassified<T>>(path, parse_unclassified<T>);
		}
}

#endif
