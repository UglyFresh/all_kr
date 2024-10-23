#include "file_handling.h" 

void InputFilesInfo(std::vector <Files>& file_info, std::vector <Date>& _date) {

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
	Date _date_of_creation = ValidDateInput(_date);
	std::cout << "Введите количество обращений к файлу: ";
	_num_of_accesses = ValidUserInput();
	while (_num_of_accesses < 0) {
		std::cout << "Ошибка! Количество обращений к файду не может быть отрицателльным! Повторите попытку: ";
		_num_of_accesses = ValidUserInput();
	}

	Files files_info(_name, _size, _date_of_creation, _num_of_accesses);
	file_info.push_back(files_info);
}

void DownloadFileInfo(std::vector <Files> files_info, std::vector <Date>& _date, std::string& file_name) {

	while (ValidFileName(file_name)) {
		std::cout << "Ошибка! Имя файла зарезервированно! Повторите попытку: ";
		std::cin >> file_name;
	}

	std::ofstream log_file(file_name);

	if (!log_file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		for (const auto& file : files_info) {
			log_file << "Имя файла: " << file.get_file_name()
				<< "\nРазмер файла: " << file.get_file_size()
				<< "\nДата создания файла: ";
			for (const auto& date : _date) {
				log_file << date.get_day() << '.'
					<< date.get_month() << '.'
					<< date.get_year() << '.';
			}
			log_file << "\nКоличество обращений к файлу: "
				<< file.get_number_of_file_accesses();
		}

		std::cout << "Данные успешно сохранены в файл:\n" << file_name;
	}

	log_file.close();

}
