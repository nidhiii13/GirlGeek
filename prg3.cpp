#include <bits/stdc++.h>
using namespace std;
int st[10],t=-1,p[10],j=0,q[10],fr=0,r=-1,c=0;
void push(int i)
{
    st[++t]=i;
}
int pop()
{
    return(st[t--]);
}
void enq(int i)
{
    q[++r]=i;
}
int deq()
{
    return q[fr++];
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
    //dfs(a,f,n,st[t]);
}
void bfs(int a[10][10],int f[10],int n,int sv){
    if(f[sv]==0){
        enq(sv);
        c++;
         cout<<sv<<" ";
        f[sv]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[sv][i]==1 && f[i]==0 && i!=sv){
             enq(i);
             c++;
             cout<<i<<" ";
             f[i]=1;
        }
    }
    if(fr>r)
    return;
    bfs(a,f,n,deq());
}
int main()
{
    int n,s,e,a[10][10]={0},ch,sv;
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
        a[e][s]=1;
    }
    cout<<"1. DFS\n";
    cout<<"2. BFS\n";
    cout<<"Enter your choice:";
    cin>>ch;
    cout<<"Enter the starting vertex:";
    cin>>sv;
    int f[10]={0};
    if(ch==1){
    cout<<"DFS order:";
    dfs(a,f,n,sv);
    cout<<"\nPOP order:";
    for(int i=0;i<j;i++)
    cout<<p[i]<<" ";
    if(j==n)
    cout<<"\nConnected graph\n";
    else
    cout<<"\nNot a connected graph\n";
    }
    else if(ch==2)
    {
        cout<<"BFS order:";
        bfs(a,f,n,sv);
        if(c==n)
        cout<<"\nConnected graph\n";
        else
        cout<<"\nNot a Connected graph\n";
        }
    return 0;
}
