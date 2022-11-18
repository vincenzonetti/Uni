#include<iostream>
#include<vector>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

int max(int a,int b);
int kdane(vector<int> A);
int maxSubmatrixSum(vector<vector<int> > A);



int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int r,c;
	in>>r;
	in>>c;
	vector<vector<int>> A(r,vector <int>(c));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
				in>>A[i][j];
		}
	}
	out<<maxSubmatrixSum(A);
	return 0;
}

int max(int a,int b){
	if(a>b)return a;
	else return b;
}

int kdane(vector<int> A){
	int maxSoFar=INT_MIN;	
	int sum=0;
	for(int i=0;i<(int)A.size();i++){
		sum+=A[i];
		if(sum>maxSoFar){
			maxSoFar=sum;
		}
		if(sum<0){
			sum=0;
		}
	}

	return maxSoFar;

}
int maxSubmatrixSum(
    vector<vector<int> > A)
{
    
    // Store the rows and columns
    // of the matrix
    int r = A.size();
    int c = A[0].size();
  
    // Create an auxiliary matrix
	  vector<vector<int>> prefix(r,vector <int>(c));
  
 
    // Calculate prefix sum of all
    // rows of matrix A[][] and
    // store in matrix prefix[]
    for (int i = 0; i < r; i++) {
  
        for (int j = 0; j < c; j++) {
  
            // Update the prefix[][]
            if (j == 0)
                prefix[i][j] = A[i][j];
            else
                prefix[i][j] = A[i][j]
                               + prefix[i][j - 1];
        }
    }
  
    // Store the maximum submatrix sum
    int maxSum = INT_MIN;
  
    // Iterate for starting column
    for (int i = 0; i < c; i++) {
  
        // Iterate for last column
        for (int j = i; j < c; j++) {
  
            // To store current array
            // elements
            vector<int> v;
  
            // Traverse every row
            for (int k = 0; k < r; k++) {
  
                // Store the sum of the
                // kth row
                int el = 0;
  
                // Update the prefix
                // sum
                if (i == 0)
                    el = prefix[k][j];
                else
                    el = prefix[k][j]
                         - prefix[k][i - 1];
  
                // Push it in a vector
                v.push_back(el);
            }
  
            // Update the maximum
            // overall sum
            maxSum = max(maxSum, kdane(v));
        }
    }
 
		return maxSum;
    // Print the answer
}



