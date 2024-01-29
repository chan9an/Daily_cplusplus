#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long power(int x){
    if(x==0)return 1;
    long long P=power(x/2);
    if((x%2)==0)return (P*P)%MOD;
    else return (2*((P*P)%MOD))%MOD;
}

long long countSubstrings(string A,string B){
    long long count=0,m=A.size(),n=B.size();
    for(long long i=0;i<m;i++){
        if(m-i < n)break;
        long long j=0;
        for(j=0;j<n;j++)if(A[i+j]!=B[j])break;
        if(j==n)count++;
    }
    return count;
}//number of B's as substrings in A.

void computeLPSArray(string pat,long long m,long long lps[]){
    long long len=0,i=1;
    lps[0]=0;
    
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)len=lps[len-1];
            else{
                lps[i]=len;
                i++;
            }
        }
    }
}

long long KMPSearch(string txt,string pat){
    long long m=pat.length(),n=txt.length();
    long long lps[m];
    long long j=0; 
    
    computeLPSArray(pat,m,lps);
 
    long long i=0,res=0,next_i=0;
    while(i<n){
        if(pat[j]==txt[i]) {
            j++;
            i++;
        }
        if(j==m){
            j=lps[j-1];
            res++;
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0)j=lps[j-1];
            else i=i+1;
        }
    }
    return res;
}

int main() {
    long long T;
    cin>>T;
    while(T--){
        long long N,K;
        cin>>N>>K;
        string S;
        cin>>S;
        
        string S1(2*N,'#');
        for(long long i=0;i<N;i++)S1[i]=S[i];
        for(long long i=N-1;i>=0;i--)S1[N+N-1-i]=S[i];
        // long long count1=countSubstrings(S1,S);
        long long count1=KMPSearch(S1,S);
        
        string S2(2*N-2,'#');
        for(long long i=N-2;i>=0;i--)S2[N-2-i]=S[i];
        for(long long i=0;i<=N-2;i++)S2[N-1+i]=S[i];
        // long long count2=countSubstrings(S2,S);
        long long count2=KMPSearch(S2,S);
        
        long long result=0;
        long long P=power(K-1);
        result=(result+(P*count1)%MOD)%MOD;
        result=(result+((P-1)*count2)%MOD)%MOD;
        cout<<result<<endl;
    }
}
