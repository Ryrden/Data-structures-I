# SCC0502 Algoritmos e Estruturas de Dados 1

## Exercício 5 - Conta bancária

### Objetivo
O objetivo deste exercício prático é estimular os estudantes a se familiarizarem com o comportamento e a lógica associados à estrutura de dados **árvore.**

Queremos que os alunos se habituem com a implementação dessa estrutura e consigam entender as funções básicas, que garantem a execução adequada desse *TAD*, em diferentes contextos.


Para acostumar os alunos com conceitos de modularização e boas práticas de escrita de código, será exigido o uso de múltiplos arquivos _.c_ e _.h_ no projeto, bem como a construção de um
arquivo **Makefile**, responsável por gerenciar a execução do programa.

### Descrição
Bancos são instituições conhecidas por possuírem uma extensa base de usuários, afinal ninguém mais guarda o dinheiro no colchão não é mesmo?

Para poder garantir a satisfação de seus clientes o banco não podem deixar as pessoas zangadas esperando na hora de realizarem transações. Antes de se realizar uma operação, é necessário primeiro identificar quem é a parte que está transferindo e a parte que está recebendo a quantia em questão.

Não se pode implementar qualquer algoritmo de para se identificar as partes, no contexto de transações monetárias, performance é algo inegociável.

Eis que você é contratado pelo banco _Jorge&Lemans_ para resolver esse dilema, desenvolver uma ferramenta que seja capaz de atender às demandas do banco.

Como um estudante da USP você se lembrou que as árvores são estruturas de dados que oferecem um boa complexidade para diversas operações de acesso a dados e resolveu construir uma para solucionar o problema. 

### Entrada
Seu algoritmo deve receber como entrada um número _n_, que representa a quantidade de clientes cadastrados no nosso banco.
Após isso ele receberá um sequência de _n_ registros, representando os **CPFs** , **Nomes**, **Idades** e **Saldos** dos clientes.

Lembre que um mesmo cpf **não** pode estar associado a mais e uma conta dentro do banco.

O primeiro indivíduo deve ser considerado como a raiz da sua árvore, os demais cadastros serão inseridos na árvore por uma regra que no futuro facilitará a busca por pessoas:

Caso o valor numérico do CPF do novo registro de cliente seja **maior** que o valor do cpf da raiz, ele deve ser inserido na sua sub-árvore **direita**, caso contrário, sa sua sub-árvore **esquerda** e assim sucessivamente ae encontrar a posição adequada.

```
5
186.161.140-41;Heitor Rafael Fernandes;57;-5911.43
834.772.252-87;Heitor Júlia Fernandes;82;-8666.55
977.535.257-60;Alice Bernardo Carvalho;55;1520.47
150.664.433-39;Pedro Mendes;38;-3435.54
550.980.261-80;Pedro Henrique Arthur Davi Gomes;32;-4320.64
```

### Saída
Como saída, seu  programa deve apresentar os dados de cpf das pessoas, percorrendo a ávore pelas regras **Inorder**, **Preorder**, **Postorder**:
```
Inorder
15066443339
18616114041
55098026180
83477225287
97753525760

Preorder
18616114041
15066443339
83477225287
55098026180
97753525760

Postorder
15066443339
55098026180
97753525760
83477225287
18616114041
```

### Observações da implementação

Como é descrito na sessão objetivos desse documento, não queremos apenas que os alunos resolvam o problema, mas que utilizem métodos que serão comuns no decorrer da disciplina.

Devido a esse objetivo, será exigido que vocês desenvolvam seu projeto representando ambas as entidades citadas na descrição como **TAD completos e fechados sobre si mesmos**, isto é, com funções auxiliares que permitam o acesso e a manipulação de seus atributos em diferentes contextos(arquivos .c separados). Os dados devem ser armazenados como um **TAD cliente** e dentro de uma **Árvore Binária** implementada com nós de ponteiros duplos.


A memória deve ser alocada **dinamicamente** e ser devidamente liberada
ao fim da execução. 

Utilizar múltiplos arquivos _.c_ e _.h_ para separar a implementação e a responsabilidade dos métodos de cada objeto.

Construir funções para realizar  operações repetitivas, ou seja, modularizar adequadamente seu código.

Escrever um arquivo **Makefile** que será responsável por gerenciar a execução do projeto dentro da plataforma _run.codes_.



### Observações da avaliação
A avaliação do seu programa será feita além do resultado da plataforma *run.codes*. Portanto, ter um bom resultado com os casos de teste, não será suficiente para garantir a **nota máxima** e nem a **aprovação do exercício**.

Caso seu projeto não satisfaça os pontos exigidos nos **objetivos** e explicitados nas **observações de implementação**, sua nota poderá ser **reduzida** ou ser **desconsiderada**.

Cópias de código entre alunos, acusadas pela plataforma, resultarão imediatamente em **zero** aos dois ou mais alunos envolvidos.
