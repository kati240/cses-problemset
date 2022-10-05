#include<iostream>
#include<vector>
#include<set>
#include<algorithm> // works without this in my local , but for submission added this for sort function
using namespace std;
vector<string> fn(int n,string s){ // generate all n! permutations,unique and non unique
    if(n==1){                       
        vector<string> temp;
        temp.push_back(s);
        return temp;
    }
    vector<string>temp;
    for(int i=0;i<s.length();i++){
        char a =s[i];    
        vector<string>temp_1;
        string new_string;
        for(int k=0;k<s.length();k++){
            if(k!=i){
                new_string+=s[k];
            }
        }
        temp_1=fn(n-1, new_string);
        for(int j=0;j<temp_1.size();j++){
            temp_1[j]+=a;
            temp.push_back(temp_1[j]);
            
        }
    }
    return temp;
}
int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    int n=s.length();
    vector<string>ans;
    ans=fn(n,s);
    set<string>ans2;
    for(int i=ans.size()-1;i>=0;i--){  // create a set for unique entries 
        ans2.insert(ans[i]);
    }
    cout<<ans2.size()<<"\n";
    for (auto it = ans2.begin(); it != ans2.end(); ++it){
        cout << *it<<"\n";
    }
}