#include "Catalogue.h"
void createListGame(ListGame &G){
    G.first = nullptr;
    G.last = nullptr;
}
bool isEmptyGame(ListGame G){
    return G.first == nullptr && G.last == nullptr;
}
bool isEmptyCharacter(adrGame C){
    return C->firstChar == nullptr;
}
adrGame createElementGame(Game newGame){
    adrGame p;
    p = new elemenGame;
    p->firstChar = nullptr;
    p->info = newGame;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
adrCharacter createElementCharacter(Character newChar){
    adrCharacter p;
    p = new elemenCharacter;
    p->info = newChar;
    p->next = nullptr;
    return p;
}
void addGame(ListGame &G, adrGame game){
    if (isEmptyGame(G)){
        G.first = game;
        G.last = game;
    }
    else if (game->info.judul < G.first->info.judul){
        game->next = G.first;
        G.first->prev = game;
        G.first = game;
    }
    else {
        adrGame curr = G.first;

        while (curr->next != nullptr &&
               curr->next->info.judul < game->info.judul){
            curr = curr->next;
        }

        if (curr->next == nullptr){
            curr->next = game;
            game->prev = curr;
            G.last = game;
        }
        else {
            game->next = curr->next;
            game->prev = curr;
            curr->next->prev = game;
            curr->next = game;
        }
    }
}
void addCharacter(adrGame &C, adrCharacter chara){
    if (isEmptyCharacter(C)){
        C->firstChar = chara;
    } else if (chara->info.nama < C->firstChar->info.nama){
        chara->next = C->firstChar;
        C->firstChar = chara;
    } else {
        adrCharacter curr = C->firstChar;
        while (curr->next != nullptr &&
               curr->next->info.nama < chara->info.nama){
            curr = curr->next;
        }
        chara->next = curr->next;
        curr->next = chara;
    }
}

adrGame searchGame(ListGame G, string gameName){
    adrGame p = G.first;
    while (p != nullptr){
        if (p->info.judul == gameName){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
adrCharacter searchCharacter(ListGame G, string charaName){
    adrGame p = G.first;
    while (p != nullptr){
        adrCharacter q = p->firstChar;
        while (q != nullptr){
            if (q->info.nama == charaName){
                return q;
            }
            q = q->next;
        }
        p = p->next;
    }
    return nullptr;
}
void deleteGame(ListGame &G, string gameName){
    adrGame p = searchGame(G, gameName);
    if (p == nullptr) return;

    if (p == G.first && p == G.last){
        G.first = nullptr;
        G.last = nullptr;
    }
    else if (p == G.first){
        G.first = p->next;
        G.first->prev = nullptr;
    }
    else if (p == G.last){
        G.last = p->prev;
        G.last->next = nullptr;
    }
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
}
void deleteCharacter(adrGame &C, string charaName){
    if (!isEmptyCharacter(C)){
        adrCharacter p = C->firstChar;
        adrCharacter prev = nullptr;

        while (p != nullptr && p->info.nama != charaName){
            prev = p;
            p = p->next;
        }

        if (p != nullptr){
            if (prev == nullptr){
                C->firstChar = p->next;
            } else {
                prev->next = p->next;
            }
            delete p;
        }
    }
}
void showCharacterInGame(ListGame G, string gameName){
    adrGame p;
    p = searchGame(G, gameName);
}
int countCharacterInGame(adrGame game){
    int count = 0;
    adrCharacter p = game->firstChar;
    while (p != nullptr){
        count++;
        p = p->next;
    }
    return count;
}
adrGame GameWithMostCharacter(ListGame G){
    adrGame p = G.first;
    adrGame maxGame = p;
    int maxCount = countCharacterInGame(p);

    while (p != nullptr){
        int currCount = countCharacterInGame(p);
        if (currCount > maxCount){
            maxCount = currCount;
            maxGame = p;
        }
        p = p->next;
    }
    return maxGame;
}
void WholeCatalogue(ListGame G){
    adrGame p = G.first;
    while (p != nullptr){
        cout << "Game: " << p->info.judul << endl;
        adrCharacter q = p->firstChar;

        if (q == nullptr){
            cout << "  Tidak ada karakter" << endl;
        }

        while (q != nullptr){
            cout << "  - " << q->info.nama << endl;
            q = q->next;
        }
        p = p->next;
    }
}

//added feature
void chooseFighter(ListGame G, ListFight &arena, adrCharacter fighter){
    bool valid;
    int i, n;
    string nama;
    adrCharacter p;
    cout << "Masukkan jumlah karakter: ";
    cin >> n;
    for ( i = 1; i <= n; i++){
            valid = false;
            while (!valid){
                cout << "Masukkan nama karakter ke-" << i << ": ";
                cin >> nama;
                p = searchCharacter(G, nama);
                if (p != nullptr){
                    valid = true;
                } else {
                    cout << "Tidak ada karakter dengan nama '" << nama << "'." << endl;
                }
            }
    }
}
void simulateFight(ListFight arena){
}
