#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
struct cv
{
    int count;
    int value;
    int total;
};
vector<int> w(100);
cv defo = {-1,-1,-1};
vector<vector<vector<cv> > > memo(100,vector<vector<cv> >(100,vector<cv>(500,defo)));
bool equal_struct(cv a,cv b){
    if(a.count==b.count && a.value==b.value && a.total==b.total)return true;
    else return false;
}
int buy(int price){
    price = 1000 - price;
    while(price<0){
        price = 1000 - abs(price);
    }
    return price;
}
cv func(int i, cv m, bool buyed){
    if(m.value>=500 && buyed){
        m.count++;
        m.value-=500;
    }
    if(w[i]==-1){
        return m;
    } else {
        cv m1,m2;
        if(equal_struct(memo[m.count][m.value][m.total], defo)){
            m2 = memo[m.count][m.value][m.total];
        }
        else{
            m2 = func(i+1,m,false);
            memo[m.count][m.value][m.total] = m2;
        }
        m.value+=buy(w[i]);
        m.total+=w[i];
        if(equal_struct(memo[m.count][m.value][m.total], defo)){
            m1 = memo[m.count][m.value][m.total];
        }
        else{
            m1 = func(i+1,m,true);
            memo[m.count][m.value][m.total] = m1;
        }
        if(m1.count>m2.count)return m1;
        else if(m1.count<m2.count)return m2;
        else if(m1.total<=m2.total)return m1;
        else return m2;
    }
}
void q_coin(int n){
    fill(w.begin(),w.end(),-1);
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    cv result = func(0,defo,false);
    cout << result.count << " " << result.total << "\n";
}
int main(){
    int n;
    while(cin >> n,n!=0){
        q_coin(n);
    }
    return 0;
}
