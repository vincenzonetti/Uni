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

int countNodes(int n);
int notRecCount(bool * visited,int t,int n);
int maxVect(int * v, int n);
int max(int a, int b){
  if(a>b)return a;
  else return b;
}
void printGraph(int n);
int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N, M;
  in >> N >> M;
  grafo.resize(N);

  for(int j=0; j<M; j++) {
    int from, to;
    in >> from >> to;
    grafo[from].vic.push_back(to);

    grafo[to].vic.push_back(from);
  }
 // printGraph(N);
  out<<countNodes(N);
  return 0;
}

int countNodes(int n){
  bool * visited = new bool[n];
 
  int res=-1;
  for(int i=0;i<n;i++){
    for(int i=0;i<n;i++){
      visited[i]=false;
    }
  res=max(res,notRecCount(visited,i,n)); 
  } 
  delete [] visited;
  return res;
}
int notRecCount(bool * visited,int t,int n){
    queue<int> q;
    int vet[n];
    q.push(t);
    for(int i=0;i<n;i++){
      vet[i]=0;
    }
    while(!q.empty()){
        t=q.front();
        visited[t]=true;
        q.pop();
        for(int i=0;i<grafo[t].vic.size();i++){
          if(!visited[grafo[t].vic[i]]){
            visited[grafo[t].vic[i]]=true;
            if(vet[grafo[t].vic[i]]==0 || vet[t]+1<vet[grafo[t].vic[i]]){
            vet[grafo[t].vic[i]]=vet[t]+1;
            }
            q.push(grafo[t].vic[i]);
          }
        }
    }

    return vet[t];
}

void printGraph(int N){
  for(int i=0; i<N; i++) {
    cout << "Nodo " << i << " ha " << grafo[i].vic.size() <<" vicini" << endl;
    for(int v: grafo[i].vic) {
      cout << "  " << v << endl;
    }
  }

  }

int maxVect(int * v, int n){
  int max=v[0];
  for(int i=1;i<n;i++){
      if(v[i]>max) max=v[i];
  }
  return max;
}

