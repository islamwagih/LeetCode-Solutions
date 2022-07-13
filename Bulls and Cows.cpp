class Solution {
public:

    string getHint(string secret, string guess) {
        map<char, set<int>> s;
        int n = secret.size();
        int A = 0, B = 0;
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                A++;
            }else{
                s[secret[i]].insert(i);
            }
        }
        int m = guess.size();
        for(int i=0;i<m;i++){
            if(guess[i] != secret[i] && s.find(guess[i]) != s.end()){
                B++;
                s[guess[i]].erase(s[guess[i]].begin());
                if(s[guess[i]].size() == 0){
                    s.erase(guess[i]);
                }
            }
        }
        string str = to_string(A)+"A"+to_string(B)+"B";
        return str;
    }
};
