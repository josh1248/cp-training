const long long BASE_MOD = 998'244'353;
int binpow(int x, int n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = (long long) ans * x % BASE_MOD;
        n >>= 1;
        x = (long long) x * x % BASE_MOD;
    }
    return ans;
}