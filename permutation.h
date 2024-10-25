#pragma once
#include "file_handling.h"
/// <summary>
/// Сортировка в алфавитном порядке
/// </summary>
/// <param name="files_info">Данные из файла</param>
/// <param name="sorted_files_info">Отсортированные данные</param>
void SortByABC(std::vector <Files> files_info, std::vector <Files> sorted_files_info);
/// <summary>///сортировка относительно указанного размера/// </summary>/// <param name="files_info"></param>/// <param name="sorted_files_info"></param>/// <param name="min_size"></param>
void SortBySize(std::vector <Files> files_info, std::vector <Files> sorted_files_info, int min_size);