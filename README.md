# Gerenciamento de Estudantes

Este projeto implementa um sistema de gerenciamento de estudantes em C, permitindo a criação, consulta e remoção de estudantes de uma lista. A lista de estudantes é gerenciada dinamicamente, com suporte para um número máximo de estudantes definido pelo usuário.

## Funcionalidades

- **Criação de Estudantes**: Permite a criação de novos estudantes com ID, nome e quatro notas.
- **Consulta de Estudantes**: Permite a consulta de informações de um estudante pelo ID.
- **Remoção de Estudantes**: Permite a remoção de um estudante da lista pelo ID.
- **Gerenciamento de Memória**: Inclui funções para liberar a memória alocada dinamicamente para estudantes e para a lista de estudantes.

## Estruturas de Dados

### `T_STUDENT`

Estrutura para armazenar informações de um estudante:
- `id`: ID do estudante (string de até 15 caracteres).
- `name`: Nome do estudante (string de até 127 caracteres).
- `grades`: Vetor de quatro notas (alocado dinamicamente).

### `T_STUDENT_LIST`

Estrutura para armazenar uma lista de estudantes:
- `max`: Quantidade máxima de estudantes na lista.
- `size`: Quantidade atual de estudantes na lista.
- `students`: Vetor de ponteiros para `T_STUDENT`.

## Funções Principais

### `create_student`

Cria um novo estudante com ID, nome e notas fornecidas.

### `create_student_list`

Cria uma nova lista de estudantes com um tamanho máximo definido.

### `collect_student_info`

Coleta informações de um novo estudante e o adiciona à lista, se o ID não estiver duplicado.

### `is_empty`

Verifica se a lista de estudantes está vazia.

### `is_full`

Verifica se a lista de estudantes está cheia.

### `search_student`

Busca um estudante na lista pelo ID e retorna o índice.

### `add_student`

Adiciona um estudante à lista, se a lista não estiver cheia.

### `remove_student`

Remove um estudante da lista pelo ID, se a lista não estiver vazia.

### `free_student`

Libera a memória alocada para um estudante.

### `free_student_list`

Libera a memória alocada para a lista de estudantes e para cada estudante na lista.

### `len`

Retorna o tamanho atual da lista de estudantes.

### `menu`

Exibe o menu de opções e obtém a escolha do usuário.

### `main`

Função principal que gerencia o fluxo do programa, incluindo a criação da lista de estudantes, exibição do menu e execução das opções escolhidas pelo usuário.

## Como Executar

1. Compile o código com um compilador C, por exemplo:
    ```sh
    gcc -o students_crud students_crud.c
    ```
2. Execute o programa:
    ```sh
    ./students_crud
    ```

## Exemplo de Uso

1. Defina o número máximo de estudantes.
2. Escolha uma opção no menu:
    - Inserir um novo aluno.
    - Consultar dados de um estudante.
    - Excluir um aluno.
    - Sair do programa.

## Observações

- Certifique-se de liberar a memória alocada dinamicamente para evitar vazamentos de memória.
- O ID do estudante deve ser único para cada estudante na lista.

## Licença

Este projeto está licenciado sob os termos da licença MIT. Consulte o arquivo `LICENSE` para obter mais informações.