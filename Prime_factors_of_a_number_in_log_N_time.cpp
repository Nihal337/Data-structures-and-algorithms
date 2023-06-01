#include<iostream>
using namespace std ;

// to find Prime factors of a number N in log N time .

vector<int>lpf ;

    void sieve() {
      
        lpf.resize(N+1,0) ;
      
        for(long i = 2 ;i<=N ;i++) {
           if(lpf[i] != 0) continue ;
            lpf[i] = i ;
          
            for(long j = i*i ; j<=N ; j+=i) 
                if(lpf[j] == 0) lpf[j] = i ;
            
        }
    }
    
    vector<int> PrimeFactors(int x) {
           vector<int>result ;
           while(x!=1){
               
               int t = lpf[x] ;
               while(x%t == 0) x = x/t ;
               result.push_back(t) ;
           }
        return result ;
    }

int main() {
  
  sieve() ;
  vector<int>p = PrimeFactors(15) ;
  
}
