#include <vector>
using namespace std;

class OrgChart {
  public:
    char name;
    vector<OrgChart*> directReports;

    OrgChart(char name) {
      this->name = name;
      this->directReports = {};
    }
    
    void addDirectReports(vector<OrgChart*> directReports);
};

struct LCM {
	int reports;
	OrgChart* name;
};

LCM getLCM(OrgChart* topManager, OrgChart* reportOne, OrgChart* reportTwo) {
	int reports = 0;
	if (!topManager) return {0, NULL};
	if (topManager == reportOne || topManager == reportTwo) {
		reports++;
	}
	for (OrgChart* dr : topManager->directReports) {
		LCM lcm = getLCM(dr, reportOne, reportTwo);
		reports += lcm.reports;
		if (lcm.reports == 2) {
			return {2, lcm.name};
		}
	}
	return {reports, topManager};
}

OrgChart* getLowestCommonManager(OrgChart* topManager, OrgChart* reportOne, OrgChart* reportTwo) {
  // Write your code here.
	return getLCM(topManager, reportOne, reportTwo).name;
}