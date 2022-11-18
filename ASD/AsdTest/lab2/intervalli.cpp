#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

void printPair(vector<pair<int,int>> v);
void mergeSort(vector<pair<int,int>> & v, int start, int end);
void merge(vector <pair<int,int>> & A, int start, int mid,int end);
pair<int,int> getPair(vector<pair<int,int>> v);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in>>n;
  vector <pair<int, int>> A (n);
  for(int i=0;i<n;i++){
    in>>A[i].first;
    in>>A[i].second;
  } 
  mergeSort(A, 0,A.size()-1);
  pair <int,int> res= getPair(A);
  if(res.first==0 && res.second==0){
    out<<0;
  }else{
    out<<res.first <<" "<< res.second;
  }
  in.close();
  out.close();
}
pair<int,int> getPair(vector<pair<int,int>> v){
    pair<int,int> res;
    int last=v[0].second;
    int diff=0;
    for(int i=1;i<(int)v.size();i++){
      if(v[i].first>last && (v[i].first-last)>diff){
         res.first=last; res.second=v[i].first; 
         diff=v[i].first-last;
        last=v[i].second;
      }else if(v[i].second>last){
          last=v[i].second;
      }
    }
    if(diff==0 && v[0].first!=1){
      res.first=1; res.second=v[0].first;
    }
    if(diff==0){
    res.first=0;res.second=0;
    }
    return res;
}
void printPair(vector<pair<int,int>> v){
  for(int i=0;i<(int)v.size();i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
  }
}
void mergeSort(vector<pair<int,int>> & v, int start, int end){
	if(start<end){
		int mid=(start+end)/2;
		mergeSort(v,start,mid);
		mergeSort(v,mid+1,end);
		merge(v,start,mid,end);
	}
};

void merge(vector <pair<int,int>> & A, int start, int mid,int end){
    pair<int,int> B[end-start];
    int i=start,k=0,j=mid+1;
    while(i <= mid && j<=end){
        if(A[i].first< A[j].first){
           B[k]=A[i];
           i++;
        }else{
            B[k]=A[j];
            j++;
        }
        k++;
    }
    for(int h=i;h<=mid;h++){
        B[k]=A[h];
        k++;
    } 
    for(int h=j;h<=end;h++){
        B[k]=A[h];
        k++;
    } 
    for(k=start;k<=end;k++){
       A[k]=B[k-start];
   }
   
}
