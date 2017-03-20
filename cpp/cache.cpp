#include <iostream>
#include "cache.h"

using namespace std;

LRUCache::LRUCache(int c) : _capacity(c) {}

int LRUCache::get(int k) {
	//list<CacheEntry>::iterator it = cacheMap.find(k);
	//auto it = cacheMap.find(k);
	//if this key exists
	//if (it != cacheMap.end()) {
	if (cacheMap.find(k) != cacheMap.end()) {
		cout << k << " is found\n";

		//move the cahe entry to the first position
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[k]);

		////update the map
		//cacheMap[k] = cacheList.begin();

		return cacheMap[k]->_value;
	}

	cout << "key doesn't exist\n";
	return -1;
}

void LRUCache::set(int k, int v) {
	//auto it = cacheMap.find(k);
	//if this key exists
	if (cacheMap.find(k) != cacheMap.end()) {
		cout << "update " << k << "'s value\n";
		//move the cahe entry to the first position
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[k]);

		//change the value
		cacheMap[k]->_value = v;

		////update the map
		//cacheMap[k] = cacheList.begin();
	}
	else { //key doesn't exist
		cout << "insert a new key: " << k << endl;
		if (cacheList.size() >= _capacity) {
			cout << "cache is full\n";
			//delete the entry in map by the key
			cacheMap.erase(cacheList.back()._key);
			//delete the last entry in list
			cacheList.pop_back();
		}
		//insert the new key-value pair
		//cacheList.insert(cacheList.begin(), CacheEntry(k, v));
		cacheList.push_front(CacheEntry(k, v));
		//update the map
		//cacheMap.insert(make_pair(k, cacheList.begin());
		cacheMap[k] = cacheList.begin();
	}
}
		

void LRUCache::show() const {
	bool first = true;
	for (auto cit = cacheList.begin(); cit != cacheList.end(); ++cit) {
		if (first) {
			cout <<"(" << cit->_key << ", ";
			cout << cit->_value << ")";

			first = false;
		}
		else {
			cout << "->";
			cout <<"(" << cit->_key << ", ";
			cout << cit->_value << ")";
		}
	}
	cout << endl;
}
	

int main() {
	LRUCache cache(2);

	//cache.get(4);
	cache.set(2, 1);
	cache.set(1, 1);
	cache.set(2, 3);
	cache.set(4, 1);
	cache.get(1);
	cache.get(2);
	//cache.set(3, 3);
	//cache.get(2);
	//cache.set(1, 1);
	//cache.get(2);
	//cache.set(4, 44);
	//cache.set(5, 55);

	cache.show();

	return 0;
}
	

