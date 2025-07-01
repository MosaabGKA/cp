#include <vector>
using namespace std;
struct BIT {
    vector<int> bit;
    BIT(int n){
        bit.resize(n + 2);
    }
    void add(int i, int x){
        i++;
        while(i < bit.size()){
            bit[i] += x;
            i += i & -i;
        }
    }
    void add(int l, int r, int x){
        l++, r++;
        add(l, x);
        add(r + 1, -x);
    }
    int pref(int i){
        i++;
        int res = 0;
        while (i) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    int sum(int l, int r) {
        l++, r++;
        return pref(r) - pref(l-1);
    }
};
