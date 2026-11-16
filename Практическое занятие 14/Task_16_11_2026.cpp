
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;
//Задание 3
class MyStack {
private:
	std::vector<int> data;  
	std::vector<int> mins;  

public:
	void push(int x) {
		data.push_back(x);
		if (mins.empty()) {
			mins.push_back(x);              
		}
		else {
			mins.push_back(std::min(x, mins.back())); 
		}
	}

	int pop() {
		if (data.empty())
			throw std::runtime_error("pop из пстого массива");
		int value = data.back();
		data.pop_back();
		mins.pop_back();
		return value;              

	}

	bool empty() const {
		return data.empty();
	}

	int getMin() const {
		return mins.back();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	// Задание 1
	
	string input ;
	cin >> input;
	vector<char> s;
	for (char& c : input) {
		if (c == '(' || c == ')') {
			s.push_back(c);
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (char& i : s) {
		if (i == '(') {
			if (cnt2 != 0) {
				if (cnt1 != cnt2) {
					cout << "no\n";
					return 0;
				}
				cnt2 = 0;
				cnt1 = 0;
			}
			cnt1++;
		}
		else if (i == ')') {
			cnt2++;
		}
	}
	if (cnt1 != cnt2) {
		cout << "no\n";
		return 0;
	}
	cout << "yes";
	//Задание 2
	
	
	string input;
	cin >> input;
	vector<string> del = { ",","."," - ","!","?"};
	for (const std::string& d : del) {
		size_t pos;
		while ((pos = input.find(d)) != std::string::npos)
			input.erase(pos, d.size());
	}
	vector<string> words;
	istringstream iss(input);
	string word;
	while (iss >> word)
		words.push_back(word);
	for (string& s : words) {
		for (char& sym : s) {
			sym = tolower(sym);
		}
	}
	set<string> setWords(words.begin(), words.end());
	for (const string& s : setWords) {
		cout << s << "\n";
	}

}

