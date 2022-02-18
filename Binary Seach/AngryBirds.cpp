


  bool canplace(int N,int B,vector<int>&nests,int sep) {
       	    
       	 int birds = 1 ;// no of birds placed currently
       	 int last_location = nests[0] ; // Location of Last placed bird
       	 
       	 //  check for each pos except first that can we place birds at the current place such that  separation
       	 // b/w nests is sep atleast
       	 
       	 for(int i=1 ;i<N ;i++) {
       	 	
       	 	int curr_location = nests[i] ;
       	 	if(curr_location-last_location>=sep) {
       	 		
       	 		birds += 1 ;  // update bird count
       	 		last_location = nests[i] ;// update last location
       	 	}
       	 	if(birds==B) return true ;
       	 }
       	 // not got valid answer
       	 return false ;
       }
  



  int AngryBirds(int N,int B,vector<int>&nests) {
  	
  	        int ans = -1 ;
  	
  	// Binary Search
  	// Intuition of Binary search : think about binary search when you have to maximise or minimiZe your answer.

  	 
  	 // search space -> Distance
  	    int s = 0 ;// minimum distance
  	    int e = nests[N-1]-nests[0] ; // Maximum Distance
  	    
  	    while(s<=e) {
  	    	
  	    	
  	    	int mid = (s+e)/2 ; // separation b/w the nests 
  	    	
  	    	// can i place birds in nest such that separation is mid
  	    	bool canPlace = canplace( N, B,nests,mid) ;
  	    	
  	    	if(canPlace) {
  	    		
  	    	// update my ans
  	    		ans = mid ; 
  	    		
  	        // search for more better ans in the right side.
  	          s  = mid + 1 ;
  	    		
  	    	}
  	    	else {
  	    		
  	    		// check in left of search space.
  	    		
  	    		e=mid -1 ;
  	    		
  	    		
  	    		
  	    	}
  	    	
  	    }
  	    return ans ;
  	    
  	    
  	    
  }
