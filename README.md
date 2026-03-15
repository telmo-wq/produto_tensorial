# Produto tensorial v2

Este repositório é a reimplementação de um projeto antigo em C de um produto tensorial entre matrizes quadradas. Porém, esta nova implementação inclui manipulção das threads do sistema operacional por meio das bibliotecas de pthreads e OpenMP, além de ser capaz de cronometrar o tempo de execução em segundos

## Conteúdos

O interior da pasta source contém três arquivos:

- biblioteca.c: Arquivo da biblioteca criada que contém todas as funções usadas no código

- biblioteca.h: Header da biblioteca.c, contém todas as funções e struct usadas

- main.c: Arquivo que contém o fluxo principal do programa

Fora da pasta também contém

- m1.txt, m2.txt, m3.txt e m7.txt: Arquivos .txt usados como testes para o código, contém matrizes quadradas pré-escritas

- tensor_tmfc.out: Arquivo de saída onde a matriz resultado é escrita após cada execução do programa

- Makefile: Arquivo makefile com os alvos e dependências dos arquivos objeto, responsável por automatizar o comando de compilação

## Instruções para execução

Primeiramente é importante instalar o make na sua máquina 

```
sudo apt install build-essential
```

Com o makefile instalado, clone este repositório

Para compilar através do makefile:

```
make clean
make
```

Para executar:

```
./tensor arquivo1.txt arquivo2.txt... arquivoN.txt
```

Se desejar, você pode criar seus próprios arquivos.txt para testar o programa, contanto que especifique o caminho na linha de comando

Este repositório foi desenvolvido por Telmo Melo (telmo-wq) em um sistema Linux-Mint
