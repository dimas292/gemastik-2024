#include <iostream>

using namespace std;

long long myMin(long long a, long long b) {
    return (a < b) ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    
    long long days = 0, daily = 0;
    while (A + B + C + D > 0) {
        if (A > 0) {
            A -= min(3LL - daily, A);
        }
        if (B > 0) {
            B -= min(3LL - daily, B);
        }
        if (C > 0 && (daily < 3 || D == 0)) {
            C -= min(3LL - daily, C);
        }
        if (D > 0 && (daily < 3 || C == 0)) {
            D -= min(3LL - daily, D);
        }
        daily = (daily + 1) % 3;
        days++;
    }
    
   
    
    return 0;
}
