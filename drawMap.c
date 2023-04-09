#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include "loadMap.h"
#include "drawMap.h"
#include "game.h"


char **map;

void drawWall(int mX, int mY)			// fonction qui affiche les éléments du plateau
{

	for (int j = 0; j < mX; ++j)
	{
		for (int i = 0; i < mY; ++i)
		{
			if(*(*(map + j) + i) == '#')
			{
				glColor3f(0.0f,1.0f,0.3f);	// Bande enherbée

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				//glTranslatef(j*Square_size,i*Square_size,0.0f);

				glBegin(GL_QUADS);
	
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
				
				
			}
			if (*(*(map + j) + i) == '-')
			{
				glColor3f(1.0f,0.8f,0.0f);	// marquage routier

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				//glTranslatef(j*Square_size, i*Square_size,0.0f);
				glBegin(GL_QUADS);

					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			
			
			if(*(*(map + j) + i) == '0')
			{	
				//glColor3f(0.0f,0.0f,1.0f);
				glColor3f(0,0,1);			// rivière

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				//glTranslatef(j*Square_size, i*Square_size,0.0f);
			
				glBegin(GL_QUADS);

					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
			
			if(*(*(map + j) + i) == 'v')
			{	
				//glColor3f(0.0f,0.0f,1.0f);
				glColor3f(1,0,0);			// rivière

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				//glTranslatef(j*Square_size, i*Square_size,0.0f);
			
				glBegin(GL_QUADS);

					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
			
			if(*(*(map + j) + i) == 'x')
			{	
				//glColor3f(0.0f,0.0f,1.0f);
				glColor3f(0,0,0);			// bordures

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				//glTranslatef(j*Square_size, i*Square_size,0.0f);
			
				glBegin(GL_QUADS);

					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
		
		}
	}

	

}

void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	
	
	glColor3f(1.0f,0.5f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);

	glBegin(GL_POLYGON);
	      glVertex2f(0, 0);
	      glVertex2f(40, 0);
	      glVertex2f(40, 20);
	      glVertex2f(20, 40);
	      glVertex2f(0, 20);
        glEnd();
	
}

void drawEnemy(enemy e)	
{
	int i, j;
	i = e->pos.x;
	j = e->pos.y;
	glColor3f(1.0f,0.0F,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);
	
	glBegin(GL_QUADS);
	
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(Square_size,0.0f,0.0f);
		glVertex3f(Square_size,Square_size,0.0f);
		glVertex3f(0.0f,Square_size,0.0f);
	glEnd();
	
}

void drawTirs(tirsP p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Shoot_size,i*Shoot_size,0.0f);
	
	glBegin(GL_POLYGON);
	
	      glVertex2f(-0.5*Shoot_size, 0.0*Shoot_size);
	      glVertex2f(-0.4*Shoot_size, 0.2*Shoot_size);
	      glVertex2f(-0.2*Shoot_size, 0.4*Shoot_size);
	      glVertex2f(0.2*Shoot_size, 0.4*Shoot_size);
	      glVertex2f(0.4*Shoot_size, 0.2*Shoot_size);
	      glVertex2f(0.5*Shoot_size, 0.0*Shoot_size);
	      glVertex2f(0.4*Shoot_size, -0.2*Shoot_size);
	      glVertex2f(0.2*Shoot_size, -0.4*Shoot_size);
	      glVertex2f(-0.2*Shoot_size, -0.4*Shoot_size);
	      glVertex2f(-0.4*Shoot_size, -0.2*Shoot_size);
	      
   	glEnd();
}

void drawAllEnnemis(listeEn e)
{	
	enemy first = malloc(sizeof(enemies));
	enemy next = malloc(sizeof(enemies));
	first = e->starList;
	next = e->starList->nextptr;
	if (e->starList != NULL || e->endList != NULL)
	{
		drawEnemy(first);
		if (e->starList->nextptr != NULL)
		{
			drawEnemy(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawEnemy(next);
			}
		}
	}
}


void drawAllTirs(listetirsP t)
{
	tirsP first = malloc(sizeof(tirs));
	tirsP next = malloc(sizeof(tirs));
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
	next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		drawTirs(first);
		if (t->starList->nextptr != NULL)
		{
			drawTirs(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawTirs(next);
			}
		}
	}
}
