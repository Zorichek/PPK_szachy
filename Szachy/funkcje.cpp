#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

#include "funkcje.h"




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



string figura_name(int figura_number) {
	switch (figura_number)
	{
	case -1: return "P2";
	case -2: return "S2";
	case -3: return "G2";
	case -4: return "W2";
	case -5: return "H2";
	case -6: return "K2";
	case 0: return "0";
	case 1: return "P";
	case 2: return "S";
	case 3: return "G";
	case 4: return "W";
	case 5: return "H";
	case 6: return "K";
	default:
		break;
	}
}


bool H_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {

	if (player) {
		if (tablica[start_x][start_y] != 5) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -5) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) { // czy nie wyjdzie za tą tablicę
		return false;
	}



	if (abs(end_x - start_x) == abs(end_y - start_y)) {

		if (end_x - start_x > 0 && end_y - start_y > 0) {
			for (int a = start_x + 1; a < end_x; a++)
			{
				for (int b = start_y + 1; b < end_y; b++)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x > 0 && end_y - start_y < 0) {
			for (int a = start_x + 1; a < end_x; a++)
			{
				for (int b = start_y - 1; b > end_y; b--)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x < 0 && end_y - start_y > 0) {
			for (int a = start_x - 1; a > end_x; a--)
			{
				for (int b = start_y + 1; b < end_y; b++)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x < 0 && end_y - start_y < 0) {
			for (int a = start_x - 1; a > end_x; a--)
			{
				for (int b = start_y - 1; b > end_y; b--)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		return true;
	}

	if (start_x != end_x && start_y != end_y) {
		return false;
	}


	if (start_x != end_x && start_y == end_y) {
		if (end_x - start_x > 0) {
			for (int i = start_x + 1; i < end_x; i++)
			{
				if (tablica[i][start_y] != 0) {
					return false;
				}
			}
		}
		else {
			for (int i = start_x - 1; i > end_x; i--)
			{
				if (tablica[i][start_y] != 0) {
					return false;
				}
			}
		}
	}

	if (start_y != end_y && start_x == end_x) {
		if (end_y - start_y > 0) {
			for (int i = start_y + 1; i < end_y; i++)
			{
				if (tablica[start_x][i] != 0) {
					return false;
				}
			}
		}
		else {
			for (int i = start_y - 1; i > end_y; i--)
			{
				if (tablica[start_x][i] != 0) {
					return false;
				}
			}
		}
	}

	return true;
}



bool G_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {


	if (player) {
		if (tablica[start_x][start_y] != 3) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -3) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) { // czy nie wyjdzie za tą tablicę
		if (!player) {
			cout << "suko" << endl;
		}
		return false;
	}

	if (start_x == end_x && start_y == end_y) {
		return false;
	}

	if (abs(end_x - start_x) == abs(end_y - start_y)) {

		if (end_x - start_x > 0 && end_y - start_y > 0) {
			for (int a = start_x + 1; a < end_x; a++)
			{
				for (int b = start_y + 1; b < end_y; b++)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x > 0 && end_y - start_y < 0) {
			for (int a = start_x + 1; a < end_x; a++)
			{
				for (int b = start_y - 1; b > end_y; b--)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x < 0 && end_y - start_y > 0) {
			for (int a = start_x - 1; a > end_x; a--)
			{
				for (int b = start_y + 1; b < end_y; b++)
				{
					if (abs(end_x - a) == abs(end_y - b)) {
						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		if (end_x - start_x < 0 && end_y - start_y < 0) {
			for (int a = start_x - 1; a > end_x; a--)
			{
				for (int b = start_y - 1; b > end_y; b--)
				{
					if (abs(end_x - a) == abs(end_y - b)) {

						if (tablica[a][b] != 0) {
							return false;
						}
					}
				}
			}
		}

		return true;
	}


	return false;
}


bool S_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {


	if (player) {
		if (tablica[start_x][start_y] != 2) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -2) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) { // czy nie wyjdzie za tą tablicę
		return false;
	}



	for (int a = -2; a < 3; a++) // skript jaki sprawdza prawidlowość ruchu
	{
		for (int b = -2; b < 3; b++)
		{
			if (end_x - start_x == a && end_y - start_y == b && abs(a) != abs(b) && end_x - start_x != 0 && end_y - start_y != 0) {
				return true;
			}
		}
	}


	return false;
}

bool W_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {



	if (player) {
		if (tablica[start_x][start_y] != 4) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -4) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) {
		return false;
	}

	if (start_x == end_x && start_y == end_y) {
		return false;
	}

	if (start_x != end_x && start_y != end_y) {
		return false;
	}


	if (start_x != end_x && start_y == end_y) {
		if (end_x - start_x > 0) {
			for (int i = start_x + 1; i < end_x; i++)
			{
				if (tablica[i][end_y] != 0) {
					return false;
				}
			}
		}
		else {
			for (int i = start_x - 1; i > end_x; i--)
			{
				if (tablica[i][end_y] != 0) {
					return false;
				}
			}
		}
	}

	if (start_y != end_y && start_x == end_x) {
		if (end_y - start_y > 0) {
			for (int i = start_y + 1; i < end_y; i++)
			{
				if (tablica[end_x][i] != 0) {
					return false;
				}
			}
		}
		else {
			for (int i = start_y - 1; i > end_y; i--)
			{
				if (tablica[end_x][i] != 0) {

					return false;
				}
			}
		}

	}

	return true;

}

bool P_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {


	if (player) {
		if (tablica[start_x][start_y] != 1) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -1) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) {
		return false;
	}

	if (player) {
		if ((end_x - start_x == 1 && (start_y == end_y)) && (tablica[end_x][end_y] == 0)) {
			return true;
		}

		if (((end_x - start_x == 2 && (start_y == end_y)) && (tablica[end_x][end_y] == 0) && (tablica[end_x - 1][end_y] == 0)) && start_x == 1)
		{
			return true;
		}

		if (((end_x - start_x == 1) && (end_y - start_y == 1 || end_y - start_y == -1)) && (tablica[end_x][end_y] < 0)) {
			return true;
		}
	}
	else {
		if ((end_x - start_x == -1 && (start_y == end_y)) && (tablica[end_x][end_y] == 0)) {
			return true;
		}

		if (((end_x - start_x == -2 && (start_y == end_y)) && (tablica[end_x][end_y] == 0) && (tablica[end_x + 1][end_y] == 0)) && start_x == 6)
		{
			return true;
		}
		if (((end_x - start_x == -1) && (end_y - start_y == 1 || end_y - start_y == -1)) && (tablica[end_x][end_y] > 0)) {
			return true;
		}
	}


	return false;
}

bool K_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica) {

	if (end_x > 7 || end_y > 7 || end_x < 0 || end_y < 0) { // czy nie wyjdzie za tą tablicę
		return false;
	}

	if (player) {
		if (tablica[start_x][start_y] != 6) { // czy tam jest ta figura
			return false;
		}


		if (tablica[end_x][end_y] > 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}
	else {
		if (tablica[start_x][start_y] != -6) { // czy tam jest ta figura
			return false;
		}

		if (tablica[end_x][end_y] < 0) { // czy nie jest w miejscu końcowym nie nasza figura
			return false;
		}
	}

	if (abs(end_x - start_x) < 2 && abs(end_y - start_y) < 2) {
		return true;
	}


	return false;
}

bool roszada(int start_x1, int start_y1, int end_x1, int end_y1, bool player, vector < vector <int> > tablica) {
	if (player) {
		if (start_x1 == 0 && start_y1 == 4) {
			if (end_x1 == 0 && end_y1 == 7) {
				for (int i = end_y1 - 1; i >= start_y1; i--)
				{
					if (tablica[start_x1][i] != 0 && i != start_y1) {
						return false;
					}

					for (int start_x = 0; start_x < 8; start_x++)
					{
						for (int start_y = 0; start_y < 8; start_y++)
						{
							if (tablica[start_x][start_y] < 0) {

								for (int end_x = 0; end_x < 8; end_x++)
								{
									for (int end_y = 0; end_y < 8; end_y++)
									{
										if (tablica[end_x][end_y] == i) {
											switch (tablica[start_x][start_y])
											{
											case -1: {
												if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}
											}
											case -4:
												if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -2:
												if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -3:
												if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -5:
												if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -6:
												if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											default:
												break;
											}
										}
									}
								}
							}
						}
					}

				}

			}
			if (end_x1 == 0 && end_y1 == 0) {
				for (int i = end_y1 + 1; i <= start_y1; i++)
				{
					if (tablica[start_x1][i] != 0 && i != start_y1) {
						return false;
					}

					for (int start_x = 0; start_x < 8; start_x++)
					{
						for (int start_y = 0; start_y < 8; start_y++)
						{
							if (tablica[start_x][start_y] < 0) {

								for (int end_x = 0; end_x < 8; end_x++)
								{
									for (int end_y = 0; end_y < 8; end_y++)
									{
										if (tablica[end_x][end_y] == i) {
											switch (tablica[start_x][start_y])
											{
											case -1: {
												if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}
											}
											case -4:
												if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -2:
												if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -3:
												if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -5:
												if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -6:
												if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											default:
												break;
											}
										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
	else {
		if (start_x1 == 7 && start_y1 == 4) {
			if (end_x1 == 7 && end_y1 == 7) {
				for (int i = end_y1 - 1; i >= start_y1; i--)
				{
					if (tablica[start_x1][i] != 0 && i != start_y1) {
						return false;
					}

					for (int start_x = 0; start_x < 8; start_x++)
					{
						for (int start_y = 0; start_y < 8; start_y++)
						{
							if (tablica[start_x][start_y] < 0) {

								for (int end_x = 0; end_x < 8; end_x++)
								{
									for (int end_y = 0; end_y < 8; end_y++)
									{
										if (tablica[end_x][end_y] == i) {
											switch (tablica[start_x][start_y])
											{
											case -1: {
												if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}
											}
											case -4:
												if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -2:
												if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -3:
												if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -5:
												if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -6:
												if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											default:
												break;
											}
										}
									}
								}
							}
						}
					}

				}

			}
			if (end_x1 == 0 && end_y1 == 0) {
				for (int i = end_y1 + 1; i <= start_y1; i++)
				{
					if (tablica[start_x1][i] != 0 && i != start_y1) {
						return false;
					}

					for (int start_x = 0; start_x < 8; start_x++)
					{
						for (int start_y = 0; start_y < 8; start_y++)
						{
							if (tablica[start_x][start_y] < 0) {

								for (int end_x = 0; end_x < 8; end_x++)
								{
									for (int end_y = 0; end_y < 8; end_y++)
									{
										if (tablica[end_x][end_y] == i) {
											switch (tablica[start_x][start_y])
											{
											case -1: {
												if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}
											}
											case -4:
												if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -2:
												if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -3:
												if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -5:
												if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											case -6:
												if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
													return false;
													break;
												}

											default:
												break;
											}
										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
}


bool szach(bool player, vector < vector <int> > tablica) {
	if (player) {
		for (int start_x = 0; start_x < 8; start_x++)
		{
			for (int start_y = 0; start_y < 8; start_y++)
			{
				if (tablica[start_x][start_y] > 0) {

					for (int end_x = 0; end_x < 8; end_x++)
					{
						for (int end_y = 0; end_y < 8; end_y++)
						{

							if (tablica[end_x][end_y] == -6) {
								//cout << figura << endl;
								switch (tablica[start_x][start_y])
								{
								case 1: {
									if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}
								}
								case 4:
									if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case 2:
									if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case 3:
									if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case 5:
									if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case 6:
									if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								default:
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		for (int start_x = 0; start_x < 8; start_x++)
		{
			for (int start_y = 0; start_y < 8; start_y++)
			{
				if (tablica[start_x][start_y] < 0) {

					for (int end_x = 0; end_x < 8; end_x++)
					{
						for (int end_y = 0; end_y < 8; end_y++)
						{
							if (tablica[end_x][end_y] == 6) {
								switch (tablica[start_x][start_y])
								{
								case -1: {
									if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}
								}
								case -4:
									if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case -2:
									if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case -3:
									if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case -5:
									if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								case -6:
									if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
										return true;
										break;
									}

								default:
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	return false;

}

bool turn_check(int start_x, int end_x, int start_y, int end_y, bool player, vector < vector <int> > tablica) {
	//std::cout << start_x << start_y << end_x << end_y << tab_arrangement.tablica[start_x][start_y]  << endl;
	switch (tablica[start_x][start_y])
	{
	case -1: {
		if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}
	}
	case -4:
		if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case -2:
		if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case -3:
		if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case -5:
		if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case -6:
		if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}
	case 1: {
		if (P_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}
	}
	case 4:
		if (W_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case 2:
		if (S_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case 3:
		if (G_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case 5:
		if (H_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	case 6:
		if (K_move(start_x, start_y, end_x, end_y, player, tablica)) {
			return true;
			break;
		}

	default:
		break;
	}

	return false;
}

int points_check(int start_x, int end_x, int start_y, int end_y, vector < vector <int> > tablica) {
	if (tablica[start_x][start_y] > 0) {
		switch (tablica[end_x][end_y])
		{
		case 0: {
			return 0;
			break;
		}
		case -1: {
			return -7;
			break;
		}
		case -2: {
			return -21;
			break;
		}
		case -3: {
			return -21;
			break;
		}
		case -4: {
			return -35;
			break;
		}
		case -5: {
			return -56;
			break;
		}
		case -6: {
			return -120;
			break;
		}
		default:
			break;
		}
	}
	else if (tablica[start_x][start_y] < 0) {
		switch (tablica[end_x][end_y])
		{
		case 0: {
			return 0;
			//if (tablica[start_x][start_y] != 6) {
			//	return tablica[start_x][start_y];
			//}
			break;
		}
		case 1: {
			return 7;
			break;
		}
		case 2: {
			return 21;
			break;
		}
		case 3: {
			return 21;
			break;
		}
		case 4: {
			return 35;
			break;
		}
		case 5: {
			return 56;
			break;
		}
		case 6: {
			return 120;
			break;
		}
		default:
			break;
		}
	}

	return 0;
}



vector < vector <int> > computer_turn(vector < vector <int> > tablica1, vector < vector <bool> > tablica2) {

	int sx, sy, ex, ey;
	int end_points = 0;
	bool szach_komp = 0;
	bool first = true;
	vector < vector <int> > tablica = tablica1;
	if (szach(1, tablica1)) {
		for (int start_x1 = 0; start_x1 < 8; start_x1++)
		{
			for (int start_y1 = 0; start_y1 < 8; start_y1++)
			{
				if (tablica[start_x1][start_y1] < 0) {

					for (int end_x1 = 0; end_x1 < 8; end_x1++)
					{
						for (int end_y1 = 0; end_y1 < 8; end_y1++)
						{
							if (turn_check(start_x1, end_x1, start_y1, end_y1, 0, tablica) && tablica[end_x1][end_y1] >= 0) {
								tablica[end_x1][end_y1] = tablica[start_x1][start_y1];
								tablica[start_x1][start_y1] = 0;
								if (!szach(1, tablica)) {
									return tablica;
								}
								tablica = tablica1;
							}
						}
					}
				}
			}
		}
		cout << "Wygral gracz" << endl;
		exit(0);

	}
	for (int start_x1 = 0; start_x1 < 8; start_x1++)
	{
		for (int start_y1 = 0; start_y1 < 8; start_y1++)
		{
			if (tablica[start_x1][start_y1] < 0) {

				for (int end_x1 = 0; end_x1 < 8; end_x1++)
				{
					for (int end_y1 = 0; end_y1 < 8; end_y1++)
					{
						int points;
						int points1 = 0;
						tablica = tablica1;
						if (turn_check(start_x1, end_x1, start_y1, end_y1, 0, tablica) && tablica[end_x1][end_y1] >= 0) {
							points = points_check(start_x1, end_x1, start_y1, end_y1, tablica);
							tablica[end_x1][end_y1] = tablica[start_x1][start_y1];
							tablica[start_x1][start_y1] = 0;
							if (szach(0, tablica)) {
								szach_komp = true;
							}

							for (int start_x = 0; start_x < 8; start_x++)
							{
								for (int start_y = 0; start_y < 8; start_y++)
								{
									if (tablica[start_x][start_y] > 0) {

										for (int end_x = 0; end_x < 8; end_x++)
										{
											for (int end_y = 0; end_y < 8; end_y++)
											{

												if (turn_check(start_x, end_x, start_y, end_y, 1, tablica) && tablica[end_x][end_y] <= 0) {
													if (szach_komp) {
														int copy = tablica[end_x][end_y];
														tablica[end_x][end_y] = tablica[start_x][start_y];
														tablica[start_x][start_y] = 0;
														szach_komp = szach(0, tablica);
														tablica[start_x][start_y] = tablica[end_x][end_y];
														tablica[end_x][end_y] = copy;
													}
													if (points1 > points_check(start_x, end_x, start_y, end_y, tablica)) {
														points1 = points_check(start_x, end_x, start_y, end_y, tablica);
														int copy = tablica[end_x][end_y];
														tablica[end_x][end_y] = tablica[start_x][start_y];
														tablica[start_x][start_y] = 0;




														tablica[start_x][start_y] = tablica[end_x][end_y];
														tablica[end_x][end_y] = copy;
													}

													/*																				for (int start_x = 0; start_x < 8; start_x++)
																																	{
																																		for (int start_y = 0; start_y < 8; start_y++)
																																		{
																																			if (tablica[start_x][start_y] < 0) {

																																				for (int end_x = 0; end_x < 8; end_x++)
																																				{
																																					for (int end_y = 0; end_y < 8; end_y++)
																																					{
																																						if (turn_check(start_x, end_x, start_y, end_y, 0, tablica) && tablica[end_x][end_y] >= 0) {
																																							 points += points_check(start_x, end_x, start_y, end_y, tablica);
																																							 if (first) {
																																								 sx = start_x1;
																																								 sy = start_y1;
																																								 ex = end_x1;
																																								 ey = end_y1;
																																								 end_points = points;
																																								 points = 0;
																																								 first = false;

																																							 } else
																																							 if (points > end_points) {
																																								 end_points = points;
																																								 points = 0;
																																								 sx = start_x1;
																																								 sy = start_y1;
																																								 ex = end_x1;
																																								 ey = end_y1;
																																							 }
																																							 else {
																																								 points = 0;
																																							 }

																																						}
																																					}
																																				}
																																			}
																																		}
																																	} */

												}
											}
										}
									}
								}
							}

							if (szach_komp) {
								sx = start_x1;
								sy = start_y1;
								ex = end_x1;
								ey = end_y1;
								tablica1[ex][ey] = tablica1[sx][sy];
								tablica1[sx][sy] = 0;
								return tablica1;
							}

							points += points1;
							if (first) {
								sx = start_x1;
								sy = start_y1;
								ex = end_x1;
								ey = end_y1;
								end_points = points;
								points = 0;
								first = false;

							}
							else if (points == end_points && szach(0, tablica)) {
								end_points = points;
								points = 0;
								sx = start_x1;
								sy = start_y1;
								ex = end_x1;
								ey = end_y1;
							}
							else if (points > end_points) {

								end_points = points;
								points = 0;
								sx = start_x1;
								sy = start_y1;
								ex = end_x1;
								ey = end_y1;
							}
							else  if (points == end_points) {
								if (!tablica2[start_x1][start_y1]) {
									end_points = points;
									points = 0;
									sx = start_x1;
									sy = start_y1;
									ex = end_x1;
									ey = end_y1;
								}

							}
							else {
								points = 0;
							}

						}
					}
				}
			}
		}
	}



	if (end_points == 0) {
		if (tablica1[6][4] == -1) {
			if (turn_check(6, 4, 4, 4, 0, tablica1)) {
				tablica1[4][4] = -1;
				tablica1[6][4] = 0;
				return tablica1;
			}
		}
		if (tablica1[6][3] == -2) {
			if (turn_check(7, 5, 1, 2, 0, tablica1)) {
				tablica1[5][2] = -2;
				tablica1[7][1] = 0;
				return tablica1;
			}
		}
		if (tablica1[6][3] == -1) {
			if (turn_check(6, 5, 3, 3, 0, tablica1)) {
				tablica1[5][3] = -1;
				tablica1[6][3] = 0;
				return tablica1;
			}
		}
		if (tablica[7][6] == -2) {
			if (turn_check(7, 5, 6, 5, 0, tablica1)) {
				tablica1[5][5] = -2;
				tablica1[7][6] = 0;
				return tablica1;
			}
		}
	}
	tablica1[ex][ey] = tablica1[sx][sy];
	tablica1[sx][sy] = 0;
	return tablica1;

}

bool mat(vector < vector <int> > tablica1) {

	vector < vector <int> > tablica = tablica1;

	for (int start_x1 = 0; start_x1 < 8; start_x1++)
	{
		for (int start_y1 = 0; start_y1 < 8; start_y1++)
		{
			if (tablica[start_x1][start_y1] > 0) {

				for (int end_x1 = 0; end_x1 < 8; end_x1++)
				{
					for (int end_y1 = 0; end_y1 < 8; end_y1++)
					{
						if (turn_check(start_x1, end_x1, start_y1, end_y1, 1, tablica) && tablica[end_x1][end_y1] <= 0) {
							tablica[end_x1][end_y1] = tablica[start_x1][start_y1];
							tablica[start_x1][start_y1] = 0;
							if (!szach(0, tablica)) {
								return false;
							}
							tablica = tablica1;
						}
					}
				}
			}
		}
	}

	return true;
}


void turn(vector < vector <int> > tablica, vector < vector <bool> > tablica1) {

	bool spr = 1;

	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			if (tablica[a][b] < 0 && tablica1[a][b] != 1) {
				spr = 0;
			}
		}
	}

	if (spr) {
		tablica1 =
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
	}



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


	for (int a = 0; a < 8; a++)
	{
		if (a == 0) {
			std::cout << "A  B  C  D  E  F  G  H" << endl << endl;
		}

		for (int b = 0; b < 8; b++)
		{
			if (tablica[a][b] >= 0) {
				std::cout << figura_name(tablica[a][b]) << "  ";
			}
			else {
				std::cout << figura_name(tablica[a][b]) << " ";
			}
			if (b == 7) {
				std::cout << "              " << a + 1;
			}
		}
		std::cout << endl;
	}

	if (mat(tablica)) {
		cout << "Wygral komputer" << endl;
		exit(0);
	}

	if (szach(0, tablica)) {
		cout << "Szach od komputera" << endl;
	}
	string move;
	char figura;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	string start;
	string end;
	std::cout << "it's your turn" << endl;
	cin >> move;
	while (!(move.size() == 5 || move.size() == 6)) {
		cout << "nieprawidlowy ruch" << endl;
		cin >> move;
	}
//	if (move.size() == 5) {
//		while (!((move[0] == 'a' || move[0] == 'b' || move[0] == 'c' || move[0] == 'd' || move[0] == 'e' || move[0] == 'f' || move[0] == 'g' || move[0] == 'h') && (move[3] == 'a' || move[3] == 'b' || move[3] == 'c' || move[3] == 'd' || move[3] == 'e' || move[3] == 'f' || move[3] == 'g' || move[3] == 'h') && (move[1] == '1' || move[1] == '2' || move[1] == '3' || move[1] == '4' || move[1] == '5' || move[1] == '6' || move[1] == '7' || move[1] == '8') && (move[4] == '1' || move[4] == '2' || move[4] == '3' || move[4] == '4' || move[4] == '5' || move[4] == '6' || move[4] == '7' || move[4] == '8'))) {
//			cout << "nieprawidlowy ruch" << endl;
//			cin >> move;
//		}
//	}
//	if (move.size() == 6) {
//		while (!((move[0] == 'S' || move[0] == 'G' || move[0] == 'W' || move[0] == 'H' || move[0] == 'K') && (move[1] == 'a' || move[1] == 'b' || move[1] == 'c' || move[1] == 'd' || move[1] == 'e' || move[1] == 'f' || move[1] == 'g' || move[1] == 'h') && (move[4] == 'a' || move[4] == 'b' || move[4] == 'c' || move[4] == 'd' || move[4] == 'e' || move[4] == 'f' || move[4] == 'g' || move[4] == 'h') && (move[2] == '1' || move[2] == '2' || move[2] == '3' || move[2] == '4' || move[2] == '5' || move[2] == '6' || move[2] == '7' || move[2] == '8') && (move[5] == '1' || move[5] == '2' || move[5] == '3' || move[5] == '4' || move[5] == '5' || move[5] == '6' || move[5] == '7' || move[5] == '8'))) {
//			cout << "nieprawidlowy ruch" << endl;
//			cin >> move;
//		}
//		}


	for (int a = 0; a < move.size(); a++)
	{
		if (move[a] == '-') {
			for (int b = a + 1; b < move.size(); b++)
			{
				end += move[b];
			}
			break;
		}
		else {
			start += move[a];
		}

	}
	if (move == "RK1") {
		figura = 'R';
		start_y = 4;
		start_x = 0;
		end_y = 7;
		end_x = 0;
	}
	else if (move == "RK2") {
		figura = 'R';
		start_y = 4;
		start_x = 0;
		end_y = 0;
		end_x = 0;
	}
	else if (start.size() == 2) {
		figura = 'P';
		start_y = y_toint(start[0]);
		start_x = (start[1] - 1) - '0';
		end_y = y_toint(end[0]);
		end_x = (end[1] - 1) - '0';
	}
	else {
		figura = start[0];
		start_y = y_toint(start[1]);
		start_x = (start[2] - 1) - '0';
		end_y = y_toint(end[0]);
		end_x = (end[1] - 1) - '0';
	}

	switch (figura)
	{
	case 'W':
		if (W_move(start_x, start_y, end_x, end_y, true, tablica)) {
			tablica[end_x][end_y] = W;
			tablica[start_x][start_y] = 0;
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'S':
		if (S_move(start_x, start_y, end_x, end_y, true, tablica)) {
			tablica[end_x][end_y] = S;
			tablica[start_x][start_y] = 0;
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'G':
		if (G_move(start_x, start_y, end_x, end_y, true, tablica)) {
			tablica[end_x][end_y] = G;
			tablica[start_x][start_y] = 0;
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'H':
		if (H_move(start_x, start_y, end_x, end_y, true, tablica)) {
			tablica[end_x][end_y] = H;
			tablica[start_x][start_y] = 0;
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'K':
		if (K_move(start_x, start_y, end_x, end_y, true, tablica)) {
			tablica[end_x][end_y] = K;
			tablica[start_x][start_y] = 0;
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'R':
		if (roszada(start_x, start_y, end_x, end_y, true, tablica)) {
			if (end_y - start_y > 0) {
				tablica[end_x][end_y] = 0;
				tablica[start_x][start_y] = 0;
				tablica[start_x][start_y + 2] = K;
				tablica[end_x][end_y - 2] = W;
			}

			if (end_y - start_y < 0) {
				tablica[end_x][end_y] = 0;
				tablica[start_x][start_y] = 0;
				tablica[start_x][start_y - 2] = K;
				tablica[end_x][end_y + 3] = W;
			}

			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}

	case 'P': {
		if (P_move(start_x, start_y, end_x, end_y, true, tablica)) {
			if (end_x == 7) {
				char figura2;
				cout << "Prosze wybrac figure" << endl;
				cin >> figura2;
				cout << figura2 << endl;
				if (!(figura2 == 'S' || figura2 == 'H' || figura2 == 'W' || figura2 == 'G'))
				{
					cout << "nieprawidlowo zaznaczyles figure" << figura2 << endl;
				}
				while (!(figura2 == 'S' || figura2 == 'H' || figura2 == 'W' || figura2 == 'G'))
				{
					cin >> figura2;

				}
				cout << figura2 << endl;
				switch (figura2)
				{
				case 'S':
					tablica[end_x][end_y] = S;
					tablica[start_x][start_y] = 0;
					break;

				case 'G':
					tablica[end_x][end_y] = G;
					tablica[start_x][start_y] = 0;
					break;

				case 'H':
					tablica[end_x][end_y] = H;
					tablica[start_x][start_y] = 0;
					break;

				case 'W':
					tablica[end_x][end_y] = W;
					tablica[start_x][start_y] = 0;
					break;

				default:
					break;
				}
			}
			else {
				tablica[end_x][end_y] = P;
				tablica[start_x][start_y] = 0;
			}
			break;
		}
		else {
			std::cout << "niema tam figury oraz ten ruch nie jest mozliwy" << endl;
			turn(tablica, tablica1);
			break;
		}
	}
	default:
		break;
	}


	if (szach(true, tablica)) {
		std::cout << "Szach od gracza" << endl;
	}

	vector < vector <int> > tablica2 = tablica;

	tablica = computer_turn(tablica, tablica1);

	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			if (tablica[a][b] != tablica2[a][b] && tablica[a][b] < 0) {
				tablica1[a][b] = 1;
			}
		}
	}

	turn(tablica, tablica1);
}



