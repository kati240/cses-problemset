#include<iostream>
#include <math.h>
using namespace std;
void fn(long long int val,long long int position,long long int len_digits){

    long long int arr[len_digits];
    for(long long int i=0;i<len_digits;i++){
        arr[i]=val%10;
        val/=10;
    }
    cout<<arr[position]<<endl;

}
int main(){
    int q;
    cin>>q;
    while(q--){
        long long int k;
        cin>>k;
        if(k<=9){
            cout<<k<<endl;
        }
        else{
            long long int count=9;
            long long int len_digits=1;
            long long int n=0;
            while(n<k){
                n+=count*len_digits;
                len_digits+=1;
                count*=10;
            }
            len_digits-=1;
            n-=(count/10)*(len_digits);
            n=k-n;
            long long int num=0;
            if(n%len_digits!=0){
                num=((n-(n%len_digits))/len_digits) ;
            }
            else{
                num=((n-(n%len_digits))/len_digits) -1;
            }
            long long int position=0;
            if(n%len_digits!=0){
                position=len_digits-n%len_digits;
            }
            else{
                position=0;
            }
            long long int val=1;
            long long int y=len_digits-1;
            while(y--){
                val=val*10;
            }
            val+=num;
            fn(val,position,len_digits);
        }  
    }
     return 0;
}