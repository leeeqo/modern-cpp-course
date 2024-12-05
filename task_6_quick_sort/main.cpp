// Задание 6, Першин, 335 группа

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

/*template<class forward_it, class predicate>
forward_it _partition2(forward_it first, forward_it last, predicate p) {
	first = find_if_not(first, last, p);
	if (first == last) return first;

	//nex = std::next(first);
	for_each(next(first), last, [](const auto& a) {
		if (p(a)) {
			iter_swap(this, first);
			++first;
		};
		}
	);
	return first;
	
	for (forward_it i = next(first); i != last; ++i) {
		if (p(*i)) {
			iter_swap(i, first);
			++first;
		}
	}
	
}*/

/*
template<class forward_it, class reverse_it, class predicate>
forward_it alg_partition(forward_it first, forward_it last, reverse_it rfirst, reverse_it rlast, predicate p) {
	//if (first == last) return first;
	//auto f1 = find_if_not(first, last, p);
	//auto f2 = find_if(rfirst, rlast, p);
	// if (f1 == f2) return f1;
	//cout << "f1 " << *f1 << " ; f2 " << *f2 << endl;
	first = find_if_not(first, last, p);
	last = static_cast<forward_it>(find_if(rfirst, rlast, p));
	if (first == last) return first;
	iter_swap(first, last);
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	alg_partition(first, last, rfirst, rlast, p);
}*/

/*
template<class forward_it, class reverse_it, class predicate>
forward_it alg_partition(forward_it first, forward_it last, reverse_it rfirst, reverse_it rlast, predicate p) {
	first = find_if_not(first, last, p);
	if (first == last) return first;

	//auto fir = first++;
	auto temp = find_if(first, last, p);

	if (temp == last) return first;
	
	iter_swap(first, temp);
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	cout << endl << endl;

	alg_partition(first, last, p);
}*/

/*
template<class forward_it, class reverse_it, class predicate>
forward_it alg_partition(forward_it first, forward_it last, reverse_it rfirst, reverse_it rlast, predicate p) {
	//if (first == last) return first;
	auto f1 = find_if_not(first, last, p);
	auto f2 = find_if(rfirst, rlast, p);
	//if (p(*f1)) return f1;
	if (find_if_not(f1, last, p) == last) return f1;
	cout << endl << *find_if_not(f1, last, p) << endl;
	cout << "f1 " << *f1 << " ; f2 " << *f2 << endl;
	iter_swap(f1, f2);
	cout << "==============" << endl;
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	alg_partition(first, last, rfirst, rlast, p);
}*/

/*
template<class bidir_it, class predicate>
bidir_it alg_partition(bidir_it first, bidir_it last, predicate p) {
	//if (first == last) return first;
	auto f1 = find_if_not(first, last, p);
	auto f2 = find_if(rfirst, rlast, p);
	//if (p(*f1)) return f1;
	if (find_if_not(f1, last, p) == last) return f1;
	cout << endl << *find_if_not(f1, last, p) << endl;
	cout << "f1 " << *f1 << " ; f2 " << *f2 << endl;
	iter_swap(f1, f2);
	cout << "==============" << endl;
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	alg_partition(first, last, rfirst, rlast, p);
}*/

template<class forward_it, class predicate>
forward_it _partition(forward_it first, forward_it last, predicate p) {
	first = find_if_not(first, last, p);
	if (first == last) return first;

	for_each(next(first), last, [p, &first](auto& a) {
		if (p(a)) {
			swap(a, *first);
			++first;
		};
		}
	);

	return first;
}

template<typename forward_it>
void quick_sort(forward_it first, forward_it last) {
	if (first == last) return;
	auto pivot = *next(first, distance(first, last) / 2);

	forward_it p1 = _partition(first, last, [pivot](const auto& a) { return a < pivot; });
	/*cout << endl << "after p1: ";
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	cout << endl << "p1 " << *p1 << endl;*/
	forward_it p2 = _partition(p1, last, [pivot](const auto& a) { return !(pivot < a); });
	/*cout << endl << "after p2: ";
	for (auto it = first; it != last; ++it) {
		cout << *it << ' ';
	}
	cout << endl << "p2" << *p2 << endl;*/

	quick_sort(first, p1);
	quick_sort(p2, last);
}

int main() {
	setlocale(LC_ALL, "Rus");
	
	forward_list<int> list = { 6, 5, 3, 1, 2, 8, 7, 4, 10, 2, 50, 57};
	cout << "Неотсортированный список : " << endl;
	for (int n : list) cout << n << ' ';
	cout << endl;

	quick_sort(list.begin(), list.end());
	cout << "Отсортированный список: " << endl;
	for (int n : list) cout << n << ' ';
	cout << endl;

	/*_partition(list.begin(), list.end(), [](const auto& a) { return a < 7; });
	cout << "_partition: " << endl;
	for (int n: list) cout << n << ' ';
	cout << endl;*/

	/*auto it = list.begin();
	alg_partition(list.begin(), list.end(), [](const auto& a) { return a < 7; });
	cout << "alg_partition: " << endl;
	for (int n : list) cout << n << ' ';
	cout << endl;*/

	/*vector<int> vec = {6, 5, 3, 1, 7, 8, 2, 4, 10, 2, 50, 57};
	cout << "неотсортированный vec: " << endl;
	for (int n : vec) cout << n << ' ';
	cout << endl;*/
	
	/*list<int> l = {6, 5, 3, 1, 7, 8, 2, 4, 10, 2, 50, 57};
	cout << "неотсортированный l: " << endl;
	for (int n : l) cout << n << ' ';
	cout << endl;*/

	/*alg_partition(vec.begin(), vec.end(), vec.rbegin(), vec.rend(), [](const auto& a) { return a < 7; });
	_partition(vec.begin(), vec.end(), [](const auto& a) { return a < 7; });
	cout << "alg_partition: " << endl;
	for (int n : vec) cout << n << ' ';
	cout << endl;*/

	/*alg_partition(vec.begin(), vec.end(), [](const auto& a) { return a < 7; });
	cout << "alg_partition: " << endl;
	for (int n : vec) cout << n << ' ';
	cout << endl;*/

	return 0;
}