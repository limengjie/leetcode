#include <iostream>

struct car {
	char make[20];
	int year;
};

int main() {
	using namespace std;
	//cout << "how many cars?\n";
	//int number;
	//cin >> number;
	car * ps = new car[20];
	cout << "please enter the make: ";
	cin.getline(ps[0].make, 20);
	cout << "please enter the year: ";
	cin >> ps[0].year;

	return 0;
}
