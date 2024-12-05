// Задание 7, Першин, 335 группа

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <new>
#include <algorithm>

using namespace std;

template<typename T, typename Container = vector<T>, typename Compare = less<T>>                //typename Container::value_type>>
class Priority_queue {
private:
	Container data;
	Compare comp;
public:
	Priority_queue();
	Priority_queue(Container data);
	Priority_queue(const Priority_queue& other);
	~Priority_queue();
	Priority_queue<T>& operator=(const Priority_queue& other);

	void Push(T item);
	void Pop();
	T& Top();

	int size() { return data.size(); }
	Container& Get_container();
};

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>::Priority_queue() : data(), comp() {}

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>::Priority_queue(Container in_data) : data(in_data), comp() {
	stable_sort(data.begin(), data.end(), comp);
}

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>::Priority_queue(const Priority_queue& other) : data(other.data), comp(other.comp) {}

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>::~Priority_queue() {
	data.clear();
}

template<typename T, typename Container, typename Compare>
Priority_queue<T>& Priority_queue<T, Container, Compare>::operator=(const Priority_queue& other) {
	data = other.data;
	comp = other.comp;
	return *this;
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::Push(T item) {
	data.push_back(item);
	stable_sort(data.begin(), data.end(), comp);
}


template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::Pop() {
	data.erase(data.begin());
}

template<typename T, typename Container, typename Compare>
T& Priority_queue<T, Container, Compare>::Top() {
	return *data.begin();
}

template<typename T, typename Container, typename Compare>
Container& Priority_queue<T, Container, Compare>::Get_container() {
	return data;
}


template<typename T>       
class Priority_queue<set<T>> {
private:
	set<T> data;
public:
	Priority_queue() : data() {};
	Priority_queue(set<T> in_data) : data(in_data) {};
	Priority_queue(const Priority_queue& other) { data = other.data; };
	~Priority_queue() { data.erase(data.begin(), data.end()); };
	
	Priority_queue& operator=(const Priority_queue& other) {
		data = other.data;
		return *this;
	};

	void Push(T item) { data.insert(item); };
	void Pop() { data.erase(data.begin()); };
	T& Top() {
		T item = *data.begin();
		return item; 
	};

	int size() { return data.size(); }
	set<T>& Get_container() { return data; };
};

template<typename T>
class Priority_queue<multiset<T>> {
private:
	multiset<T> data;
public:
	Priority_queue() : data() {};
	Priority_queue(multiset<T> in_data) : data(in_data) {};
	Priority_queue(const Priority_queue& other) { data = other.data; };
	~Priority_queue() { data.erase(data.begin(), data.end()); };
	
	Priority_queue& operator=(const Priority_queue& other) {
		data = other.data;
		return *this;
	};

	void Push(T item) { data.insert(item); };
	void Pop() { data.erase(data.begin()); };
	T& Top() {
		T item = *data.begin();
		return item;
	};

	int size() { return data.size(); }
	multiset<T>& Get_container() { return data; };
};

template<typename T1, typename T2>
class Priority_queue<map<T1, T2>> {
private:
	map<T1, T2> data;
public:
	Priority_queue() : data() {};
	Priority_queue(map<T1, T2> in_data) : data(in_data) {};
	Priority_queue(const Priority_queue& other) { data = other.data; };
	~Priority_queue() { data.erase(data.begin(), data.end()); };

	Priority_queue<map<T1, T2>>& operator=(const Priority_queue& other) {
		data = other.data;
		return *this;
	};

	void Push(T1 key, T2 item) { data.insert(make_pair(key, item)); };
	void Pop() { data.erase(data.begin()); };
	T2 Top() {
		T2 item = data.begin()->second;
		return item;
	};

	int size() { return data.size(); }
	map<T1, T2>& Get_container() { return data; };
};

template<typename T1, typename T2>
class Priority_queue<multimap<T1, T2>> {
private:
	multimap<T1, T2> data;
public:
	Priority_queue() : data() {};
	Priority_queue(multimap<T1, T2> in_data) : data(in_data) {};
	Priority_queue(const Priority_queue& other) { data = other.data; };
	~Priority_queue() { data.erase(data.begin(), data.end()); };

	Priority_queue<multimap<T1, T2>>& operator=(const Priority_queue& other) {
		data = other.data;
		return *this;
	};

	void Push(T1 key, T2 item) { data.insert(make_pair(key, item)); };
	void Pop() { data.erase(data.begin()); };
	T2 Top() {
		T2 item = data.begin()->second;
		return item;
	};

	int size() { return data.size(); }
	multimap<T1, T2>& Get_container() { return data; };
};



