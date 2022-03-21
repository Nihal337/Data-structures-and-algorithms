

class Solution {
public:
    // `Brute force : sort the array and iterate and update the lcs
    // TC : O(NlogN) SC : O(1)
    int longestConsecutive(vector<int>& nums) {
        
         int n = nums.size() ;
        if(n==0) return 0 ;
        if(n==1) return 1 ;
        sort(nums.begin(),nums.end()) ;
        int maxlen = 1 ;
       
        int len = 1 ;
        for(int i=1 ;i<n ;i++) {
            if(nums[i]==nums[i-1]) continue ;
            if(nums[i]-nums[i-1]==1) {
                len++ ;
                maxlen = max(len,maxlen) ;
            }
            else len =1 ;
            
        }
        return maxlen ;
    }
};
------------------------------------------------------------------------------------------
	
	Optimised Approach  :
  Try to visulise in number line 
  think how u can find all subsequences present in array
  
          TC :  O(2n)== O(n)
	  SC : o(n)
  
class Solution {
public:
   
    int longestConsecutive(vector<int>& nums) {
        
       int n = nums.size() ;
        if(n==0) return 0 ;
        unordered_set<int>s(nums.begin(),nums.end()) ;
           int maxlen = 1 ;
            int len = 1 ;
        
        for(auto x:nums) {
            
           int left = x-1 ;
            // check if left of x exists 
            // if Not present that means x is first element of a subsequence
            if(s.count(left)==0) {
                    int val = x ;
                 while(true) {
                     val++;
                     if(s.count(val)) {
                         len++ ;
                         maxlen = max(len,maxlen) ;
                     }
                     else {
                         len =1 ;
                         break ;
                     }
                 }
            }
        }
        return maxlen ;
    }
};
