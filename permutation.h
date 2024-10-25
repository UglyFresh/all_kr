#pragma once
#include "file_handling.h"
/// <summary>
/// ���������� � ���������� �������
/// </summary>
/// <param name="files_info">������ �� �����</param>
/// <param name="sorted_files_info">��������������� ������</param>
void SortByABC(std::vector <Files> files_info, std::vector <Files> sorted_files_info);
/// <summary>///���������� ������������ ���������� �������
/// </summary>
/// /// <param name="files_info">������ �� �����</param>
/// /// <param name="sorted_files_info">��������������� ������</param>
/// /// <param name="min_size">����������� ������ �����</param>
void SortBySize(std::vector <Files> files_info, std::vector <Files> sorted_files_info, int min_size);
/// <summary>
/// ���������� ������������ ���������� ���������� ���������
/// /// </summary>
/// /// <param name="files_info"> ������ �� �����</param>
/// /// <param name="sorted_files_info"> ��������������� ������</param>
/// /// <param name="min_accesses"> ����������� ���������� ��������� </param>
void SortByAccesses(std::vector <Files> files_info, std::vector <Files> sorted_files_info, int min_accesses);