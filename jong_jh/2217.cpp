#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int T;
    cin>>T;
    vector <int> v(T);
    for(int i = 0 ;i<T;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());


    int w;
    w=v[0] * T;
    for(int i = 1; i<T;i++){
        if(w < v[i] * (T-i) )    
        w = v[i] * (T-i);
    }
    cout<<w;
}