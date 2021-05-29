#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Solve(vector<int> arr)
{
    // Write your code here
    vector<vector<int>> tow;
    int x = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
        }
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i_arr = 0; i_arr < N; i_arr++)
        cin >> arr[i_arr];

    vector<vector<int>> out_ = Solve(arr);
    for (int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
        for (int j_out_ = 0; j_out_ < out_[i_out_].size(); j_out_++)
            cout << out_[i_out_][j_out_] << " ";
        cout << "\n";
    }
}

/*#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> arr, int n)

{

    int t = n, i;

    priority_queue<int> p;

    for (i = 0; i < n; i++)
    {
        p.push(arr[i]);
        while (p.top() == t)
        {
            cout << p.top() << " ";
            p.pop();
            t--;
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i_arr = 0; i_arr < N; i_arr++)
    {
        cin >> arr[i_arr];
    }
    solve(arr, N);
}
*/