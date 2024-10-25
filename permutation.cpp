#include "permutation.h"

void SortByABC(std::vector <Files> files_info, std::vector <Files> sorted_files_info) {

	sorted_files_info = files_info;
	std::sort(sorted_files_info.begin(), sorted_files_info.end(),
		[](const Files& a, const Files& b) {
			return a.get_file_name() < b.get_file_name();
		});
}