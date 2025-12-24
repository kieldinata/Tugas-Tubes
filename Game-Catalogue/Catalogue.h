#ifndef CATALOGUE_H_INCLUDED
#define CATALOGUE_H_INCLUDED

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct elemenGame* adrGame;
typedef struct elemenCharacter* adrCharacter;

struct Game {
    string nama;
    string genre;
	int tahunRilis;
	float rating;
	int jumlahKarakter;
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
bool isValidGameToAdd(ListGame G, Game gameInfo);
adrGame findGame(ListGame G, string gameName);                    //poin c
void deleteGame(ListGame &G, adrGame C);                      //poin f


//[CHARACTER]
bool isEmptyCharacter(adrGame C);
adrCharacter createElementCharacter(Character newChar);             //poin b
void addCharacter(adrGame &C, adrCharacter chara);                  //poin d
bool isValidCharacter(adrGame C, string charaName);
vector<adrCharacter> findCharacter(ListGame G, string charaName);
adrCharacter findCharacterFromGame(adrGame C, string charaName);
void deleteCharacterFromGame(adrGame &C, string charaName);                 //poin g
void deleteAllCharacter(adrGame &C, adrCharacter &chara);
                                        //poin i

//[FIGHT SIMULATOR]
const int MAX_FIGHTER = 10;
void chooseCharacterArray(ListGame G, Character chosenChar[], int &count, string gameName, string charaName, bool &valid);
Character simulateFight(Character chosenChar[], int count);
int calcDamage(Character attacker, Character defender);
Character duel(Character p1, Character p2);


//[CHARACTER RANK]
const int MAX_CHAR_SHOWN = 4000;
void initCharaArray(ListGame G, Character charArray[], int &counter);
int calcPower(Character c);
void sortCharacterRank(Character charArray[], int counter);


//GAME RANK
const int MAX_GAME_SHOWN = 200;
void initGameArray(ListGame G, Game gameArray[], int &counter);
void sortGameWithParameter(Game gameArray[], int counter, string parameter);
int countCharacterInGame(adrCharacter chara);
adrGame GameWithMostCharacter(ListGame G);                                   //poin j



//[- byebye data game & karakter]
void byebyedata(adrGame &C);


#endif // CATALOGUE_H_INCLUDED
