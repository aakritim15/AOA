#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int s, destination, w;
};
vector<int> bellmanFord(vector<Edge> edges, int v, int s) {
    vector<int> d(v, numeric_limits<int>::max());
    d[s] = 0;
    for (int i = 0; i < v - 1; ++i) {
        for (const auto& edge : edges) {
            if (d[edge.s] != numeric_limits<int>::max() && 
                d[edge.s] + edge.w < d[edge.destination]) {
                d[edge.destination] = d[edge.s] + edge.w;
            }
        }
    }
    for (const auto& edge : edges) {
        if (d[edge.s] != numeric_limits<int>::max() && 
            d[edge.s] + edge.w < d[edge.destination]) {
            cout << "Graph contains a negative cycle" << endl;
            return vector<int>();
        }
    }

    return d;
}

int main() {
    int v, e, s;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    cout << "Enter edges in the format 'source destination weight': " << endl;
    for (int i = 0; i < e; ++i) {
        cin >> edges[i].s >> edges[i].destination >> edges[i].w;
    }

    cout << "Enter the source vertex: ";
    cin >> s ;

    vector<int> distances = bellmanFord(edges, v, s);

    if (!distances.empty()) {
        cout << "Shortest distances from source vertex " << s << ":" << endl;
        for (int i = 0; i < v; ++i) {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}
