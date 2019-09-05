#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

#define QUANTUM 2

using namespace std;

typedef enum Estado { NOVO, PRONTO, EXECUTANDO, TERMINADO } ESTADO;

typedef struct Tarefa{
    int tempo_ingresso;
    int tempo_duracao;

    int prioridade_estatica;
    int prioridade_dinamica;

    int tempo_executado;
    int tempo_restante;

    ESTADO estado_atual;
} TAREFA;

int nTarefas;
TAREFA vTarefas[100];

TAREFA* TAREFA_ATUAL;

int texec, tvida, tespera, trocasDeContexto;
double tempos[2] = {0, 0}; //tempos[0]-> tempo medio de execucao; tempos[1] = tempo medio de espera;

void scanInput();
void reseta();

void FirstComeFirstServed(TAREFA *v);
void RoundRobin(TAREFA * v);
void ShortestJobFirst(TAREFA *v);
void ShortestRemainingTimeFirst(TAREFA *v);
void PRIOc(TAREFA *v);
void PRIOp(TAREFA *v);
void PRIOd(TAREFA *v);

int main(int argc, char **argv){

    scanInput();

    FirstComeFirstServed(vTarefas);
    
    RoundRobin(vTarefas);
    ShortestJobFirst(vTarefas);
    ShortestRemainingTimeFirst(vTarefas);
    PRIOc(vTarefas);
    PRIOp(vTarefas);
    PRIOd(vTarefas);
    
    return 0;
}

void reseta(){
    trocasDeContexto = 0;
    texec = 0;
    tespera = 0;
    tempos[1] = 0;
    tempos[2] = 0;
}

void scanInput(){
    scanf("%d", &nTarefas);

    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].tempo_ingresso);
    }
    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].tempo_duracao);
    }
    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].prioridade_estatica);
    }
    // for (int i = 0; i < nTarefas; i++)
    // {
    //     printf("t%d: %d| %d| %d\n", i+1, vTarefas[i].tempo_ingresso, vTarefas[i].tempo_duracao, vTarefas[i].prioridade);
    // }
}

void FirstComeFirstServed(TAREFA *v){
    reseta();

    for (int i = 0; i < nTarefas; i++){
        texec = texec + v[i].tempo_duracao - v[i].tempo_ingresso;
        trocasDeContexto++;
    }
    for (int i = 1; i < nTarefas; i++){
        tespera = tespera + v[i-1].tempo_duracao - v[i].tempo_duracao;
    }
    texec = texec / nTarefas;
    tespera = tespera / nTarefas;
    tempos[1] = texec;
    tempos[2] = tespera;

    cout << "--FCFS--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;
}

void RoundRobin(TAREFA *v){
    reseta();

    queue<TAREFA> filaDeTarefas;

    for (int i = 0; i < nTarefas; i++){
        filaDeTarefas.push(vTarefas[i]);
    }

    cout << "--RR--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;
}
//ToDo
void ShortestJobFirst(TAREFA *v){
    reseta();

    cout << "--SJF--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;
}
//ToDo
void ShortestRemainingTimeFirst(TAREFA *v){
    reseta();   

    cout << "--SRTF--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl; 
}
//ToDo
void PRIOc(TAREFA *v){
    reseta();    

    cout << "--PRIOc--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;
}
//ToDo
void PRIOp(TAREFA *v){
    reseta();

    cout << "--PRIOp--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;    
}
//ToDo
void PRIOd(TAREFA *v){
    reseta(); 

    cout << "--PRIOd--" << endl;
    cout << "Tt = " << tempos[1] << endl;
    cout << "Tw = " << tempos[2] << endl;
    cout << "Trocas de contexto = " << trocasDeContexto << endl;  
}