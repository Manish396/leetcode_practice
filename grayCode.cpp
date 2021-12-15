class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> res;
        res.push_back(0);
        for(int i = 1; i <= n; i++){
            for(int j = res.size( )-1; j >= 0; j--){
                res.push_back(1 <<(i-1) | res[j]);
                // cout << res.back() << endl;
            }
        }
        return res;
    }
};
