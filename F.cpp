#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;  // Definisikan infinity yang besar

long long minimum_coins(long long A, long long P, long long Q) {
    if (A == 0) return 0;
    
    unordered_map<long long, long long> dp;
    queue<long long> q;
    
    dp[A] = 0;
    q.push(A);
    
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        long long current_cost = dp[current];
        
        // Gunakan senapan peluru (biaya 1 koin)
        if (current > 0 && dp.find(current - 1) == dp.end()) {
            dp[current - 1] = current_cost + 1;
            q.push(current - 1);
        }
        
        // Gunakan bom kecil (biaya P koin), hanya jika jumlah tentara genap
        if (current % 2 == 0) {
            long long half = current / 2;
            if (dp.find(half) == dp.end()) {
                dp[half] = current_cost + P;
                q.push(half);
            }
        }
        
        // Gunakan bom besar (biaya Q koin), hanya jika jumlah tentara dapat dibagi tiga
        if (current % 3 == 0) {
            long long third = current / 3;
            if (dp.find(third) == dp.end()) {
                dp[third] = current_cost + Q;
                q.push(third);
            }
        }
    }
    
    // Mengembalikan biaya minimum untuk mengalahkan semua tentara, jika ada
    return dp.count(0) ? dp[0] : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long P, Q;
    cin >> N >> P >> Q;
    
    vector<long long> results(N);
    for (int i = 0; i < N; ++i) {
        long long Ai;
        cin >> Ai;
        long long min_coins = minimum_coins(Ai, P, Q);
        results[i] = (min_coins == -1) ? 0 : min_coins;
    }
    
    for (long long result : results) {
        cout << result << endl;
    }
    
    return 0;
}
