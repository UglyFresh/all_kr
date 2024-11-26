#pragma once
#include "person.h"

/// <summary>
/// Проверка файла на содержание данных
/// </summary>
/// <param name="file_name">- путь к файлу</param>
/// <returns>Истина или ложь</returns>
bool IsFileEmpty(std::string file_name);

/// <summary>
/// Загрузка данных в файл
/// </summary>
/// <param name="person_info">- вектор содержащий данные </param>
void DownloadData(std::vector<std::unique_ptr<Person>>& person_info);

/// <summary>
/// Выгрузка данных из файла 
/// </summary>
void DumpData();