#include "file_handling.h"

bool IsFileEmpty(std::string file_name) {

	std::ifstream file(file_name);

	if (file.peek() == EOF) {
		return true;
	}
	else {
		return false;
	}
}

void DownloadData(std::vector<std::unique_ptr<Person>>& person_info) {

	std::string file_location;
	std::cout << "Введите полный путь к файлу для сохранения: ";
	std::cin >> file_location;
	while (IsValidFileName(file_location)) {
		std::cout << "Ошибка! Недопустимое имя файла! Повторите попытку: ";
		std::cin >> file_location;
	}

	std::ofstream log_file(file_location);
	if (!log_file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		for (const auto& person : person_info) {
			if (auto is_employee = dynamic_cast<Employee*>(person.get())) {
				log_file << "Сотрудник:\n"
					<< "\tФамилия: " << is_employee->get_surname() << ",\n"
					<< "\tПол: " << is_employee->get_gender() << ",\n"
					<< "\tАдрес: " << is_employee->get_address() << ",\n"
					<< "\tКафедра: " << is_employee->get_department() << ",\n"
					<< "\tПредмет: " << is_employee->get_subject() << ';' << std::endl;
			}
			else {
				log_file << "Личность:\n"
					<< "\tФамилия: " << person->get_surname() << ",\n"
					<< "\tПол: " << person->get_gender() << ",\n"
					<< "\tАдрес: " << person->get_address() << ';' << std::endl;
			}
		}

		std::cout << "Данные успешно сохранены в файл:\n" << file_location;
		log_file.close();
	}

}