class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n,vector<int> (n,0));
        
        int k=0, right=n-1,left=0,top=0,bottom=n-1,row=0,col=0;
        while(left<=right && top<=bottom)
        {   
            col=left;
            while(col<=right )
            {
                mat[row][col]=++k;
                col+=1;
            }
            col--;
            top++;

            row=top;
            while(row<=bottom )
            {
                mat[row][col]=++k;
                ++row;

            }
            row--;
            right--;

            if(top<=bottom)
            {col=right;
            while(col>=left  )
            {
                mat[row][col]=++k;
                --col;
            }
            col++;
            bottom--;
            }
            if(left<=right)
            {row=bottom;
            while(row>=top)
            {
                mat[row][col]=++k;
                --row;
            }
            row++;
            left++;}
        }
        return mat;
    }
};