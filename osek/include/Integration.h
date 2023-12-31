/*******************************************************************************************
* This file has been automatically generated by SmartSAR Configurator
* SmartSAR Core v1.0.
*
* PLEASE DO NOT EDIT THIS FILE.
*
* Copyright 2009-2013 by Embedded System and Engineering Center of Zhejiang University (ESE)
* All rights exclusively reserved. Reproduction in whole or in part is    prohibited
* without the prior written consent of the copyright owner. The information presented in this
* document does not form part of any quotation or contract, is believed to be    accurate and
* reliable and may be changed without notice.    No liability will be accepted by the publisher
* for any consequence of its use. Publication thereof does not convey nor imply any license
* under patent or other industrial or intellectual property rights.
*******************************************************************************************/


#ifndef _MPC5606B_INTEGRATION_H_
    #define _MPC5606B_INTEGRATION_H_
    
    #include "Std_Types.h"
   
   /* System Services */
   #define OS_MODULE   STD_ON
   #define SCHM_MODULE   STD_ON
   #define ECUM_MODULE   STD_ON
   #define WDGM_MODULE   STD_OFF
   #define CRC_MODULE   STD_OFF
   #define XCP_MODULE   STD_OFF
   #define KWP2000_MODULE   STD_OFF
   
   /* Communication Services */
   #define DRIVER_CAN_MODULE  STD_ON
   #define CANTRCV_MODULE  STD_OFF
   #define CANIF_MODULE  STD_ON
   #define CANSM_MODULE  STD_OFF
   #define CANTP_MODULE  STD_OFF
   
   #define LIN_MODULE  STD_OFF
   #define LINIF_MODULE  STD_OFF
   #define LINSM_MODULE  STD_OFF
   #define LINTP_MODULE  STD_OFF
   
   #define FRTRCV_MODULE  STD_OFF
   #define FR_MODULE  STD_OFF
   #define FRIF_MODULE  STD_OFF
   #define FRSM_MODULE  STD_OFF
   #define FRTP_MODULE  STD_OFF
   
   #define PDUR_MODULE  STD_ON
   #define CANNM_MODULE  STD_OFF
   #define FRNM_MODULE  STD_OFF
   #define NM_MODULE  STD_OFF
   #define IPDUM_MODULE  STD_OFF
   #define COM_MODULE  STD_ON
   #define COMM_MODULE  STD_OFF
        
   /* Diagnostic Services */   
   #define DCM_MODULE   STD_OFF 
   #define DEM_MODULE   STD_OFF 
   #define DET_MODULE   STD_OFF 
   #define FIM_MODULE   STD_OFF 
   
   /* Memory Services */ 
   #define DRIVER_FLASH_MODULE   STD_OFF
   #define EEP_MODULE   STD_OFF
   #define EA_MODULE   STD_OFF
   #define FEE_MODULE   STD_OFF
   #define MEMIF_MODULE   STD_OFF
   #define NVRAM_MODULE   STD_OFF
   #define RAMTST_MODULE   STD_OFF
    
   /* Peripherals */   
   #define DRIVER_GPT_MODULE   STD_ON   
   #define DRIVER_ADC_MODULE   STD_ON  
   #define DRIVER_DIO_MODULE   STD_ON       
   #define DRIVER_MCU_MODULE   STD_ON   
   #define DRIVER_PORT_MODULE  STD_ON   
   #define DRIVER_PWM_MODULE   STD_ON   
   #define DRIVER_ICU_MODULE   STD_ON  
   #define DRIVER_SPI_MODULE   STD_OFF   
   #define DRIVER_WDG_MODULE   STD_ON   
   #define DRIVER_SWG_MODULE   STD_OFF   
   #define WDGIF_MODULE   STD_OFF   


    
   /* ECU Abstraction */
   #define IOHWAB_MODULE        STD_ON
   
   /* Others */
   #define DRIVER_SCI_MODULE        STD_OFF
   #define DEC_MODULE                STD_OFF
   #define RTE_MODULE                STD_OFF  
   #define CORE_MODULE             STD_OFF
#endif
