//KMP
#include <iostream>
#include <cstring> //strlen()

using namespace std;

//complete the failure table
void compute_prefix(const char * pattern, int next[]) {
	//i is the position of current char in text,
	//j is the position of current char in pattern
	int i, j = -1;
	const int m = strlen(pattern);

	next[0] = j;
	for (i = 1; i < m; ++i) {
		//fall back
		while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];

		//the substring continues
		if (pattern[i] == pattern[j + 1]) j++;
		next[i] = j;//fill the table
	}
}

//KMP searches for the 1st occurrence of a "word" within a "text"
int kmp(const char * text, const char * pattern) {
	//i is the position of current char in text,
	//j is the position of current char in pattern
	int i, j = -1; 
	const int n = strlen(text);
	const int m = strlen(pattern);
	if (n == 0 && m == 0) return 0;
	if (m == 0) return 0;
	int * next = (int*)malloc(sizeof(int) * m);

	//complete the failure table
	compute_prefix(pattern, next);

	for (i = 0; i < n; ++i) {
		//fall back
		while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
		//substring continues
		if (text[i] == pattern[j + 1]) j++;
		//found the needle
		if (j == m - 1) {
			free(next);
			return i - j;
		}
	}

	free(next);
	return -1;
}

char * myStrStr(const char * haystack, const char * needle) {
	int pos = kmp(haystack, needle);
	if (pos == -1) return nullptr;
	else return (char*)haystack + pos;
}


int main() {
	string hs =  "find a needle in a haystack\n";
	string nd = "needle";

	const char * str = hs.c_str();
	const char * ndl = nd.c_str();

	char * pos = myStrStr(str, ndl);

	if (pos)
		cout << pos;
	else
		cout << "not found\n";

	return 0;
}
