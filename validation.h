#include "files.h"

/// <summary> ��������� ����������������� ����� </summary>/// <returns>���������������� ����</returns>
int ValidUserInput();
/// <summary> �������� ������������ ���� </summary>/// <returns>��������� ������ Date</returns>
Date ValidDateInput(std::vector <Date>& _date);
/// <summary> �������� ������ ����� �� ������������������� </summary>/// <param name="file_name"> ���� � ����� </param>/// <returns> ������� ��� ���� </returns>
bool ValidFileName(std::string file_name);