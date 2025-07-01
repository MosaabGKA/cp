struct seg {
    struct node {
        node *l{}, *r{};
        int sum{};
    };

    node *rt;

    seg() {
        rt = new node();
    }

    void mrg(node *&left, node *&right, node *&result) {
        *result = {left, right, 0};
        if (left) result->sum += left->sum;
        if (right) result->sum += right->sum;
    }

    void upd(node *&nd, int l, int r, int idx, int x) {
        if (l == r) {
            nd->sum += x;
            return;
        }
        int mid = l + r >> 1;
        if (idx <= mid) {
            if (!nd->l) nd->l = new node();
            upd(nd->l, l, mid, idx, x);
        } else {
            if (!nd->r) nd->r = new node();
            upd(nd->r, mid + 1, r, idx, x);
        }
        mrg(nd->l, nd->r, nd);
    }

    int qry(node *&nd, int l, int r, int lx, int rx) {
        if (l >= lx && r <= rx) return nd->sum;
        if (l > rx || r < lx) return 0;
        int mid = l + r >> 1, q = 0;
        if (nd->l) q += qry(nd->l, l, mid, lx, rx);
        if (nd->r) q += qry(nd->r, mid + 1, r, lx, rx);
        return q;
    }
};
