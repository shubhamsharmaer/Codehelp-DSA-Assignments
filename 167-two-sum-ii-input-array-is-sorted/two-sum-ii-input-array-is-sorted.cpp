class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     vector<int> ans;
        int idx1 = 1;  // Start from the first element (0-based index)
        int idx2 = numbers.size();  // Start from the last element

        // Use two-pointer technique
        while (idx1 < idx2) {
        int sum = numbers[idx1 - 1] + numbers[idx2 - 1];
        if(sum == target){
            ans.push_back(idx1);
            ans.push_back(idx2);
            break;
        }
        else if(sum < target){
            idx1++;
        }
        else{
            idx2--;
        }
    }
    return ans;
    }
};