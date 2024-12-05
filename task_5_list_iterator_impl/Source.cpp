//Задание 5, Першин Александр, 335 группа

#include <iostream>
#include <string>
#include <algorithm>
#include "MyList.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	MyList<double> A;

	cout << endl << "Проверка push'ев" << endl;
	A.push_front(3.94);
	A.push_front(2);
	A.push_front(1);
	A.push_back(4);
	A.push_back(5.38);
	A.push_back(6);
	A.push_back(7);
	A.push_back(199);
	A.push_back(9000);

	MyList<double> B(A);

	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << ' ';
	}
	cout << endl;
	cout << "Size: " << B.size() << endl;
	B.nullptr_check();
	cout << endl;

	cout << endl << "Вывод с помощью итераторов: " << endl;
	for (auto it = B.begin(); it != B.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	auto it1 = B.begin();
	cout << endl << "Проверка advance: ";
	cout << endl << *it1;
	advance(it1, 2);
	cout << ", after advance : " << * it1 << endl;

	cout << endl << "Проверка for_each: ";
	for_each(B.begin(), B.end(), [](auto& a){ a = a - 10; });
	for (auto it = B.begin(); it != B.end(); ++it) {
		cout << *it << ' ';
	}

	cout << endl << "Проверка count: сколько раз встречается -7? - ";
	cout << count(B.begin(), B.end(), -7) << " раз" << endl;

	cout << endl << "Проверка count_if: сколько чисел меньших нуля? - ";
	cout << count_if(B.begin(), B.end(), [](auto a) { return a < 0; }) << endl;
	cout<< "а больших нуля? - ";
	cout << count_if(B.begin(), B.end(), [](auto a) { return a > 0; }) << endl;

	cout << endl << "Проверка replace: замена -6 на 3000";
	replace(B.begin(), B.end(), -6, 3000);
	cout << endl;
	for (auto it = B.begin(); it != B.end(); ++it) {
		cout << *it << ' ';
	}

	cout << endl << endl << "clear: " << endl;
	B.clear();
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;

	return 0;
}

