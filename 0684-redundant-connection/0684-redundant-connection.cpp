class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n+1);
        for(int i = 1; i<= n; i++){
            parents[i]= i;
        }

        for(const auto& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(parents, node1);
            int root2 = find(parents, node2);

            if(root1 == root2){
                return edge;
            }

            parents[root1] = root2;
        }

        return {};
    }

    private:
        static int find(vector<int>& parent, int node){
            while(node != parent[node]){
                parent[node] = parent[parent[node]];
                node = parent[node];
            }
            return node;
        }
};