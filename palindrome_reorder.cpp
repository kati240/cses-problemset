#include <iostream>
#include <string>
#include<iomanip>

using namespace std;
int main(){
    clock_t start, end;
    start=clock();

    string s;
    getline(cin,s);
    int n=s.length();
    
    int a[26]={0};
    for(int i=0;i<n;i++){
        a[s[i]-'A']+=1;
    }
    int odd_chars=0;
    for(int i=0;i<26;i++){  // at max one, odd times appearing character 
        if(a[i]%2){
            odd_chars+=1;
        }
    }
    if(odd_chars>=2){
        cout<<"NO SOLUTION";
    }
    else{
        string result;
    for (int i = 0; i < 26; i++){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++){
        if(a[i]%2){
            for(int j = 0; j < a[i]; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 25; i >= 0; i--){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }
    cout<<result;

    }

    end=clock();
 double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
 
  
    

    
    //cout<<arr[0];


    return 0;
}