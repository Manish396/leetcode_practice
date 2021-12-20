class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        int carry = 1;
        while(i >= 0){
            int curr = digits[i] + carry;
            digits[i] = (curr)%10;
            carry = curr/10;
            i--;
        }
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
