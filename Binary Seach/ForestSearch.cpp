


                 // Brute Force  Appraoch  TC : O(nlogn + n*2) = O(n*2)
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {  
        
          int sum ;
        sort(tree,tree+n) ;
        int maxval = tree[n-1] ;
        for(int i=1 ;i<=maxval ;i++)  {
             sum = 0 ;
            for(int j=0 ;j<n ;j++) {
                   
                  int val  ;
                  if(i>tree[j]) val = 0 ;
                 else val = tree[j]-i ;
                 sum += val ;
            }
            if(sum==k) return i ;
            }
            return -1 ;
            
        }
};

----------------------------------------------------------------------------------------------------------------------


         // Optimized Appraoch Using Binary Search O(nlogn)
//            Think of valid options of of what you want to find to get your search space  

class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {  
        // brute force 
          int sum ;
        sort(tree,tree+n) ;
        int maxval = tree[n-1] ;
        for(int i=1 ;i<=maxval ;i++)  {
             sum = 0 ;
            for(int j=0 ;j<n ;j++) {
                   
                  int val  ;
                  if(i>tree[j]) val = 0 ;
                 else val = tree[j]-i ;
                 sum += val ;
            }
            if(sum==k) return i ;
            }
            return -1 ;
            
        }
        
    
};
