class Solution {
public:
    long long ncr(long long n, long long k){
        long long int res = 1;
        if(k > n - k){
            k = n - k;
        }
        for(long long i = 0; i < k; i++){
            res *= (n - i);
            res /= (i+1);
        }
        return res;
    }
    int numTrees(int n) {
        return ncr(2*(long long)n, (long long)n)/(n+1);
    }
};
