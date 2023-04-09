#ifndef _HERO_H_
#define _HERO_H_

struct positionP
{
	int x;
	int y;
};

struct play
{
	int vie;
	struct positionP pos;
};

typedef struct play *player;
extern player p;

player createPlayer(int maxX, int maxY);
void moveLeft(player p);
void moveRight(player p);
void moveUp(player p);
void moveDown(player p);

#endif
