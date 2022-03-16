


// So  What  i will do ?
// ans : so i will do level order traversal or u can say bfs traversal i.e Breadth First Search
// so in every node i will assign some index and each time i will stores the (lastidx -firstidx+1)
// so now question arises how can i assign no to each node ?
// ans : see if i assign like 1
                             // 2 3
                           // 4 5 6 .. like  that then it will be no value right
// so what i will do , since there is relation if u observe and that is 
// if i=parent , then its childs will be 2*i+1 and 2*i+2 

// But again there is a problem and that is each time we are doubling right
// so it may cause integer overflow for high constraints so we have to do something

// so how to solve overflow problems ?
// ans : what will after assigning no in a paricular level 
// i will change the no of each node be like i = i-min_no(in that level)
// so now if u will observe at each level no will be like 0,1,2,3,4 
// hence the problem of integer overflow is solved.


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(!root) return 0 ;
        
        // bfs 
        queue<pair<TreeNode*,int>>q ;
        q.push({root,0}) ;
        long long ans = 0 ;
        while(!q.empty()) {

        int min_no = q.front().second ;
            int size = q.size() ;
             long long firstno,lastno ;
          // traversing the level
            for(int i=0 ;i<size ;i++) {
                long long curr_id = q.front().second ;
                TreeNode* curr_node = q.front().first ;
                q.pop() ;
                
             curr_id  -= min_no ; 
               
            if(i==0)  firstno = curr_id ;
            if(i==size-1) lastno = curr_id ;
                
            if(curr_node->left) q.push({curr_node->left,2*curr_id+1})     ;
            if(curr_node->right) q.push({curr_node->right,2*curr_id+2}) ;    
                
            }
            // cout<<lastno<< " "<<firstno<<endl ;
            ans = max(ans,lastno-firstno+1) ;
        }
      return ans ;  
    }
};
