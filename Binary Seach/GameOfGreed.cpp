

//  very good question for bs implementation 

 bool DivideCoins(vector<int>&arr,int k,int mincoins) {
        	
        	int curr_Friendcoins = 0 ;
        	int partitions = 0 ;
        	int n= arr.size() ;
        	for(int i=0 ;i<n ;i++) {
        			
        		if(curr_Friendcoins+arr[i] >=mincoins) {
        			
        			curr_Friendcoins = 0 ;
        			partitions++ ;
        		}
        		else{
        			curr_Friendcoins += arr[i] ;
        			
        		}
        		
        	
        		
        	}
        	return partitions>=k ;
        }

 int GetCoins(vector<int>&arr,int k) {
 	
 	int ans = -1 ;
 	
 	int sum = accumulate(arr.begin(),arr.end(),0) ;
 	
 	
 	// Using Binary Search
 	// Goal : To Partition the array in such a way i can get maximum coins.
 	//  or have to  maximise the minimum sum of coins u can get
 	//  or maximise the minimum partition.
 	
 	// Think what Can be the Range of search Space
 	// ask urself : 
 	//  What can be the minimum sum of coins i can get in my partition ? -> that will ur s
 	// Similarly What can be the Maximum Sum Of Coins I can get in my Partition ? -> that will be e   
 	
 	
 	int s= arr[0] ; // smallest element of array
 	int e =  sum ;
 	
 	while(s<=e) {
 		
 		int mid = (s+e)/2 ;
 		
 		
 		//  say : Let me Check is there a way to partition the array so that i can get mid coins.
 		// or can i divide the array into k  parts such that everyone get atleast mid coins 
 		
 		bool flag = DivideCoins(arr,k,mid) ;
 		
 		if(flag) { // Yes I can divide
 			
 			ans = mid ;
 			
 			// Trying to increase my answer
 			 s = mid+1 ;
 			
 			
 		}
 		else { // I can't Divide the Array
 		      
 		      // Check for the other options in left side
 		       e = mid-1 ;
 			
 		}
 		
 		
 		
 	}
 	return ans ;
 	        
 	
 }
	
