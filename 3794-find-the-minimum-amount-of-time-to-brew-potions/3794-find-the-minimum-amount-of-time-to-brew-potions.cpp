#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    ll minTime(vector<int>& skillPower, vector<int>& manaCost) {
        int skillCount = skillPower.size(), manaCount = manaCost.size();
        vector<ll> totalTime(skillCount + 1, 0);
        
        loop(j, manaCount) {
            loop(i, skillCount) {
                totalTime[i + 1] = max(totalTime[i + 1], totalTime[i]) + 1LL * manaCost[j] * skillPower[i];
            }
            for(int i = skillCount - 1; i > 0; i--) {
                totalTime[i] = totalTime[i + 1] - 1LL * manaCost[j] * skillPower[i];
            }
        }
        
        return totalTime[skillCount];
    }
};
