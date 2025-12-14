class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;

        map<int,int> freq;

        for(auto &a:hand)
        {
            freq[a]++;


        }
        auto it=freq.begin();
        while(it!=freq.end())
        {if(it->second==0)
        {it++;continue;}
        int start=it->first;
        int count=it->second;
        for(int i=0;i<k;i++)
        {
            if(freq[i+start]<count) return false;
            freq[start+i]-=count;
        }
        ++it;
        }
        return true;

    }
};