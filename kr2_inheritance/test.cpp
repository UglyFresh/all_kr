#include "test.h"

bool Test() {

	Person _test_person("Kuzmin", "M", "Veteranov_avenue");

	if (_test_person.get_surname() != "Kuzmin") {
		return false;
	}
	if (_test_person.get_gender() != "M") {
		return false;
	}
	if (_test_person.get_address() != "Veteranov_avenue") {
		return false;
	}

	Employee _test_employee("Fedin", "M", "Pushkina_str", "SAPR", "VSIT");

	if (_test_employee.get_surname() != "Fedin") {
		return false;
	}
	if (_test_employee.get_gender() != "M") {
		return false;
	}
	if (_test_employee.get_address() != "Pushkina_str") {
		return false;
	}
	if (_test_employee.get_department() != "SAPR") {
		return false;
	}
	if (_test_employee.get_subject() != "VSIT") {
		return false;
	}

	return true;
}