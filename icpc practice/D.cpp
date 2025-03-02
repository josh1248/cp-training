#include <bits/stdc++.h>
using namespace std;
long long fitintomod(long long x) {
    return ((x + 998244353) % 998244353);
}

int swap_around(int x, int arr[3], int also[3]) {
    int phid = -1;
    int toret = 2;
    for (int i = 0; i < 3; ++i) {
        if (arr[i] == x) {
            toret = i;
            continue;
        }
        if (phid == -1) phid = i;
        else {
            int ph = arr[phid];
            int aph = also[phid];
            arr[phid] = arr[i];
            also[phid] = also[i];
            also[i] = aph;
            arr[i] = ph;
            return toret;
        }
    }
    assert(false);
    return -1;
}

int swap_around(int x, int arr[3]) {
    int also[] = {1,1,1};
    return swap_around(x, arr, also);
}
vector<long long> po2; //powers of two



struct st {
    long long val[3]; //given self is index
    int ifparis[3]; // = then self is...
    int lo, hi, mid;
    st *lft, *rght;

    /*void propogate() {
        if (lazy == 0ll) return;
        val += lazy * (hi - lo + 1);
        if (lo != hi) {
            lft->lazy += lazy;
            rght->lazy += lazy;
        }
        lazy = 0ll;
    } //*/

    int gline(int x) {
        if (x < lo) return 0;
        if (x == lo) 
            for (int i = 0; i < 3; ++i) if (ifparis[i] == 0) return i;
        int cline;
        if (x <= mid) lft->gline(x);
        else cline = rght->gline(x);
        for (int i = 0; i < 3; ++i) if (ifparis[i] == cline) return i;
        return -1;
    }

    long long query(int l, int h, int line) {
        //propogate();
        int adjline = ifparis[line];
        if (l <= lo && hi <= h) return val[adjline];
        long long res = 0;
        if (l <= mid) res += lft->query(l, h, adjline);
        res = fitintomod(res);
        if (mid < h) res += rght->query(l, h, adjline);
        return fitintomod(res);
    }

    long long update(int v, int frm, int to) {
        //propogate();
        if (frm == to) return 0;
        assert (v >= lo);
        if (v == lo) {
            swap_around(frm, ifparis);
            swap_around(to, ifparis);
            return 1ll;
        }
        /*if (l <= lo && hi <= h) {
            lazy += v;
            return;
        } //*/
        
        if (v <= mid) {
            lft->update(v, frm, to);
        }
        //lft->propogate();
        else if (v == mid + 1) {
            
        }
        else {
            long long cup = rght->update(v, frm, to);
            
        }
        //rght->propogate();
        for (int i = 0; i < val = lft->val + rght->val;
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
