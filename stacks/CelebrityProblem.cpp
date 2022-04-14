class Solution 
{
    public:
     bool doKnows(vector<vector<int> >M,int a,int b) {
         return M[a][b] ==1 ; // means a knows b
     }
       // TWo Things : 1) celebrity knows noone i.e its row will be all 0. 
                       //2) everybody know the celeb 
 
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1 ) 
        // put all people in stack
        stack<int>st ; // stack of potential candidates 
        for(int i=0 ;i<n ;i++) {
            st.push(i) ;
        }
        
        // pop out two guys from stacks Lets say a and b
        // case 1 ) if a knows b then that means a can never be celeb so put b back to stack
        // case 2 ) else if b knows a then that means b can never be celeb so put a back to stack
        
         while(st.size()>1) {
             
             int a = st.top() ;
                     st.pop() ;
                     
            int b = st.top() ;
                    st.pop() ;
        
        // case 1  a knows b
           if(doKnows(M,a,b)) {
                st.push(b) ;
           }
           else  {
               st.push(a) ;
           }
         }
          
          int candidate = st.top() ;
        // now stack will contains only one candidate 
        // so that candidate may or may not be a celeb
        
        // so now we will check above Two things i wrote at the top
           bool rowCheck = false ;
           bool colCheck = false ;
           int countrow = 0 ;
           int countcol = 0 ;
           
           for(int i=0 ;i<n ;i++) {
                 if(M[candidate][i]==0) countrow++ ;
                 if(M[i][candidate]==1) countcol++ ;
           }
           
           if(countrow==n) rowCheck = true ;
           else return -1 ;
           if(countcol==n-1) colCheck = true ;
           else return -1 ;
           
           if(rowCheck and colCheck) return candidate ;
           else return -1 ;
        
    }
};



// without using stack

TC : O(N) SC : O(1)

class Solution 
{
    
    public:
    bool knows(int a,int b,vector<vector<int>>&M) {
        if(M[a][b] == 1)  return true ;
        else return false ;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       // compare and eliminate the one that is not celebrity 
       
       // lets say 0th student can be a celeb
       int candidate = 0 ;
       // compare with each student and update the val of candidate
       for(int j=1 ;j<n ;j++) {
           
           if(knows(candidate,j,M)) {
               candidate = j ;// candidate knows j that means 0 can not be a celeb , hence updated it
           }
       }
       // after the loop the candidate may or may not be a celeb 
       
       // I will Check  candidate with each  perseon
       // if my candidate knows anyone or noone knows candidate then candidate cannot be a celeb 
    //   cout<<candidate<<endl ;
      for(int k=0 ;k<n ;k++) {
           
          if(candidate==k) continue ;
          if(knows(candidate,k,M) || !knows(k,candidate,M)) return -1 ;
        
      }
      return candidate ;
       
    }
};


  // } Driver Code Ends

