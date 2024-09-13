#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include "listaEstatica.h"


void Menuagenda(){
	
	

	system("cls");
	Contato agenda[MAX_CONTATOS];
    int contador = 0;
    int opcao; 
    char nome[100]; 

    do {
    	    

    	printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t|------------Menu da Agenda---------|\n");
        printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t||1|. Adicionar Contato             |\n");
        printf("\t\t\t\t\t\t\t\t\t||2|. Listar Contatos               |\n");
        printf("\t\t\t\t\t\t\t\t\t||3|. Buscar Contato                |\n");
        printf("\t\t\t\t\t\t\t\t\t||4|. Remover Contato               |\n");
        printf("\t\t\t\t\t\t\t\t\t||5|. Sair                          |\n");
         printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\tEscolha uma opção: ");
       
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                adicionarContato(agenda, &contador); 
                break;
            case 2:

                listarContatos(agenda, contador); 
                break;
            case 3:
		system("cls"); 
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %s", nome);
                 
                buscarContato(agenda, contador, nome);
                break;
            case 4:
				system("cls");
				
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %s", nome);
                removerContato(agenda, &contador, nome); 
                break;
            case 5:

                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n"); 
        }
    } while (opcao != 5); 

}

void adicionarContato(Contato agenda[], int *contador) {
system("cls");
    if (*contador < MAX_CONTATOS) {

        printf("\nDigite o nome do contato: \n");
        scanf(" %s", agenda[*contador].nome);
        printf("Digite o telefone do contato: ");
        scanf(" %s", agenda[*contador].telefone);
        printf("Digite o email do contato: ");
        scanf(" %s", agenda[*contador].email);
        (*contador)++;
        	

        printf("\033[0;32mContato adicionado com sucesso!\033[0m\n");
         sleep(3);
        system("cls");
        
    } else {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
    }
}
int compararNomes(const void *a, const void *b) {
    Contato *contatoA = (Contato *)a;
    Contato *contatoB = (Contato *)b;
    return strcmp(contatoA->nome, contatoB->nome);
}
void listarContatos(Contato agenda[], int contador) {
   

    if (contador == 0) {
        printf("A agenda está vazia.\n"); 
    } else {
       
        qsort(agenda, contador, sizeof(Contato), compararNomes);

        for (int i = 0; i < contador; i++) {
        	system("cls");
        	printf("\t\t\t\t\t\t\t\t\t--------------------------|\n");
            printf("\t\t\t\t\t\t\t\t\t|Contato %d:\n", i + 1);
            printf("\t\t\t\t\t\t\t\t\t|Nome: %s\n", agenda[i].nome);
            printf("\t\t\t\t\t\t\t\t\t|Telefone: %s\n", agenda[i].telefone);
            printf("\t\t\t\t\t\t\t\t\t|Email: %s\n", agenda[i].email);
            printf("\t\t\t\t\t\t\t\t\t|-------------------------|\n");
           	  system("pause"); ]
             system("cls");
        }
    }
}
]
void buscarContato(Contato agenda[], int contador, const char *nome) {
            	

    for (int i = 0; i < contador; i++) {
    		
        if (strcmp(agenda[i].nome, nome) == 0) { ]
            printf("\t\t\t\t\t\t\t\t\tContato encontrado:\n");
            printf("\t\t\t\t\t\t\t\t\tNome: %s\n", agenda[i].nome);
            printf("\t\t\t\t\t\t\t\t\tTelefone: %s\n", agenda[i].telefone);
            printf("\t\t\t\t\t\t\t\t\tEmail: %s\n", agenda[i].email);
            system("pause"); 
        	system("cls");
        	
        	
        }
    }
  
    printf("\x1B[0;31mContato não encontrado.\x1B[0m\n");
}
void removerContato(Contato agenda[], int *contador, const char *nome) {
            		system("cls");

    for (int i = 0; i < *contador; i++) { 
    		

        if (strcmp(agenda[i].nome, nome) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*contador)--; 
		 
            printf("\033[0;32mContato removido com sucesso!\033[0m\n");
            	sleep(3); 
            	system("cls");
        }
    }

    printf("\x1B[0;31mContato não encontrado.\x1B[0m");
     	 sleep(3); 
   		system("cls");
}

