#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    unsigned long long k,n;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        if((n/k)%k==0)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
    }
	
	return 0;
}
