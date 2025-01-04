class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int>mpp;
        int bull=0;
        int cow=0;
        for(int i=0;i<secret.length();i++){
            mpp[secret[i]]++;
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bull++;
                mpp[secret[i]]--;
            }
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i]!=guess[i] && mpp[guess[i]]){
                cow++;
                mpp[guess[i]]--;
            }
        }
        string ans;
        ans+=to_string(bull)+'A'+to_string(cow)+'B';
        return ans;
    }
};
