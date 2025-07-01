#include <vector>
using namespace std;

struct lazy_seg {
    struct node {
        int s;
    };

    int n;
    vector<node> tree;
    vector<node> lazy;
    node skip{};


    lazy_seg(int n) {
        this->n = n++;
        tree.resize(n << 2);
        lazy.resize(n << 2);
    }

    node mrg(node &a, node &b) {
        return {a.s + b.s};
    }

    void prp(int i, int l, int r) {
        if (l != r) {
            lazy[i << 1].s += lazy[i].s;
            lazy[i << 1 | 1].s += lazy[i].s;
        }
        tree[i].s += (r - l + 1) * lazy[i].s;
        lazy[i] = {};
    }

    void upd(int i, int l, int r, int lx, int rx, int x) {
        prp(i, l, r);
        if (r < lx || l > rx)
            return;
        if (r <= rx && l >= lx) {
            lazy[i].s = x;
            prp(i, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(i << 1, l, mid, lx, rx, x);
        upd(i << 1 | 1, mid + 1, r, lx, rx, x);
        tree[i] = mrg(tree[i << 1], tree[i << 1 | 1]);
    }

    node qry(int i, int l, int r, int lx, int rx) {
        prp(i, l, r);
        if (r < lx || l > rx)
            return {};
        if (r <= rx && l >= lx)
            return tree[i];
        int mid = l + r >> 1;
        auto ql = qry(i << 1, l, mid, lx, rx);
        auto qr = qry(i << 1 | 1, mid + 1, r, lx, rx);
        return mrg(ql, qr);
    }
};
