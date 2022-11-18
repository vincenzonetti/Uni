#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};
vector<nodo> grafo;

pair<int,int> solve(int n,int s, int t);
int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N, M, S,T;
  in >> N >> M >> S >> T;
  grafo.resize(N);

  for(int j=0; j<M; j++) {
    int from, to;
    in >> from >> to;
    grafo[from].vic.push_back(to);
  }
pair <int,int> otp=solve(N,S,T);
    out<<otp.first<< " " << otp.second;
  return 0;
}

pair<int,int> solve(int n,int s, int t){
  bool visited [n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }
  queue <pair<int,int>> q;
  q.push({s,0});
  pair <int,int> k;
  int min=-1;
  int occ=0;
  while(!q.empty()){
    k=q.front();
    visited[k.first]=true;
    q.pop();
    for(int i=0;i<(int)grafo[k.first].vic.size();i++){
      if(!visited[grafo[k.first].vic[i]]){
      if(grafo[k.first].vic[i]==t){
        if(k.second+1<min || min==-1){
          min=k.second+1;
          occ=1;
        }else if(k.second+1==min){
          occ++;
        }
      }else{
      q.push({grafo[k.first].vic[i],k.second+1});
        }
      }
    }
  }
  return {min,occ};
}

