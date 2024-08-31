#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &result, map<char, int> &paren, string &bl, int sum, int n)
{

    if (sum < 0)
    {
        return;
    }
    if (bl.size() == n)
    {
        if (sum == 0)
        {
            result.push_back(bl);
            return;
        }
        return;
    }

    bl += '(';
    sum += paren['('];
    solve(result, paren, bl, sum, n);

    bl.pop_back();
    sum -= paren['('];

    bl += ')';
    sum += paren[')'];
    solve(result, paren, bl, sum, n);

    bl.pop_back(); 
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    map<char, int> pr;
    std::string bl;
    bl.reserve(n * 2);
    pr.insert({'(', 1});
    pr.insert({')', -1});
    solve(result, pr, bl, 0, n*2);

    return result;
}

int main()
{

    int n;
    cin >> n;
    vector<string> res = generateParenthesis(n);
    cout << res.size() << endl;
    for (auto it : res)
    {
        cout << it << endl;
    }

    return 0;
}