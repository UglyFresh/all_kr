#include "file_handling.h" 

void InputFilesInfo(std::vector <Files>& file_info, std::vector <Date>& _date) {

	std::string _name;
	int _size;
	int _num_of_accesses;
	Date _date_of_creation;

	std::cout << "������� ��� �����: ";
	std::cin >> _name;
	std::cout << "������� ������ �����: ";
	_size = ValidUserInput();
	while (_size <= 0) {
		std::cout << "������! ������ ����� ������ ���� ������ ����! �������� ��������: ";
		_size = ValidUserInput();
	}
	std::cout << "������� ���� �������� �����: ";
	_date_of_creation = ValidDateInput(_date);
	std::cout << "������� ���������� ��������� � �����: ";
	_num_of_accesses = ValidUserInput();
	while (_num_of_accesses < 0) {
		std::cout << "������! ���������� ��������� � ����� �� ����� ���� ��������������! ��������� �������: ";
		_num_of_accesses = ValidUserInput();
	}

	Files files_info(_name, _size, _date_of_creation, _num_of_accesses);
	file_info.push_back(files_info);
}

void DownloadFileInfo(std::vector <Files> files_info, std::vector <Date>& _date, std::string& file_name) {

	while (ValidFileName(file_name)) {
		std::cout << "������! ��� ����� ����������������! ��������� �������: ";
		std::cin >> file_name;
	}

	std::ofstream log_file(file_name);

	if (!log_file.is_open()) {
		std::cout << "������ �������� �����!";
	}
	else {
		for (const auto& file : files_info) {
			log_file << "��� �����: " << file.get_file_name()
				<< "\n������ �����: " << file.get_file_size()
				<< "\n���� �������� �����: ";
			for (const auto& date : _date) {
				log_file << date.get_day() << '.'
					<< date.get_month() << '.'
					<< date.get_year();
			}
			log_file << "\n���������� ��������� � �����: "
				<< file.get_number_of_file_accesses() << "\n";
			
		}

		std::cout << "������ ������� ��������� � ����:\n" << file_name;
	}

	log_file.close();

}

bool IsFileEmpty(std::string file_name) {

	std::ifstream file(file_name);

	if (file.peek() == EOF) {
		return false;
	}
	else {
		return true;
	}
}

void DumpFileInfo(std::vector <Files>& files_info, std::vector <Date>& _date, std::string& file_name) {

	std::ifstream dump_file(file_name);

	if (!dump_file.is_open()) {
		std::cout << "������ �������� �����!";
	}
	else {
		std::string line;
		Files file;
		Date date;

		while (std::getline(dump_file, line)) {
			if (line.empty()) { continue; }
			std::stringstream str(line);
			std::string point;
			while (std::getline(str, point)) {
				if (point.find("��� �����:") != std::string::npos) {
					file.set_file_name(point.substr(point.find(":") + 1));
				}
				if (point.find("������ �����:") != std::string::npos) {
					std::string size_str = point.substr(point.find(":") + 1);
					try {
						file.set_file_size(std::stoi(size_str));
					}
					catch (std::invalid_argument&) {
						std::cout << "������! ������������ ������ �����!\n";
					}
				}
				if (point.find("���� �������� �����:") != std::string::npos) {
					std::string day_str = point.substr(point.find(":") + 1, point.find_first_of(".") - 1);
					try {
						int _day = std::stoi(day_str);
						date.set_day(_day);
					}
					catch (std::invalid_argument&) {
						std::cout << "������! ������������ ����!\n";
					}
					std::string month_str = point.substr(point.find_first_of(".") + 1, point.find_last_of(".") - 1);
					try {
						int _month = std::stoi(month_str);
						date.set_month(_month);
					}
					catch (std::invalid_argument&) {
						std::cout << "������! ������������ �����!\n";
					}
					std::string year_str = point.substr(point.find_last_of(".") + 1);
					try {
						int _year = std::stoi(year_str);
						date.set_year(_year);
					}
					catch (std::invalid_argument&) {
						std::cout << "������! ������������ ���!\n";
					}
					_date.push_back(date);
				}
				if (point.find("���������� ��������� � �����:") != std::string::npos) {
					std::string accesses_str = point.substr(point.find(":") + 1);
					try {
						file.set_number_of_file_accesses(std::stoi(accesses_str));
					}
					catch (std::invalid_argument&) {
						std::cout << "������! ������������ ���������� ��������� � �����!\n";
					}
				}
			}
		}
		files_info.push_back(file);
	}

}