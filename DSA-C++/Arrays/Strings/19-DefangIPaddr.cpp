class Solution {
public:
    string defangIPaddr(string address) {

        // TC -> O(n)
        // SC -> O(n)
        
        string ans;
        for(int i = 0; i < address.length(); i++){
            
            if(address[i] == '.'){
                ans += "[.]";
            }
            else{
                ans += address[i];
            }
        }
        return ans;
    }
};