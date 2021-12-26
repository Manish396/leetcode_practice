#define ll long long
class Solution {
public:
    vector<string> result;
    void dfs(const string& num, int index, ll val, ll prev, int target, string& temp) {
        if (index == num.size()) {
            if (val == target) {
                result.push_back(temp);
            }
            return;
        }
        for (int i = index + 1; i <= num.size(); ++i) {
            string left = num.substr(index, i - index);
            if (left[0] == '0' && left.size() > 1) {
                continue;
            }
            ll leftNum = atoll(left.c_str());
            if (index == 0) {
                temp = left;
                dfs(num, i, leftNum, leftNum, target, temp);
                temp.clear();
            } 
            else {
                temp.push_back('+');
                temp.append(left);
                dfs(num, i, val + leftNum, leftNum, target, temp);
                temp[temp.length() - left.length()-1] = '-';
                dfs(num, i, val - leftNum, -leftNum, target, temp);
                temp[temp.length() - left.length()-1] = '*';
                dfs(num, i, (val - prev) + (leftNum * prev), (leftNum * prev), target, temp);
                temp.erase(temp.length() - left.length()-1);
            }
        }
    }
    vector<string> addOperators(const string& num, int target) {
        result.clear();
        string temp;
        dfs(num, 0, 0, 0, target, temp);
        return result;
    }
};
