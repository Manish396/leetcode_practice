class Solution {
public:
    static bool cmp(string a, string b){
        int i = a.find(" ")+1;
        if (isdigit(a[i])) 
            return false;
        int j = b.find(" ")+1;
        if (isdigit(b[j])) 
            return true;
        if (a.substr(i) != b.substr(j)) 
        {
            return a.substr(i) < b.substr(j);
        }
        return a.substr(0,i-1) < b.substr(0,j-1);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
