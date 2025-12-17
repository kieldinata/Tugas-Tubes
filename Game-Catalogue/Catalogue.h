#ifndef CATALOGUE_H_INCLUDED
#define CATALOGUE_H_INCLUDED

#include <string>
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
    adrCharacter prev;
};

struct ListGame {
    adrGame first;
    adrGame last;
};


//basic requirement
void createListGame(ListGame &G)
bool isEmptyGame(ListGame G);
bool isEmptyCharacter(adrCharacter c);
adrGame createElementGame(Game newGame);                            //poin a
adrCharacter createElementCharacter(Character newChar);             //poin b
void addGame(ListGame &G, adrGame game);
void addCharacter(adrGame &C, adrCharacter chara);                  //poin d
adrGame searchGame(ListGame G, string gameName);                    //poin c
adrCharacter searchCharacter(adrGame C, string charaName);
void deleteGame(ListGame &G, string gameName);                      //poin f
void deleteCharacter(adrGame &C, string charaName);                 //poin g
void showCharacterInGame(adrGame game);                                         //poin e
int countCharacterInGame(adrGame game);                                         //poin i
void showGameWithMostCharacter(ListGame G);                                   //poin j
void showWholeCatalogue(ListGame G);                                          //poin h

//added feature
void simulateFight(ListGame game);


#endif // CATALOGUE_H_INCLUDED
