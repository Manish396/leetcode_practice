class Solution {
public:
    int common(string& word1, string& word2) {
        int cnt = 0;
        for (int i = 0; i < 6; ++i) {
            if (word1[i] == word2[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; ++i) {
            string guessWord = "###";
            while(guessWord == "###"){
                guessWord = wordlist[rand() % wordlist.size()];
            }
            int match = master.guess(guessWord);
            vector<string> newlist;
            for (string& word : wordlist) {
                if (match != common(word, guessWord)) {
                    word = "###";
                }
            }
        }
    }
};
