/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
typedef enum {false, true} bool;
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PV */
// Velocidade
	#define PI 3.1416
	#define DIAMETRO 0.51916 //Diametro efetivo da roda em metros
	#define COMP_TOTAL (PI*DIAMETRO) // Comprimento da circunferência do sensor capacitivo
	#define COMP_PARCIAL (PI*DIAMETRO/3) // Circuferência possui 3 gomos iguais, podemos dividir por 3
/* USER CODE END PV */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

/* USER CODE BEGIN PV */
	// COMBUSTÍVEL
		float desceLed; // Variável para descer os leds do painel
		unsigned int ledComb; // Variável para leitura dos leds
		float valorTotal; // Variável para calculo do tempo total
		bool primeira = true; // Variável para o primeiro enchimento do tanque
		int tempComp = 0, tempMais = 0, tempMenos = 0, tempComp2 = 0, tempComp3 = 0, tempComp4 = 0; // Variáveis para comparar tempo de consumo
		bool flagCima = false, flagMedio = false, flagBaixo = false, flagMBaixo = false, flagCompTempo = false, flagCompTempo2 = false; // Variáveis para verificar nível de combutível
		int flagDesceCima = 0, flagDesceMedio = 0, flagDesceBaixo = 0, flagDesceMBaixo = 0, flagSobe = 0, flagVariacao = 0; // Variáveis para confirmação da leitura do sensor

	// FREIO
		float valorTrans1 = 0.0, valorTrans2 = 0.0; //Variáveis para os transdutores de pressão
		int transMinDia = 0, transMaxDia = 0; // Valor máximo e mínimo do transdutor dianteiro
		int transMinTras = 0, transMaxTras = 0; // Valor máximo e mínimo do transdutor traseiro
		int dadosTrans = 0;

	// RPM
		const unsigned int pulsesPerRev = 1;
		unsigned long int lastPulseTime = 0; // Tenpo do ultimo pulso
		unsigned long int RPM = 0;
		unsigned long int tempoMomento = 0;
		unsigned long int interval = 0;
		unsigned int RPM_Led;
		int flag_rpm = 0;

	// SENSOR TEMPERATURA CVT
		float tempCVT = 0;
	falta max6675
	//TELEMETRIA
		int dadosComunicacao = 0;
		char input[];
		char Compa[];

	// VARIÁVEIS DE COMPARAÇÃO
		bool estadoVel = false, estadoRPM = false, estadoComb = false, estadoTemp = false, estadoBat = false, estadoFreio = false, estadoTrans = false, estadoTel = false;
		int tempoCombCVT = 0;
		int tempoBateria = 0;

	// VELOCIDADE
		int vel = 10; // Velocidade em Km/h
		int vel1 = 0; // Velocidade em T instantes antes
		int tempoVelRPM = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 16;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pins : Trans1_Pin Trans2_Pin */
  GPIO_InitStruct.Pin = Trans1_Pin|Trans2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Bateria_Pin Freio_Pin Vel_In_Pin IgnitionPin_Pin
                           Comb3_Pin */
  GPIO_InitStruct.Pin = Bateria_Pin|Freio_Pin|Vel_In_Pin|IgnitionPin_Pin
                          |Comb3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : CS_Pin SCK_Pin SO_Pin Comb2_Pin
                           Comb1_Pin */
  GPIO_InitStruct.Pin = CS_Pin|SCK_Pin|SO_Pin|Comb2_Pin
                          |Comb1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : Serial_TX_Pin */
  GPIO_InitStruct.Pin = Serial_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(Serial_TX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Serial_RX_Pin */
  GPIO_InitStruct.Pin = Serial_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Serial_RX_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
