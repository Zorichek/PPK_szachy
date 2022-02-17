#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

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

int tablica[8][8] =
{
	W, S, G, H, K, G, S, W,
	P, P, P, P, P, P, P, P,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	P2, P2, P2, P2, P2, P2, P2, P2,
	W2, S2, G2, H2, K2, G2, S2, W2,
};



void arrangement(int figura, int end_x, int end_y, int start_x, int start_y) {
	tablica[end_x-1][end_y] = figura;
	tablica[start_x - 1][start_y] = 0;
}

int y_toint(char y_cord) {
	switch (y_cord)
	{
	case 'a': return 0;
	case 'b': return 1;
	case 'c': return 2;
	case 'd': return 3;
	case 'e': return 4;
	case 'f': return 5;
	case 'g': return 6;
	case 'h': return 7;
	default:
		break;
	}
}

bool W_move(int start_x, int start_y, int end_x, int end_y) {
	

	if (tablica[(start_x - 1)][start_y] != W) {
		return false;
	}

	if (end_x - 1 > 7 || end_y > 7 || end_x - 1 < 0 || end_y < 0) {
		return false;
	}

	if (tablica[end_x - 1][end_y] > 0) {
		return false;
	}
	
	bool check = true;
	
	if (start_x != end_x && start_y != end_y) {
		return false;
	}

	if (start_x != end_x) {
		if (end_x - start_x > 0) {
			for (int i = start_x-1; i < end_x-1; i++)
			{
				if (tablica[i+1][start_y] != 0 && i+1 != (end_x - 1)) {
					check = false;
					
				}
			}
		}

		if (end_x - start_x < 0) {
			for (int i = start_x-1; i > end_x-1; i--)
			{
				if (tablica[i-1][start_y] != 0 && i-1 != (end_x - 1)) {
					check = false;
				}
			}
		}
	}

	if (start_y != end_y) {
		if (end_y - start_y > 0) {
			for (int i = start_y; i < end_y; i++)
			{
				if (tablica[start_x-1][i+1] != 0 && i+1 != end_y) {
					check = false;

				}
			}
		}

		if (end_y - start_y < 0) {
			for (int i = start_y; i > end_y; i--)
			{
				if (tablica[start_x-1][i-1] != 0 && i-1 != end_y) {
					check = false;
				}
			}
		}
	}

	return check;

}

bool P_move(int start_x, int start_y, int end_x, int end_y) {

	if (tablica[(start_x - 1)][start_y] != P) {
		return false;
	}
	
	if (end_x - 1 > 7 || end_y > 7 || end_x - 1 < 0 || end_y < 0) {
		return false;
	}

	if (end_x - start_x == 1) {
		if (tablica[(end_x-1)][end_y] == 0) {
			return true;
		}

	}
	
	if (end_x - start_x == 2 && start_x == 2) {
		if (tablica[(end_x + 1)][end_y] == 0) {
			return true;
		}
	}

	if (end_x - start_x == 1) {
		if (end_y - start_y == 1 || end_y - start_y == -1) {
			if (tablica[end_x-1][end_y] < 0) {
				return true;
			}
		}
	}

	return false;
}





void turn() {    // funkcja testowa numer 1
	for (int a = 0; a < 8; a++)
	{
		if (a == 0) {
			cout << "A B C D E F G H" << endl << endl;
		}
		
		for (int b = 0; b < 8; b++)
		{
			cout << tablica[a][b] << " ";
			if (b == 7) {
				cout << "              " << a + 1;
			}
		}
		cout << endl;
	}
	string move;
	char figura;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	string start;
	string end;
	cout << "it's your turn" << endl;
	cin >> move;
	for (int a = 0; a < move.size(); a++)
	{
		if (move[a] == '-') {
			for (int b = a+1; b < move.size(); b++)
			{
				end += move[b];
			}
			break;
		}
		else {
			start += move[a];
		}

	}
	
	if (start.size() == 2) {
		figura = 'P';
		start_y = y_toint(start[0]);
		start_x = start[1] - '0';
		end_y = y_toint(end[0]);
		end_x = end[1] - '0';
	}
	else {
		figura = start[0];
		start_y = y_toint(start[1]);
		start_x = start[2] - '0';
		end_y = y_toint(end[0]);
		end_x = end[1] - '0';
	}

	switch (figura)
	{
	case 'P': 
		if (P_move(start_x, start_y, end_x, end_y)) {
			arrangement(P, end_x, end_y, start_x, start_y);
		}
		else {
			cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn();
		}
	case 'W':
		if (W_move(start_x, start_y, end_x, end_y)) {
			arrangement(W, end_x, end_y, start_x, start_y);
		}
		else {
			cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn();
		}

	default:

		turn();
	}
	turn();
}



int main() {


	

	turn();
}

