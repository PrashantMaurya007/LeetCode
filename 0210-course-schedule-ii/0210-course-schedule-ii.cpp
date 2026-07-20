class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, vector<int>& ans){
        if(pathVis[i]) return 0;
        if(vis[i]) return 1;
        pathVis[i] = 1;
        vis[i] =1;

        for(auto it: adj[i]){
            if(!dfs(it, vis, pathVis, adj, ans)) return false;
        }
        pathVis[i] =0;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> ans;
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(!dfs(i,vis,pathVis,adj,ans)) return {};
            }
        }

        return ans;
    }
};