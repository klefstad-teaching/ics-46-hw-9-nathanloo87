#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int vertices = G.numVertices;
    vector<int> distances(vertices, INF);
    previous.assign(vertices, -1);
    vector<bool> visited(vertices, false);
    distances[source] = 0;
    previous[source] = -1; // Undefined = -1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //pair<vertex, weight>
    minHeap.push({source, 0});
    while (!minHeap.empty()) {
        auto [dist, u] = minHeap.top();
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true
        for (const Edge &edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
};
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
};
void print_path(const vector<int>& v, int total);

