// class MyHashSet {
// public:
    // APPRAOCH 1
    // TC -> O(1)
    // SC -> O(n)  Always uses ~1 MB of memory even if you store 2 values. Wasteful. 
//     vector<bool> vec;
//     MyHashSet() {
//         vec.resize(1000001, false);
//     }
    
//     void add(int key) {
//         vec[key] = true;
//     }
    
//     void remove(int key) {
//         vec[key] = false;
//     }
    
//     bool contains(int key) {
//         return vec[key];
//     }
// };

class MyHashSet {
public:
    // APPROACH 2
    // TC -> O(n / m)
    // n = keys inserted so far
    // M = number of buckets
    // SC -> O(n + m)
    // n = space for all inserted keys across all buckets
    // M = space for the bucket array itself (always allocated)
    
    int M; // number of buckets
    vector<vector<int>> bucket;

    int getIdx(int key){
        return key % M;
    }

    MyHashSet() {
        M = 1009;
        bucket = vector<vector<int>>(M);
    }
    
    void add(int key) {
        int idx = getIdx(key);

        auto itr = find(bucket[idx].begin(), bucket[idx].end(), key);

        if(itr == bucket[idx].end()){
            bucket[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getIdx(key);

        auto itr = find(bucket[idx].begin(), bucket[idx].end(), key);
        
        if(itr != bucket[idx].end()){
            bucket[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = getIdx(key);

        auto itr = find(bucket[idx].begin(), bucket[idx].end(), key);

        return itr != bucket[idx].end();
    }
};



/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */