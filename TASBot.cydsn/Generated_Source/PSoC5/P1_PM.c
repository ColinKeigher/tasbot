/*******************************************************************************
* File Name: P1_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for sleep mode support for Shift
*  Register component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "P1.h"

static P1_BACKUP_STRUCT P1_backup =
{
    P1_DISABLED,

    ((uint16) P1_DEFAULT_A0),
    ((uint16) P1_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint16) P1_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: P1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void P1_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    P1_backup.saveSrA0Reg   = CY_GET_REG16(P1_SHIFT_REG_LSB_PTR);
    P1_backup.saveSrA1Reg   = CY_GET_REG16(P1_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        P1_backup.saveSrIntMask = P1_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: P1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void P1_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG16(P1_SHIFT_REG_LSB_PTR, P1_backup.saveSrA0Reg);
    CY_SET_REG16(P1_SHIFT_REG_VALUE_LSB_PTR, P1_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        P1_SR_STATUS_MASK = ((uint8) P1_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: P1_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void P1_Sleep(void) 
{
    P1_backup.enableState = ((uint8) P1_IS_ENABLED);

    P1_Stop();
    P1_SaveConfig();
}


/*******************************************************************************
* Function Name: P1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void P1_Wakeup(void) 
{
    P1_RestoreConfig();

    if(0u != P1_backup.enableState)
    {
        P1_Enable();
    }
}


/* [] END OF FILE */
