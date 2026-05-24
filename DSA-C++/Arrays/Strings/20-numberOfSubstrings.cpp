class Solution {
public:
    int numberOfSubstrings(string s) {
        // APPROACH 1(TLE)
        // TC -> O(n^2)
        // SC -> O(1)
        
        // int n = s.length();
        // int result = 0;

        // for(int i = 0; i < n; i++){

        //     vector<int> freq(3, 0);

        //     for(int j = i; j < n; j++){
                
        //         freq[s[j] - 'a']++;

        //         if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
        //             result++;
        //         }
        //     }
        // }
        // return result;

        // APPROACH 2 (Sliding Window + Two Pointers)
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int result = 0;

        vector<int> freq(3, 0);
        int left = 0, right = 0;

        while(right < n){

            freq[s[right] - 'a']++;
 
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                
                result += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }

            right++;
        }
        return result;
    }
};