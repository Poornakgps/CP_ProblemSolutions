#include <bits/stdc++.h>
using namespace std;

int lazy[40000000];

void shift(int id){
	if(lazy[id])
		lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
	lazy[id] = 0;
}

void upd(int x,int y,int color, int id = 0,int l = 0,int r = 10000000){//painting the interval [x,y) whith color "color"
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y){
		lazy[id] = color;
		return ;
	}
	int mid = (l+r)/2;
	shift(id);
	upd(x, y, color, 2 * id, l, mid);
	upd(x, y, color, 2*id+1, mid, r);
}

set <int> se;
void cnt(int id = 1,int l = 0,int r = 10000000){
	if(lazy[id]){
		se.insert(lazy[id]);
		return ; // there is no need to see the children, because all the interval is from the same color
	}
	if(r - l < 2)	return ;
	int mid = (l+r)/2;
	cnt(2 * id, l, mid);
	cnt(2*id+1, mid, r);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(lazy, 0, sizeof lazy);
        int color=1;
        for(int i=0; i<n; i++){
            int l, r;
            cin >> l >> r;
            upd(l, r, color++);
        }
        se.clear();
        upd(0, n, 1);
        cnt();
        cout << se.size() << endl;
    }
}