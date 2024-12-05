#include <iostream>
#include <string>
#include "Poly3.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	double koefi[4];
	cout << "������� ������������ 1 ��������: " << '\n';
	for (size_t i = 0; i < 4; i++) {
		cin >> koefi[i];
	};
	
	double koefi2[4];
	cout << "������� ������������ 2 ��������: " << '\n';
	for (size_t i = 0; i < 4; i++) {
		cin >> koefi2[i];
	};

	Poly3 Polinom(koefi);
	Poly3 Polinom2(koefi2);

	cout << "1-� �������: " << Polinom << '\n' << "2-� �������: " << Polinom2 << '\n';
	
	string operation = "s";
	while (true) {
		cout << '\n' << "��������: ";
		cin >> operation;
		if (operation == "f") {  //����� �� ����� - �������� f
			break;
		}
		if (operation == "+=") {
			operation = "1";
		}
		if (operation == "-=") {
			operation = "2";
		}
		const char* oper = operation.c_str(); //������� ������ � ������ ����� ��� switch'a (���� ������ ��-�� +=, -=)
		switch (oper[0]) {
		case '+':
			cout << "����� ���������: " << Polinom + Polinom2;
			break;
		case '-':
			cout << "�������� ���������: " << Polinom - Polinom2;
			break;
		case '1':
			Polinom += Polinom2;
			cout << "����������� �������� � ���������: " << Polinom;
			break;
		case '2':
			Polinom -= Polinom2;
			cout << "��������� �������� �� ���������: " << Polinom;
			break;
		case '*':
			cout << "������������ ���������: " << Polinom * Polinom2;
			break;
		case '/':
			cout << "������� ���������: " << Polinom / Polinom2;
			break;
		}
	}
	return 0;
}