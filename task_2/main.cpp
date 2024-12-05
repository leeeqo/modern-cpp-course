//Задание 2, Першин Александр, 335 группа

#include <iostream>
#include <string>
#include <memory>
#include "MyList.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	MyList<double> A;

	cout << endl << "Проверка push'ев" << endl;
	A.push_front(3);
	A.push_front(2);
	A.push_front(1);
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	A.push_back(7);


	MyList<double> B(A); 

	
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;
	B.nullptr_check();
	cout << endl;


	cout << endl << "Проверка pop'ов" << endl;
	B.pop_back();
	B.pop_front();
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "size: " << B.size() << endl;
	B.nullptr_check();
	cout << endl;

	cout << endl << "resize(10, 789): " << endl;
	B.resize(10, 789);
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;

	cout << endl << "unique: " << endl;
	B.unique();
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;

	cout << endl << "reverse: " << endl;
	B.reverse();
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << endl <<  "Size: " << B.size() << endl;

	cout << endl << "insert(5, 106969.4, 3): " << endl;
	B.insert(5, 106969.4, 3);
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;

	cout << endl << "erase(3, 5): " << endl;
	B.erase(3, 5);
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;
	B.nullptr_check();
	cout << endl;
	
	cout << endl << "clear: " << endl;
	B.clear();
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << endl;
	}
	cout << "Size: " << B.size() << endl;

	return 0;
}


