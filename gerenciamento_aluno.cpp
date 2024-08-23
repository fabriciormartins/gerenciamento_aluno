#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Estrutura de Dados
    float Valor[1000], Maior, Menor;
    int Resposta, Qtd, Soma = 0;

    do
    {
        printf("Informe a %i° idade: ", Qtd+1);
        scanf("%f", &Valor[Qtd]);
        Soma = Soma + Valor[Qtd];
        // Processamento
        if (Qtd == 0)
        {
            Maior = Valor[0];
            Menor = Valor[Qtd];
        }
        else
        {
            if (Valor[Qtd] > Maior)
            {
                Maior = Valor[Qtd];
            }
            else if (Valor[Qtd] < Menor)
            {
                Menor = Valor[Qtd];
            }
        }
        printf("\nDeseja informar a proxima idade?\n 1/Sim-2Nao\n");
        scanf("%d", &Resposta);
        Qtd++;
    } while (Resposta == 1);
    // Saída de dados
    printf("\nO maior valor: %0.2f", Maior);
    printf("\nO menor valor: %0.2f", Menor);
    printf("\nA soma dos %i valores: %d\n", Qtd, Soma);
    // Calculo da média
    int media = Soma / Qtd;
    printf("\nA média dos %i valores: %0.2f\n", Qtd, media);

    //Ordenar valores 
    for (int i = 0; i < Qtd - 1; i++)
    {
        for (int j = i + 1; j < Qtd; j++)
        {
            if (Valor[i] > Valor[j])
            {
                float temp = Valor[i];
                Valor[i] = Valor[j];
                Valor[j] = temp;
            }
        }
    }

    //Calculando a moda (valor mais frequente)
    int Moda = 0, Contador = 0;
    for (int i = 0; i < Qtd; i++)
    {
        int ContadorAtual = 0;
        for (int j = 0; j < Qtd; j++)
        {
            if (Valor[i] == Valor[j])
            {
                ContadorAtual++;
            }
        }
        if (ContadorAtual > Contador)
        {
            Contador = ContadorAtual;
            Moda = Valor[i];
        }
    }
    // Saída de dados - Moda
    printf("\nA moda dos valores: %d", Moda);

    //Calculando a mediana (valor central)
    float mediana = 0;
    if (Qtd % 2 == 0)
    {
        mediana = (Valor[Qtd / 2 - 1] + Valor[Qtd / 2]) / 2.0;
    }
    else
    {
        mediana = Valor[Qtd / 2];
    }

    // Saída de dados - Mediana
    printf("\nA mediana dos valores: %0.2f\n", mediana);

}