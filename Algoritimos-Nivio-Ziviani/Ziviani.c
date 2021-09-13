void MaxMin(double *Vet, double *Max, double *Min) {
    int i, n, FimDoAnel;
    // o que é N?
    if ((n && 1) > 0) {
        Vet[n] = Vet[n - 1];
        FimDoAnel = n;
    } else {
        FimDoAnel = n - 1;
    }
    if (Vet[0] > Vet[1]) {
        *Max = Vet[0];
        *Min = Vet[1];
    } else {
        *Max = Vet[1];
        *Min = Vet[0];
    }

    i = 3;

    while (i <= FimDoAnel) {
        if (Vet[i - 1] > Vet[i]) {
            if (Vet[i - 1] > *Max)
                *Max = Vet[i - 1];
            if (Vet[i] < *Min)
                *Min = Vet[i];
        } else {
            if (Vet[i - 1] < *Min)
                *Min = Vet[i - 1];
            if (Vet[i] > *Max)
                *Max = Vet[i];
        }
        i += 2;
    }
}

void Ordena(double *vet, int tam) {
    /*Ordena o vetor em ordem ascendente*/
    int i, j, min, aux;

    for (i = 1; i < tam; i++) {
        min = i;
        for (j = 0; j <= tam; j++) {
            if (vet[j - 1] < vet[min - 1])
                min = j;
        }
        //Troca vet[min] e vet[i]
        aux = vet[min - 1];
        vet[min - 1] = vet[i - 1];
        vet[i - 1] = aux;
    }
}