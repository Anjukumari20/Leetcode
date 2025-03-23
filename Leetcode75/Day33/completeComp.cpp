class Solution {
    public:
        void dfs(int node, unordered_set<int>& visited, vector<vector<int>>& adj, vector<int>& component) {
            visited.insert(node);
            component.push_back(node);
            
            for (int neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    dfs(neighbor, visited, adj, component);
                }
            }
        }
        
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            unordered_set<int> visited;
            
            // Build adjacency list
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            int completeCount = 0;
            
            for (int i = 0; i < n; ++i) {
                if (visited.find(i) == visited.end()) {
                    vector<int> component;
                    
                    // Find connected component using DFS
                    dfs(i, visited, adj, component);
                    
                    // Check if the component is complete
                    int size = component.size();
                    int expectedEdges = (size * (size - 1)) / 2;
                    int actualEdges = 0;
                    
                    for (int node : component) {
                        actualEdges += adj[node].size();
                    }
                    
                    // Each edge is counted twice in an undirected graph
                    actualEdges /= 2;
                    
                    if (actualEdges == expectedEdges) {
                        completeCount++;
                    }
                }
            }
            
            return completeCount;
        }
    };