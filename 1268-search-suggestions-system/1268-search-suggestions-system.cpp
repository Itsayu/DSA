class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=searchWord.size();
        vector<vector<string>>res(n);
        sort(products.begin(),products.end());
        int m=products.size();
        for(int i=0;i<m;i++){
            if(products[i][0]==searchWord[0])
                res[0].push_back(products[i]);
        }
        for(int i=1;i<n;i++){
            for(auto x:res[i-1]){
                if(x.size()<=i)
                    continue;
                if(x[i]==searchWord[i])
                    res[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++){
            if(res[i].size()>3)
            res[i].resize(3);
        }
        return res;
    }
};