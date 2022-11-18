#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};

vector<nodo> grafo;

int countNodes(int n,int m,int t);
int notRecCount(bool * visited,int t);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N, M,t;
  in >> N >> M >> t;
  grafo.resize(N);

  for(int j=0; j<M; j++) {
    int from, to;
    in >> from >> to;
    grafo[from].vic.push_back(to);
  }

  out<<countNodes(N,M,t);
  return 0;
}

int countNodes(int n,int m,int t){
  bool * visited = new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }
  int res=notRecCount(visited,t); 
  delete [] visited;
  return res;
}
int notRecCount(bool * visited,int t){
    queue<int> q;
    int res=1;
    q.push(t);
    while(!q.empty()){
        t=q.front();
        visited[t]=true;
        q.pop();
        for(int i=0;i<grafo[t].vic.size();i++){
          if(!visited[grafo[t].vic[i]]){
            visited[grafo[t].vic[i]]=true;
            res++;
            q.push(grafo[t].vic[i]);
          }
        }
    }

    return res;
}

