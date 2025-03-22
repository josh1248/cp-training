
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


// example use: inverse of factorials
// Fermat's little theorem to find multiplicative inverses:
// a^(-1) mod m equals a^(m-2) mod m
long long inv_fact[17];
void populate_inverses() {
    long long fact = 1;
    for (int i = 1; i <= 16; i++) {
        fact *= i;
        inv_fact[i] = binpow(fact, BASE_MOD - 2);
    }
}