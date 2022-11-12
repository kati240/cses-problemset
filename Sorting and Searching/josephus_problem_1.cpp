#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    arr[n-1]=0;
    int count=0;
    int curr_index=0;
    int temp;
    while(count!=n-1){
        temp=arr[curr_index];
        cout<<temp+1<<" ";
        arr[curr_index]=arr[temp];
        curr_index=arr[temp];
        count+=1;
    }
    cout<<arr[temp]+1;
    return 0;
}