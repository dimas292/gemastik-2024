#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

long long combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);  
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}


long long find_number(long long N, int ones) {
    long long result = 0;
    int total_bits = ones + 1;  
    for (int i = total_bits - 1; i >= 0; --i) {
      
        long long count = combination(i, ones - 1);
        if (N > count) {
            N -= count; 
            result |= (1LL << i); 
            --ones;  
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

   
    long long result = find_number(N, 30);
    cout << result << endl;

    return 0;
}
