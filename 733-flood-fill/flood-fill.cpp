class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=image.size();
        int m=image[0].size();
        if (image[sr][sc] == color) return image; 
        int val=image[sr][sc];
        image[sr][sc] = color;
        return paint(image,sr,sc,drow,dcol,color,n,m,val);

        
    }

    vector<vector<int>> paint(vector<vector<int>>& image,int sr,int sc,int drow[],int dcol[],int color,int n,int m,int val)
    {
        
        for(int i=0;i<4;++i)
        {
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] !=color && image[nrow][ncol]==val )
            {image[nrow][ncol]=color;
            paint(image,nrow,ncol,drow,dcol,color,n,m,val);
            }
        }

        return image;
    }
};