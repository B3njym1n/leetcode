#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto word : words) {
            m[word]++;
        }
        struct {
            bool operator() (const pair<string, int>& l, const pair<string, int>& r) const {
                return l.second == r.second ? l.first > r.first : l.second < r.second;
            }
        } customComp;
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(customComp)> pq;
        for (auto entry : m) {
            pq.emplace(entry.first, entry.second);
        }
        vector<string> ans;
        for (int i = 0; i < k; ++i) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};

int main() 
{
    // vector<string> words {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    // int k = 4;
    vector<string> words {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution s;
    cout << '[';
    for (auto v : s.topKFrequent(words, k)) {
        cout << v << ", ";
    }
    cout << "]\n";
    return 0;
}