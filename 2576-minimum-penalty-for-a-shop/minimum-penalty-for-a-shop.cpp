class Solution {
public:
    int bestClosingTime(string customers) {
        // take 2 var
        int minP = INT_MAX;
        int minHr = INT_MAX;
        int n = customers.length();

    
        vector<int>prefix_N(n+1, 0);
        prefix_N[0] = 0; // at i == 0 before i - 1 there is no 'N'    
        
        vector<int>suffix_Y(n+1, 0);
        suffix_Y[n] = 0; // at i == n after i + 1 there is no 'Y'

        // loop for strings
        for(int i = 1; i <= n; i++){
            if(customers[i - 1] == 'N'){ // YHA MA GALTI KRUGA checking i-1 to 0
                prefix_N[i] = prefix_N[i - 1] + 1;
            }
            else{
                prefix_N[i] = prefix_N[i - 1];
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(customers[i] == 'Y'){
                suffix_Y[i] = suffix_Y[i+1] + 1;
            }
            else{
                suffix_Y[i] = suffix_Y[i+1];
            }
        }

        for(int j = 0; j <= n; j++){
            int tempP = prefix_N[j] + suffix_Y[j];
            cout<<prefix_N[j]<<" ";
            if(tempP < minP){
                minP = tempP;
                minHr = j;
            }
        }
        // EDGE Case j = nth hr
        // int nthHrPenalty = count(begin(customers), end(customers), 'N');
        // if(nthHrPenalty < minP){
            // minHr = n;
        // }
        return minHr;
    }
};