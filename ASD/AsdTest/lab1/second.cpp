#include<iostream>
#include<fstream>

using namespace std;
int main(int argc, char ** argv){	
	int buffer,n;
	int sum=0;
	int maxsum=0;
	ifstream f("input.txt");
	f>>n;

	for(int i=0;i<n;i++){
			f>>buffer;
			if(i==0){
				sum=buffer;
				maxsum=sum;
			}else if(buffer>sum && sum<0){
				sum=buffer;
				maxsum=sum;
			}else if(buffer+sum>0){
			sum+=buffer;
				//cout<<sum<<endl;
			if(sum>maxsum){
				maxsum=sum;
			}			
			}else{
				sum=0;
			}

	}
	f.close();
	ofstream o("output.txt");
	o<< maxsum <<endl;
	return 0;
}
