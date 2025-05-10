class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        return exist(m,n,board,word);

    }

    bool searchNext(int idx,int row, int col, vector<vector<char>>& board,string& word,int m, int n)
    {   
        if (idx==word.length())
            return true;

        if(row<0 || col<0 ||row==m || col==n || word[idx]!=board[row][col] ||  board[row][col]=='*')
            {
                return false;
            }

        char c=board[row][col];
        board[row][col]='*';

        bool top=searchNext(idx+1,row-1,col,board,word,m,n);
        bool bottom=searchNext(idx+1,row+1,col,board,word,m,n);
        bool left=searchNext(idx+1,row,col-1,board,word,m,n);
        bool right=searchNext(idx+1,row,col+1,board,word,m,n);

        board[row][col]= c;

        return top||bottom||left||right;
    }

    bool exist(int m , int n,vector<vector<char>>& board, string word )

       { for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if(board[i][j]== word[0])
                   if(searchNext(0,i,j,board,word,m,n))
                   return true;
        
        return false;


        
        }
    
};