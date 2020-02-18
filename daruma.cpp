#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
map<string, int> mp;
string str(vector<int> v){
    string str = "";
    for(int i=0;i<v.size();i++){
        str = str + to_string(v[i]) + ",";
    }
    return str;
}
int func(vector<int> w){
    int s = w.size();
    if(s>1){
        int temp;
        int min = s;
        for(int i=0;i<s-1;i++){
            vector<int> remain;
            for(int j=0;j<s;j++){
                if(j==i){j+=2;}
                if(j>=s)break;
                remain.push_back(w[j]);
            }
            if(abs(w[i]-w[i+1])<2){
                int memo;
                if(mp[str(remain)]!=0){
                    temp=mp[str(remain)];
                    if(temp==-1)temp++;
                }
                else{
                    temp = func(remain);
                    mp[str(remain)] = temp==0 ? -1 : temp;
                }
                min = min > temp ? temp : min;
            }
            if(min==0)break;
        }
        return min;
    } else {
        return s;
    }
}
void q_daruma(int n){
    vector<int> w;
    int t;
    for(int i=0;i<n;i++){cin>>t;w.push_back(t);}
    cout << w.size()-func(w) << "\n";
}
int main(){
    int n;
    while(cin >> n, n!=0){
        q_daruma(n);
    }
    // q_daruma(n);
    return 0;
}


