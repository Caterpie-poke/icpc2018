#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;
void test(){
    char c;
    while(scanf("%c",&c), c!='~'){
        cout << c << ", ";
    }
    cout << '\n';
}
int add(int a,int b){
    cout << a+b << " :add\n";
    return a+b;
}
int sub(int a,int b){
    cout << a-b << " :sub\n";
    return a-b;
}
bool q1(){
    int n,maxValue;
    cin >> n >> maxValue;
    if(n==0 && maxValue==0)return false;
    int value[n];
    int tempValue=0;
    int tempMax=0;
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    for(int top=0;top<n-1;top++){
    for(int i=1;i<n-top;i++){
        tempValue = value[top] + value[top+i];
        if(tempMax < tempValue && tempValue <= maxValue)tempMax=tempValue;
    }
    }
    if(tempMax==0){cout << "NONE" << "\n";return true;}
    cout << tempMax << "\n";return true;
}
bool q2(){
    char c;
    bool check = true;
    stack<char> st;
    st.push('0');
    if(scanf("%c",&c) && c == '.')return false;
    while(c != '.'){
        switch(c){
            case '(':
                st.push('(');break;
            case '[':
                st.push('[');break;
            case ')':
                if(st.top()!='('){check=false;break;}
                st.pop();break;
            case ']':
                if(st.top()!='['){check=false;break;}
                st.pop();break;
            default:
                break;
        }
        scanf("%c",&c);
    }
    cout << (check ? "yes" : "no") << '\n';
    scanf("%c",&c);
    return true;
}
void printArray(int* array){
    cout << "array = {";
    for(int i=0;i<sizeof(array)-2;i++){
        cout << array[i] << ", ";
    }
    cout << "}\n";
}
int func(int count, int current, int* remain){
    int n_l,n_r;
    if(remain[0]!=-1){
        int left = current ^ remain[0];
        int right = current;
        n_l = func(count++,left,remain+1);
        n_r = func(count,right,remain+1);
        if(n_l > n_r)return n_l;
        else return n_r;
    } else {
        if(current==0)return count;
        else return 0;
    }
}
bool q_bento(){
    int n,m;
    cin >> n >> m;
    if(n==0&&m==0)return false;//stop
    int array[n+1];
    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        array[i] = stoi(str,nullptr,2);
    }
    array[n+1]=-1;
    cout << func(0,0,array) << "\n";
    return true;
}
int main()
{
    while(q_bento());
}

