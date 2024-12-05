// Çàäàíèå 7, Ïåðøèí, 335 ãðóïïà

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <new>
#include <algorithm>
#include "Priority_queue.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	// ÏÐÎÂÅÐÊÀ ÄËß VECTOR, DEQUE, LIST

	Priority_queue<int, vector<int>> P_vec;
	P_vec.Push(4);
	P_vec.Push(66);
	P_vec.Push(30);
	P_vec.Push(888);
	P_vec.Push(9);
	P_vec.Push(888);

	int P_vec_size = P_vec.size();
	for (int i = 0; i < P_vec_size; i++) {
		cout << P_vec.Top() << ' ';
		P_vec.Pop();
	}

	cout << endl << endl;

	Priority_queue<double, deque<double>> P_deque;
	P_deque.Push(4);
	P_deque.Push(66);
	P_deque.Push(30.9);
	P_deque.Push(888.89209);
	P_deque.Push(9);
	P_deque.Push(888.389);

	int P_deque_size = P_deque.size();
	for (int i = 0; i < P_deque_size; i++) {
		cout << P_deque.Top() << ' ';
		P_deque.Pop();
	}

	cout << endl << endl;

	Priority_queue<string, list<string>> P_list;
	P_list.Push("Australia");
	P_list.Push("Russia");
	P_list.Push("Germany");
	P_list.Push("Zanzibar");

	int P_list_size = P_list.size();
	for (int i = 0; i < P_list_size; i++) {
		cout << P_list.Top() << ' ';
		P_list.Pop();
	}

	cout << endl << endl;

	// ÏÐÎÂÅÐÊÀ ÄËß SET
	/*
	set<int> Set = { 4, 66, 30, 888, 9 };
	
	Priority_queue<set<int>> P_set;
	P_set.Push(4);
	P_set.Push(66);
	P_set.Push(30);
	P_set.Push(888);
	P_set.Push(9);

	int P_size = P_set.size();
	for (int i = 0; i < P_size; i++) {
		cout << P_set.Top() << ' ';
		P_set.Pop();
	}

	cout << endl << endl;*/

	// ÏÐÎÂÅÐÊÀ ÄËß MULTISET
	/*
	multiset<double> Set = { 4, 66, 30, 888, 9, 888, 30 };

	Priority_queue<multiset<double>> P_set;
	P_set.Push(4.4);
	P_set.Push(66);
	P_set.Push(30);
	P_set.Push(888.909);
	P_set.Push(9.5);
	P_set.Push(888.909);
	P_set.Push(30);

	int P_size = P_set.size();
	for (int i = 0; i < P_size; i++) {
		cout << P_set.Top() << ' ';
		P_set.Pop();
	}
	
	cout << endl << endl;*/

	//ÏÐÎÂÅÐÊÀ ÄËß MAP
	/*
	map<int, string> Map = { {4, "letter"}, {30, "word"}, {888, "sentence"} };

	Priority_queue<map<int, string>> P_set;
	P_set.Push(4, "letter");
	P_set.Push(30, "word");
	P_set.Push(888, "sentence");
	
	int P_size = P_set.size();
	for (int i = 0; i < P_size; i++) {
		cout << P_set.Top() << ' ';
		P_set.Pop();
	}*/

	//ÏÐÎÂÅÐÊÀ ÄËß MULTIMAP
	/*
	multimap<int, string> Map = { {30, "word"}, {4, "letter"}, {30, "word"}, {888, "sentence"}};

	Priority_queue<multimap<int, string>> P_set;
	P_set.Push(4, "letter");
	P_set.Push(30, "word");
	P_set.Push(888, "sentence");
	P_set.Push(30, "word");
	P_set.Push(4, "letter");

	int P_size = P_set.size();
	for (int i = 0; i < P_size; i++) {
		cout << P_set.Top() << ' ';
		P_set.Pop();
	}*/

	return 0;
}


