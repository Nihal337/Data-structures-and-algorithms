


	class segTree {
		
		vector<int>seg ;
		
		public:
		
		segTree(int n)
		{
			seg.resize(4*n+1) ;
			
		}
		
		void build(int ind , int low , int high , vector<int>&arr) 
		{
		     
		     // base case
		      if(low == high) {
		      	   seg[ind] = arr[low] ;
		      	   return ;
		      }
		         
		     
		    
		     int mid = (low+high) >> 1 ;
		     build(2*ind+1 , low , mid , arr);
		     build(2*ind+2 , mid+1,high,arr) ;
		     seg[ind] = min(seg[2*ind+1],seg[2*ind+2]) ;
		   
		}
		
		
		int query(int ind ,int low,int high ,int l,int r) 
		{ 
			
			     // No overlap 
			     if(l > high || low > r) return INT_MAX ; 
			     
			     // Complete Overlap 
			     if(low >= l && high <= r) {
			     	return seg[ind] ;
			     }
			     
			     // Partial Overlap
			     	int mid = (low+high)>>1 ;
			     	int left = query(2*ind+1 ,low ,mid,l,r) ;
			     	int right = query(2*ind+2 ,mid+1 ,high , l,r) ;
			     	
			         return min(left,right) ;
			     	         
		}
		
		void update(int ind , int low ,int high,int i , int val) {
			
			    // base case
			    if(low == high) {
			    	seg[ind] = val ;
			    	return ;
			    }
			    
			   int mid = (low+high) >> 1 ;
			   
			   if(i<=mid) update(2*ind+1 , low,mid,i,val) ;
			   else update(2*ind+2 ,mid+1 , high ,i ,val) ;
			   seg[ind] = min(seg[2*ind+1],seg[2*ind+2]) ;
			    
		}
		
	} ;

void solve() {
		
	   
	    
	   int n = 5 ;
	   vector<int>arr(n) ;
	  for(auto &i : arr) cin>>i ;
	   segTree seg1(n) ;
	   seg1.build(0 , 0 , n-1,arr) ;
	
	   cout<<seg1.query(0,0,n-1,3,4)<<endl ;
}
