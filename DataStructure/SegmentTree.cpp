#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename value_t, class merge_t> class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge;     // associative function for SGT
  public:
    explicit SGT(int _n, const merge_t &_merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void modify(int p, const value_t &x) {
        for (t[p += n] = x; p > 1; p >>= 1)
            t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                init = merge(init, t[l++]);
            if (r & 1)
                init = merge(init, t[--r]);
        }
        return init;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q; // N element, Q pairs of (l, r)
    cin >> N >> Q;
    vector<int> v;
    SGT<int, bit_xor<int>> sgt(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        sgt.modify(i, num);
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        // Becareful that if the l given by the problem starts from 1,
        // l should be -1 when passed to query()
        cout << sgt.query(l - 1, r, 0) << "\n";
    }

    return 0;
}
