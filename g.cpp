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

int target;
int ans;
vector<vector<bool> > memo;

int len_in(string s, int begin){
    int cnt=1;
    for(int i=begin+1;i<s.size();i++){
        if(s[i]=='(')cnt++;
        if(s[i]==')')cnt--;
        if(cnt==0)return i;
    }
    return 0;
}
int rlen_in(string s, int end){
    int cnt=1;
    for(int i=end-1;i>=0;i--){
        if(s[i]==')')cnt++;
        if(s[i]=='(')cnt--;
        if(cnt==0)return end-i;
    }
    return 0;
}
int fst(string s, char c, int begin, int end){
    for(int i=begin;i<=end;i++){
        if(s[i]=='(')i = len_in(s,i);
        if(s[i]==c)return i;
    }
    return -1;
}
int eval(string s, int begin, int end){
    int index=-1;
    int l,r;
    if((index = fst(s, '+', begin, end)) != -1){
        l = eval(s,begin,index-1);
        r = eval(s,index+1,end);
        return l + r;
    }else if((index = fst(s, '*', begin, end)) != -1){
        l = eval(s,begin,index-1);
        r = eval(s,index+1,end);
        return l * r;
    }else if(s[begin]=='(' && s[end]==')'){
        return eval(s, begin+1, end-1);
    }else{
        int num = s[begin] - '0';
        return num;
    }
}
int check(string s, int begin, int end){
    if(s[begin]=='(' && end==len_in(s,begin)){
        return 3;
    }else if(s[begin]=='(' && s[end]==')'){
        return 4;
    }
    if(begin==end)return 5;
    if(s[end]  ==')')return 2;
    if(s[begin]=='(')return 1;
    else return 0;
}
void rec(string s, int begin, int end){
    if(!memo[begin][end]){
        int e = eval(s, begin, end);
        if(e == target)ans++;
        int c = check(s, begin, end);
        if(c==0){
            // num num
            rec(s, begin, end-2);
            rec(s, begin+2, end);
        }else if(c==1){
            // ( num
            rec(s, begin, end-2);
            rec(s, len_in(s,begin)+2, end);
        }else if(c==2){
            // num )
            rec(s, begin, end-rlen_in(s,end)-2);
            rec(s, begin+2, end);
        }else if(c==3){
            // ( )
            rec(s, begin+1, end-1);
        }else if(c==4){
            // ( ) + ( )
            rec(s, begin, end-rlen_in(s,end)-2);
            rec(s, len_in(s,begin)+2, end);
        }
        memo[begin][end] = true;
    }
}
int main(){
    string str;
    while(cin >> target,target!=0){
        cin >> str;
        int ss = str.size();
        ans = 0;
        memo = vector<vector<bool> >(ss, vector<bool>(ss, false));
        rec(str,0,ss-1);
        cout << ans << endl;
    }
}
