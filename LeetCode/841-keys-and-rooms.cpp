// Recursive DFS
class Solution {
public:
    
    void openRooms(vector<vector<int>>& rooms, int i, vector<bool>& opened) {
        if (opened[i]) return;
        opened[i] = true;
        for (int& n : rooms[i]) {
            openRooms(rooms, n, opened);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> opened(n, false);
        openRooms(rooms, 0, opened);
        for (bool val : opened) {
            if (!val) return false;
        }
        return true;
    }
};


// Iterative DFS
#include <stack>

class Solution {
public:
    void openRooms(vector<vector<int>>& rooms, int i, vector<bool>& opened) {
        stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int currRoom = s.top();
            s.pop();
            for (auto& n : rooms[currRoom]) {
                if (!opened[n]) {
                    s.push(n);
                    opened[n] = true;
                }
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> opened(n, false);
        opened[0] = true;
        for (int i = 0; i < n; i++) {
            if (opened[i]) {
                openRooms(rooms, i, opened);
            }
        }
        for (bool val : opened) {
            if (!val) return false;
        }
        return true;
    }
};