const int N = 1e7 + 9, M = 1e9 + 7;

// smallest prime factor of [i]
vector<int> spf(N);
// sieve O( N * log(log(N)) )
void generate_spf() {
    for (int i = 2; i < N; i++)
        if (!spf[i])
            for (int j = i; j < N; j += i)
                if (!spf[j])
                    spf[j] = i;
}

// O( log(x) )
vector<int> prime_factors(int x) {
    vector<int> primes;
    while (x > 1) {
        primes.push_back(spf[x]);
        x /= spf[x];
    }
    return primes;
}

// O( log(x) * log(x) )
set<int> distinct_prime_factors(int x) {
    set<int> primes;
    while (x > 1) {
        primes.insert(spf[x]);
        x /= spf[x];
    }
    return primes;
}

// vector contains divisors of [i] sorted
vector<vector<int> > divisors(N);
// generated O( N * log(N) )
void generate_divisors() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divisors[j].push_back(i);
}

// O( log(min(a,b)) )
ll mygcd(ll a, ll b) {
    return b ? mygcd(b, a % b) : a;
}

// O( log(min(a,b)) )
ll mylcm(ll a, ll b) {
    return a / mygcd(a, b) * b;
}

// (b^p)%M  O( log p )
ll fp(ll b, ll p, ll m = M) {
    if (!p) return 1;
    auto res = fp(b, p / 2, m);
    res = res * res % m;
    if (p % 2) res = res * (b % m) % m;
    return res;
}

// for a*x + b*y = gcd(a,b)
// returns auto [x,y,g]: possible value for x and y and the gcd(a,b)
// O( log(min(a,b)) )
tuple<ll, ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return {1, 0, a};
    auto [y, x, g] = extgcd(b, a % b);
    y -= a / b * x;
    return {x, y, g};
}

// O( sqrt(x) )
bool is_prime(ll x) {
    if (x == 2) return 1;
    if (x < 2 || x % 2 == 0) return 0;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0) return 0;
    return 1;
}

// O( 1 )
bool is_prime_pre(ll x) {
    return spf[x] == x;
}

// O( sqrt(x) ) // not sorted
vector<ll> divs(ll x) {
    vector<ll> d;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            d.push_back(i);
            if (i != x / i)
                d.push_back(x / i);
        }
    }
    return d;
}
