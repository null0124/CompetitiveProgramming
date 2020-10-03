---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/splaytree.md
    document_title: splay-tree
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/BBST/splaytree.cpp\"\n\uFEFF\
    /*\n* @title splay-tree\n* @docs kyopro/docs/splaytree.md\n*/\n\ntemplate<typename\
    \ T>\nstruct splaytree {\n\n\tstruct node {\n\t\tnode* left, * right, * parent;\n\
    \t\tint siz;\n\t\tT val;\n\t\tnode(T e) {\n\t\t\tleft = rught = parent = nullptr;\n\
    \t\t\tsiz = 1;\n\t\t\tval = e;\n\t\t}\n\n\t\tint state() {\n\t\t\tif (not this->parent)return\
    \ 0;//\u89AA\u304C\u3044\u306A\u3044\n\t\t\telse if (this->parent->left == this)return\
    \ 1;//\u89AA\u306E\u5DE6\n\t\t\telse if (this->parent->right == this)return -1;//\u89AA\
    \u306E\u53F3\n\t\t\treturn 0;\n\t\t}\n\n\t\tvoid rotate() {\n\t\t\tnode* p = this->parent,\
    \ * pp = p->parent, * c;\n\n\t\t\tif (p->left == this) {\n\t\t\t\tc = this->right;\n\
    \t\t\t\tthis->right = p;\n\t\t\t\tp->left = c;\n\t\t\t}\n\t\t\telse {\n\t\t\t\t\
    c = this->left;\n\t\t\t\tthis->left = p;\n\t\t\t\tp->right = c;\n\t\t\t}\n\n\t\
    \t\tif (pp and this->parent->parent->left == this->parent)this->parent->parent->left\
    \ = this;\n\t\t\telse if (pp) this->parent->parent->right = this;\n\n\t\t\tthis->parent\
    \ = pp;\n\t\t\tp->parent = this;\n\t\t\tp->left = c;\n\n\t\t\tif (c)c->parent\
    \ = p;\n\n\t\t\tp->update();\n\t\t\tthis->update();\n\t\t}\n\n\t\tvoid splay()\
    \ {\n\t\t\twhile (this->state()) {\n\t\t\t\tif (this->parent->state() == 0) {\n\
    \t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\telse if (this->state() == this->parent->state())\
    \ {\n\t\t\t\t\tthis->parent->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\
    \t\t\t\telse {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\n\t\tvoid update() {\n\t\t\tthis->siz = 1;\n\t\t\tif (this->left)this->siz\
    \ += this->left->siz;\n\t\t\tif (this->right)this->siz += this->right->siz;\n\t\
    \t}\n\t};\n\n\tnode* get(int idx, node* root) {\n\t\tnode* now = root;\n\t\tint\
    \ lsiz = now->left ? now->left->siz : 0;\n\t\twhile (idx != lsiz) {\n\t\t\tif\
    \ (idx < lsiz) {\n\t\t\t\tnow = now->left;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tnow\
    \ = now->right;\n\t\t\t\tidx = idx - lsiz - 1;\n\t\t\t}\n\t\t}\n\t\tnow->splay();\n\
    \t\treturn now;\n\t}\n\n};\n"
  code: "\uFEFF/*\n* @title splay-tree\n* @docs kyopro/docs/splaytree.md\n*/\n\ntemplate<typename\
    \ T>\nstruct splaytree {\n\n\tstruct node {\n\t\tnode* left, * right, * parent;\n\
    \t\tint siz;\n\t\tT val;\n\t\tnode(T e) {\n\t\t\tleft = rught = parent = nullptr;\n\
    \t\t\tsiz = 1;\n\t\t\tval = e;\n\t\t}\n\n\t\tint state() {\n\t\t\tif (not this->parent)return\
    \ 0;//\u89AA\u304C\u3044\u306A\u3044\n\t\t\telse if (this->parent->left == this)return\
    \ 1;//\u89AA\u306E\u5DE6\n\t\t\telse if (this->parent->right == this)return -1;//\u89AA\
    \u306E\u53F3\n\t\t\treturn 0;\n\t\t}\n\n\t\tvoid rotate() {\n\t\t\tnode* p = this->parent,\
    \ * pp = p->parent, * c;\n\n\t\t\tif (p->left == this) {\n\t\t\t\tc = this->right;\n\
    \t\t\t\tthis->right = p;\n\t\t\t\tp->left = c;\n\t\t\t}\n\t\t\telse {\n\t\t\t\t\
    c = this->left;\n\t\t\t\tthis->left = p;\n\t\t\t\tp->right = c;\n\t\t\t}\n\n\t\
    \t\tif (pp and this->parent->parent->left == this->parent)this->parent->parent->left\
    \ = this;\n\t\t\telse if (pp) this->parent->parent->right = this;\n\n\t\t\tthis->parent\
    \ = pp;\n\t\t\tp->parent = this;\n\t\t\tp->left = c;\n\n\t\t\tif (c)c->parent\
    \ = p;\n\n\t\t\tp->update();\n\t\t\tthis->update();\n\t\t}\n\n\t\tvoid splay()\
    \ {\n\t\t\twhile (this->state()) {\n\t\t\t\tif (this->parent->state() == 0) {\n\
    \t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\t\t\t\telse if (this->state() == this->parent->state())\
    \ {\n\t\t\t\t\tthis->parent->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t}\n\
    \t\t\t\telse {\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\tthis->rotate();\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\n\t\tvoid update() {\n\t\t\tthis->siz = 1;\n\t\t\tif (this->left)this->siz\
    \ += this->left->siz;\n\t\t\tif (this->right)this->siz += this->right->siz;\n\t\
    \t}\n\t};\n\n\tnode* get(int idx, node* root) {\n\t\tnode* now = root;\n\t\tint\
    \ lsiz = now->left ? now->left->siz : 0;\n\t\twhile (idx != lsiz) {\n\t\t\tif\
    \ (idx < lsiz) {\n\t\t\t\tnow = now->left;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tnow\
    \ = now->right;\n\t\t\t\tidx = idx - lsiz - 1;\n\t\t\t}\n\t\t}\n\t\tnow->splay();\n\
    \t\treturn now;\n\t}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/BBST/splaytree.cpp
  requiredBy: []
  timestamp: '2020-05-19 18:57:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/datastructure/BBST/splaytree.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/BBST/splaytree.cpp
- /library/kyopro/library/datastructure/BBST/splaytree.cpp.html
title: splay-tree
---
﻿
## 説明
splay tree 

## 使い方
未完成  

## 計算量
う  

