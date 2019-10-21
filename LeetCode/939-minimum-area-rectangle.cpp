
// Time: O(N^2), Spoce: O(N)
#include <unordered_map>

class Solution {
public:
    struct Point {
        int x;
        int y;
        
        Point() {
            x = 0;
            y = 0;
        }
        
        Point(int x_, int y_) {
            x = x_;
            y = y_;
        }

        bool isTopRight(Point& other) {
            return other.x > x && other.y > y;
        }

        string getName() {
            return "(" + to_string(x) + ", " + to_string(y) + ")";
        }
    };
    
    int areaFormed(Point p1, Point p2, unordered_map<string, Point>& pointsMap) {
        Point topLeft(p1.x, p2.y);
        Point bottomRight(p2.x, p1.y);
        if (pointsMap.find(topLeft.getName()) != pointsMap.end() && pointsMap.find(bottomRight.getName()) != pointsMap.end()) {
            return (p2.y - p1.y) * (p2.x - p1.x);
        } else {
            return -1;
        }
    }
    
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INT_MAX;
        unordered_map<string, Point> pointsMap;
        for (vector<int>& p : points) {
            Point pn(p[0], p[1]);
            string name = pn.getName();
            pointsMap[name] = pn;
        }
        for (auto it1 = pointsMap.begin(); it1 != pointsMap.end(); it1++) {
            Point currPoint = it1->second;
            for (auto it2 = pointsMap.begin(); it2 != pointsMap.end(); it2++) {
                Point candidateDiagonal = it2->second;
                if (currPoint.isTopRight(candidateDiagonal)) {
                    int area = areaFormed(currPoint, candidateDiagonal, pointsMap);
                    if (area != -1) {
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};