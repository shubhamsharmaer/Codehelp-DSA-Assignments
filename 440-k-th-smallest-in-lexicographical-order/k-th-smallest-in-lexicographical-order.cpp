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
    int countnum(long cur, long next, int& n){
        int countnums = 0;
        while(cur <= n){
            countnums += next - cur;
            cur *= 10;
            next *= 10;
            next = min(next,long(n+1));
        }
        return countnums;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1; // as we have to return k-1 index 0 based index

        while(k > 0){
            int count = countnum(cur, cur+1, n);
            // check if count <= k
            if(count <= k){
                cur++; // go to next
                k -= count; // skipping the elements
            }
            else{
                cur *= 10;
                k -= 1; // go deep in same tree 1 step
                
            }
        }
        return cur;
    }
};