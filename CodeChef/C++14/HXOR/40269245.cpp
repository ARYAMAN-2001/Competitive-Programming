#include <bits/stdc++.h>
using namespace std;
#define N 1000000007 // prime modulo value 
  
long int exponentiation(long int base, 
                        long int exp) 
{ 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return base % N; 
  
    long int t = exponentiation(base, exp / 2); 
    t = (t * t) % N; 
  
    // if exponent is even value 
    if (exp % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((base % N) * t) % N; 
} 
  

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long x,n,temp=0,c,r=1,op=0,i,j;
	    cin>>n>>x;
	    long long a[n],b[34*n+1];
	    for(int i=0;i<34*n+1;i++)
	    b[i]=0;
	    for(int i=0;i<n;i++)
	    {cin>>a[i];
	    c=(i+1)*34;
	    while(a[i]>0){
	        b[c]=a[i]%2;
	        a[i]=a[i]/2;
	        c--;
	    }
	      }
	    /*for(int i=1;i<32*n+1;i++)
	    {cout<<b[i];
	    if(i%32==0)
	    cout<<endl;}*/
	    
	    for(int i=1;i<34*n+1;i++)
	    {
	        if(op==x)
	        break;
	        if(b[i]==0)
	        continue;
	        j=i+34;
	        if(j>n*34)
	        break;
	        while(j<=34*n and b[j]==0)
	        j=j+34;
	        if(j>n*34)
	        j=j-34;
	        b[i]=0;
	        b[j]==0?b[j]=1:b[j]=0;
	        op++;
	        if(op==x)
	        break;
	    }
	    /*cout<<x<<endl;*/
	   /* for(int i=1;i<34*n+1;i++)
	    {cout<<b[i];
	    if(i%34==0)
	    cout<<endl;}*/
	if(n==2 and (x-op)%2!=0)
	{
	    
	    (b[34*n]==1)?(b[34*n]=0):(b[34*n]=1) ;
	    b[34*n-34]=1;
	    temp=0;
	for(int i=1;i<34*n+1;i++)
	{if(b[i]==1)
	temp=temp+exponentiation(2,(34*n-i)%34);
	if(i%34==0)
	{cout<<temp<<" ";
	temp=0;}}
	    cout<<endl;
	}
	else
	{ 
	   temp=0;
	for(int i=1;i<34*n+1;i++)
	{if(b[i]==1)
	temp=temp+exponentiation(2,(34*n-i)%34);
	if(i%34==0)
	{cout<<temp<<" ";
	temp=0;}} 
	    cout<<endl;

	}
	
	}
	
	return 0;
}
