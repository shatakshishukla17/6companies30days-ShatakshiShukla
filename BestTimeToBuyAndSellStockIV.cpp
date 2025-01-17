class Solution {
public:
    //RECURSION APPROACH 1:
     int fr(int ind, int buy, int cap, vector<int>&prices, int n){
        if(cap==0 || ind==n) return 0;
        if(buy==1){
            return max(-prices[ind]+fr(ind+1, 0, cap, prices, n), 0+ fr(ind+1, 1, cap, prices, n));
        } else{
            return max(prices[ind]+fr(ind+1, 1, cap-1, prices, n), 0+fr(ind+1, 0, cap, prices, n));
        }
    }

     //MEMOIZATION APPROACH 1:
    int fm(int ind, int buy, int cap, vector<int>&prices, int n, vector<vector<vector<int>>>&dp){
        if(cap==0 || ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1){
            return dp[ind][buy][cap] = max(-prices[ind]+fm(ind+1, 0, cap, prices, n, dp), 0+ fm(ind+1, 1, cap, prices, n, dp));
        } else{
            return dp[ind][buy][cap] = max(prices[ind]+fm(ind+1, 1, cap-1, prices, n, dp), 0+fm(ind+1, 0, cap, prices, n, dp));
        }
    }

    //RECURSION APPROACH 2:
    int fr2(int ind, int tranNo, int k, vector<int>&prices, int n){
        if(ind==n || tranNo==2*k) return 0;
        if(tranNo%2==0){
            return max(-prices[ind]+fr2(ind+1, tranNo+1, k, prices, n), 0+fr2(ind+1, tranNo, k, prices, n));
        } else{
            return max(prices[ind]+fr2(ind+1, tranNo+1, k, prices, n), 0+fr2(ind+1, tranNo, k, prices, n));
        }
    }

    //MEMOIZATION APPROACH 2:
    int fm2(int ind, int tranNo, int k, vector<int>&prices, int n, vector<vector<int>>&dp){
        if(ind==n || tranNo==2*k) return 0;
        if(dp[ind][tranNo]!=-1) return dp[ind][tranNo];
        if(tranNo%2==0){
            return dp[ind][tranNo]= max(-prices[ind]+fm2(ind+1, tranNo+1, k, prices, n, dp), 0+fm2(ind+1, tranNo, k, prices, n, dp));
        } else{
            return dp[ind][tranNo]= max(prices[ind]+fm2(ind+1, tranNo+1, k, prices, n, dp), 0+fm2(ind+1, tranNo, k, prices, n, dp));
        }
    }


    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        //**************APPROACH 1********************
        // return fr(0,1,k,prices, n);

        // vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return fm(0,1,k,prices, n, dp);

        //TABULATION APPROACH 1:
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int cap=1;cap<=k;cap++){
        //             if(buy==1){
        //             dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap], 0+ dp[ind+1][1][cap]);
        //         } else{
        //             dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
        //         }
        //         }
        //     }
        // }
        // return dp[0][1][k];


        //SPACE OPTIMIZATION APPROACH 1:
        // vector<vector<int>>after(2, vector<int>(k+1, 0));
        // vector<vector<int>>cur(2, vector<int>(k+1, 0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int cap=1;cap<=k;cap++){
        //             if(buy==1){
        //             cur[buy][cap] = max(-prices[ind]+after[0][cap], 0+ after[1][cap]);
        //         } else{
        //             cur[buy][cap] = max(prices[ind]+after[1][cap-1], 0+after[0][cap]);
        //         }
        //         }
        //     }
        //     after=cur;
        // }
        // return after[1][k];

        //**********APPROACH 2:*****************
        // return fr2(0,0,k,prices, n);

        // vector<vector<int>>dp(n, vector<int>(2*k+1, -1));
        // return fm2(0,0,k,prices, n, dp);

        //TABULATION 2:
        // vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        // for(int ind=n-1; ind>=0; ind--){
        //     for(int tranNo=2*k-1; tranNo>=0; tranNo--){
        //         if(tranNo%2==0){
        //             dp[ind][tranNo]= max(-prices[ind]+dp[ind+1][tranNo+1], 0+dp[ind+1][tranNo]);
        //         } else{
        //             dp[ind][tranNo]= max(prices[ind]+dp[ind+1][tranNo+1], 0+dp[ind+1][tranNo]);
        //         }
        //     }
        // }
        // return dp[0][0];


        //SPACE OPTIMIZATION 2:
        vector<int>after(2*k+1, 0);
        vector<int>cur(2*k+1, 0);
        for(int ind=n-1; ind>=0; ind--){
            for(int tranNo=2*k-1; tranNo>=0; tranNo--){
                if(tranNo%2==0){
                    cur[tranNo]= max(-prices[ind]+after[tranNo+1], 0+after[tranNo]);
                } else{
                    cur[tranNo]= max(prices[ind]+after[tranNo+1], 0+after[tranNo]);
                }
            }
            after=cur;
        }
        return after[0];

    }
};
