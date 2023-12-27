class DSU {
public:
    vector<int>parent ;
    vector<int>size ;
    DSU(int n) {

       parent.resize(n) ;
       size.resize(n,1) ;
       for(int i = 0 ;i<n ;i++) parent[i] = i ;
    }
    int find(int u) {

        if(parent[u] == u) return u ;
        return parent[u] = find(parent[u]) ;
    }
    void merge(int u , int v) {

        int parent_u = find(u) ;
        int parent_v = find(v) ;

        if(parent_u != parent_v) {

            if(size[parent_u] <= size[parent_v]) {

                  parent[parent_u] = parent_v ;
                  size[parent_v] += size[parent_u] ;
            } else {
                 parent[parent_v] = parent_u ;
                 size[parent_u] += size[parent_v] ;
            }
        }
    }
} ;
