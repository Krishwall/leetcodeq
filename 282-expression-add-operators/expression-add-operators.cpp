class Solution {
public:
    void solve(int index, string num, int target, vector<string>& ans, string& temp, long resSoFar, long prevNum) {
        if(index == num.length()) {
            if(target == resSoFar) {
                ans.push_back(temp);
            }
            return;
        }

        string numStr;
        long n = 0;
        for(int i=index; i<num.length(); i++) {
            if(i > index && num[index] == '0') // to avoid numbers with leading zeros
                break;

            numStr = num.substr(index, i - index + 1);
            n = stol(numStr);

            string ori = temp;

            if(index == 0) {
                temp += numStr;
                solve(i + 1, num, target, ans, temp, n, n);
                temp = ori;
            } else {
                temp += "+" + numStr;
                solve(i + 1, num, target, ans, temp, resSoFar + n, n);
                temp = ori;

                temp += "-" + numStr;
                solve(i + 1, num, target, ans, temp, resSoFar - n, -n);
                temp = ori;

                temp += "*" + numStr;
                solve(i + 1, num, target, ans, temp, resSoFar - prevNum + (prevNum * n), prevNum * n);
                temp = ori;
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp = "";
        solve(0, num, target, ans, temp, 0, 0);
        return ans;
    }
};