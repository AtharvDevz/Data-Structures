int floorSqrt(int n)
{
    // Write your code here.
    int s = 0, e = n, ans;

    while(s <= e){
        int mid = (s + e) / 2 ;
        if((mid*mid) > n){
            e = mid - 1 ;
        }else if((mid*mid) < n){
            s = mid + 1;
            ans = mid ;
        }else{
            return mid;
        }
    }
    return ans;
}