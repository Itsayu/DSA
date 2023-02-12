class Solution {
public:
    vector<int>size;
     void dfs( vector<vector<int>> &v , int node , int par  = -1 ){
         size[node]  = 1; 
         for( auto it : v[node ] ){
             if( it != par ){
                 dfs( v , it , node );
                 
             }
         }

         if(par != -1 )
             size[par]  += size[node] ; 

     }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n  = roads.size() +1 ;
        size.resize( n +1 , 0  );
        vector<vector<int>>v( n +1 );
    
        for( auto it : roads ){
            int a = it[0];
            int b = it[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs( v , 0 , -1 );
        long long int ans = 0 ;
        for( int i = 1 ; i<n ; ++i ){
            int cnt  = size[i]; 
            ans += 1ll*( (cnt + seats - 1)/seats );
        }
        return ans; 
    }
};