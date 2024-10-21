#include "file_handling.h"

void InputFilesInfo(std::vector <Files>& file_info) {

	std::string _name;
	int _size;
	int _num_of_accesses;

	std::cout << "Введите имя файла: ";
	std::cin >> _name;
	std::cout << "Введите размер файла: ";
	_size = ValidUserInput();
	while (_size <= 0) {
		std::cout << "Ошибка! Размер файла должен быть больше нуля! Пвторите попыттку: ";
		_size = ValidUserInput();
	}
	std::cout << "Введите дату создания файла: ";
	Date _date_of_creation = ValidDateInput();
	std::cout << "Введите количество обращений к файлу: ";
	_num_of_accesses = ValidUserInput();
	while (_num_of_accesses < 0) {
		std::cout << "Ошибка! Количество обращений к файду не может быть отрицателльным! Повторите попытку: ";
		_num_of_accesses = ValidUserInput();
	}

	Files files_info(_name, _size, _date_of_creation, _num_of_accesses);
	file_info.push_back(files_info);
}
