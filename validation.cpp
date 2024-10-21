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

Date ValidDateInput() {

	int _year;
	int _month;
	int _day;

	std::cout << "������� ���: ";
	_year = ValidUserInput();
	while (_year < 1990 || _year > 2024) {
		std::cout << "������! ������������ ���! ��������� �������: ";
		_year = ValidUserInput();
	}

	std::cout << "\n������� �����: ";
	_month = ValidUserInput();
	while (_month < 1 || _month > 12) {
		std::cout << "������! ������������ �����! ��������� �������: ";
		_month = ValidUserInput();
	}

	std::cout << "\n������� ����: ";
	_day = ValidUserInput();

	while (_year % 4 == 0 && _month == 2 && _day > 29 && _day < 1) {
		std::cout << "������! � ���������� ��� � ���� ������ �� ������ 29 ����! ��������� �������: ";
		_day = ValidUserInput();
	}

	while (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12 && _day > 31 || _day < 1) {
		std::cout << "������! � ���� ������ �� ����� ���� ������ 31 ���! ��������� �������: ";
		_day = ValidUserInput();
	}

	while (_month == 4 || _month == 6 || _month == 9 || _month == 11 && _day > 30 || _day < 1) {
		std::cout << "������! � ���� ������ �� ����� ���� ������ 30 ����! ��������� �������: ";
		_day = ValidUserInput();
	}

	if (_year % 4 != 0 && _month == 2) {
		while (_day < 1 || _day > 28) {
			std::cout << "������! � ���� ������ �� ����� ���� ������ 28 ����! ��������� �������: ";
			_day = ValidUserInput();
		}
	}

	Date _creation_date(_day, _month, _year);

	return _creation_date;

}