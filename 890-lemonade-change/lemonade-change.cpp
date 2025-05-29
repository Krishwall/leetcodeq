class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int r=0;int n=bills.size();
        int bill5=0,bill10=0,bill20=0;
        while(r<n)
        {
            if(bills[r]==5)
                bill5+=5;
            else 
            {
                if(bills[r]==10)
                {
                    if(bill5)
                   { bill10+=10;
                    bill5-=5;
                    }
                    else return false;
                }
                else if(bills[r]==20)
                {
                    if(bill10 && bill5)
                        {bill10-=10;
                            bill5-=5;}
                     else if(bill5>=15)
                        bill5-=15;
                    else return false;       
                }
            }
            r++;
            
        }
        return true;
    }
};