class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int al = a.length();
        int bl = b.length();
        string copyofa = a;
        int cnt = 1;
        while(a.length() < bl){
            a += copyofa;
            cnt++;
        }
        if(a.find(b)!= string::npos){
            return cnt;
        }
        else{
            a+=copyofa;
            cnt++;
            if(a.find(b)!= string::npos){
                return cnt;
            }
        }
        return -1;
    }
};
