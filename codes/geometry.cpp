typedef struct {    
  long long x,y;
}Point;
 
long long get_line_dist(Point p1, Point p2){
  long long dx = p1.x - p2.x;
  long long dy = p1.y - p2.y;
  return ((dx * dx) + (dy * dy));
}
 
class Rect{
 
  public:
 
    Point b, t;
 
    Rect(int bx, int by, int tx, int ty){
      b.x = bx;
      b.y = by;
      t.x = tx;
      t.y = ty;
    }
 
    Rect(){
      b.x = b.y = t.x = t.y = 0;
    }
 
    bool check_area(){
      if( (t.x - b.x < 0) or (t.y - b.y) < 0)
        return false;
      return true;
    }
 
    long long area(){
        if(!check_area()) return 0;
        return ((t.y - b.y) * (t.x - b.x));
    }
 
    Rect intersect(Rect r){
      Rect inter;
      inter.t.x = min(t.x, r.t.x);
      inter.b.x = max(b.x, r.b.x);
      inter.t.y = min(t.y, r.t.y);
      inter.b.y = max(b.y, r.b.y);
      return inter;
    }
 
};

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
		area = area.intersect(rec[i]);;

	if(area.check_area())
		// Existe intercessão de todos os retangulos
	return 0;
}
