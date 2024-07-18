//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOcccurance(int nums[], int n, int target) {
        int start = 0;
        int end = n-1;
        int firstOcc = -1;

        while(start <= end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == target) {
            firstOcc = mid;
            end = mid-1;
      // to find last occurance -> start = mid+1;
            }

    else if(target > nums[mid]) start = mid+1;

    else if(target < nums[mid]) end = mid-1;
        }
       return firstOcc;
    }

    int lastOcccurance(int nums[], int n, int target) {
        int start = 0;
        int end = n-1;
        int lastOcc = -1;

          while(start <= end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == target) {
            lastOcc = mid;
            start = mid+1;
    
            }

    else if(target > nums[mid]) start = mid+1;

    else if(target < nums[mid]) end = mid-1;
        }
        return lastOcc;
    }
    
    
	int count(int arr[], int n, int x) {
	   
	    int firstOcc = firstOcccurance(arr,n,x);
	    int lastOcc = lastOcccurance(arr,n,x);
	    
	    if(firstOcc < 0 && lastOcc < 0) return 0;
	    
	    else {
	         int count = (lastOcc-firstOcc) + 1;
	         return count;
	    }

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends