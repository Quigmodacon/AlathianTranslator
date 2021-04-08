// Translator
// by: Jonathan Hansen
// edit: APR 2 2021

#include "./../headers/translator.hpp"
#include <iostream>
#include <vector>

bool compare(const char* lhs, const char* rhs) {
	int i = 0;
	while (lhs[i] != '\0' && rhs[i] != '\0' && lhs[i] == rhs[i]) {
		i++;
	}
	return lhs[i] == rhs[i];
}

int main(int argc, char** argv) {

	std::cout << "\n\n\t~~~~Alathian Translator~~~~";
	std::cout << "\n\nEnter what you want to translate, end with \\0 after a space:\n";

	char word[256];
	char* transWord;
	Translator::Alathian ATranslator;

	std::vector<char*> sentence;

	char loop = 'y';
	while (loop == 'y') {
		std::cout << "\n\n";
		std::cin >> word;
		while (!compare(word, "\\0")) {
			transWord = ATranslator(word);
			sentence.push_back(transWord);
			std::cin >> word;
		}
		for(auto e : sentence) {
			std::cout << e << ' ';
		}
		sentence.clear();
		std::cout << "\n\n" << "Continue (y, n)? ";
		std::cin >> loop;
	}
}
