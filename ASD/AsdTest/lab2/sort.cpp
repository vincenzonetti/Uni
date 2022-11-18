#include<iostream>
#include<fstream>
#include<cmath>
#include <vector>
using namespace std;
void mergeSort(vector<int> & v, int start, int end);
void merge(vector<int> & v, int start, int mid,int end);
int main(int argc, char ** argv){
	int n;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>n;
	vector <int> v (n);
	for(int i=0;i<n;i++){
		in>>v[i];
	}
	mergeSort(v,0,v.size()-1);
	for(int i=0;i<n;i++){
		out<<v[i]<<" ";	
	}
	return 0;
}
void mergeSort(vector<int> & v, int start, int end){
	if(start<end){
		int mid=(start+end)/2;
		mergeSort(v,start,mid);
		mergeSort(v,mid+1,end);
		merge(v,start,mid,end);
	}
};

void merge(vector<int> & A, int start, int mid,int end){
    int B[end-start];
    int i=start,k=0,j=mid+1;
    while(i <= mid && j<=end){
        if(A[i]< A[j]){
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
