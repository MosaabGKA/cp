#include <vector>
using namespace std;
struct BIT { // Works only one type, either update range query point, or update point query range 
    vector<int> bit;
    BIT(int n) {
        bit.resize(n + 1);
    }
    void add(int i, int x){
        while(i < bit.size()){
            bit[i] += x;
            i += i & -i;
        }
    }
    void add(int l, int r, int x){
        add(l, x);
        add(r + 1, -x);
    }
    int pref(int i){
        int res = 0;
        while (i) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    int sum(int l, int r) {
        return pref(r) - pref(l - 1);
    }
};
