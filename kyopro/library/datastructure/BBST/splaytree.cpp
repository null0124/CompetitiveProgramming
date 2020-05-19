template<typename T>
struct splaytree {

	struct node {
		node* left, * right, * parent;
		int siz;
		T val;
		node(T e) {
			left = rught = parent = nullptr;
			siz = 1;
			val = e;
		}

		int state() {
			if (not this->parent)return 0;//親がいない
			else if (this->parent->left == this)return 1;//親の左
			else if (this->parent->right == this)return -1;//親の右
			return 0;
		}

		void rotate() {
			node* p = this->parent, * pp = p->parent, * c;

			if (p->left == this) {
				c = this->right;
				this->right = p;
				p->left = c;
			}
			else {
				c = this->left;
				this->left = p;
				p->right = c;
			}

			if (pp and this->parent->parent->left == this->parent)this->parent->parent->left = this;
			else if (pp) this->parent->parent->right = this;

			this->parent = pp;
			p->parent = this;
			p->left = c;

			if (c)c->parent = p;

			p->update();
			this->update();
		}

		void splay() {
			while (this->state()) {
				if (this->parent->state() == 0) {
					this->rotate();
				}
				else if (this->state() == this->parent->state()) {
					this->parent->rotate();
					this->rotate();
				}
				else {
					this->rotate();
					this->rotate();
				}
			}
		}

		void update() {
			this->siz = 1;
			if (this->left)this->siz += this->left->siz;
			if (this->right)this->siz += this->right->siz;
		}
	};

	node* get(int idx, node* root) {
		node* now = root;
		int lsiz = now->left ? now->left->siz : 0;
		while (idx != lsiz) {
			if (idx < lsiz) {
				now = now->left;
			}
			else {
				now = now->right;
				idx = idx - lsiz - 1;
			}
		}
		now->splay();
		return now;
	}

};