class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int beg=1,mid;
        int n= bloomDay.size();
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int adj=0;
        int cnt=0;
        int ans=-1;
        
        while (beg<=end)
        {   adj=0;
              cnt=0;
             mid=(beg+end)/2;

            for(int i=0;i<n;++i)
            {
                    if(mid>=bloomDay[i])
                    {
                        cnt+=1;
                    }
                    else
                        cnt=0;
                    if (cnt==k)
                        {adj+=1;
                        cnt=0;
                        }    
            }
            
            if (adj<m)
                beg=mid+1;
            else
               { ans=mid;
                end=mid-1;}
            
        }
        return ans;
       
    }
};