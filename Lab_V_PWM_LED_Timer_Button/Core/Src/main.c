#include "main.h"
#include <stdio.h>

static TIM_HandleTypeDef s_TimerInstance = {.Instance = TIM4};


void SystemClock_Config(void);

void InitializeTimer() {
            __TIM4_CLK_ENABLE();
    s_TimerInstance.Init.Prescaler = 0;
    s_TimerInstance.Init.CounterMode = TIM_COUNTERMODE_UP;
    s_TimerInstance.Init.Period = 100;
    s_TimerInstance.Init.ClockDivision = TIM_CLOCKDIVISION_DIV4;
    s_TimerInstance.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&s_TimerInstance);
    HAL_TIM_Base_Start(&s_TimerInstance);
}

void InitTimerPwm(int brightness, u_int32_t channel){
    TIM_OC_InitTypeDef sConfigOC;
    HAL_TIM_PWM_Init(&s_TimerInstance);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;

    sConfigOC.Pulse = brightness;

    // Specifies Pulse value to be loaded in OCR
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH; // Output polarity
    sConfigOC.OCFastMode = TIM_OCFAST_ENABLE; // Fast mode state

    HAL_TIM_PWM_ConfigChannel(&s_TimerInstance, &sConfigOC, channel);
    HAL_TIM_PWM_Start(&s_TimerInstance, channel);


}

/*
void InitGreenTimerPWM(int brightness) {
    TIM_OC_InitTypeDef sConfigOC;
    HAL_TIM_PWM_Init(&s_TimerInstance);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;

    sConfigOC.Pulse = brightness;

    // Specifies Pulse value to be loaded in OCR
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH; // Output polarity
    sConfigOC.OCFastMode = TIM_OCFAST_ENABLE; // Fast mode state

    HAL_TIM_PWM_ConfigChannel(&s_TimerInstance, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&s_TimerInstance, TIM_CHANNEL_1);
}

void InitOrangeTimerPWM2(int brightness) {
    TIM_OC_InitTypeDef sConfigOC;
    HAL_TIM_PWM_Init(&s_TimerInstance);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;

    sConfigOC.Pulse = brightness;

    // Specifies Pulse value to be loaded in OCR
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH; // Output polarity
    sConfigOC.OCFastMode = TIM_OCFAST_ENABLE; // Fast mode state

    HAL_TIM_PWM_ConfigChannel(&s_TimerInstance, &sConfigOC, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&s_TimerInstance, TIM_CHANNEL_2);
}

void InitRedTimerPWM2(int brightness) {
    TIM_OC_InitTypeDef sConfigOC3;
    HAL_TIM_PWM_Init(&s_TimerInstance);
    sConfigOC3.OCMode = TIM_OCMODE_PWM1;

    sConfigOC3.Pulse = brightness;

    // Specifies Pulse value to be loaded in OCR
    sConfigOC3.OCPolarity = TIM_OCPOLARITY_HIGH; // Output polarity
    sConfigOC3.OCFastMode = TIM_OCFAST_ENABLE; // Fast mode state

    HAL_TIM_PWM_ConfigChannel(&s_TimerInstance, &sConfigOC3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&s_TimerInstance, TIM_CHANNEL_3);
}

void InitBlueTimerPWM2(int brightness) {
    TIM_OC_InitTypeDef sConfigOC4;
    HAL_TIM_PWM_Init(&s_TimerInstance);
    sConfigOC4.OCMode = TIM_OCMODE_PWM1;

    sConfigOC4.Pulse = brightness;

    sConfigOC4.OCPolarity = TIM_OCPOLARITY_HIGH; // Output polarity
    sConfigOC4.OCFastMode = TIM_OCFAST_ENABLE; // Fast mode state

    HAL_TIM_PWM_ConfigChannel(&s_TimerInstance, &sConfigOC4, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&s_TimerInstance, TIM_CHANNEL_4);

}
*/


void InitializeButton() {
            __GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStructure3;
    GPIO_InitStructure3.Pin = GPIO_PIN_0;
    GPIO_InitStructure3.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure3.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStructure3);
}

void InitializeAllLeds() {

            __GPIOD_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStructureOrange;
    GPIO_InitTypeDef GPIO_InitStructureRed;
    GPIO_InitTypeDef GPIO_InitStructureBlue;
    GPIO_InitTypeDef GPIO_InitStructureGreen;

    GPIO_InitStructureOrange.Pin = LD3_Pin;
    GPIO_InitStructureOrange.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructureOrange.Pull = GPIO_NOPULL;
    GPIO_InitStructureOrange.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructureOrange.Alternate = GPIO_AF2_TIM4;

    GPIO_InitStructureGreen.Pin = LD4_Pin;
    GPIO_InitStructureGreen.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructureGreen.Pull = GPIO_NOPULL;
    GPIO_InitStructureGreen.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructureGreen.Alternate = GPIO_AF2_TIM4;

    GPIO_InitStructureRed.Pin = LD5_Pin;
    GPIO_InitStructureRed.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructureRed.Pull = GPIO_NOPULL;
    GPIO_InitStructureRed.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructureRed.Alternate = GPIO_AF2_TIM4;

    GPIO_InitStructureBlue.Pin = LD6_Pin;
    GPIO_InitStructureBlue.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructureBlue.Pull = GPIO_NOPULL;
    GPIO_InitStructureBlue.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructureBlue.Alternate = GPIO_AF2_TIM4;


    HAL_GPIO_Init(LD3_GPIO_Port, &GPIO_InitStructureOrange);
    HAL_GPIO_Init(LD4_GPIO_Port, &GPIO_InitStructureGreen);
    HAL_GPIO_Init(LD5_GPIO_Port, &GPIO_InitStructureRed);
    HAL_GPIO_Init(LD6_GPIO_Port, &GPIO_InitStructureBlue);


}

int main(void) {

    HAL_Init();
    SystemClock_Config();
    InitializeTimer();
    InitializeButton();
    InitializeAllLeds();

    volatile int i = 0;
    volatile int flipFlag = 0;
    volatile char color = 'g';


    while (1) {


        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {


            if (i == 100) { flipFlag = 1; }
            if (flipFlag == 0) { i++; }
            if (flipFlag == 1) { i--; }
            HAL_Delay(10);

            switch (color) {
                case 'g':
                    InitTimerPwm(i,TIM_CHANNEL_1);
                    if (i == -1) {
                        color = 'o';
                        i = 0;
                        flipFlag = 0;
                        InitTimerPwm(0,TIM_CHANNEL_1);
                    }
                    break;

                case 'o':
                    InitTimerPwm(i,TIM_CHANNEL_2);
                    if (i == -1) {
                        color = 'r';
                        i = 0;
                        flipFlag = 0;
                        InitTimerPwm(0,TIM_CHANNEL_2);
                    }
                    break;
                case 'r':
                    InitTimerPwm(i,TIM_CHANNEL_3);
                    if (i == -1) {
                        color = 'b';
                        i = 0;
                        flipFlag = 0;
                        InitTimerPwm(0,TIM_CHANNEL_3);
                    }

                    break;
                case 'b':
                    InitTimerPwm(i,TIM_CHANNEL_4);
                    if (i == -1) {
                        color = 'g';
                        i = 0;
                        flipFlag = 0;
                        InitTimerPwm(0,TIM_CHANNEL_4);
                    }
                    break;
            }


        }

    }

}

void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
    */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 50;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
        Error_Handler();
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
