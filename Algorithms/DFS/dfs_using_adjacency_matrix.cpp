#define total_nodes 100
vector<bool> visited[total_nodes];
vector<vector<int>> matrix(total_nodes, vector<int> (total_nodes));

void dfs(int cur_node) {
	visited[cur_node] = 1;
	for (int i = 0; i < total_nodes; ++i) {
		if(!visited[matrix[cur_node][i]]) {
			dfs(matrix[cur_node][i]);
		}
	}
	return;
}