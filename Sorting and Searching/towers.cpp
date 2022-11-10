#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>tops;
int main(){
    int n;
    int cube;
    int count=0;
    cin>>n;
    cin>>cube;
    tops.push_back(cube);
    count+=1;
    for(int i=1;i<n;i++){
        cin>>cube;
        int left=0;
        int right=tops.size();
        while (left<right)
        {
            int mid=(left+right) /2;
            if(tops[mid]>cube){
                right=mid;
            }
            else{
                left=mid+1;
            }     
        }
        if(right==tops.size()){
            tops.push_back(cube);
        }
        else{
            tops[left]=cube;
        }   
    }  
    cout<<tops.size();
    return 0;
}