class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low = 0, high = arr.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
