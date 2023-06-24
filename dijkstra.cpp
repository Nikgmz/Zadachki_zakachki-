#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Edge
{
    int to;
    int dist;
    bool operator< (const Edge other) const
    {
        if(dist!=other.dist) return dist>other.dist;
        else return to>other.to;
    }
    Edge(int to, int dist):to(to), dist(dist) {}
};
struct Graph
{
    int n1, n2, d;
};
int main ()
{
    int n, m;
    cout<<"Enter the number of vertices and the number of edges: "<<endl;
    cin>>n>>m;

    vector<vector<Edge>> gr(m);
    bool visited[n];
    int v, neigh, len;

    cout<<"Enter the graph: "<<endl;
    for(int i=0; i<m; ++i)
    {
        cin>>v>>neigh>>len;
        gr[v].push_back({neigh, len});
    }

    for(int i=0; i<n; ++i)
    {
        visited[i]=false;
    }

    priority_queue<Edge> pq;

    int start_, end_;
    cout<<"Enter the start and end vertex: "<<endl;
    cin>>start_>>end_;

    pq.push(Edge(0,0));

    while(!pq.empty())
    {
        Edge mini=pq.top();
        pq.pop();
        if(mini.to==end_)
        {
            cout<<"The shortest path to "<<mini.to<<" is: "<<mini.dist;
            break;
        }
        if(visited[mini.to]==false)
        {
            visited[mini.to]=true;
            for(int i = 0; i < gr[mini.to].size(); ++ i)
            {
                Edge e = gr[mini.to][i];
                pq.push(Edge(e.to, e.dist + mini.dist));
            }
        }
    }

    return 0;
}
