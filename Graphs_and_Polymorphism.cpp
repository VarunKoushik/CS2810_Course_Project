#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    graph(int k, int j)
    {
        n = k;
        m = j;
        adj = vector<set<int>>(n);
    }
    void add_edge(int u, int v)
    {
        adj[u].insert(v);
        adj[v].insert(u);
    }
    void remove_edge(int u, int v)
    {
        adj[u].erase(v);
        adj[v].erase(u);
    }
    void isreachable(int u, int v)
    {
        queue<int> q;
        q.push(u);
        vector<int> vis(n, false);

        while (q.size())
        {
            int k = q.front();
            vis[k] = true;
            q.pop();
            for (auto &x : adj[k])
            {
                if (vis[x] == false)
                {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        if (vis[v] == true)
        {
            cout << "Yes" << endl;
            return;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    graph operator+(graph g)
    {
        vector<set<int>> k = adj;
        adj = vector<set<int>>(max(n, g.n));

        for (int i = 0; i < g.n; i++)
        {
            for (auto &x : g.adj[i])
            {
                adj[i].insert(x);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto &x : k[i])
            {
                adj[i].insert(x);
            }
        }
        n = max(n, g.n);
        return *this;
    }
    graph operator-(graph g)
    {
        vector<set<int>> k = adj;

        adj = vector<set<int>>(max(n, g.n));

        for (int i = 0; i < max(n, g.n); i++)
        {
            if (i < n)
            {
                for (auto &x : k[i])
                {
                    if (i < g.n)
                    {
                        if (g.adj[i].find(x) != g.adj[i].end())
                        {
                            adj[i].insert(x);
                        }
                    }
                }
            }
        }
        n = max(n, g.n);
        return *this;
    }
    graph operator!()
    {
        bool a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto &x : adj[i])
            {

                a[i][x] = true;
            }
        }
        adj = vector<set<int>>(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j])
                {
                    continue;
                }
                if (i != j)
                    adj[i].insert(j);
            }
        }

        return *this;
    }
    friend ostream &operator<<(
        ostream &stream, graph &g);
    friend istream &operator>>(
        istream &stream, graph &g);

private:
    int n;
    int m;
    vector<set<int>> adj;
};
ostream &operator<<(
    ostream &stream, graph &g)
{
    for (int i = 0; i < g.n; i++)
    {
        stream << "Vertex " << i << ": ";
        for (auto &x : g.adj[i])
        {
            stream << x << ' ';
        }
        stream << '\n';
    }
    return stream;
}
istream &operator>>(
    istream &stream, graph &g)
{

    for (int i = 0; i < g.m; i++)
    {
        int x, y;
        stream >> x >> y;
        g.add_edge(x, y);
    }
    return stream;
}
int main()
{
    string s;
    cin >> s;
    int n, m;
    cin >> n >> m;
    graph g(n, m);
    cin >> g;

    while (s != "end")
    {
        cin >> s;
        if (s == "union")
        {
            cin >> s;
            int n, m;
            cin >> n >> m;
            graph h(n, m);
            cin >> h;
            g + h;
        }
        else if (s == "printGraph")
        {
            cout << g;
        }
        else if (s == "isReachable")
        {
            int x, y;
            cin >> x >> y;
            g.isreachable(x, y);
        }
        else if (s == "remove_edge")
        {
            int x, y;
            cin >> x >> y;
            g.remove_edge(x, y);
        }
        else if (s == "add_edge")
        {
            int x, y;
            cin >> x >> y;
            g.add_edge(x, y);
        }
        else if (s == "complement")
        {
            !g;
        }
        else if (s == "intersection")
        {
            cin >> s;
            int n, m;
            cin >> n >> m;
            graph h(n, m);
            cin >> h;
            g - h;
        }
    }
    return 0;
}
