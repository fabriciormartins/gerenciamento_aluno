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
        Qtd++;
        printf("Informe a %i° idade: ", Qtd);
        scanf("%f", &Valor[Qtd]);
        Soma = Soma + Valor[Qtd];

        // Processamento
        if (Qtd == 1)
        {
            Maior = Valor[1];
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
    } while (Resposta == 1);
    // Saída de dados
    printf("\nO maior valor: %0.2f", Maior);
    printf("\nO menor valor: %0.2f", Menor);
    printf("\nA soma dos %i valores: %d\n", Qtd, Soma);
    int media = Soma / Qtd;
    printf("\nA média dos %i valores: %0.2f\n", Qtd, media);

}