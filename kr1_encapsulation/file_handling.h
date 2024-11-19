#pragma once
#include "validation.h"

/// <summary> Ввод данных о файле </summary>/// <param name="files_info"> Вектор на основе класса </param>
void InputFilesInfo (std::vector <Files>& files_info, std::vector <Date>& _date);
/// <summary>Загрузка данных в файл </summary>/// <param name="files_info">Вектор на основе класса Files</param>/// <param name="_date">Вектор на основе класса Date</param>
void DownloadFileInfo(std::vector <Files> files_info, std::vector <Date>& _date, std::string& file_name);
/// <summary>Прповерка файла на пустоту </summary>/// <param name="file_name">Путь к файлу</param>/// <returns>Истинна или Ложь</returns>
bool IsFileEmpty(std::string file_name);
/// <summary>Выгрузка данных в файл </summary>/// <param name="files_info"> Вектор на основе класса Files </param>/// <param name="_date"> Вектор на основе класса Date </param>/// <param name="file_name"> Путь к файлу </param>
void DumpFileInfo(std::vector <Files>& files_info, std::vector <Date>& _date, std::string& file_name);