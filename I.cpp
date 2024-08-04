#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& prices) {
    int n = prices.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (prices[j] > prices[j + 1]) {
                int temp = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = temp;
            }
        }
    }
}

long long calculate_min_cost(const vector<int>& prices, int X) {
    int N = prices.size();
    long long total_cost = 0;
    int i = 0;

    while (i < N) {
        int end = min(i + X, N);
        int min_price = prices[i];
        for (int j = i; j < end; ++j) {
            if (prices[j] < min_price) {
                min_price = prices[j];
            }
        }

        long long sum = 0;
        for (int j = i; j < end; ++j) {
            sum += prices[j];
        }
        sum -= min_price / 2;
        total_cost += sum;

        i = end;
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    bubble_sort(prices);

    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < Q; ++i) {
        int X = queries[i];
        long long min_cost = calculate_min_cost(prices, X);
        cout << min_
