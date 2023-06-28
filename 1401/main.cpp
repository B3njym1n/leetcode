#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearest_point_x;
        int nearest_point_y;
        if (xCenter >= x1 && xCenter <= x2)
        {
            nearest_point_x = xCenter;
        }
        else
        {
            nearest_point_x = abs(xCenter - x1) < abs(xCenter - x2)? x1 : x2;
        }
        if (yCenter >= y1 && yCenter <= y2)
        {
            nearest_point_y = yCenter;
        }
        else
        {
            nearest_point_y = abs(yCenter - y1) < abs(yCenter -y2)? y1 : y2;
        }
        return (radius * radius) >= (nearest_point_x - xCenter) * ((nearest_point_x - xCenter)) + \
            (nearest_point_y - yCenter) * (nearest_point_y - yCenter);
    }
};

int main()
{
    Solution s;
    assert(s.checkOverlap(1,0,0,1,-1,3,1));
    return 0;
}