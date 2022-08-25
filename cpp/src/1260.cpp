#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> _edges;
    int _N;
    int _M;
    int _V;
public:
    Graph (int n_ver, int s_ver, vector<vector<int>> edges) 
    : _N(n_ver), _V(s_ver) {
        for (int v = 0; v < edges.size(); v++) {
            for (int u = 0; u < edges[v].size(); u++) {
                edges[u].push_back(edges[v][u]);
            }
        }

    }

    void pushEdge (int u, int v) {
    }

    /* Getter / Setter */
    int getEdgeNum () {
    }

    vector<int> DFS () {
    }
    vector<int> BFS () {
    }
};

int main (void) {
    int N, M, V;
    cin >> N >> M >> V;
    Graph graph(N, M, V);

    for (int v = 0; v < M; v++) {
        int n, m;
        cin >> n >> m;
        graph.pushEdge(n, m)
    }
    return 0;
}
