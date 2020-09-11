/*
* @title vector(2D)
* @docs kyopro/docs/vector2D.md
*/

struct vector2D {

	ll x, y;

	vector2D(ll x, ll y) : x(x), y(y) {}
	vector2D(ll stx, ll sty, ll enx, ll eny) : x(enx - stx), y(eny - sty) {}
	vector2D() : x(0), y(0) {}

	vector2D operator+(const vector2D p) { return vector2D(x + p.x, y + p.y); }
	vector2D operator-(const vector2D p) { return vector2D(x - p.x, y - p.y); }
	// スカラー倍
	vector2D operator*(const ll p) { return vector2D(x * p, y * p); }

};

inline ll vectorproduct(vector2D p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }
inline ll vectorproductcomp(vector2D p, vector2D q) { return p.x * q.y - p.y * q.x; }

inline bool comp(const vector2D& a, const vector2D& b) {
	if (a.x == 0 and a.y == 0)return true;
	else if (b.x == 0 and b.y == 0)return false;
	else if (a.x < 0) {
		if (b.x < 0) {
			return vectorproductcomp(a, b) > 0;
		}
		else {
			return false;
		}
	}
	else {
		if (b.x < 0) {
			return true;
		}
		else {
			return vectorproductcomp(a, b) > 0;
		}
	}
}