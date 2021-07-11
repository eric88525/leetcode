class Solution {
public:
	int numTrees(int n) {

		vector<int> nodes(n + 1, 0);

		nodes[0] = 1, nodes[1] = 1;


		for (int i = 2; i <= n;i++) {

			for (int j = 0; j < i;j++) {

				nodes[i] += nodes[j] * nodes[i - j - 1];

			}
		}
		
		return nodes[n];
	
	}
};