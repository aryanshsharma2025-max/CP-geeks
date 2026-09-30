#include <bits/stdc++.h>
using namespace std;

bool canBuild(vector<int>& a, long long w, long long height)
{
    long long water = 0;

    for(int x : a)
    {
        if(x < height)
        {
            water += height - x;
        }
    }

    return water <= w;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        long long w;

        cin >> n >> w;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long left = 1;
        long long right = *max_element(a.begin(), a.end()) + w;

        while(left <= right)
        {
            long long mid = left + (right - left) / 2;

            if(canBuild(a, w, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << right << '\n';
    }
}