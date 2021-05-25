#include <bits/stdc++.h>
using namespace std;

#define sz(a)             int((a).size())
#define pb                push_back
#define fr                first
#define sc                second

bool dfs(int cur, int st, string &s, vector<vector<int> > &v, map<int , string> &ind)
{
  if(st>=sz(s))
    return true;
  if(cur==-1)
  {
    int q=0;
    for(auto i: ind)
    {
      if(s[st]==i.sc[0])
      {
        bool ch=dfs(i.fr, st+1, s,v, ind);
        if(ch)
          return true;
      }
    }
    return false;
  }
  for(auto i:v[cur])
  {
    if(ind[i][0]==s[st])
    {
      if(dfs(i, st+1, s, v, ind))
        return true;
    }
  }
  return false;
}

int solve()
{
  ifstream fcin;
  fcin.open("input.txt");
  ofstream fcout;
  fcout.open("output.txt");
  vector<string> vstr;
  string temp;
  getline(fcin, temp);
  int szt=sz(temp);
  for(int i=0;i<szt;)
  {
    string tmp;
    while(i<szt)
    {
      if(temp[i]==',')
        break;
      tmp.pb(temp[i]);
      i++;
    }
    vstr.pb(tmp);
    i+=2;
  }

  map<int, string> ind;
  map<string , int> indsi;
  for(int i=0;i<sz(vstr);i++)
  {
    ind[i]=vstr[i];
    indsi[vstr[i]]=i;
  }

  vector<vector<int> > v(sz(vstr));
  int cnt=0;

  fcin>>temp;
  fcin>>temp;
  while(temp.substr(0, 6)!="Paths:")
  {
    string tmp1, tmp2;
    for(auto i:temp)
    {
      if(i=='-')
        break;
      tmp1.pb(i);
    }
    fcin>>tmp2;
    v[indsi[tmp1]].pb(indsi[tmp2]);
    // cout<<tmp1<<"-> "<<tmp2<<endl;
    cnt++;
    if(cnt>10)
      break;

    fcin>>temp;
  }
  while(fcin>>temp)
  {
    fcout<<temp<<" ["<<(dfs(-1, 0, temp, v, ind)?"YES]\n":"NO]\n");
  }


  

  return 0;
}

int main()
{
  // freopen("input.txt","r", stdin);
  // freopen("output.txt","w",stdout);
  int t=1;

  //cin>>t;
  
  while(t--)
  {
    solve();
  }
}