#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#define p_b push_back
using namespace std;

#define vi vector<string>::iterator

vector<int>sorted;

void radix_sort(int*a,int n)
   {  vector<string>v(n);
      vector<string >v1[11];
      int digit;
      int mi=-1;

      for(int i=0;i<n;i++)
         mi=max(mi,(int)ceil(log10(a[i])));


      for(int i=0;i<n;i++)
       {
         int m = (int)floor(log10(a[i]));
         int d = mi-m;
         string t="";

         while(d--)
           t+="0";

        t+=to_string(a[i]);
         v[i]=t;
       }



      for(int k=mi;k>=0;k--)
       {
         for(vi it=v.begin();it!=v.end();it++)
           {
             string x=*it;
             v1[x[k]-'0'].p_b(x);
            }
           int k1=0;
      for(int i=0;i<10;i++)
            {
              for(int j=0;j<v1[i].size();j++)
                {
                 v[k1++]=(v1[i][j]);
                }
           }

         for(int i=0;i<11;i++)
            v1[i].clear();
    }

    for(int i=0;i<v.size();i++)
    {
      string x=v[i];
      sorted.push_back(stoi(x));
    }

  }

int main()
{
cout<<"enter no of element ";
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
  cin>>a[i];

radix_sort(a,n);

for(auto it=sorted.begin();it!=sorted.end();it++)
      cout<<*(it)<<" ";

  return 0;
}
