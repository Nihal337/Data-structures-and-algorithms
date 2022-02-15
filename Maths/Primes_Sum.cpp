




bool isPrime(int N) {
    	if(N==1) return false ;
    	
    	for(int i=2 ;i<=N/2 ;i++) {
    		
    		if(N%i==0)
    		return false ; 
    		
    	}
    	return true ;
    }


     string Primes_Sum(int N) {
     	
     	// if N is odd then N = odd + even . bcz odd + odd = even 
     	//even + even = even
     	// since the only even prime no is 2.
     	// so we have N = a + 2  the only option.
     	// so we have to check only  If a is prime or not right.
     	
     	if(N&1) {     // for odd case
     		
     		if(isPrime(N-2)) return "Yes" ;
     		else return "No" ;
     	}
       
     	// Now even case
     	// even = even + even : this case is satisfied by
     	// only 4 as 2 is the only even prime no. 4 = 2 + 2
       
       
     	if(N==4) return "Yes" ;
     	
     	// even = odd + odd case
     	
     	for(int i=3 ;i<=N/2 ;i+=2) {
     		
     		if(isPrime(i)) {
          
     			if(isPrime(N-i))
            
     			return "Yes" ;
     		}
     	}
     	return "No" ;
     	
     	
     	
     }
     
