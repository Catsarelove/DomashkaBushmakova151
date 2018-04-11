#pragma once
#include <fstream>
#include <map>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;
typedef  map<string, int> mymap;
typedef  map<char, int> mychmap;
mymap::iterator I;
mychmap::iterator CI;
locale l("");
struct UnP {
	string word;
	UnP(string s) {
		word = s;
	}
	bool operator ()(string s) const
	{
		bool flag = true;
        for (int i = 0, k = 0; i < word.length() && flag; i++, k++) {
			if (!isalpha(s[k], l) && k < s.length())
				k++;	
			else flag = !(k>=s.length() || (k<s.length() && toupper(s[k]) != toupper(word[i])) );
		}
		return flag;
	}
};
void cheat(string & word) {
	int i = 0;
	while (i != word.length() && (isalpha(word[i], l) || word[i]=='`' || word[i]=='-' || word[i]=='@'))
		i++;
	if (i != word.length()) {
		string news;
		for (int j = 0; j < i; j++) {
			news+= word[j];
		}
		swap<string>(word, news);
	}
	for (int j = 0; j < i; j++) {
		word[j]=toupper(word[j]);
	}
}
int freq(mymap& Voc, string word) {
	cheat(word);
	I = Voc.find(word);
	if (I != Voc.end())
		return Voc[word];
	else
		return 0;
}
void seevoc(mymap& Voc) {
	for (I = Voc.begin(); I != Voc.end(); I++) {
		cout << I->first << " встречается " << I->second << " раз(a)\n";
	}
}
void seevoc(mymap& Voc, ofstream &f) {
	f << "       Словарик вхождений         \n";
	for (I = Voc.begin(); I != Voc.end(); I++) {
		f << I->first << " встречается " << I->second << " раз(a)\n";
	}
}
void fill(mymap& Voc, ifstream & f) {
	f.clear();
	f.seekg(0);
	string word;
	while (!f.eof()) {
		f >> word;
		cheat(word);
		I = Voc.find(word);
		if (I != Voc.end())
			Voc[word]++;
		else
			Voc[word] = 1;

	}
}
void findinfile(ifstream &f, string word) {
	f.clear();
	f.seekg(0);
	bool found = false;
	UnP p(word);
	istream_iterator<string> eof;
	found = find_if(istream_iterator<string>(f), eof, p) != eof;
    if (found)
		cout << "найдено\n";
	else
		cout << "не найдено \n";
}
void fill(mychmap& ChVoc, ifstream &f) {
	f.clear();
	f.seekg(0);
	char c;
	while (!f.eof()) {
		f >> c;
		CI = ChVoc.find(c);
		if (CI != ChVoc.end())
			ChVoc[c]++;
		else
			ChVoc[c] = 1;

	}
}
void seevoc(mychmap& ChVoc, ofstream &f) {
	f << "       Частота вхождений символов        \n";
	for (CI = ChVoc.begin(); CI != ChVoc.end(); CI++) {
		f << CI->first << " встречается " << CI->second << " раз(a)\n";
	}
}
int freq(mychmap& ChVoc, char c) {
	CI = ChVoc.find(c);
	if (CI != ChVoc.end())
		return ChVoc[c];
	else
		return 0;
}
