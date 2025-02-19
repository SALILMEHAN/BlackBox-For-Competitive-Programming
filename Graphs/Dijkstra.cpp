int minDistance(vector<int>& dist, bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < dist.size(); v++) if (sptSet[v] == false && dist[v] <= min) min = dist[v], min_index = v;
    return min_index;
}
vector<int> dijkstra(vector<vector<int>>& graph, int src)
{
    int V=graph.size();
    vector<int> dist(V);
    bool sptSet[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for(int v = 0; v < V; v++) if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
    }
    return dist;
}

//Argument: graph --->> adjacency matrix
//Argument: src --->> source node
