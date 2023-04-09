#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"

int maxY()		//fonction qui compte le nombre de colonnes
{
    FILE *f = NULL;
    f = fopen("MAP.map", "r");
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
    int mY=1;
	while ((c=fgetc(f))!='\n')
	
	{		
		mY+=1;
	}
    fclose(f);
    return mY;
			
}

int maxX()		//fonction qui compte le nombre de lignes
{
    FILE *f = NULL;
    f = fopen("MAP.map", "r");
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
    int mX=0;
	while ((c=fgetc(f))!=EOF)
	
	{		
		if(c=='\n') mX+=1;
	}
    fclose(f);
    return mX;
			
}


bool loadMap(int mX, int mY)		//fonction qui ouvre le fichier map et charge la carte dans le tableau
{
    map = malloc(sizeof(char *) * mX);	
    FILE *f = NULL;
    f = fopen("MAP.map", "r");
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
    int i = 0;
    int j = 0;
	
	*(map + i) = malloc(sizeof(char *) * mY);	
	for(i = 0; i < mX; i++)
		{
		*(map + i) = malloc(sizeof(char *) * mY);	
			for(j = 0; j < mY; j++)
			{		
				c = fgetc(f);
				*(*(map + i) + j) = c;
			}
			
		}

	    fclose(f);
		
	    printf("\n");

		for(i = 0; i < mX; i++)
		{
			for(j = 0; j < mY; j++)
			{
				printf("%c", map[i][j]);
			}
		}
				
		
 return true;
 }		

