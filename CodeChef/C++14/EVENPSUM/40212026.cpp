#include <iostream>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long a,b;
	    cin>>a>>b;
	    if(a%2==1 and b%2==1)
	    cout<<a*b/2+1<<endl;
	    else
	    cout<<a*b/2<<endl;
	}
	return 0;
}
