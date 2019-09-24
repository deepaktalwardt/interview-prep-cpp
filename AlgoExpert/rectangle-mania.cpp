#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
  int x;
  int y;
	
	bool isTopRight(Point& other) {
		return other.x > x && other.y > y;
	}
	
	string getName() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
};

bool formsRectangle(Point& p1, Point& p2, unordered_map<string, Point>& points) {
	Point topLeft({p1.x, p2.y});
	Point bottomRight({p2.x, p1.y});
	return points.find(topLeft.getName()) != points.end() && points.find(bottomRight.getName()) != points.end();
}


int rectangleMania(vector<Point> coords) {
  // Write your code here.
	unordered_map<string, Point> points;
	for (Point& p : coords) {
		string name = p.getName();
		points[name] = p;
	}
	
	int numRectangles = 0;
	
	for (auto it1 = points.begin(); it1 != points.end(); it1++) {
		Point currPoint = it1->second;
		for (auto it2 = points.begin(); it2 != points.end(); it2++) {
			Point candidateDiagonal = it2->second;
			if (currPoint.isTopRight(candidateDiagonal)) {
				if (formsRectangle(currPoint, candidateDiagonal, points)) numRectangles++;
			}
		}
	}
	return numRectangles;
}