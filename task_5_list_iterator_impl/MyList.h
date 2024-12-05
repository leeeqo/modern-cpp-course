//Задание 5, Першин Александр, 335 группа

#pragma once

using namespace std;

template <typename T>
class MyList {
private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->pNext = pNext;
			this->data = data;
		}
	};

	int Size;
	Node<T>* head;
public:
	class forward_iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = value_type*;
		using reference = value_type&;

		Node<T>* ptr;

		forward_iterator() : ptr(nullptr) {}
		forward_iterator(Node<T>* ptr) : ptr(ptr) {}
		forward_iterator(forward_iterator const& other) : ptr(other.ptr) {}

		forward_iterator& operator= (const forward_iterator& other) {
			ptr = other.ptr;
			return *this;
		}

		forward_iterator operator++ (int) {
			ptr = ptr->pNext;
			return this;
		}

		forward_iterator& operator++ () {
			forward_iterator temp(ptr);
			ptr = ptr->pNext;
			return temp;
		}

		bool operator== (const forward_iterator& it) { return it.ptr == this->ptr; }
		bool operator!= (const forward_iterator& it) { return it.ptr != this->ptr; }
		T& operator* () const { return ptr->data; }
		Node<T>* operator-> () const { return ptr; }
	};

	MyList();
	MyList(const MyList<T>& other);
	~MyList();
	int size();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void nullptr_check();

	T& operator[](const int index);

	forward_iterator begin() { return head; };
	forward_iterator end() {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		return current->pNext;
	};
};

template <typename T>
MyList<T>::MyList() {
	Size = 0;
	head = nullptr;
}

template<typename T>
MyList<T>::MyList(const MyList<T>& other) {
	this->Size = other.Size;
	this->head = new Node<T>(other.head->data);

	Node<T>* current = this->head;
	Node<T>* other_current = other.head;

	while (other_current->pNext != nullptr) {
		current->pNext = new Node<T>((other_current->pNext)->data);
		current = current->pNext;
		other_current = other_current->pNext;
	}
	current->pNext = nullptr;
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
void MyList<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void MyList<T>::push_front(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		head = new Node<T>(data, head);
	}
	Size++;
}

template<typename T>
void MyList<T>::pop_front() {
	if (head->pNext != nullptr) {
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
	}
	else {
		delete head;
		head = nullptr;
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
	Node<T>* current = this->head;
	while (current->pNext != nullptr) {
		current = current->pNext;
	}
	cout << "End: " << current->pNext; 
}

template<typename T>
T& MyList<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (true) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	} 
}