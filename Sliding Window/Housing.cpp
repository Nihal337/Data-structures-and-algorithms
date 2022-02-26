

 Goal : print out the starting and ending index of continuous plots whose sum is = = k
 
 
 Approach 1:  Brute Force    
 - Generate all subarray and find the ans
 
 - TC :  O(N*3)
   
   
   Apporach 2 : same as approach 1 but to find sum of subarray 
   -  we will use Prefix Sum
   
   -   TC : O(N*2)
     
     
     Approach 3 : Using Prefix Sum and Binary Search 
     
     - TC : O(N) + O(NlogN) = O(NlogN)
     
     
     
     
     
     
     
     Final Approach : Using Sliding Window
     
     - TC : O(N)
