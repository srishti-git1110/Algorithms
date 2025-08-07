// Breadth-first search algorithm for a graph
#include <vector>
#include <queue>
#include <iostream>

class Bfs {
    public:
        std::vector<int> bfs(int V, int start_node, std::vector<int> adj[]) {
            std::vector<int> vis(V+1, 0);
            vis[0] = 1; // 0 based indexing
            vis[start_node] = 1;
            std::queue<int> q;
            q.push(start_node);
            std::vector<int> bfsTraversal;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfsTraversal.push_back(node);

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfsTraversal; 
        }
};

int main() {
    int V = 5, start_node = 1;
    std::vector<int> adj[V+1];
    
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[3].push_back(1);
    adj[4].push_back(3);
    adj[4].push_back(2);
    adj[4].push_back(1);
    adj[5].push_back(3);

    Bfs bfs;
    std::vector<int> result = bfs.bfs(V, start_node, adj);

    std::cout << "BFS Traversal from node " << start_node << ": ";
    for (int node : result) {
        std::cout << node << " ";
    }   
    return 0;
}