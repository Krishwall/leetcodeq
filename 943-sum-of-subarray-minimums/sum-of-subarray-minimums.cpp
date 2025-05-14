class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nexts= nse(arr,n);
        vector<int> prevs= pse(arr,n);int total=0;
        int mod=1e9+7;
        for(int i=0;i<n;++i)
        {   
            total=(total+(arr[i]*1LL*(nexts[i]-i)*(i-prevs[i]))%mod)%mod;

        }return total;
    }

    vector<int> nse(vector<int>& arr,int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int r=n-1;r>=0;--r){
            while(!st.empty() && arr[st.top()]>= arr[r])
            st.pop();
            
                if(st.empty())
                    res[r]=n;
                else
                    res[r]=st.top();

            st.push(r);
            }
        
    return res;
    }
    vector<int> pse(vector<int>& arr , int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int l=0;l<arr.size();++l){
            while(!st.empty() && arr[st.top()]> arr[l])
            st.pop();
            
                if(st.empty())
                    res[l]=-1;
                else
                    res[l]=st.top();

            st.push(l);
            }
        
    return res;}

};