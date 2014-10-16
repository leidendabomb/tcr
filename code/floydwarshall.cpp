// Dist[i][j] moet geinitialiseerd worden op een arbitrair grote
// waarde "O" voor alle knopen die geen verbinding hebben.
//
// Pas op voor overflow, O mag maximaal limit::max() / 2 zijn.

for (int k = 0; k < N; k++) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}
