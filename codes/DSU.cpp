int p[N];
int s[N];
 
int find(int a) {
  if (p[a] == a) return a;
  return p[a] = find(p[a]);
}
 
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}


int main(){
    for(int i = 0; i < N; i++)p[i] = i, s[i] = 1;
}