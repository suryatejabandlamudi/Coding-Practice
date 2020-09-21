class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {

        // n = no of neighbours
        // Live- l, Dead - d
        
        // l , n<2 ... => d
        // l , n==2 or 3 ... => l
        // l , n>3 .... => d
        // d , n==3 ... => l
        
        
        // use 2nd bit to store,the next state
        // then at end remove last but , by shifting
        
        // [2nd bit, 1st bit] = [next state, current state]

        // 00  dead (next) <- dead (current)
        // 01  dead (next) <- live (current)  
        // 10  live (next) <- dead (current)  
        // 11  live (next) <- live (current) 
        
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m ; i++)
        {
           for(int j=0; j<n; j++)
           {
               int no_of_neighbours = getNeighbours(board, m,n,i,j);
               
               if(board[i][j])
               {
                   if(no_of_neighbours ==2 || no_of_neighbours==3)
                       board[i][j] = 3;
                   else
                       board[i][j] = 1;
               }
               else
               {
                   if(no_of_neighbours ==3)
                       board[i][j] = 2;
               }
           }
        }
        
        for(int i=0; i<m ; i++)
        {
           for(int j=0; j<n; j++)
           {
               board[i][j] >>= 1;
           }
        }
        

    }
    
    
    int getNeighbours(vector<vector<int>> board, int m, int n, int i, int j)
    {
        int count = 0;
        for(int I=max(i-1,0); I<=min(i+1, m-1); I++)
        {
            for(int J=max(j-1,0); J<=min(j+1, n-1); J++)
            {
                count += board[I][J] & 1;
            }
        }
        
        count -= board[i][j] & 1;
        
        return count;
    }
};
