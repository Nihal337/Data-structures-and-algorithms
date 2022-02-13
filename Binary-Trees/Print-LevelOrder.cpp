  











//  Print Level Order (BFS)


 void PrintLevelOrder(Node*root) { 

     //iteratively
     // i cannot traverse breadth wise using recursion
    //  recursion will lead to what we call depth wise search but i dont want ,i want       
        // breadth wise 

     // so i will use data structure Queue for Two reasons(advantages) :
     //1) it will store the node that been marked
     //2) it will help to maintain the fifo ordering, nodes which are in earlier level from
     //them we can go nodes which are at later level.

     queue<Node*>q ;
     q.push(root) ;
     q.push(NULL) ;

     while(!q.empty()) {

         Node* temp = q.front() ;
         if(temp==NULL) {
             cout<<endl ;
             q.pop() ;
             
             //insert a new null for the next level
             if(!q.empty()) q.push(NULL) ;
         }
         else {
             cout<<temp->data ;
             q.pop() ;

             if(temp->left)
             q.push(temp->left) ;
             if(temp->right)
             q.push(temp->right) ;
         }
     }
return ;
     

 }
