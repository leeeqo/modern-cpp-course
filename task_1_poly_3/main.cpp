#include <iostream>
#include <string>
#include "Poly3.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	double koefi[4];
	cout << "Введите коэффициенты 1 полинома: " << '\n';
	for (size_t i = 0; i < 4; i++) {
		cin >> koefi[i];
	};
	
	double koefi2[4];
	cout << "Введите коэффициенты 2 полинома: " << '\n';
	for (size_t i = 0; i < 4; i++) {
		cin >> koefi2[i];
	};

	Poly3 Polinom(koefi);
	Poly3 Polinom2(koefi2);

	cout << "1-й полином: " << Polinom << '\n' << "2-й полином: " << Polinom2 << '\n';
	
	string operation = "s";
	while (true) {
		cout << '\n' << "Операция: ";
		cin >> operation;
		if (operation == "f") {  //выход из цикла - операция f
			break;
		}
		if (operation == "+=") {
			operation = "1";
		}
		if (operation == "-=") {
			operation = "2";
		}
		const char* oper = operation.c_str(); //перевод строки в массив чаров для switch'a (саму строку из-за +=, -=)
		switch (oper[0]) {
		case '+':
			cout << "Сумма полиномов: " << Polinom + Polinom2;
			break;
		case '-':
			cout << "Разность полиномов: " << Polinom - Polinom2;
			break;
		case '1':
			Polinom += Polinom2;
			cout << "Прибавление полинома к исходному: " << Polinom;
			break;
		case '2':
			Polinom -= Polinom2;
			cout << "Вычитание полинома из исходного: " << Polinom;
			break;
		case '*':
			cout << "Произведение полиномов: " << Polinom * Polinom2;
			break;
		case '/':
			cout << "Частное полиномов: " << Polinom / Polinom2;
			break;
		}
	}
	return 0;
}