#ifndef CATALOGUE_H_INCLUDED
#define CATALOGUE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct elemenGame* adrGame;
typedef struct elemenCharacter* adrCharacter;

struct Game {
    string judul;
    string genre;
	int tahunRilis;
	float rating;
};

struct Character {
    string nama;
    string asalDunia;
	string peran;
	string ras;
	int strenght;
	int agility;
	int hp;
	int battleIq;
	int experience;
};

struct elemenGame {
    Game info;
    adrGame next;
    adrGame prev;
    adrCharacter firstChar;
};

struct elemenCharacter {
    Character info;
    adrCharacter next;
};

struct ListGame {
    adrGame first;
    adrGame last;
};

struct ListFight {
    adrCharacter first;
};


//basic requirement
void createListGame(ListGame &G);
bool isEmptyGame(ListGame G);
bool isEmptyCharacter(adrGame C);
adrGame createElementGame(Game newGame);                            //poin a
adrCharacter createElementCharacter(Character newChar);             //poin b
void addGame(ListGame &G, adrGame game);
void addCharacter(adrGame &C, adrCharacter chara);                  //poin d
adrGame searchGame(ListGame G, string gameName);                    //poin c
adrCharacter searchCharacter(adrGame C, string charaName);
void deleteGame(ListGame &G, string gameName);                      //poin f
void deleteCharacter(adrGame &C, string charaName);                 //poin g
void showCharacterInGame(ListGame G, string gameName);                                         //poin e
int countCharacterInGame(adrGame game);                                         //poin i
adrGame GameWithMostCharacter(ListGame G);                                   //poin j
void WholeCatalogue(ListGame G);                                          //poin h

//added feature
void chooseFighter(ListGame G, ListFight &arena, adrCharacter fighter);
void simulateFight(ListFight arena);


#endif // CATALOGUE_H_INCLUDED
