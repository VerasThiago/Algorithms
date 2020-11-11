#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

using namespace std;

template <class Info = int, class T = int>
struct ColorUpdate {
public:
	struct Range {
		Range(T _l = 0) : l(_l) {}
		Range(T _l, T _r, Info _v) : l(_l), r(_r), v(_v) { }
		T l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> erase(T l, T r) {
		std::vector<Range> ans;
		if(l > r) return ans;
		auto it = ranges.lower_bound(l);
		if(it != ranges.begin()) {
			it--;
			if(it->r > l) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, l, cur.v));
				ranges.insert(Range(l, cur.r, cur.v));
			}
		}
		it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->r > r) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, r, cur.v));
				ranges.insert(Range(r, cur.r, cur.v));
			}
		}
		for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
			ans.push_back(*it);
		}
		ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
		return ans;
	}

	std::vector<Range> upd(T l, T r, Info v) {
        r++; // To make range inclusive
		auto ans = erase(l, r);
		ranges.insert(Range(l, r, v));
		return ans;
	}

	bool exists(T x) {
		auto it = ranges.upper_bound(x);
		if(it == ranges.begin()) return false;
		it--;
		return it->l <= x && x < it->r;
	}
	std::set<Range> ranges;
};

ColorUpdate<long long,long long> base;
map<long long, int> table;

void updateFrequency(vector<ColorUpdate<long long,long long>::Range> v){
    for(auto x : v){
        table[x.v] -= x.r - x.l; // not + 1 because R is not inclusive
    }
}

/*
    {1,1,4,6,7,7,7,10}
    vector<Range> = {
        {0, 2, 1},
        {2, 3, 4},
        {3, 4, 6},
        {4, 7, 7},
        {7, 8, 10},
    }

*/

void solve(){
    
    int n = 10, L = 4, R = 7;
    base.upd(0, n - 1, 1); // start all list with 1's
    table[1] = n; // update 1 frequency

    int newColor = 8;
    auto result = base.upd(L, R, newColor);
    updateFrequency(result);
    table[newColor] += R - L + 1; // +1 because R is inclusive here 

}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

