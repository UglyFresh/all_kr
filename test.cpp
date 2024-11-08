#include "test.h"

bool Test() {

	Date _date(10, 12, 2018);

	//test 1.1
	std::vector <Files> files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20)
	};

	std::vector<Files> sorted_by_ABC;

	SortByABC(files_info, sorted_by_ABC);

	if (sorted_by_ABC[0].get_file_name() != "dddddd" || sorted_by_ABC[1].get_file_name() != "ffffff") {
		return false;
	}

	files_info.clear();
	sorted_by_ABC.clear();

	//test 1.2
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35)
	};

	SortByABC(files_info, sorted_by_ABC);

	if (sorted_by_ABC[0].get_file_name() != "dddddd" || sorted_by_ABC[1].get_file_name() != "eeeeee"){
		return false;
	}

	files_info.clear();
	sorted_by_ABC.clear();

	//test 1.3
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35),
		Files("aaaaaa", 3, _date, 1)
	};

	SortByABC(files_info, sorted_by_ABC);

	if (sorted_by_ABC[0].get_file_name() != "aaaaaa" && sorted_by_ABC[1].get_file_name() != "dddddd") {
		return false;
	}

	files_info.clear();
	sorted_by_ABC.clear();

	//test 2.1
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20)
	};

	std::vector<Files> sorted_by_size;
	int min_size = 6;

	SortBySize(files_info, sorted_by_size, min_size);

	if (sorted_by_size.size() != 2) {
		return false;
	}

	files_info.clear();
	sorted_by_size.clear();

	//test 2.2
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35)
	};

	min_size = 5;

	SortBySize(files_info, sorted_by_size, min_size);

	if (sorted_by_size.size() != 3) {
		return false;
	}

	files_info.clear();
	sorted_by_size.clear();

	//test 2.3
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35),
		Files("aaaaaa", 3, _date, 1)
	};

	min_size = 3;

	SortBySize(files_info, sorted_by_size, min_size);

	if (sorted_by_size.size() != 4) {
		return false;
	}

	files_info.clear();
	sorted_by_size.clear();

	//test 3.1
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20)
	};

	std::vector<Files> sorted_by_accesses;
	int min_accesses = 11;

	SortByAccesses(files_info, sorted_by_accesses, min_accesses);

	if (sorted_by_accesses.size() != 2) {
		return false;
	}

	files_info.clear();
	sorted_by_accesses.clear();

	//test 3.2
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35)
	};

	min_accesses = 13;

	SortByAccesses(files_info, sorted_by_accesses, min_accesses);

	if (sorted_by_accesses.size() != 3) {
		return false;
	}

	files_info.clear();
	sorted_by_accesses.clear();

	//test 3.3
	files_info = {
		Files("dddddd", 12, _date, 9),
		Files("ffffff", 7, _date, 14),
		Files("gggggg", 4, _date, 20),
		Files("eeeeee", 27, _date, 35),
		Files("aaaaaa", 3, _date, 1)
	};

	min_accesses = 3;

	SortByAccesses(files_info, sorted_by_accesses, min_accesses);

	if (sorted_by_accesses.size() != 4) {
		return false;
	}

	files_info.clear();
	sorted_by_accesses.clear();

	return true;

}