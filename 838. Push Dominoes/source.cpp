class Solution {
public:

	string pushDominoes(string dominoes) {


        // last position & last sign
		pair<int, char> lastInfo = make_pair(0, 'L');

		for (int i = 0; i < dominoes.size(); i++) {

			if (dominoes[i] == '.') continue;

		    // 遇到連續兩個相同
			if (dominoes[i] == lastInfo.second) {
				for (int j = lastInfo.first; j < i; j++) {
					dominoes[j] = dominoes[i];
				}
			}
			// 能組成一組
			else if (lastInfo.second == 'R' &&   dominoes[i] == 'L') {
				int range = (i - lastInfo.first - 1) / 2;
				for (int j = 1; j <= range; j++) {
					dominoes[lastInfo.first + j] = 'R';
					dominoes[i - j] = 'L';
				}
			}
			lastInfo = make_pair(i, dominoes[i]);

		}

		if (lastInfo.second == 'R') {
			for (int i = lastInfo.first; i < dominoes.size(); i++) {
				dominoes[i] = 'R';
			}
		}

		return dominoes;
	}
};
