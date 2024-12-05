// Задание 4, Першин Александр, 335 группа

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Shared_ptr {
private:
    T* ptr;
    size_t* counter;
public:
    Shared_ptr();
    Shared_ptr(T* ptr);
    Shared_ptr(Shared_ptr const& other);
    ~Shared_ptr();
    T& operator*() const;
    T* operator->() const;
    size_t use_count() const;
};

template<typename T>
Shared_ptr<T>::Shared_ptr() : ptr(nullptr), counter(nullptr) {}

template<typename T>
Shared_ptr<T>::Shared_ptr(T* ptr) : ptr(ptr), counter(new size_t(1)) {
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr const& other) : ptr(other.ptr), counter(other.counter) {
    ++*counter;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr() {
    if (*counter > 1) {
        --*counter;
        return;
    }
    delete ptr;
    delete counter;
}

template<typename T>
T& Shared_ptr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T* Shared_ptr<T>::operator->() const{
    return ptr;
}

template<typename T>
size_t Shared_ptr<T>::use_count() const {
    return *counter;
}


int main() {
    Shared_ptr<double> sp1(new double(888));
    Shared_ptr<double> sp2(sp1);
    Shared_ptr<double> sp3(sp1);

    cout << *sp3 << endl;
    cout << sp2.use_count() << endl;

    Shared_ptr<string> sp_str(new string("net"));

    cout << *sp_str << endl;
    cout << sp_str.use_count() << endl;

    return 0;
}