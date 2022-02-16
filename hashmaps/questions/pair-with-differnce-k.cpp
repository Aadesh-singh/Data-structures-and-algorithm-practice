#include<iostream>
#include<unordered_map>
using namespace std;

void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int,int> m;
    for(int i=0 ; i< n ;i++)
    {
        m[input[i]]++;
    }
    
    if(k!=0){
    	for(int i=0 ; i<n ;i++)
    	{
     	
        	if(m.count(input[i]-k)>0)
        	{
            	// m[input[i]]--; 
            	int j=0;
            	while(j<m[input[i]-k])
            	{
            	if((input[i]-k)<input[i])
                	cout<<input[i]-k<<" "<<input[i]<<endl;
            	else
               		cout<<input[i] << " "<< input[i]-k<<endl;

            	j++;  
            	}
        	}
        
    	}

	}
    else if(k==0){
     	for(int i=0;i<n;i++)
        	{
              if(m.count(input[i])>0)
            	{
              		for(int j=0;j<m[input[i]]-1;j++)
             		{ cout<<input[i]<<" "<<input[i]<<endl;
                    }
               
                		m[input[i]]--;
                }
            }
         }

}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k; 
    cin>>k;
    printPairs(a, n, k);

    delete [] a;
}


