#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &tin,
             vector<int> &low, vector<vector<int>> &bridges)
    {

        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto neighbour : adj[node])
        {
            if (neighbour == parent)
                continue;

            if (!visited[neighbour])
            {
                dfs(neighbour, node, adj, visited, tin, low, bridges);
                low[node] = min(low[node], low[neighbour]);
                // checking the bridge
                if (low[neighbour] > tin[node])
                {
                    bridges.push_back({neighbour, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[neighbour]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto x : connections)
        {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges; // storing ans

        dfs(0, -1, adj, visited, tin, low, bridges);
        return bridges;
    }
};

int main()
{
    Solution solution;
    int n = 5;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    vector<vector<int>> criticalConnections = solution.criticalConnections(n, connections);

    cout << "Critical connections are:" << endl;
    for (const auto &bridge : criticalConnections)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    return 0;
}
