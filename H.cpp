#include <iostream>
#include <deque>
#include <unordered_map>
#include <algorithm>  
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    deque<int> stack;
    unordered_map<int, int> position;
    
    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        stack.push_back(card);
        position[card] = i;
    }
    
    for (int i = 0; i < K; i++) {
        char op;
        int X;
        cin >> op >> X;
        
        if (op == 'A') {
            stack.push_front(X);
            for (auto& p : position) {
                p.second++;
            }
            position[X] = 0;
        } else if (op == 'G') {
            int pos = position[X];
            if (pos > 0) {
                rotate(stack.begin(), stack.begin() + pos, stack.end());
                for (size_t j = 0; j < stack.size(); j++) {
                    position[stack[j]] = j;
                }
            }
        }
    }
    
    cout << stack.size() << '\n';
    for (int card : stack) {
        cout << card << ' ';
    }
    cout << '\n';
    
    return 0;
}