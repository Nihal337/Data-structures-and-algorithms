

approach 01 :  TC:(No. of Bits of a number)

    int Countingbits(int n) {
      
      int count = 0 ;
      
      while(n>0) {
       count += n&1   ;
        n=n>>1 ;
      }
      return count ;
      
    }

----------------------------------------------
  
  APPROACH 2 : O(No. OF SET BITS)
    
     int Countingbits(int n) {
      
      int count = 0 ;
      
      while(n>0) {
      
         count++ ;
           n= n&(n-1) ;
        
      }
      return count ;
      
    }
