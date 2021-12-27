class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, unordered_set<char>> mp;
        int it = 0;
        for (int i = 2; i <= 9; i++)
        {
            if (i == 7 || i == 9)
            {
                for (int j = it; j < it + 4; j++)
                {
                    mp['0' + i].insert('a' + j);
                }
                it += 4;
            }
            else
            {
                for (int j = it; j < it + 3; j++)
                {
                    mp['0' + i].insert('a' + j);
                }
                it += 3;
            }
        }
        set<string>res;
        for(int i = 0; i < digits.length(); i++){
            if(mp.find(digits[i])!=mp.end()){
                if(res.empty()){
                    for(auto it: mp[digits[i]]){
                        string temp = "";
                        temp += it;
                        res.insert(temp);
                        // cout << temp << endl;
                    }
                }
                else{
                    vector<string>temp(res.begin(), res.end());
                    res.clear();
                    for(int j = 0; j < temp.size(); j++){
                        for(auto itt: mp[digits[i]]){
                            res.insert(temp[j] + itt);
                        }
                    }
                }
            }
        }
        vector<string>ans(res.begin(), res.end());
        return ans;
    }
};
