class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0;
        int j=9;
        unordered_map<string, int>mpp;
        while(j<s.length()){
            mpp[s.substr(i, j-i+1)]++;
            j++;
            i++;
        }
        vector<string>ans;
        for(auto& it: mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
