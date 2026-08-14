class Solution {
public:
    int rows, cols;
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int k){
         if(k == word.length())
         return true;

         if(i<0 || j<0 || i>=rows || j>=cols || board[i][j]!=word[k])
         return false;

         char temp = board[i][j];
         board[i][j] = '#';

         bool found =  dfs(i+1, j, board, word, k+1) || dfs(i-1, j, board, word, k+1) || dfs(i, j+1, board, word, k+1) || dfs(i, j-1, board, word, k+1);

         board[i][j] = temp;
         return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
         rows = board.size();
         cols = board[0].size();

        for(int i =0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(dfs(i, j, board, word, 0))
                return true;
            }
        }
        return false;
    }
};
