#include<iostream>
#include<iomanip>
#include<vector>


using namespace std;
typedef long long int ll;

int main()
{

    clock_t start, end;
    start=clock();



   unsigned long long int n;
   cin>>n;
   unsigned long long int  ans=1;
   for(int i=0;i<n;i++){  // 2 raised to the power n 
    ans*=2;
    ans=ans%(1000000007);
   }
  




  cout<<ans<<endl;




end=clock();
 double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
 
  
   
  
   

   
  
   return 0;
   }


 
