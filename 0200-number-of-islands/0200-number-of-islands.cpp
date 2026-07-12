class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
         if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();

        int island = 0;

        for(int i = 0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    island++;
                    dfs(i, j, grid);
                }
            }
        }
        return island; 
    }
    public:
          void dfs( int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs( i + 1, j, grid); // down
        dfs( i - 1, j, grid); // up
        dfs( i, j + 1, grid); // right
        dfs( i, j - 1, grid); // left
    }
};