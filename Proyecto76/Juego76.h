#pragma once

#ifndef JUEGO76_H_ 
#define JUEGO76_H_
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4789 )
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 
static char mapa[7][7];
static char mapa2[7][7];
static int move1;
static int win;
static int j;
static int onescore = 0;
static int twoscore = 0;
static char again = 'y';
static char c[200];

static char player1char = '1';
static char player2char = '2';

static int PlayOut = 0;
static int EVA = 0;
static int ult[2] = { 0,0 };
//funciones


void crearMapa();
void pintar2();
char pintar3(char xd[7][7]);
void meterFicha2(const char* player, char a, int col,int l);
void buscarLibre2(char a);
int llena(int a);
int winCheckMapa(int i);

bool movres();
int AIManager();
int NegaMax(int Depth);

//int findBestMove();
//int mixmax(int nivel, bool player);
//estos dos metodos no los usamos en la demo, pero se usaran mas tarde para cargar tableros personalizados que vayamos creando
void crearFich(char* nombre, char mapaG[][7]);
void leerFich(char* nombre);


#endif JUEGO76_H_