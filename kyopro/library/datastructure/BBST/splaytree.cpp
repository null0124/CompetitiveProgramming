template<typename T, typename F>
struct splaytree {

	const F f;
	const T e;

	struct node {
		T val, num;
		node* l, * r, * p;
		int siz;

		node() {
			l = r = p = nullptr;
			siz = 1;
			val = num = e;
		}

		void update() {
			this->siz = 1;
			this->num = this->val;
			if (this->l) {
				this->siz += this->l->siz;
				this->num = f(this->num, this->left->num);
			}
			if (this->r) {
				this->siz += this->r->siz;
				this->num = f(this->num, this->right->num);
			}
		}

		void rightrotate(node*& x) {
			x = this->l;
			this->l = x->r;
			x->rch = this;
		}

		void leftrotate(node*& x) {
			x = this->r;
			this->r = x->l;
			x->l = this;
		}


		int state() {
			if (not this->p)return 0;
			if (this->p->l == this)return 1;
			if (this->p->r == this)return -1;
			return 0;
		}

		void rotate() {
			node* p = this->p, * pp = p->p, * c;
			if (this->state() == 1)rightrotate(c);
			else leftrotate(c);
			if (pp and pp->l == p)pp->l = this;
			if (pp and pp->r == p)pp->r = this;
			this->p = pp;
			p->p = this;
			if (c)c->p = p;

			p->update();
			this->update();
		}

		void splay() {
			while (this->state()) {
				if (not this->p->state()) {
					this->rotate();
				}
				else if (this->state() == this->p->state()) {
					this->p->rotate();
					this->rotate();
				}
				else {
					this->rotate();
					this->rotate();
				}
			}
		}
	};

	vector<node> a;
	node* root;
	int n;

	splaytree(const int& n, const F& f, const T& e) : n(n), a(n), f(f), e(e) {
		rep(i, n - 1) {
			a[i].p = &a[i + 1];
			a[i + 1].l = &a[i];
			a[i + 1].update();
		}
		root = &a[n - 1];
	}

	void init(const vector<T>& v) {
		rep(i, n)a[i].val = v[i];
	}

	void set(const int& idx, T x) {
		a[idx] = x;
	}

	node* get(int ind) {
		node* cur = root;
		while (true) {
			int lsiz = (cur->l ? cur->l->siz : 0);
			if (ind < lsiz) {
				cur = cur->l;
			}
			if (ind == lsiz) {
				cur->splay();
				return (root = cur);
			}
			if (ind > lsiz) {
				cur = cur->r;
				ind = ind - lsiz - 1;
			}
		}
	}

};