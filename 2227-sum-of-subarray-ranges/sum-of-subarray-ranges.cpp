class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         int n=nums.size();
        vector<int> nexts= nsee(nums,n);
        vector<int> prevs= psee(nums,n);long long totals=0,totalg=0;
        vector<int> prevg= pgee(nums,n);
        vector<int> nextg= ngee(nums,n);
        int mod=1e9+7;
        for(int i=0;i<n;++i)
        {   
            totals=(totals+(nums[i]*1LL*(nexts[i]-i)*(i-prevs[i])));
            totalg=(totalg+(nums[i]*1LL*(nextg[i]-i)*(i-prevg[i])));

        }return totalg-totals;

        
    }
    vector<int> nsee(vector<int>& arr,int n ){
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
    vector<int> psee(vector<int>& arr , int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int l=0;l<n;++l){
            while(!st.empty() && arr[st.top()]> arr[l])
            st.pop();
            
                if(st.empty())
                    res[l]=-1;
                else
                    res[l]=st.top();

            st.push(l);
            }
        
    return res;}
    vector<int> ngee(vector<int>& arr,int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int r=n-1;r>=0;--r){
            while(!st.empty() && arr[st.top()]<= arr[r])
            st.pop();
            
                if(st.empty())
                    res[r]=n;
                else
                    res[r]=st.top();

            st.push(r);
            }
        
    return res;
    }
    vector<int> pgee(vector<int>& arr , int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int l=0;l<n;++l){
            while(!st.empty() && arr[st.top()]< arr[l])
            st.pop();
            
                if(st.empty())
                    res[l]=-1;
                else
                    res[l]=st.top();

            st.push(l);
            }
        
    return res;}
};