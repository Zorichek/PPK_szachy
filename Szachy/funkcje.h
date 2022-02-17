/** @file */


#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


/** Funkcja pobiera literę ze współrzędnej y i zwraca ją jako liczbę
 * @param y_toint współrzędna y
 * @return współrzędną y
 */

int y_toint(char y_cord);

/** Funkcja pobiera liczbę i zapisuje ją jako opisującą ją literę
 * @param figura_name liczba opisująca figurę
 * @return literę opisującą figurę
 */

string figura_name(int figura_number);


/** Funkcja sprawdzania możliwości ruchu hetmana
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch hetmana
 */

bool H_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);


/** Funkcja sprawdzania możliwości ruchu gońca
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch gońca
 */

bool G_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);

/** Funkcja sprawdzania możliwości ruchu skoczka
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch skoczka
 */

bool S_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);

/** Funkcja sprawdzania możliwości ruchu wieży
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch wieży
 */


bool W_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);

/** Funkcja sprawdzania możliwości ruchu piona
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch piona
 */



bool P_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);


/** Funkcja sprawdzania możliwości ruchu króla
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy ruch króla
 */

bool K_move(int start_x, int start_y, int end_x, int end_y, bool player, vector < vector <int> > tablica);



/** Funkcja sprawdzania możliwości rozszady
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwa roszada
 */


bool roszada(int start_x1, int start_y1, int end_x1, int end_y1, bool player, vector < vector <int> > tablica);



/** Funkcja sprawdzania szachu na tablicy
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest szach na tablicy
 */


bool szach(bool player, vector < vector <int> > tablica);


/** Funkcja sprawdzania możliwości ruchu dla podanej figury przez komputera
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return czy jest możliwy taki ruch
 */



bool turn_check(int start_x, int end_x, int start_y, int end_y, bool player, vector < vector <int> > tablica);


/** Funkcja sprawdzająca ile punktów komputer zdobędzie za dany ruch
 * @param start_x startowa współrzędna x
 * @param start_y startowa współrzędna y
 * @param end_x końcowa współrzędna x
 * @param end_y końcowa współrzędna y
 * @param player zmienna gracza
 * @param tablica aktualny stan tablicy
 * @return ilość punktów za jeden ruch
 */



int points_check(int start_x, int end_x, int start_y, int end_y, vector < vector <int> > tablica);


/** Funkcja, która wyszukuje najlepsze ruchy komputera, biorąc pod uwagę stan tablicy
 * @param tablica1 aktualny stan tablicy
 * @param tablica2 miejsca na tablicy, w których wskazano figury, które przesunęły się już w ciągu jednego cyklu
 * @return stan tablicy po ruchu komputera
 */




vector < vector <int> > computer_turn(vector < vector <int> > tablica1, vector < vector <bool> > tablica2);



/** Funkcja sprawdzania matu na tablicy
 * @param tablica1 aktualny stan tablicy
 * @return czy jest mat na tablicy
 */



bool mat(vector < vector <int> > tablica1);


/** Główna zapętlona funkcja programu, w której wykonywane są wszystkie sprawdzenia ruchu gracza
 * @param tablica aktualny stan tablicy
 * @param tablica1 miejsca na tablicy, w których wskazano figury, które przesunęły się już w ciągu jednego cyklu
 */





void turn(vector < vector <int> > tablica, vector < vector <bool> > tablica1);


#endif