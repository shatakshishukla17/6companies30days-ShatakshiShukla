//APPROACH 1 O(n3):
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool isIncreasing=true;
                int prev=-1;
                for(int k=0;k<i;k++){
                    if(prev!=-1 && nums[k]<=prev){
                        isIncreasing=false;
                        break;
                    }
                    prev=nums[k];
                }
                for(int k=j+1;k<n && isIncreasing; k++){
                    if(prev!=-1 && nums[k]<=prev){
                        isIncreasing=false;
                        break;
                    }
                    prev=nums[k];
                }
                if(isIncreasing) cnt++;
            }
        }
        return cnt;
    }
};

//APPROACH 2 O(nlogn):
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        while(j>0 && nums[j-1]<nums[j]) j--;
        //if j==0 it means the array is sorted
        if(j==0) return (n*(n+1))/2;

        int ans=n-j+1;
        int last=-1;
        for(int i=0; nums[i]>last; last=nums[i], i++){
            ans+=n-(upper_bound(nums.begin()+j, nums.end(), nums[i])-nums.begin())+1;
        }
        return ans;
    }
};
