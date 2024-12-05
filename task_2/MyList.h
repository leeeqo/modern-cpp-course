//Задание 2, Першин Александр, 335 группа

#pragma once
#include <string>
#include <memory>

using namespace std;

template <typename T>
class MyList {
private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->pNext = pNext;
			this->pPrev = pPrev;
			this->data = data;
		}
	};

	int Size;
	Node<T>* head;
	Node<T>* tail;
public:
	MyList();
	MyList(const MyList<T>& other);
	~MyList();
	int size();
	void resize(int newSize, T Data = T());
	void reverse();
	void insert(int index, T data, int num = 1);
	void erase(int index);
	void erase(int index_first, int index_last);
	void unique();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void clear();
	void nullptr_check();

	T& operator[](const int index);
};

template <typename T>
MyList<T>::MyList() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
MyList<T>::MyList(const MyList<T>& other) {
	this->Size = other.Size;
	this->head = new Node<T>(other.head->data);

	Node<T>* current = this->head;
	Node<T>* other_current = other.head;

	current->pPrev = nullptr;
	while (other_current->pNext != nullptr) {
		current->pNext = new Node<T>((other_current->pNext)->data);
		(current->pNext)->pPrev = current;
		current = current->pNext;
		other_current = other_current->pNext;
	}
	current->pNext = nullptr;
	this->tail = current;
}

template <typename T>
MyList<T>::~MyList() {
	clear();
}

template<typename T>
int MyList<T>::size() {
	return Size;
}

template<typename T>
void MyList<T>::resize(int newSize, T Data) {
	const int temp = Size - newSize;
	if (temp > 0) {
		for (int i = 0; i < temp; i++) {
			pop_back();
		}
	}
	if (temp < 0) {
		for (int i = 0; i < -temp; i++) {
			push_back(Data);
		}
	}
}

template<typename T>
void MyList<T>::reverse() {
	Node<T>* temp = head;
	head = tail;
	tail = temp;
	Node<T>* current = this->tail;
	while (current != nullptr) {
		Node<T>* temp = current->pNext;
		current->pNext = current->pPrev;
		current->pPrev = temp;
		current = temp;
	}
}

template<typename T>
void MyList<T>::insert(int index, T data, int num) {
	if (index == 0 || index == Size) {
		if (index == 0) {
			for (int i = 0; i < num; i++) {
				push_front(data);
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				push_back(data);
			}
		}
	}
	else {
		if (index <= Size / 2) {
			Node<T>* prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->pNext;
			}
			for (int i = 0; i < num; i++) {
				Node<T>* newNode = new Node<T>(data, prev->pNext, prev);
				(newNode->pNext)->pPrev = newNode;
				prev->pNext = newNode;
			}
		}
		if (index > Size / 2) {
			Node<T>* next = this->tail;
			for (int i = 0; i < (Size - index) - 1/*именно -1*/; i++) {
				next = next->pPrev;
			}
			for (int i = 0; i < num; i++) {
				Node<T>* newNode = new Node<T>(data, next, next->pPrev);
				(newNode->pPrev)->pNext = newNode;
				next->pPrev = newNode;
			}
		}
		Size = Size + num;
	}
}

template<typename T>
void MyList<T>::erase(int index) {
	if (index == 0 || index == Size - 1) {
		if (index == 0) {
			pop_front();
		}
		else {
			pop_back();
		}
	}
	else {
		if (index <= Size / 2) { //C НАЧАЛА СПИСКА
			Node<T>* prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->pNext;
			}
			Node<T>* toDelete = prev->pNext;
			prev->pNext = toDelete->pNext;
			(prev->pNext)->pPrev = prev;
			delete toDelete;
		}
		if (index > Size / 2) { //С КОНЦА
			Node<T>* prev = this->tail;
			for (int i = 0; i < (Size - index) - 2/*именно -2*/; i++) {
				prev = prev->pPrev;
			}
			Node<T>* toDelete = prev->pPrev;
			prev->pPrev = toDelete->pPrev;
			(prev->pPrev)->pNext = prev;
			delete toDelete;
		}
		Size--;
	}
}

template<typename T>
void MyList<T>::erase(int index_first, int index_last) {
	if (index_first == 0 || index_last == Size) {
		if (index_first == 0) {
			for (int i = 0; i < index_last - index_first; i++) {
				pop_front();
			}
		}
		else {
			for (int i = 0; i < index_last - index_first; i++) {
				pop_back();
			}
		}
	}
	else {
		if (index_first <= Size / 2) { //C НАЧАЛА
			Node<T>* prev = this->head;
			for (int i = 0; i < index_first - 1; i++) {
				prev = prev->pNext;
			}
			for (int i = 0; i < index_last - index_first; i++) {
				Node<T>* toDelete = prev->pNext;
				prev->pNext = toDelete->pNext;
				(prev->pNext)->pPrev = prev;
				delete toDelete;
			}
		}
		if (index_first > Size / 2) { //С КОНЦА
			Node<T>* prev = this->tail;
			for (int i = 0; i < (Size - index_last) - 2/*именно -2*/; i++) {
				prev = prev->pPrev;
			}
			for (int i = 0; i < index_last - index_first; i++) {
				Node<T>* toDelete = prev->pPrev;
				prev->pPrev = toDelete->pPrev;
				(prev->pPrev)->pNext = prev;
				delete toDelete;
			}
		}
		Size = Size - (index_last - index_first);
	}
}

template<typename T>
void MyList<T>::unique() {
	int counter = 1;
	Node<T>* current = this->head;
	while (current->pNext != nullptr) {
		while (true) {
			if (current->data == (current->pNext)->data) {
				erase(counter);
				if (counter == Size) {
					break;
				}
			}
			else {
				current = current->pNext;
				counter++;
				break;
			}
		}
	}
}

template<typename T>
void MyList<T>::push_back(T data) {
	if (tail == nullptr) {
		tail = head = new Node<T>(data);
	}
	else {
		tail = tail->pNext = new Node<T>(data, nullptr, tail);
	}
	Size++;
}

template<typename T>
void MyList<T>::push_front(T data) {
	if (head == nullptr) {
		head = tail = new Node<T>(data);
	}
	else {
		head = head->pPrev = new Node<T>(data, head, nullptr);
	}
	Size++;
}

template<typename T>
void MyList<T>::pop_front() {
	if (head->pNext != nullptr) {
		Node<T>* temp = head;
		(head->pNext)->pPrev = nullptr;
		head = head->pNext;
		delete temp;
	}
	else {
		delete head;
		head = tail = nullptr;
	}
	Size--;
}

template<typename T>
void MyList<T>::pop_back() {
	if (tail->pPrev != nullptr) {
		Node<T>* temp = tail;
		(tail->pPrev)->pNext = nullptr;
		tail = tail->pPrev;
		delete temp;
	}
	else {
		delete tail;
		tail = head = nullptr;
	}
	Size--;
}

template<typename T>
void MyList<T>::clear() {
	while (Size) {
		pop_front();
	}
}

template<typename T>
void MyList<T>::nullptr_check() {
	cout << "Head: " << head->pPrev << " ; Tail:" << tail->pNext;
}

template<typename T>
T& MyList<T>::operator[](const int index) {
	int counter = 0;
	if (index <= Size / 2) {
		Node<T>* current = this->head;
		while (true) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else {
		counter = Size - 1;
		Node<T>* current = this->tail;
		while (true) {
			if (counter == index) {
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}