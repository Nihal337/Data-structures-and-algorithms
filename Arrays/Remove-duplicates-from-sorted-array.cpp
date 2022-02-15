
// brute force : using hashing 
// tc = o(n)
// sc = o(n)


//optimised
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n= nums.size() ;
     
        // Two pointer approach
        // in-place
        
    int left = 0 ; // point to unique elements 
        int it = 0 ; // iterator
        
        for(int it=0 ;it<n-1 ;it++) {
            
            // check if current guy and next guy are different or not
            // if different -> update left and move left to next index
            
            if(nums[it] != nums[it+1]) // if different
            {
             nums[left++] = nums[it] ;// update and move left 
            }
        }
        nums[left++] = nums[n-1] ; 
        
        return left ;
    }
};
