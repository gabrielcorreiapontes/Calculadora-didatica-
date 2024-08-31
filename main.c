#include <stdio.h>

void decimalParaBinario(int numero) {
    int binario[32]; 
    int i = 0;

  
    printf("Passo 1: Dividir %d por 2 até o quociente ser 0 e armazenar os restos:\n", numero);

    while (numero > 0) {
        binario[i] = numero % 2;
        printf("%d %% 2 = %d (resto)\n", numero, binario[i]);
        numero = numero / 2;
        printf("%d / 2 = %d (novo número)\n", numero * 2 + binario[i], numero); 
        i++;
    }

    
    printf("Passo 2: Inverter a ordem dos restos:\n");
    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int main() {
    int numero;

    printf("Digite um número em base 10: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);

    return 0;
}
