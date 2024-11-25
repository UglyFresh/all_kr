#include "validation.h"

int ValidUserInput() {

    int choice;
    while (!(std::cin >> choice)) {
        std::cout << "Ошибка ввода! Введите вещественное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;

}

int ValidChoice(int begin, int finish) {

    int menu_choice = ValidUserInput();
    while (begin > menu_choice && finish < menu_choice) {
        std::cout << "Ошибка! Выберите одно из предложенных значений: ";
        menu_choice = ValidUserInput();
    }

    return menu_choice;

}

bool IsValidFileName(const std::string file_name) {

	std::vector<std::string> reserved_filenames = {
		"CON.txt",  "PRN.txt",  "AUX.txt",  "NUL.txt",  "COM1.txt", "COM2.txt",
		"COM3.txt", "COM4.txt", "COM5.txt", "COM6.txt", "COM7.txt", "COM8.txt",
		"COM9.txt", "LPT1.txt", "LPT2.txt", "LPT3.txt", "LPT4.txt", "LPT5.txt",
		"LPT6.txt", "LPT7.txt", "LPT8.txt", "LPT9.txt", "con.txt",  "prn.txt",
		"aux.txt",  "nul.txt",  "com1.txt", "com2.txt", "com3.txt", "com4.txt",
		"com5.txt", "com6.txt", "com7.txt", "com8.txt", "com9.txt", "lpt1.txt",
		"lpt2.txt", "lpt3.txt", "lpt4.txt", "lpt5.txt", "lpt6.txt", "lpt7.txt",
		"lpt8.txt", "lpt9.txt" };

	for (const std::string& reserved_filename : reserved_filenames) {
		if (file_name.find(reserved_filename) != std::string::npos) {
			return true;
		}
	}

	return false;

}