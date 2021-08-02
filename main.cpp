#include <bits/stdc++.h>
using namespace std;

const int mxn=2e5+5;
int SparseTable[mxn][18];
int n;
 
void build(vector<int> &sub){
    for(int i=0;(1<<i)<=n;i++){
        for(int j=1;j<=n;j++){
            if(j+(1<<i)-1>n) break;
            if(i==0){
                SparseTable[j][i]=sub[j];continue;
            }
            SparseTable[j][i]=__gcd(SparseTable[j][i-1],SparseTable[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(int l,int r){
    int w=r-l+1;
    int x=log2(w);
    return __gcd(SparseTable[l][x],SparseTable[r-(1<<x)+1][x]);
}

int main(){
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i]
    }
    build(v);
    // For each query it returns the pre computed value in the range [l,r].
    return 0;
}
