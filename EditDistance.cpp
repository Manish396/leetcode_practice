class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int table[n+1][m+1];
        for(int i = 0; i < m+1; i++){
            table[n][i] = (m - i);
        }
        for(int i = 0; i < n+1; i++){
            table[i][m] = (n - i);
        }
        for(int i = n -1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    table[i][j] = table[i+1][j+1];
                }
                else{
                    table[i][j] = min(table[i+1][j], min(table[i+1][j+1], table[i][j+1])) + 1;
                }
            }
        }
        return table[0][0];
    }
};
