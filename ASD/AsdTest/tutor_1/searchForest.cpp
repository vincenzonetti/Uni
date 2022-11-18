#include<iostream>
#include <stdlib.h>
using namespace std;
int searchForest(int ** mat, int n);
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int dfs(int ** mat, int i,int j, int n);
int main(int argc, char ** argv){
    int n=4;
    int ** mat = new int*[n];
    for(int i=0;i<n;i++){
            mat[i]=new int;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           mat[i][j]=rand()%2; 
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int x=searchForest(mat, n);
    cout<<x<<endl;
    return 0;
}

int searchForest(int ** mat, int n){
    int maxSoFar=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
            maxSoFar=max(maxSoFar,dfs(mat,i,j,n));
            }
        }
    }
    return maxSoFar; 
}


int dfs(int ** mat, int i,int j, int n){
    if(i<n && i>= 0 &&  j<n && j>= 0 && mat[i][j]==1){
            mat[i][j]=0;
           return 1+dfs(mat,i-1,j,n)+dfs(mat,i+1,j,n)+dfs(mat,i,j-1,n)+dfs(mat,i,j+1,n); 

    }else{
    return 0;
    }

}
