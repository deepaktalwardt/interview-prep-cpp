class Solution {
public:
    string processEmail(string& email) {
        string localName = "";
        int i;
        bool ignore = false;
        for (i = 0; i < email.size(); i++) {
            char c = email[i];
            if (c == '.') continue;
            if (c == '+') {
                ignore = true;
                continue;
            }
            if (c == '@') break;
            if (!ignore) localName += c;
        }
        string domainName = email.substr(i + 1);
        return localName + '@' + domainName;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for (string& e : emails) {
            string processedEmail = processEmail(e);
            uniqueEmails.insert(processedEmail);
            cout << processedEmail << endl;
        }
        return uniqueEmails.size();
    }
};