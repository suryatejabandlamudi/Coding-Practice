// working

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        bool row_arr[9][9] = {false};
        bool col_arr[9][9] = {false};
        bool box_arr[9][9] = {false};
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                
                int num = board[i][j] - '0' -1;
                int k = ((i/3) * 3) + (j/3);
                
                if(board[i][j] != '.')
                {
                    if(row_arr[i][num] || col_arr[j][num] || box_arr[k][num])
                        return false;
                    
                    row_arr[i][num] = col_arr[j][num] = box_arr[k][num] = true;
                }
            }
        }
        return true; 
    }
};





