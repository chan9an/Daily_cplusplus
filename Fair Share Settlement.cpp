#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T , N , K;
    cin>>T;
    while(T--)
    {
            double shareFare = 0 , totalReceived = 0;
        cin>>N>>K;
        shareFare = N/(K+1);
        for (int i = 0; i < K; ++i)
        {
            totalReceived += floor(shareFare);
        }
        double iPaid = N-totalReceived;
        cout<<iPaid<<"\n";
    }
    return 0;
}
