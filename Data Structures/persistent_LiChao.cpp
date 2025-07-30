ll OO = 1e18;

// gets min m*x+c
struct Line {
    ll m, c;

    Line(ll _m, ll _c) : m(_m), c(_c) {
    }

    ll operator()(ll x) {
        return m * x + c;
    }
};

struct node {
    Line ln;
    node *l{}, *r{};

    node(Line _ln): ln(_ln) {
    }
};

void del(node *&rt) {
    if (rt->l)
        del(rt->l);
    if (rt->r)
        del(rt->r);
    delete rt;
    rt = 0;
}

node *copy(node *nd) {
    node *cp = new node(nd->ln);
    cp->l = nd->l ? nd->l : new node({0, OO});
    cp->r = nd->r ? nd->r : new node({0, OO});
    return cp;
}


node *insert(node *rt, ll l, ll r, Line ln) {
    node *cur = copy(rt);
    ll m = l + r >> 1;
    bool lef = ln(l) < cur->ln(l);
    bool mid = ln(m) < cur->ln(m);
    if (mid) swap(cur->ln, ln);
    if (l == r) return cur;
    if (lef != mid) {
        cur->l = insert(cur->l, l, m, ln);
    } else cur->r = insert(cur->r, m + 1, r, ln);
    return cur;
}

ll qry(node *&rt, ll l, ll r, ll x) {
    if (!rt) return OO;
    if (l == r) return rt->ln(x);
    ll m = l + r >> 1;
    if (x <= m)
        return min(rt->ln(x), qry(rt->l, l, m, x));
    if (rt->r)
        return min(rt->ln(x), qry(rt->r, m + 1, r, x));
    return rt->ln(x);
}

node *dp[1000009];
