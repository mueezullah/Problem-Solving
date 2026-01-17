class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        //APPROACH 1 (Brute Force)
        // for(int i = 0; i < n; i++){
        //     if(arr[i] == 0){

        //         for(int j = n-1; j > i; j--){
        //             arr[j] = arr[j-1];
        //         }
        //         i++;
        //     }
        // }

        // APPROACH 2 (Extra Space)
        // vector<int> ans;

        // for(int i = 0; i < n; i++){
        //     if(arr[i] != 0){
        //         ans.push_back(arr[i]);   
        //     }
        //     if(arr[i] == 0){
        //         ans.push_back(0);
        //         ans.push_back(0);
        //     }             
        // }
        // for(int i = 0; i < n; i++){
        //     arr[i] = ans[i];
        // }

        // APPROACH 3 (Two Pointer)
        int zeros = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] == 0) zeros++;
        }

        int i = n - 1;
        int j = n + zeros -1;

        while(i != j){  // i < j
            if(j < n){
                arr[j] = arr[i];
            }
            j--;

            if(arr[i] == 0){
                if(j < n){
                    arr[j] = arr[i];
                }
                j--;
            }
            i--;
        }

    }
};