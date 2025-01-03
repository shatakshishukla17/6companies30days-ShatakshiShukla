class Solution {
public:
    int lps(string s1){
        int n=s1.size();
        string s2=s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    void solve(int i, string s, string& s1, string& s2, int& ans){
        if(i==s.size()){
            if(!s1.empty() && !s2.empty()){
                ans=max(ans, lps(s1)*lps(s2));
            }
            return;
        }
        s1.push_back(s[i]);
        solve(i+1, s, s1, s2, ans);
        s1.pop_back();

        s2.push_back(s[i]);
        solve(i+1, s, s1, s2, ans);
        s2.pop_back();
    }
    int maxProduct(string s) {
        int ans=0;
        string s1="", s2="";
        solve(0,s,s1,s2,ans);
        return ans;
    }
};
