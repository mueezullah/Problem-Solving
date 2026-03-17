class Solution {
public:
    int getMinCount(vector<int>& freq){
        // TC -> O(n^2)
        // SC -> O(1)
        int mini = INT_MAX;

        for(int count : freq){
            if(count != 0){
                mini = min(mini, count);
            }
        }
        return mini;
    }

    int getMaxCount(vector<int>& freq){
        int maxi = 0;

        for(int count : freq){
            if(count != 0){
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }

    int beautySum(string s) {
        int n = s.length(), sum = 0;

        for(int i = 0; i < n; i++){

            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};