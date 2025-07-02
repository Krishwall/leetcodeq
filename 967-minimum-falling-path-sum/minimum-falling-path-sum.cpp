class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prev (m,-1);
        for(int j=0;j<m;++j)
        prev[j]=matrix[0][j];
        for(int i=1;i<n;++i)
        {   vector<int> col(m,-1);
            for(int j=0;j<m;++j)
            {
                
                 int top=INT_MAX,top_left=INT_MAX,top_right=INT_MAX;
                    
                        top=prev[j]+matrix[i][j];
                        if(j>0) top_left=prev[j-1]+matrix[i][j];
                        if(j<m-1) top_right=prev[j+1]+matrix[i][j];
                

                col[j]=min(top,min(top_left,top_right));
            }
            prev=col;
        }
        return *min_element(prev.begin(),prev.end());
    }
};