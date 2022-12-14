#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>
#include <cmath>
#include <libgen.h>

using namespace std;

template<typename U, typename V> ostream &operator<<(ostream &os, const pair<U, V> &p) {return os << '(' << p.first << ", " << p.second << ')';}
template<typename Container,typename T = typename enable_if<!is_same<Container, string>::value, typename Container::value_type>::type>ostream &operator<<(ostream &os, const Container &v) {os << "{";for (int i = 0; i < v.size(); i++) {os << v[i];if (i < v.size()-1)os << ", ";}os << "}"; return os;}

static inline void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> static inline void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...);}

#ifdef DEBUG
#define dbg(...) cerr << __LINE__ << ": " << #__VA_ARGS__ << " =", dbg_out(__VA_ARGS__);
#else
# define dbg(x)
#endif


struct anthill {
	pair<int, int> pos;
	vector<string> out;

	anthill(pair<int,int> p = {0, 0}) : pos(p), out(0) {}
};

void parse(map<string, anthill> &graph, vector<vector<string>> &paths, string &start, string &end);

static inline void die(const char *msg) {
	std::cerr << "\x1b[1;91mError\x1b[0m: " << msg << std::endl;
	exit(1);
}