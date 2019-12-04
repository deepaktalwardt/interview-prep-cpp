// Time: O(N), Space: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                secret[i] = '$';
                guess[i] = '$';
                bulls++;
            }
        }
        for (int k = 0; k < secret.size(); k++) {
            if (secret[k] == '$') continue;
            int idx = guess.find_first_of(secret[k], 0);
            if (idx != string::npos) {
                cows++;
                guess[idx] = '!';
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// Time: O(N), Space: O(N)
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() == 0) return "";
        unordered_multiset<char> guessSet;
        vector<bool> marked(secret.size(), false);
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                marked[i] = true;
                bulls++;
            } else {
                guessSet.insert(guess[i]);
            }
        }
        for (int k = 0; k < secret.size(); k++) {
            if (!marked[k]) {
                auto it = guessSet.find(secret[k]);
                if (it != guessSet.end()) {
                    cows++;
                    guessSet.erase(it);
                }
            }
        }
        string toReturn = to_string(bulls) + "A" + to_string(cows) + "B";
        return toReturn;
    }
};