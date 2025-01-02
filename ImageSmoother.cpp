//1st APPROACH USING SPACE 
class Solution {
public:
    vector<vector<int>> dir{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                int cnt=0;
                for(auto &it:dir){
                    int inew= i+it[0];
                    int jnew= j+it[1];
                    if(inew>=0 && inew<n && jnew>=0 && jnew<m){
                        sum+=img[inew][jnew];
                        cnt++;
                    }
                }
                ans[i][j]=sum/cnt;
            }

        }
        return ans;
    }
};
