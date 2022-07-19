---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/BBST/splaytree.cpp\"\n\uFEFF\
    template<typename T, typename F>\nstruct splaytree {\n\n\tconst F f;\n\tconst\
    \ T e;\n\n\tstruct node {\n\t\tT val, num;\n\t\tnode* l, * r, * p;\n\t\tint siz;\n\
    \n\t\tnode() {\n\t\t\tl = r = p = nullptr;\n\t\t\tsiz = 1;\n\t\t\tval = num =\
    \ e;\n\t\t}\n\n\t\tvoid update() {\n\t\t\tthis->siz = 1;\n\t\t\tthis->num = this->val;\n\
    \t\t\tif (this->l) {\n\t\t\t\tthis->siz += this->l->siz;\n\t\t\t\tthis->num =\
    \ f(this->num, this->left->num);\n\t\t\t}\n\t\t\tif (this->r) {\n\t\t\t\tthis->siz\
    \ += this->r->siz;\n\t\t\t\tthis->num = f(this->num, this->right->num);\n\t\t\t\
    }\n\t\t}\n\n\t\tvoid rightrotate(node*& x) {\n\t\t\tx = this->l;\n\t\t\tthis->l\
    \ = x->r;\n\t\t\tx->rch = this;\n\t\t}\n\n\t\tvoid leftrotate(node*& x) {\n\t\t\
    \tx = this->r;\n\t\t\tthis->r = x->l;\n\t\t\tx->l = this;\n\t\t}\n\n\n\t\tint\
    \ state() {\n\t\t\tif (not this->p)return 0;\n\t\t\tif (this->p->l == this)return\
    \ 1;\n\t\t\tif (this->p->r == this)return -1;\n\t\t\treturn 0;\n\t\t}\n\n\t\t\
    void rotate() {\n\t\t\tnode* p = this->p, * pp = p->p, * c;\n\t\t\tif (this->state()\
    \ == 1)rightrotate(c);\n\t\t\telse leftrotate(c);\n\t\t\tif (pp and pp->l == p)pp->l\
    \ = this;\n\t\t\tif (pp and pp->r == p)pp->r = this;\n\t\t\tthis->p = pp;\n\t\t\
    \tp->p = this;\n\t\t\tif (c)c->p = p;\n\n\t\t\tp->update();\n\t\t\tthis->update();\n\
    \t\t}\n\n\t\tvoid splay() {\n\t\t\twhile (this->state()) {\n\t\t\t\tif (not this->p->state())\
    \ {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\telse if (this->state() == this->p->state())\
    \ {\n\t\t\t\t\tthis->p->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\
    \telse {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t};\n\n\tvector<node> a;\n\tnode* root;\n\tint n;\n\n\tsplaytree(const\
    \ int& n, const F& f, const T& e) : n(n), a(n), f(f), e(e) {\n\t\trep(i, n - 1)\
    \ {\n\t\t\ta[i].p = &a[i + 1];\n\t\t\ta[i + 1].l = &a[i];\n\t\t\ta[i + 1].update();\n\
    \t\t}\n\t\troot = &a[n - 1];\n\t}\n\n\tvoid init(const vector<T>& v) {\n\t\trep(i,\
    \ n)a[i].val = v[i];\n\t}\n\n\tvoid set(const int& idx, T x) {\n\t\ta[idx] = x;\n\
    \t}\n\n\tnode* get(int ind) {\n\t\tnode* cur = root;\n\t\twhile (true) {\n\t\t\
    \tint lsiz = (cur->l ? cur->l->siz : 0);\n\t\t\tif (ind < lsiz) {\n\t\t\t\tcur\
    \ = cur->l;\n\t\t\t}\n\t\t\tif (ind == lsiz) {\n\t\t\t\tcur->splay();\n\t\t\t\t\
    return (root = cur);\n\t\t\t}\n\t\t\tif (ind > lsiz) {\n\t\t\t\tcur = cur->r;\n\
    \t\t\t\tind = ind - lsiz - 1;\n\t\t\t}\n\t\t}\n\t}\n\n};\n"
  code: "\uFEFFtemplate<typename T, typename F>\nstruct splaytree {\n\n\tconst F f;\n\
    \tconst T e;\n\n\tstruct node {\n\t\tT val, num;\n\t\tnode* l, * r, * p;\n\t\t\
    int siz;\n\n\t\tnode() {\n\t\t\tl = r = p = nullptr;\n\t\t\tsiz = 1;\n\t\t\tval\
    \ = num = e;\n\t\t}\n\n\t\tvoid update() {\n\t\t\tthis->siz = 1;\n\t\t\tthis->num\
    \ = this->val;\n\t\t\tif (this->l) {\n\t\t\t\tthis->siz += this->l->siz;\n\t\t\
    \t\tthis->num = f(this->num, this->left->num);\n\t\t\t}\n\t\t\tif (this->r) {\n\
    \t\t\t\tthis->siz += this->r->siz;\n\t\t\t\tthis->num = f(this->num, this->right->num);\n\
    \t\t\t}\n\t\t}\n\n\t\tvoid rightrotate(node*& x) {\n\t\t\tx = this->l;\n\t\t\t\
    this->l = x->r;\n\t\t\tx->rch = this;\n\t\t}\n\n\t\tvoid leftrotate(node*& x)\
    \ {\n\t\t\tx = this->r;\n\t\t\tthis->r = x->l;\n\t\t\tx->l = this;\n\t\t}\n\n\n\
    \t\tint state() {\n\t\t\tif (not this->p)return 0;\n\t\t\tif (this->p->l == this)return\
    \ 1;\n\t\t\tif (this->p->r == this)return -1;\n\t\t\treturn 0;\n\t\t}\n\n\t\t\
    void rotate() {\n\t\t\tnode* p = this->p, * pp = p->p, * c;\n\t\t\tif (this->state()\
    \ == 1)rightrotate(c);\n\t\t\telse leftrotate(c);\n\t\t\tif (pp and pp->l == p)pp->l\
    \ = this;\n\t\t\tif (pp and pp->r == p)pp->r = this;\n\t\t\tthis->p = pp;\n\t\t\
    \tp->p = this;\n\t\t\tif (c)c->p = p;\n\n\t\t\tp->update();\n\t\t\tthis->update();\n\
    \t\t}\n\n\t\tvoid splay() {\n\t\t\twhile (this->state()) {\n\t\t\t\tif (not this->p->state())\
    \ {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\telse if (this->state() == this->p->state())\
    \ {\n\t\t\t\t\tthis->p->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\
    \telse {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t};\n\n\tvector<node> a;\n\tnode* root;\n\tint n;\n\n\tsplaytree(const\
    \ int& n, const F& f, const T& e) : n(n), a(n), f(f), e(e) {\n\t\trep(i, n - 1)\
    \ {\n\t\t\ta[i].p = &a[i + 1];\n\t\t\ta[i + 1].l = &a[i];\n\t\t\ta[i + 1].update();\n\
    \t\t}\n\t\troot = &a[n - 1];\n\t}\n\n\tvoid init(const vector<T>& v) {\n\t\trep(i,\
    \ n)a[i].val = v[i];\n\t}\n\n\tvoid set(const int& idx, T x) {\n\t\ta[idx] = x;\n\
    \t}\n\n\tnode* get(int ind) {\n\t\tnode* cur = root;\n\t\twhile (true) {\n\t\t\
    \tint lsiz = (cur->l ? cur->l->siz : 0);\n\t\t\tif (ind < lsiz) {\n\t\t\t\tcur\
    \ = cur->l;\n\t\t\t}\n\t\t\tif (ind == lsiz) {\n\t\t\t\tcur->splay();\n\t\t\t\t\
    return (root = cur);\n\t\t\t}\n\t\t\tif (ind > lsiz) {\n\t\t\t\tcur = cur->r;\n\
    \t\t\t\tind = ind - lsiz - 1;\n\t\t\t}\n\t\t}\n\t}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/BBST/splaytree.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/datastructure/BBST/splaytree.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/BBST/splaytree.cpp
- /library/kyopro/library/datastructure/BBST/splaytree.cpp.html
title: kyopro/library/datastructure/BBST/splaytree.cpp
---
