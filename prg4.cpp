#include <bits/stdc++.h>
using namespace std;
int st[10],t=-1,p[10],j=0,c=0,n;
void push(int i)
{
    st[++t]=i;
}
int pop()
{
    return(st[t--]);
}

void dfs(int a[10][10],int f[10],int n,int sv)
{
    if(f[sv]==0){
    push(sv);
     cout<<sv<<" ";
    f[sv]=1;}
    int i;
for(i=1;i<=n;i++)
{
    if(a[sv][i]==1 && f[i]==0 && i!=sv)
    {
        dfs(a,f,n,i);
    }
}
if(t==-1)
return;
p[j++]=pop();
}

void vertices_rem(int a[10][10],int ind[10],int s,int f[10]){
 cout<<s<<" ";
 f[s]=1;
 c++;
 for(int i=1;i<=n;i++)
 {
     if(a[s][i]==1)
     {
         a[s][i]=0;
         ind[i]--;
     }
 }
 for(int i=1;i<=n;i++){
 if(ind[i]==0 && f[i]==0)
 vertices_rem(a,ind,i,f);
 }
 if(c==n)
 return;
 }
int main()
{
    int s,e,a[10][10]={0},ch,sv,in[10]={0};
    cout<<" Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter 0 to stop entering\n";
    while(true)
    {
        cout<<"Start vertex:";
        cin>>s;
        if(s==0)
        break;
        cout<<"End vertex:";
        cin>>e;
        a[s][e]=1;
        in[e]++;
    }
    cout<<"Enter the starting vertex:";
    cin>>sv;
    int f[10]={0};
    cout<<"1.Vertices removal method\n2.DFS method\nEnter your choice:";
    cin>>ch;
    if(ch==1){
       cout<<"\nThe elements in TOPOLOGICAL ORDERING : ";
       vertices_rem(a,in,sv,f);
    }
    if(ch==2){
    cout<<"DFS order:";
    dfs(a,f,n,sv);
    cout<<"\nTOPOLOGICAL ORDERING: ";
    for(int i=j-1;i>=0;i--)
    cout<<p[i]<<" ";}
    return 0;
}
