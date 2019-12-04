#include <algorithm>
#include <sstream>
#include <cctype>
class Solution {
public:

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let_logs;
        vector<string> dig_logs;
        string id, first_word;
        for (string log : logs) {
            
            stringstream ss(log);
            ss >> id;
            ss >> first_word;
            if (isalpha(first_word[0])) {
                let_logs.push_back(log);
            } else {
                dig_logs.push_back(log);
            }
        }
        sort(let_logs.begin(), let_logs.end(), [](const string& a, const string& b) {
            string str_a = a.substr(a.find_first_of(" ") + 1);
            string str_b = b.substr(b.find_first_of(" ") + 1);
            if (str_a != str_b) {
                return str_a < str_b;
            } else {
                return a < b;
            }
            
        });
        let_logs.insert(let_logs.end(), dig_logs.begin(), dig_logs.end());
        return let_logs;
    }
                
};