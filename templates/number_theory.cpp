ll gcd(ll a, ll b) { // O(log max(a,b))
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) { // O(log max(a,b))
    return a / gcd(a, b) * b;
}

ll fp(ll b, ll p, ll m = M) { // O(log p)
    if (!p) return 1;
    auto res = fp(b, p / 2, m);
    res = res * res % m;
    if (p % 2) res = res * (b % m) % m;
    return res;
}

bool is_prime(ll x) { // O(sqrt x)
    bool prime = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            prime = 0;
        }
    }
    return prime;
}

vector<ll> divisors(ll x) { // O(sqrt x)
    vector<ll> divs;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i != x / i)divs.push_back(x / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}
