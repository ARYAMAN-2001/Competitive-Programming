#include <iostream>
using namespace std;

int main() {int a[100];
    for(int i=0;i<100;i++)
    cin>>a[i];
    for(int i=0;i<100;i++)
    {if(a[i]==42)
    break;
    cout<<a[i]<<endl;
    }
	
	return 0;
}
