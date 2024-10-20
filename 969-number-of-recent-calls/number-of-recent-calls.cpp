class RecentCounter {
public:
    // implement a Queue
    queue<int> qu;
    RecentCounter() {
    }
    
    int ping(int t) {
        // push in queue
        qu.push(t);
        // pop the [t-3000] element 
        while(!qu.empty() && qu.front() < t - 3000){
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