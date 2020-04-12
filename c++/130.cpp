class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X')
            return;
        if(visited[r][c])
            return;
        visited[r][c] = true;
        dfs(board, visited, r + 1, c);
        dfs(board, visited, r, c + 1);
        dfs(board, visited, r - 1, c);
        dfs(board, visited, r, c-1);
    }

    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')
                dfs(board, visited, i, 0);
            if(board[i][board[0].size()-1] == 'O')
                dfs(board, visited, i, board[0].size()-1);
                
        }
        for (int j = 0; j < board[0].size(); j++){
            if(board[0][j] == 'O')
                dfs(board, visited, 0, j);
            if(board[board.size()-1][j] == 'O')
                dfs(board, visited, board.size()-1, j);
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};