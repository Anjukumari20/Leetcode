class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        // Create an adjacency list where each node maps to a list of (neighbor, weight)
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }

        // Build the graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
        }

        // Find connected components
        int[] component = new int[n];
        Arrays.fill(component, -1);
        int componentId = 0;

        // Store minimum weight in each component
        Map<Integer, Integer> minWeight = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                int minEdgeWeight = dfs(graph, component, i, componentId, Integer.MAX_VALUE);
                minWeight.put(componentId, minEdgeWeight);
                componentId++;
            }
        }

        // Answer queries
        int[] result = new int[query.length];
        for (int i = 0; i < query.length; i++) {
            int s = query[i][0], t = query[i][1];

            if (component[s] != component[t]) {
                result[i] = -1;  // No path exists
            } else {
                result[i] = minWeight.get(component[s]);
            }
        }

        return result;
    }

    private int dfs(Map<Integer, List<int[]>> graph, int[] component, int node, int id, int minWeight) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        component[node] = id;
        int minEdgeWeight = minWeight;

        while (!stack.isEmpty()) {
            int curr = stack.pop();
            for (int[] neighbor : graph.get(curr)) {
                int nextNode = neighbor[0], weight = neighbor[1];
                minEdgeWeight &= weight;
                if (component[nextNode] == -1) {
                    component[nextNode] = id;
                    stack.push(nextNode);
                }
            }
        }

        return minEdgeWeight;
    }
}