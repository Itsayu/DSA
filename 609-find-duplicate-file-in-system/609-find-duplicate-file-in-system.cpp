// #include <string.h>
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        string dir;
        string cont;
        string fileName;
        char* FNP;
        const char* deli = " ()";
        
        unordered_map<string, vector<string>> mp;
        for(auto& p: paths){
            char cur[1<<12];
            strcpy(cur, p.c_str());
            dir = strtok(cur, deli);
            FNP = strtok(NULL, deli);
            while(FNP){
                fileName = FNP;
                cont = strtok(NULL, deli);
                mp[cont].emplace_back(dir+"/"+fileName);
                FNP = strtok(NULL, deli);
            }
        }
        
        vector<vector<string>> res;
        for(auto& [key, val]: mp)
            if(val.size() > 1)
                res.emplace_back(val);
        
        return res;   
    }
};