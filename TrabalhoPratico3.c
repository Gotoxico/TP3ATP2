#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Menu e utilização funções//
    PularLinha(2);
    printf("Este e um programa para manipular structs de jogadores gravados em arquivos binários!");
    PularLinha(2);

    int opcao;
    do{
        printf("1 - Gravar jogadores;\n");
        printf("2 - Ler jogadores;\n");
        printf("3 - Alterar jogador;\n");
        printf("4 - Listar jogadores ordem alfabética;\n");
        printf("5 - Listar jogadores posição rank mundial;\n");
        printf("6 - Listar jogadores que possuem maior número de vitórias;\n");
        printf("7 - Listar classificação campeonato;\n");
        printf("8 - Listar jogadores com pontuação maior que;\n");
        printf("9 - Listar jogadores com pontuação menor que;\n");
        printf("10 - Buscar jogador por nome;\n");
        printf("11 - Buscar jogador por rank mundial;\n");
        printf("12 - Mostrar média seguidores jogadores;\n");
        printf("13 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        string100 chaves;
        int a, chave, limite, opcao2;

        switch (opcao){
            case 1:
                EscreverJogadoresArquivoBinario();
                break;

            case 2:
                LerJogadoresArquivoBinario();
                break;

            case 3:
                printf("Digite numero jogador alterar: ");
                scanf("%d", &a);
                do{
                    printf("1 - Alterar nome;\n");
                    printf("2 - Alterar data;\n");
                    printf("3 - Alterar CPF;\n");
                    printf("4 - Alterar genero;\n");
                    printf("5 - Alterar estado civil;\n");
                    printf("6 - Alterar equipe;\n");
                    printf("7 - Alterar patrocinadora;\n");
                    printf("8 - Alterar rede social;\n");
                    printf("9 - Alterar hardware;\n");
                    printf("10 - Alterar Vitorias, empates, derrotas;\n");
                    printf("11 - Alterar campeonato;\n");
                    printf("12 - Sair;\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao2);

                    switch(opcao2){
                        case 1:
                            AlterarNomeJogadorArquivoBinario(a);
                            break;

                        case 2:
                            AlterarDataJogadorArquivoBinario(a);
                            break;
                        
                        case 3:
                            AlterarCPFJogadorArquivoBinario(a);
                            break;
                        
                        case 4:
                            AlterarGeneroJogadorArquivoBinario(a);
                            break;

                        case 5:
                            AlterarCivilJogadorArquivoBinario(a);
                            break;

                        case 6:
                            AlterarEquipeJogadorArquivoBinario(a);
                            break;

                        case 7:
                            AlterarPatrocinadoraJogadorArquivoBinario(a);
                            break;

                        case 8:
                            AlterarRedeSocialJogadorArquivoBinario(a);
                            break;

                        case 9:
                            AlterarHardwareJogadorArquivoBinario(a);
                            break;

                        case 10:
                            InserirVitoriaEmpateDerrota(a);
                            break;
                        
                        case 11:
                            AlterarCampeonatoJogadorArquivoBinario(a);
                            break;
                        
                        case 12:
                            printf("\n\nParou de alterar jogador!\n\n");
                            break;

                        default:
                            printf("\n\nOpcao invalida!\n");
                            break;
                    }
                }while(opcao2 != 12);
                break;

             case 4:
                OrdenarJogadores_alfabeto( );

                break;
            
            case 5:
                OrdenarJogadores_posicao();
                break;
            
            case 6:
                OrdenarJogadores_vitoria();

                break;
            
            case 7:
                ListarJogadores_posicaoCampeonato();
                break;
            
            case 8:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuação maior: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMaior(limite );
                break;
            
            case 9:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuação menor: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMenor(limite);
                break;
            
            case 10:
                printf("Digite nome: ");
                fflush(stdin);
                gets(chaves);
                BuscarJogadorNome(chaves);
                break;

            case 11:
                printf("Digite rank: ");
                scanf("%d", &chave);
                BuscarJogadorRank(chave);
                break;

            case 12:
                MostrarMediaSeguidoresJogadores();
                break;

            case 13:
                printf("\n\nSaiu do programa!\n\n");
                break;

            default:
                printf("\n\nOpcao invalida! Digite outra:\n\n");
                break;
        }
        if(opcao != 13){
            system("pause");
            PularLinha(2);
        }
    }while(opcao != 13);
}




