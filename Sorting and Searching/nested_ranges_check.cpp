#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

bool sortbycontained(const tuple<int,int,int>&a,const tuple<int,int,int> &b){
    if(get<0>(a)!=get<0>(b)){
        return get<0>(a)<get<0>(b);
    }
    if(get<0>(a)==get<0>(b)){
        return get<1>(a)>get<1>(b);
    }
}
bool sortbycontains(const tuple<int,int,int>&a,const tuple<int,int,int> &b){
    if(get<0>(a)!=get<0>(b)){
        return get<0>(a)>get<0>(b);
    }
    if(get<0>(a)==get<0>(b)){
        return get<1>(a)<get<1>(b);
    }
}
int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int> >arr;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr.push_back(make_tuple(a,b,i));
    }
    
    int contains[n];   // just logic no fancy data structure, when attempting start from the basics and figure out the requirements then 
    sort(arr.begin(),arr.end(),sortbycontains);
    int curr_min_right=2000000000;
    for(int i=0;i<n;i++){
        if(get<1>(arr[i])<curr_min_right){
            contains[get<2>(arr[i])]=0;
            curr_min_right=get<1>(arr[i]);
        }
        else{
             contains[get<2>(arr[i])]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    sort(arr.begin(),arr.end(),sortbycontained);
    int curr_max_right=0;
    int contained[n];
    for(int i=0;i<n;i++){
        if(get<1>(arr[i])>curr_max_right){
            contained[get<2>(arr[i])]=0;
            curr_max_right=get<1>(arr[i]);
        }
        else{
             contained[get<2>(arr[i])]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    return 0;
}