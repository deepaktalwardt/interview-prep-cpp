#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
  public:
    vector<int> heap;

    MinHeap(vector<int> vector) {
      heap = buildHeap(&vector);
    }

    vector<int> buildHeap(vector<int>* vector) {
      // Write your code here.
			int lastParentIdx = (vector->size() - 2) / 2;
			while (lastParentIdx >= 0) {
				siftDown(lastParentIdx, vector->size() - 1, vector);
				lastParentIdx--;
			}
			return *vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int>* heap) {
      // Write your code here.
			int childOneIdx = 2 * currentIdx + 1;
			while (childOneIdx <= endIdx) {
				int childTwoIdx = 2 * currentIdx + 2 <= endIdx ? 2 * currentIdx + 2 : -1;
				int swapWithAt = childOneIdx;
				if (childTwoIdx != -1) {
					swapWithAt = heap->at(childOneIdx) < heap->at(childTwoIdx) ? childOneIdx : childTwoIdx;
				}
				if (heap->at(currentIdx) > heap->at(swapWithAt)) {
					swap(heap, currentIdx, swapWithAt);
					currentIdx = swapWithAt;
					childOneIdx = 2 * currentIdx + 1;
				} else {
					return;
				}
			}
    }

    void siftUp(int currentIdx, vector<int>* heap) {
      // Write your code here.
			int parIdx = (currentIdx - 1) / 2;
			int parent = heap->at(parIdx);
			while (currentIdx > 0 && parent > heap->at(currentIdx)) {
				swap(heap, currentIdx, parIdx);
				currentIdx = parIdx;
				parIdx = (currentIdx - 1) / 2;
				parent = heap->at(parIdx);
			}
    }

    int peek() {
      // Write your code here.
			return heap.front();
    }

    int remove() {
      // Write your code here.
			swap(&heap, 0, heap.size() - 1);
			int valueToRemove = heap.back();
			heap.pop_back();
			siftDown(0, heap.size() - 1, &heap);
			return valueToRemove;
    }

    void insert(int value) {
      // Write your code here.
			heap.push_back(value);
			siftUp(heap.size() - 1, &heap);
    }
	
    void swap(vector<int>* vec, int idx1, int idx2) {
        int temp = vec->at(idx1);
        vec->at(idx1) = vec->at(idx2);
        vec->at(idx2) = temp;
    }
};
