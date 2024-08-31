#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

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
        i++;
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

void decimalParaComplemento2(int numero) {
    int complemento2[16];
    int i;

    if (numero < -32768 || numero > 32767) {
        printf("Erro: O número %d está fora do intervalo de 16 bits com sinal.\n", numero);
        return;
    }

    if (numero < 0) {
        printf("O número é negativo. Primeiro, convertendo para positivo:\n");
        numero = -numero;
    }

    for (i = 0; i < 16; i++) {
        complemento2[i] = numero % 2;
        numero = numero / 2;
    }

    if (complemento2[15] == 1) {
        printf("Aplicando complemento a 2:\n");

        for (i = 0; i < 16; i++) {
            complemento2[i] = complemento2[i] == 1 ? 0 : 1;
        }

        for (i = 0; i < 16; i++) {
            if (complemento2[i] == 0) {
                complemento2[i] = 1;
                break;
            } else {
                complemento2[i] = 0;
            }
        }
    }

    printf("Complemento a 2 (16 bits): ");
    for (i = 15; i >= 0; i--) {
        printf("%d", complemento2[i]);
    }
    printf("\n");
}

void converterParaBinarioFracao(double num, char *binario, int precisao) {
    int i;
    double frac = num - (int)num;

    for (i = 0; i < precisao && frac != 0.0; i++) {
        frac *= 2;
        if (frac >= 1.0) {
            binario[i] = '1';
            frac -= 1.0;
        } else {
            binario[i] = '0';
        }
    }
    binario[i] = '\0';
}

void converterParaFloat(float numero) {
    union {
        float f;
        unsigned int i;
    } u;

    u.f = numero;

    unsigned int sinal = (u.i >> 31) & 0x1;
    unsigned int expoente = (u.i >> 23) & 0xFF;
    unsigned int fração = u.i & 0x7FFFFF;

    int expoenteComViés = expoente - 127;

    printf("Conversão para Float (32 bits):\n");
    printf("Sinal: %u\n", sinal);
    printf("Expoente: %u (em binário: ", expoente);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf(")\n");
    printf("Expoente com viés: %d\n", expoenteComViés);
    printf("Fração: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (fração >> i) & 1);
    }
    printf("\n\n");
}

void converterParaDouble(double numero) {
    union {
        double d;
        unsigned long long i;
    } u;

    u.d = numero;

    unsigned long long sinal = (u.i >> 63) & 0x1;
    unsigned long long expoente = (u.i >> 52) & 0x7FF;
    unsigned long long fração = u.i & 0xFFFFFFFFFFFFF;

    int expoenteComViés = expoente - 1023;

    printf("Conversão para Double (64 bits):\n");
    printf("Sinal: %llu\n", sinal);
    printf("Expoente: %llu (em binário: ", expoente);
    for (int i = 10; i >= 0; i--) {
        printf("%llu", (expoente >> i) & 1);
    }
    printf(")\n");
    printf("Expoente com viés: %d\n", expoenteComViés);
    printf("Fração: ");
    for (int i = 51; i >= 0; i--) {
        printf("%llu", (fração >> i) & 1);
    }
    printf("\n\n");
}

int main() {
    int numero;
    float numeroFloat;
    double numeroDouble;

    printf("Digite um número em base 10: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);
    decimalParaOctal(numero);
    decimalParaHexadecimal(numero);
    decimalParaBCD(numero);
    decimalParaComplemento2(numero);

    printf("Digite um número real: ");
    scanf("%lf", &numeroDouble);

    numeroFloat = (float)numeroDouble;

    converterParaFloat(numeroFloat);
    converterParaDouble(numeroDouble);

    return 0;
}
