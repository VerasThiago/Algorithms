typedef struct {		
	int x,y;
}Point;

typedef struct{
	Point b, t;
}Rect;
long long get_line_dist(Point p1, Point p2){
	long long dx = p1.x - p2.x;
	long long dy = p1.y - p2.y;
	return ((dx * dx) + (dy * dy));
}

bool check_rec_area(Rect r){
	if( (r.t.x - r.b.x < 0) or (r.t.y - r.b.y) < 0)
		return false;
	return true;
}

Rect get_rec_intersection(Rect r1, Rect r2){
	
	Rect r;

	r.t.x = min(r1.t.x,r2.t.x);
	r.b.x = max(r1.b.x,r2.b.x);
	r.t.y = min(r1.t.y,r2.t.y);
	r.b.y = max(r1.b.y,r2.b.y);

	return r;
}
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	
	Point line[n];

	for(int i = 0; i < n; i++)
		scanf("%d %d", &line[i].x, &line[i].y);

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			cout << "Dist de " << i << " - " << j << " = " << sqrt(get_line_dist(line[i],line[j])) << endl; 
		
	Rect rec[m];

	for(int i = 0; i < m; i++)
		scanf("%d %d %d %d",&rec[i].b.x, &rec[i].b.y, &rec[i].t.x, &rec[i].t.y );
	
	Rect area;

	area = rec[0];
	
	for(int i = 0; i < m; i++)
		area = get_newArea(rec[i],area);

	if(ok(area))
		// Existe intercessão de todos os retangulos
	return 0;
}
