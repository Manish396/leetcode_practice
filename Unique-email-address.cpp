class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        int n = emails.size();
        for(int i = 0; i < n; i++){
            string temp = "";
            bool atrate = false, plus = false;
            for(auto it: emails[i]){
                if(it == '@'){
                    temp+=it;
                    atrate = true;
                }
                if(plus and !atrate){
                    continue;
                }
                if(!atrate){
                    if(it!='.' and it!='+')
                        temp+=it;
                    else if(it == '+'){
                        plus = true;
                    }
                    
                }
                else{
                    temp+=it;
                }
            }
            // cout << temp <<" ";
            st.insert(temp);
        }
        return st.size();
    }
};
