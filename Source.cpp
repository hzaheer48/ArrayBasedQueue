#include<iostream>
using namespace std;
template<typename T>
class queue {
	int r, f, size;
	T* data;
public:
	queue(int s = 10) {
		size = s + 1;
		r = f = 0;
		data = new T[size];
	}
	~queue() {
		delete[]data;
	}
	void push(const T& val) {
		if (full())
			throw("Queue Overflow!");
		r = (r + 1) % size;
		data[r] = val;
	}
	void pop() {
		if (empty())
			throw("Queue Underflow!");
		f = (f + 1) % size;
	}
	T front() const {
		if (empty())
			throw("Queue is empty!");
		return data[(f + 1) % size];
	}
	bool empty() const {
		return r == f;
	}
	bool full() const {
		return (r + 1) % size == f;
	}
	void make_empty() {
		f = r = 0;
	}
	void operator=(const queue<T>& rhs) {
		delete[] data;
		size = rhs.size;
		r = rhs.r;
		f = rhs.f;
		data = new T[size];
		for (int i = f + 1; i <= r; i++)
			data[i] = rhs.data[i];
	}
	queue(const queue<T>& rhs) {
		size = rhs.size;
		r = rhs.r;
		f = rhs.f;
		data = new T[size];
		for (int i = f + 1; i <= r; i++)
			data[i] = rhs.data[i];
	}
};