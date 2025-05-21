class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=0;
        for(int i=0;i<n-1;++i)
        {   m++;
            for(int j=m;j<n;++j)
                swap(matrix[i][j],matrix[j][i]);
        }

         for (int i=0;i<n;++i)
                reverse(matrix[i].begin(),matrix[i].end());   
    }
};