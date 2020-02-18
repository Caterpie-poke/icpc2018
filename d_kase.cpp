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
#define ULL unsigned long long
#define UI unsigned int

LL power(LL x, int n) {
    return n <= 0 ? 1 : x * power(x, n - 1);
}

bool fill(int n, vector<vector<int>> &res, int num) {
    bool isFill = false;
    for (int i = 0; i < n; i++) {
        int wins = 0;
        int loses = 0;
        for (int j = 0; j < n; j++) {
            if (res[i][j] == 1) {
                wins++;
            } else if(res[i][j] == 2) {
                loses++;
            }
        }
        if (wins > num || loses > num) {
            return false;
        }
        if (wins == num) {
            for(int j = 0; j < n; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = 2;
                    res[j][i] = 1;
                    isFill = true;
                }
            }
        } else if (loses == num) {
            for(int j = 0; j < n; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = 1;
                    res[j][i] = 2;
                    isFill = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int wins = 0;
        int loses = 0;
        for (int j = 0; j < n; j++) {
            if (res[j][i] == 1) {
                wins++;
            } else if(res[j][i] == 2) {
                loses++;
            }
        }
        if (wins > num || loses > num) {
            return false;
        }
        if (wins == num) {
            for(int j = 0; j < n; j++) {
                if(res[j][i] == 0) {
                    res[j][i] = 2;
                    res[i][j] = 1;
                    isFill = true;
                }
            }
        } else if (loses == num) {
            for(int j = 0; j < n; j++) {
                if(res[j][i] == 0) {
                    res[j][i] = 1;
                    res[i][j] = 2;
                    isFill = true;
                }
            }
        }
    }
    if (isFill) return fill(n, res, num);
    return true;
}

pair<int, int> getNull(int n, vector<vector<int>> res) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[i][j] == 0) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int rundomFill(int n, vector<vector<int>> &res, int num) {
    int i, j;
    pair<int, int> p = getNull(n, res);
    if(p.first == -1) {
        return 1;
    }

    vector<int> a(n);
    vector<vector<int>> cp(n, a);
    for(int i = 0; i < n; i++) {
        copy(res[i].begin(), res[i].end(), cp[i].begin());
    }

    int sum = 0;

    res[p.first][p.second] = 1;
    res[p.second][p.first] = 2;
    if (fill(n, res, num)) {
        sum += rundomFill(n, res, num);
    }

    cp[p.first][p.second] = 2;
    cp[p.second][p.first] = 1;
    if (fill(n, cp, num)) {
        sum += rundomFill(n, cp, num);
    }

    return sum;
}

int f(int n, vector<vector<int>> &res) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += i;
    }
    if (!fill(n, res, sum / n)) {
        return 0;
    }
    return rundomFill(n, res, sum / n);
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        int m;
        cin >> m;
        vector<int> a(n);
        vector<vector<int>> res(n, a);//0->null, 1->win, 2->lose
        int x, y;
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            res[x-1][y-1] = 1;
            res[y-1][x-1] = 2;
        }
        for(int i = 0; i < n; i++) {
            res[i][i] = 9;
        }
        cout << f(n, res) << endl;
    }
    return 0;
}