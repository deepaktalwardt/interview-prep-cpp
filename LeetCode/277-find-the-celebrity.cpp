// Time: O(N), Space: O(1)
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) {
                return -1;
            }
        }
        return candidate;
    }
};

// Time: O(N^2), Space: O(N)
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    struct Degrees {
        int in;
        int out;
        Degrees(int i, int o): in(i), out(o) {}
    };
    
    int findCelebrity(int n) {
        vector<Degrees> degrees(n, Degrees(0, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (knows(i, j)) {
                    degrees[i].out++;
                    degrees[j].in++;
                }
                if (knows(j, i)) {
                    degrees[j].out++;
                    degrees[i].in++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (degrees[i].in == n - 1 && degrees[i].out == 0) {
                return i;
            }
        }
        return -1;
    }
};