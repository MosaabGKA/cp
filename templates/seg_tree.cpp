struct seg {
    struct node {
        int s;
    };

    int n;
    vector<node> tree;

    seg(int n) {
        this->n = n++;
        tree.resize(n << 2);
    }

    node ADD(node &a, node &b) {
        return node(a.s + b.s);
    }

    void upd(int i, int l, int r, int idx, int x) {
        if (l == r) {
            tree[i].s = x;
            return;
        }
        int mid = l + r >> 1;
        if (idx <= mid)
            upd(i << 1, l, mid, idx, x);
        else
            upd(i << 1 | 1, mid + 1, r, idx, x);
        tree[i] = ADD(tree[i << 1], tree[i << 1 | 1]);
    }

    node qry(int i, int l, int r, int lx, int rx) {
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
