#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
int ff(vector<int> v){
    int s = v.size();
    if(s>2){
        int top;
        if(abs(v[s-1]-v[s-2])<2)top=1;
        else top=0;
        vector<int> v_next =
        return top+ff(v_next);
    } else if(s==1){
        return 0
    } else {
        if(abs(v[0]-v[1])<2)return 1;
        else return 0;
    }
}
void daruma(int n){
    vector<int> w;
    int t;
    for(int i=0;i<n;i++){cin>>t;w.push_back(t);}
    cout << ff(w) << "\n";
}
int main(){
    int n;
    while(cin>>n,n!=0){
        q_daruma(n);
    }
    return 0;
}