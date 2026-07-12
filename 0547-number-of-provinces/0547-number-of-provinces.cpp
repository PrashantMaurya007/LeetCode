class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,
             vector<bool>& visited,
             int start) {

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {

            int city = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {

                if (isConnected[city][i] == 1 && !visited[i]) {

                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int provinces = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                bfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }
};