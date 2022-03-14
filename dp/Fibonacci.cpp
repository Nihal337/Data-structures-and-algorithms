


    // approach 1 - Recursion 
    int fibo(int n) {
    	
    	// base case                   In this Case 
    	if(n<=1) return n ;         // TC : O(2*N) , SC : O(N)
    	
    	// rec case
    	return fibo(n-1)+fibo(n-2) ;
    }
  --------------------------------------------------------------------------------------------  
    // Now Lets Do using dp
    
    // Appproach 2 - Using Memoization or Top Down dp
     // Top down dp means we will break our problem into subproblem 
     // as in recursion , each time we call and compute the same subproblem again , which 
   // increases the fun call and hence the Time Complexity
   // but in this dp , what we do , we save the each subproblem we solved first time
   // and next time whenever we encounter it  , we use it from dp array in O(1)
  
    int fibo1(int n,vector<int>&dp) {
    	// base case
    	if(n<=1) return n ;
    	
    	// have i solved this subproblem earlier, If yes then give me to use it in O(1)
    	if(dp[n] != -1) return dp[n] ;
    	
    	
    	dp[n] = dp[n-1]+dp[n-2] ; ;
    	
    	return dp[n] ;
    	
    	// TC : O(N) i.e approx N function calls
    	// SC : O(N)(height of tree) + O(N)
    	
    }
 ----------------------------------------------------------------------------------------------------------------------------------   
    // approach 3 : Using Bottom top dp or Tabulation or non recursive dp
    // In this, we start from base case to the required problem
    // we find many subproblem using base case and try to think of some recursive
    // relation
    int Fibo2(int n,vector<int>&dp) {
    	
    	dp[0]=0  ;
    	dp[1] = 1 ;
    	
    	for(int i=2 ;i<=n ;i+++) {
    		dp[i] = dp[i-1] + dp[i-2] ;
    	}
    	
    	return dp[n] ;
    	
    	// TC : O(N)  
    	// SC :  O(N) this space is only bcz of dp array
    	
    	
    }
    ------------------------------------------------------------------------------------------------------------------------------
    // Approach 4 : using bottom top dp with some optimisation by observation
    
    int Fibo3(int n) {
    	
    	int prevofprev = 0  ;
    	int prev = 1 ;
    	int curr ;
    	
    	for(int i=2 ;i<=n ;i++) {
    		curr = prev + prevofprev ;
    		prevofprev = prev ;
    		prev = curr ;
    	}
    	
    	return curr ;
    	
    	// TC :O(N)
    	// SC : O(1)
    	
    	
    }
