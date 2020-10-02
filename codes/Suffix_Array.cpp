// n log² n 
class SuffixArray {
public:
    template<class T>
    vector<int> buildSuffix(const T &array) {
        int n = array.size();
        vector<int> sa(n);
        for(int i = 0; i < n; i++) {
            sa[i] = i;
        }
        sort(sa.begin(), sa.end(), [&](int a, int b) { return array[a] < array[b]; });
        int cur = 0;
        vector<int> inv(n);
        vector<int> nxt(n);
        inv[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            inv[sa[i]] = (array[sa[i - 1]] != array[sa[i]] ? ++cur : cur);
        }
        cur++;
        for(int k = 0; cur < n; k++) {
            cur = 0;
            auxSort(sa, inv, 1 << k);
            for(int l = 0, r = 0; l < n; l = r, cur++) {
                while(r < n && getPair(inv, sa[l], 1 << k) == getPair(inv, sa[r], 1 << k)) {
                    nxt[sa[r++]] = cur;
                }
            }
            nxt.swap(inv);
        }
        return sa;
    }
 
    template<class T>
    vector<int> buildLCP(const vector<int> &sa, const T &array) {
        int n = sa.size();
        vector<int> inv(n);
        for(int i = 0; i < n; i++) {
            inv[sa[i]] = i;
        }
        vector<int> lcp(n, 0);
        for(int i = 0, k = 0; i < n; i++) {
            if(inv[i] + 1 == n) {
                k = 0;
                continue;
            }
            int j = sa[inv[i] + 1];
            while(i + k < n && j + k < n && array[i + k] == array[j + k]) {
                k++;
            }
            lcp[inv[i]] = k;
            if(k > 0) {
                k--;
            }
        }
        return lcp;
    }
private:
    void auxSort(vector<int> &sa, const vector<int> &inv, int offset) {
        // O(nlogn) step, O(nlog^2n) total
        sort(sa.begin(), sa.end(), [&](int a, int b) { return getPair(inv, a, offset) < getPair(inv, b, offset); });
        // O(n) step, O(nlogn) total -- TO DO --
    }
    pair<int, int> getPair(const vector<int> &inv, int pos, int offset) {
        return pair<int, int>(inv[pos], pos + offset < (int) inv.size() ? inv[pos + offset] : -1);
    }
};