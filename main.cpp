#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

template <typename T>
void fill_arr(T arr[], int length, int l, int r) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (r - l) + l;
}
template <typename T>
void print_arr(T arr[], int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
bool myFunction1(std::string str) {
	std::string str1{};

	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	int j = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == str[j])
			str1 += str[j];
		j++;
	}
	if (str == str1)
		return true;
	else
		return false;
		
}
int myFunction2(std::string str) {
	int counter{};
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',' || str[i] == '!' || str[i] == '.' || str[i] == ' ' || str[i] == '?')
			counter++;
	}
	return counter;

}
std::string myFunction3(std::string str, char sym) {
	int u = str.rfind(sym);
	
	return str.substr(u, str.length() - 1);
}
 
int main() {
	system("chcp 1251>null");
	setlocale(LC_ALL, "Russian");
	//Задача 1
	std::cout << "Задача 1. Изначальная строка  - Hello world!" << std::endl;
	std::string str = "Hello world!", result;
	char sym;
	std::cout << "Введите символ -> ";
	std::cin >> sym;
	std::cin.ignore();
	for (int i = 0; i < str.size(); i++)
		if (str[i] == sym)
			result += sym;
	std::cout << "Новая строка: " << result << std::endl;

	// Задача 2
	std::string str1;
	std::cout << "Задача 2. Введите слово -> " << std::endl;
	std::getline(std::cin, str1);
	if (myFunction1(str1))
		std::cout << "Слово " << str1 << " является палиндромом" << std::endl;
	else
		std::cout << "Слово " << str1 << " не является палиндромом" << std::endl;
	
	//Задача 3
	std::string str2;
	std::cout << "Задача 3. Введите строку -> " << std::endl;
	std::getline(std::cin, str2);
	std::cout << "В вашей строке " << myFunction2(str2) << " искомых символа(ов)." << std::endl;
	

	//Задача 4
	std::string str3;
	char sym1{};
	std::cout << "Задача 4. Введите строку -> " << std::endl;
	std::getline(std::cin, str3);
	std::cout << "Первоначальная строка - " << str3 << std::endl;
	std::cout << "Введите символ -> " << std::endl;
	std::cin >> sym1;
	std::cout << "Подстрока извлеченная с последнего вхождения символа " << sym1 << ':' << std::endl;
	std::cout << myFunction3(str3, sym1);
}