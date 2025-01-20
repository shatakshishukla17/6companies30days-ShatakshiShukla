class Solution {
public:
    void func(int k, int n, int start, vector<int>&combination, vector<vector<int>>&ans){
        if(combination.size()==k && n==0){
            ans.push_back(combination);
            return;
        }
        if(combination.size()>k || n<0){
            return;
        }

        for(int i=start; i<=9;i++){
            combination.push_back(i);
            func(k, n-i, i+1, combination, ans);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>combination;
        vector<vector<int>>ans;
        func(k, n, 1, combination, ans);
        return ans;
    }
};
