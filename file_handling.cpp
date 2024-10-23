#include "file_handling.h" 

void InputFilesInfo(std::vector <Files>& file_info, std::vector <Date>& _date) {

	std::string _name;
	int _size;
	int _num_of_accesses;

	std::cout << "������� ��� �����: ";
	std::cin >> _name;
	std::cout << "������� ������ �����: ";
	_size = ValidUserInput();
	while (_size <= 0) {
		std::cout << "������! ������ ����� ������ ���� ������ ����! �������� ��������: ";
		_size = ValidUserInput();
	}
	std::cout << "������� ���� �������� �����: ";
	Date _date_of_creation = ValidDateInput(_date);
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
					<< date.get_year() << '.';
			}
			log_file << "\n���������� ��������� � �����: "
				<< file.get_number_of_file_accesses();
		}

		std::cout << "������ ������� ��������� � ����:\n" << file_name;
	}

	log_file.close();

}
