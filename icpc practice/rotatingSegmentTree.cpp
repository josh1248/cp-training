#include <bits/stdc++.h>
using namespace std;


struct st {
    long long val, lazy;
    int lo, hi, mid;
    st *lft, *rght;

    void propogate() {
        if (lazy == 0ll) return;
        val += lazy * (hi - lo + 1);
        if (lo != hi) {
            lft->lazy += lazy;
            rght->lazy += lazy;
        }
        lazy = 0ll;
    }

    long long query(int l, int h) {
        propogate();
        if (l <= lo && hi <= h) return val;
        long long res = 0;
        if (l <= mid) res += lft->query(l, h);
        if (mid < h) res += rght->query(l, h);
        return res;
    }

    void update(int l, int h, long long v) {
        propogate();
        if (l <= lo && hi <= h) {
            lazy += v;
            return;
        }
        if (l <= mid) {
            lft->update(l, h, v);
        }
        lft->propogate();
        if (mid < h) rght->update(l, h, v);
        rght->propogate();
        val = lft->val + rght->val;
    }
};

st* init_st(int l, int h) {
    fflush(stdout);
    st* root = new st;
    root->val = root->lazy = 0ll;
    root->lo = l;
    root->hi = h;
    root->mid = (h + l) / 2;
    if (l == h) {
        root->lft = root->rght = nullptr;
        return root;
    }
    st *lph = init_st(l, root->mid), *rph = init_st(root->mid+1, h);
    root->lft = lph;
    root->rght = rph;
    return root;
}


int main() {
    int n, q, rot = -1;
    scanf("%d %d", &n, &q);
    st *r = init_st(0, n-1);
    for (int i = 0; i < q; ++i) {
        int op, s, e, v;
        scanf("%d", &op);
        switch (op) {
        case 1:
            scanf("%d", &v);
            rot += v;
            break;
        case 2:
            scanf("%d %d %d", &s, &e, &v);
            s = (s + rot) % n; e = (e + rot) % n;
            if (s <= e) {
                r->update(s, e, v);
            }
            else r->update(s, n, v), r->update(0, e, v);
            break;
        case 3:
            scanf("%d %d", &s, &e);
            s = (s + rot) % n; e = (e + rot) % n;
            if (s <= e) printf("%lld\n", r->query(s, e));
            else printf("%lld\n", r->query(s, n) + r->query(0, e));
            break;
        default:
            return 1;
        }
    }
}
