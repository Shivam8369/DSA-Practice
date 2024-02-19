#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

class Graph
{
private:
    int numNodes;                  // Number of nodes in the graph
    int numEdges;                  // Number of edges in the graph
    map<int, vector<int>> adjList; // Adjacency list representation using map

public:
    // Constructor to initialize the graph with the given number of nodes
    Graph(int nodes, int edges) : numNodes(nodes), numEdges(edges) {}

    // Function to add an edge between two nodes in the graph
    void createGraph()
    {

        for (int i = 0; i < numEdges; i++)
        {
            int u, v;
            cout << "Enter the edges: ";
            cin >> u >> v;

            addEdge(u, v);
        }
    }
    void addEdge(int u, int v)
    {

        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Function to perform BFS traversal starting from the given source node
    void bfs(int start)
    {

        map<int, bool> visited;
        for (auto i : adjList)
            visited[i.first] = false;

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfs(int start)
    {
        map<int, bool> visited;
        for (auto i : adjList)
            visited[i.first] = false;

        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int current = s.top();
            cout << current << " ";
            s.pop();

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(nodes, edges); // Creating a graph with 4 nodes and 5 edges
    graph.createGraph();

    int startNode; // Starting node for BFS traversal
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    graph.bfs(startNode);
    cout << endl;

    cout << "DFS traversal starting from node " << startNode << ": ";
    graph.dfs(startNode);
    cout << endl;

    return 0;
}
