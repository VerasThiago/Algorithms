class SegTree{
	
  vector<int> st;
	int n;
 
	void upd(int p, int nodeL, int nodeR, int queryL, int queryR, int v){
 
		if(queryR <  nodeL or  queryL >  nodeR) return;
		if(queryL <= nodeL and queryR >= nodeR){
			st[p] = v;
			return;
		}
 
		int mid = (nodeL + nodeR) / 2;
 
		upd(2*p,   nodeL, mid,   queryL, queryR, v);
		upd(2*p+1, mid+1, nodeR, queryL, queryR, v);
 
		st[p] = max(st[2*p], st[2*p+1]);
	}
	
	int qry(int p, int nodeL, int nodeR, int queryL, int queryR){
 
		if(queryR <  nodeL or  queryL >  nodeR) return 0;
		if(queryL <= nodeL and queryR >= nodeR) return st[p];
 
		int mid = (nodeL + nodeR) / 2;
 
		return max(qry(2*p, nodeL, mid, queryL, queryR), qry(2*p+1, mid+1, nodeR, queryL, queryR));
	}
 
public:
 
	SegTree(int sz){
		n = sz;
		st.assign(5*(n + 1), 0);
	}
 
	int qry(int i, int j){
		return qry(1, 1, n, i, j);
	}
 
	void upd(int i, int j, int v){
		upd(1, 1, n, i, j, v);
	}
 
};