#include <stdio.h>


void decimalParaBinario(int numero) {
    int binario[32]; 
    int i = 0;

    
    printf("Passo 1 (Base 2): Dividir %d por 2 até o quociente ser 0 e armazenar os restos:\n", numero);

    while (numero > 0) {
        binario[i] = numero % 2;
        printf("%d %% 2 = %d (resto)\n", numero, binario[i]);
        numero = numero / 2;
        printf("%d / 2 = %d (novo número)\n", numero * 2 + binario[i], numero); 
        i++;
    }

    
    printf("Passo 2 (Base 2): Inverter a ordem dos restos:\n");
    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}


void decimalParaOctal(int numero) {
    int octal[32]; 
    int i = 0;

    
    printf("Passo 1 (Base 8): Dividir %d por 8 até o quociente ser 0 e armazenar os restos:\n", numero);

    while (numero > 0) {
        octal[i] = numero % 8;
        printf("%d %% 8 = %d (resto)\n", numero, octal[i]);
        numero = numero / 8;
        printf("%d / 8 = %d (novo número)\n", numero * 8 + octal[i], numero); 
    }

    
    printf("Passo 2 (Base 8): Inverter a ordem dos restos:\n");
    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}


void decimalParaHexadecimal(int numero) {
    char hexadecimal[32]; 
    int i = 0;

    
    printf("Passo 1 (Base 16): Dividir %d por 16 até o quociente ser 0 e armazenar os restos:\n", numero);

    while (numero > 0) {
        int resto = numero % 16;

        
        if (resto < 10) {
            hexadecimal[i] = 48 + resto; 
        } else {
            hexadecimal[i] = 55 + resto; 
        }

        printf("%d %% 16 = %c (resto)\n", numero, hexadecimal[i]);
        numero = numero / 16;
        printf("%d / 16 = %d (novo número)\n", numero * 16 + resto, numero); 
        i++;
    }

    
    printf("Passo 2 (Base 16): Inverter a ordem dos restos:\n");
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}


void decimalParaBCD(int numero) {
    int digito;
    int bcd[4]; 

    printf("Passo 1 (BCD): Converter cada dígito decimal em seu equivalente binário:\n");

    printf("BCD: ");
    while (numero > 0) {
        digito = numero % 10; 

       
        for (int i = 3; i >= 0; i--) {
            bcd[i] = digito % 2;
            digito = digito / 2;
        }

       
        for (int i = 0; i < 4; i++) {
            printf("%d", bcd[i]);
        }
        printf(" "); 

        numero = numero / 10; 
    }
    printf("\n");
}

int main() {
    int numero;

    printf("Digite um número em base 10: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);
    decimalParaOctal(numero);
    decimalParaHexadecimal(numero);
    decimalParaBCD(numero);

    return 0;
}
