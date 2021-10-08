#include <bits/stdc++.h>
using namespace std; / Users / unknown / Desktop / z.cpp
#define int long long

vector<int> house[100001];
int valueOfHouse[100001] = {0};
int dis[100001] = {0};

void dfs(int h, int p)
{

    for (auto nei : house[h])
    {
        if (nei != p)
        {
            dis[nei] = 1 + dis[h];
            dfs(nei, h);
        }
    }
}

signed main()
{
    int numHouses;

    cin >> numHouses;

    for (int i = 1; i <= numHouses - 1; i++)
    {
        int houseA, houseB;
        cin >> houseA >> houseB;
        house[houseA].push_back(houseB);
        house[houseB].push_back(houseA);
    }

    for (int i = 1; i <= numHouses; i++)
    {
        int value;
        cin >> value;
        valueOfHouse[i] = value;
    }

    int ans = 1e9;
    int index;
    for (int i = 1; i <= numHouses; i++)
    {
        dfs(i, -1);
        int tempAns = 0;
        for (int j = 1; j <= numHouses; j++)
        {
            if (valueOfHouse[j] == 1)
            {
                tempAns += dis[j];
            }
            dis[j] = 0;
        }
        if (tempAns < ans)
        {
            index = i;
            ans = tempAns;
        }
    }

    cout << index << endl;
}
