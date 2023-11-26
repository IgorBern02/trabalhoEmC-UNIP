#include <stdio.h> //entradas e saidas
#include <string.h> // manipular string usando o strcmp
#include <locale.h> // melhorar a acentua��o no terminal

#define size 100 // defini��o de tamanho 100 caracteres das strings

// armazenar as informa��es do cadastro da ind�stria
typedef struct {
    char nomeResponsavel[size];
    char cpfResponsavel[size];
    char nascimentoResponsavel[size];
    char nomeEmpresa[size];
    char cnpj[size];
    char razaoSocial[size];
    char nomeFantasia[size];
    char telefone[20];
    char rua[size];
    char numero[size];
    char bairro[size];
    char cidade[size];
    char estado[size];
    char cep[size];
    char email[size];
    char dataAbertura[20];
    int quantidadeResiduos;
    float valorCusto;
} IndustriaCliente;

// realizar o login
int realizarLogin() {
    char nomeUser[20] = "unip";
    char senha[20] = "unip123";

    printf("BEM VINDO!\n");

    printf("Login:\n");
    printf("Usu�rio: ");
    scanf("%s", nomeUser);
    printf("Senha: ");
    scanf("%s", senha);

// verifica��o usu�rio e senha

if (strcmp(nomeUser, "unip") == 0 && strcmp(senha, "unip123") == 0)
{
    printf("Login realizado com sucesso!\n");
    return 1;
} else {
    printf("Tentativa de Login negada, us�ario ou senha incorretos.\n");
    return 0;
}
}

// criptografar os dados como CPF e CNPJ
void criptografar(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                str[i] = 'a' + (str[i] - 'a' + 1) % 26;
            } else {
                str[i] = 'A' + (str[i] - 'A' + 1) % 26;
            }
        }
    }
}

// cadastrar os informa��es da ind�stria
void cadastrarIndustria(IndustriaCliente *cliente) {
    printf("\nCadastro da ind�stria:\n");
    printf("Nome do Respons�vel: ");
    scanf(" %[^\n]s", cliente->nomeResponsavel);
    printf("CPF do Respons�vel: ");
    scanf(" %[^\n]s", cliente->cpfResponsavel);
    printf("Data de Nascimento do Respons�vel: ");
    scanf(" %[^\n]s", cliente->nascimentoResponsavel);
    printf("Nome da Empresa: ");
    scanf(" %[^\n]s", cliente->nomeEmpresa);
    printf("CNPJ: ");
    scanf(" %[^\n]s", cliente->cnpj);
    printf("Raz�o Social: ");
    scanf(" %[^\n]s", cliente->razaoSocial);
    printf("Nome Fantasia: ");
    scanf(" %[^\n]s", cliente->nomeFantasia);
    printf("Telefone: ");
    scanf(" %[^\n]s", cliente->telefone);
    printf("Rua: ");
    scanf(" %[^\n]s", cliente->rua);
    printf("N�mero: ");
    scanf(" %[^\n]s", cliente->numero);
    printf("Bairro: ");
    scanf(" %[^\n]s", cliente->bairro);
    printf("Cidade: ");
    scanf(" %[^\n]s", cliente->cidade);
    printf("Estado: ");
    scanf(" %[^\n]s", cliente->estado);
    printf("CEP: ");
    scanf(" %[^\n]s", cliente->cep);
    printf("E-mail: ");
    scanf(" %[^\n]s", cliente->email);
    printf("Data de Abertura: ");
    scanf(" %[^\n]s", cliente->dataAbertura);


    // criptografar
    criptografar(cliente->cpfResponsavel);
    criptografar(cliente->cnpj);

    // criar um arquivo para armazenar o cadastro
    FILE *arquivo;
    arquivo = fopen("cadastro_industria.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // dados no arquivo
    fprintf(arquivo, "Nome do Respons�vel: %s\n", cliente->nomeResponsavel);
    fprintf(arquivo, "CPF do Respons�vel: %s\n", cliente->cpfResponsavel);
    fprintf(arquivo, "Data de Nascimento do Respons�vel: %s\n", cliente->nascimentoResponsavel);
    fprintf(arquivo, "Nome da Empresa: %s\n", cliente->nomeEmpresa);
    fprintf(arquivo, "CNPJ: %s\n", cliente->cnpj);
    fprintf(arquivo, "Raz�o Social: %s\n", cliente->razaoSocial);
    fprintf(arquivo, "Nome Fantasia: %s\n", cliente->nomeFantasia);
    fprintf(arquivo, "Telefone: %s\n", cliente->telefone);
    fprintf(arquivo, "Rua: %s\n", cliente->rua);
    fprintf(arquivo, "Numero: %s\n", cliente->numero);
    fprintf(arquivo, "Bairro: %s\n", cliente->bairro);
    fprintf(arquivo, "Cidade: %s\n", cliente->cidade);
    fprintf(arquivo, "Estado: %s\n", cliente->estado);
    fprintf(arquivo, "Cep: %s\n", cliente->cep);
    fprintf(arquivo, "E-mail: %s\n", cliente->email);
    fprintf(arquivo, "Data de Abertura: %s\n", cliente->dataAbertura);

    fclose(arquivo);
}


// cadastrar os res�duos e valores
void cadastrarResiduos(IndustriaCliente *cliente) {
    int quantidadeResiduos;
    float valorCusto;

    printf("\nCadastrar os res�duos:\n");
    printf("Digite a quantidade de res�duos tratados: ");
    scanf("%d", &quantidadeResiduos);
    printf("Digite o valor estimado de custo: ");
    scanf("%f", &valorCusto);

     // salvar os dados atualizados em um arquivo
    FILE *arquivo;
    arquivo = fopen("dados_da_quantidade_e_valor.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // dados atualizados no arquivo
    fprintf(arquivo, "Quantidade de res�duos ambientais tratados: %d\n", quantidadeResiduos);
    fprintf(arquivo, "valor estimado de custo: %.2f\n", valorCusto);

    fclose(arquivo);
}


// atualizar as quantidades de res�duos e valores
void atualizarDados(IndustriaCliente *cliente) {
    int quantidadeResiduos;
    float valorCusto;
    // IndustriaCliente industria;

    printf("\nAtualizar os dados:\n");
    printf("Digite a quantidade de res�duos tratados: ");
    scanf("%d", &quantidadeResiduos);
    printf("Digite o valor estimado de custo: ");
    scanf("%f", &valorCusto);

    // atualizar os dados
    quantidadeResiduos = quantidadeResiduos;
    valorCusto = valorCusto;

    // salvar os dados atualizados em um arquivo
    FILE *arquivo;
    arquivo = fopen("dados_da_quantidade_e_valor.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // dados atualizados no arquivo
    fprintf(arquivo, "Quantidade de res�duos ambientais tratados: %d\n", quantidadeResiduos);
    fprintf(arquivo, "valor estimado de custo: %.2f\n", valorCusto);

    fclose(arquivo);
}

// gerar relat�rios individuais
void gerarRelatorioIndividual(IndustriaCliente cliente) {

    printf("\nRelat�rio Individual:\n");
    printf("Nome da Resp�nsavel: %s\n", cliente.nomeResponsavel);
    printf("Nome da Empresa: %s\n", cliente.nomeEmpresa);
    printf("Quantidade de res�duos tratados: %s\n", cliente.quantidadeResiduos);
    printf("Valor estimado de custo: %s\n", cliente.valorCusto);

    // salvar os dados do relatório em um arquivo
    FILE *arquivoRelatorio;
    arquivoRelatorio = fopen("relatorio_individual.txt", "w");

    if (arquivoRelatorio == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }

    // escrever os dados no arquivo
    fprintf(arquivoRelatorio, "Relat�rio Individual:\n");
    fprintf(arquivoRelatorio, "Nome do Resp�nsavel: %s\n", cliente.nomeResponsavel);
    fprintf(arquivoRelatorio, "Nome da Empresa: %s\n", cliente.nomeEmpresa);
    fprintf(arquivoRelatorio, "Quantidade de res�duos tratados: %d\n", cliente.quantidadeResiduos);
    fprintf(arquivoRelatorio, "Valor estimado de custo: %.2f\n", cliente.valorCusto);

    fclose(arquivoRelatorio);
}

// fun��o principal
int main() {

    setlocale(LC_ALL,"Portuguese_Brazil");

    IndustriaCliente clientes[size];
    int numeroClientes = 0;
    int cadastroResiduos = 0;
    int opcao;

    if (!realizarLogin()) {
        printf("Login inv�lido, o programa ser� encerrado.\n");
        return 0;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar a ind�stria\n");
        printf("2. Cadastrar res�duos e valor");
        printf("3. Atualizar os res�duos e valor\n");
        printf("2. Gerar relat�rio individual\n");
        printf("3. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                cadastrarIndustria(&clientes[numeroClientes]);
                numeroClientes++;
                break;
            case 2:
                cadastrarResiduos(&clientes[cadastroResiduos]);
                cadastroResiduos++;
                break;
            case 3:
                atualizarDados(&clientes[numeroClientes - 1]);
                break;
            case 4:
                gerarRelatorioIndividual(clientes[numeroClientes - 1]);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
