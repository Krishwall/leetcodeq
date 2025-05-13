class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int size=nums2.size();
        int size1=nums1.size();
        vector<int> arr(size);
        vector<int> res(size1);
        int n=size-1;
        while(n>=0)
        {   
                while(!st.empty() && st.top()<nums2[n])
                    {
                        st.pop();
                    }    
                if (st.empty())
                    arr[n]=-1;
                else
                    arr[n]=st.top();
            st.push(nums2[n]);
            n--;

        }
        for (int i=0;i<size1;++i)
        {
                for(int j=0;j<size;++j)
                    {if(nums1[i] == nums2[j])
                    {res[i]=arr[j];
                    break;}
                    }
        }
        return res;

    }
};