class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> a(n);
        a[0]=arr[0];
        for (int i=1;i<n;++i)
            a[i]=a[i-1]^arr[i];
        vector<int> answer(queries.size());
        for (int k=0;k<queries.size();++k)
        {
            int i=queries[k][0];
            int j=queries[k][1];

            if(i==0){
                answer[k]=a[j];
            }
            else 
                answer[k]=a[j]^a[i-1];
        }
        return answer;
    }
};