#ifndef CATALOGUE_H_INCLUDED
#define CATALOGUE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

typedef struct elemenGame* adrGame;
typedef struct elemenCharacter* adrCharacter;

struct Game {
    string nama;
    string genre;
	int tahunRilis;
	float rating;
};
struct Character {
    string nama;
    string asalDunia;
	string peran;
	string ras;
	int strength;
	int agility;
	int hp;
	int battleIQ ;
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

//[GAME]
void createListGame(ListGame &G);
bool isEmptyGame(ListGame G);
adrGame createElementGame(Game gameInfo);                            //poin a
void addGame(ListGame &G, adrGame game);
adrGame searchGame(ListGame G, string gameName);                    //poin c
adrGame searchGameWithCharacter(ListGame G, string charaName);
void deleteGame(ListGame &G, string gameName);                      //poin f
adrGame GameWithMostCharacter(ListGame G);                                   //poin j
int countCharacterInGame(adrCharacter chara);

//[CHARACTER]
bool isEmptyCharacter(adrGame C);
adrCharacter createElementCharacter(Character newChar);             //poin b
void addCharacter(adrGame &C, adrCharacter chara);                  //poin d
adrCharacter searchCharacter(ListGame G, string charaName);
void deleteCharacter(ListGame G, string charaName);                 //poin g
void deleteAllCharacter(adrGame &C, adrCharacter &chara);
                                        //poin i

//[FIGHT SIMULATOR]
void chooseCharacter(ListGame &G, vector<Character> &chosenChar, string charaName, bool &valid);
Character simulateFight(vector<Character> &chosenChar);
int calcDamage(Character attacker, Character defender);
Character duel(Character p1, Character p2);

//[POWER RANK]
void initCharVector(ListGame G, vector<Character> &charVector);
int calcPower(Character c);
void sortCharacterRank(vector<Character> &charVector);


#endif // CATALOGUE_H_INCLUDED
