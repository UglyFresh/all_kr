#include "file_handling.h"

void InputFilesInfo(std::vector <Files>& file_info) {

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
	Date _date_of_creation = ValidDateInput();
	std::cout << "������� ���������� ��������� � �����: ";
	_num_of_accesses = ValidUserInput();
	while (_num_of_accesses < 0) {
		std::cout << "������! ���������� ��������� � ����� �� ����� ���� ��������������! ��������� �������: ";
		_num_of_accesses = ValidUserInput();
	}

	Files files_info(_name, _size, _date_of_creation, _num_of_accesses);
	file_info.push_back(files_info);
}
