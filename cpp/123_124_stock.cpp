//best time to buy and sell stock
#include <iostream>
#include <vector>
#include <algorithm> //max()

using namespace std;

////buy and sell once
////traverse the vector in order and
////find the largest difference
//int stock(vector<int> price) {
        //if (price.empty())
                //return -1;

        //int maxDiff = 0;
        //int cur_min = price[0];
        //for (size_t i  = 1; i < price.size(); ++i) {
                //maxDiff = max(maxDiff, price[i] - cur_min);
                //cur_min = min(cur_min, price[i]);
        //}

        //return maxDiff;
//}

//buy and sell for multiple times
//add all the positive differences together
int stock(vector<int> price) {
        if (price.empty())
                return -1;

        int tot_profit = 0;
        int profit;
        for (size_t i = 1; i < price.size(); ++i) {
                profit = price[i] - price[i - 1];
                if (profit > 0) {
                        tot_profit += profit;
                }
        }

        return tot_profit;
}



int main() {
        vector<int> price = {5, 9, 1, 4, 7, 6};

        int profit = stock(price);

        cout << "max profit = " << profit << endl;

        return 0;
}





