#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#define PINO_SERVO 22      // Pino de controle PWM
#define FREQUENCIA_PWM 50  // Frequência do PWM em Hz
#define DIVISOR_CLOCK 125.0f  // Divisor de clock para 50Hz
#define VALOR_TOPO 40000   // Valor máximo do contador PWM

#define PULSO_MINIMO 500     // Pulso correspondente a 0 graus (500us)
#define PULSO_MEIO 1470    // Pulso correspondente a 90 graus (1470us)
#define PULSO_MAXIMO 2400    // Pulso correspondente a 180 graus (2400us)
#define TAMANHO_PASSO 5       // Incremento para suavizar o movimento
#define ATRASO_PASSO 10     // Tempo de atraso entre mudanças (ms)

void configurar_pwm(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM);
    uint fatia = pwm_gpio_to_slice_num(pino);
    pwm_set_clkdiv(fatia, DIVISOR_CLOCK);
    pwm_set_wrap(fatia, VALOR_TOPO);
    pwm_set_enabled(fatia, true);
}

void definir_pulso_pwm(uint pino, uint32_t pulso) {
    pwm_set_gpio_level(pino, pulso);
}

int main() {
    stdio_init_all();
    configurar_pwm(PINO_SERVO);

    // Posicionar servo nos ângulos especificados
    definir_pulso_pwm(PINO_SERVO, PULSO_MAXIMO);
    printf("flange a 180 graus");
    sleep_ms(5000);
    definir_pulso_pwm(PINO_SERVO, PULSO_MEIO);
    printf("flange a 90 graus");
    sleep_ms(5000);
    definir_pulso_pwm(PINO_SERVO, PULSO_MINIMO);
    printf("flange a 0 graus");
    sleep_ms(5000);

    uint32_t angulo_atual = PULSO_MINIMO;
    bool aumentando = true;

    while (true) {
        definir_pulso_pwm(PINO_SERVO, angulo_atual);
        sleep_ms(ATRASO_PASSO);
        
        // Alterna entre mover o servo para frente e para trás
        if (aumentando) {
            angulo_atual += TAMANHO_PASSO;
            if (angulo_atual >= PULSO_MAXIMO) aumentando = false;
        } else {
            angulo_atual -= TAMANHO_PASSO;
            if (angulo_atual <= PULSO_MINIMO) aumentando = true;
        }
    }
    return 0;
}
