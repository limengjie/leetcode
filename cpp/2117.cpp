#include <iostream>
#include <vector>

using namespace std;

class Solution {
        private:
                vector<int> add(vector<int> &digits, int n) {
                        int carry = 0;
                        size_t i = 0;
                        do { 
                                int sum = carry + digits.at(i);
                                if (i == 0) sum += n;
                                carry = sum / 10;
                                digits.at(i) = sum % 10;
                                ++i;
                        } while (carry != 0 and i < digits.size());

                        if (carry != 0) 
                                digits.push_back(carry);

                        return digits;
                }
        public:
                vector<int> plusOne(vector<int> &digits) {
                        add(digits, 1);
                        return digits;
                }

                void printDigits(const vector<int> &digits) {
                        auto rit = digits.crbegin();
                        for (; rit != digits.crend(); ++rit)
                                cout << *rit;
                        cout << endl;
                }
};

int main() {
        Solution solution;

        int array[] = {9, 9, 9, 9};
        vector<int> number(array, array + 4);

        vector<int> ans = solution.plusOne(number);
        cout << "Result:\n";
        solution.printDigits(ans);

        return 0;
}
