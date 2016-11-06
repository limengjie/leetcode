#include <iostream>
#include "pQ.h"

template <typename T>
PQ::PQ(T * array, int n) {
        //allocate space in heap
        //for simplicity, store the 1st elt at index 1
        _queue = new((n + 1) * sizeof(T));
        _len = n;
        //copy values
        for (int i = 0; i < n; ++i) {
                insert(array[i]);
        }
}

bool PQ::isEmpty() {
        return cur_pos == 0;
}

template <typename T>
void PQ::insert(T key) {
        if (cur_pos == len + 1) {
                cout << "priority queue is full\n";
                return;
        }

        _queue[++cur_pos] = key;
        swim(cur_pos);
}

template <typename T>
T PQ::delMax() {
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
void PQ::swim(int pos) {
        int k = pos;
        while (k  > 1) {
                if (_queue[k] > _queue[k / 2])
                        exchange(k, k / 2);
                else
                        return;

                k /= 2;
        }
}


template <typename T>
void PQ::sink(int pos) {
        int k = pos;
        int lrg_pos;
        while (2k <= _cur_pos) {
                //get the smaller one
                if (2k + 1 > _cur_pos)
                        lrg_pos = 2k;
                else {
                        if (_queue[2k] >= _queue[2k + 1]) 
                                lrg_pos = 2k;
                        else
                                lrg_pos = 2k + 1;
                }
                if (_queue[k] < _queue[lrg_pos])
                        exchange(k, lrg_pos);
                else
                        return;

                k *= 2;
        }
}

template <typename T>
void PQ::exchange(int p0, int p1) {
        T temp = _queue[p0];
        _queue[p0] = _queue[p1];
        _queue[p1] = temp;
}

template <typename T>
void show() const {
        for (int i = 1; i <= _cur_pos; ++i) 
                cout << _queue[i];
        cout << endl;
}

int main() {
        int array = {1, 9, 8, 7, 2, 5};

        PQ pq(array, 6);

        pq.show();

        return 0;
}
