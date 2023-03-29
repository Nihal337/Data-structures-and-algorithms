	#include <bits/stdc++.h>
	using namespace std ;
	#define ll long long int
	#define ld     long double
	#define endll "\n"
	#define pb push_back
	#define ppb pop_back
	#define mp make_pair
	#define ff first
	#define ss second
	#define sz(x) ((int)(x).size())
	#define all(c) c.begin(), c.end()
	#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
	 int mod =1e9+7;
	#define vi                  vector<int>
	#define ps(x,y)             fixed<<setprecision(y)<<x
	#define len(s) s.size() 
	
	#define setbits(x)          __builtin_popcountll(x)
	#define FIO                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
	
	 // 48-57 ->  0-9
	 // 65-90 ->  A-Z
	 // 97-122 -> a-z
	 
	// lower = lower_bound(v.begin(), v.end(), 6) - v.begin();  //first element with value >= 6
	// upper = upper_bound(v.begin(), v.end(), 6) - v.begin();  //first element with value > 6 
	
	// https://usaco.guide/PAPS.pdf#page=99
	// https://usaco.guide/CPH.pdf#page=27
	// https://darrenyao.com/usacobook/cpp.pdf#page=12
	     
	    
	    
	void buildSegmentTree(ll l , ll r , vector<ll>&segTree,ll i,vector<ll>&arr) {
	    	
	    	  
	    	    if(l == r) {
	    	    	
	    	    	segTree[i] = arr[l] ;
	    	    	return ;
	    	    }
	    	    
	    	    ll m = (l+r)/2 ;
	    	    buildSegmentTree(l,m,segTree,2*i+1,arr) ;
	    	    buildSegmentTree(m+1,r,segTree,2*i+2,arr) ;
	    	    
	    	    segTree[i] = min(segTree[2*i+1],segTree[2*i+2]) ;
		    	
	    }
	    
	    void update(ll ind , ll newValue , ll l ,ll r ,vector<ll>&segTree,ll i) {
	    	
	    	  if(l == r) {
	    	  	
	    	  	segTree[i] = newValue ;
	    	  	return ;
	    	  }
	    	  
	    	  ll m = (l+r)/2 ;
	    	  
	    	  if(ind <= m) update(ind ,newValue ,l , m , segTree , 2*i+1) ;
	    	  else update(ind , newValue , m+1 , r ,segTree , 2*i+2) ;
	    	  
	    	  segTree[i] = min(segTree[2*i+1] , segTree[2*i+2]) ;
	    	  
	    }
	    
	    int Query(ll x,ll y , ll l , ll r , vector<ll>&segTree ,ll i) {
	    	
	    	  // No overlapping 
	    	  if(r < x || l > y) return 1e9 ;
	    	  
	    	  // complete overlapping 
	    	  if(l >= x and r <= y) return segTree[i] ;
	    	  
	    	  // partial overlapping 
	    	 ll m = (l+r)/2 ;
	    	 return min(Query(x,y,l,m,segTree,2*i+1) , Query(x,y,m+1,r,segTree,2*i+2)) ;
	    	
	    }
	    
	    
	
   void solve() {
		  	
		  
		  	
		  	ll n,Qu ;
		  	cin>>n>>Qu ;
		  
		  	
		  	vector<ll>arr(n,0),segTree(4*n+1 , 0) ;
		  	for(auto &i : arr) cin>>i ;
		  
		  	buildSegmentTree(0 , n-1 , segTree , 0 , arr) ;
		  	
		  	
		  	while(Qu--) {
		  		
		  		string c ;
		  		ll x,y ;
		  		cin>>c>>x>>y ;
		  		x-- ;
		  		y-- ;
		  		
		  		
		  		
		  		if(c == "q") {
		  			cout<<Query(x,y,0,n-1,segTree,0)<<endl ;
		  			continue ;
		  		}
		  		
		  			
		  			update(x,y,0,n-1 , segTree , 0) ;
		  			
		  		
		  	}
		  
		  		 	  	

		}
	 
 int main() {
	 	
	 	FIO ;
	 	
	 	int t = 1;
	 	// cin>>t ;
	 	while(t--) {
	 		
	 	 solve() ;
	      
	 	}
	 	
	 }
