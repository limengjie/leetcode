#ifndef __PQ__
#define __PQ__

template <typename T>
class PQ {
	private:
		T * _queue;
		int _len;
		int _cur_pos = 0;
	public:
		//PQ();
		PQ(T * array, int n);
		bool isEmpty();
		int size();
		void insert(T key);
		T delMax();
		void swim(int pos);
		void sink(int pos);
		void exchange(int p0, int p1);
		void show() const;
			
};
		

#endif
