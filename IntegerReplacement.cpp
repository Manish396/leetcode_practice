class Solution {
public:
    int integerReplacement(long long int n) {
        if(n <= 1){
            return 0LL;
        }
        if(n%2 == 0){
            return integerReplacement(n/2LL) + 1LL;
        }
        else{
            return min(integerReplacement(n-1LL) + 1LL, integerReplacement(n + 1LL) + 1LL);
        }
    }
};
