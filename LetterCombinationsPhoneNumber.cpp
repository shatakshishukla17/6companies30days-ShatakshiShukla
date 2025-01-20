class Solution {
public:
    const vector<string> digitToLetters = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz" // 9
    };
    void func(string digits, int ind, string curr, vector<string>&ans){
        if(ind==digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = digitToLetters[digits[ind] - '0'];
        for(char letter : letters){
           curr.push_back(letter);
            func(digits , ind+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string>ans;
        string curr;
        func(digits, 0, curr, ans);
        return ans;
    }
};
