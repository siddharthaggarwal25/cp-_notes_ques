#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countPairs(vector<int> &numbers)
{
     unordered_map<int, vector<string>> digitGroups;
     int count = 0;

     // Group numbers by their digit lengths
     for (int num : numbers)
     {
          string numStr = to_string(num);
          int length = numStr.size();
          digitGroups[length].push_back(numStr);
     }

     // Check pairs in each group
     for (auto &group : digitGroups)
     {
          const vector<string> &nums = group.second;

          for (int i = 0; i < nums.size(); ++i)
          {
               for (int j = i + 1; j < nums.size(); ++j)
               {
                    int diffCount = 0;
                    for (int k = 0; k < nums[i].size(); ++k)
                    {
                         if (nums[i][k] != nums[j][k])
                         {
                              diffCount++;
                         }
                         if (diffCount > 1)
                         {
                              break;
                         }
                    }
                    if (diffCount == 1)
                    {
                         count++;
                    }
               }
          }
     }

     return count;
}

int main()
{
     vector<int> numbers = {1, 151, 241, 1, 9, 22, 351};
     cout << "Number of distinct pairs: " << countPairs(numbers) << endl;
     return 0;
}