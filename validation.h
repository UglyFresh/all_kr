#include "files.h"

/// <summary> Прроверка пользовательского ввода </summary>/// <returns>Пользовательский ввод</returns>
int ValidUserInput();
/// <summary> Проверка корректности даты </summary>/// <returns>Экземпляр класса Date</returns>
Date ValidDateInput(std::vector <Date>& _date);
/// <summary> Проверка имении файла на зарезервированность </summary>/// <param name="file_name"> Путь к файлу </param>/// <returns> Истинна или Ложь </returns>
bool ValidFileName(std::string file_name);