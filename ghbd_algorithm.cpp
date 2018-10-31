#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define lli long long int
#define pb push_back
#define mp make_pair
#define fo(i,n) for(i=0;i<(n);i++)
#define endl "\n"

long long int i,j;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    lli e,v;
    // v=81;
    cin>>v;
    cin>>e;
    vector<lli>a[v];
    set<lli>color[v],marked[v];
    vector<int>degree(v,0);
    // cout<<"inn";
    fo(i,e)
    {
        lli c,b;
        cin>>c>>b;
        a[c-1].pb(b-1);
        a[b-1].pb(c-1);
        degree[c-1]++;
        degree[b-1]++;
    }
    lli final[v];
    fo(i,v)
    final[i]=0;
    bool proc[v];
    fo(i,v)
    proc[i]=false;
    unordered_set<lli>q;
    q.insert(0);
    // proc[0]=true;
    color[0].insert(1);
    int p=0;
    while(q.size()>0)
    {
    // for(auto it=q.begin();it!=q.end();it++)
    //     cout<<*it;
        // cout<<"in";
        p++;
        if(p==20)
        {
            // break;
        }
        // cout<<"in"<<endl;
        int min=INT_MAX;
        int index=-1;
        int last=0;
        // cout<<q.size()<<endl;
        for(int it=0;it<v;it++)
        {
            // cout<<"hi";
            // cout<<degree[0];
            if(color[it].size()<min&&color[it].size())
            {
                // cout<<"hi";
                min=color[it].size();
                index=it;
                last=0;
            }
            else if(color[it].size()==min&&color[it].size())
            {
                auto ii=color[it].end();
                ii--;
                if(*ii>last)
                {
                    last=*ii;
                    index=it;
                }
            }
        }
        lli now=index;
        // cout<<color[15].size()<<endl;
        // for(auto it=color[13].begin();it!=color[13].end();it++)
        // {
        //     cout<<*it<<" ";
        // }
        // cout<<endl;
        q.erase(index);
        if(proc[now])
        continue;
        fo(i,a[now].size())
        {
            if(proc[a[now][i]])
            {
                color[now].erase(final[a[now][i]]);
            }
        }
        // cout<<now;
        // cout<<*(color[now].begin())<<" "<<now+1<<endl;
        final[now]=*(color[now].begin());
        degree[now]=INT_MIN;
        color[now].clear();
        // cout<<*(color[now].begin());
        // cout<<a[now].size();
        fo(i,a[now].size())
        {
            // cout<<a[now][i];
            if(!proc[a[now][i]])
            {
                // fo(j,final[now]+1){
                    // cout<<j<<endl;
                marked[a[now][i]].insert(final[now]);
                if(color[a[now][i]].find(final[now])!=color[a[now][i]].end())
                    color[a[now][i]].erase(final[now]);
                if(marked[a[now][i]].find(final[now]+1)==marked[a[now][i]].end()){
                                                color[a[now][i]].insert(final[now]+1);
                                                degree[a[now][i]]--;}
                            // }
                // cout<<"in";
                if(final[now]-1>0&&(marked[a[now][i]].find(final[now]-1)==marked[a[now][i]].end()))
                color[a[now][i]].insert(final[now]-1);
                q.insert(a[now][i]);
            }
        }
        proc[now]=true;
    }

    // fo(i,9)
    // {
        fo(j,v)
    //     {
            // if(proc[i*9+j])
            cout<<final[j]<<" ";                
            // else if(color[i*9+j].size())
            // cout<<*(color[i*9+j].end()--)<<" ";
            // else
                // cout<<"0 ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
