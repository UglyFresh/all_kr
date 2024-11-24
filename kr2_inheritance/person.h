#pragma once
#include "validation.h"


/// <summary>
/// Родительский класс "Личность"
/// </summary>
class Person {
protected:

	std::string surname;
	std::string gender;
	std::string address;

public:

	Person() = default;
	Person(std::string srnm, std::string gndr, std::string adrs):surname(srnm), gender(gndr), address(adrs){}

	std::string get_surname() const { return surname; }
	std::string get_gender() const { return gender; }
	std::string get_address() const { return address; }

	void set_surname(const std::string& new_surname) { surname = new_surname; }
	void set_gender(const std::string& new_gender) { gender = new_gender; }
	void set_address(const std::string& new_address) { address = new_address; }

	virtual void Show() const {
		std::cout << "Личность:" << "\n"
			<< "Фамилия: " << get_surname() << ',' << "\n"
			<< "Пол: " << get_gender() << ',' << "\n"
			<< "Адрес: " << get_address() << ';' << std::endl;
	}

	virtual std::vector<std::unique_ptr<Person>> InputData() {

		std::vector <std::unique_ptr<Person>> person_info;

		std::cout << "Введите фамилию: ";
		std::cin >> surname;
		std::cout << "Введите пол (мужской - M/женский - W): ";
		std::cin >> gender;
		while (gender != "M" && gender != "W") {
			std::cout << "Ошибка! Выберите из предложенных вариантов: ";
			std::cin >> gender;
		}
		std::cout << "Введите адрес: ";
		std::cin >> address;

		person_info.push_back(std::make_unique<Person>(surname, gender, address));
		return person_info;
	}

	virtual ~Person() {}

};


/// <summary>
/// Дочерний класс "Сотрудник университета"
/// </summary>
class Employee : public Person{
private:

	std::string department;
	std::string subject;

public:

	Employee() = default;
	Employee(std::string srnm, std::string gndr, std::string adrs, std::string dprtmnt, std::string sbjct) : Person(srnm, gndr, adrs), department(dprtmnt), subject(sbjct){}

	std::string get_department() const { return department; }
	std::string get_subject() const { return subject; }

	void set_department(const std::string new_department) { department = new_department; }
	void set_subject(const std::string new_subject) { subject = new_subject; }

	void Show() const override {
		std::cout << "Сотрудник университета:" << "\n"
			<< "Фамилия: " << get_surname() << ',' << "\n"
			<< "Пол: " << get_gender() << ',' << "\n"
			<< "Адрес: " << get_address() << ',' << "\n"
			<< "Кафедра: " << get_department() << ',' << "\n"
			<< "Должность" << get_subject() << ';' << std::endl;
	}

	virtual std::vector<std::unique_ptr<Person>> InputData() override {

		std::vector <std::unique_ptr<Person>> person_info;

		std::cout << "Введите фамилию: ";
		std::cin >> surname;
		std::cout << "Введите пол (мужской - M/женский - W): ";
		std::cin >> gender;
		while (gender != "M" && gender != "W") {
			std::cout << "Ошибка! Выберите из предложенных вариантов: ";
			std::cin >> gender;
		}
		std::cout << "Введите адрес: ";
		std::cin >> address;
		std::cout << "Введите кафедру: ";
		std::cin >> department;
		std::cout << "Введите предмет который ведет сотрудник: ";
		std::cin >> subject;

		person_info.push_back(std::make_unique<Employee>(surname, gender, address, department, subject));
		return person_info;
	}

	virtual ~Employee() override {};

};