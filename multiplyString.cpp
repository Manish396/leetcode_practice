class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        
        string str;
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int>res(len1+len2, 0);
        
        for(int i = len1-1; i >= 0; --i) {
            for(int j=len2-1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i+j+1];
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        
        int i = 0;
        while(res[i++] == 0);
        for (--i; i < res.size(); ++i) {
            str += res[i] + '0';
        }
        
        return str;
    }
};
