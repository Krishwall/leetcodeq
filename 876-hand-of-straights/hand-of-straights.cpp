class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;

       unordered_map<int,int> mp;

        for(auto &a:hand)
        {
            mp[a]++;


        }
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto p:mp)
        pq.push(p.first);

        while(!pq.empty()){
            int top=pq.top();

            if(mp[top]==0){
                pq.pop();
            }
            else{
                mp[top]--;
                for(int i=0;i<k-1;i++)
                {
                    top++;
                    if(mp[top]<=0)
                        return false;
                    mp[top]--;
                }
            }
        }
        return true;
    }
};