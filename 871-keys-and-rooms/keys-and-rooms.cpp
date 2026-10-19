class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n==0) return true;
        vector<int> visited(n, false);
        stack<int> toVisit;
        visited[0] = true;
        toVisit.push(0);
        int count = 0;
        while(!toVisit.empty()){
            int room = toVisit.top();
            toVisit.pop();
            for(int key: rooms[room]){
                if(!visited[key]){
                    visited[key] = true;
                    count++;
                    toVisit.push(key);
                }
            }
        }
        return count==n-1;
    }
};