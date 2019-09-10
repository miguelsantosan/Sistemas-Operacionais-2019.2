#include<stdio.h>
#include <stdlib.h>

typedef struct Tarefa{
    int tIngresso;
    int tDuracao;
    int prioridade;
} Tarefa;

int texec, tvida, tespera;
double tmvida, tmespera;
double tempos[2] = {0, 0}; //tempos[0]-> tempo medio de execucao; tempos[1] = tempo medio de espera;

double * FirstComeFirstServed(int *v){
    
}

int main(int argc, char **argv){
    int nTarefas;
    Tarefa *vTarefas;

    scanf("%d", &nTarefas);
    vTarefas = malloc(nTarefas*sizeof(Tarefa));

    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].tIngresso);
    }
    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].tDuracao);
    }
    for (int i = 0; i < nTarefas; i++){
        scanf("%d", &vTarefas[i].prioridade);
    }
    for (int i = 0; i < nTarefas; i++)
    {
        printf("t%d: %d| %d| %d\n", i+1, vTarefas[i].tIngresso, vTarefas[i].tDuracao, vTarefas[i].prioridade);
    }
    printf("\n----\n");
    
    free(vTarefas);
    return 0;
}