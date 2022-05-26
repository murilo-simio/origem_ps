# Processo Seletivo Origem

Murilo Simionato Arnemann

---
## Execução do Programa
### Rotina 0
Cria uma moto com 85% de bateria, uma ETB com 7 posições e 8 baterias. Define a carga de 6 baterias e as conecta no ETB.

### Rotina 1-4
Representam os ciclos de aceleração e freio da moto. A cada 1s recalcula a velocidade da moto e com ela gera uma nova SoC para a bateria da moto. Também calcula os valores das cargas das baterias conectadas no SoC.

A cada 10s imprime na tela algumas informações da moto (placa, velocidade, carga e uid da bateria) e também as informações sobre os CP's do ETB, contendo o id, a carga da bateria e se ela esta carregando ou não.

### Rotina 5
Essa é a rotina de troca da bateria da moto. A bateria usada da moto é inserida no CP vazio do ETB, CP 6, e então a bateria que estava na primeira posição com 100% de carga é colocada na moto. Por fim são impressos novamente os dados da moto e do ETB para ter certeza de que a troca ocorreu.

## Funcionalidades Implementadas
### Moto
- Calcula a velocidade
- Get's
  - Estado
  - Placa
  - Velocidade
  - Bateria
- Set's
  - Estado
  - Placa
  - Velocidade
  - Bateria 

### ETB
- Conecta bateria (toAttatch)
- Desconecta bateria (toDetach)
- Carrega bateria
- Conta baterias presentes
- Conta baterias carregando
- Conta tempo de carga
- Get's
  - CP
  - UID
- Set's
  - UID
  
### Baterias
- Calcula SoC
- Get's
  - Estado
  - Host
  - UID
  - SoC
- Set's
  - Estado
  - Host
  - UID
  - SoC

### CP
- Get's
  - Estado
  - Bateria
- Set's
  - Estado
  - Bateria

## Compilação e Execução
Para compilar e executar o programa basta executar os seguintes comandos.
```bash
mkdir build && cd build
```
```bash
cmake ../
```
```bash
make
```
```bash
./origem_ps
```

## Ambiente de Desenvolvimento
Compilador: GCC 11.2.0 x86_64-linux-gnu  
SO: Pop!_OS 21.10  
IDE: Visual Studio Code 1.67.2

