
//�Z�O��/0-indexed/��ċA/(�傫��, �P�ʌ�)�ŏ�����
template<typename T>
struct segtree {
	//�؂�z��ł���킵������
	vector<T> seg;
	//�؂�1/2�̑傫��
	int siz;
	//�P�ʌ�
	const T e;
	//��r�֐��̌^
	using F = function<T(T, T)>;
	//�}�[�W����֐�
	const F f;

	//n �̑傫��, a (�P�ʌ�) �� segtree ������������
	segtree(int n, const T a, const F f) : e(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		seg.assign(2 * siz - 1, e);
		--siz;
	}

	//k (0-indexed) �Ԗڂ� t ����
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f �ɂ���Ė؂��\�z
	void build() {
		for (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
	}

	//i �Ԗڂ̗v�f��Ԃ�
	T operator[](const int i) {
		return seg[i + siz];
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

	//[a, b) �ɂ��� f �������ʂ�Ԃ�
	T query(int a, int b) {
		T l = e, r = e;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, seg[a++]);
			if (!(b & 1))r = f(seg[--b], r);
		}
		return f(l, r);
	}

	//[start, end) �ɂ��āA[l, r) �𒲂ׂȂ��� k �Ԗڂ� check �𖞂������񕪒T�� �Ōオ true �Ȃ� left, false �Ȃ� right f�̋t���Z
	template<typename C>
	int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const function<T(T, T)> revf) {
		//cerr << checknum << '\n';
		//�͈͊O�܂��͂��������łɖ������Ȃ��Ƃ�
		//cerr << k << ',' << checknum << '\n';
		if (start <= l && r <= end && !check(seg[k], checknum)) {
			checknum = revf(checknum, seg[k]);
			return -1;
		}
		if ((r <= start || l >= end)) {
			return -1;
		}
		//���ɗt
		if (k >= siz) {
			return k - siz;
		}
		int res;
		if (b) {
			//�����𒲂ׂ�
			res = find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
			//�������K���Ă��炻�ꂪ����
			if (res != -1)return (res);
			return find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
		}
		else {
			//�E���𒲂ׂ�
			res = find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
			//�E�����K���Ă��炻�ꂪ����
			if (res != -1)return (res);
			return find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
		}
	}

	template<typename C>
	int find_left(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	}

	template<typename C>
	int find_right(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	}

};