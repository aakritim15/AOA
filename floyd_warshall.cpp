#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> path(n, vector<int>(n)); // Initialize the path matrix

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
               if(graph[i][k] + graph[k][j] < graph[i][j]) {
                   path[i][j] = k + 1;
                   graph[i][j] = graph[i][k] + graph[k][j];
               }
            }
        }
    }
    
    cout << "Distance Matrix:" << "\n" << "\n";
    for(auto &i: graph) {
        for(auto &j: i) cout << j << " ";
        cout << "\n";
    }

    cout << endl << "Path Matrix:" << "\n" << "\n";
    for(auto &i: path) {
        for(auto &j: i) cout << j << " ";
        cout << "\n";
    }

    cout << endl << "Intermediate Path:" << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] != 999) {
                cout << "Intermediate vertices from: " << i + 1 << " to " << j + 1<< ": ";
                int x = path[i][j];
                while(x != 0) {
                    cout << x << " ";
                    x = path[x-1][j];
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int> (n)), path(n, vector<int> (n));
    cout << "Enter the adjacency matrix (use 999 for absent edges):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph);

    return 0;
}
