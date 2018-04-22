#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct Smth {
	string filename = "File.txt";
	fstream f;
    Smth() {
		f.open(filename);
	}
    char toc(char* c) {
		int s = 0;
		int j = 1;
		for (int i = 7; i >= 0; i--) {
			s += (c[i] == '1')*j;
			j *= 2;
		}
		char ch = (char)s;
		return ch;
	}
	int* tobin(char c) {
		int* buff = new int[8];
		int t = (int)c;
		int i = 7;
		while (t != 0) {
			buff[i] = (t % 2 == 1);
			t /= 2;
			i--;
		}
		for (int o = 0; o <= i; o++) {
			buff[o] = 0;
		}
		return buff;
	}
	void backtonorm(ofstream & a) {
		char* buff;
		while (!f.eof()) {
			buff = new char[8];
			for (int o = 0; o < 8; o++)
				f >> buff[o];
			char c = toc(buff);
			delete[] buff;
			a << c;
		}
		f.seekg(0);
	}
	void trtobin(ifstream & b) {
		char c;
		int* buff;
		while (!b.eof()) {
			b.get(c);
			if (b.eof()) break;
			buff = new int[8];
			buff=tobin(c);
			for (int i = 0; i < 8; i++)
            f << buff[i];
			delete[] buff;
		}
		f.seekg(0);
		b.seekg(0);
	}
	~Smth() {
		f.close();
	}
};
