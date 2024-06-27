void north(int initial_y)
{
    initial_y++;
}
void south(int initial_y)
{
    initial_y--;
}
void east(int initial_x)
{
    initial_x++;
}
void west(int initial_x)
{
    initial_x--;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        vector<int> count(4, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
            {
                count[0]++;
            }
            else if (s[i] == 'S')
            {
                count[1]++;
            }
            else if (s[i] == 'E')
            {
                count[2]++;
            }
            else
            {
                count[3]++;
            }
        }
        if ((count[2] - count[3]) % 2 != 0 || (count[1] - count[0]) % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int finalx = (count[2] - count[3]) / 2;
            int finaly = (count[0] - count[1]) / 2;
            string ans = "";
            int rx = 0, ry = 0, hx = 0, hy = 0;
            int ch = 0, cr = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'N')
                {
                    if (ry < finaly)
                    {
                        if (hy < finaly && ch == 0)
                        {
                            north(hy);
                            ch += 1;
                            ans += 'H';
                        }
                        else
                        {
                            north(ry);
                            cr += 1;
                            ans += 'R';
                        }
                    }
                    else
                    {
                        if (hy > finaly && cr == 0)
                        {
                            north(ry);
                            cr += 1;
                            ans += 'R';
                        }
                        else
                        {
                            north(hy);
                            ch += 1;
                            ans += 'H';
                        }
                    }
                }
                else if (s[i] == 'S')
                {
                    if (ry > finaly)
                    {
                        if (hy > finaly && ch == 0)
                        {
                            south(hy);
                            ch += 1;
                            ans += 'H';
                        }
                        else
                        {
                            south(ry);
                            cr += 1;
                            ans += 'R';
                        }
                    }
                    else
                    {
                        if (hy < finaly && cr == 0)
                        {
                            south(ry);
                            cr += 1;
                            ans += 'R';
                        }
                        else
                        {
                            south(hy);
                            ch += 1;
                            ans += 'H';
                        }
                    }
                }
                else if (s[i] == 'E')
                {
                    if (rx < finalx)
                    {
                        if (hx < finalx && ch == 0)
                        {
                            east(hx);
                            ch++;
                            ans += 'H';
                        }
                        else
                        {
                            east(rx);
                            cr++;
                            ans += 'R';
                        }
                    }
                    else
                    {
                        if (hx > finalx && cr == 0)
                        {
                            east(rx);
                            cr++;
                            ans += 'R';
                        }
                        else
                        {
                            east(hx);
                            ch++;
                            ans += 'H';
                        }
                    }
                }
                else
                {
                    if (rx > finalx)
                    {
                        if (hx > finalx && ch == 0)
                        {
                            west(hx);
                            ch++;
                            ans += 'H';
                        }
                        else
                        {
                            west(rx);
                            cr++;
                            ans += 'R';
                        }
                    }
                    else
                    {
                        if (hx < finalx && cr == 0)
                        {
                            west(rx);
                            cr++;
                            ans += 'R';
                        }
                        else
                        {
                            west(hx);
                            ch++;
                            ans += 'H';
                        }
                    }
                }
            }
            if (ch == 0 || cr == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}

#include <bits/stdc++.h>
struct Node
{
    Node *link[26];
    bool flag = false;
    bool checklink(char ch) { return link[ch - 'a'] != NULL; }
} class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->checklink[word[i]])
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
} string completeString(int n, vector<string> &a)
{
    // Write your code here.
}

#include <bits/stdc++.h>
struct Node
{
    Node *link[26];
    bool flag = false;
    bool checklink(char ch) { return link[ch - 'a'] != NULL; }
    void setEnd() { flag = true; }
    void put(char ch, Node *node) { link[ch - 'a'] = node; }
    Node *get(char ch) { return link[ch - 'a']; }
    bool getend() { return flag; }
};
 class Trie
{
private:
    Node *root;
public:
    Trie() { root = new Node(); }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->checklink[word[i]])
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExist(string word)
    {
        Node *node = root;
        bool flag = true;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->checklink(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if (!node->getend())
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie trie;
    for (auto child : a)
    {
        trie.insert(child);
    }
    string longest = "";
    for (auto str : a)
    {
        if (trie.checkIfPrefixExist(str))
        {
            if (str.length > longest.length)
            {
                longest = str;
            }
            else if (longest.lenght == str.lenght && longest > str)
            {
                longest = str;
            }
        }

    }
        return longest;
}