class Solution {
public:
    set<int>diag;
    set<int>anti_diag;
    set<int>cols;
    void helper(int row,vector<string>&board,  vector<vector<string>>&res){
        // if(row>=res.size() || cols.count(col)>0 || diag.count(row+col)>0 || anti_diag.count(col-row)>0 ){
        //     return false;
        // }
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for(int i = 0 ;i < board.size(); i++){
            if(cols.count(i) > 0 || diag.count(row+i)>0 || anti_diag.count(row-i)>0){
                continue ;
            }
            board[row][i] = 'Q';
            cols.insert(i);
            diag.insert(row+i);
            anti_diag.insert(row-i);
            helper(row+1, board, res);

            board[row][i] = '.';
            cols.erase(i);
            diag.erase(row+i);
            anti_diag.erase(row-i);
            
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n, string(n, '.'));


        helper(0,board,res);
        // for(int i = 0 ; i < n; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         cout<<res[i][j] << " ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;

        return res;
        
    }
};
