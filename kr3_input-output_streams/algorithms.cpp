#include "algorithms.h"

std::vector<std::string> TextPreparing(std::string text) {

	std::vector<std::string> new_text;
	std::stringstream ss(text);
	std::string word;
	int counter = 0;

	while (std::getline(ss, word, ' ')) { 
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
		new_text.push_back(word);
		counter++;
	}

	new_text.erase(std::remove_if(new_text.begin(), new_text.end(), [](unsigned char c) { return std::ispunct(c); }), new_text.end());

	return new_text;

}


//std::vector<std::string> FindAnagrams(int choice, std::string text) {

//}