class RecentCounter {
public:
    queue<int> qu;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // push in stack
        qu.push(t);
        int count = 0;
        // count the ping
        while(!qu.empty() && qu.front() < t - 3000){
            // qu.top();
            qu.pop();
        }
        return qu.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */