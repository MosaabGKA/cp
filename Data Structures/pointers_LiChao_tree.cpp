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

void insert(node *&rt, ll l, ll r, Line ln) {
    if (!rt) return rt = new node(ln), void();
    if (l == r) {
        if (ln(l) < rt->ln(l))
            rt->ln = ln;
        return;
    }
    ll mid = l + r >> 1;
    if (ln.m < rt->ln.m) swap(rt->ln, ln);
    if (rt->ln(mid) > ln(mid)) {
        swap(rt->ln, ln);
        insert(rt->r, mid + 1, r, ln);
    } else insert(rt->l, l, mid, ln);
}

ll qry(node *&rt, ll l, ll r, ll x) {
    if (l == r) return rt->ln(x);
    ll mid = l + r >> 1;
    if (x <= mid && rt->l)
        return min(rt->ln(x), qry(rt->l, l, mid, x));
    if (rt->r)
        return min(rt->ln(x), qry(rt->r, mid + 1, r, x));
    return rt->ln(x);
}
