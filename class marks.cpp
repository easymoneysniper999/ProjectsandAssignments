#include <bits/stdc++.h>
using namespace std;

int num(string s)
{
  int n=s.size();
  int ans=0, pw=1;
  for(int i=n-1;i>=0;i--)
  {
    ans+=pw*((int)(s[i]-'0'));
    pw*=10;
  }
  return ans;
}

int main()
{
  freopen("student.txt", "w", stdout);
  freopen("group1.txt", "r", stdin);

  vector<string> subjects;
  vector<vector<int> > vmarks1;
  string subj;
  while(cin>>subj)
  {
    subjects.push_back(subj);
    vector<int> vtemp;
    while(1)
    {
      int marks;
      cin>>marks;
      if(marks==-999)
        break;
      vtemp.push_back(marks);
    }
    vmarks1.push_back(vtemp);
  }

  int n=subjects.size();
  fstream newfile;
  newfile.open("group2.txt",ios::in);
  vector<vector<int> > vmarks2;
  
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    getline(newfile, s);
    vector<int> spaces;
    for(int j=0;j<s.size();j++)
    {
      if(s[j]==' ')
        spaces.push_back(j);
    }
    int prev=-1;
    vector<int> vtemp;
    for(int j=0;j<spaces.size();j++)
    {
      if(j==0)
      {
        prev=spaces[j];
        continue;
      }
      vtemp.push_back(num(s.substr(prev+1, spaces[j]-prev-1)));
      prev=spaces[j];
    }
    vmarks2.push_back(vtemp);
  }


  //double avg[n][2];
  vector<vector<double> > avg(n , vector<double>(2, 0.0));
  for(int i=0;i<n;i++)
  {
    avg[i][0]=avg[i][1]=0;
    for(int j=0;j<vmarks1[i].size();j++)
    {
      avg[i][0]+=vmarks1[i][j];
    }
    avg[i][0]/=(double)(vmarks1[i].size());

    for(int j=0;j<vmarks2[i].size();j++)
    {
      avg[i][1]+=vmarks2[i][j];
    }
    avg[i][1]/=(double)(vmarks2[i].size());
  }

  
  cout<<"        Bar Graph\n";
  cout<<"COURSE ID    COURSE AVERAGE   0    10   20   30   40   50   60   70   80   90   100\n";
  cout<<"                              |....|....|....|....|....|....|....|....|....|....|\n";
  cout<<fixed<<setprecision(2);

  for(int i=0;i<n;i++)
  {
    cout<<subjects[i]<<"          ";
    cout<<avg[i][0]<<"            ";
    for(int j=0;j<ceil(avg[i][0])/2;j++)
      cout<<"*";
    cout<<endl;
    cout<<"             "<<avg[i][1]<<"            ";
    for(int j=0;j<ceil(avg[i][1])/2;j++)
      cout<<"#";
    cout<<endl<<endl;
  }

  cout<<"Group 1 -- ****\n";
  cout<<"Group 2 -- ####\n";
  for(int i=0;i<2;i++)
  {
    double av=0.0;
    for(int j=0;j<n;j++)
    av+=avg[j][i];
    av/=(double)n;
    cout<<"Avg for group "<<i+1<<": "<<av<<endl;
  }


  return 0;
}
