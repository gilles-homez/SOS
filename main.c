#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "hero.h"
#include "enemis.h"
#include "tirs.h"

bool test = false;
int mX;
int mY;

void updateCollisions(int valeur)
{
	enemy baseE = e->starList;
	tirsP baseP = t->starList;
	if (e->starList != NULL && t->starList != NULL)
	{
		checkCollision(baseE, baseP);
		if (t->starList->nextptr != NULL)
			{
				baseP = baseP->nextptr;	
				checkCollision(baseE, baseP);
				while (baseP->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision(baseE, baseP);
				}
			}
		if (e->starList->nextptr != NULL)
		{
			baseE = baseE->nextptr;
			baseP = t->starList;
			checkCollision(baseE, baseP);
			if (t->starList->nextptr != NULL)
			{
				baseP = baseP->nextptr;
				checkCollision (baseE, baseP);
				while (baseP->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision(baseE, baseP);
				}
			}
			while (baseE->nextptr != NULL)
			{
				baseE = baseE->nextptr;
				baseP = t->starList;
				checkCollision(baseE, baseP);
				if (t->starList->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision (baseE, baseP);
					while (baseP->nextptr != NULL)
					{
						baseP = baseP->nextptr;
						checkCollision(baseE, baseP);
					}
				}
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateCollisions, 0);
}

void updateEnemies(int valeur)
{
	q = e->starList;
	if (e->starList != NULL)
	{
		if (q->pos.x==15 || q->pos.x==19)
		
		{
		
			q->pos.y -= 1;
			if (q->pos.y < 1)
			{
				q->pos.y = 1;
				q->active = false;
			}
		}
		else
		{
			q->pos.y += 1;
			if (q->pos.y > 58)
			{
				q->pos.y = 58;
				q->active = false;
			}
		
		}	
		while (q->nextptr != NULL)
		{
			q = q->nextptr;
			if (q->pos.x==15 || q->pos.x==19)
		
			{
				q->pos.y -= 1;
				if (q->pos.y < 1)
				{
					q->pos.y = 1;
					q->active = false;
				}
			}
			else
			{
				q->pos.y += 1;
				if (q->pos.y > 58)
				{
					q->pos.y = 88;
					q->active = false;
				}
				
			}	
				
		}
	}
	glutPostRedisplay();
	glutTimerFunc(200, updateEnemies, 1);
}

void updateNewEnemies(int valeur)
{
	enemy new = createEnemy();
	insertionEnemies(e, new);
	glutPostRedisplay();
	glutTimerFunc(1000, updateNewEnemies, 3);
}


void updateTirs(int valeur)
{
	r = t->starList;
	if (t->starList != NULL)
	{
		r->pos.x -= 1;
		if (r->pos.x < 1)
		{
			r->pos.x = 88;
			r->active = false;
		}
		while (r->nextptr != NULL)
		{
			r = r->nextptr;
			r->pos.x -= 1;
			if (r->pos.x < 1)
			{
				r->pos.x = 88;
				r->active = false;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateTirs, 2);
}


void updateDeleateEnemies(int valeur)
{
	if (e->starList != NULL || e->endList != NULL)
	{
		suppressionEnemies(e, test);
	}
	glutPostRedisplay();
	glutTimerFunc(200, updateDeleateEnemies, 4);
}

void updateDeleteTirs(int valeur)
{
	if (t->starList != NULL || t->endList != NULL)
	{
		suppressionTirs(t, test);
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateDeleteTirs, 5);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width,int heigth)
{
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, heigth, 0);
}

void Display()
{
	mX=maxX();
	mY=maxY();
	glClearColor(0.5f,0.5f,0.5f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        game(mX, mY, p, e, t);
	glFlush();
}

int main(int argc, char *argv[])
{
	
	
	mX=maxX();
	mY=maxY();
	srand(time(NULL));
	loadMap(mX, mY);
	p = createPlayer(mX, mY);
	e = initialListEnemies();
        t = initialListeTirs();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((mY-1)*Square_size, mX*Square_size);

	glutCreateWindow("SOS Tirs");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	glutTimerFunc(50, updateCollisions, 0);
	glutTimerFunc(10, updateEnemies, 1);
	glutTimerFunc(50, updateTirs, 2);
	glutTimerFunc(30, updateNewEnemies, 3);
	glutTimerFunc(20, updateDeleateEnemies, 4);
	glutTimerFunc(50, updateDeleteTirs, 5);
	
	

	glEnable(GL_DEPTH_TEST);
	

	glutMainLoop();

	return 0;
}
