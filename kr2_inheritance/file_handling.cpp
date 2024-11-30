#include "file_handling.h"
#include <string>
#include <sstream>

bool IsFileEmpty(std::string file_name) {

	std::ifstream file(file_name);

	if (file.peek() == EOF) {
		return true;
	}
	else {
		return false;
	}

	file.close();
}

void DownloadData(std::vector<std::unique_ptr<Person>>& person_info) {

	std::string file_location;
	std::cout << "Введите полный путь к файлу для сохранения: ";
	std::cin >> file_location;
	while (IsValidFileName(file_location)) {
		std::cout << "Ошибка! Недопустимое имя файла! Повторите попытку: ";
		std::cin >> file_location;
	}
	
	while (!IsFileEmpty(file_location)) {
		std::cout << "Файл содержит данные! Желаете перезаписать его? 1- Да, 2 - Нет ";
		int choice = ValidChoice(1, 2);
		if (choice == 2) {
			std::cout << "Введите путь к новому файлу для сохранения: ";
			std::cin >> file_location;
		}
		else {
			break;
		}
	}
	std::ofstream log_file(file_location);
	if (!log_file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		for (const auto& person : person_info) {
			if (auto is_employee = dynamic_cast<Employee*>(person.get())) {
				log_file << "\nСотрудник|\n"
					<< "\tФамилия: " << is_employee->get_surname() << ",\n"
					<< "\tПол: " << is_employee->get_gender() << ",\n"
					<< "\tАдрес: " << is_employee->get_address() << ",\n"
					<< "\tКафедра: " << is_employee->get_department() << ",\n"
					<< "\tПредмет: " << is_employee->get_subject() << ';';
			}
			else {
				log_file << "\nЛичность|\n"
					<< "\tФамилия: " << person->get_surname() << ",\n"
					<< "\tПол: " << person->get_gender() << ",\n"
					<< "\tАдрес: " << person->get_address() << ';';
			}
		}

		std::cout << "Данные успешно сохранены в файл:\n" << file_location;
		log_file.close();
		person_info.clear();
	}


}

void DumpData() {

	std::string file_location;
	std::cout << "Введите полный путь к файлу для выгрузки: ";
	std::cin >> file_location;
	while (IsValidFileName(file_location)) {
		std::cout << "Ошибка! Недопустимое имя файла! Повторите попытку: ";
		std::cin >> file_location;
	}

	while (IsFileEmpty(file_location)) {
		std::cout << "Файл пуст! Попробуйте другой файл: ";
		std::cin >> file_location;
		while (IsValidFileName(file_location)) {
			std::cout << "Ошибка! Недопустимое имя файла! Повторите попытку: ";
			std::cin >> file_location;
		}
	}

	std::ifstream dump_file(file_location);
	if (!dump_file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		std::vector<std::unique_ptr<Person>> person_info;
		std::string line;

		while (std::getline(dump_file, line, ';')) {
			if (line.empty()) { continue; }
			std::string surname, gender, address, department, subject;
			std::stringstream str(line);
			std::string point;
			if (line.find("Личность|") != std::string::npos) {
				while (std::getline(str, point, ',')) {
					if (point.find("Фамилия:") != std::string::npos) {
						surname = point.substr(point.find(':') + 1);
					}
					if (point.find("Пол:") != std::string::npos) {
						gender = point.substr(point.find(':') + 1);
					}
					if (point.find("Адрес:") != std::string::npos) {
						address = point.substr(point.find(':') + 1);
					}
				}
				person_info.push_back(std::make_unique<Person>(surname, gender, address));
			}
			else if (line.find("Сотрудник|") != std::string::npos) {
				while (std::getline(str, point, ',')) {
					if (point.find("Фамилия:") != std::string::npos) {
						surname = point.substr(point.find(':') + 1);
					}
					if (point.find("Пол:") != std::string::npos) {
						gender = point.substr(point.find(':') + 1);
					}
					if (point.find("Адрес:") != std::string::npos) {
						address = point.substr(point.find(':') + 1);
					}
					if (point.find("Кафедра:") != std::string::npos) {
						department = point.substr(point.find(':') + 1);
					}
					if (point.find("Предмет:") != std::string::npos) {
						subject = point.substr(point.find(':') + 1);
					}
				}
				person_info.push_back(std::make_unique<Employee>(surname, gender, address, department, subject));
			}
			else {
				std::cout << "Некорректный файл! Возможна потеря данных";
			}
		}
		std::cout << "Считывание завершенно!" << std::endl;
		
		for (auto& person : person_info) {
			person->Show();
		}

		dump_file.close();
		person_info.clear();

	}

}