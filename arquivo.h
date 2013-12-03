#include<stdio.h>
#include<stdlib.h>

struct Tupla
{
       int codigo;
       char curso[35];
       int predio;
       int chave;
       

};

struct ArvoreCodigo
{
	int codigo;
	int linha;
	int predio;
	char curso[35];
	struct ArvoreCodigo *esquerda;
	struct ArvoreCodigo *direita;

	ArvoreCodigo()
	{
		predio=NULL;
		
	}

	
};

