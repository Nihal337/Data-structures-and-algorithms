

// TC : O(N) SC : O(N)
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
       
       unordered_map<ll,ll>mp ;
       // {sum,cnt}
       mp[0]++ ;
      
       ll sum = 0 ;
       ll ans =0 ;
      
       for(auto x:arr) {
           sum += x ;
           mp[sum]++ ;
       }
      
       for(auto x:mp) {
           int cnt = x.second ;
           if(cnt>1)  ans += (cnt*(cnt-1))/2 ;
           
       }
       return ans ;
    }
};
