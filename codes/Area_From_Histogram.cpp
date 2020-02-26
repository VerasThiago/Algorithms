int calc(stack<int> &s, vector<int> hist, int i){
	int top = s.top(); s.pop();
	int curr_area = hist[top] * (s.empty() ? i : i - s.top() - 1); 
	return curr_area;
}

int getMaxAreaFromHistogram(vector<int> hist){ 
    stack<int> s;
	int n = hist.size(), ans = 0, i = 0;
    while (i < n) { 
        if (s.empty() || hist[s.top()] <= hist[i]) s.push(i++); 
        else ans = max(ans, calc(s, hist, i));
    } 
    while (!s.empty()) ans = max(ans, calc(s, hist, i));
    return ans; 
}
