#include <iostream>
#include<vector>
using namespace std;

int main() {
	int M,N,temp;
	cin>>N;
    vector<int> B(N);
	for(int i=0;i<N;i++)
	    cin>>B[i];
	cin>>M;
	for(int i=0;i<M;i++)
	{    
	    cin>>temp;
	    cout<<B[temp-1]<<endl;
	    B.erase(B.begin()+temp-1);
	}
	return 0;
}
