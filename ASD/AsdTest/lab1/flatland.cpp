#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	int counter=0;
	in>>n;
	string res("");
	vector<char> v(n);
	vector<int> rv(n);
	int indexRv=0;
	for(int i=0;i<n;i++){
		in>>v[i];
	}
	for(int i=0;i<n-2;i++){
		if(v[i]==v[i+1] && v[i+1]==v[i+2]){
			if(i%2==0){
				rv[indexRv]=i;
				indexRv++;
			}
				}
	}
	for(int i=0;i<n;i++){
		if(!(v[i-1]=='d' || v[i+1]=='s')){
			if(i%2==0){
			counter++;
			res+=to_string(i) + " ";
			rv[indexRv]=i;
			indexRv++;
			}
					}	
	}	
	out<<indexRv<<endl;
	for(int i=0;i<indexRv;i++){
		out<<rv[i]<<" ";
	}
	return 0;
}
