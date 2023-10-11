#include <iostream>
#include <list>
#include <vector>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void dfs(int v);

private:
    int vertices;
    std::vector<std::list<int>> adj;
    void dfsUtil(int v, std::vector<bool>& visited);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::dfs(int v) {
    std::vector<bool> visited(vertices, false);
    dfsUtil(v, visited);
}

void Graph::dfsUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (const auto& neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited);
        }
    }
}

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);

    std::cout << "Depth-First Traversal (starting from vertex 0):" << std::endl;
    graph.dfs(0);

    return 0;
}
