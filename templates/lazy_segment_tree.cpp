struct lazy_seg {
    struct node {
        int s;
    };

    int n;
    vector<node> tree;
    vector<node> lazy;

    seg(int n) {
        this->n = n++;
        tree.resize(n << 2);
        lazy.resize(n << 2);
    }

    node ADD(node &a, node &b) {
        return node(a.s + b.s);
    }

    void prop(int i, int l, int r) {
        if (!lazy[i].s) return;
        if (l != r) {
            if (lazy[i].s < 0) {
                lazy[i << 1] = lazy[i];
                lazy[i << 1 | 1] = lazy[i];
            } else {
                if (lazy[i << 1].s < 0) {
                    lazy[i << 1].s += -lazy[i].s;
                } else {
                    lazy[i << 1].s += lazy[i].s;
                }
                if (lazy[i << 1 | 1].s < 0) {
                    lazy[i << 1 | 1].s += -lazy[i].s;
                } else {
                    lazy[i << 1 | 1].s += lazy[i].s;
                }
            }
        }
        if (lazy[i].s > 0) {
            tree[i].s += (r - l + 1) * lazy[i].s;
        } else {
            tree[i].s = -(r - l + 1) * lazy[i].s;
        }
        lazy[i] = {};
    }

    void upd(int i, int l, int r, int lx, int rx, int x) {
        prop(i, l, r);
        if (r < lx || l > rx)
            return;
        if (r <= rx && l >= lx) {
            lazy[i].s = x;
            prop(i, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(i << 1, l, mid, lx, rx, x);
        upd(i << 1 | 1, mid + 1, r, lx, rx, x);
        tree[i] = ADD(tree[i << 1], tree[i << 1 | 1]);
    }

    node qry(int i, int l, int r, int lx, int rx) {
        prop(i, l, r);
        if (r < lx || l > rx)
            return {};
        if (r <= rx && l >= lx)
            return tree[i];
        int mid = l + r >> 1;
        auto ql = qry(i << 1, l, mid, lx, rx);
        auto qr = qry(i << 1 | 1, mid + 1, r, lx, rx);
        return ADD(ql, qr);
    }
};
