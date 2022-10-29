#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "gotoxy.h"
#include "cliente.h"

#define ARCHIVO_CLIENTE "cliente.dat"

void cleanAndSetScreen();
void titulo();
int leerOpcion();
void menuPrincipal();
void logIn();
void registrarse();
void marco();
void lineaRecta(int x);
void lineaRectavertical(int x,int y);


#endif // MENUPRINCIPAL_H_INCLUDED
