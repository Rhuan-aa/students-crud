# Gerenciamento de Alunos

Este projeto é um sistema simples de CRUD (Create, Read, Update, Delete) para gerenciar informações de alunos. Ele foi desenvolvido em linguagem C e permite a inserção, consulta e remoção de alunos de uma lista.

## Funcionalidades

- **Inserir Aluno**: Adiciona um novo aluno à lista, solicitando ID, nome e notas.
- **Consultar Aluno**: Permite buscar um aluno pelo ID e exibir suas informações.
- **Remover Aluno**: Remove um aluno da lista pelo ID.
- **Sair**: Encerra o programa.

## Estruturas de Dados

### T_STUDENT

Representa um aluno com os seguintes campos:
- `id`: Identificador do aluno.
- `name`: Nome do aluno.
- `grades`: Vetor de notas (4 notas), alocado dinamicamente.

### T_STUDENT_LIST

Representa a lista de alunos com os seguintes campos:
- `max`: Quantidade máxima de alunos que a lista pode conter.
- `size`: Quantidade atual de alunos na lista.
- `students`: Vetor de ponteiros para `T_STUDENT`.

## Funções Principais

- `create_student`: Cria um novo aluno.
- `create_student_list`: Cria uma nova lista de alunos.
- `collect_student_info`: Coleta informações de um novo aluno e o adiciona à lista.
- `is_empty`: Verifica se a lista está vazia.
- `is_full`: Verifica se a lista está cheia.
- `search_student`: Busca um aluno pelo ID.
- `add_student`: Adiciona um aluno à lista.
- `remove_student`: Remove um aluno da lista pelo ID.
- `free_student`: Libera a memória alocada para um aluno.
- `free_student_list`: Libera a memória alocada para a lista de alunos.
- `len`: Retorna o tamanho atual da lista de alunos.
- `menu`: Exibe o menu de opções e retorna a opção escolhida.

## Como Executar

1. Compile o código fonte:
    ```sh
    gcc students_crud.c -o students_crud
    ```

2. Execute o programa:
    ```sh
    ./students_crud
    ```

3. Siga as instruções no menu para gerenciar os alunos.

## Exemplo de Uso

Ao iniciar o programa, você será solicitado a informar a quantidade máxima de alunos que o curso pode possuir. Em seguida, o menu será exibido com as opções de inserir, consultar, remover alunos ou sair do programa.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.