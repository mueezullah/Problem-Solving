class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // APPROACH 1 (sort)
        // TC -> O(n log n)
        // SC -> O(n) unique elements

        // unordered_map<int, int> freq;

        // for(int i : nums){
        //     freq[i]++;
        // }

        // vector<pair<int, int>> items(freq.begin(), freq.end());

        // sort(items.begin(), items.end(), [] (auto &a, auto &b){
        //     return a.second > b.second;
        // });

        // vector<int> ans;
        // for(int i = 0; i < k; i++){
        //     ans.push_back(items[i].first);
        // }

        // return ans;

        // APPROACH 2 (Heap)
        // TC -> O(n log k)
        // SC -> O(n) n = unique elements

        // unordered_map<int, int> freq;
        // for(int i : nums){
        //     freq[i]++;
        // }

        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;

        // for(auto i : freq){
        //     int val = i.first;
        //     int f = i.second;

        //     pq.push({f, val});

        //     if(pq.size() > k){
        //         pq.pop();
        //     }
        // }

        // vector<int> ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }

        // return ans;

        // APPROACH 3 (Bucket Sort)
        // TC -> O(n)
        // SC -> O(n)

        int n = nums.size();

        unordered_map<int, int> freq;
        for(int i : nums){
            freq[i]++;
        }

        vector<vector<int>> bucket(n + 1);

        for(auto i : freq){
            int element = i.first;
            int freqElem = i.second;

            bucket[freqElem].push_back(element);
        }

        vector<int> ans;
        for(int i = n; i > 0; i--){
            
            while(bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return ans;
    }
};