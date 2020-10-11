//count primes
#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
	if (n < 2)
		return 0;

	vector<int> primes;
	//initialize vec
	primes.push_back(2);
	for (int i = 3; i < n; ++i) {
		int j = 0;
		bool isPrime = true;
		//if a num can't be divided by half of itself
		//it can't be divided by other primes
		while (primes[j] <= i / 2) {
			//chekc if i can be divided by a prime number
			if (i % primes[j] == 0) {
				isPrime = false;
				break;
			}
			++j;
		}
		if (isPrime) 
			primes.push_back(i);
	}

	//show the results
	for (size_t i = 0; i < primes.size(); ++i) {
		cout << primes[i] << " ";
	}
	cout << endl;

	return (int)primes.size();
}

int main() {
	int n = 100;

	int res = countPrimes(n);

	cout << "res = " << res << endl;

	return 0;
}
	






