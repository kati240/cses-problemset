#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int> >movies;
    int a;
    int b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        movies.push_back(make_pair(b,a));
    }
    sort(movies.begin(),movies.end());
    int last_ending_movie_time=0;
    int ans=0;
    for(int i=0;i<n;i++){   // take the movie that ends the earliest
        if(movies[i].second>=last_ending_movie_time){
            ans+=1;
            last_ending_movie_time=movies[i].first;
        }
    }
    printf("%d",ans);

    return 0;
}