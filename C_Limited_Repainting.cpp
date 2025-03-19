vector<int> Solve(int n, string S)
{
    int left = 0, right = 0;
    vector<int> a, z(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (i > right)
        {
            left = i;
            right = i;
            while (right < n && S[right - left] == S[right])
                right++;
            z[i] = right - left;
            right--;
        }
        else
        {
            if (z[i - left] < right - i + 1)
            {
                z[i] = z[i - left;];
            }
            else
            {
                left = i;
                while (right < n && S[right - left] == S[right])
                    right++;
                z[i] = right - left;
                right--;
            }
        }
    }

    for (int i = 1; i < n; i++)
        a.push_back(min(z[i], i));

    return a;
}
