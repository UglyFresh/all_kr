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