#include "file_handling.h" 

void InputFilesInfo(std::vector <Files>& file_info, std::vector <Date>& _date) {

	std::string _name;
	int _size;
	int _num_of_accesses;
	Date _date_of_creation;

	std::cout << "Введите имя файла: ";
	std::cin >> _name;
	std::cout << "Введите размер файла: ";
	_size = ValidUserInput();
	while (_size <= 0) {
		std::cout << "Ошибка! Размер файла должен быть больше нуля! Пвторите попыттку: ";
		_size = ValidUserInput();
	}
	std::cout << "Введите дату создания файла: ";
	_date_of_creation = ValidDateInput(_date);
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
			log_file << "\nИмя файла: " << file.get_file_name() << ","
				<< "\nРазмер файла: " << file.get_file_size() << ","
				<< "\nДата создания файла: ";
			for (const auto& date : _date) {
				log_file << date.get_day() << '.'
					<< date.get_month() << '.'
					<< date.get_year() << ",";
				_date.erase(_date.begin());
				break;
			}
			log_file << "\nКоличество обращений к файлу: "
				<< file.get_number_of_file_accesses() << ";";
		}

		std::cout << "Данные успешно сохранены в файл:\n" << file_name;
	}

	log_file.close();

}

bool IsFileEmpty(std::string file_name) {

	std::ifstream file(file_name);

	if (file.peek() == EOF) {
		return true;
	}
	else {
		return false;
	}
}

void DumpFileInfo(std::vector <Files>& files_info, std::vector <Date>& _date, std::string& file_name) {

	std::ifstream dump_file(file_name);

	if (!dump_file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		std::string line;
		Files file;
		Date date{};

		while (std::getline(dump_file, line, ';')) {
			if (line.empty()) { continue; }
			std::stringstream str(line);
			std::string point;
			while (std::getline(str, point, ',')) {
				if (point.find("Имя файла:") != std::string::npos) {
					file.set_file_name(point.substr(point.find(":") + 1));
				}
				if (point.find("Размер файла:") != std::string::npos) {
					std::string size_str = point.substr(point.find(":") + 1);
					try {
						file.set_file_size(std::stoi(size_str));
					}
					catch (std::invalid_argument&) {
						std::cout << "Ошибка! Некорректный размер файла!\n";
					}
				}
				if (point.find("Дата создания файла:") != std::string::npos) {
					std::string day_str = point.substr(point.find(":") + 1, point.find_first_of(".") - 1);
					std::string month_str = point.substr(point.find_first_of(".") + 1, point.find_last_of(".") - 1);
					std::string year_str = point.substr(point.find_last_of(".") + 1);
					try {
						date.set_day(std::stoi(day_str));
						date.set_month(std::stoi(month_str));
						date.set_year(std::stoi(year_str));
					}
					catch (std::invalid_argument&) {
						std::cout << "Ошибка! Некорректная дата!\n";
					}
				}
				if (point.find("Количество обращений к файлу:") != std::string::npos) {
					std::string accesses_str = point.substr(point.find(":") + 1);
					try {
						file.set_number_of_file_accesses(std::stoi(accesses_str));
					}
					catch (std::invalid_argument&) {
						std::cout << "Ошибка! Некорректное количество обращений к файлу!\n";
					}
				}
			}
			_date.push_back(date);
			files_info.push_back(file);
		}
		dump_file.close();
	}

}