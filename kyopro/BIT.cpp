
template<typename T>
//0-indexed/�����I�� 1-indexed
struct BIT {
	vector<T> tree;
	//������
	BIT(int n) : tree(n) {
		tree.assign(n + 1, 0);
	}

	int LSB(int n) { return (n & (-n)); }

	//[0, n) �� sum ��Ԃ�/0-indexed
	T sum(int n) {
		T ret = 0;
		//���� 1-indexed �������J��ԂȂ̂Ō����ڂ����̂܂�
		for (; n >= 0; n -= LSB(n)) {
			ret += tree[n];
			if (!n)break;
		}
		return ret;
	}


	//[i, j) �� sum ��Ԃ�/0-indexed
	T sum(int i, int j) {;
		return sum(j) - sum(i);
	}

	//n �Ԗڂ� x �𑫂�
	void add(int n, T x) {
		int siz = tree.size();
		for (++n; n < siz; n += LSB(n))tree[n] += x;
	}
};