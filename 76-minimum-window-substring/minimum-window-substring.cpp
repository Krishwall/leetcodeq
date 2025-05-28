class Solution {
public:
    string minWindow(string s, string t) {
       int m=s.length();
       int n=t.length();
       vector<int> hash(125,0);
       int count=0,minl=INT_MAX;
       int l=0,r=0,start_idx=-1; 
       for(int i=0;i<n;++i)
       {
        hash[t[i]]++;
       }

       while(r<m)
       {
        if(hash[s[r]]>0) count+=1;
        hash[s[r]]--;

        while(count==n)
        {   
            if(r-l+1<minl)
               { minl=r-l+1;
            
                start_idx=l;}
            hash[s[l]]++;
            if (hash[s[l]]>0) count-=1;
            l++;

        }
     
        r++;
       }
       return start_idx==-1?"":s.substr(start_idx,minl);
    }
};