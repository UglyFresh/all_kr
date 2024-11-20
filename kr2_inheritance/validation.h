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
