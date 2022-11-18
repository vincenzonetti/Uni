#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

void func(vector<int> v, int & S, int & P);
void func2(vector<int> v, int & S, int & P);
int min(int a,int b){
  if(a<b)return a;
  else return b;
}
int find(vector<int> v, int n);
int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in>>n;
  vector<int> v(n);
  for(int i=0; i<n;i++){
    in>>v[i];
  }
  int S=0,P=0;
  func2(v, S,P); 
  out<<S<<" "<<P;
  in.close();
  out.close();
}

void func2(vector<int> v, int & S, int & P){
  for(int i=0;i<(int)v.size();i++){
    while(v[i]!=i+1){
        int f1=find(v,i+1);
        int f2= find(v,f1+1);
        int temp=v[f1];
        v[f1]=v[f2];
        v[f2]=temp;
        S++;
        P+=v[f1]+v[f2];
    }
  }

}

void func(vector<int> v, int & S, int & P){
  for(int i=0;i<(int)v.size();i++){
    while(v[i]!=i+1){
        int f1=find(v,i+1);
        int f2= find(v,f1+1);
        int temp=v[f1];
        v[f1]=v[f2];
        v[f2]=temp;
        S++;
        P+=v[f1]+v[f2];
    }
  }

}

int find(vector<int> v, int n){
  for(int i=0;i<(int)v.size();i++){
    if(v[i]==n)return i;
  }
  return -1;
}
