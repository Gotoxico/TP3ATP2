 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "Funcoes.h"
// #include <locale.h>

//fun��o de pular linha
void PularLinha(int num){
    for(int i = 0; i < num;i++){
        printf("\n");
    }
}

//Fun��o Escrever Jogadores Vetor e no Arquivo Binario//

void EscreverJogadoresArquivoBinario(){
    JOGADOR jogadores[1];
    for(int i=0; i<1; i++){
        printf("\nNome jogador: ");
        fflush(stdin);
        gets(jogadores[i].nome);

        printf("Dia nascimento: ");
        scanf("%d", &jogadores[i].data.dia);
        printf("Mes nascimento: ");
        scanf("%d", &jogadores[i].data.mes);
        printf("Ano nascimento: ");
        scanf("%d", &jogadores[i].data.ano);
        fflush(stdin);

        printf("CPF: ");
        gets(jogadores[i].cpf);
        fflush(stdin);
        
        do{
            printf("Genero (Masculino=0/Feminino=1):");
            scanf("%u", &jogadores[i].genero);
        }while(jogadores[i].genero!=0 && jogadores[i].genero!=1);
            
        do{
            printf("Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3):");
            scanf("%u", &jogadores[i].civil);
        }while(jogadores[i].civil!=0 && jogadores[i].civil!=1 && jogadores[i].civil!=2 && jogadores[i].civil!=3);

        printf("Nome Equipe: ");
        fflush(stdin);
        gets(jogadores[i].time.nome_equipe);
        printf("Nickname equipe rede social: ");
        fflush(stdin);
        gets(jogadores[i].time.nickname_equipe);
        printf("Seguidores rede social equipe: ");
        scanf("%d", &jogadores[i].time.seguidores_equipe);

        printf("Patrocinadora principal: ");
        fflush(stdin);
        gets(jogadores[i].patrocinadora);

        printf("Rede social: ");
        fflush(stdin);
        gets(jogadores[i].redesocial_jogador.nickname_jogador);

        printf("Seguidores rede social: ");
        scanf("%d", &jogadores[i].redesocial_jogador.seguidores_jogador);

        do{
            printf("Desktop(0) ou Notebook(1)? ");
            scanf("%u", &jogadores[i].hardware.computer);
        }while(jogadores[i].hardware.computer!=0 && jogadores[i].hardware.computer!=1);
        printf("CPU: ");
        fflush(stdin);
        gets(jogadores[i].hardware.cpu);
        printf("GPU: ");
        fflush(stdin);
        gets(jogadores[i].hardware.gpu);
        printf("Quantidade RAM: ");
        scanf("%d", &jogadores[i].hardware.ram);

        printf("Vitorias: ");
        scanf("%d", &jogadores[i].campeonato.victories);
        printf("Empates: ");
        scanf("%d", &jogadores[i].campeonato.draws);
        printf("Derrotas: ");
        scanf("%d", &jogadores[i].campeonato.losses);
        int vitorias = jogadores[i].campeonato.victories*3;
        int empates = jogadores[i].campeonato.draws*1;
        int derrotas = jogadores[i].campeonato.losses*0;
        int pontos = vitorias+empates+derrotas;
        jogadores[i].campeonato.points=pontos;

        printf("Titulos: ");
        scanf("%d", &jogadores[i].titulos.titles);

        printf("Ranking: ");
        scanf("%d", &jogadores[i].ranking.rank);

        PularLinha(2);
    }

    //Escrever Vetor no Arquivo Binario//
        FILE *file;
        file = fopen("TrabalhoPratico.dat", "ab");
        if(file != NULL){
            fwrite(jogadores, sizeof(JOGADOR), 1, file);
            fclose(file);
        }
        
        else{
            printf("\n\nArquivo populado!\n\n");
        }
    return;
}

//Fun��o ler jogadores arquivo binario//

void LerJogadoresArquivoBinario(){
     FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        for(int i=0; i<tamanhoArquivo; i++){
        printf("\nNome %d: %s\n", i+1, jogadores[i].nome);
       
        printf("Nascimento: %d/%d/%d\n", jogadores[i].data.dia, jogadores[i].data.mes, jogadores[i].data.ano);


        printf("CPF %d: %s \n", i+1, jogadores[i].cpf);

        if(jogadores[i].genero == 0){
            printf("Gênero %d: Masculino \n", i+1);
        }
        else{
            printf("Gênero %d: Feminino \n", i+1);
        }
        
        if(jogadores[i].civil == 0){
            printf("Estado Civil %d: Casado \n", i+1);
        }
        if(jogadores[i].civil == 1){
            printf("Estado Civil %d: Solteiro \n", i+1);
        }
        if(jogadores[i].civil == 2){
            printf("Estado Civil %d: Divorciado \n", i+1);
        }
        if(jogadores[i].civil == 3){
            printf("Estado Civil %d: Viuvo \n", i+1);
        }
        
        printf("Nome Equipe %d: %s \n", i+1, jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social %d: %s \n", i+1, jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social %d: %d \n", i+1, jogadores[i].time.seguidores_equipe);

        printf("Patrocinadora Principal %d: %s \n", i+1, jogadores[i].patrocinadora);

        printf("Rede Social %d: %s \n", i+1, jogadores[i].redesocial_jogador.nickname_jogador);

        printf("Seguidores %d: %d \n", i+1, jogadores[i].redesocial_jogador.seguidores_jogador);

        if(jogadores[i].hardware.computer==0){
            printf("Computador %d: Desktop \n", i+1);
        }
        else{
            printf("Computador %d: Laptop \n", i+1);
        }
        printf("CPU %d: %s \n", i+1, jogadores[i].hardware.cpu);
        printf("GPU %d: %s \n", i+1, jogadores[i].hardware.gpu);
        printf("RAM %d: %d \n", i+1, jogadores[i].hardware.ram);

        printf("Vitorias %d: %d \n", i+1, jogadores[i].campeonato.victories);
        printf("Empates %d: %d \n", i+1, jogadores[i].campeonato.draws);
        printf("Derrotas %d: %d \n", i+1, jogadores[i].campeonato.losses);
        printf("Pontos %d: %d \n", i+1, jogadores[i].campeonato.points);

        printf("Titulos %d: %d \n", i+1, jogadores[i].titulos.titles);

        printf("Rank %d: %d \n", i+1, jogadores[i].ranking.rank);
        PularLinha(2);
        }

    }
    
    else{
        printf("Arquivo nao aberto!\n\n");
    }
    fclose(file);
    return;
}

//Função alterar nome jogador//
void AlterarNomeJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            printf("Nome jogador: ");
            fflush(stdin);
            gets(jogadores[a-1].nome);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }

    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarDataJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            printf("Dia nascimento: ");
            scanf("%d", &jogadores[a-1].data.dia);
            printf("Mes nascimento: ");
            scanf("%d", &jogadores[a-1].data.mes);
            printf("Ano nascimento: ");
            scanf("%d", &jogadores[a-1].data.ano);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }

    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarCPFJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            fflush(stdin);
            printf("CPF: ");
            gets(jogadores[a-1].cpf);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
            
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarGeneroJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            do{
                printf("Genero (Masculino=0/Feminino=1): ");
                scanf("%u", &jogadores[a-1].genero);
            }while(jogadores[a-1].genero!=0 && jogadores[a-1].genero!=1);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarCivilJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            do{
                printf("Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3):");
                scanf("%u", &jogadores[a-1].civil);
            }while(jogadores[a-1].civil!=0 && jogadores[a-1].civil!=1 && jogadores[a-1].civil!=2 && jogadores[a-1].civil!=3);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarEquipeJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            printf("Nome Equipe: ");
            fflush(stdin);
            gets(jogadores[a-1].time.nome_equipe);
            printf("Nickname equipe rede social: ");
            fflush(stdin);
            gets(jogadores[a-1].time.nickname_equipe);
            printf("Seguidores rede social equipe: ");
            scanf("%d", &jogadores[a-1].time.seguidores_equipe);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarPatrocinadoraJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            printf("Patrocinadora principal: ");
            fflush(stdin);
            gets(jogadores[a-1].patrocinadora);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarRedeSocialJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            //Rede Social//
            printf("Rede social: ");
            fflush(stdin);
            gets(jogadores[a-1].redesocial_jogador.nickname_jogador);

            //Seguidores Rede Social//
            printf("Seguidores rede social: ");
            scanf("%d", &jogadores[a-1].redesocial_jogador.seguidores_jogador);
            PularLinha(2);
        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarHardwareJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            do{
                printf("Desktop(0) ou Notebook(1)? ");
                scanf("%u", &jogadores[a-1].hardware.computer);
            } while(jogadores[a-1].hardware.computer!=0 && jogadores[a-1].hardware.computer!=1);
            
            printf("CPU: ");
            fflush(stdin);
            gets(jogadores[a-1].hardware.cpu);
            printf("GPU: ");
            fflush(stdin);
            gets(jogadores[a-1].hardware.gpu);
            printf("Quantidade RAM: ");
            scanf("%d", &jogadores[a-1].hardware.ram);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

void AlterarCampeonatoJogadorArquivoBinario(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

            PularLinha(2);
            printf("Titulos: ");
            scanf("%d", &jogadores[a-1].titulos.titles);
            printf("Ranking: ");
            scanf("%d", &jogadores[a-1].ranking.rank);
            PularLinha(2);

        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função atualizar pontuação jogador//

void InserirVitoriaEmpateDerrota(int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb+");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        //Atualizar Vitorias, empates, derrotas//
        PularLinha(2);
        printf("Digite vitorias: ");
        scanf("%d", &jogadores[a-1].campeonato.victories);
        printf("Digite empates: ");
        scanf("%d", &jogadores[a-1].campeonato.draws);
        printf("Digite derrotas: ");
        scanf("%d", &jogadores[a-1].campeonato.losses);
        PularLinha(2);
        fseek(file, 0, SEEK_SET);
        fwrite(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
        fclose(file);
    }
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}


//Função buscar jogador por nome//

void BuscarJogadorNome(string100 chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(strcmp(jogadores[i].nome, chave)!=0){
            if(i == tamanhoArquivo){
                i++;
                PularLinha(2);
                printf("Jogador não encontrado!Tente novamente!");
                PularLinha(2);
                break;
            }
            i++;
        }

        if(i <= tamanhoArquivo){

            //Nascimento//

            printf("Nascimento: %d/%d/%d\n", jogadores[i].data.dia, jogadores[i].data.mes, jogadores[i].data.ano);

            //CPF//
            printf("CPF: %s\n", jogadores[i].cpf);

            //Gênero//
            if(jogadores[i].genero == 0){
                printf("Gênero: Masculino\n");
            }
            else{
                printf("Gênero: Feminino\n");
            }
            
            //Estado Civil//
            printf("Estado Civil: %d\n", jogadores[i].civil);

            //Equipe//
            printf("Nome Equipe: %s\n", jogadores[i].time.nome_equipe);
            printf("Nickname Equipe Rede Social: %s\n", jogadores[i].time.nickname_equipe);               
            printf("Seguidores Equipe Rede Social: %d\n", jogadores[i].time.seguidores_equipe);

            //Patrociadora Principal//
            printf("Patrocinadora Principal: %s\n", jogadores[i].patrocinadora);

            //Rede Social//
            printf("Rede Social: %s\n", jogadores[i].redesocial_jogador.nickname_jogador);

            //Seguidors Rede Social//
            printf("Seguidores: %d\n", jogadores[i].redesocial_jogador.seguidores_jogador);

            //Equipmento de Hardware//
            if(jogadores[i].hardware.computer==0){
                printf("Computador: Desktop\n");
            }
            else{
                printf("Computador: Laptop\n");
            }
            printf("CPU: %s\n", jogadores[i].hardware.cpu);
            printf("GPU: %s\n", jogadores[i].hardware.gpu);
            printf("RAM: %d\n", jogadores[i].hardware.ram);

            //Dados Campeonato//
            printf("Vitorias: %d\n", jogadores[i].campeonato.victories);
            printf("Empates: %d\n", jogadores[i].campeonato.draws);
            printf("Derrotas: %d\n", jogadores[i].campeonato.losses);
            printf("Pontos: %d\n", jogadores[i].campeonato.points);

            //Títulos mundiais//
            printf("Titulos: %d\n", jogadores[i].titulos.titles);

            //Ranking//
            printf("Rank: %d\n", jogadores[i].ranking.rank);
            PularLinha(2);
    }
    }
    fclose(file);
    return;
}

//Função buscar jogador por rank//

void BuscarJogadorRank(int chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(jogadores[i].ranking.rank != chave){
            i++;
            if(i > tamanhoArquivo){
                i++;
                PularLinha(2);
                printf("Rank não encontrado! Tente novamente!\n\n");
                break;
            }
        }
        
        if(i <= tamanhoArquivo){

            //Nome//
            printf("\nNome: %s\n", jogadores[i].nome);

            //Nascimento//
            printf("Nascimento: %d/%d/%d\n", jogadores[i].data.dia, jogadores[i].data.mes, jogadores[i].data.ano);

            //CPF//
            printf("CPF: %s\n", jogadores[i].cpf);

            //Gênero//
            if(jogadores[i].genero == 0){
                printf("Gênero: Masculino\n");
            }
            else{
                printf("Gênero: Feminino\n");
            }
            
            //Estado Civil//
            printf("Estado Civil: %d\n", jogadores[i].civil);

            //Equipe//
            printf("Nome Equipe: %s\n", jogadores[i].time.nome_equipe);
            printf("Nickname Equipe Rede Social: %s\n", jogadores[i].time.nickname_equipe);               
            printf("Seguidores Equipe Rede Social: %d\n", jogadores[i].time.seguidores_equipe);

            //Patrociadora Principal//
            printf("Patrocinadora Principal: %s\n", jogadores[i].patrocinadora);

            //Rede Social//
            printf("Rede Social: %s\n", jogadores[i].redesocial_jogador.nickname_jogador);

            //Seguidors Rede Social//
            printf("Seguidores: %d\n", jogadores[i].redesocial_jogador.seguidores_jogador);

            //Equipmento de Hardware//
            if(jogadores[i].hardware.computer==0){
                printf("Computador: Desktop\n");
            }
            else{
                printf("Computador: Laptop\n");
            }
            printf("CPU: %s\n", jogadores[i].hardware.cpu);
            printf("GPU: %s\n", jogadores[i].hardware.gpu);
            printf("RAM: %d\n", jogadores[i].hardware.ram);

            //Dados Campeonato//
            printf("Vitorias: %d\n", jogadores[i].campeonato.victories);
            printf("Empates: %d\n", jogadores[i].campeonato.draws);
            printf("Derrotas: %d\n", jogadores[i].campeonato.losses);
            printf("Pontos: %d\n", jogadores[i].campeonato.points);

            //Títulos mundiais//
            printf("Titulos: %d\n", jogadores[i].titulos.titles);
            PularLinha(2);
        }
    }
    fclose(file);
    return;
}

//Função mostrar média seguidores jogadores//

void MostrarMediaSeguidoresJogadores(){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR jogadores[tamanhoArquivo];
    fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

    unsigned soma=0;

    for(int i=0; i< tamanhoArquivo; i++){
        soma = soma+(float)jogadores[i].redesocial_jogador.seguidores_jogador;
    }
    unsigned media = soma/(float)tamanhoArquivo;
    printf("\n\nMedia: %.2u\n\n", media);
    fclose(file);
    return;
}


//ordena os nomes dos jogadores por ordem alfabÃ©tica
void OrdenarJogadores_alfabeto(){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR auxiliares[tamanhoarquivo];
    fread(auxiliares, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);

    int conferidor, i, j;
    JOGADOR aux;
    for(j = 0; j < tamanhoarquivo; j++){
        for(i = 0; i < tamanhoarquivo - 1; i++){
            conferidor = strcasecmp(auxiliares[i].nome , auxiliares[i+1].nome);
            if(conferidor > 0){
                aux = auxiliares[i];
                auxiliares[i] = auxiliares[i+1];
                auxiliares[i+1] = aux;
            }
        }
    }

    printf("\n\nLista ordenada dos nomes dos jogadores:\n\n");

    for(i = 0; i < tamanhoarquivo; i++){
        printf("%s\n", auxiliares[i].nome);
    }

    PularLinha(2);

}




//Ordena os posiÃ§Ãµes dos jogadores em ordem crescente
void OrdenarJogadores_posicao(){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR auxiliar[tamanhoarquivo];
    fread(auxiliar, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);
    
    JOGADOR aux;
    int i, j;

    for(j = 0; j < tamanhoarquivo; j++){
        for(i = 0; i < tamanhoarquivo - 1; i++){
            if(auxiliar[i].ranking.rank > auxiliar[i+1].ranking.rank){
                aux = auxiliar[i]; 
                auxiliar[i] = auxiliar[i+1];
                auxiliar[i+1] = aux;
            }
        }
    }
    

    printf("\n\nLista ordenada das posições dos jogadores:\n");

    for(i = 0; i < tamanhoarquivo; i++){
        printf("%s, %dª posição!\n", auxiliar[i].nome, auxiliar[i].ranking.rank);
    }

    PularLinha(2);

}

//Ordena os jogadores em ordem crescente por nÃºmero de VitÃ³rias
void OrdenarJogadores_vitoria (){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR jogadores[tamanhoarquivo];
    fread(jogadores, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);
    
    int i, j;
    JOGADOR aux;

    
    for(j = 0; j < tamanhoarquivo; j++){
        for(i = 0; i < tamanhoarquivo - 1; i++){
            if(jogadores[i].campeonato.victories < jogadores[i+1].campeonato.victories){
                aux = jogadores[i];
                jogadores[i] = jogadores[i+1];
                jogadores[i+1] = aux;
            }
        }
    }

    printf("\n\nLista ordenada das posição dos jogadores:\n");

    for(i = 0; i < tamanhoarquivo; i++){
        printf("%s, %d vitórias!\n", jogadores[i].nome, jogadores[i].campeonato.victories);
    }

    PularLinha(2);

}

//Mostrar (listar) classifição do campeonato com nome, posição no campeonato, pontuação, quantidade de vitorias, derrotas e empates.
void ListarJogadores_posicaoCampeonato (){

    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR auxiliar[tamanhoarquivo];
    fread(auxiliar, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);

    printf("\n\nClassificação do campeonato de acordo com a posição: \n");
    for(int i = 0; i < tamanhoarquivo; i++){
        printf("Nome: %s; %dª posição; Pontuação: %d; Vitórias: %d; Derrotas: %d; Empates: %d\n", auxiliar[i].nome, auxiliar[i].ranking.rank, auxiliar[i].campeonato.points, auxiliar[i].campeonato.victories, auxiliar[i].campeonato.losses, auxiliar[i].campeonato.draws);
    }
    PularLinha(2);
}

//Lista jogadores com pontuação menor que um determinado numero
void ListarJogadores_PontuacaoMenor ( int limite){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR auxiliar[tamanhoarquivo];
    fread(auxiliar, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);

    int i;

    printf("\n\nJogadores com pontuação menor que %d:\n", limite);
    for(i = 0; i < tamanhoarquivo; i++){
        if(auxiliar[i].campeonato.points < limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }

    PularLinha(2);
    
}

void ListarJogadores_PontuacaoMaior ( int limite){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoarquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR auxiliar[tamanhoarquivo];
    fread(auxiliar, sizeof(JOGADOR), tamanhoarquivo, file);
    fclose(file);

    int i;
    printf("\n\nJogadores com pontuação maior que %d:\n", limite);
    for(i = 0; i < tamanhoarquivo; i++){
        if(auxiliar[i].campeonato.points > limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }

    PularLinha(2);
    
}








