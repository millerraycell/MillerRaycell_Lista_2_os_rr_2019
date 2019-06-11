#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_LENGHT 100

int main()
{
    int abrir_arquivo, escrever_arquivo, printar_lista, remover_lista, cont = 0;
    char tarefa[BUFFER_LENGHT];

    abrir_arquivo = open("/dev/ebbchar", O_RDWR);
    
    if(abrir_arquivo < 0)
    {
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 0;
    }
    char escolha[3];
    while(1)
    {
        printf("\tMODULO KERNEL PARA LISTA DE TAREFAS USANDO LIST.H\t");
        printf("OPÇÕES:\n");
        printf("1 - INSERIR ATIVIDADES NA LISTA\n");
        printf("2 - PRINTAR LISTA DE TAREFAS\n");
        printf("3 - REMOVER ATIVIDADE DA LISTA DE TAREFAS\n");
        printf("0 - SAIR\n");
        printf("DIGITE UMA OPÇÃO:\n");
        scanf(" %[^\n]s",escolha);

        switch (escolha[0])
        {
            case '1':
                printf("INSIRA O NUMERO DE ATIVIDADES QUE DESEJA INSERIR NA LISTA\n");
                scanf("%d",&numero_atividades);
                while(cont != numero_atividades)
                {
                    printf("INSIRA A DESCRIÇÃO DA ATIVIDADE %d:\n",cont++);
                    scanf(" %[^\n]s",tarefa);
                    escrever_arquivo = write(abrir_arquivo,tarefa,strlen(tarefa),1,0);
                    cont++;
                }
                cont = 0;
                break;

            case '2':
                printar_lista = write(abrir_arquivo,tarefa,strlen(tarefa),2,0);
                break;

            case '3':
                printar_lista = write(abrir_arquivo,tarefa,strlen(tarefa),2,0);
                int tarefa_removida;
                printf("INSIRA A ATIVIDADE QUE DESEJA REMOVER DA LISTA:\n");
                scanf("%d",&tarefa_removida);
                printar_lista = write(abrir_arquivo,tarefa,strlen(tarefa),3,tarefa_removida);
                break;

            case '0':
                return 0;

        default:
            printf("Opcao invalida, digite a opcao novamente:\n ");break;
            break;
        }
    }
}