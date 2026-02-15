#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * This is a configuration structure for a GPIO Pin
 */

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;       /* Possible values from @GPIO_PIN_MODES*/
	uint8_t GPIO_PinSpeed;		/* Possible values from @GPIO_PIN_SPEED*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;				/* pointer to hold the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig; 	/* This holds GPIO pin configuration settings */
}GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO possible pin number
 */
#define GPIO_PIN_NO_0 												0
#define GPIO_PIN_NO_1 												1
#define GPIO_PIN_NO_2 												2
#define GPIO_PIN_NO_3 												3
#define GPIO_PIN_NO_4 												4
#define GPIO_PIN_NO_5 												5
#define GPIO_PIN_NO_6 												6
#define GPIO_PIN_NO_7 												7
#define GPIO_PIN_NO_8 												8
#define GPIO_PIN_NO_9 												9
#define GPIO_PIN_NO_10 												10
#define GPIO_PIN_NO_11 												11
#define GPIO_PIN_NO_12 												12
#define GPIO_PIN_NO_13 												13
#define GPIO_PIN_NO_14 												14
#define GPIO_PIN_NO_15 												15


/*
 * @GPIO_PIN_MODES
 * GPIO Pin possible MODES
 */

#define GPIO_MODE_INP 		/*Input Mode */								0
#define GPIO_MODE_OUT 		/*Output Mode*/								1
#define GPIO_MODE_ALTFN 	/*Alternate Functionality Mode*/			2
#define GPIO_MODE_ANALOG 	/*Analog Mode*/								3
#define GPIO_MODE_IT_FT		/*Input Falling Edge Trigger*/				4
#define GPIO_MODE_IT_RT		/*Input Rising Edge Trigger*/				5
#define GPIO_MODE_IT_RFT	/*Input Rising Falling Edge Trigger*/		6


/*
 * GPIO Pin possible output types
 */
#define GPIO_OP_TYPE_PP 	/*Push-Pull Mode*/							0
#define GPIO_OP_TYPE_OD 	/*Open-Drain Mode*/							1

/*
 * @GPIO_PIN_SPEED
 * GPIO Pin possible output speed
 */
#define GPIO_SPEED_LOW		/*Low speed*/								0
#define GPIO_SPEED_MEDIUM 	/*Medium speed*/							1
#define GPIO_SPEED_FAST 	/*High speed*/								2
#define GPIO_SPEED_HIGH 	/*Very high speed*/							3


/*
 * GPIO Pin pull up pull down configuration
 */
#define GPIO_NO_PUPD 													0
#define GPIO_PIN_PU 													1
#define GPIO_PIN_PD 													2

/******************************* APIs supported by this driver ***********************************************/

/*
 * Peripheral Clock Setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-Init
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
