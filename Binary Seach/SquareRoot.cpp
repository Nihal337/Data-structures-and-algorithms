
      // Brute Force : O(squarerootN) 

  
         Using Binary Search
         
         
         Tc : O(logN)
           
           
        float findSquareRoot(int N,int P) {
   	
   	       float ans = 0;
   	 
   	  // Integer Part Using Binary Search
   	   
   	   // Always Remember ,  for Binary Search  Think of two things in the beginning :
   	   
   	   // 1)Think  about the search space or u can say possible options where u will search.
   	   // 2) Your Seach space should be monotonic.
   	   
   	   // here seach space will be {0,1,2------10}
   	   
   	   int s=0 , e= N ;
   	     while(s<=e) {
   	     	
   	     	int mid = (s+e)/2 ;
   	     	
   	     	if(mid*mid==N) {
   	     		ans = mid ;
   	     		break ;
   	     	}
   	     	
   	     	if(mid*mid < N) {
   	     		ans = mid ;
   	     		s = mid+1 ;
   	     		
   	     	}
   	     	else {
   	     		e = mid-1 ;
   	     	}
   	     }
   	     
   	     // for Decimal Parts - Using Linear Search 
   	     
   	        float incre = 0.1 ;
   	        
   	        // Loop for each P decimal places
   	        for(int i=1 ;i<=P ;i++) {
   	        	
   	        	while(ans*ans<=N) {
   	        		ans += incre ;
   	        		
   	        	}
   	        	ans -= incre ;
   	        	incre *= 0.1 ;
   	        }
   	   
   	   return ans ;
   	
   }
   
