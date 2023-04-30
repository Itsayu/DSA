class Solution {
public:
    vector<int> repa,repb;
    vector<int> sza,szb;
    //for alice
    int roota(int x){
        if(x==repa[x]){return x;}
        return repa[x]=roota(repa[x]);
    }
    //for bob
    int rootb(int x){
        if(x==repb[x]){return x;}
        return repb[x]=rootb(repb[x]);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& ar) {
        //initializing stuff
        //repa for alice and repb for bob
        //sza for alice and szb for bob
        
        repa.resize(n);
        sza.resize(n);
        repb.resize(n);
        szb.resize(n);
        //init 
        int xx=ar.size(); // useless edges
        int x=0;//useful edges
        for(int i=0;i<n;i++){
            repa[i]=repb[i]=i;
            sza[i]=szb[i]=1;
        }
        for(auto it:ar){
            if(it[0]==3){
                int a=it[1],b=it[2];
                a--;b--;
                a=roota(a);
                b=roota(b);
                if(a==b){continue;}
                //useful edge spotted
                x++;
                xx--;
                if(sza[a]<sza[b]){
                    swap(a,b);
                }
                //updating values
                sza[a]+=sza[b];
                repa[b]=a;
            }
        }
        
        //copying values for bob as well as common edges graph has been generated and will
        //be same for all
        repb=repa;
        szb=sza;
        //useful edges till now for both Alcie and Bob
        int xa=x;
        int xb=x;
        for(auto it:ar){
            if(it[0]==3){continue;}
            if(it[0]==1){
                //Alice graph update only
                int a=it[1],b=it[2];
                a--;b--;
                a=roota(a);
                b=roota(b);
                if(a==b){continue;}
                //useful edge for alice
                xa++;
                xx--;
                if(sza[a]<sza[b]){swap(a,b);}
                repa[b]=a;
                sza[a]+=sza[b];
            }
            else{
                //Bob graph update only
                int a=it[1],b=it[2];
                a--;b--;
                a=rootb(a);
                b=rootb(b);
                if(a==b){continue;}
                //useful edge for bob
                xb++;xx--;
                if(szb[a]<szb[b]){swap(a,b);}
                repb[b]=a;
                szb[a]+=szb[b];
            }
        }
        if(xa == n-1 && xb == n-1){
            //both graphs good and well connected 
            true;
        }
        else{
            xx=-1;
        }
        return xx;
    }
};