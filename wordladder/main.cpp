/**
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
    每次转换只能改变一个字母。
    转换过程中的中间单词必须是字典中的单词。
    说明:

    如果不存在这样的转换序列，返回 0。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。 
 * 
 **/
#include <bits/stdc++.h>

using namespace std;

bool isAdjc(string &a, string &b);

class Solution {
    public:
    /**
     * C++ program to find length of the shortest 
     * transformation from source to target
     * Returns length of shortest chain to target
     * using minimum number of adjacent moves.
     **/
    int ladderLength(string beginWord, string endWord,
    vector<string>& wordList) {
        int count = 0;
        queue<string> Q;
        Q.push(beginWord);

        while (!Q.empty()) {
            string last = Q.front();
            for (string &s : wordList) {
                if (isAdjc(s, last) && s != last) {
                    Q.push(s);
                    if (isAdjc(s, endWord)) break;
                }
            }
            Q.pop();
        }
        return count;
    }
};

// detect whether a string is another string adjacent
bool isAdjc(string &a, string &b) {
    if (a.size() != b.size()) return false;
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) count++;
    }
    if (count == 1) return true;
    return false;
}

int main()
{
    Solution s;
    string beginWord("hit");
    string endWord("cog");
    vector<string> worldList = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength(beginWord, endWord, worldList);
    return 0;
}