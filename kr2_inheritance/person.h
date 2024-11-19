#pragma once
#include <iostream>


/// <summary>
/// Родительский класс "Личность"
/// </summary>
class Person {
protected:

	std::string surname;
	char gender;
	std::string address;

public:

	Person() = default;
	Person(std::string srnm, char gndr, std::string adrs):surname(srnm), gender(gndr), address(adrs){}

	std::string get_surname() const { return surname; }
	char get_gender() const { return gender; }
	std::string get_address() const { return address; }

	void set_surname(const std::string& new_surname) { surname = new_surname; }
	void set_gender(const char& new_gender) { gender = new_gender; }
	void set_address(const std::string& new_address) { address = new_address; }

	virtual void Show() const {
		std::cout << "Личность:" << "\n"
			<< "Фамилия: " << get_surname() << ',' << "\n"
			<< "Пол: " << get_gender() << ',' << "\n"
			<< "Адрес: " << get_address() << ';' << std::endl;
	}

	~Person() = default;

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
	Employee(std::string srnm, char gndr, std::string adrs, std::string dprtmnt, std::string sbjct) : Person(srnm, gndr, adrs), department(dprtmnt), subject(sbjct){}

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

	~Employee() = default;

};