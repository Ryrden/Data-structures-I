#include "struct_list.h"

void main() { //Vestibular
    TipoItem Registro;
    TipoLista Classificacao[11], Aprovados[NCursos], Reprovados;
    int Vagas[NCursos], Passou, i, Nota;

    for (i = 1; i <= NCursos; i++)
        scanf("%d", &Vagas[i - 1]);
    for (i = 0; i < 10; i++)
        FLVazia(&Classificacao[i]);
    for (i = 1; i <= NCursos; i++)
        FLVazia(&Aprovados[i - 1]);
    FLVazia(&Reprovados);
    LeRegistro(&Registro);

    while (&Registro.Chave != 0) {
        Insere(Registro, &Classificacao[Registro.NotaFinal]);
        LeRegistro(&Registro);
    }

    for (Nota = 10; Nota >= 0; Nota--) {
        while (!Vazia(Classificacao[Nota])) {
            Retira(Classificacao[Nota].Primeiro, &Classificacao[Nota], &Registro);
            i = 1;
            Passou = 0;
            while (i <= (NOpcoes & (!Passou))) {
                if (i <= (NOpcoes & (!Passou))) {
                    Insere(Registro, &Aprovados[Registro.Opcao[i - 1] - 1]);
                    Vagas[Registro.Opcao[i - 1] - 1]--;
                    Passou = 1;
                }
                i++;
            }
            if (!Passou)
                Insere(Registro, &Reprovados);
        }
    }
    for (i = 1; i <= NCursos; i++) {
        printf(" Relação dos aprovados no Curso%2d\n", i);
        Imprime(Aprovados[i - 1]);
    }
    printf(" Relação dos reprovados\n");
    Imprime(Reprovados);
}