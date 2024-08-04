#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> B(N), J(N);
    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> J[i];
    }
    
    vector<int> maxSellAfter(N);
    maxSellAfter[N-1] = J[N-1];
    for (int i = N-2; i >= 0; i--) {
        maxSellAfter[i] = max(J[i], maxSellAfter[i+1]);
    }
    
    int maxProfit = 0;
    int minBuy = INT_MAX;
    
    for (int i = 0; i < N - 2; i++) {
        minBuy = min(minBuy, B[i]);
        if (i + 2 < N && maxSellAfter[i+2] > minBuy) {
            maxProfit = max(maxProfit, maxSellAfter[i+2] - minBuy);
        }
    }
    
    if (maxProfit > 0) {
        cout << maxProfit << '\n';
    } else {
        cout << "tidak mungkin\n";
    }
    
    return 0;
}