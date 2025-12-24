#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "Catalogue.h"
using namespace std;

void mainMenu(ListGame &G);

//INPUT
void inputMenu(ListGame &G);
void inputGameMenu(ListGame &G);
void inputCharaMenu(ListGame &G);

//SEARCH
void searchMenu(ListGame G);
void searchGameMenu(ListGame G);
void searchCharaMenu(ListGame G);

//DELETE
void deleteMenu(ListGame &G);
void deleteGameMenu(ListGame &G);
void deleteCharMenu(ListGame &G);
void iForgor(ListGame &G);

//VIEW
void viewMenu(ListGame G);
void viewAllCatalog(ListGame G);
void viewGameMostCharacter(ListGame G);
void viewGameAZ(ListGame G);
void viewGameHighestRating(ListGame G);
void viewGameOldest(ListGame G);
void viewCharacterRankPower(ListGame G);

//FIGHT
void fightMenu(ListGame G);

#endif // MENU_H_INCLUDED
