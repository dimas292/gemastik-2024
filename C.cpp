#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, set<int>& component) {
    visited[node] = true;
    component.insert(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }

    vector<bool> visited(N + 1, false);
    int vehicles = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            set<int> component;
            dfs(i, graph, visited, component);
            vehicles = max(vehicles, (int)component.size());
        }
    }

    cout << vehicles << endl;

    return 0;
}