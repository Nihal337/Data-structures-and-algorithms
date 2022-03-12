

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// steps :
//  step0)    traverse through the each col and print the data of levels in sorted fashion

// step1)    make a ds to store your data in the form like (think like you have to iterate over the col(x)
//         in the ascending order and at each col,store data of multiple levels in sorted order)

// step2)      traverse(preorder or postorder or levelorder) through the tree i.e 
//            make queue and while(not empty()) and all that stuff😉 and insert the each data in the form  (node,x,y) where x represents col and y represents level.
//            visulialize it for better understanding why i name x=col and for all that.
//             and at each point also store the given data in the ds you made.

// step3)       copy the data from queue to vector of vector.
// step4)          return the vector of vector
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
         map<int,map<int,multiset<int>>>nodes ;
    queue<pair<TreeNode*,pair<int,int>>>todo ; // (node,col,row) 
    todo.push({root,{0,0}}) ; // (root,0 ,0 ) 
    while(!todo.empty()) {
    	auto p = todo.front() ;
    	todo.pop() ;
    	
    	TreeNode*node = p.first ;
    	int x = p.second.first ,y = p.second.second ; // x = col ,y = level
    	
    	nodes[x][y].insert(node->val) ;
    	
    	// if left child exists
    	if(node->left) {
    		todo.push({node->left,{x-1,y+1}}) ;
    	}
    	
    	// if right child exists
    	if(node->right) {
    		todo.push({node->right,{x+1,y+1}}) ;
    	}
    }
    vector<vector<int>>ans ;
    
    for(auto p:nodes) {
    	vector<int>col ;
    	for(auto q: p.second) {
    		col.insert(col.end(),q.second.begin(),q.second.end()) ;
    	}
    	ans.push_back(col) ;
    }
    return ans ;
    }
};
