#include <iostream>
using namespace std;

int main() {int a,b,z;
cin>>a>>b;
z=a-b;
if(z%10==9)
cout<<z-1;
else
cout<<z+1;
	return 0;
}

