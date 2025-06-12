#include <bits/stdc++.h>
using namespace std;
#define int long long
class employee
{
public:
    employee(int a, int b, int c, int d)
    {
        employee_id = a;
        age = b;
        experience = c;
        boss_id = d;
    }
    // gives_id
    int getid()
    {
        return employee_id;
    }
    // gives experience
    int getexperience()
    {
        return experience;
    }
    // gives age
    int getage()
    {
        return age;
    };

private:
    // private variables
    int employee_id;
    int age;
    int experience;
    int boss_id;
};
// returns id of the k youngest employee;
map<int, int> vis;
map<int, vector<employee>> adj;
map<int, int> sum;
map<int, int> child;
map<int, int> d;
int dfs(employee a)
{

    int ans = a.getexperience();

    for (employee &x : adj[a.getid()])
    {

        if (vis[x.getid()] == 0)
        {

            ans += dfs(x);
        }
    }
    sum[a.getid()] = ans;

    return ans;
};
int dfs2(employee a)
{

    int ans = 1;

    for (employee &x : adj[a.getid()])
    {

        if (vis[x.getid()] == 0)
        {
            ans += dfs2(x);
        }
    }
    child[a.getid()] = ans;

    return ans;
};
bool s_experience(employee &a, employee &b)
{
    if (a.getexperience() != b.getexperience())
        return a.getexperience() > b.getexperience();
    else
    {
        return d[a.getid()] > d[b.getid()];
    }
}
bool s_ae(employee &a, employee &b)
{
    if (a.getexperience() != b.getexperience())
        return a.getexperience() > b.getexperience();
    else
    {
        return a.getage() > b.getage();
    }
}
bool s_age(employee &a, employee &b)
{
    if (a.getage() != b.getage())
        return a.getage() > b.getage();
    else
    {
        return d[a.getid()] > d[b.getid()];
    }
}

int32_t main()
{

    // adjacency list to store the grapgh
    int n;
    cin >> n;

    vector<employee> v;

    int f_boss;
    for (int i = 0; i < n; i++)
    {
        int id, age, exp, boss_id;
        cin >> id >> age >> exp >> boss_id; // take input here
        employee a(id, age, exp, boss_id);
        v.push_back(a);

        if (id == boss_id)
        {
            f_boss = i;
        }
        else
        {
            adj[boss_id].push_back(a);
        }
    }
    d[v[f_boss].getid()] = 0;
    queue<employee> q;
    q.push(v[f_boss]);
    map<int, int> vis;
    while (q.size())
    {
        employee t = q.front();
        q.pop();

        for (employee &x : adj[t.getid()])
        {

            if (vis[x.getid()] == 0)
            {

                d[x.getid()] = d[t.getid()] + 1;

                vis[x.getid()] = 1;
                q.push(x);
            }
        }
    };
    dfs(v[f_boss]);
    dfs2(v[f_boss]);

    int h;
    cin >> h;

    int x1 = -1;

    int x2 = -1;
    int x3 = -1;

    for (int i = 0; i < h; i++)
    {
        int queryType;
        cin >> queryType;
        if (queryType == 1)
        {
            int k;
            cin >> k;
            if (k == 1)
            {
                if (x1 != -1)
                    cout << x1 << endl;
                else
                {
                    set<int> s;
                    vector<employee> p = v;
                    sort(v.begin(), v.end(), s_experience);
                    int k = 1e9;
                    int exp = -1;
                    for (int i = 0; i < n; i++)
                    {
                        if (d[v[i].getid()] <= k)
                        {
                            k = d[v[i].getid()];
                            s.insert(v[i].getid());
                        }
                    }
                    v = p;
                    x1 = s.size();
                    cout << x1 << endl;
                }
            }
            else if (k == 2)
            {
                if (x2 != -1)
                    cout << x2 << endl;
                else
                {
                    set<int> s;
                    vector<employee> p = v;
                    sort(v.begin(), v.end(), s_age);
                    int k = 1e9;
                    int exp = -1;
                    for (int i = 0; i < n; i++)
                    {
                        if (d[v[i].getid()] <= k)
                        {
                            k = d[v[i].getid()];
                            s.insert(v[i].getid());
                        }
                    }
                    v = p;
                    x2 = s.size();
                    cout << x2 << endl;
                }
            }
            else
            {
                if (x3 != -1)
                {
                    cout << x3 << endl;
                }
                else
                {
                    set<int> s;
                    vector<employee> p = v;
                    sort(v.begin(), v.end(), s_ae);
                    int k = 1e9;
                    int exp = -1;
                    for (int i = 0; i < n; i++)
                    {
                        if (v[i].getage() <= k)
                        {
                            k = v[i].getage();
                            s.insert(v[i].getid());
                        }
                    }
                    v = p;
                    x3 = s.size();
                    cout << x3 << endl;
                }
            }
        }
        else if (queryType == 2)
        {
            int id;
            cin >> id;

            cout << sum[id] / child[id] << endl;
        }
        else
        {
            int id;
            int k;
            cin >> id >> k;
            vector<employee> va;

            queue<employee> q;
            long long ans;
            for (int i = 0; i < n; i++)
            {
                if (v[i].getid() == id)
                {
                    ans = v[i].getexperience();
                    q.push(v[i]);
                    va.push_back(v[i]);
                }
            }
            map<int, int> vis;

            while (q.size())
            {
                employee t = q.front();
                q.pop();

                for (employee &x : adj[t.getid()])
                {

                    if (vis[x.getid()] == 0)
                    {
                        vis[x.getid()] = 1;
                        va.push_back(x);
                        q.push(x);
                    }
                }
            };
            vector<pair<int, int>> vi;
            for (int i = 0; i < va.size(); i++)
            {
                int a = va[i].getage();
                int b = va[i].getid();
                vi.push_back({a, b});
            }
            sort(vi.begin(), vi.end());
            if (vi.size() < k)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << vi[k - 1].second << endl;
            }
        }
    }
    return 0;
}
