class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Build the adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        // Function to perform DFS and collect nodes in the current component
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };

        // Iterate over all nodes to find all components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);
                // Check if the component is complete
                bool isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (graph[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) {
                    ++completeComponents;
                }
            }
        }

        return completeComponents;
    }
};