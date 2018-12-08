#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
  if (*id == usu->id && strcmp(nome, usu->nome)){
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

int testa_novo_usu() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);
  if(usu != NULL) {
    return 1;
  }
  
  return 0;
}

int testa_libera_usu() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  if(libera_usu(&usu) == 1) {
    return 0;
  }
  
  scanf("%d",&id);
  scanf("%s",nome);
  usu = novo_usu(id, nome);
  
  if(usu != NULL) {
    if(libera_usu(&usu) == 1 && usu == NULL) {
        return 1;
    }
  }
  
  return 0;
}

int testa_acessa_usu() {
  int id, id2;
  char nome[100], nome2[80];
  Usu *usu = NULL;
  
  scanf("%d",&id);
  scanf("%s",&nome);
  printf("testesffa");
  if(acessa_usu(usu, &id, nome) == 1) {
    return 0;
  }
  
  usu = novo_usu(id, nome);
  
  if(usu != NULL) {
    if(acessa_usu(usu, &id2, nome2) == 1) {
      if(id == id2 && strcmp(nome, nome2) == 0) {
        return 1;
      }
    }
  }
  return 0;
}

int testa_atribui_usu() {
  int id, id2;
  char nome[100], nome2[80];
  Usu *usu = NULL;
 
  scanf("%d",&id);
  scanf("%s",nome);
  
  if(atribui_usu(usu, id, nome) == 1) {
    return 0;
  }
  
  usu = novo_usu(id, nome);
  if(usu != NULL) {
    if(atribui_usu(usu, id, nome) == 1) {
      if(acessa_usu(usu, &id2, nome2) == 1) {
        if(id == id2 && strcmp(nome, nome2) == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main(void) {
  int op = 0;
  while(op != 2424){
    scanf("%d", &op);
    
    switch(op) {
      case 1: printf("%d", testa_novo_usu());   //OK
              break; 
      
      case 2: printf("%d", testa_atribui_usu());
              break;
      
      case 3: printf("%d", testa_acessa_usu());
              break;
              
      case 4: printf("%d", testa_libera_usu());
              break;
              
    }
  }
  return 0;
}