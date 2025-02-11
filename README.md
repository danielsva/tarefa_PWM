# Controle de Servomotor por PWM no Raspberry Pi Pico W

## Descrição
Este projeto tem como objetivo simular o controle do ângulo de um servomotor padrão utilizando o módulo PWM do microcontrolador RP2040, presente no Raspberry Pi Pico W. A simulação será realizada no ambiente Wokwi, integrado ao VS Code, e o desenvolvimento será feito utilizando a linguagem C com o Pico SDK.

## 📺 Demonstração

- **Execução na Placa BitDogLab:** [Assista no YouTube](https://youtu.be/QZhPXDIq2H0)

## Requisitos
Os seguintes componentes serão simulados no Wokwi:
- **Microcontrolador Raspberry Pi Pico W**
- **Servomotor padrão**

## Objetivos
1. Configurar a GPIO 22 para gerar um sinal PWM com frequência de aproximadamente **50Hz** (período de 20ms).
2. Ajustar o ciclo ativo (duty cycle) do PWM para **2.400μs** (0,12%) para posicionar o servomotor em **180 graus**, aguardando **5 segundos**.
3. Ajustar o ciclo ativo do PWM para **1.470μs** (0,0735%) para posicionar o servomotor em **90 graus**, aguardando **5 segundos**.
4. Ajustar o ciclo ativo do PWM para **500μs** (0,025%) para posicionar o servomotor em **0 graus**, aguardando **5 segundos**.
5. Criar uma rotina para movimentação periódica do servomotor entre **0 e 180 graus** de forma suave, utilizando incrementos de **±5μs** a cada **10ms**.
6. Integrar a ferramenta **BitDogLab** para realizar um experimento com um **LED RGB na GPIO 12** e observar seu comportamento durante a execução do código.

## Ambiente de Desenvolvimento
- **VS Code** com extensões para C/C++
- **SDK do Raspberry Pi Pico**
- **Simulador Wokwi**
- **Placa de desenvolvimento BitDogLab** (para testes físicos)

## Configuração do PWM
- **GPIO 22** será utilizada para o controle do servomotor.
- Frequência do PWM configurada para **50Hz**.
- Ciclos ativos definidos conforme os requisitos para posicionamento do servomotor.

## Como Executar a Simulação
1. Clone este repositório:
   ```sh
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_REPOSITORIO>
   ```
2. Compile o código usando o **Pico SDK**:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. Execute a simulação no **Wokwi**.


## Repositório do Código
Este projeto está disponível no GitHub. 

---

### Autor
Desenvolvido para a disciplina de **Sistemas Embarcados**.
