//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Prim's algorithm :
    Vertex based.
    All vertex are at distance infinity
    Use priority_queue ( PQ is default MAX Heap) so make it Min Heap by
    priority_queue < int, vector<int> , greater<int> >
    Push {distance, node} in PQ and store visited, and distance

    Sample graph from : https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
9 14
1 2 4
1 8 8
2 8 11
2 3 8
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_SIZE = 15;

vector<pair<ll, ll>> G[MAX_SIZE]; // Adjacency list contains, to which node present node is connected and the cost for it
bool visited[MAX_SIZE];
ll dist[MAX_SIZE];
ll parent[MAX_SIZE];

void preprocess()
{
    for (int i = 0; i < MAX_SIZE; i++)
        G[i].clear(), visited[i] = false, dist[i] = INF, parent[i] = -1;
}

ll prim(ll src, ll N)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ; // Min heap, where pair<ll,ll> is {Distance , node};
    // dist of src 0 not required rather push all nodes

    for (int i = 2; i <= N; i++)
        PQ.push({dist[i], i});

    dist[src] = 0;
    ll mst_cost = 0;
    PQ.push({dist[src], src});
    while (!PQ.empty())
    {
        ll node = PQ.top().second;
        ll cost = PQ.top().first;
        PQ.pop();

        if (visited[node]) // if visited that means already shortest path till this vertex is computed
            continue;
        visited[node] = true;

        mst_cost += cost;
        for (int i = 0; i < G[node].size(); i++) // Traverse the adjacency list
        {
            ll toNode = G[node][i].first;
            ll costToNode = G[node][i].second;

            // No relaxation, just simple compare of which edge is to be chosen from the current node
            if (dist[toNode] > costToNode and !visited[toNode])
            {
                dist[toNode] = costToNode;
                parent[toNode] = node;
                PQ.push({dist[toNode], toNode});
            }
        }
    }
    return mst_cost;
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    preprocess();

    ll N, M; // N nodes and M edges
    cin >> N >> M;

    // UNDIRECTED GRAPH LOGIC
    ll a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    cout << "MST Cost is : " << prim(1, N) << endl;

    for (int i = 1; i <= N; i++)
        cout << "Parent of " << i << " is : " << parent[i] << endl;

    return 0;
}
// END OF SOURCE CODE