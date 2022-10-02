#include <iostream>

#include <vector>
using namespace std;

int main(){

    


    int n;
    cin>>n;
    vector <vector<int> >ans;
    vector<int> a;
    a.push_back(0);
    vector<int>b;
    b.push_back(1);

    ans.push_back(a);
    ans.push_back(b);
    for(int i=1;i<n;i++){
        vector<vector<int> > temp;
        vector<int> a;
        vector<int> b;
        vector<int> c;

        int j=ans.size();
        for(int k=0;k<j;k++){ // right down left down , repeat
            if(k%2==0){
                a=ans[k];
                a.push_back(0);
                c=a;
                a.pop_back();
                a.push_back(1);
                b=a;
                temp.push_back(c);
                temp.push_back(b);
            }
            else{
                 a=ans[k];
                a.push_back(0);
                c=a;
                a.pop_back();
                a.push_back(1);
                b=a;
                temp.push_back(b);
                temp.push_back(c);

            }

        }
        ans=temp;

    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
 
 


 
    


}