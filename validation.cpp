#include "validation.h"

int ValidUserInput() {

    int choice;
    while (!(std::cin >> choice)) {
        std::cout << "������ �����! ������� ������������ �����: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;
    
}