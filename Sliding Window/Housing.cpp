

 Goal : print out the starting and ending index of continuous plots whose sum is = = k
 
 
 Approach 1:  Brute Force    
 - Generate all subarray and find the ans
 
 - TC :  O(N*3)
   
   
   Apporach 2 : same as approach 1 but to find sum of subarray 
   -  we will use Prefix Sum
   
   -   TC : O(N*2)
     
     
     Approach 3 : Using Prefix Sum and Binary Search 
     
     - TC : O(N) + O(NlogN) = O(NlogN)
     
     
     
     
     
     
     
     Final Approach : Using Sliding Window
     
     - TC : O(N)
      
         void PlotsSum(vector<int>&plots,int k) {
		
		            int n= plots.size() ;
      
	            	int i=0,j=0 ,cs = 0 ;
		
	               	while(j<n) {
			
			
	           		// Expanding the Window
	               	cs += plots[j] ;
	                j++ ;
			
		               	// What if sum >k
		               	// contracting the Window
			
		              	while(cs > k and i<j) {
		              		cs -= plots[i] ;
			               	i++ ;
			}
		               	// check if sum == k
		          	if(cs==k) cout<<i<<" "<<j-1<<endl ;
		}
	}
