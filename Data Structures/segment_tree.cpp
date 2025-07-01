#include <vector>
using namespace std;
struct seg {
    struct node {
        int s;
    };

    int n;
    vector<node> tree;

    node skip{};

    seg(int n) {
        this->n = n++;
        tree.assign(n << 2, skip);
    }

    node mrg(node &a, node &b) {
        return {a.s + b.s};
    }

    void upd(int i, int l, int r, int idx, int x) {
        if (l == r) {
            tree[i] = {x};
            return;
        }
        int mid = l + r >> 1;
        if (idx <= mid)
            upd(i << 1, l, mid, idx, x);
        else
            upd(i << 1 | 1, mid + 1, r, idx, x);
        tree[i] = mrg(tree[i << 1], tree[i << 1 | 1]);
    }

    node qry(int i, int l, int r, int lx, int rx) {
        if (r < lx || l > rx)
            return skip;
        if (r <= rx && l >= lx)
            return tree[i];
        int mid = l + r >> 1;
        auto ql = qry(i << 1, l, mid, lx, rx);
        auto qr = qry(i << 1 | 1, mid + 1, r, lx, rx);
        return mrg(ql, qr);
    }
};