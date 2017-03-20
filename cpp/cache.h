#ifndef __LRU_CACHE__
#define __LRU_CACHE__

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
	private:
		struct CacheEntry {
			int _key;
			int _value;
			CacheEntry(int k, int v) : _key(k), _value(v) {}
		};
		list <CacheEntry> cacheList;
		unordered_map<int, list<CacheEntry>::iterator> cacheMap;
		int _capacity;
	public:
		LRUCache(int capacity);
		int get(int key);
		void set(int key, int value);
		void show() const;
};

class LFUCache {
	private:
		struct CacheEntry {
			int _key;
			int _value;
			CacheEntry(int k, int v) : _key(k), _value(v) {}
		};
		list <CacheEntry> cacheList;
		unordered_map<int, list<CacheEntry>::iterator> cacheMap;
		int _capacity;
	public:
		LFUCache(int capacity);
		int get(int key);
		void put(int key, int value);
		void show() const;
};
#endif
