class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
       
        vector<int> arr(n);
        
        
        for(auto i=2*n-1;i>=0;i--)
            {  
                while(!st.empty() && st.top()<=nums[i%n])
                    {
                        st.pop();
                    }    
                if (st.empty())
                    arr[i%n]=-1;
                else
                    arr[i%n]=st.top();
            st.push(nums[i%n]);
          

        }
        
        return arr;

    }
};