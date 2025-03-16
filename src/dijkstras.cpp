#include "dijkstras.h"
#include <algorithm>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int vertices = G.numVertices;
    vector<int> distances(vertices, INF);
    vector<bool> visited(vertices, false);
    distances[source] = 0;
    previous[source] = -1; // Undefined = -1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //pair<vertex, weight>
    minHeap.push(make_pair(source, 0));
    while (!minHeap.empty()) {
        int u = minHeap.top().second; // stored in a set [index, value]
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (const Edge &edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push(make_pair(v, distances[v]));
            }
        }
    }
    return distances;
};
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int current = destination; current != -1; current = previous[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());
    return path;
};
void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cout << "No path found" << endl;
        return;
    }
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << "\nTotal Cost: " << total << endl;
};

