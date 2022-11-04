#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "utilidades.h"


void cleanAndSetScreen();
void titulo();
int leerOpcion();
void menuPrincipal();
void logIn(nodoCliente* listaCliente);
void registrarse();
void marco();
void lineaRecta(int x);
void lineaRectavertical(int x,int y);
void subMenuAdmin(nodoCliente* listaCliente);
void subMenuUsuario(nodoCliente* listaCliente);
void adminCliente(nodoCliente* listaCliente);
void usuarioCliente();
void adminPedido(nodoCliente* listaCliente);
void usuarioPedido(nodoPedido* listaPedido);
void adminProducto();
void usuarioProducto();



#endif // MENU_H_INCLUDED
