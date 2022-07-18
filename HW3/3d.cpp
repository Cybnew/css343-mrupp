 class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            const int a = board.size();
            const int b = board.front().size();
            vector<vector<bool>> visited(a, vector<bool> (b, false) );
            for(int i = 0; i < a; ++i) {
                
                for(int j = 0; j < b; ++j) {
                    
                    if(dfs(board, word, 0,  i, j, visited))
                        return true;
                }
            }

            return false;
        }
    
        bool dfs(vector<vector<char> > &board, string word, int index, int i, int j,  vector<vector<bool> > &visited) {
            if(index == word.size()){
              return true;  
            }; 

            if(i < 0 || j < 0 
               || i >= board.size() 
               || j >= board.front().size()  
               || visited[i][j]
               || board[i][j] != word[index]){
                return false;
            };
                
            
            //Set visited 
            visited[i][j] = true;
            bool value = dfs(board, word, index + 1,  i + 1, j, visited) 
                || dfs(board, word, index + 1,  i, j + 1, visited) 
                || dfs(board, word, index + 1,  i - 1, j, visited) 
                || dfs(board, word, index + 1,  i, j - 1, visited);
            
            
            visited[i][j] = false;

            return value;
        }
};
