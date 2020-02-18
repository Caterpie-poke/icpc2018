#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<vector>
#include<list>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<array>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned long long
#define UI unsigned int

LL power(LL x, int n) {
    return n <= 0 ? 1 : x * power(x, n - 1);
}

pair<int, int> next(pair<int, int> p, int n) {
    if(p.second == n - 1) {
        if(p.first == n - 2) {
            return make_pair(n, n);
        } else {
            return make_pair(p.first + 1, p.first + 2);
        }
    } else {
        return make_pair(p.first, p.second + 1);
    }
}

#define LEFT 10000.0
#define RIGHT -10000.0
LD root3 = sqrt(3.0);

bool calc(pair<LD, LD> range, pair<int, int> p, int bottom, vector<LD> &memo) {
    int diff = p.second - bottom;
    if (diff < 0) return false;
    if (memo[diff] == -1.0) {
        memo[diff] = ((LD)diff) / root3;
    }
    LD l = p.first - memo[diff];
    LD r = p.first + memo[diff];

    return range.first <= l && r <= range.second;
}

pair<LD, LD> triangle(pair<int, int> a, pair<int, int> b, int bottom, vector<LD> &memo) {
    int adiff = a.second - bottom;
    if (memo[adiff] == -1.0) {
        memo[adiff] = ((LD)adiff) / root3;
    }

    int bdiff = b.second - bottom;
    if (memo[bdiff] == -1.0) {
        memo[bdiff] = ((LD)bdiff) / root3;
    }

    LD l = min((LD)(a.first) - memo[adiff], (LD)(b.first) - memo[bdiff]);
    LD r = max((LD)(b.first) + memo[bdiff], (LD)(a.first) + memo[adiff]);
    return make_pair(l, r);
}

LD length(pair<LD, LD> range) {
    return 3.0 * abs(range.second - range.first);
}

LD f(vector<pair<int, int> > v, int n, int k, vector<LD> &memo, int bUpper) {
    pair<int, int> p(0, 1);
    LD mini = 60000.0;
    while(p.first != n) {
        pair<int, int> a = v[p.first];
        pair<int, int> b = v[p.second];
        int bottom = a.second < b.second ? a.second : b.second;
        if (bottom >= bUpper) {
            p = next(p, n);
            continue;
        }
        pair<LD, LD> range = triangle(a, b, bottom, memo);
        //cout << p.first << " " << p.second << " " << bottom << " " << range.first << " " << range.second;
        int cnt = 0;
        for(pair<int, int> z: v) {
            if (calc(range, z, bottom, memo)){
                cnt++;
                if (cnt == n - k) break;
            }
        }
        if (cnt == n - k) {
            mini = min(mini, length(range));
            //cout << " " << mini;
        }
        //cout << endl;
        p = next(p, n);
    }
    return mini;
}

int main() {
    int n;
    vector<LD> memo(10000, -1.0);
    //int cnt = 1;
    while(cin >> n && n != 0) {
        int k;
        cin >> k;

        vector<int> bs(10000);
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v[i] = make_pair(x, y);
            for(int j = y; j >= 0; j--) {
                if(bs[j] >= n - k) break;
                bs[j]++;
            }
        }
        int i = 0;
        for(;i<10000;i++) {
            if(bs[i] < n - k) {
                break;
            }
        }
        cout << fixed << setprecision(12) << f(v, n, k, memo, i) << endl;
        //cout << cnt << " ";
        //cnt++;
    }
    //cout << endl;
    return 0;
}