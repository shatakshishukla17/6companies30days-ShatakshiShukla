class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size()/2;
        //we use median because : When the array is sorted, the median is the middle value that minimizes the distance to all other elements on either side. If we choose a value smaller or larger than the median, the total moves increase because the imbalance between the distances on either side grows. Using the median ensures that the sum of distances to all numbers is minimized. This is a mathematical property of the median for minimizing absolute differences
        int median=nums[n];
        int ans=0;
        for(int num :nums){
            ans+=abs(num-median);
        }
        return ans;
    }
};
