#include "test.h"

#define GREETINGS																		\
"Кузьмин Владислав Евгеньевич\nГруппа 4304\nВариант 12\nТекст задания:\n"				\
"Первая контрольная работа предназначена для приобретения практического"				\
"опыта в создании простейших классов с использованием языка"							\
"программирования С++.Необходимо разработать класс для указанной"						\
"предметной области.Доступ к данным реализовать с помощью методов Set, Get,"			\
"Show.Предусмотреть необходимые проверки исходных данных.\n"							\

#define USER_MENU																		\
"Вырите желаемый пункт меню: \n1. Провести тестирование программы\n2. Ввести данные "	\
"через консоль\n3. Загрузить данные из файла\n4. Завершить работу программы\n"			\

#define FILTER_MENU																		\
"Выберите желаемое действие: \n1. Вывести список файлов отфильтрованный в алфавитном "	\
"порядке\n2. Вывести список файлов размер которых превышает заданный\n3. Вывести"		\
"список файлов количество обращений которых превышает заданный\n4. Отказаться\n"		\

enum MENU_CHOICE { TEST = 1, MANUAL_INPUT, DUMP_DATA, EXIT };
enum FILTER_CHOICE {ABC_SORT = 1, SIZE_SORT, ACCESSES_SORT, MENU};

int main() {

	Files _file;
	const int begin_choice = 1, finish_choice = 4;
	int choice = 0;
	std::vector <Files> files_info;
	std::vector <Date> dates_info;
	std::vector <Files> sorted_files;

	std::cout << GREETINGS;

	while (true) {
		std::cout << USER_MENU;
		choice = ValidUserInput();
		while (begin_choice > choice && finish_choice < choice) {
			std::cout << "Ошибка! Выберите один  из предложенных вариантов: ";
			choice = ValidUserInput();
		}

		switch (choice) {
		case TEST:
		{
				if (Test()) {
					std::cout << "Тестирование прошло успешно!\n";
				}
				else {
					std::cout << "Тестирование провалено!\n";
				}
				break;
		}
		case MANUAL_INPUT:
		{
			int num_of_files;
			std::cout << "Введите желаемое количество файлов: ";
			num_of_files = ValidUserInput();
			while (num_of_files <= 0) {
				std::cout << "Необходимо заполнить хотя бы один файл! Повторите попытку: ";
				num_of_files = ValidUserInput();
			}

			for (int i = 0; i < num_of_files; i++) {
				InputFilesInfo(files_info, dates_info);
			}
			_file.Show(files_info, dates_info);

			std::cout << FILTER_MENU;
			choice = ValidUserInput();
			while (begin_choice > choice && finish_choice < choice) {
				std::cout << "Ошибка! Выберите один  из предложенных вариантов: ";
				choice = ValidUserInput();
			}

			switch (choice) {
			case ABC_SORT:
			{
				SortByABC(files_info, sorted_files);
				_file.Show(sorted_files, dates_info);
				files_info = sorted_files;
				break;
			}
			case SIZE_SORT:
			{
				std::cout << "Введите минииальный размер файла: ";
				int min_size = 0;
				min_size = ValidUserInput();
				while (min_size <= 0) {
					std::cout << "Ошибка! Размер файла должен быть больше нуля! Повторите попытку: ";
					min_size = ValidUserInput();
				}

				SortBySize(files_info, sorted_files, min_size);
				_file.Show(sorted_files, dates_info);
				files_info = sorted_files;
				break;
			}
			case ACCESSES_SORT:
			{
				std::cout << "Введите минииальное количество обращений: ";
				int min_accesses = ValidUserInput();
				while (min_accesses < 0) {
					std::cout << "Ошибка! Количество обращений не может быть меньше нуля! Повторите попытку: ";
					min_accesses = ValidUserInput();
				}

				SortByAccesses(files_info, sorted_files, min_accesses);
				_file.Show(sorted_files, dates_info);
				files_info = sorted_files;
				break;
			}
			case MENU:
				break;
			}

			std::cout << "Желаете сохранить результаты в файл?\n"
				<< "1 - Да\n2 - Нет\n";
			choice = ValidUserInput();
			while (choice != 1 && choice != 2) {
				std::cout << "Ошибка! Выберите из предложенных вариантов: ";
				choice = ValidUserInput();
			}

			if (choice == 1) {
				std::string file_location;
				std::cout << "Введите полный путь к файлу: ";
				std::cin >> file_location;
				std::ofstream file(file_location);

				while (!file.is_open()) {
					std::cout << "Ошибка открытия файла! Повтрите попытку: ";
					std::cin >> file_location;
					std::ofstream file(file_location);
				}

				while (IsFileEmpty(file_location)) {
					std::cout << "Файл содержит данные! Желаете перезаписать его?\n1 - Да\n2 - Нет\n";
					choice = ValidUserInput();
					while (choice != 1 && choice != 2) {
						std::cout << "Ошибка! Выберите из предлооженных вариантов: ";
						choice = ValidUserInput();
					}

					if (choice == 1) {
						DownloadFileInfo(files_info, dates_info, file_location);
					}
				}
				file.close();
			}
			files_info.clear();
			break;
		}
		case DUMP_DATA:
		{
			std::string file_location;
			std::cout << "Введите путь к файлу для выгрузки данных: ";
			std::cin >> file_location;
			std::ifstream file(file_location);

			while (!file.is_open()) {
				std::cout << "Ошибка открытия файла! Повторите попытку: ";
				std::cin >> file_location;
			}
			if (IsFileEmpty(file_location)) {
				std::cout << "Файл пуст!";
				break;
			}

			DumpFileInfo(files_info, dates_info, file_location);
			_file.Show(files_info, dates_info);

			std::cout << FILTER_MENU;
			choice = ValidUserInput();
			while (begin_choice > choice && finish_choice < choice) {
				std::cout << "Ошибка! Выберите один  из предложенных вариантов: ";
				choice = ValidUserInput();
			}

			switch (choice) {
			case ABC_SORT:
			{
				SortByABC(files_info, sorted_files);
				_file.Show(sorted_files, dates_info);
				break;
			}
			case SIZE_SORT:
			{
				std::cout << "Введите минииальный размер файла: ";
				int min_size = ValidUserInput();
				while (min_size <= 0) {
					std::cout << "Ошибка! Размер файла должен быть больше нуля! Повторите попытку: ";
					min_size = ValidUserInput();
				}

				SortBySize(files_info, sorted_files, min_size);
				_file.Show(sorted_files, dates_info);
				break;
			}
			case ACCESSES_SORT:
			{
				std::cout << "Введите минииальное количество обращений: ";
				int min_accesses = ValidUserInput();
				while (min_accesses < 0) {
					std::cout << "Ошибка! Количество обращений не может быть меньше нуля! Повторите попытку: ";
					min_accesses = ValidUserInput();
				}

				SortByAccesses(files_info, sorted_files, min_accesses);
				_file.Show(sorted_files, dates_info);
				break;
			}
			case MENU:
				break;
			}

			std::cout << "Желаете сохранить результаты в файл?\n"
				<< "1 - Да\n2 - Нет\n";
			choice = ValidUserInput();
			while (choice != 1 && choice != 2) {
				std::cout << "Ошибка! Выберите из предложенных вариантов: ";
				choice = ValidUserInput();
			}

			if (choice == 1) {
				std::string file_location;
				std::cout << "Введите полный путь к файлу: ";
				std::cin >> file_location;
				std::ofstream file(file_location);

				while (!file.is_open()) {
					std::cout << "Ошбика открытия файла! Повтрите попытку: ";
					std::cin >> file_location;
					std::ofstream file(file_location);
				}

				while (IsFileEmpty(file_location)) {
					std::cout << "Файл содержит данные! Желаете перезаписать его?\n1 - Да\n2 - Нет\n";
					choice = ValidUserInput();
					while (choice != 1 && choice != 2) {
						std::cout << "Ошибка! Выберите из предлооженных вариантов: ";
						choice = ValidUserInput();
					}

					if (choice == 1) {
						DownloadFileInfo(files_info, dates_info, file_location);
					}
				}
				file.close();
			}
			files_info.clear();
			break;
		}	
		case EXIT: return EXIT_SUCCESS;
		}
	}

}