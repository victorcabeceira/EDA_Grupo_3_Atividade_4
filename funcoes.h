#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arquivo.h"

//Constroi arvore padrão
ArvoreCodigo *construirArvore(ArvoreCodigo *arvore,Tupla arquivo)
{
        
    if(arvore != NULL)
    {
        if(arquivo.codigo < arvore->codigo)
        {
        	arvore->esquerda = construirArvore(arvore->esquerda,arquivo);
        }
        else
	{
		arvore->direita = construirArvore(arvore->direita,arquivo);
	}        
               
    }
    else
    {
       arvore = (ArvoreCodigo*)malloc(sizeof(ArvoreCodigo));
               
        arvore->codigo = arquivo.codigo;
        arvore->linha = arquivo.chave;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
    }
    return arvore;   
      
}

//Constroi Arvore baseando-se no curso
ArvoreCodigo *construirArvoreCurso(ArvoreCodigo *arvore,Tupla arquivo)
{
        
    if(arvore != NULL)
    {
        if(strcmp(arquivo.curso, arvore->curso) <= 0 )
        {
        	arvore->esquerda = construirArvoreCurso(arvore->esquerda,arquivo);
        }
        else
	{
		arvore->direita = construirArvoreCurso(arvore->direita,arquivo);
	}        
               
    }
    else
    {
       arvore = (ArvoreCodigo*)malloc(sizeof(ArvoreCodigo));
               
        strcpy (arvore->curso,arquivo.curso);
        arvore->linha = arquivo.chave;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
    }
    return arvore;   
      
}

//Constroi Arvore baseando-se no predio
ArvoreCodigo *construirArvorePredio(ArvoreCodigo *arvore,Tupla arquivo)
{
        
    if(arvore != NULL)
    {
        if(arquivo.predio < arvore->predio)
        {
        	arvore->esquerda = construirArvorePredio(arvore->esquerda,arquivo);
        }
        else
	{
		arvore->direita = construirArvorePredio(arvore->direita,arquivo);
	}        
               
    }
    else
    {
       arvore = (ArvoreCodigo*)malloc(sizeof(ArvoreCodigo));

        arvore->codigo = arquivo.codigo;       
        arvore->predio = arquivo.predio;
        arvore->linha = arquivo.chave;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
    }
    return arvore;   
      
}

//Carrega Arquivo txt
struct Tupla *carregarArquivo(FILE *estrutura,char nomeArquivo[],int numeroDeLinhas,ArvoreCodigo **arvore,int construir)
{	
	struct Tupla *carregar;
	
	
	
	int i=0;
	carregar=(Tupla*)malloc(numeroDeLinhas*sizeof(Tupla));		
    
                                                   
    estrutura = fopen(nomeArquivo,"r");
    
    
    
	while(fscanf(estrutura,"%d",&carregar[i].codigo)!=EOF)
	{
      		    
		   
		fscanf(estrutura,"%d",&carregar[i].codigo);
		fscanf(estrutura,"%s",&carregar[i].curso);             
		fscanf(estrutura,"%d",&carregar[i].predio);
		carregar[i].chave = i;

	if(construir == 0)
	{	      
		*arvore=construirArvore(*arvore,carregar[i]);
	}
	else if(construir == 1)
	{
		*arvore=construirArvoreCurso(*arvore,carregar[i]);
	}
	else if(construir ==3)
	{
		*arvore=construirArvorePredio(*arvore,carregar[i]);	
	}
         
      i++;
      
                             
	}
     
     fclose(estrutura);
     
     return carregar;
}

//Pesquisa codigo desejado
struct ArvoreCodigo *pesquisarCodigo(struct ArvoreCodigo *arvorer,int codPesquisa)
{
	if(arvorer != NULL)
	{
		if(codPesquisa == arvorer->codigo)//codigo encontrado
		{	
			return arvorer;
		}
		else if(codPesquisa <= arvorer->codigo)//pesquisar na esquerda
		{	
			return pesquisarCodigo(arvorer->esquerda,codPesquisa);
		}
		else//pesquisar na direita
		{
			
			return pesquisarCodigo(arvorer->direita,codPesquisa);
		}
		
	}
	else
	{
		return NULL;
	}
		
}

//Descobre o minimo de uma arvore
struct ArvoreCodigo *minimo(ArvoreCodigo *T){// procura o nó com valor mínimo
    if(T==NULL){
       return T;
    }else{
          if( T->esquerda == NULL){
              return T;
          }else{
              return minimo(T->esquerda);
          }
    }
}

//Exclui Arvore perante um codigo
struct ArvoreCodigo *excluirNo(ArvoreCodigo *arvore,int cod)
{
	if ( arvore == NULL )
	{
		printf("\nElemento nao encontrado\n");
	}
	else
	{
		if (cod < arvore->codigo)
		{         // busca a esquerda
			return excluirNo( arvore->esquerda, cod );
		}	
		else
		{
			if ( cod > arvore->codigo )
			{     // busca a direita
				return excluirNo( arvore->direita, cod );
			}
			else
			{
				ArvoreCodigo *temp = arvore;
				if ( arvore->esquerda == NULL )
				{  // existe somente um filho a direita
					arvore = arvore->direita;   // aponta a direita
				}
				else
				{
					if ( arvore->direita == NULL )
					{ // existe somente um filho a esquerda
						arvore = arvore->esquerda;
					}
					else
					{
						// o nodo possui dois filhos
						temp = minimo((arvore)->direita);
						(arvore)->codigo = (temp->codigo);
                     				return excluirNo((arvore)->direita, (arvore)->codigo);
							
					}
				}
				free (temp);
				return arvore;
			}
		}
	}
}

//Ordena e imprimi em Ordem
void ordenaCodigo(struct ArvoreCodigo *t,FILE *novotxt,Tupla *arquivo)
{	


 	if (t != NULL)
	{	
		ordenaCodigo(t->esquerda,novotxt,arquivo);
		fprintf(novotxt,"(%d)\t",arquivo[t->linha].codigo);
		fprintf(novotxt,"%s\t",arquivo[t->linha].curso);
		fprintf(novotxt,"%d\n",arquivo[t->linha].predio);
		ordenaCodigo(t->direita,novotxt,arquivo);	
	}
	
		
}

/*void imprime(struct ArvoreCodigo *t,Tupla *arquivo)
{	


 	if (t != NULL)
	{	
		ordenaCodigo(t->esquerda,NULL, arquivo);
		printf("(%d)\t",arquivo[t->linha].codigo);
		printf("%s\t",arquivo[t->linha].curso);
		printf("%d\n",arquivo[t->linha].predio);
		ordenaCodigo(t->direita,arquivo);	
	}
	
		
}*/




