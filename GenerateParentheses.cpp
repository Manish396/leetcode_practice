class Solution {
public:
    void generate(vector<string>&ans, int op, int cl, string res, int n){
        if(res.length() == 2*n){
            ans.push_back(res);
            return;
        }
        if(op < n){
            generate(ans, op +1, cl, res + '(', n);
        }
        if(cl < op){
            generate(ans, op, cl + 1, res + ')', n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res = "";
        int op = 0, cl = 0;
        generate(ans, op, cl, res, n);
        return ans;
    }
};
