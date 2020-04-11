class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<bool>>& visit,vector<vector<char>>& board, int r, int c, string word, int widx){
        
        if(widx == word.size())
            return true;
        int m = board.size(), n = board[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || visit[r][c] || board[r][c] != word[widx])
            return false;

        visit[r][c] = true;
        bool b = dfs(visit, board, r + 1, c, word, widx + 1) || dfs(visit, board, r - 1, c, word, widx + 1) || dfs(visit, board, r, c+1, word, widx + 1) || dfs(visit, board, r, c-1, word, widx + 1);
        visit[r][c] = false;
        return b;
        
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                
                if(dfs(visit, board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};