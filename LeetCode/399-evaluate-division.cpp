class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> m;
    unordered_map<string, bool> v;
    
    double dfs(string start, string end) {
        double result = -1.0;
        for (auto it = v.begin(); it != v.end(); it++) it->second = false;
        stack<pair<string, double>> s;
        s.push(make_pair(start, 1.0));
        while (!s.empty()) {
            pair<string, double> curr = s.top();
            s.pop();
            v[curr.first] = true;
            for (auto& p : m[curr.first]) {
                if (p.first == end) {
                    return curr.second * p.second;
                }
                if (!v[p.first]) {
                    s.push(make_pair(p.first, curr.second * p.second));
                }
            }
        }
        return result;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // Building graph
        for (vector<string>& e : equations) {
            if (m.find(e[0]) == m.end()) {
                m[e[0]] = {make_pair(e[0], 1.0)};
                v[e[0]] = false;
            }
            if (m.find(e[1]) == m.end()) {
                m[e[1]] = {make_pair(e[1], 1.0)};
                v[e[1]] = false;
            }
        }
        for (int i = 0; i < equations.size(); i++) {
            vector<string>& e = equations[i];
            m[e[0]].push_back(make_pair(e[1], values[i]));
            m[e[1]].push_back(make_pair(e[0], 1.0 / values[i]));
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << ": ";
            for (auto p : it->second) {
                cout << p.first << ", " << p.second << "; ";
            }
            cout << endl;
        }
        
        vector<double> result;
        
        // Iterate over queries
        for (vector<string>& q : queries) {
            if (m.find(q[0]) != m.end() && m.find(q[1]) != m.end()) {
                double factor = dfs(q[0], q[1]);
                result.push_back(factor);
            } else {
                result.push_back(-1.0);
            }
        }
        return result;
    }
};