//�Z�O��/0-indexed/��ċA/n �̑傫��, a (�P�ʌ�), �{�̂̃}�[�W�֐�, �x���m�[�h�̒P�ʌ�, �x���m�[�h�̃}�[�W�֐�, �x���m�[�h�Ɩ{�̂̃}�[�W�֐� �� segtree ������������
template<typename T, typename U>
struct lazysegtree {
	//�؂�z��ł���킵������
	vector<T> seg;
	//�x���m�[�h
	vector<U> lazy;
	//�T�C�Y�m�[�h
	vector<int> size;
	//�x���m�[�h�̃t���O�Ǘ�
	vector<bool> flag;
	//�؂�1/2�̑傫��
	int siz, height;
	//�{�̂̒P�ʌ�
	const T se;
	//�x���m�[�h�̒P�ʌ�
	const U le;
	//�{�̂̃}�[�W�֐��̌^
	using F = function<T(T, T)>;
	//�x���m�[�h�̃}�[�W�֐��̌^
	using F2 = function<U(U, U)>;
	//�x���m�[�h�Ɩ{�̂̃}�[�W�֐��̌^
	using F3 = function<T(T, U)>;
	//�T�C�Y���g�������Z������֐��̌^
	using F4 = function<U(U, int)>;
	//�{�̓��m���}�[�W����֐�
	const F f;
	//�x���m�[�h���m���}�[�W����֐�
	const F2 f2;
	//�x���m�[�h�Ɩ{�̂��}�[�W����֐�
	const F3 f3;
	//�T�C�Y���g�������Z������֐�
	const F4 f4;

	//n �̑傫��, a (�P�ʌ�), �{�̂̃}�[�W�֐�, �x���m�[�h�̒P�ʌ�, �x���m�[�h�̃}�[�W�֐�, �x���m�[�h�Ɩ{�̂̃}�[�W�֐�, �T�C�Y���g�������Z������֐� �� segtree ������������
	lazysegtree(int n, const T se, const F f, const U le, const F2 f2, const F3 f3, const F4 f4) : se(se), f(f), le(le), f2(f2), f3(f3), f4(f4) {
		siz = 1;
		height = 0;
		while (siz < n)siz <<= 1, ++height;
		seg.assign(2 * siz - 1, se);
		lazy.assign(2 * siz - 1, le);
		size.assign(2 * siz - 1, 1);
		flag.assign(2 * siz - 1, false);
		--siz;
	}

	//k (0-indexed) �Ԗڂ� t ����
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f �ɂ���Ė؂��\�z
	void build() {
		for (int i = siz - 1; i >= 0; --i) {
			seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
			size[i] = size[i * 2 + 1] + size[i * 2 + 2];
		}
	}

	//i �Ԗڂ̗v�f��Ԃ�
	T operator[](const int i) {
		return query(i, i + 1);
	}

	//k �Ԗڂ̒x���m�[�h��`�d����
	inline T merge(int k) {
		return (!flag[k] ? seg[k] : f3(seg[k], f4(lazy[k], size[k])));
	}

	//�q�ɓ`�d
	inline void eval(int k) {
		if (flag[k]) {
			lazy[k * 2 + 1] = f2(lazy[k * 2 + 1], lazy[k]);
			lazy[k * 2 + 2] = f2(lazy[k * 2 + 2], lazy[k]);
			flag[k * 2 + 1] = flag[k * 2 + 2] = true;
			seg[k] = merge(k);
			lazy[k] = le;
			flag[k] = false;
		}
	}

	inline void bottomup(int k) {
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(merge(2 * k + 1), merge(2 * k + 2));
		}
	}

	inline void topdown(int k) {
		for (int i = height; i > 0; --i) {
			eval(((k + 1) >> i) - 1);
		}
	}

	//k �Ԗڂ̒l�� a �ɍX�V
	void update(int k, T a) {
		k += siz;
		//�K�v�ł���΂�����ς���
		seg[k] = a;
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}

	//[l, r) �̒l�� a �ɍX�V
	void update(int l, int r, T a) {
		int x = l + siz, y = r + siz - 1;
		topdown(x);
		topdown(y);
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (!(l & 1)) {
				lazy[l] = f2(lazy[l], a);
				flag[l] = true;
				++l;
			}
			if (!(r & 1)) {
				--r;
				lazy[r] = f2(lazy[r], a);
				flag[r] = true;
			}
		}
		bottomup(x);
		bottomup(y);
	}

	//[a, b) �ɂ��� f �������ʂ�Ԃ�
	T query(int a, int b) {
		topdown(a += siz);
		topdown(b += siz - 1);
		T l = se, r = se;
		for (++b; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, merge(a++));
			if (!(b & 1))r = f(merge(--b), r);
		}
		return f(l, r);
	}


	////[start, end) �ɂ��āA[l, r) �𒲂ׂȂ��� k �Ԗڂ� check �𖞂������񕪒T�� �Ōオ true �Ȃ� left, false �Ȃ� right f�̋t���Z
	//template<typename C>
	//int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const function<T(T, T)> revf) {
	//	//cerr << checknum << '\n';
	//	//�͈͊O�܂��͂��������łɖ������Ȃ��Ƃ�
	//	//cerr << k << ',' << checknum << '\n';
	//	if (start <= l && r <= end && !check(seg[k], checknum)) {
	//		checknum = revf(checknum, seg[k]);
	//		return -1;
	//	}
	//	if ((r <= start || l >= end)) {
	//		return -1;
	//	}
	//	//���ɗt
	//	if (k >= siz) {
	//		return k - siz;
	//	}
	//	int res;
	//	if (b) {
	//		//�����𒲂ׂ�
	//		res = find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//		//�������K���Ă��炻�ꂪ����
	//		if (res != -1)return (res);
	//		return find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//	}
	//	else {
	//		//�E���𒲂ׂ�
	//		res = find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//		//�E�����K���Ă��炻�ꂪ����
	//		if (res != -1)return (res);
	//		return find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//	}
	//}

	//template<typename C>
	//int find_left(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
	//	return find< C >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	//}

	//template<typename C>
	//int find_right(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
	//	return find< C >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	//}

};
