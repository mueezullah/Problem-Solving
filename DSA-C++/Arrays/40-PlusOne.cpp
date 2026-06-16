class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        for(int i = n-1; i >= 0; i--){
           int curr = digits[i];

            if(curr < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};