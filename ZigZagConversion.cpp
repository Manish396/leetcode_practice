class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>table(numRows+1, vector<char>(1001, ' '));
        int n = s.length();
        int cnt = 0, i;
        if(numRows == 1){
            return s;
        }
        for(i = 0; i < numRows and cnt < n; i++){
            table[i][0] = s[cnt++];
        }
        int j = 1;
        string ans;
        while(cnt < n){
            if(i == numRows){
                i = numRows - 2;
                while(i > 0 and cnt < n){
                    table[i][j] = s[cnt++];
                    i--;
                }
                j++;
            }
            if(i == 0){
                while(i < numRows and cnt < n){
                    table[i][j] = s[cnt++];
                    i++;
                }
                j++;
            }
        }
        int col = j;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < col; j++){
                if(table[i][j] != ' '){
                    ans += table[i][j];
                }
            }
        }
        return ans;
    }
};
