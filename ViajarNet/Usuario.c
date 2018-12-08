#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

struct usuario {
	int id;
	char nome[31];
};


Usu *novo_usu(int id, char *nome) {
  Usu *Noh;                                       //falta fazer a verificação
  Noh = malloc(sizeof(Noh));
  Noh->id = id;
  strcpy(Noh->nome, nome);
  if (Noh == NULL){
    return NULL;
  }
  return Noh;
}

int libera_usu(Usu **usu) {
  free(*usu);
  if (usu == NULL){
    return 1;
  }
  return 0;
}

int acessa_usu(Usu *usu, int *id, char *nome) {
  *id = usu->id;
  strcpy(nome, usu->nome);
  if (id == usu->id && nome == uau->nome){
    return 1;
  }
  return 0;
}

int atribui_usu(Usu *usu, int id, char *nome) {
  usu->id = id;
  strcpy(usu->nome, nome);
  if (usu->id == id && usu->nome == nome){
    return 1;
  }
  return 0;
}

int tamanho_usu() {
  return sizeof(Usu);
}