#include <bits/stdc++.h>

using namespace std;

int minDeletion(vector<int>& nums) {
    int ans = 0;
    auto iter = nums.begin();
    while (iter != nums.end() && next(iter) != nums.end()) {
		if (*iter == *next(iter)) { ans++;}
		else {
			iter = next(iter);
		}
		iter = next(iter);
    }
    if ((nums.size() - ans) % 2 !=0) ans++;
    return ans;
}

int main() {
    vector<int> nums;
    char ch;
    int v;
    cin >> ch;
    do {
        cin >> v;
        nums.push_back(v);
        cin >> ch;
    } while (ch == ',');
    cout << minDeletion(nums) << '\n';
    return 0;
}
