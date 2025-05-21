class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        if (numRows==1)
            return {{1}};
        if (numRows==2)
            return {{1},{1,1}};

        vector<vector<int>> triangle(numRows);
            for(int i=0;i<numRows;++i)
            {
                triangle[i].resize(i+1,1);
            }

        
        for(int i=2;i<numRows;++i)
        {
            for(int j=1;j<triangle[i].size()-1;++j)
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
        return triangle;
    }
};