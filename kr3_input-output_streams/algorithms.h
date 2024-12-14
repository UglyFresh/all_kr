#pragma once
#include "validation.h"
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<std::string> TextPreparing(std::string text);
/// <summary>Посик аннограмм</summary>/// <returns>Истина или ложь</returns>
std::vector<std::string> FindAnagrams(int choice, std::string text );