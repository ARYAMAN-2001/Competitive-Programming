#include <bits/stdc++.h>
#include<vector>
using namespace std;

long long minDiffSubArray(long long arr[], long long n) 
{ 
  
    // To store prefix sums 
    long long prefix_sum[n]; 
  
    // Generate prefix sum array 
    prefix_sum[0] = arr[0]; 
  
    for(int i = 1; i < n; i++) 
        prefix_sum[i] = prefix_sum[i - 1] + 
                               arr[i]; 
  
    // To store suffix sums 
    long long suffix_sum[n]; 
  
    // Generate suffix sum array 
    suffix_sum[n - 1] = arr[n - 1]; 
  
    for(int i = n - 2; i >= 0; i--) 
        suffix_sum[i] = suffix_sum[i + 1] +  
                               arr[i]; 
  
    // Stores the minimum difference 
    long long minDiff = INT_MAX; 
  
    // Traverse the given array 
    for(int i = 0; i < n - 1; i++) 
    { 
          
        // Calculate the difference 
        long long diff = abs(prefix_sum[i] -  
                       suffix_sum[i + 1]); 
  
        // Update minDiff 
        if (diff < minDiff) 
            minDiff = diff; 
    } 
  
    // Return minDiff 
    return minDiff; 
} 
int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n,k,r=0,p=0,sum1=0,sum2=0,q,d,sum=0,res=0,temp;
	    cin>>n>>k;
	    long long a[n],s1[n],s2[n],s[n],u[n];
	    for(int i=0;i<n;i++)
	    {cin>>a[i];
	    sum=sum+a[i];}
	    if(sum<2*k)
	    cout<<-1<<endl;
	    else{
	    sort(a,a+n);
	    if(a[n-1]>=2*k)
	    {
	        for(int i=n-2;i>=0;i--)
	        {
	            sum2=sum2+a[i];
	            if(sum2>=k)
	            {
	                cout<<n-i<<endl;res=1;break;
	            }
	            
	        }
	        if(res==0)
	        cout<<-1<<endl;
	    }
	    else
	    {
	        for(int i=n-1;i>=0;i--)
	        {
	            sum1=sum1+a[i];
	            s1[p]=a[i];
	            p++;
	            if(sum1>=k)
	            {    
	                sum2=sum1;
	                q=i;break;
	            }
	        }
	        for(int i=q-1;i>=0;i--)
	        {
	            sum2=sum2+a[i];
	            s2[r]=a[i];
	            r++;
	            if(sum2>=2*k)
	            break;
	        }
	        if(sum2-sum1>=k)
	        cout<<r+p<<endl;
	        else
	        {
	          sum=sum2;
	          sum2=sum2-sum1;
	          for(int i=0;i<p;i++)
	          s[i]=s1[i];
	          for(int i=0;i<r;i++)
	          s[i+p]=s2[i];
	          /*for(int i=0;i<r+p;i++)
	          cout<<s[i]<<" ";
	          cout<<endl;*/
	          for(int i=0;i<r+p;i++)
	          {   
	              u[i/2]=s[i];
	              i++;
	              if(i<r+p)
	              u[r+p-(i+1)/2]=s[i];
	              i++;
	              if(i<r+p)
	              u[r+p-(i+2)/2]=s[i];
	              i++;
	              if(i<r+p)
	              u[(i-1)/2]=s[i];
	              
	          }
	          /*for(int i=0;i<r+p;i++)
	          cout<<u[i]<<" ";
	          cout<<endl;*/
	          temp=r+p;
	          d=minDiffSubArray(u,temp);
	          /*cout<<minDiffSubArray(u,temp)<<"&"<<endl;*/
	          if((sum-d)/2>=k)
	          cout<<r+p<<endl;
	          else{
	              d=sum1-k;
	          
	          {for(int i=p-1;i>=0;i--)
	          {
	              for(int j=0;j<r;j++)
	              {
	                  if(s1[i]>s2[j] and s1[i]-s2[j]<=d)
	                  {   d=d-(s1[i]-s2[j]);
	                      temp=s1[i];
	                      s1[i]=s2[j];
	                      s2[j]=temp;
	                      
	                      break;
	                  }
	              }
	          }
	          }
	          sum2=0;
	          for(int i=0;i<r;i++)
	          sum2=sum2+s2[i];
	          if(sum2>=k)
	          cout<<r+p<<endl;
	          
	          else
	          {
	              for(int i=q-r-1;i>=0;i--)
	              {sum2=sum2+a[i];
	              if(sum2>=k)
	              {cout<<n-i<<endl;res=1;break;}
	          }
	          if(res==0)
	          cout<<-1<<endl;
	          }
	    }}
	    
	}
	    }}
	
	return 0;
}
