
class Solution {
public:
    int lessThanEqual(vector<int>&nums, int k){
        if(k<0) return 0;
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(sum>k){
                sum=sum-(nums[l]%2);
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessThanEqual(nums, k)-lessThanEqual(nums, k-1);
    }
};
