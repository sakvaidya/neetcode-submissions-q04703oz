class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryout = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (i == digits.size() - 1) {
                digits[i] += 1;
                carryout = digits[i]/10;
                digits[i] = digits[i]%10;
            } else {
                digits[i] += carryout;
                carryout = digits[i]/10;
                digits[i] = digits[i]%10;
            }
        }
        if (carryout > 0) {
            digits.insert(digits.begin(), carryout);
        }
        return digits;
    }
};
