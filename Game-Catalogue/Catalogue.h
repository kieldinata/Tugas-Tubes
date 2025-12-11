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

struct ListCharacter {
	adrCharacter first;
};
#endif // CATALOGUE_H_INCLUDED
