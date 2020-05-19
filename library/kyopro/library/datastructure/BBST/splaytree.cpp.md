---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: splay-tree

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#69df2a6b39f1dc68c8ea69e0fa166f43">kyopro/library/datastructure/BBST</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/datastructure/BBST/splaytree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 18:57:10+09:00




﻿
## なに
splay tree 

## 使い方
未完成  

## 計算量
う  



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title splay-tree
* @docs kyopro/docs/splaytree.md
*/

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/datastructure/BBST/splaytree.cpp"
﻿/*
* @title splay-tree
* @docs kyopro/docs/splaytree.md
*/

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

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

