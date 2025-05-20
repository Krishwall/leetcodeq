class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colj=1,m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;++i)
            {   for(int j=0;j<n;++j)
            {
                if (matrix[i][j]==0)
                    {matrix[i][0]=0;
                    if (j!=0)
                        matrix[0][j]=0;
                    else 
                    colj=0;
                    }
            }
            }
        for(int i=1;i<n;++i)
        {   if (matrix[0][i]==0)
            for (int j=0;j<m;++j)
            {
                matrix[j][i]=0;
            }
        }
        for(int i=0;i<m;++i)
        {   if (matrix[i][0]==0)
            for (int j=0;j<n;++j)
            {
                matrix[i][j]=0;
            }
        }
         if (colj==0)
         for(int i=0;i<m;++i)
         {
            matrix[i][0]=0;
         }
    }
};