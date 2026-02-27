/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> children;
        
        for(int i=0;i<employees.size();i++)
        {
            children[employees[i]->id]={employees[i]->importance,employees[i]->subordinates};
        }
        
        
        queue<int> q;
        q.push(id);
        int val=0;
        while(!q.empty())
        {
           
            for(auto &a:children[q.front()].second)
                q.push(a);
            val+=children[q.front()].first;
            q.pop();
            
        }

        return val;



    }
};