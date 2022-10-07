
// generate factors


// APPROACH 1  : O(N) using loops 
-------------------------------------------
// APPROACH 2 : TC : O(square root of N)
vector<int>factors_list ;
    void factors(int n) {
    	
    	for(int i=1 ;i*i<=n ;i++) {
    		
    		if(n%i==0) {
    			
    			int fact1 = i ;
    			int fact2 = n/i ;
    			factors_list.push_back(i) ;
    			if(fact1 != fact2)factors_list.push_back(n/i) ;
    		}
    	}
    }
 ------------------------------------------------------------------------------------------   
// Approach 3 : using sieve to get the count of factors of each number from 1 to 1e5
   
// method 1 : TC : O(N root N) .
// method 2 : using sieve TC : O(NlogN)

// sieve logic : iterate through all numbers  and for each number , iterate over its multiples
//               increment each of them as that number is one of their factors.

int factors[maxn]  ; // to store count of factots of each number

 void fill_count_factors() {
 	
 	for(int i = 1 ;i<=maxn ;i++) {
 		for(int j = i ;j<=maxn ;j += i) {
 			 factors[j]++ ;
 		}
 	}
 }
