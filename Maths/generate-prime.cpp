

 // Generating Primes
 
 // APPROACH 1 : TC : O(N) 
  
        bool isPrime(int n) {
        	
        	if(n==1) return false ;
        	for(int i=2 ;i<n ;i++) {
        		if(n%i==0) return false ;
        	}
        	return true ;
        }
        
  ----------------------------------------------------------------
  
 APPROACH 2 : TC : O(Square root of N)
         bool isPrime(int n) {
         
         if(n==1) return false ;
         for(int i=2 ;i*i<=n ;i++) {
               if(n%i==0) return false ;
          }
          return true ;
         }
 -----------------------------------------------------------------    
 APPROACH  3 : Sieve of Erathosthenes

// The basic logic of sieve is for each number , we iterate through all its 
// factors which are less than equal to N in NlogN time complexity.

// TC : NlogN

// steps :

// 1) 	// make all numbers one that means intially we consider all numbers 1 to N
	      // are prime
// 2) 	// now we will iterate over each number and if that num is prime , then
	// we will make all its multiple as non-prime( why ? -> definition of prime).

int primes[maxn] ;

void sieve() {
	

	for(int i=0 ;i<=maxn ;i++) primes[i] = 1 ;
	
	primes[0] = 0 ;
	primes[1] = 0 ;
	

	
	for(int i=2 ;i<=maxn ;i++) {
		
		if(primes[i] == 1) {
			   for(int j = i*i ;j <= maxn ;j += i) {
			   	       primes[j] = 0 ;
			   }
			   if(i*i > maxn) break ;
		}
	}
}

