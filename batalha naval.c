
/*DESENVOLVIDO POR TALLYSON JOSÉ LUCAS FAUSTINO*/
/*Inclusão de Bibliotecas da linguagem*/
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
/* Fim da Inclusão de Bibliotecas*/

/*Declaração de Variáveis Globais*/
	char matriz[5][5];
	char tab_nav[5][5];
	int cont_jog=0,cont_acert=0,cont_erro=0;
/* Fim das variáveis Globais*/

/* Início- Funções para o jogo*/

	//Preenche o tabuleiro com ~ representando agua
	 	preenche_tabuleiro(){
	 		int i,j;
	 		for(i=0;i<5;i++){
		 		for(j=0;j<5;j++){
		 			matriz[i][j]= '~';
				}
			}
		}
	//fim de preenche_tabuleiro();
	
	//Exibe o tabuleiro de acordo com o valor que está na matriz global
	mostra_tabuleiro(){
		int i,j;
		printf("-------------------------------------------------\n");
		for(i=0;i<5;i++){
			printf("|	");
			for(j=0;j<5;j++){
				printf("%c	",matriz[i][j]);			
			}
			printf("|");
			printf("\n\n");
		}
		printf("-------------------------------------------------\n");
	}
	// fim de mostra_tabuleiro();
	
	//Cria Matriz que será visualizada pelo jogador
	navios_tabuleiro(){
		int k,l,i,j;
		for(k=0;k<5;k++)
			for(l=0;l<5;l++)
				tab_nav[k][l]='-';
	}
	//fim de navios_tabuleiro();
	
	//Realiza o sorteio do local onde estará os navios e onde estará água
	sorteio(){
		bool x=true;
		int k,l,i,j;
		do{
			srand(time(NULL));
			i=rand()%5;
		//	printf("%d\n",i);
			j=rand()%5;
		//	printf("%d\n",j);
			if(tab_nav[i][j]=='-'){
		 		tab_nav[i][j]='U';
		 		x=true;
	 		}
	 		else x=false;
	 	}
	 	while (x==false);
	}
	//fim de sorteio
	
	
	//Criada para exibir as coordenadas de onde estavam os navios - Matriz do Jogo-
	mostra_navios() {
	 	printf("\n");
	 	printf ("Estas eram as coordenadas dos navios.\n");
	 	int i,j;
	 	for(i=0;i<5;i++){
	 		for(j=0;j<5;j++){
	 			printf("%c	",tab_nav[i][j]);
	 		}
	 		printf("\n\n");
		}
	}
	//fim de mostra_navios();
	
	//Verifica se as coordenadas digitas estão corretas e são válidas
	int aceita_jogada(char linha, char coluna){
		int l=((int)(linha)-48);
		int c=((int)(coluna)-48);
		if(matriz[l][c]=='~')
			return 1;
		return 0;
	}
	//fim de aceita_jogada();
	
	//Criada para tratar casos de usuário pressionar letras ao invés de número.
	int aceita_jogada02(char var){
		int i;
		if(var=='0'||var=='1'||var=='2'||var=='3'||var=='4'){
			return 1;
		}
		else return 0;
	}
	//fim de aceita_jogada();
	
	//Realiza veirificação para determinar acertos e erros do jogador
	void compara_nav(int l, int c){
		if(matriz[l][c]=='~'){
			
					if(tab_nav[l][c]=='U'){
						matriz[l][c]=tab_nav[l][c];
						cont_acert++;
					}
					else {
						matriz[l][c]='x';
						cont_erro++;
					}
		}
	}
	//fim de compara_nav();
	
	//Imprimir troféu ao fim do jogo
	void trofeu(){
		printf("                                \n");
	    printf("\t\t     ______________________\n");
	    printf("\t\t   /|                    |\\    \n");
	    printf("\t\t /  |                    | \\   \n");
	    printf("\t\t |  |                    |  |   \n");
	    printf("\t\t  \\ |                    | /   \n");
	    printf("\t\t   \\|                    |/    \n"); 
	    printf("\t\t    |                    |      \n");
	    printf("\t\t     \\                  /      \n");
	    printf("\t\t      \\                /       \n");
	    printf("\t\t       \\              /        \n");
	    printf("\t\t        |            |          \n");
	    printf("\t\t         |          |           \n");
	    printf("\t\t          |        |            \n");
	    printf("\t\t           |      |             \n");
	    printf("\t\t           |      |             \n");
	    printf("\t\t         __|______|__        \n");
	}
	//fim de trofeu();
	
	// Mostrar resultado do jogo
	void gera_result(float i, float j){ 
		mostra_navios();
		printf("Foram realizadas %d jogadas.\n",cont_jog);
		printf(" Atingiram a água %d tiros.\n",cont_erro);
		printf("Seu percentual de acerto foi %.2f%%.\n",(i/j)*100);
	}
	//fim de gera_result();
	
	//Função principal do programa
	main(){
		//Idioma
		setlocale(LC_ALL,"portuguese");
		//Variáveis
	 	int i,j;
	 	int x=1;
	 	char lin,col;
	 	int l,c;
	 	//Introdução
	 	printf (" ----------------------------------------\n");
	 	printf (" |            | BATALHA NAVAL |         |\n");
	 	printf (" ----------------------------------------\n");
		printf("\n\n");
		//preenche matriz
	 	preenche_tabuleiro();
	 	//exibe matriz sem os locais dos navios
	 	mostra_tabuleiro();
	 	//insere os navios na matriz
	 	navios_tabuleiro();
	 	//sorteia as coordenadas dos navios
	 	do {
		 	sorteio();
	 		x++;
	 	}
	 	while (x<=4);
	 	// Principal laço do jogo-Do início ao fim-
	 	do{
			printf("Digite uma coordenada para atirar:\n");
			// verifica se a coordenada é válida, com números válidos e se a coordenada não se repete
			do{
				//verifica se a coordenada é um número e se é uma posição válida
				do{
					printf("Digite uma posição entre 0 e 4 para linha .\n");
					fflush(stdin);
					scanf("%c",&lin);
				}
				while(aceita_jogada02(lin)==0);
				do{
					printf("Digite um posição entre 0 e 4 para coluna .\n");
					fflush(stdin);
					scanf("%c",&col);
				}
				while(aceita_jogada02(col)==0);
			}
			while((aceita_jogada(lin,col)==0));
			l=(int)(lin)-48;//convertendo char para inteiro para salvar as posições 
			c=(int)(col)-48;//convertendo char para inteiro para salvar as posições 
			cont_jog++;//numero de jogadas
			compara_nav(l,c);//verifica se não ganhou
			mostra_tabuleiro();// mostra novamente o tabuleiro do jogador
		}
		while(cont_acert<4);// se acertou todos os locais do navio
		gera_result(cont_acert,cont_jog);// mostra o resultado
		trofeu();//exibe o troféu
	}
	// fim do main();
