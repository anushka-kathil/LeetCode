struct packet{
    int src, dst, ts;
    packet(int source, int destination, long long timestamp){
        this->src = source;
        this->dst = destination;
        this->ts = timestamp;
    }
    string unique_id(){
        return to_string(src)+" "+to_string(dst)+" "+to_string(ts);
    }
};

class Router {
queue<packet> q;
int size;
unordered_set<string> st;
unordered_map<int,deque<int>> destTime;
public:
    Router(int memoryLimit) {
      size = memoryLimit;   
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        packet new_pckt(source,destination,timestamp);
        string newid = new_pckt.unique_id();
        if(st.count(newid)){
            return false;
        }
        st.insert(newid);
        q.push(new_pckt);
        destTime[destination].push_back(timestamp);
        if(q.size()>size){
           packet p = q.front();
           int destination=p.dst;
           q.pop();
           st.erase(p.unique_id());
           destTime[destination].pop_front();
        //    auto &ms = destTime[p.dst];
        //    auto it = ms.find(p.ts);
        //    if(it!=ms.end()) ms.erase(it);
        //    if(ms.empty()) destTime.erase(p.dst);
        }
        return true; 
    }
    
    vector<int> forwardPacket() {
        if(q.size() == 0) return {};
        packet p = q.front();
        q.pop();
        st.erase(p.unique_id());
        destTime[p.dst].pop_front();
        //    auto &ms = destTime[p.dst];
        //    auto it = ms.find(p.ts);
        //    if(it!=ms.end()) ms.erase(it);
        //    if(ms.empty()) destTime.erase(p.dst);

        return {p.src, p.dst, p.ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int start = lower_bound(destTime[destination].begin(),destTime[destination].end(),startTime) - destTime[destination].begin();
        int end = upper_bound(destTime[destination].begin(),destTime[destination].end(),endTime) - destTime[destination].begin();
        if(destTime.find(destination) == destTime.end()) return 0;
        return end - start;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */