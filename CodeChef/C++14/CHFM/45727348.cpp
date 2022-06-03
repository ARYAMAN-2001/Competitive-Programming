
#include<iostream>
using namespace std;

int main() {
int t;
cin>>t;
for(int i=0;i<t;i++)
{int n;
    cin>>n;
    long a[n];
    for(int i=0;i<n;i++)
   { cin>>a[i];}
   
   long long sum=0; 
    for(int i=0;i<n;i++)
    {sum=sum+a[i];}
    
    if((sum%n)!=0)
    {cout<<"Impossible"<<endl;
    continue;}
    
    long x=sum/n;
    bool found=0;
    int pos;
    for(int i=0;i<n;i++)
    {if(x==a[i]){
        found=1;
        pos=i+1;
        break ;   }}
        if(found){
            cout<<pos<<endl;}
            else{cout<<"Impossible"<<endl;}
        }
    
    
     
  
     
    
    
   

	

	return 0;
}