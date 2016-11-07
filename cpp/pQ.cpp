#include <iostream>
#include "pQ.h"

using namespace std;

template <typename T>
PQ<T>::PQ(T * array, int n) {
        //allocate space in heap
        //for simplicity, store the 1st elt at index 1
        _queue = new T[n + 1];
        _len = n;
        //copy values
        for (int i = 0; i < n; ++i) {
                insert(array[i]);
//		show();
        }
}

template <typename T>
bool PQ<T>::isEmpty() {
        return _cur_pos == 0;
}

template <typename T>
int PQ<T>::size() {
	return _cur_pos;
}

template <typename T>
void PQ<T>::insert(T key) {
        if (_cur_pos == _len + 1) {
                cout << "priority queue is full\n";
                return;
        }

        _queue[++_cur_pos] = key;
        swim(_cur_pos);
}

template <typename T>
T PQ<T>::delMax() {
        if (isEmpty())
                return T();

        //save the max value and return it later
        T max = _queue[1];
        //replace the max value with last elt
        _queue[1] = _queue[_cur_pos--];
        //move the 1st elt to proper position
        sink(1);

        return max;
}

template <typename T>
void PQ<T>::swim(int pos) {
        int k = pos;
        while (k  > 1) {
                if (_queue[k] > _queue[k / 2]) {
			//exchange
                        exchange(k, k / 2);
//			T temp = _queue[k];
//			_queue[k] = _queue[k / 2];
//			_queue[k / 2] = temp;
		}
                else
                        return;

                k /= 2;
        }
}


template <typename T>
void PQ<T>::sink(int pos) {
        int k = pos;
        int lrg_pos;
        while (k <= _cur_pos / 2) {
                //get the smaller one
                if (k > (_cur_pos - 1) / 2)
                        lrg_pos = 2 * k;
                else {
                        if (_queue[2 * k] >= _queue[2 * k + 1]) 
                                lrg_pos = 2 * k;
                        else
                                lrg_pos = 2 * k + 1;
                }
                if (_queue[k] < _queue[lrg_pos]) {
			//exchange
                        exchange(k, lrg_pos);
		}
                else
                        return;

                k *= 2;
        }
}

template <typename T>
void PQ<T>::exchange(int p0, int p1) {
        T temp = _queue[p0];
        _queue[p0] = _queue[p1];
        _queue[p1] = temp;
}

template <typename T>
void PQ<T>::show() const {
	int k = 2;
        for (int i = 1; i <= _cur_pos; ++i) {
                cout << _queue[i] << " ";
		if (i == k - 1) {
			cout << endl;
			k *= 2;
		}
	}
	if (_cur_pos != k / 2 - 1)
		cout << endl;
}

template class PQ<int>;
template class PQ<string>;
