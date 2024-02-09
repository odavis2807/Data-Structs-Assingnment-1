#include <stdio.h>
#include "player.h"

//creates player struct with random values
int CreatePlayer(PLAYER *p) {
	char* characters = "0123456789abcdefghijklmnopqrstubwxyz";
	char* factions[] = { "red", "green", "blue" };
	p->level = (rand() % (60 - 2)) + 1;
	p->faction = factions[rand() % 3];
	for (int i = 0; i < 10; i++) {
		p->username[i] = characters[rand() % 36];
	}
	p->username[10] = '\0';
	return (p == NULL);
}