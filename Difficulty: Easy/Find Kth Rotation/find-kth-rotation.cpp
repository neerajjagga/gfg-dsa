class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(mid-1 >= 0 && arr[mid] < arr[mid-1]) return mid;
            else if(mid+1 < n && arr[mid] > arr[mid+1]) return mid + 1;
            else if(arr[low] <= arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        
        return 0;
    }
};
