class Solution {
public:
        // countnum function ma no of elements find kr rhe ha jo agr k se chote ha 
    // to hum unhe skip kar skte ha
    // LOGIC to countnum(cur, next, n)
    //      take a var countnums = 0
    //      loop cur <= n --> coutnums += next-cur
    //                    --> cur *= 10
    //                    --> next *= 10 then next = min(next, n+1) extra irrelevant nodes ko nhi lena

    // findkthnums fun ma hum check krege ki return count k se bada to nhi ha
    // LOGIC findkthnums(n,k) 
    //   take a cur which stores the curr kth element
    //   then k -= 1 for make 0 base index
    //   loop k > 0
    //          int count = countnum() call
    //          if(count <= k) cur++, k -= count // skipp
    //          else cur *= 10, k -= 1
    // return cur
    int countnums(long cur, long next, int& n){
        // base cond
        int countnum = 0;
        while(cur <= n){
            countnum += next - cur;
            cur *= 10;
            next *= 10;
            next = min(next, long(n+1));
        }
        return countnum;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1; // make it 0 based indexed

        while(k > 0){
            // take int count
            int count = countnums(cur, cur+1, n);
            if(k >= count){
                cur++;
                k -= count;
            }
            else{
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
};