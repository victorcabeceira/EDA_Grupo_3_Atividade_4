/*Arquivo destinado para realizacao do trabalho de numero 4.
Tema:Arvores Binarias de Pesquisa (ABP) 
Materia:EDA 
Professor: Nilton
Integrantes: 1-Henrique Augusto - Matricula:??/??????? - ??
             2-Ricardo - Matrícula:??/??????? - ??
             3-Victor Fellipe Gonçalves Cabeceira - Matrícula:13/0048976 - victorfgcabeceira@gmail.com
             
             
Repositório no git - "git@github.com:victorcabeceira/EDA_Grupo_3_Atividade_4.git"

Enunciado:
Faca um programa para ordenacoes deste arquivo utilizando o conceito de Arvore Binaria de Pesquisa (ABP). O programa deve conter as seguintes funcionalidades:
     1. [1,0] Carregar um arquivo (conforme a estrutura da figura 1). O nome do arquivo deve ser informado pelo usuario;
     2. [3,0] Exibir um registro (Mostrar Nome e Predio). O usuario informara o codigo do curso a ser exibido;
     3. [3,0] Excluir um registro. O usuario informara o codigo do curso a ser excluido;
     4. Gravar arquivos de saida:
        a. [1,0] Codigo.txt: Conteudo do arquivo carregado ordenado pelo campo Codigo;
        b. [1,0] Nome.txt: Conteudo do arquivo carregado ordenado pelo campo Nome;
        c. [1,0] Predio.txt: Conteudo do arquivo carregado ordenado pelo campo Predio;
-> A busca a ser realizada no item 2 deve ser feita sobre uma ABP pela campo Codigo e deve respeitar as exclusoes.
-> O item 3 deve respeitar as exclusoes e deve ser resolvido seguindo o fluxo demonstrado na figura 2 para uma dada chave (campo) Ch.
Figura 2.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Comeco da struct - teste

//Menu
void menu(){
    printf("\n\t\t\t____________________________\n");
    printf("\t\t\t Digite a opcao desejada:\n");
    printf("\t\t\t____________________________\n\n");

    printf("\t\t **-------------------------------------------** \n");
    printf("\t\t || \t 1) Exibir registro                   || \n"); //Mostra nome e predio, pede o codigo
    printf("\t\t || \t 2) Excluir registro                  || \n");  //Pede o codigo para realizar a exclusao
    printf("\t\t || \t 3) Ordenar e gerar arquivo de saída  || \n"); //Grava o arquivo de saída a partir do especificado pelo usuário entre por: codigo,nome e predio
    printf("\t\t || \t 4) TESTE                             || \n");
    printf("\t\t || \t 5) TESTE                             || \n");
    printf("\t\t || \t 6) Sair do programa                  || \n");
    printf("\t\t **-------------------------------------------** \n");

}

//Main
main()
{
      int opcao, ordem,codigoDePesquisa;
      
      do
      {
          system("cls");
          menu();
          
          scanf("%i", &opcao);
          
          switch(opcao){
                
            case 1:
                printf("\nInforme o codigo do registro que deseja visualizar: ");
                scanf("%d",&codigoDePesquisa); //Exemplo
                //retorna_dados(busca_por_codigo(arvore_codigos,codigoDePesquisa));
                break;
            case 2:
                printf("\nInforme o codigo do curso que se deseja excluir : ");
                //HUEHUEHUHE
                break;
            case 3:
                printf("\nQual o metodo de ordenacao desejado?\n(1)-Codigo \n(2)-Nome\n(3)-Predio\n");
                scanf("%i",&ordem);
                    switch(ordem)
                    {
                        case 1:
                             printf("Ordenacao por codigo.\n");
                             /*ordena_codigo(Arvore);
                             geraArquivo();*/
                             break;              
                        case 2:
                             printf("Ordenacao por nome.\n");
                             /*ordena_nome(Arvore);
                             geraArquivo();*/
                             break;
                        case 3:
                             printf("Ordenacao por predio.\n");
                             /*ordena_predio(Arvore);
                             geraArquivo();*/
                             break;
                        default:
                             printf("Opcao invalida.\n");
                    }
            
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf ("\n\nSaindo do programa!\n\n");
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }while(opcao!=6);

    system("pause");
}//Fim Main
