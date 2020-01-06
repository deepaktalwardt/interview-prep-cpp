class Solution {
public:
    /*
    
    [1,   2,   3,   2,   2]
          p1             p2
    
    b1 -> 2
    b2 -> 3
    currFruits = 4
    maxFruits = 4
    
    [3,  3,  3,  1,  2,  1,  1,  2,  3,  3,  4]
                                         p1  p2
    
    b1 -> 3
    b2 -> 4
    currFruits = 2
    maxFruits = 5
    
    */
    
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        if (n < 3) return n;
        
        int p1 = 0;
        int p2 = 0;
        int prevStart = 0;
        int typeB1 = tree[p1]; 
        int typeB2 = tree[p2];
        
        int maxFruits = 0;
                
        for (int i = 1; i < n; i++) {
            int currType = tree[i];
            
            if (currType != typeB1 && typeB1 == typeB2) {
                typeB2 = currType;
            }
            if (currType == typeB1 || currType == typeB2) {
                p2++;
                if (currType != tree[prevStart]) prevStart = i;
            } else {
                maxFruits = max(p2 - p1 + 1, maxFruits);
                p1 = prevStart;
                p2 = i;
                typeB1 = tree[p1];
                typeB2 = currType;
                prevStart = p2;
            }
        }
        maxFruits = max(p2 - p1 + 1, maxFruits);
        return maxFruits;
    }
};