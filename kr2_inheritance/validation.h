#pragma once
#include "person.h"

/// <summary>
/// Проверка корректноси пользовательского ввода
/// </summary>
/// <returns>Введенное значение</returns>
int ValidUserInput();

/// <summary>
/// Проверка выбора на соответствие диапазону
/// </summary>
/// <param name="begin">Нижняя граница выбора</param>
/// <param name="finish">Верхняя граница выбора</param>
/// <returns>Введенное значение</returns>
int ValidChoice(int begin, int finish);

/// <summary>
/// Проверка корректности имени файла
/// </summary>
/// <param name="file_name">Путь к файлу</param>
/// <returns>Истина или ложь</returns>
bool IsValidFileName(const std::string file_name);
