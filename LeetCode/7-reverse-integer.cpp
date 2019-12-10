// Easy to read solution
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while (x != 0) {
            int num = x % 10;
            x = x / 10;
            result = result * 10 + num;
        }
        if (result < INT_MIN || result > INT_MAX) {
            return 0;
        }
        return result;
    }
};


// Not easy to read
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int curr = x % 10;
            x =  x / 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && curr > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && curr < -8)) return 0;
            rev = rev * 10 + curr;
        }
        return rev;
    }
};