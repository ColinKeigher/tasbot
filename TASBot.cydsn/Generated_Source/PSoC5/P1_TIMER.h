/*******************************************************************************
* File Name: P1_TIMER.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_P1_TIMER_H)
#define CY_ISR_P1_TIMER_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void P1_TIMER_Start(void);
void P1_TIMER_StartEx(cyisraddress address);
void P1_TIMER_Stop(void);

CY_ISR_PROTO(P1_TIMER_Interrupt);

void P1_TIMER_SetVector(cyisraddress address);
cyisraddress P1_TIMER_GetVector(void);

void P1_TIMER_SetPriority(uint8 priority);
uint8 P1_TIMER_GetPriority(void);

void P1_TIMER_Enable(void);
uint8 P1_TIMER_GetState(void);
void P1_TIMER_Disable(void);

void P1_TIMER_SetPending(void);
void P1_TIMER_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the P1_TIMER ISR. */
#define P1_TIMER_INTC_VECTOR            ((reg32 *) P1_TIMER__INTC_VECT)

/* Address of the P1_TIMER ISR priority. */
#define P1_TIMER_INTC_PRIOR             ((reg8 *) P1_TIMER__INTC_PRIOR_REG)

/* Priority of the P1_TIMER interrupt. */
#define P1_TIMER_INTC_PRIOR_NUMBER      P1_TIMER__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable P1_TIMER interrupt. */
#define P1_TIMER_INTC_SET_EN            ((reg32 *) P1_TIMER__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the P1_TIMER interrupt. */
#define P1_TIMER_INTC_CLR_EN            ((reg32 *) P1_TIMER__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the P1_TIMER interrupt state to pending. */
#define P1_TIMER_INTC_SET_PD            ((reg32 *) P1_TIMER__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the P1_TIMER interrupt. */
#define P1_TIMER_INTC_CLR_PD            ((reg32 *) P1_TIMER__INTC_CLR_PD_REG)


#endif /* CY_ISR_P1_TIMER_H */


/* [] END OF FILE */
