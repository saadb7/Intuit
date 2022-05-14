class Solution {
public:
    int di[4] = {1,0,-1,0} ,
        dj[4] = {0,1,0,-1};
    bool dfs (vector<vector<char>> &board , string &s , int idx , int i , int j){
        
        if (idx == s.length()) return true;
        for (int dir = 0 ; dir < 4 ; ++dir){
            int ni = i + di[dir] , nj = j + dj[dir];
            if (ni >= 0 and ni < board.size() and nj >= 0 and nj < board[0].size()
            and board[ni][nj] == s[idx]){
                char prev = board[ni][nj];
                board[ni][nj] = '-';
                if (dfs (board , s , idx+1 , ni , nj)) return true;
                board[ni][nj] = prev;
            }
        }
        
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string s) {
        // Code here
        
        for (int i = 0 ; i < board.size() ; ++i){
            for (int j = 0 ; j < board[0].size() ; ++j){
                if (board[i][j] == s[0]){
                    char prev = board[i][j];
                    board[i][j] = '-';
                    if (dfs (board , s , 1 , i , j)) return true;
                    board[i][j] = prev;
                }
            }
        }
        
        return false;
    }
};
