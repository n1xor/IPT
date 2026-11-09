#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool canSplit(vector<int>& a, int D, int x) {
	int days = 1;
	int start = 0;

	for (int i = 1; i < a.size(); i++) {
		if (a[i] - a[start] > x) {
			days++;
			start = i;
		}
	}

	return days <= D;
}



int main() {
	setlocale(LC_ALL, "ru");
	/*
		// Задание 1
	ifstream fin("../1.txt");
	if (!fin.is_open()) {
		cerr << "Не удалось открыть input.txt\n";
		return 1;
	}

	vector<vector<long long>> a;
	string line;
	while (getline(fin, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		vector<long long> row;
		long long x;
		while (ss >> x) row.push_back(x);
		if (!row.empty()) a.push_back(row);
	}
	fin.close();

	if (a.empty()) {
		cerr << "Файл пуст или не содержит чисел\n";
		return 1;
	}

	int N = (int)a.size();
	int M = (int)a[0].size();

	for (int i = 1; i < N; ++i) {
		if ((int)a[i].size() != M) {
			cerr << "Строки матрицы имеют разную длину\n";
			return 1;
		}
	}

	vector<vector<long long>> dp(N, vector<long long>(M));
	vector<vector<int>> from(N, vector<int>(M, 0));

	dp[0][0] = a[0][0];

	for (int j = 1; j < M; ++j) {
		dp[0][j] = dp[0][j - 1] + a[0][j];
		from[0][j] = 1;
	}
	for (int i = 1; i < N; ++i) {
		dp[i][0] = dp[i - 1][0] + a[i][0];
		from[i][0] = 0;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
				from[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i][j - 1] + a[i][j];
				from[i][j] = 1;
			}
		}
	}
	vector<pair<int, int>> path;
	int i = N - 1, j = M - 1;
	while (true) {
		path.push_back({ i, j });
		if (i == 0 && j == 0) break;
		if (from[i][j] == 0) --i;
		else --j;
	}
	reverse(path.begin(), path.end());

	for (auto& p : path)
		cout << p.first << ' ' << p.second << '\n';

	*/
	/*
	// Задание 2
	int N, D;
	cin >> N >> D;

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int left = -1;
	int right = a[N - 1] - a[0];

	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (canSplit(a, D, mid))
			right = mid;
		else
			left = mid;
	}

	cout << right << "\n";

	*/
	/*
	// Задание 3

	int N, K, L;
	cin >> N >> K >> L;

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	sort(a.rbegin(), a.rend());

	map<int, int> used;
	long long answer = 0;
	int taken = 0;

	for (int x : a) {
		if (used[x] < L) {
			answer += x;
			used[x]++;
			taken++;
			if (taken == K) break;
		}
	}

	cout << answer << "\n";*/
	// Задача 4
	ifstream fin("../4.txt");
	int N, M;
	fin >> N >> M;

	vector<vector<char>> g(N, vector<char>(M));
	int ei = N - 1, ej = M - 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			fin >> g[i][j];
			if (g[i][j] == 'E') { ei = i; ej = j; }
		}
	fin.close();

	vector<vector<int>> dp(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] == '1') continue;
			if (i == 0 && j == 0) { dp[0][0] = (g[0][0] == 'P'); continue; }

			int best = -1;
			if (i > 0) best = max(best, dp[i - 1][j]);
			if (j > 0) best = max(best, dp[i][j - 1]);

			if (best >= 0)
				dp[i][j] = best + (g[i][j] == 'P');
		}
	}

	cout << dp[ei][ej] << endl;


	return 0;
}