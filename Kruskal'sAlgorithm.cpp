#include<bits/stdc++.h>
using namespace std;

#define all(x)            (x).begin(),(x).end()
#define ll                long long
#define M                 10007

int parent[M+2];

struct edge
{
    int v1;
    int v2;
    int weight;
};

vector< struct edge > v;

bool compare( struct edge e1, struct edge e2)
{
    if(e1.weight<e2.weight)
        return true;
    return false;
}


int parfind(int ele)
{
    if(parent[ele]==0)
        return ele;
    return parfind(parent[ele]);
}

void un(int a,int b)
{
    int p1=parfind(a);
    int p2=parfind(b);
    if(p1==p2)
        return;
    parent[p1]=p2;
}

int solve()
{
    int n,m;
    //n is no.of vertices, m is no.of edges
    cout<<"\nEnter number of Vertices: "<<endl;
    cin>>n;
    cout<<"\nEnter number of Edges: "<<endl;
    cin>>m;
    cout<<"\nEnter details of all "<<m<<" edges : "<<endl;
    for(int i=0;i<m;i++)
    {
        struct edge el;
        cin>>el.v1>>el.v2>>el.weight;
        v.push_back(el);
    }
    sort(all(v), compare);
    int einst=0,i=0;
    ll ans=0;
    int tr;
    cout<<"edges of minimum spanning tree are as follows: "<<endl;
    for(int i=0;i<n;i++)
    {
      if(v[i].v1==1||v[i].v2==1)
      {
        tr=i;
        einst++;
        ans+=v[i].weight;
        un(v[i].v1, v[i].v2);
        cout<<v[i].v1<<" "<<v[i].v2<<endl;
        break;
      }
    }
    while(einst<n-1)
    {
      if(i==tr)
        i++;
        int v1=v[i].v1,v2=v[i].v2;
        int p1=parfind(v1),p2=parfind(v2);
        
        if(p1==p2)
        {
            i++;
            continue;
        }
        cout<<v[i].v1<<" "<<v[i].v2<<endl;
        ans+=v[i].weight;
        un(p1,p2);
        einst++;
        i++;

    }
    cout<<"weight of minimum spanning tree is "<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
