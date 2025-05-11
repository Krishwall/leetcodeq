class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrackOperation(num, target, ans, 0, 0, 0, "");
        return ans;
    }
    void backtrackOperation(string& num, int target, vector<string>& ans, long temp, 
              long prevNum, int index, string s) {
      
        if (index == num.length()) {
            if (temp == target) {
                ans.push_back(s);
            }
            return;
        }

        
        for (int i = index; i < num.length(); i++) {
            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

           
            if (i > index && num[index] == '0') break;

            if (index == 0) {
                
                backtrackOperation(num, target, ans, currNum, currNum, i + 1, currStr);
            } else {
               
                backtrackOperation(num, target, ans, temp + currNum, currNum, i + 1, s + "+" + currStr);
                
              
                backtrackOperation(num, target, ans, temp - currNum, -currNum, i + 1, s + "-" + currStr);
                
                
                backtrackOperation(num, target, ans, temp - prevNum + (prevNum * currNum),
                     prevNum * currNum, i + 1, s + "*" + currStr);
            }
        }
    }

};