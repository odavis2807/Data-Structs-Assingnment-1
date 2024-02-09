#pragma once

typedef struct Player {
	char username[11];
	int level;
	char* faction;
}PLAYER;

int CreatePlayer(PLAYER *p);