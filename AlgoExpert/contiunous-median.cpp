#include <queue>

using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
  public:
    double median;
		priority_queue<int, vector<int>> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;

    void insert(int number) {
      // Write your code here.
			if (empty(max_heap)) {
				max_heap.emplace(number);
				median = number;
				return;
			} else {
				if (number < max_heap.top()) {
					max_heap.emplace(number);
				} else {
					min_heap.emplace(number);
				}
				
				if (min_heap.size() - max_heap.size() == 2) {
					max_heap.emplace(min_heap.top());
					min_heap.pop();
				} else if (max_heap.size() - min_heap.size() == 2) {
					min_heap.emplace(max_heap.top());
					max_heap.pop();
				}
				
				if (min_heap.size() == max_heap.size()) {
					median = (double) (min_heap.top() + max_heap.top()) / 2.0;
				} else if (min_heap.size() < max_heap.size()) {
					median = (double) max_heap.top();
				} else {
					median = (double) min_heap.top();
				}
				return;
			}
    }

    double getMedian() {
      return median;
    }
};