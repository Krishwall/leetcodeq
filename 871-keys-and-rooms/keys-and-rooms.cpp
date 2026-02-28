class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        int count = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int key : rooms[node]) {
                if (!vis[key]) {
                    vis[key] = true;
                    q.push(key);
                    count++;
                }
            }
        }

        return count == n;
    }
};