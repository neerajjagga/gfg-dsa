class Solution {
  public:
  
    int lowerbound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int upperbound(vector<int>& arr, int target) {
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
    
    int countFreq(vector<int>& arr, int target) {
        int lb = lowerbound(arr, target);
        
        // if(lb == arr.size() || lb != target) {
        //     return -1;
        // }
        
        int up = upperbound(arr, target);
        
        return up - lb;
    }
};
