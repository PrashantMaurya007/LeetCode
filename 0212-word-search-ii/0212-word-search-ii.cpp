class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> ans;

    void insert(TrieNode* root, string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {

        char ch = board[i][j];

        if (ch == '#')
            return;

        node = node->child[ch - 'a'];

        if (!node)
            return;

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int m = board.size();
        int n = board[0].size();

        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for (auto &d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && x < m && y >= 0 && y < n)
                dfs(board, x, y, node);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (string word : words)
            insert(root, word);

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (root->child[board[i][j]-'a'])
                    dfs(board, i, j, root);
            }
        }

        return ans;
    }
};