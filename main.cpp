#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, vector<int>& prices, bool cooldown = false) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    
    vector<vector<vector<int>>> dp(
        n + 2,
        vector<vector<int>>(2, vector<int>(k + 1, 0))
    );

    for (int day = n - 1; day >= 0; day--) {
        for (int tx = 0; tx <= k; tx++) {

            
            int buy  = -prices[day] + dp[day + 1][0][tx];
            int skip =                dp[day + 1][1][tx];
            dp[day][1][tx] = max(buy, skip);

            
            if (tx == 0) {
                dp[day][0][tx] = dp[day + 1][0][tx];
            } else {
                int nextFree  = cooldown ? day + 2 : day + 1;
                int afterSell = (nextFree <= n)
                    ? dp[nextFree][1][tx - 1] : 0;
                int sell = prices[day] + afterSell;
                int hold = dp[day + 1][0][tx];
                dp[day][0][tx] = max(sell, hold);
            }
        }
    }
    return dp[0][1][k];
}

int main() {
    int n, k;
    
    cout << "Enter number of days: ";
    cin >> n;
    
    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    cout << "Enter max transactions (k): ";
    cin >> k;
    
    cout << "\nMax profit (no cooldown): $" << maxProfit(k, prices) << "\n";
    cout << "Max profit (with cooldown): $" << maxProfit(k, prices, true) << "\n";
    
    return 0;
}