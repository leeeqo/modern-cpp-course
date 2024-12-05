#pragma once
#include <iostream>
#include <string>

using namespace std;

class Poly3 {
private:
	double koef[4];
public:
	Poly3() {
		for (int i = 0; i < 4; i++) {
			koef[i] = 0;
		};
	}

	Poly3(double koef[4]) {
		for (int i = 0; i < 4; i++) {
			this->koef[i] = koef[i];
		};
	}

	Poly3(const Poly3& copy) { 
		for (int i = 0; i < 4; i++) {
			koef[i] = copy.koef[i];
		};
	}

	~Poly3() {}

	double sum() const {
		double sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += koef[i];
		};
		return sum;
	}

	const Poly3& operator = (const Poly3& other) const {
		cout << "Полином, которому присваиваются другие коэф, явл константным!" << endl;
		return *this;
	}

	Poly3& operator = (const Poly3& other) {
		for (int i = 0; i < 4; i++) {
			koef[i] = other.koef[i];
		};
		return *this;
	}

	const Poly3& operator += (const Poly3& other) const {
		cout << "Полином, которому присваиваются его коэф - коэф другого, явл константным!" << endl;
		return *this;
	}

	Poly3& operator += (const Poly3& other) {
		for (int i = 0; i < 4; i++) {
			koef[i] += other.koef[i];
		};
		return *this;
	}

	Poly3 operator + (const Poly3& other) const {
		Poly3 temp;
		for (int i = 0; i < 4; i++) {
			temp.koef[i] = koef[i] + other.koef[i];
		};
		return temp;
	}

	const Poly3& operator -= (const Poly3& other) const {
		cout << "Полином, которому присваиваются его коэф - коэф другого, явл константным!" << endl;
		return *this;
	}

	Poly3& operator -= (const Poly3& other) {
		for (int i = 0; i < 4; i++) {
			koef[i] -= other.koef[i];
		};
		return *this;
	}

	Poly3 operator - (const Poly3& other) const {
		Poly3 temp;
		for (int i = 0; i < 4; i++) {
			temp.koef[i] = koef[i] - other.koef[i];
		};
		return temp;
	}

	Poly3 operator * (const Poly3& other) const {
		Poly3 temp;
		for (int i = 0; i < 4; i++) {
			temp.koef[i] = koef[i] * other.koef[i];
		};
		return temp;
	}

	Poly3 operator / (const Poly3& other) const {
		Poly3 temp;
		for (int i = 0; i < 4; i++) {
			if (other.koef[i] != 0) {
				temp.koef[i] = koef[i] / other.koef[i];
			}
			else {
				temp.koef[i] = koef[i];
			}
		};
		return temp;
	}

	friend ostream& operator << (ostream& os, const Poly3& other) {
		for (int i = 0; i < 2; i++) {
			os << other.koef[i] << "*(x^" << 3 - i << ") + ";
		};
		os << other.koef[2] << "*x + " << other.koef[3];
		return os;
	}
};
