#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;
int main()
{

	setlocale(LC_ALL, "ru");
	//Задание 1
	int N;

	/*
	//Способ 1

	cout << "Ведите N\n";
	cin >> N;
	*/
	//Способ 2

	ifstream file("../Task 1.txt");
	if (file.is_open()) {

		string line;
		getline(file, line);
		file.close();
		N = stoi(line);
	}
	else {
		cerr << "Не удалось открыть файл!\n";
		return 0;
	}
	for (int i = N - 1; i > -1; i--) {
		for (int i1 = 0; i1 < N; i1++) {
			if (i1 < i) {
				cout << "0";
			}
			else if (i1 == i) {
				cout << "1";
			}
			else {
				cout << "2";
			}
		}
		cout << "\n";
	}

	//Задание 2
	bool Grid[33][33] = { false };
	int N, M, W;
	/*
	//Способ 1
	cout << "Введите N, M, W\n";
	cin >> N >> M >> W;
	for (int k = 0; k < W; k++) {
		int r, c;
		cout << "Введите сначала координату по x, потом по y\n";
		cin >> r >> c;
		Grid[r][c] = true;
	}
	*/
	//Способ 2
	ifstream file("../Task 2.txt");
	if (file.is_open()) {
		string line;
		int i = 0;
		int r, c;
		while (getline(file, line)) {
			if (i == 0) N = stoi(line);
			else if (i == 1) M = stoi(line);
			else if (i == 2) W = stoi(line);
			else {
				if (i % 2 == 1) r = stoi(line);
				else {
					c = stoi(line);
					Grid[r][c] = true;
				}
			}
			i++;
		}
		file.close();
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {

			if (Grid[i][j]) {
				cout << '*';
			}
			else {
				int cnt = 0;

				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (di == 0 && dj == 0) continue;
						int ni = i + di;
						int nj = j + dj;
						if (ni >= 1 && ni <= M && nj >= 1 && nj <= N) {
							if (Grid[ni][nj]) {
								cnt++;
							}
						}
					}
				}
				cout << cnt;
			}
		}
		cout << '\n';
	}

	//Задание 3

	int N;
	string X;
	/*
	//Способ 1
	cout << "Ведите X\n";
	cin >> X;

	cout << "Ведите N\n";
	cin >> N;
	*/
	//Способ 2
	ifstream file("../Task 3.txt");
	if (file.is_open()) {
		string line;
		int i = 0;
		while (getline(file, line)) {
			if (i == 0) X = line;
			else N = stoi(line);
			i++;
		}
		file.close();
	}
	else {
		cerr << "Не удалось открыть файл!\n";
		return 0;
	}
	regex re(R"(([0-9])\1*)");
	for (int i = 0; i < N; i++) {
		vector<string> find(
			sregex_token_iterator(X.cbegin(), X.cend(), re),
			sregex_token_iterator()
		);
		X = "";
		for (const auto& s : find) {
			X += to_string(s.size()) + s[0];
		}
		cout << X << "\n";
	}
	return 0;




}


