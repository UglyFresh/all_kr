#include "test.h"

#define GREETINGS																	\
"Кузьмин Владислав Евгеньевич\nГруппа 4304\nВаринат 12\nТекст задания\n"			\
"В контрольной работе задается базовый и производный класс. Необходимо "			\
"разработать поля и методы, наследуемые из базового класса, а также собственные"	\
"компоненты производных классов.Базовый класс может быть абстрактным. "				\
"Реализовать возможность получения списка объектов в контейнере. "					\
"Предусмотреть необходимые проверки исходных данных."								\

#define USER_MENU																	\
"\nВыберите желаемый пункт: \n1. Провести тестирование программы\n2. Ввести данные "	\
"через консоль.\n3. Выгрузить данные из файла\n4. Завершить работу программы.\n"	\

enum MENU_CHOICE {TEST = 1, MANUAL_INPUT, DUMP_DATA, EXIT};
int main(){

	std::vector<std::unique_ptr<Person>> _person_info;
	int choice;

	std::cout << GREETINGS;

	while (true) {
		std::cout << USER_MENU;
		choice = ValidChoice(1, 4);
		static_cast <MENU_CHOICE> (choice);
		Person _person;
		Employee _emplouee;

		switch (choice) {
		case TEST:
			if (!Test()) {
				std::cout << "Тестирование провалено!";
			}
			else {
				std::cout << "Тестирование прошло успешно!";
			}
			break;
		case MANUAL_INPUT: {
			Person _person;
			Employee _employee;

			std::cout << "Данные о скольких людях вы бы хотели внести?  ";
			int num_of_person = ValidUserInput();
			for (int i = 0; i < num_of_person; i++) {
				std::cout << "Личность является сотрудниками уиверситета? 1- Да, 2 - Нет ";
				choice = ValidChoice(1, 2);
				if (choice == 1) {
					_employee.InputData(_person_info);
				}
				else {
					_person.InputData(_person_info);
				}
			}

			for (auto& person : _person_info) {
				person->Show();
			}
			
			std::cout << "Желаете сохранить данные? 1 - Да, 2 - Нет ";
			choice = ValidChoice(1, 2);
			if (choice == 1) {
				DownloadData(_person_info);
			}
			else {
				std::cout << "Данные не будут сохранены!";
			}
			break;
		}
		case DUMP_DATA:
			DumpData();
			break;
		case EXIT:
			return EXIT_SUCCESS;
		}
	}

}