#ifndef FUNCOES_H
#define FUNCOES_H


//Variavel string100//
typedef char string100[100];

//variÃÂ¡vel CPF 
typedef char CPF[11];

//Genero
typedef enum genero{
    masculino, feminino
}GENERO;

typedef enum Est_civil{
    casado, solteiro, divorciado, viuvo
}EST_CIVIL;

//Data de nascimento
typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

//Struct Hardware//
typedef enum computador{
    Desktop, Notebook
}COMPUTADOR;


typedef struct hardware{
    COMPUTADOR computer;
    string100 cpu;
    string100 gpu;
    int ram;
}HARDWARE;

//Struct Dados do Campeonato//
typedef struct campeonato{
    int victories;
    int draws;
    int losses;
    int points;
}CAMPEONATO;

//Struct TÃÂ­tulos Campeonato//
typedef struct titulos{
    int titles;
}TITULOS;

//Struct Posicao Ranking Mundial//
typedef struct ranking{
    int rank;
}RANKING;

//Struct Equipe//
typedef struct equipe{
    string100 nome_equipe;
    string100 nickname_equipe;
    int seguidores_equipe;
}EQUIPE;

//Struct Rede Social//
typedef struct redesocial{
    string100 nickname_jogador;
    int seguidores_jogador;
}REDESOCIAL;

typedef struct jogador{
    string100 nome;
    DATA data;
    CPF cpf;
    GENERO genero;
    EST_CIVIL civil;
    EQUIPE time;  
    string100 patrocinadora;
    REDESOCIAL redesocial_jogador;
    HARDWARE hardware;
    CAMPEONATO campeonato;
    TITULOS titulos;
    RANKING ranking;
}JOGADOR;





void EscreverJogadoresArquivoBinario();

void LerJogadoresArquivoBinario();

void AlterarNomeJogadorArquivoBinario(int a);
void AlterarDataJogadorArquivoBinario(int a);
void AlterarCPFJogadorArquivoBinario(int a);
void AlterarGeneroJogadorArquivoBinario(int a);
void AlterarCivilJogadorArquivoBinario(int a);
void AlterarEquipeJogadorArquivoBinario(int a);
void AlterarPatrocinadoraJogadorArquivoBinario(int a);
void AlterarRedeSocialJogadorArquivoBinario(int a);
void AlterarHardwareJogadorArquivoBinario(int a);
void AlterarCampeonatoJogadorArquivoBinario(int a);

void InserirVitoriaEmpateDerrota(int a);

void BuscarJogadorNome(string100 chave);
void BuscarJogadorRank(int chave);

void MostrarMediaSeguidoresJogadores();

void OrdenarJogadores_alfabeto();
void OrdenarJogadores_posicao();
void OrdenarJogadores_vitoria ();

void ListarJogadores_posicaoCampeonato ();
void ListarJogadores_PontuacaoMenor (int limite);
void ListarJogadores_PontuacaoMaior (int limite);

#include "Funcoes.c"
#endif
