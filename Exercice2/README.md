# SCC0502 Algoritmos e Estruturas de Dados 1

## Exercício 2 - Catálogo de jogos eletrônicos

### Objetivo

O objetivo deste primeiro exercício prático é reforçar tópicos que já foram vistos em disciplinas anteriores e que serão essenciais para os próximos trabalhos e atividades. Além de reforçar o bom uso de TADs simples, que também serão essenciais para a continuidade da disciplina.

Queremos que os alunos se acostumem com o uso de múltiplos arquivos .c e .h em um projeto, bem como a construção de um arquivo **Makefile**, responsável por gerenciar a execução do programa.

### Descrição

Um site de jogos eletrônicos perdeu o seu catálogo e quer refazê-lo. Você foi contratado para resolver esse problema e deve criar um programa que gerencie os jogos desse site. Isto é, permita o armazenamento e acesso às informações dos produtos e seus dados conforme o pedido do usuário.

Espera-se que seu programa seja capaz atender aos seguintes requisitos:

1. Armazenar as informações de um jogo: *Nome*, *Empresa produtora*, *Ano de lançamento*
2. Buscar pelos jogos lançados em um determinado ano.
3. Buscar pelos jogos criados por uma determinada produtora.

### Entrada

Seu algoritmo deve receber os atributos associados aos jogos um por linha, na ordem:

* Nome
* Produtora
* Ano

Até ler a letra *"F"* (Maiúscula).

Após a primeira letra *"F"*, seu código deve esperar por um próximo carácter

* *"A"* correspondendo à opção de busca por ano
* *"E"* - correspondendo à opção de busca por empresa produtora

Deve continuar realizando as operações requisitadas até ler novamente a letra *"F"*, marcando o fim do algoritmo.

Exemplo de entrada:

```
Horizon Zero Dawn
Guerrilla Games
2017
Killzone
Guerrilla Games
2004
Crash Bandicoot
Naughty Dog
1999
F
A
2004
A
2000
E
Guerrilla Games
F
```

### Saída

Como saída, seu programa deve retornar a listagem dos nomes dos jogos pesquisados de acordo como o parâmetro determinado. Caso não haja jogos registrados que satisfaçam o critério, seu programa deve responder com *"Nada encontrado"*.

Saída da caso acima:
```
Killzone
Nada encontrado
Horizon Zero Dawn
Killzone
```

### Observações da implementação

Como é descrito na sessão objetivos desse documento, não queremos apenas que os alunos resolvam o problema, mas que utilizem métodos que serão comuns no decorrer da disciplina.

Devido a esse objetivo, será exigido que vocês desenvolvam seu projeto representando o objeto *jogo* e o objeto *catálogo* de forma abstrata, isto é, com uma *struct* para cada. A memória deve ser alocada dinamicamente e ser devidamente liberada ao fim da execução.

Utilizar múltiplos arquivos *.c* e *.h* para separar a implementação e a responsabilidade dos métodos de cada objeto (*jogo.c* e *catalogo.c*).

Construir funções para realizar operações repetitivas, ou seja, modularizar adequadamente seu código.

Escrever um arquivo **Makefile** que será responsável por gerenciar a execução do projeto dentro da plataforma run.codes.

### Observações da avaliação

A avaliação do seu programa será feita além do resultado da plataforma *run.codes*. Portanto, ter um bom resultado com os casos de teste, não será suficiente para garantir a **nota máxima** e nem a **aprovação do exercício**.

Caso seu projeto não satisfaça os pontos exigidos nos **objetivos** e explicitados nas **observações de implementação**, sua nota poderá ser reduzida ou ser desconsiderada.

Cópias de código entre alunos, acusadas pela plataforma, resultarão imediatamente em **zero** aos dois ou mais alunos envolvidos.