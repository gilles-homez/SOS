#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "hero.h"
#include "enemis.h"
#include "tirs.h"



void drawWall(int maxX, int maxY);
void drawPlayer(player p);
void drawEnemy(enemy e);
void drawPTirs(tirsP p);
void drawAllEnnemis(listeEn e);
void drawAllTirs(listetirsP t);
	
extern char **map;

#endif
