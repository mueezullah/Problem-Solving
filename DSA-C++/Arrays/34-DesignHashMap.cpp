// class MyHashMap {
// public:
//     // APPROACH 1
//     // TC -> O(1)
//     // SC -> O(n), n = 10^6
//     vector<int> vec;
//     MyHashMap() {
//         vec.resize(1000001, -1);
//     }
    
//     void put(int key, int value) {
//         vec[key] = value;
//     }
    
//     int get(int key) {
//         return vec[key];
//     }
    
//     void remove(int key) {
//         vec[key] = -1;
//     }
// };

class MyHashMap {
public:
    // APPROACH 2
    // TC -> O(1)
    // SC -> O(k), k no of keys inserted
    vector<list<pair<int, int>>> bucket;
    int size = 1007;
    
    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {

        int bucketNo = key % size;
        auto &chain = bucket[bucketNo];

        // update if key already exists
        for(auto &it : chain){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        // insert new at the end if key not exists
        chain.emplace_back(key, value);
    }
    
    int get(int key) {

        int bucketNo = key % size;
        auto &chain = bucket[bucketNo];

        if(chain.empty()){
            return -1;
        }

        for(auto &it : chain){
            if(it.first == key){
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int bucketNo = key % size;
        auto &chain = bucket[bucketNo];

        for(auto it = chain.begin(); it != chain.end(); it++){
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */