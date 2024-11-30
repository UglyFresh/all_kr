#pragma once
#include <iostream>

/// <summary>
/// Проверка на корректность ввода
/// </summary>
/// <returns>Введенное значение</returns>
int ValidUserInput();
/// <summary>Проверка на соотвествие диапазону</summary>/// <param name="begin">- нижняя граница</param>/// <param name="finish">-верхняя граница </param>/// <returns>Введенное значение</returns>
int ValidChoice(int begin, int finish);