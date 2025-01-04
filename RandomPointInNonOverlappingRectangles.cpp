class Solution {
public:
    vector<vector<int>>react;
    vector<int>v;
    int sides(vector<int>&r){
        return (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }
    Solution(vector<vector<int>>& rects) {
        react=rects;
        int total=0;
        for(auto r: react){
            total+=sides(r);
            v.push_back(total);
        }
    }
    
    vector<int> pick() {
        int random=rand()%v.back();
        int ind=upper_bound(v.begin(), v.end(), random)-v.begin();
        auto r=react[ind];
        int x_ran=rand()%(r[2]-r[0]+1)+r[0];
        int y_ran=rand()%(r[3]-r[1]+1)+r[1];
        return {x_ran, y_ran};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
