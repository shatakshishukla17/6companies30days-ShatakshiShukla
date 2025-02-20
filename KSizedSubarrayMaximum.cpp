class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // your code here
        int n = arr.size();
        int i = 0, j = 1, maxi = 0;
        vector<int> ans;
        
        while(i < k) {
            if(arr[i] > maxi) maxi = arr[i];
            i++;
        }
        ans.push_back(maxi);
        
        while(i < n) {
            if(arr[j-1]==maxi)
                maxi = *max_element(arr.begin()+j,arr.begin()+i+1);
            else if(arr[i]>maxi) 
                maxi = arr[i];
            ans.push_back(maxi);
            i++; j++;
        }
        
        return ans;
    }
};
