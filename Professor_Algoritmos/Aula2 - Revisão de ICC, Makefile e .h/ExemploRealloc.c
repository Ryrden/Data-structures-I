

char *palavra = NULL;
int contador = 0;
do
{
    char* palavraBackup;
    palavraBackup = (char*) realloc(palavra, sizeof(char)*(contador+1));
    if(palavraBackup != NULL)
    {
        palavra = palavraBackup;
        scanf("%c", palavra[contador]);
        contador++;
    }
    else
    {
        imprimePalavra(palavra);
        exit(1);
    }
} while (palavra[contador-1]!='$');
