#include <stack>
using namespace std;
using ll = long long;
struct que {
    stack<ll> l, ql, r, qr;
    void trans(){
        if(r.size()){
            l.push(r.top());
            ql.push(r.top());
            r.pop();
            qr.pop();
        }
        while(r.size()){
            l.push(r.top());
            ql.push(min(ql.top(),r.top()));
            r.pop();
            qr.pop();
        }
    }
    void push(ll x){
        r.push(x);
        qr.push(min(x,qr.size()?qr.top():(ll)9e18));
    }
    void pop(){
        if(l.empty()) trans();
        l.pop();
        ql.pop();
    }
    ll query(){
        return min(l.size()?ql.top():(ll)9e18,r.size()?qr.top():(ll)9e18);
    }
};