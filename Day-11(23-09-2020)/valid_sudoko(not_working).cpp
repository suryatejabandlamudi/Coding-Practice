// not working

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRowCol(board) && checkBoxes(board);
    }
    

    bool checkRowCol(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            bool row_arr[10] = {false};
            bool col_arr[10] = {false};

            for(int j=0; j<9; j++)
            {
                char row_ch = board[i][j];
                char col_ch = board[j][i];
                
                if(row_ch != '.')
                {
                    if(row_arr[int(row_ch-'0')])
                        return false;
                    row_arr[int(row_ch-'0')] = true;
                }
                
                if(col_ch != '.')
                {
                    if(col_arr[int(col_ch-'0')])
                        return false;
                    col_arr[int(col_ch-'0')] = true;
                }
                
            }
        }
        return true;
    }
    
    bool checkBoxes(vector<vector<char>>& board)
    {
        return checkBox(board,0,0,3,3) && checkBox(board,0,3,6,3) &&
        checkBox(board,0,6,9,3) && checkBox(board,3,0,3,6) &&
        checkBox(board,3,3,6,6) && checkBox(board,3,6,6,9) &&
        checkBox(board,6,0,9,3) && checkBox(board,6,3,9,6) && checkBox(board,6,6,9,9);

        
        //for(int i=0; i<10, i+=3)
        //{
        //    for(int j=3; j<10, j+=3)  
        //    {
        //        checkBox(board,i,i,j,j);
        //    }
        //}
    }
    
    bool checkBox(vector<vector<char>>& board, int top_i,int top_j,int bottom_i,int bottom_j)
    {
        bool arr[10] = {false};
        int k;

        for(k=top_i; k<bottom_i; k++)
        {
            for(int j=top_j; j<bottom_j; j++)
            {
                char ch = board[k][j];
                
                if(ch != '.')
                {
                    if(arr[int(ch-'0')])
                        return false;
                    arr[int(ch-'0')] = true;
                }
            }
        }
        return true;
    }
    
    
};





