#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<long long> minimum_coins_needed(int N, long long P, long long Q, const vector<long long>& A) {
    vector<long long> results;
    
    for (long long Ai : A) {
        if (Ai == 0) {
            results.push_back(0);
            continue;
        }
        
        // Initialize DP table with a large number
        unordered_map<long long, long long> dp;
        queue<long long> q;
        
        dp[Ai] = 0;
        q.push(Ai);
        
        while (!q.empty()) {
            long long current = q.front();
            q.pop();
            long long current_cost = dp[current];
            
            // Use bullet (cost 1 koin)
            if (current > 0 && dp.find(current - 1) == dp.end()) {
                dp[current - 1] = current_cost + 1;
                q.push(current - 1);
            }
            
            // Use small bomb (cost P koin), only if even
            if (current % 2 == 0) {
                long long half = current / 2;
                if (dp.find(half) == dp.end()) {
                    dp[half] = current_cost + P;
                    q.push(half);
                }
            }
            
            // Use big bomb (cost Q koin), only if divisible by 3
            if (current % 3 == 0) {
                long long third = current / 3;
                if (dp.find(third) == dp.end()) {
                    dp[third] = current_cost + Q;
                    q.push(third);
                }
            }
        }
        
        // The result for Ai
        results.push_back(dp[0]);
    }
    
    return results;
}

int main() {
    int N;
    long long P, Q;
    cin >> N >> P >> Q;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> results = minimum_coins_needed(N, P, Q, A);
    
    for (long long result : results) {
        cout << result << endl;
    }
    
    return 0;
}
