#include <unordered_map>

class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> stream;
    
    Logger() {
        
    }
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = stream.find(message);
        if (it != stream.end()) {
            if (timestamp - it->second >= 10) {
                it->second = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            stream[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */