class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        
        // Use queue of pairs for (row, col) coordinates
        queue<pair<int, int>> rottenq;

        // Step 1: Scan the grid to count fresh oranges and enqueue rotten ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                } else if (grid[i][j] == 2) {
                    rottenq.push({i, j});
                }
            }
        }

        // If there are no fresh oranges from the start, we're done
        if (freshCount == 0) return 0;

        int minutes = 0;
        // Direction vectors for moving Up, Down, Left, Right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Multi-source BFS
        while (!rottenq.empty() && freshCount > 0) {
            int size = rottenq.size();
            
            // Process all rotten oranges at the current minute layer
            for (int i = 0; i < size; i++) {
                auto [r, c] = rottenq.front(); // Get front coordinates
                rottenq.pop();

                for (const auto& dir : directions) {
                    int x = r + dir.first;
                    int y = c + dir.second;

                    // If neighbor is within bounds and is a fresh orange
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2; // Corrected: assign value to rot it
                        freshCount--;
                        rottenq.push({x, y});
                    }
                }
            }
            // Increment time only if this layer actually spread the rot
            minutes++;
        }

        // If freshCount is still > 0, it means some oranges were isolated and couldn't be reached
        return (freshCount == 0) ? minutes : -1;
    }
};