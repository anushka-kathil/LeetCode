#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

class Solution {
public:
    vector<int> avoidFlood(vector<int>& arr) {

        int len = arr.size();
        vector<int> res(len , -1);
        unordered_map<int,int> full;
        set<int> dry; 
        bool flood = false;

        for(int i = 0 ; i < len ; i++){
            
            if(arr[i] == 0){
                dry.insert(i);
                continue;
            }

            if(full.find(arr[i]) != full.end()){ 
                int last = full[arr[i]];
                auto it = dry.lower_bound(last);
                
                if(it == dry.end()){ 
                    flood = true;
                    break;
                }

                res[*it] = arr[i];
                dry.erase(it);
            }

            full[arr[i]] = i;
            res[i] = -1;
        }

        if(flood) return {};

        for(int i = 0 ; i < len ; i++){
            if(arr[i] == 0 && res[i] == -1){
                res[i] = 1;
            }
        }

        return res;
    }
};
