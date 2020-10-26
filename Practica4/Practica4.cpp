// practica4.cpp
//
#include <stdio.h>
#include <stdarg.h>
#include "consola.h"
#include <Windows.h>


struct TEntity;
typedef void (*funcEntity)(TEntity*);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************

struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void drawA(TEntity* entity)
{
	gotoxy(entity->m_ix, entity->m_iy);
	printf("A");
}
void drawB(TEntity* entity)
{
	gotoxy(entity->m_ix, entity->m_iy);
	printf("B");
}

void drawC(TEntity* entity)
{
	gotoxy(entity->m_ix, entity->m_iy);
	printf("C");
}

void drawD(TEntity* entity)
{
	gotoxy(entity->m_ix, entity->m_iy);
	printf("D");
}
void moveRight(TEntity* entity)
{
	++entity->m_ix;
}

void moveLeft(TEntity* entity)
{
	--entity->m_ix;
}

void moveDown(TEntity* entity)
{
	--entity->m_iy;
}

void moveDiagonal(TEntity* entity)
{
	++entity->m_ix;
	++entity->m_iy;
}
// ***************************************************************************************
// MAIN
// ***************************************************************************************

unsigned int uKey;

int main(int argc, char* argv[])
{
	TEntity* tEntities[4];
	
	funcEntity tFuncs1[2] = { &drawA, &moveRight };
	tEntities[0] = new TEntity(tFuncs1, 0, 0);

	funcEntity tFuncs2[2] = { &drawB, &moveLeft };
	tEntities[0] = new TEntity(tFuncs2, 2, 2);

	funcEntity tFuncs3[2] = { &drawC, &moveDiagonal };
	tEntities[0] = new TEntity(tFuncs3, 0, 0);

	funcEntity tFuncs4[2] = { &drawD, &moveDown };
	tEntities[0] = new TEntity(tFuncs4, 0, 0);

	
	while (true)
	{
		clear();
		for (unsigned int i = 0; i < sizeof(tEntities)/sizeof(*tEntities); i++)
		{
			//coger la entidad
			TEntity *entity = tEntities[i];
			funcEntity draw = entity->m_funcs[0];
			funcEntity move = entity->m_funcs[1];

			draw(entity);
			hidecursor();
			move(entity);
			hidecursor();
		}
		Sleep(100);
	}
}

void checkMoveLimits(TEntity* entity)
{
	const int MAX_X = 15;
	const int MAX_Y = 8;
	const int MIN_X = 0;
	const int MIN_Y = 0;
}

