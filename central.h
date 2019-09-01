#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Aen = 0, Ben = 0, Cout = 0, id = 0, count = 0, op = 0, overFlow = 0;
void menuRegistradorA();
void menuRegistradorB();
void menuOperacao();

typedef struct lista
{
	int id;
	int num;
	struct lista *ant;
	struct lista *prox;
} registradorA, registradorB, registradorC;

registradorA *p, *q, *ini= NULL, *fim = NULL;
registradorB *c, *g, *com = NULL, *final = NULL;
registradorC *b, *r, *beg = NULL, *end = NULL;




int insereNumA (int n, int id)
{
		p = (registradorA *)malloc(sizeof(registradorA));
		
		p->id = id;
		p->num = n;
		p->prox = NULL;
		p->ant = NULL;
		
		if(ini == NULL)
		{
			ini = p;
		}
		else
		{
			q->prox = p;
			p->ant = q;
			ini->ant = p;
		}
		q = p;
		fim = p;
}


int insereNumB (int n, int id)
{

	c = (registradorB *)malloc(sizeof(registradorB));
	
	c->id = id;
	c->num = n;
	c->prox = NULL;
	
	if(com == NULL)
	{
		com = c;
	}
	else
	{
		g->prox = c;
		c->ant = g;
		com->ant = c;
	}
	g = c;
	final = c;
	
}

int insereNumC (int n)
{	
		
		b = (registradorC *)malloc(sizeof(registradorC));
		
		b->num = n;
		b->prox = NULL;
		b->ant = NULL;
		
		if(beg == NULL)
		{
			beg = b;
		}
		else
		{
			r->prox = b;
			b->ant = r;
			beg->ant = b;
		}
		r = b;
		end = b;			

}



void exibirRegistradorA(void){
	
    p = ini;
    printf("Registrador A: ");
    while(p->prox != NULL){
        printf("%d  ", p->num);
        p = p->prox;
    }
    printf("%d ", p->num);
}

void exibirRegistradorB(void){	
    c = com;
    printf("Registrador B: ");
    while(c->prox != NULL){
        printf("%d  ", c->num);
        c = c->prox;
    }
    printf("%d ", c->num);
}


void exibirRegistradorC(void){
    b = end;
    printf("Registrador C: ");
    while(b != beg){
        printf("%d  ", b->num);
        b = b->ant;
    }
    printf("%d ", b->num);
}

void captaRegistradorA(char num[4]){
	int m, l=0;	
	for(l = 0; l<=3; l++){	
		m = int(num[l]) - 48;
		insereNumA(m, l);
	}
	printf("Gravado com sucesso no Registrador A!\n");
	exibirRegistradorA();	
}

void captaRegistradorB(char num[4]){
	int m, l=0;	
	for(l = 0; l<=3; l++){	
		m = int(num[l]) - 48;
		insereNumB(m, l);
	}
	printf("Gravado com sucesso no Registrador B!\n");
	exibirRegistradorB();	
}

void excluirNumA(void){
	int del;
	system("CLS");
	exibirRegistradorA();
	printf("\n	   ID: 0  1  2  3\n");
	printf("Digite o ID do número que deseja trocar: ");
	scanf("%d", &del);
	p = ini;
	count = 0;
	do{
		if(p->id == del){
			if(p->num == 0)
			{
				p->num = 1;
			}
			else
			{
				p->num = 0;
			}
		}
		p = p->prox;	
		count++;
	}while(count <= 3);
	exibirRegistradorA();
}

void excluirNumB(void){
	int del;
	system("CLS");
	exibirRegistradorB();
	printf("\n	   ID: 0  1  2  3\n");
	printf("Digite o ID do número que deseja trocar: ");
	scanf("%d", &del);
	c = com;
	count = 0;
	do{
		if(c->id == del){
			if(c->num == 0)
			{
				c->num = 1;
			}
			else
			{
				c->num = 0;
			}
		}
		c = c->prox;	
		count++;
	}while(count <= 3);
	exibirRegistradorB();
}


void deletaRegistradorA(){
	p = ini;
	do{
		p->prox = NULL;
	}while(p != ini);
	p = NULL;
	ini = NULL;
	fim = NULL;
}

void deletaRegistradorB(){
	c = com;
	do{
		c->prox = NULL;
	}while(c != com);
	c = NULL;
	com = NULL;
	final = NULL;
}

void deletaRegistradorC(){
	b = beg;
	do{
		b->prox = NULL;
	}while(b != beg);
	b = NULL;
	beg = NULL;
	end = NULL;
}


	
int Menu(void){
	do
	{
		printf("\n\n-------MENU-------\n\n1 - Registrador A\n2 - Registrador B\n3 - Operacao\n4 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				menuRegistradorA();	
			break;
			case 2:
				menuRegistradorB();	
			break;
			case 3:
				menuOperacao();
			break;
			case 4:
				printf("\nSaindo...");
				getche();
				return 0;
			break;
		}
		
	}while(op != 4);		
}	

void menuRegistradorA(){
	system("CLS");
	
	do
	{
		system("CLS");
		printf("\n\n---REGISTRADOR A---\n\n1 - Inserir\n2 - Alterar \n3 - Exibir\n4 - Voltar\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("CLS");
				printf("\n\n------INSERIR------\n\n");
				char numA[4];
				printf("\nDigite um numero de 4 bits: ");
				scanf("%s", &numA);
				if(fim != NULL){
					deletaRegistradorA();
					captaRegistradorA(numA);
				}else{
					captaRegistradorA(numA);
				}	
				getche();
								
			break;
			case 2:
				system("CLS");
				printf("\n\n------ALTERAR------\n\n");	
				excluirNumA();
				getche();				
			break;
			case 3:
				system("CLS");
				printf("\n\n------EXIBIR-------\n\n");
				exibirRegistradorA();
				getche();					
			break;
			case 4:
				system("CLS");
				Menu();
			break;
		}
		
	}while(op != 4);
	
}			

void menuRegistradorB(){
	system("CLS");
	
	do
	{
		system("CLS");
		printf("\n\n---REGISTRADOR B---\n\n1 - Inserir\n2 - Alterar \n3 - Exibir\n4 - Voltar\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("CLS");
				printf("\n\n------INSERIR------\n\n");
				char numB[4];
				printf("\nDigite um numero de 4 bits: ");
				scanf("%s", &numB);
				if(final != NULL){
					deletaRegistradorB();
					captaRegistradorB(numB);
				}else{
					captaRegistradorB(numB);
				}	
				getche();
								
			break;
			case 2:
				system("CLS");
				printf("\n\n------ALTERAR------\n\n");	
				excluirNumB();
				getche();				
			break;
			case 3:
				system("CLS");
				printf("\n\n------EXIBIR-------\n\n");
				exibirRegistradorB();
				getche();					
			break;
			case 4:
				system("CLS");
				Menu();
			break;
		}
		
	}while(op != 4);
	
}			



void validaOperacaoAmenosB(){
	Aen = p->num;
	Ben = c->num;
	p = p->prox;
	c = c->prox;
	
	if(Aen == 0 && Ben == 1){
		printf("\nErro. Impossivel fazer a operacao.");
		getche();
		menuOperacao();						
	}
	else if(Aen == 1 && Ben == 1 || Aen == 0 && Ben == 0){
		validaOperacaoAmenosB();									
	}
}

void validaOperacaoBmenosA(){
	Aen = p->num;
	Ben = c->num;
	p = p->prox;
	c = c->prox;
	
	if(Ben == 0 && Aen == 1){
		printf("\nErro. Impossivel fazer a operacao.");
		getche();
		menuOperacao();						
	}
	else if(Ben == 1 && Aen == 1 || Ben == 0 && Aen == 0){
		validaOperacaoBmenosA();									
	}
}

void menuOperacao(){
	system("CLS");
	
	do
	{
		system("CLS");
		printf("\n\n------OPERACAO------\n\n000 - Clear\n001 - B Minus A \n010 - A Minus B\n011 - A Plus B\n100 - A Xor B\n101 - A Or B\n110 - A And B\n111 - Preset\n\n\n9 - Voltar\n");			
		scanf("%d",&op);
		overFlow = 0;
		switch(op){
			case 0:
				system("CLS");
				printf("\n\n-------CLEAR-------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				for(count = 0; count <=3; count++){
					insereNumC (0);	
				}
				exibirRegistradorC();
				getche();							
			break;
			case 1:
				system("CLS");
				printf("\n\n------B MINUS A-----\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				p = ini;
				c = com;
				validaOperacaoBmenosA();
				p = fim;
				c = final;
				overFlow = 0;
				do{				
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if(Ben == 1 && Aen == 0){
						if(overFlow == 1){
							Cout = 0;
							overFlow = 0;
						}
						else{
							Cout = 1;
						}
					}else if(Ben == 0 && Aen == 1){
						if(overFlow == 1){
							Cout = 0;
							overFlow = 0;
						}else{
							Cout = 1;
							overFlow = 1;
						}
					}else if(Ben == 1 && Aen == 1){
						if(overFlow == 1){
							Cout = 1;
							overFlow = 1;
						}else{
							Cout = 0;
						}
					}else{
						if(overFlow == 1){
							Cout = 1;
							overFlow = 1;
						}else{
							Cout = 0;
						}
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();		
				
				getche();				
			break;
			case 10:
				system("CLS");
				printf("\n\n------A MINUS B-----\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				p = ini;
				c = com;
				validaOperacaoAmenosB();
				p = fim;
				c = final;
				overFlow = 0;
				do{				
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if(Aen == 1 && Ben == 0){
						if(overFlow == 1){
							Cout = 0;
							overFlow = 0;
						}
						else{
							Cout = 1;
						}
					}else if(Aen == 0 && Ben == 1){
						if(overFlow == 1){
							Cout = 0;
							overFlow = 0;
						}else{
							Cout = 1;
							overFlow = 1;
						}
					}else if(Aen == 1 && Ben == 1){
						if(overFlow == 1){
							Cout = 1;
							overFlow = 1;
						}else{
							Cout = 0;
						}
					}else{
						if(overFlow == 1){
							Cout = 1;
							overFlow = 1;
						}else{
							Cout = 0;
						}
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();
				getche();						
			break;
			case 11:
				system("CLS");
				printf("\n\n------A PLUS B------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				
				p = fim;
				c = final;
				do{				
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if(Aen == 0 && Ben == 0){
						if(overFlow == 1){
							Cout = 1;
							overFlow = 0;
						}else{
							Cout = 0;	
						}
						
					}else if(Aen == 0 && Ben == 1||Aen == 1 && Ben == 0){
						if(overFlow == 1){
							Cout = 0;
							overFlow = 1;
						}else{
							Cout = 1;
						}
					}else{
						if(overFlow == 1){
							Cout = 1;
							overFlow = 1;
						}else{
							Cout = 0;
							overFlow = 1;							
						}
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();
				getche();	
			break;
			case 100:
				system("CLS");	
				printf("\n\n-------A XOR B------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				p = fim;
				c = final;
				do{
					q = p;
					g = c;					
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if((Aen == 0 && Ben == 0)||(Aen == 1 && Ben == 1)){
						Cout = 0;
					}else{
						Cout = 1;
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();
				getche();
			break;
			case 101:
				system("CLS");	
				printf("\n\n--------A OR B-------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				p = fim;
				c = final;
				do{
					q = p;
					g = c;					
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if(Aen == 0 && Ben == 0){
						Cout = 0;
					}else{
						Cout = 1;
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();						

				getche();
			break;
			case 110:
				system("CLS");	
				printf("\n\n-------A AND B-------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				p = fim;
				c = final;
				do{
					q = p;
					g = c;					
					Aen = p->num;
					Ben = c->num;
					p = p->ant;	
					c = c->ant;	
					if(Aen == 1 && Ben == 1){
						Cout = 1;
					}else{
						Cout = 0;
					}
					insereNumC (Cout);			
				}while(p!=fim);
				exibirRegistradorC();
				getche();
			break;
			case 111:
				system("CLS");	
				printf("\n\n--------PRESET--------\n\n");
				if(beg != NULL){
					deletaRegistradorC();
				}
				for(count = 0; count <=3; count++){
					insereNumC (1);	
				}
				exibirRegistradorC();
				getche();	
			break;
			case 9:
				system("CLS");
				Menu();
			break;
		}
		
	}while(op != 9);
	
}			


