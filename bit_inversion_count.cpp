#include <bits/stdc++.h>
using namespace std;
int getsum(vector<int>& BIT,int x)
{  int sum=0;
    while(x>0)
    {
        sum+=BIT[x];
        x-=(x&(-x));
    }
    return sum;
}
void update(vector<int>& BIT,int val,int x)
{

    while(x<BIT.size())
    {
        BIT[x]+=val;
        x+=(x&(-x));
    }
}
int countInversions(vector<int> &A) {
   int maxi=INT_MIN;
   vector<int> B,c(A.size());
   for(int i=0;i<A.size();i++)
      B.push_back(A[i]);
    sort(B.begin(),B.end());

   for(int i=0;i<A.size();i++)
     {
         int idx=lower_bound(B.begin(),B.end(),A[i])-B.begin();
         c[i]=idx+1;
     }
   for(int i=0;i<c.size();i++)
     if(maxi<c[i])
       maxi=c[i];
    vector<int>BIT(maxi+1,0);
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        update(BIT,1,c[i]);
        int a=getsum(BIT,BIT.size()-1);
        int b=getsum(BIT,c[i]);
        //cout<<A[i]<<" "<<a<<" "<<b<<"\n";
        count+=(a-b);
    }
    return count;
}

int main() {
    //int arr[] = {6,2,1,0,5,4};
    //int n = sizeof(arr)/sizeof(int);
    vector<int> A;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    cout<<countInversions(A)<<endl;

}
