class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        if(n < 0) return false;
        vector<int>arr;
        while(n > 0){
            int d = n%10;
            n = n/10;
            arr.insert(arr.begin(), d);
        }
        for(int i = 0; i < arr.size()/2; i++){
            if(arr[i] != arr[arr.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};
