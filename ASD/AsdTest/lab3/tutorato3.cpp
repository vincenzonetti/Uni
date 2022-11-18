

int solve (Graph G){
		Stack s= topSort(G);
		int v[G.size()];
		node t = s.pop();
		int maxSoFar = 0;
		for(int i=0;i<G.size();i++){
			v[i]=0;
		}
		while(!s.empty()){
			if(t.adj == nullptr){
				v[t]=1
			}else{
				int max=0;
				foreach(k in t.adj){
					if(v[k]>max){
						max=k;
					}
				}
				v[t]=max+1;
			}
			if(v[t]>maxSoFar){
				maxSoFar=v[t];
			}
		}
		return maxSoFar;
}
