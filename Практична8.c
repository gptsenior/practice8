#include <stdio.h>
#include <string.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%14s", word);

    int length = strlen(word);
    if (length > 14) {
        printf("Слово занадто довге. Максимальна довжина 14 символів.\n");
        return 1;
    }

    int count[256] = {0};
    for (int i = 0; i < length; i++) {
        count[(unsigned char)word[i]]++;
    }

    long long totalAnagrams = factorial(length);

    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) {
            totalAnagrams /= factorial(count[i]);
        }
    }

    printf("Кількість можливих анаграм: %lld\n", totalAnagrams);
    return 0;
}