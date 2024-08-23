#include <stdio.h>
#include <locale.h>
#include <conio.h>

struct Aluno
{
    char Nome[30];
    int Idade;
    float Notas[3];
    char Sexo;
};


void adicionaSexo(struct Aluno aluno, int nAluno){
        aluno.Sexo = ' ';
        bool sexoValido = false;
        do
        {
            if (aluno.Sexo != ' ' && !sexoValido)
            {
                printf("\nValor inválido. Por favor, informe 'M' ou 'F'.\n");
            }
            printf("\nInforme o Sexo do %i° aluno: (F/M)", nAluno);
            scanf("%s", &aluno.Sexo);
            sexoValido = aluno.Sexo == 'M' || aluno.Sexo == 'F';
        } while (!sexoValido || aluno.Sexo == ' ');

}

void adicionarNotas(struct Aluno aluno, int nAluno){
    int qtdNotas = 1;
    do
    {
        printf("\nInforme a %i° nota do %i aluno", qtdNotas, nAluno);
        scanf("%f", aluno.Notas[qtdNotas-1]);
    } while (qtdNotas <= 3);
    
}
// TODO: 

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Estrutura de Dados
    struct Aluno vetorAluno[100];
    float Valor[1000], Maior, Menor;
    int Resposta, Qtd, Soma, nAluno = 0;

    do
    {
        nAluno = Qtd + 1;
        // Entrada de dados
        printf("\nInforme o nome do %i° aluno: (Até 30 caracteres): ", nAluno);
        scanf("%s", &vetorAluno[Qtd].Nome);

        printf("\nInforme a idade do %i° aluno: ", nAluno);
        scanf("%d", &vetorAluno[Qtd].Idade);

        adicionaSexo(vetorAluno[Qtd], nAluno);
        
        adicionarNotas(vetorAluno[Qtd], nAluno);

        Soma = Soma + vetorAluno[Qtd].Idade;
        // Processamento
        if (Qtd == 0)
        {
            Maior = vetorAluno[0].Idade;
            Menor = vetorAluno[Qtd].Idade;
        }
        else
        {
            if (vetorAluno[Qtd].Idade > Maior)
            {
                Maior = vetorAluno[Qtd].Idade;
            }
            else if (vetorAluno[Qtd].Idade < Menor)
            {
                Menor = vetorAluno[Qtd].Idade;
            }
        }
        printf("\nDeseja informar a proxima idade?\n 1/Sim-2Nao\n");
        scanf("%d", &Resposta);
        Qtd++;
        getchar();
    } while (Resposta == 1);
    // Saída de dados
    printf("\nO maior valor: %0.2f", Maior);
    printf("\nO menor valor: %0.2f", Menor);
    printf("\nA soma dos %i valores: %d\n", Qtd, Soma);
    // Calculo da média
    int media = Soma / Qtd;
    printf("\nA média dos %i valores: %0.2f\n", Qtd, media);

    // Ordenar valores
    for (int i = 0; i < Qtd - 1; i++)
    {
        for (int j = i + 1; j < Qtd; j++)
        {
            if (vetorAluno[i].Idade > vetorAluno[j].Idade)
            {
                Aluno temp = vetorAluno[i];
                vetorAluno[i] = vetorAluno[j];
                vetorAluno[j] = temp;
            }
        }
    }

    // Calculando a moda (valor mais frequente)
    int Moda = 0, Contador = 0;
    for (int i = 0; i < Qtd; i++)
    {
        int ContadorAtual = 0;
        for (int j = 0; j < Qtd; j++)
        {
            if (vetorAluno[i].Idade == vetorAluno[j].Idade)
            {
                ContadorAtual++;
            }
        }
        if (ContadorAtual > Contador)
        {
            Contador = ContadorAtual;
            Moda = vetorAluno[i].Idade;
        }
    }
    // Saída de dados - Moda
    printf("\nA moda dos valores: %d", Moda);

    // Calculando a mediana (valor central)
    float mediana = 0;
    if (Qtd % 2 == 0)
    {
        mediana = (vetorAluno[Qtd / 2 - 1].Idade + vetorAluno[Qtd / 2].Idade) / 2.0;
    }
    else
    {
        mediana = vetorAluno[Qtd / 2].Idade;
    }

    // Saída de dados - Mediana
    printf("\nA mediana dos valores: %0.2f\n", mediana);
    
}