class Solution {
public:
    string frequencySort(string s) {
        // APPROACH 1 (Brute)
        // TC -> O(n log n)
        // SC -> O(1) auxiliary (or O(log n) recursion stack)

        // vector<int> freq(128, 0);

        // for(char i : s){
        //     freq[i]++;
        // }

        // auto comp = [&](char a, char b){
        //     if(freq[a] == freq[b]){
        //         return a < b;
        //     }
        //     return freq[a] > freq[b];
        // };

        // sort(s.begin(), s.end(), comp);

        // return s;

        // APPROACH 2 (Better)
        // TC -> O(n + k log k)
        // SC -> O(k or n) -> n in worst case

        // unordered_map<char, int> freq;
        // for(char i : s) freq[i]++;

        // vector<pair<char, int>> vec(freq.begin(), freq.end());

        // sort(vec.begin(), vec.end(), [&](auto a, auto b){
        //     return a.second > b.second;
        // });

        // string ans = "";
        // for(auto p : vec){
        //     ans.append(p.second, p.first);
        // }
        // return ans;

        // APPROACH 3 (Optimal) Bucket sort
        // TC -> O(n)
        // SC -> O(n)

        vector<int> freq(128, 0);
        for(char i : s) freq[i]++;

        vector<vector<char>> bucket(s.length() + 1);
        for(int i = 0; i < 128; i++){
            if(freq[i] > 0){
                bucket[freq[i]].push_back(char(i));
            }
        }

        string result = "";
        for(int i = s.length(); i > 0; i--){
            for(char c : bucket[i]){
                result.append(i, c);
            }
        }
        return result;
    }
};