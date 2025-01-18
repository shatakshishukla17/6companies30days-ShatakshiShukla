class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mpp;
        // string temp="";
        for(char c : s){
            mpp[c]++;
        }
        vector<pair<char, int>>freqVec(mpp.begin(), mpp.end());
        sort(freqVec.begin(), freqVec.end(), [](pair<char, int>&a, pair<char, int>&b){
            return b.second<a.second;
        });

        string result;
        for(auto& p : freqVec ){
            result.append(p.second , p.first);
        }
        
        return result;
    }
};
