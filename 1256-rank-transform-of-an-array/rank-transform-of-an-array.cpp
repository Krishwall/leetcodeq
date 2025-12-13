class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        }
    };
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return {};
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        vector<int>ans(arr.size());
        int m=pq.top().first;
        int i=1;
        ans[pq.top().second]=i;
        pq.pop();
        while(!pq.empty()){
            if(m==pq.top().first){
                ans[pq.top().second]=i;
                pq.pop();
            }
            else{
                m=pq.top().first;
                ans[pq.top().second]=++i;
                pq.pop();
            }
        }
        return ans;

    }
};