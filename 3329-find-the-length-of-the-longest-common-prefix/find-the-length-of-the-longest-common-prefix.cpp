class Solution {
public:
    // make an unordered set ---> insert all val of arr1 then num /= 10
    //                            with for loop and while(num > 0 && !st.count(num)) loop under for 
    // take a for loop for arr2 and check while(num2 > 0 && !st.count(num2)) then num2 /= 10
    //                            if(num2 > 0) then result = max(result, static_cast<int>(log10(num2) + 1))
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // take an unordered set to store arr1
        unordered_set<int> st;
        for(auto num : arr1){
            while(num > 0 && !st.count(num)){
                st.insert(num);
                num /= 10;
                
            }
        }
        int result = 0;
        for(auto num2 : arr2){
            while(!st.count(num2) && num2 > 0){
                num2 /= 10;
            }
            if(num2 > 0){
                result = max(result, static_cast<int>(log10(num2) + 1));
            }
        }
        return result;

    }
};