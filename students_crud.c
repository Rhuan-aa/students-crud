#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definição de um tipo string como um ponteiro para char
typedef char* string;

// Estrutura para armazenar informações de um estudante
typedef struct {
    char id[16]; // ID do estudante
    char name[128]; // Nome do estudante
    float* grades; // Vetor de notas (4 notas) alocado dinamicamente
} T_STUDENT;

// Estrutura para armazenar uma lista de estudantes
typedef struct {
    int max; // Quantidade máxima de estudantes na lista
    int size; // Quantidade atual de estudantes na lista
    T_STUDENT** students; // Vetor de ponteiros para T_STUDENT
} T_STUDENT_LIST;

// Função para criar um novo estudante
T_STUDENT* create_student(string id, string name, float* grades){
    T_STUDENT* student;
    student = malloc(sizeof(T_STUDENT)); // Aloca memória para o estudante
    strcpy(student->id, id); // Copia o ID
    strcpy(student->name, name); // Copia o nome
    student->grades = malloc(sizeof(float)*4); // Aloca memória para as notas
    memcpy(student->grades, grades, sizeof(float)*4); // Copia as notas

    return student;
}

// Função para criar uma nova lista de estudantes
T_STUDENT_LIST* create_student_list(int max){
    T_STUDENT_LIST* list;
    list = malloc(sizeof(T_STUDENT_LIST)); // Aloca memória para a lista
    list->max = max; // Define o tamanho máximo da lista
    list->size = 0; // Inicializa o tamanho atual da lista
    list->students = malloc(sizeof(T_STUDENT*) * max); // Aloca memória para o vetor de estudantes
    return list;
}

// Função para coletar informações de um novo estudante
T_STUDENT* collect_student_info(T_STUDENT_LIST* list){
    char id[16];
    char name[128];
    float grades[4];

    getchar(); // Limpa o buffer de entrada
    printf("Digite o ID do estudante: ");
    fgets(id, 16, stdin); // Lê o ID do estudante
    id[strcspn(id, "\n")] = 0; // Remove o caractere de nova linha

    int x = search_student(list, id); // Verifica se o estudante já está na lista

    if (x == -1) { // Estudante não encontrado, pode ser adicionado
        printf("Digite o nome do estudante: ");
        fgets(name, 128, stdin); // Lê o nome do estudante
        name[strcspn(name, "\n")] = 0; // Remove o caractere de nova linha

        for (int i = 0; i < 4; i++){
            printf("Digite o valor da %dª nota: ", i+1);
            scanf("%f", &grades[i]); // Lê as notas do estudante
        }

        T_STUDENT* estudante = create_student(id, name, grades); // Cria o estudante
        add_student(list, estudante); // Adiciona o estudante à lista
        return estudante;
    } else {
        printf("ERRO: Estudante já cadastrado\n");
        return NULL;
    }
}

// Função para verificar se a lista está vazia
int is_empty(T_STUDENT_LIST* list){
    if (list->size == 0){
        return true;
    } 
    return false;
}

// Função para verificar se a lista está cheia
int is_full(T_STUDENT_LIST* list){
    if (list->size == list->max){
        return true;
    } 
    return false;
}

// Função para buscar um estudante na lista pelo ID
int search_student(T_STUDENT_LIST* list, string id){
    for (int i = 0; i < list->size; i++){
        if (strcmp(id, list->students[i]->id) == 0){
            return i; // Retorna o índice do estudante encontrado
        }
    }
    return -1; // Retorna -1 se o estudante não for encontrado
}

// Função para adicionar um estudante à lista
void add_student(T_STUDENT_LIST* list, T_STUDENT* student){
    if (!(is_full(list))){
        list->students[list->size] = student; // Adiciona o estudante à lista
        list->size++; // Incrementa o tamanho da lista
    } else {
        printf("ERRO: O curso está lotado!");
    }
}

// Função para remover um estudante da lista pelo ID
void remove_student(T_STUDENT_LIST* list, string id){
    if (!(is_empty(list))){
        int index = search_student(list, id); // Busca o estudante pelo ID
        if (!(index == -1)){
            for (int i = index; i < list->size - 1; i++){
                list->students[i] = list->students[i+1]; // Remove o estudante deslocando os elementos
            }
        } else {
            printf("ERRO: Estudante não cadastrado\n");
            return NULL;
        }
    } else {
        printf("ERRO: Não há alunos cadastrados");
        return NULL;
    }
}

// Função para liberar a memória de um estudante
void free_student(T_STUDENT* student){
    free(student->grades); // Libera a memória das notas
    free(student); // Libera a memória do estudante
}

// Função para liberar a memória da lista de estudantes
void free_student_list(T_STUDENT_LIST* list){
    for (int i = 0; i < list->size; i++){
        free_student(list->students[i]); // Libera a memória de cada estudante
    }
    free(list); // Libera a memória da lista
}

// Função para obter o tamanho da lista de estudantes
int len(T_STUDENT_LIST* students){
    return students->size;
}

// Função para exibir o menu e obter a opção do usuário
int menu(){
    int option;
    do {
        printf("====== MENU ======\n");
        printf("1 - Inserir um novo aluno\n");
        printf("2 - Consultar dados de um studante\n");
        printf("3 - Excluir um aluno\n");
        printf("4 - Sair do programa\n");
        printf("\nDigite a opcao que deseja: ");
        scanf("%d", &option); // Lê a opção do usuário
    } while (!(option >= 1 && option <= 4)); // Valida a opção
    return option;
}

// Função principal
int main(int argc, char const *argv[]){
    T_STUDENT_LIST* course;
    int max; 

    printf("Digite quantos alunos seu curso pode possuir: ");
    scanf("%d", &max); // Lê o número máximo de alunos
    
    bool start = true;
    course = create_student_list(max); // Cria a lista de estudantes
    
    do {
        int opt = menu(); // Exibe o menu e obtém a opção do usuário
        if (opt == 1) {
            collect_student_info(course); // Coleta informações de um novo estudante
        } else if (opt == 2){
            char id[16];

            printf("Digite o ID do aluno: ");
            scanf("%d", id); // Lê o ID do estudante

            int index = search_student(course, id); // Busca o estudante pelo ID
            if (index == -1){
                printf("ERRO: Estudante não cadastrado\n");
            } else {
                printf("Nome: %s", course->students[index]->name); // Exibe o nome do estudante
                for (int j = 0; j < course->size; j++){
                    printf("Nota %d: %f", j, course->students[index]->grades[j]); // Exibe as notas do estudante
                }
            }
        } else if (opt == 3){
            char id[16];

            printf("Digite o ID do aluno: ");
            scanf("%d", id); // Lê o ID do estudante

            remove_student(course, id); // Remove o estudante da lista
        } else {
            start = false; // Encerra o programa
        }
    } while (start);
    
    return 0;
}