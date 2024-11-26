const int N = 1e7+9, M = 1e9+7;

// (b^p)%m  in O( log p )
ll fp(ll b, ll p, ll m = M) {
    if (!p) return 1;
    auto res = fp(b, p / 2, m);
    res = res * res % m;
    if (p % 2) res = res * (b % m) % m;
    return res;
}

// (x^-1) in O( log mod )
ll inv_mod(ll x, ll mod = M) {
    return fp(x, mod - 2, mod);
}

// all factorials in O(N)
ll fact[N], inv_fact[N];
void pre(){
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % M;
    inv_fact[N - 1] = inv_mod(fact[N - 1]);
    for (ll i = N - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % M;
}

// nCr in O( 1 ) after precomputation
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * inv_fact[n - r] % M * inv_fact[r] % M;
}

// nPr in O( 1 ) after precomputation
ll nPr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * inv_fact[n - r] % M;
}
