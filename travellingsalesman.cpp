#include<bits/stdc++.h>
using namespace std;
int fact(int n) {
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}
int findMinCost(vector<vector<int>>& graph, vector<int>& path) {
    int n = graph.size();
    int minCost = numeric_limits<int>::max();
    
    do {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (graph[path[i]][path[i + 1]] == 0) { 
                cost = numeric_limits<int>::max();
                break;
            }
            cost += graph[path[i]][path[i + 1]];
        }
        if (graph[path[n - 1]][path[0]] == 0) { 
            cost = numeric_limits<int>::max();
        } else {
            cost += graph[path[n - 1]][path[0]];
        }
        minCost = min(minCost, cost);
    } while (next_permutation(path.begin() + 1, path.end()));
    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the distances between cities: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }
    int minCost = findMinCost(graph, path);
    cout << "Minimum cost of traversal: " << minCost << endl;

    return 0;
}
