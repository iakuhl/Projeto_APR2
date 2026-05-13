/*
 * Projeto: Sistema de Curadoria de Obras de Artes
 * Arquivo: estruturas.h
 * Autor: Iano de Oliva Kuhlmann
 * Colaboradores: chat.deepseek.com
 * Disciplina: APR2
 * Professora: Dra. Eloize Rossi Marques Seno
 */


/*************************
 * ARQUIVO DE ESTRUTURAS *
 *************************/

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/**************
 * CONSTANTES *
 **************/

#define TAM_CPF 12
#define TAM_TELEFONE 20
#define TAM_NACIONALIDADE 30
#define TAM_TEXTO_PEQUENO 50
#define TAM_TEXTO_GRANDE 200
#define MAX_REDES 3


// Todos os dados deverão passar por validação no arquivo utils.c e/ou na execução do código principal.

// Todas as estruturas armazenam dados "crus", a máscara de formatação será aplicada somente na exibição dos relatórios.


/**************
 * ESTRUTURAS *
 **************/

// Estrutura para datas.
typedef struct
{
	int dia;
	int mes;
	int ano;

} Data;


// Estrutura para Artistas.
typedef struct
{
	char cpf[TAM_CPF]; // Chave única para cada artista.
	char nome[TAM_TEXTO_PEQUENO];
	char telefone[TAM_TELEFONE];
	char nacionalidade[TAM_NACIONALIDADE];
	char estilo[TAM_TEXTO_PEQUENO];
	char redesSociais[MAX_REDES][TAM_TEXTO_PEQUENO];

	Data nascimento;

} Artista;


// Estrutura para Obras de arte.
typedef struct
{
	int id; // ID única para cada obra.
	int anoCriacao;
	
	int valorCentavos; // Valor em centavos para evitar erro de conversão float.

	char titulo[TAM_TEXTO_PEQUENO];
	char tipo[TAM_TEXTO_PEQUENO];
	char descricao[TAM_TEXTO_GRANDE];

} Obra;

// Estrutura da chave de colaborações.
typedef struct
{
	char cpf[TAM_CPF]; // Deverá ser validado, somente em Artistas já cadastrados.
	int id; // Deverá ser validado, somente com Obras já cadastradas.
} ChaveColaboracao;

// Estrutura para Colaborações.
typedef struct
{
	ChaveColaboracao chaveColab; // ID única para colaboração (CPF artista + id Obra).

	char funcaoArtista[TAM_TEXTO_PEQUENO];

	int percentualContribuicao; // Percentual de colaboração, valor permitido entre 1 e 100.
	
	Data entrada;
	Data saida;

} Colaboracao;

#endif
