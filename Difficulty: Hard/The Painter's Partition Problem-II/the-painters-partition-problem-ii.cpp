//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  bool isPossibleSol(int arr[], int n, int painters, long long sol) {
      long long storeSum = 0;
      int k = 1;
      
      for(int i=0; i<n; i++) {
          
          if(arr[i] > sol) return false;
          
          if(storeSum+arr[i] > sol) {
              k++;
              storeSum = arr[i];
              
              if(k > painters)  return false;
          }
          else {
              storeSum += arr[i];
          }
      }
      return true;
  }
  
    long long minTime(int arr[], int n, int k)
    {
        long long start = 0;
        long long end = accumulate(arr, arr+n, 0LL);
        long long ans = -1;
        
        while(start <= end) {
            
            long long mid = start + (end-start)/2;
            
            if(isPossibleSol(arr, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends