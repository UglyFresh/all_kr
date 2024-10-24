#pragma once
#include "validation.h"

/// <summary> ���� ������ � ����� </summary>/// <param name="files_info"> ������ �� ������ ������ </param>
void InputFilesInfo (std::vector <Files>& files_info, std::vector <Date>& _date);
/// <summary>�������� ������ � ���� </summary>/// <param name="files_info">������ �� ������ ������ Files</param>/// <param name="_date">������ �� ������ ������ Date</param>
void DownloadFileInfo(std::vector <Files> files_info, std::vector <Date>& _date, std::string& file_name);
/// <summary>��������� ����� �� ������� </summary>/// <param name="file_name">���� � �����</param>/// <returns>������� ��� ����</returns>
bool IsFileEmpty(std::string file_name);
/// <summary>�������� ������ � ���� </summary>/// <param name="files_info"> ������ �� ������ ������ Files </param>/// <param name="_date"> ������ �� ������ ������ Date </param>/// <param name="file_name"> ���� � ����� </param>
void DumpFileInfo(std::vector <Files>& files_info, std::vector <Date>& _date, std::string& file_name);