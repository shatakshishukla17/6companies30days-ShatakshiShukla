class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1(nums); // Create a copy of nums
        sort(nums1.begin(), nums1.end()); // Sort the copy

        int i = (n - 1) / 2; // Midpoint of the sorted array (for smaller elements)
        int j = n - 1;       // End of the sorted array (for larger elements)

        // Fill nums in a wiggle pattern
        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                nums[k] = nums1[i--]; // Take from the first half
            } else {
                nums[k] = nums1[j--]; // Take from the second half
            }
        }
    }
};
