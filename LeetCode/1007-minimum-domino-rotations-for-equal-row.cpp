class Solution {
public:
    int checkRotations(int elem, vector<int>& A, vector<int>& B) {
        int rotA = 0;
        int rotB = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != elem && B[i] != elem) {
                return -1;
            } else if (A[i] != elem) {
                rotA++;
            } else if (B[i] != elem) {
                rotB++;
            }
        }
        return min(rotA, rotB);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int rotations = checkRotations(A[0], A, B);
        if (rotations != -1) {
            return rotations;
        }
        return checkRotations(B[0], A, B);
    }
};