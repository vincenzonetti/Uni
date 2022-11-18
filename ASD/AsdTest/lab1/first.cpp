#include<iostream>
#include<fstream>

using namespace std;
int main(int argc, char ** argv){
	int n;
	ifstream in("input.txt");
	in>>n;
	int * v = new int;
	for(int i=0;i<n;i++){
		in>>v[i];
		cout<<v[i]<<" ";
	}
	cout<<endl;
		for(int i=0;i<n;i++){
		in>>v[i];
		cout<<v[i]<<" ";
	}	
	
	return 0;
}
