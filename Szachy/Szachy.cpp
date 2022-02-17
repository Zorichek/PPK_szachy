#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

#include "funkcje.h"

int main() {

	const int P = 1;
	const int S = 2;
	const int G = 3;
	const int W = 4;
	const int H = 5;
	const int K = 6;

	const int P2 = -1;
	const int S2 = -2;
	const int G2 = -3;
	const int W2 = -4;
	const int H2 = -5;
	const int K2 = -6;



	/*vector < vector <int> > tablica =
	{
		{W , S , G , H , K , 0 , 0 , W },
		{P , P , P , P , P , 0 , P , P },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0,  0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{P2 , P2 , P2 , P2 , P2 , P2 , P2 , P2 },
		{W2 , S2 , G2 , H2 , K2 , G2 , S2 , W2 }
	};*/
	
	vector < vector <int> > tablica =
	{
		{0 , 0 , 0 , K , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0,  0 , W2 , 0 , 0 },
		{0 , 0 , 0 , 0 , W2 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , K2 , 0 }
	};

	vector < vector <bool> > tablica1 =
	{
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0,  0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
	};

	turn(tablica , tablica1);
	
}


