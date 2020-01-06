class Solution {
public:
    string incrementTime(string time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        
        if (++m == 60) {
            m = 0;
            if (++h == 24) {
                h = 0;
            }
        }
        string hstr = to_string(h);
        string mstr = to_string(m);
        
        if (h < 10) hstr = "0" + hstr;
        if (m < 10) mstr = "0" + mstr;
        
        string result = hstr + ":" + mstr;
        return result;
    }
    
    
    string nextClosestTime(string time) {
        unordered_set<char> chars;
        for (char c : time) chars.insert(c);
        string tempTime = time;
        string result = time;
        while (true) {
            string newTime = incrementTime(tempTime);
            bool allValid = true;
            for (char c : newTime) {
                if (chars.find(c) == chars.end()) {
                    allValid = false;
                    break;
                }
            }
            if (allValid) {
                return newTime;
            }
            tempTime = newTime;
        }
        return result;
    }
};