#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
   
    sort(heights.begin(), heights.end());
    int gema_difficulty = 0;
    for (int i = 1; i < N; i++) {
        gema_difficulty = max(gema_difficulty, heights[i] - heights[i-1]);
    }
    
   
    int astik_difficulty = *max_element(heights.begin(), heights.end()) - *min_element(heights.begin(), heights.end());
    
    cout << gema_difficulty << '\n' << astik_difficulty << '\n';
    
    return 0;
}