#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long L;
    cin >> N >> L;
    
    deque<long long> lumpia;
    lumpia.push_back(L);
    
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B;
        B--;  
        
       
        long long bagian = lumpia[B];
        
       
        lumpia.erase(lumpia.begin() + B);
        
       
        lumpia.insert(lumpia.begin() + B, bagian / 2);
        lumpia.insert(lumpia.begin() + B, bagian / 2);
    }
    
    for (long long bagian : lumpia) {
        cout << bagian << " ";
    }
    cout << '\n';
    
    return 0;
}
