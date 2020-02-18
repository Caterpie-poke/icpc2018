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

int ans;
int cnt;

int fill_top(vector<int> &team, int val, int n){
    for(int i = 0; i < team.size(); i++){
        if(team[i] == 0 && i!=n){
            team[i] = val;
            return i;
        }
    }
    return 0;
}

int check(vector<int> &team){
    int sum = 0;
    for(int i = 0; i < team.size(); i++){
        sum += team[i];
    }
    int a,b;
    a = sum /10;
    b = sum % 10;
    if(a + b == cnt - 1){
        if(a == cnt/2 && b == cnt/2){
            return 2;
        }else{
            return 0;
        }
    }else{
        if(a > cnt / 2 || b > cnt / 2){
            return 0;
        }else{
            return 1;
        }
    }
}

void rec(vector<vector<int> > &table, int n){
    int c = check(table[n]);
    if(c == 2){
        if(n+1 < cnt){
            rec(table, n+1);
        }else{
            ans ++;
        }
    }else if(c == 1){
        int index = fill_top(table[n], 10, n);
        table[index][n] = 1;
        // for(int i=0;i<cnt;i++)cout << table[n][i] << ", ";
        // cout << endl;
        rec(table, n);
        table[n][index] = 1;
        table[index][n] = 10;
        // for(int i=0;i<cnt;i++)cout << table[n][i] << ", ";
        // cout << endl;
        rec(table, n);
        table[n][index] = 0;
        table[index][n] = 0;
    }
}

int main() {
    while(cin >> cnt && cnt != 0){
        int m;
        ans = 0;
        cin >> m;
        vector<vector<int> > table(cnt, vector<int>(cnt,0));
       for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            table[a-1][b-1] = 10;
            table[b-1][a-1] = 1;
        }
        rec(table, 0);
        cout << ans << endl;
    }
    return 0;
}