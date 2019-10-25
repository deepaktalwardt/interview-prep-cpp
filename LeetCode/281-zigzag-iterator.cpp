class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1(v1), v2(v2) {
        if (v1.size() != 0) {
            nextIsV1 = true;
        } else {
            nextIsV1 = false;
        }
        idx = 0;
    }

    int next() {
        int toReturn = nextIsV1 ?  v1[idx] : v2[idx];
        if (nextIsV1) {
            if (idx < v2.size()) {
                nextIsV1 = false;
            } else {
                idx++;
            }
        } else {
            if (++idx < v1.size()) {
                nextIsV1 = true;
            }
        }
        return toReturn;
    }

    bool hasNext() {
        if (nextIsV1 && idx < v1.size()) {
            return true;
        } else if (!nextIsV1 && idx < v2.size()) {
            return true;
        }
        return false;
    }
private:
    bool nextIsV1;
    int idx;
    vector<int> &v1, &v2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */