#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Date {

private:

	int day;
	int month;
	int year;

public:

	Date() = default;
	Date(int d, int m, int y) : day(d), month(m), year(y) {}

	int get_day() const { return day; }
	int get_month() const { return month; }
	int get_year() const { return year; }

	void set_day(const int& new_day) { day = new_day; }
	void set_month(const int& new_month) { month = new_month; }
	void set_year(const int& new_year) { year = new_year; }

	~Date() = default;

};

class Files {

private:

	std::string file_name;
	int file_size;
	Date date_of_creation_file;
	int number_of_file_accesses;
	
public:

	Files() = default;
	Files(std::string fn, int fs, Date dcf, int nfa) : file_name(fn), file_size(fs), date_of_creation_file(dcf), number_of_file_accesses(nfa){}

	std::string get_file_name() const { return file_name; }
	int get_file_size() const { return file_size; }
	Date get_date_of_creation_file() const { return date_of_creation_file; }
	int get_number_of_file_accesses() const { return number_of_file_accesses; }

	void set_file_name(const std::string& new_file_name) { file_name = new_file_name; }
	void set_file_size(const int& new_file_size) { file_size = new_file_size; }
	void set_date_of_creation_file(const Date& new_date_of_creation_file) { date_of_creation_file = new_date_of_creation_file; }
	void set_number_of_file_accesses(const int& new_number_of_file_accesses) { number_of_file_accesses = new_number_of_file_accesses; }

	~Files() = default;

};