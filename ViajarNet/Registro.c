#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registro.h"

struct registro {
  Info info;
  Reg *esq;
  Reg *dir;
};

int verificarInfo(Info *info){
  //verificar as strings
  if(info->mes < 1 || info->mes > 12 ||
     info->dia < 1 || info->dia > 31 ||
     info->ano <= 0) { return 0;}
  if(strlen(info->cod) != 1 || *info->cod <= '0' ||
     strlen(info->cidade) < 1 && strlen(info->cidade) > 60 ||
     strlen(info->pais) < 1 && strlen(info->pais) > 30) {
    return 0;
  }
  if(info->mes % 2 == 0 && info->mes < 8) {
    return info->dia <= 30 ? 1 : 0;
  } else if(info->mes % 2 != 0 && info->mes > 7) {
    return info->dia <= 30 ? 1 : 0;
  }
  return 1;
}


Reg *novo_reg(Info *info) {   //cria um novo registro e aponta os seus filhos para null
  if (verificarInfo(info)){
    Reg *Noh;
  Noh = malloc (sizeof(Reg));
  if(Noh == NULL){ return NULL;}
  Noh->info = *info;
  Noh->esq = NULL;
  Noh->dir = NULL;
  return Noh;
  }
  return NULL;
}

int libera_reg(Reg **reg) {
  if(*reg != NULL) {
    libera_reg(&(*reg)->esq); 
    libera_reg(&(*reg)->dir);
    free(*reg);
    *reg = NULL;
    return 1;
  }
  return 0;
}

int atribui_info_reg(Reg *reg, Info *info) {          //atribui uma nova info ao registro
    if(info != NULL){
      reg->info = *info;
      return 1;
    }
    return 0;
}

Info *acessa_info_reg(Reg *reg) {       //retorna a info do registro
  if (reg != NULL){
    return &(reg->info);
    }
  return NULL;
}

int add_dir_reg(Reg *atual, Reg *dir) {   //add um novo registro na direita do Noh selecionada
  if (atual == NULL){return 0;}
  if (dir == NULL){
    return 1;
  }
  else{
    dir->dir = atual->dir;   // se o Noh ja tiver filho na direita ele empurra p baixo e ocupa o local
    atual->dir = dir;
    return 1;
  }
}

int add_esq_reg(Reg *atual, Reg *esq) {   //add um novo registro na esquerda do Noh selecionada
  if (atual== NULL){
    return 0;
    }
  if (esq == NULL){
    return 1;
  }
  else{
    esq->esq = atual->esq;   // se o Noh ja tiver filho na esquerda ele empurra p baixo e ocupa o local
    atual->esq = esq;
    return 1;
  }
}

Reg *visita_dir_reg(Reg *atual) {
  if (atual == NULL){
    return NULL;
  }
  return atual->dir;        // como o Noh é criado com os filhos null, caso n tenha nenhum vai retornar null
}                           // ou retornar o filho desejado

Reg *visita_esq_reg(Reg *atual) {
  if (atual == NULL){
    return NULL;
  }
  return atual->esq;         // como o Noh é criado com os filhos null, caso n tenha nenhum vai retornar null
}                            // ou retornar o filho desejado

int tamanho_no() {
  return sizeof(Reg);
}