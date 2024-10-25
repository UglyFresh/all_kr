#include "permutation.h"

void SortByABC(std::vector <Files> files_info, std::vector <Files> sorted_files_info) {

	sorted_files_info = files_info;
	std::sort(sorted_files_info.begin(), sorted_files_info.end(),
		[](const Files& a, const Files& b) {
			return a.get_file_name() < b.get_file_name();
		});
}

void SortBySize(std::vector <Files> files_info, std::vector <Files> sorted_files_info, int min_size) {
	for (const auto& file : files_info) {
		if (file.get_file_size() > min_size) {
			sorted_files_info.push_back(file);
		}
	}
}

void SortByAccesses(std::vector <Files> files_info, std::vector <Files> sorted_files_info, int min_accesses) {
	for (const auto& file : files_info) {
		if (file.get_number_of_file_accesses() > min_accesses) {
			sorted_files_info.push_back(file);
		}
	}
}