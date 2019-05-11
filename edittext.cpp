/*
	Given a non-empty input file,
 	remove all characters &, # 
 	and the consecutive duplicates of the * character
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;

inline bool isbad(const char& c) {
	return (c == '*') || (c == '#') || (c == '&');
} 

int main(){
	char temp;
	string s;
	ifstream input;
	ofstream output;
	input.open("input.txt");
	if(input){
		while(!input.eof()){
			input >> temp;
			s.push_back(temp);
		}
		input.close();

		auto end = std::unique(s.begin(), s.end(),
		[](char l, char r){
			return isbad(l) && isbad(r) && (l == r);
		});
		s.erase(end, s.end());

		output.open("output.txt");
		for(auto &c : s){
			if(c != '&' && c != '#')
				output << c;
		}
		output.close();
	}
	else cout << "No such file";

	return 0;
}