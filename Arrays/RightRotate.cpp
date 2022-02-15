



 // left and right rotate 
    
    // Brute Force Approach 


    void RightRotate(vector<int>&nums,int k) {
    	int n= nums.size() ;
    	while(k--) {
    		int temp = nums[n-1] ;
    		for(int i=n-1 ;i>0 ;i--) {
    			arr[i] = arr[i-1] ;
    			
    		}
    		arr[0] = temp ;
    	}
    } // Time Complexity : O(n*2) 
----------------------------------------------------------------------------------------------    
  
  
    // Observation based optimised approach
    
     // for right rotate , first reverse last k elements and then reverse 
     // the remaining elements 
     // then reverse the whole array
     
     void RightRotate2 (vector<int>&nums,int k) {
     	
     	int n= nums.size() ;
     	
     	// reverse the last k elements
     	reverse(nums.begin()+k,nums.end()) ;
     	
     	// reverse the remaining
     	reverse(nums.begin(),nums.begin()+k) ;
     	
     	// reverse whole
     	reverse(nums.begin(),nums.end()) ;
     	
     } // TC : O(n) ;
