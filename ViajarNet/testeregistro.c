#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Registro.h"


struct registro {
  Info info;
	Reg *esq;
	Reg *dir;
};

Reg *novo_reg(Info *info) {   //cria um novo registro e aponta os seus filhos para null
  Reg *Noh;
  Noh = malloc (sizeof(Reg));
  if(Noh == NULL){ return NULL;}
  Noh->info = *info;
  Noh->esq = NULL;
  Noh->dir = NULL;
  return Noh;
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

int testa_novo_reg() {
  Info info;
  Reg *reg = NULL;
  printf("cod\n");
  scanf("%s", &info.cod);
  printf("dia\n");
	scanf("%d", &info.dia);
  printf("mes\n");
	scanf("%d", &info.mes);
  printf("ano\n");
	scanf("%d", &info.ano);
  printf("cidade\n");
	scanf("%s", info.cidade);
  printf("pais\n");
	scanf("%s", info.pais);
  printf("periodo\n");
	scanf("%d", &info.periodo);
  
	
	reg = novo_reg(&info);
	if(reg != NULL) {
	  return 1;
	}
  return 0;
}

int testa_libera_reg() {
  Info info;
  Reg *reg = NULL;
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	if(libera_reg(&reg) == 1) {
	  return 0;
	}
	reg = novo_reg(&info);
	if(reg != NULL) {
	  if(libera_reg(&reg) == 1 && reg == NULL) {
	    return 1;
	  }
	}
	
  return 0;
}

int testa_atribui_info_reg() {
  Info info;
  
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	Reg *reg = novo_reg(&info);
	
	if(reg != NULL) {
	  Info novo;
    scanf("%s", &novo.cod);
  	scanf("%d", &novo.dia);
  	scanf("%d", &novo.mes);
  	scanf("%d", &novo.ano);
  	scanf("%s", novo.cidade);
  	scanf("%s", novo.pais);
  	scanf("%d", &novo.periodo);
  	
	  if(atribui_info_reg(reg, &novo) == 1) {
	    Info *recuperado = acessa_info_reg(reg);
	    
	    if(recuperado != NULL) {
	      
	      if(strcmp(recuperado->cod, novo.cod) != 0) {
	        return 0;
	      }
	      
	      if(recuperado->dia != novo.dia) {
	        return 0;
	      }
	      
	      if(recuperado->mes != novo.mes) {
	        return 0;
	      }
	      
	      if(recuperado->ano != novo.ano){
	        return 0;
	      }
	      
	      if(strcmp(recuperado->cidade, novo.cidade) != 0) {
	        return 0;
	      }

	      if(strcmp(recuperado->pais, novo.pais) != 0) {
	        return 0;
	      }
	      
	      if(recuperado->periodo != novo.periodo) {
	       return 0;
	      }
	      
	      return 1;
	    }
	  }
	}
}

int testa_acessa_info_reg() {
  Info info;
  Reg *reg = NULL;
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	reg = novo_reg(&info);
	if(reg != NULL) {
	  
	  Info *recuperado = acessa_info_reg(reg);
	  
	    if(recuperado != NULL) {
	      
	      if(strcmp(info.cod, recuperado->cod)) {
	        return 0;
	      }
	      
	      if(info.dia != recuperado->dia) {
	        return 0;
	      }
	      
	      if(info.mes != recuperado->mes) {
	        return 0;
	      }
	      
	      if(info.ano != recuperado->ano){
	        return 0;
	      }
	      
	      if(strcmp(info.cidade, recuperado->cidade) != 0) {
	        return 0;
	      }

	      if(strcmp(info.pais, recuperado->pais) != 0) {
	        return 0;
	      }
	      
	      if(info.periodo != recuperado->periodo) {
	       return 0;
	      }
	      
	      return 1;
	    }
	}
	return 0;
}

int testa_add_dir_reg() {
  Info info_atual, info_dir;
  Reg *atual = NULL;
  Reg *dir = NULL;
  
  if(add_dir_reg(atual, dir) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_dir_reg(atual, dir) == 0) {
	    return 0;
	  }
	  
	  scanf("%s", &info_dir.cod);
  	scanf("%d", &info_dir.dia);
  	scanf("%d", &info_dir.mes);
  	scanf("%d", &info_dir.ano);
  	scanf("%s", info_dir.cidade);
  	scanf("%s", info_dir.pais);
  	scanf("%d", &info_dir.periodo);
	  dir = novo_reg(&info_dir);
	  
	  if(dir != NULL) {
	    if(add_dir_reg(atual, dir) == 1) {
	      if(visita_dir_reg(atual) != NULL) {
	        return 1;
	      }
	    }
	  }
	}
  
  return 0;
}

int testa_add_esq_reg() {
  Info info_atual, info_esq;
  Reg *atual = NULL;
  Reg *esq = NULL;
  
  if(add_esq_reg(atual, esq) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  scanf("%s", &info_esq.cod);
  	scanf("%d", &info_esq.dia);
  	scanf("%d", &info_esq.mes);
  	scanf("%d", &info_esq.ano);
  	scanf("%s", info_esq.cidade);
  	scanf("%s", info_esq.pais);
  	scanf("%d", &info_esq.periodo);
	  esq = novo_reg(&info_esq);
	  
	  if(esq != NULL) {
	    if(add_esq_reg(atual, esq) == 1) {
  	    if(visita_esq_reg(atual) != NULL) {
  	      return 1;
  	    }
	    }
	  }
	}
  
  return 0;
}

int testa_visita_dir_reg() {
  Info info_atual, info_dir;
  Reg *atual = NULL;
  Reg *dir = NULL;
  
  if(visita_dir_reg(atual) != NULL) {
    return 0;
	}
  
  if(add_dir_reg(atual, dir) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_dir_reg(atual, dir) == 0) {
	    return 0;
	  }
	  
	  scanf("%s", &info_dir.cod);
  	scanf("%d", &info_dir.dia);
  	scanf("%d", &info_dir.mes);
  	scanf("%d", &info_dir.ano);
  	scanf("%s", info_dir.cidade);
  	scanf("%s", info_dir.pais);
  	scanf("%d", &info_dir.periodo);
	  dir = novo_reg(&info_dir);
	  
	  if(dir != NULL) {
	    if(add_dir_reg(atual, dir) == 1) {
	      if(visita_dir_reg(atual) != NULL) {
	        Info *aux = acessa_info_reg(visita_dir_reg(atual));
	        
  	      if(strcmp(info_dir.cod, aux->cod) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.dia != aux->dia) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.mes != aux->mes) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.ano != aux->ano){
  	        return 0;
  	      }
  	      
  	      if(strcmp(info_dir.cidade, aux->cidade) != 0) {
  	        return 0;
  	      }
  
  	      if(strcmp(info_dir.pais, aux->pais) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.periodo != aux->periodo) {
  	       return 0;
  	      }	        
	        
	        return 1;
	      }
	    }
	  }
	}
  
  return 0;  
}

int testa_visita_esq_reg() {
  Info info_atual, info_esq;
  Reg *atual = NULL;
  Reg *esq = NULL;
  
  if(visita_esq_reg(atual) != NULL) {
   
    return 0;
	}
  
  if(add_esq_reg(atual, esq) == 1) {
   
    return 0;
	}
 
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_esq_reg(atual, esq) == 0) {
     
	    return 0;
	  }
	  
	  scanf("%s", &info_esq.cod);
  	scanf("%d", &info_esq.dia);
  	scanf("%d", &info_esq.mes);
  	scanf("%d", &info_esq.ano);
  	scanf("%s", info_esq.cidade);
  	scanf("%s", info_esq.pais);
  	scanf("%d", &info_esq.periodo);
	  esq = novo_reg(&info_esq);
	  
	  if(esq != NULL) {
	    if(add_esq_reg(atual, esq) == 1) {
	      if(visita_esq_reg(atual) != NULL) {
	        Info *aux = acessa_info_reg(visita_esq_reg(atual));
	        
  	      if(strcmp(info_esq.cod, aux->cod) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.dia != aux->dia) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.mes != aux->mes) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.ano != aux->ano){
  	        return 0;
  	      }
  	      
  	      if(strcmp(info_esq.cidade, aux->cidade) != 0) {
  	        return 0;
  	      }
  
  	      if(strcmp(info_esq.pais, aux->pais) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.periodo != aux->periodo) {
  	       return 0;
  	      }	        
	        
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
    case 5: printf("%d", testa_novo_reg()); //OK
            break;
    
    case 6: printf("%d", testa_libera_reg());  //OK
            break;
    
    case 7: printf("%d", testa_atribui_info_reg()); //OK
            break;
    
    case 8: printf("%d", testa_acessa_info_reg());  // OK
            break; 
    
    case 9: printf("%d", testa_add_dir_reg());  //OK
            break;
    
    case 10: printf("%d", testa_add_esq_reg()); //OK
             break;
    
    case 11: printf("%d", testa_visita_dir_reg()); // OK
             break;
    
    case 12: printf("%d", testa_visita_esq_reg()); // OK
             break;
  }}
	return 0;
}