#include <bits/stdc++.h>

using namespace std;

class DisjoinSet
{
    unordered_map<int, int> parent;
public:
// perform makeset operation
    void makeSet(vector<int> const& universe) {
        for (int i : universe) parent[i] = i;
    }
    int Find(int k) {
        if (parent[k] == k) {
            return k;
        }

        return Find(parent[k]);
    }

    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        parent[x] = y;
    }
};

void printSets(vector<int> const &universe, DisjoinSet ds)
{
    for (int i : universe) {
        cout << ds.Find(i) << " ";
    }
    cout << endl;
}

// Demo
int main()
{
    vector<int> universe = {1,2,3,4,5};
    DisjoinSet ds;
    ds.makeSet(universe);
    printSets(universe, ds);
    ds.Union(4, 3);
    ds.Union(2,1);
    ds.Union(1,3);
    printSets(universe, ds);
    return 0;
}