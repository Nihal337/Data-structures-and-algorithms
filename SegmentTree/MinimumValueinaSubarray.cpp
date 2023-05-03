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
	 ll mod = 1e9+7 ;
	#define vi                  vector<int>
	#define ps(x,y)             fixed<<setprecision(y)<<x
	
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
	//Tree where root is the answer of my problem is segment tree.
	
	
	void buildSegTree(vector<ll>&Tree , vector<ll>&arr , ll l , ll r,ll i) {
		
		// base case
		if(l == r) {
			Tree[i] = arr[l] ;
			return ;
		}
		ll m = l+(r-l)/2 ;
		buildSegTree(Tree , arr ,l , m , 2*i+1 ) ;
		buildSegTree(Tree , arr ,m+1,r , 2*i+2) ;
		Tree[i] = min(Tree[2*i+1] , Tree[2*i+2]) ;
	}
	
	ll query(vector<ll>&Tree , vector<ll>&arr , ll l ,ll r ,ll x, ll y , ll i) {
		
		// no overlapping 
		 if(r < x || l > y) return 1e8 ;
		 
	   // complete overlapping 
	   if(l >= x and r <= y) return Tree[i] ;
	   
	   // partial overlapping then I need to explore both sides
	   ll m = (l+r)/2 ;
	   
	   return min(query(Tree,arr,l,m,x,y,2*i+1),query(Tree,arr,m+1,r,x,y,2*i+2)) ;
		 
	}
	
	void update(vector<ll>&Tree , vector<ll>&arr ,ll l,ll r , ll newVal , ll ind , ll i) {
		
		if(l == r) {
			Tree[i] =  newVal ;
			return ;
		}
		
		ll m = l + (r-l)/2 ;
		if(ind <= m) update(Tree,arr,l,m,newVal,ind,2*i+1) ;
		else update(Tree,arr,m+1,r,newVal,ind,2*i+2) ;
		Tree[i] = min(Tree[2*i+1] , Tree[2*i+2]) ;
	}
	
	
	
	void solve() {
	 
	 ll n , q ;
	 cin>>n>>q ;
	 
	 vector<ll>arr(n) ;
	for(int i = 0 ;i<n ;i++) cin>>arr[i] ; 
	
	  vector<ll>segTree(4*n+1,0) ;
	  
	  buildSegTree(segTree,arr,0,n-1 ,0) ; 
	  
	  while(q--) {
	  	
	  	
	  	string c ;
	  	ll a , b ;
	  	cin>>c>>a>>b ;
	    int l = a-1 , r = b-1 ;
	  	
	  	if(c == "q") cout<<query(segTree,arr,0,n-1,l,r,0)<<endl  ;
	  	else update(segTree,arr,0,n-1,b,a-1,0) ;
	  }
	  
   }
	 
	 int main() {
	 	
	 	FIO ;
	 	
	 	int t =1;
	 	// cin>>t ; 
	 	while(t--) {
	 		
	 	 solve() ;
	      
	 	}	
	 }
