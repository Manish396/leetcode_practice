class Solution {
public:
    bool validateSubmatrix(vector<vector<char>>& board, int i, int j){
        unordered_set<int>st;
        for(int m = i; m < i+3; m++){
            for(int n = j; n < j+3; n++){
                if(board[m][n] == '.') continue;
                if(board[m][n] != '.'){
                    int d = board[m][n] - '0';
                    if(st.find(d)==st.end())
                        st.insert(d);
                    else
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<int>st;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    if(st.find(d)==st.end())
                        st.insert(d);
                    else
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_set<int>st;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(board[j][i] != '.'){
                    int d = board[j][i] - '0';
                    if(st.find(d)==st.end())
                        st.insert(d);
                    else
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                bool ok = validateSubmatrix(board, i, j);
                if(!ok) return false;
            }
        }
        return true;
    }
};
