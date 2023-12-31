#ifndef ___ARUART_H_INC_
#define ___ARUART_H_INC_
#define NV_MOBILE_ARUART_H_UNIT_OF_OFFSET 1B


// Register UART_THR_DLAB_0_0
#define UART_THR_DLAB_0_0                       _MK_ADDR_CONST(0x0)
#define UART_THR_DLAB_0_0_SECURE                        0x0
#define UART_THR_DLAB_0_0_DUAL                  0x0
#define UART_THR_DLAB_0_0_SCR                   0
#define UART_THR_DLAB_0_0_WORD_COUNT                    0x1
#define UART_THR_DLAB_0_0_RESET_VAL                     _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_RESET_MASK                    _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_SW_DEFAULT_VAL                        _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_READ_MASK                     _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_WRITE_MASK                    _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_THR_A_SHIFT                   _MK_SHIFT_CONST(0)
#define UART_THR_DLAB_0_0_THR_A_FIELD                   _MK_FIELD_CONST(0xff, UART_THR_DLAB_0_0_THR_A_SHIFT)
#define UART_THR_DLAB_0_0_THR_A_RANGE                   7:0
#define UART_THR_DLAB_0_0_THR_A_WOFFSET                 0x0
#define UART_THR_DLAB_0_0_THR_A_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_THR_A_DEFAULT_MASK                    _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_THR_A_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_THR_A_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_THR_A_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_THR_A_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)

#define UART_THR_DLAB_0_0_RBR_A_SHIFT                   _MK_SHIFT_CONST(0)
#define UART_THR_DLAB_0_0_RBR_A_FIELD                   _MK_FIELD_CONST(0xff, UART_THR_DLAB_0_0_RBR_A_SHIFT)
#define UART_THR_DLAB_0_0_RBR_A_RANGE                   7:0
#define UART_THR_DLAB_0_0_RBR_A_WOFFSET                 0x0
#define UART_THR_DLAB_0_0_RBR_A_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_RBR_A_DEFAULT_MASK                    _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_RBR_A_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_RBR_A_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_RBR_A_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_RBR_A_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)

#define UART_THR_DLAB_0_0_DLL_A_SHIFT                   _MK_SHIFT_CONST(0)
#define UART_THR_DLAB_0_0_DLL_A_FIELD                   _MK_FIELD_CONST(0xff, UART_THR_DLAB_0_0_DLL_A_SHIFT)
#define UART_THR_DLAB_0_0_DLL_A_RANGE                   7:0
#define UART_THR_DLAB_0_0_DLL_A_WOFFSET                 0x0
#define UART_THR_DLAB_0_0_DLL_A_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_DLL_A_DEFAULT_MASK                    _MK_MASK_CONST(0xff)
#define UART_THR_DLAB_0_0_DLL_A_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_DLL_A_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_DLL_A_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_THR_DLAB_0_0_DLL_A_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)


// Register UART_IER_DLAB_0_0
#define UART_IER_DLAB_0_0                       _MK_ADDR_CONST(0x4)
#define UART_IER_DLAB_0_0_SECURE                        0x0
#define UART_IER_DLAB_0_0_DUAL                  0x0
#define UART_IER_DLAB_0_0_SCR                   0
#define UART_IER_DLAB_0_0_WORD_COUNT                    0x1
#define UART_IER_DLAB_0_0_RESET_VAL                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_RESET_MASK                    _MK_MASK_CONST(0x3f)
#define UART_IER_DLAB_0_0_SW_DEFAULT_VAL                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_READ_MASK                     _MK_MASK_CONST(0x3f)
#define UART_IER_DLAB_0_0_WRITE_MASK                    _MK_MASK_CONST(0x3f)
#define UART_IER_DLAB_0_0_IE_EORD_SHIFT                 _MK_SHIFT_CONST(5)
#define UART_IER_DLAB_0_0_IE_EORD_FIELD                 _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_EORD_SHIFT)
#define UART_IER_DLAB_0_0_IE_EORD_RANGE                 5:5
#define UART_IER_DLAB_0_0_IE_EORD_WOFFSET                       0x0
#define UART_IER_DLAB_0_0_IE_EORD_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_EORD_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_EORD_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_EORD_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_EORD_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_EORD_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_EORD_DISABLE                       _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_EORD_ENABLE                        _MK_ENUM_CONST(1)

#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_SHIFT                   _MK_SHIFT_CONST(4)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_FIELD                   _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_RX_TIMEOUT_SHIFT)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_RANGE                   4:4
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_WOFFSET                 0x0
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_DISABLE                 _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_RX_TIMEOUT_ENABLE                  _MK_ENUM_CONST(1)

#define UART_IER_DLAB_0_0_IE_MSI_SHIFT                  _MK_SHIFT_CONST(3)
#define UART_IER_DLAB_0_0_IE_MSI_FIELD                  _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_MSI_SHIFT)
#define UART_IER_DLAB_0_0_IE_MSI_RANGE                  3:3
#define UART_IER_DLAB_0_0_IE_MSI_WOFFSET                        0x0
#define UART_IER_DLAB_0_0_IE_MSI_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_MSI_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_MSI_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_MSI_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_MSI_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_MSI_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_MSI_DISABLE                        _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_MSI_ENABLE                 _MK_ENUM_CONST(1)

#define UART_IER_DLAB_0_0_IE_RXS_SHIFT                  _MK_SHIFT_CONST(2)
#define UART_IER_DLAB_0_0_IE_RXS_FIELD                  _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_RXS_SHIFT)
#define UART_IER_DLAB_0_0_IE_RXS_RANGE                  2:2
#define UART_IER_DLAB_0_0_IE_RXS_WOFFSET                        0x0
#define UART_IER_DLAB_0_0_IE_RXS_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RXS_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RXS_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RXS_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RXS_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RXS_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RXS_DISABLE                        _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_RXS_ENABLE                 _MK_ENUM_CONST(1)

#define UART_IER_DLAB_0_0_IE_THR_SHIFT                  _MK_SHIFT_CONST(1)
#define UART_IER_DLAB_0_0_IE_THR_FIELD                  _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_THR_SHIFT)
#define UART_IER_DLAB_0_0_IE_THR_RANGE                  1:1
#define UART_IER_DLAB_0_0_IE_THR_WOFFSET                        0x0
#define UART_IER_DLAB_0_0_IE_THR_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_THR_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_THR_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_THR_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_THR_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_THR_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_THR_DISABLE                        _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_THR_ENABLE                 _MK_ENUM_CONST(1)

#define UART_IER_DLAB_0_0_IE_RHR_SHIFT                  _MK_SHIFT_CONST(0)
#define UART_IER_DLAB_0_0_IE_RHR_FIELD                  _MK_FIELD_CONST(0x1, UART_IER_DLAB_0_0_IE_RHR_SHIFT)
#define UART_IER_DLAB_0_0_IE_RHR_RANGE                  0:0
#define UART_IER_DLAB_0_0_IE_RHR_WOFFSET                        0x0
#define UART_IER_DLAB_0_0_IE_RHR_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RHR_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RHR_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RHR_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RHR_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_IER_DLAB_0_0_IE_RHR_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_IER_DLAB_0_0_IE_RHR_DISABLE                        _MK_ENUM_CONST(0)
#define UART_IER_DLAB_0_0_IE_RHR_ENABLE                 _MK_ENUM_CONST(1)


// Register UART_IIR_FCR_0
#define UART_IIR_FCR_0                  _MK_ADDR_CONST(0x8)
#define UART_IIR_FCR_0_SECURE                   0x0
#define UART_IIR_FCR_0_DUAL                     0x0
#define UART_IIR_FCR_0_SCR                      0
#define UART_IIR_FCR_0_WORD_COUNT                       0x1
#define UART_IIR_FCR_0_RESET_VAL                        _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_RESET_MASK                       _MK_MASK_CONST(0xff)
#define UART_IIR_FCR_0_SW_DEFAULT_VAL                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_READ_MASK                        _MK_MASK_CONST(0xcf)
#define UART_IIR_FCR_0_WRITE_MASK                       _MK_MASK_CONST(0xff)
#define UART_IIR_FCR_0_EN_FIFO_SHIFT                    _MK_SHIFT_CONST(6)
#define UART_IIR_FCR_0_EN_FIFO_FIELD                    _MK_FIELD_CONST(0x3, UART_IIR_FCR_0_EN_FIFO_SHIFT)
#define UART_IIR_FCR_0_EN_FIFO_RANGE                    7:6
#define UART_IIR_FCR_0_EN_FIFO_WOFFSET                  0x0
#define UART_IIR_FCR_0_EN_FIFO_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_EN_FIFO_DEFAULT_MASK                     _MK_MASK_CONST(0x3)
#define UART_IIR_FCR_0_EN_FIFO_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_EN_FIFO_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_EN_FIFO_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_EN_FIFO_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_EN_FIFO_MODE_16550                       _MK_ENUM_CONST(1)
#define UART_IIR_FCR_0_EN_FIFO_MODE_16450                       _MK_ENUM_CONST(0)

#define UART_IIR_FCR_0_IS_PRI2_SHIFT                    _MK_SHIFT_CONST(3)
#define UART_IIR_FCR_0_IS_PRI2_FIELD                    _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_IS_PRI2_SHIFT)
#define UART_IIR_FCR_0_IS_PRI2_RANGE                    3:3
#define UART_IIR_FCR_0_IS_PRI2_WOFFSET                  0x0
#define UART_IIR_FCR_0_IS_PRI2_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI2_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI2_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI2_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI2_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI2_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI2_DISABLE                  _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_IS_PRI2_ENABLE                   _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_IS_PRI1_SHIFT                    _MK_SHIFT_CONST(2)
#define UART_IIR_FCR_0_IS_PRI1_FIELD                    _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_IS_PRI1_SHIFT)
#define UART_IIR_FCR_0_IS_PRI1_RANGE                    2:2
#define UART_IIR_FCR_0_IS_PRI1_WOFFSET                  0x0
#define UART_IIR_FCR_0_IS_PRI1_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI1_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI1_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI1_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI1_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI1_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI1_DISABLE                  _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_IS_PRI1_ENABLE                   _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_IS_PRI0_SHIFT                    _MK_SHIFT_CONST(1)
#define UART_IIR_FCR_0_IS_PRI0_FIELD                    _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_IS_PRI0_SHIFT)
#define UART_IIR_FCR_0_IS_PRI0_RANGE                    1:1
#define UART_IIR_FCR_0_IS_PRI0_WOFFSET                  0x0
#define UART_IIR_FCR_0_IS_PRI0_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI0_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI0_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI0_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI0_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_PRI0_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_PRI0_DISABLE                  _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_IS_PRI0_ENABLE                   _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_IS_STA_SHIFT                     _MK_SHIFT_CONST(0)
#define UART_IIR_FCR_0_IS_STA_FIELD                     _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_IS_STA_SHIFT)
#define UART_IIR_FCR_0_IS_STA_RANGE                     0:0
#define UART_IIR_FCR_0_IS_STA_WOFFSET                   0x0
#define UART_IIR_FCR_0_IS_STA_DEFAULT                   _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_STA_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_STA_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_STA_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_STA_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_IS_STA_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_IS_STA_INTR_PEND                 _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_IS_STA_NO_INTR_PEND                      _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_RX_TRIG_SHIFT                    _MK_SHIFT_CONST(6)
#define UART_IIR_FCR_0_RX_TRIG_FIELD                    _MK_FIELD_CONST(0x3, UART_IIR_FCR_0_RX_TRIG_SHIFT)
#define UART_IIR_FCR_0_RX_TRIG_RANGE                    7:6
#define UART_IIR_FCR_0_RX_TRIG_WOFFSET                  0x0
#define UART_IIR_FCR_0_RX_TRIG_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_TRIG_DEFAULT_MASK                     _MK_MASK_CONST(0x3)
#define UART_IIR_FCR_0_RX_TRIG_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_TRIG_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_TRIG_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_TRIG_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_RX_TRIG_FIFO_COUNT_GREATER_1                     _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_RX_TRIG_FIFO_COUNT_GREATER_4                     _MK_ENUM_CONST(1)
#define UART_IIR_FCR_0_RX_TRIG_FIFO_COUNT_GREATER_8                     _MK_ENUM_CONST(2)
#define UART_IIR_FCR_0_RX_TRIG_FIFO_COUNT_GREATER_16                    _MK_ENUM_CONST(3)

#define UART_IIR_FCR_0_TX_TRIG_SHIFT                    _MK_SHIFT_CONST(4)
#define UART_IIR_FCR_0_TX_TRIG_FIELD                    _MK_FIELD_CONST(0x3, UART_IIR_FCR_0_TX_TRIG_SHIFT)
#define UART_IIR_FCR_0_TX_TRIG_RANGE                    5:4
#define UART_IIR_FCR_0_TX_TRIG_WOFFSET                  0x0
#define UART_IIR_FCR_0_TX_TRIG_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_TRIG_DEFAULT_MASK                     _MK_MASK_CONST(0x3)
#define UART_IIR_FCR_0_TX_TRIG_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_TRIG_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_TRIG_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_TRIG_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_TX_TRIG_FIFO_COUNT_GREATER_16                    _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_TX_TRIG_FIFO_COUNT_GREATER_8                     _MK_ENUM_CONST(1)
#define UART_IIR_FCR_0_TX_TRIG_FIFO_COUNT_GREATER_4                     _MK_ENUM_CONST(2)
#define UART_IIR_FCR_0_TX_TRIG_FIFO_COUNT_GREATER_1                     _MK_ENUM_CONST(3)

#define UART_IIR_FCR_0_DMA_SHIFT                        _MK_SHIFT_CONST(3)
#define UART_IIR_FCR_0_DMA_FIELD                        _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_DMA_SHIFT)
#define UART_IIR_FCR_0_DMA_RANGE                        3:3
#define UART_IIR_FCR_0_DMA_WOFFSET                      0x0
#define UART_IIR_FCR_0_DMA_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_DMA_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_DMA_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_DMA_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_DMA_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_DMA_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_DMA_NO_CHANGE                    _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_DMA_CHANGE                       _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_TX_CLR_SHIFT                     _MK_SHIFT_CONST(2)
#define UART_IIR_FCR_0_TX_CLR_FIELD                     _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_TX_CLR_SHIFT)
#define UART_IIR_FCR_0_TX_CLR_RANGE                     2:2
#define UART_IIR_FCR_0_TX_CLR_WOFFSET                   0x0
#define UART_IIR_FCR_0_TX_CLR_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_CLR_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_TX_CLR_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_CLR_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_CLR_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_TX_CLR_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_TX_CLR_NO_CLEAR                  _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_TX_CLR_CLEAR                     _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_RX_CLR_SHIFT                     _MK_SHIFT_CONST(1)
#define UART_IIR_FCR_0_RX_CLR_FIELD                     _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_RX_CLR_SHIFT)
#define UART_IIR_FCR_0_RX_CLR_RANGE                     1:1
#define UART_IIR_FCR_0_RX_CLR_WOFFSET                   0x0
#define UART_IIR_FCR_0_RX_CLR_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_CLR_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_RX_CLR_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_CLR_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_CLR_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_RX_CLR_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_RX_CLR_NO_CLEAR                  _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_RX_CLR_CLEAR                     _MK_ENUM_CONST(1)

#define UART_IIR_FCR_0_FCR_EN_FIFO_SHIFT                        _MK_SHIFT_CONST(0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_FIELD                        _MK_FIELD_CONST(0x1, UART_IIR_FCR_0_FCR_EN_FIFO_SHIFT)
#define UART_IIR_FCR_0_FCR_EN_FIFO_RANGE                        0:0
#define UART_IIR_FCR_0_FCR_EN_FIFO_WOFFSET                      0x0
#define UART_IIR_FCR_0_FCR_EN_FIFO_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_FCR_EN_FIFO_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IIR_FCR_0_FCR_EN_FIFO_DISABLE                      _MK_ENUM_CONST(0)
#define UART_IIR_FCR_0_FCR_EN_FIFO_ENABLE                       _MK_ENUM_CONST(1)


// Register UART_LCR_0
#define UART_LCR_0                      _MK_ADDR_CONST(0xc)
#define UART_LCR_0_SECURE                       0x0
#define UART_LCR_0_DUAL                         0x0
#define UART_LCR_0_SCR                  0
#define UART_LCR_0_WORD_COUNT                   0x1
#define UART_LCR_0_RESET_VAL                    _MK_MASK_CONST(0x0)
#define UART_LCR_0_RESET_MASK                   _MK_MASK_CONST(0xff)
#define UART_LCR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_LCR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_READ_MASK                    _MK_MASK_CONST(0xff)
#define UART_LCR_0_WRITE_MASK                   _MK_MASK_CONST(0xff)
#define UART_LCR_0_DLAB_SHIFT                   _MK_SHIFT_CONST(7)
#define UART_LCR_0_DLAB_FIELD                   _MK_FIELD_CONST(0x1, UART_LCR_0_DLAB_SHIFT)
#define UART_LCR_0_DLAB_RANGE                   7:7
#define UART_LCR_0_DLAB_WOFFSET                 0x0
#define UART_LCR_0_DLAB_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_DLAB_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LCR_0_DLAB_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_DLAB_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_DLAB_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LCR_0_DLAB_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LCR_0_DLAB_DISABLE                 _MK_ENUM_CONST(0)
#define UART_LCR_0_DLAB_ENABLE                  _MK_ENUM_CONST(1)

#define UART_LCR_0_SET_B_SHIFT                  _MK_SHIFT_CONST(6)
#define UART_LCR_0_SET_B_FIELD                  _MK_FIELD_CONST(0x1, UART_LCR_0_SET_B_SHIFT)
#define UART_LCR_0_SET_B_RANGE                  6:6
#define UART_LCR_0_SET_B_WOFFSET                        0x0
#define UART_LCR_0_SET_B_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_B_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_LCR_0_SET_B_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_B_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_B_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_B_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_LCR_0_SET_B_NO_BREAK                       _MK_ENUM_CONST(0)
#define UART_LCR_0_SET_B_BREAK                  _MK_ENUM_CONST(1)

#define UART_LCR_0_SET_P_SHIFT                  _MK_SHIFT_CONST(5)
#define UART_LCR_0_SET_P_FIELD                  _MK_FIELD_CONST(0x1, UART_LCR_0_SET_P_SHIFT)
#define UART_LCR_0_SET_P_RANGE                  5:5
#define UART_LCR_0_SET_P_WOFFSET                        0x0
#define UART_LCR_0_SET_P_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_P_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_LCR_0_SET_P_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_P_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_P_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_SET_P_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_LCR_0_SET_P_NO_PARITY                      _MK_ENUM_CONST(0)
#define UART_LCR_0_SET_P_PARITY                 _MK_ENUM_CONST(1)

#define UART_LCR_0_EVEN_SHIFT                   _MK_SHIFT_CONST(4)
#define UART_LCR_0_EVEN_FIELD                   _MK_FIELD_CONST(0x1, UART_LCR_0_EVEN_SHIFT)
#define UART_LCR_0_EVEN_RANGE                   4:4
#define UART_LCR_0_EVEN_WOFFSET                 0x0
#define UART_LCR_0_EVEN_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_EVEN_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LCR_0_EVEN_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_EVEN_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_EVEN_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LCR_0_EVEN_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LCR_0_EVEN_DISABLE                 _MK_ENUM_CONST(0)
#define UART_LCR_0_EVEN_ENABLE                  _MK_ENUM_CONST(1)

#define UART_LCR_0_PAR_SHIFT                    _MK_SHIFT_CONST(3)
#define UART_LCR_0_PAR_FIELD                    _MK_FIELD_CONST(0x1, UART_LCR_0_PAR_SHIFT)
#define UART_LCR_0_PAR_RANGE                    3:3
#define UART_LCR_0_PAR_WOFFSET                  0x0
#define UART_LCR_0_PAR_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_LCR_0_PAR_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_LCR_0_PAR_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_LCR_0_PAR_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_LCR_0_PAR_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_LCR_0_PAR_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_LCR_0_PAR_NO_PARITY                        _MK_ENUM_CONST(0)
#define UART_LCR_0_PAR_PARITY                   _MK_ENUM_CONST(1)

#define UART_LCR_0_STOP_SHIFT                   _MK_SHIFT_CONST(2)
#define UART_LCR_0_STOP_FIELD                   _MK_FIELD_CONST(0x1, UART_LCR_0_STOP_SHIFT)
#define UART_LCR_0_STOP_RANGE                   2:2
#define UART_LCR_0_STOP_WOFFSET                 0x0
#define UART_LCR_0_STOP_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_STOP_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LCR_0_STOP_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_STOP_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LCR_0_STOP_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LCR_0_STOP_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LCR_0_STOP_DISABLE                 _MK_ENUM_CONST(0)
#define UART_LCR_0_STOP_ENABLE                  _MK_ENUM_CONST(1)

#define UART_LCR_0_WD_SIZE_SHIFT                        _MK_SHIFT_CONST(0)
#define UART_LCR_0_WD_SIZE_FIELD                        _MK_FIELD_CONST(0x3, UART_LCR_0_WD_SIZE_SHIFT)
#define UART_LCR_0_WD_SIZE_RANGE                        1:0
#define UART_LCR_0_WD_SIZE_WOFFSET                      0x0
#define UART_LCR_0_WD_SIZE_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_WD_SIZE_DEFAULT_MASK                 _MK_MASK_CONST(0x3)
#define UART_LCR_0_WD_SIZE_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_LCR_0_WD_SIZE_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_LCR_0_WD_SIZE_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_LCR_0_WD_SIZE_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_LCR_0_WD_SIZE_WORD_LENGTH_5                        _MK_ENUM_CONST(0)
#define UART_LCR_0_WD_SIZE_WORD_LENGTH_6                        _MK_ENUM_CONST(1)
#define UART_LCR_0_WD_SIZE_WORD_LENGTH_7                        _MK_ENUM_CONST(2)
#define UART_LCR_0_WD_SIZE_WORD_LENGTH_8                        _MK_ENUM_CONST(3)


// Register UART_MCR_0
#define UART_MCR_0                      _MK_ADDR_CONST(0x10)
#define UART_MCR_0_SECURE                       0x0
#define UART_MCR_0_DUAL                         0x0
#define UART_MCR_0_SCR                  0
#define UART_MCR_0_WORD_COUNT                   0x1
#define UART_MCR_0_RESET_VAL                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_RESET_MASK                   _MK_MASK_CONST(0x7ff)
#define UART_MCR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_MCR_0_READ_MASK                    _MK_MASK_CONST(0x7ff)
#define UART_MCR_0_WRITE_MASK                   _MK_MASK_CONST(0x7ff)
#define UART_MCR_0_OLD_SIR_DECODE_SHIFT                 _MK_SHIFT_CONST(10)
#define UART_MCR_0_OLD_SIR_DECODE_FIELD                 _MK_FIELD_CONST(0x1, UART_MCR_0_OLD_SIR_DECODE_SHIFT)
#define UART_MCR_0_OLD_SIR_DECODE_RANGE                 10:10
#define UART_MCR_0_OLD_SIR_DECODE_WOFFSET                       0x0
#define UART_MCR_0_OLD_SIR_DECODE_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_OLD_SIR_DECODE_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_MCR_0_OLD_SIR_DECODE_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_OLD_SIR_DECODE_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_OLD_SIR_DECODE_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_MCR_0_OLD_SIR_DECODE_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_OLD_SIR_DECODE_DISABLE                       _MK_ENUM_CONST(0)
#define UART_MCR_0_OLD_SIR_DECODE_ENABLE                        _MK_ENUM_CONST(1)

#define UART_MCR_0_RI_POLARITY_SHIFT                    _MK_SHIFT_CONST(8)
#define UART_MCR_0_RI_POLARITY_FIELD                    _MK_FIELD_CONST(0x3, UART_MCR_0_RI_POLARITY_SHIFT)
#define UART_MCR_0_RI_POLARITY_RANGE                    9:8
#define UART_MCR_0_RI_POLARITY_WOFFSET                  0x0
#define UART_MCR_0_RI_POLARITY_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_RI_POLARITY_DEFAULT_MASK                     _MK_MASK_CONST(0x3)
#define UART_MCR_0_RI_POLARITY_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_RI_POLARITY_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_RI_POLARITY_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MCR_0_RI_POLARITY_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MCR_0_RI_POLARITY_LOW_TO_HIGH                      _MK_ENUM_CONST(0)
#define UART_MCR_0_RI_POLARITY_HIGH_TO_LOW                      _MK_ENUM_CONST(1)
#define UART_MCR_0_RI_POLARITY_BOTH_EDGES                       _MK_ENUM_CONST(2)
#define UART_MCR_0_RI_POLARITY_RSVD                     _MK_ENUM_CONST(3)

#define UART_MCR_0_DEL_QUAL_CTS_EN_SHIFT                        _MK_SHIFT_CONST(7)
#define UART_MCR_0_DEL_QUAL_CTS_EN_FIELD                        _MK_FIELD_CONST(0x1, UART_MCR_0_DEL_QUAL_CTS_EN_SHIFT)
#define UART_MCR_0_DEL_QUAL_CTS_EN_RANGE                        7:7
#define UART_MCR_0_DEL_QUAL_CTS_EN_WOFFSET                      0x0
#define UART_MCR_0_DEL_QUAL_CTS_EN_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_MCR_0_DEL_QUAL_CTS_EN_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_MCR_0_DEL_QUAL_CTS_EN_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_MCR_0_DEL_QUAL_CTS_EN_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_MCR_0_DEL_QUAL_CTS_EN_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_DEL_QUAL_CTS_EN_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_MCR_0_DEL_QUAL_CTS_EN_DISABLE                      _MK_ENUM_CONST(0)
#define UART_MCR_0_DEL_QUAL_CTS_EN_ENABLE                       _MK_ENUM_CONST(1)

#define UART_MCR_0_RTS_EN_SHIFT                 _MK_SHIFT_CONST(6)
#define UART_MCR_0_RTS_EN_FIELD                 _MK_FIELD_CONST(0x1, UART_MCR_0_RTS_EN_SHIFT)
#define UART_MCR_0_RTS_EN_RANGE                 6:6
#define UART_MCR_0_RTS_EN_WOFFSET                       0x0
#define UART_MCR_0_RTS_EN_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_EN_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_MCR_0_RTS_EN_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_EN_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_EN_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_EN_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_RTS_EN_DISABLE                       _MK_ENUM_CONST(0)
#define UART_MCR_0_RTS_EN_ENABLE                        _MK_ENUM_CONST(1)

#define UART_MCR_0_CTS_EN_SHIFT                 _MK_SHIFT_CONST(5)
#define UART_MCR_0_CTS_EN_FIELD                 _MK_FIELD_CONST(0x1, UART_MCR_0_CTS_EN_SHIFT)
#define UART_MCR_0_CTS_EN_RANGE                 5:5
#define UART_MCR_0_CTS_EN_WOFFSET                       0x0
#define UART_MCR_0_CTS_EN_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_CTS_EN_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_MCR_0_CTS_EN_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_CTS_EN_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_CTS_EN_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_MCR_0_CTS_EN_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_CTS_EN_DISABLE                       _MK_ENUM_CONST(0)
#define UART_MCR_0_CTS_EN_ENABLE                        _MK_ENUM_CONST(1)

#define UART_MCR_0_LOOPBK_SHIFT                 _MK_SHIFT_CONST(4)
#define UART_MCR_0_LOOPBK_FIELD                 _MK_FIELD_CONST(0x1, UART_MCR_0_LOOPBK_SHIFT)
#define UART_MCR_0_LOOPBK_RANGE                 4:4
#define UART_MCR_0_LOOPBK_WOFFSET                       0x0
#define UART_MCR_0_LOOPBK_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_LOOPBK_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_MCR_0_LOOPBK_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_MCR_0_LOOPBK_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_LOOPBK_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_MCR_0_LOOPBK_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_LOOPBK_DISABLE                       _MK_ENUM_CONST(0)
#define UART_MCR_0_LOOPBK_ENABLE                        _MK_ENUM_CONST(1)

#define UART_MCR_0_OUT2_SHIFT                   _MK_SHIFT_CONST(3)
#define UART_MCR_0_OUT2_FIELD                   _MK_FIELD_CONST(0x1, UART_MCR_0_OUT2_SHIFT)
#define UART_MCR_0_OUT2_RANGE                   3:3
#define UART_MCR_0_OUT2_WOFFSET                 0x0
#define UART_MCR_0_OUT2_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT2_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_OUT2_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT2_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT2_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT2_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_MCR_0_OUT2_DISABLE                 _MK_ENUM_CONST(0)
#define UART_MCR_0_OUT2_ENABLE                  _MK_ENUM_CONST(1)

#define UART_MCR_0_OUT1_SHIFT                   _MK_SHIFT_CONST(2)
#define UART_MCR_0_OUT1_FIELD                   _MK_FIELD_CONST(0x1, UART_MCR_0_OUT1_SHIFT)
#define UART_MCR_0_OUT1_RANGE                   2:2
#define UART_MCR_0_OUT1_WOFFSET                 0x0
#define UART_MCR_0_OUT1_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT1_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_MCR_0_OUT1_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT1_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT1_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_OUT1_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_MCR_0_OUT1_DISABLE                 _MK_ENUM_CONST(0)
#define UART_MCR_0_OUT1_ENABLE                  _MK_ENUM_CONST(1)

#define UART_MCR_0_RTS_SHIFT                    _MK_SHIFT_CONST(1)
#define UART_MCR_0_RTS_FIELD                    _MK_FIELD_CONST(0x1, UART_MCR_0_RTS_SHIFT)
#define UART_MCR_0_RTS_RANGE                    1:1
#define UART_MCR_0_RTS_WOFFSET                  0x0
#define UART_MCR_0_RTS_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MCR_0_RTS_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MCR_0_RTS_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MCR_0_RTS_FORCE_RTS_HI                     _MK_ENUM_CONST(0)
#define UART_MCR_0_RTS_FORCE_RTS_LOW                    _MK_ENUM_CONST(1)

#define UART_MCR_0_DTR_SHIFT                    _MK_SHIFT_CONST(0)
#define UART_MCR_0_DTR_FIELD                    _MK_FIELD_CONST(0x1, UART_MCR_0_DTR_SHIFT)
#define UART_MCR_0_DTR_RANGE                    0:0
#define UART_MCR_0_DTR_WOFFSET                  0x0
#define UART_MCR_0_DTR_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_DTR_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MCR_0_DTR_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MCR_0_DTR_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MCR_0_DTR_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MCR_0_DTR_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MCR_0_DTR_FORCE_DTR_HI                     _MK_ENUM_CONST(0)
#define UART_MCR_0_DTR_FORCE_DTR_LOW                    _MK_ENUM_CONST(1)


// Register UART_LSR_0
#define UART_LSR_0                      _MK_ADDR_CONST(0x14)
#define UART_LSR_0_SECURE                       0x0
#define UART_LSR_0_DUAL                         0x0
#define UART_LSR_0_SCR                  0
#define UART_LSR_0_WORD_COUNT                   0x1
#define UART_LSR_0_RESET_VAL                    _MK_MASK_CONST(0x260)
#define UART_LSR_0_RESET_MASK                   _MK_MASK_CONST(0x3ff)
#define UART_LSR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_READ_MASK                    _MK_MASK_CONST(0x3ff)
#define UART_LSR_0_WRITE_MASK                   _MK_MASK_CONST(0x0)
#define UART_LSR_0_RX_FIFO_EMPTY_SHIFT                  _MK_SHIFT_CONST(9)
#define UART_LSR_0_RX_FIFO_EMPTY_FIELD                  _MK_FIELD_CONST(0x1, UART_LSR_0_RX_FIFO_EMPTY_SHIFT)
#define UART_LSR_0_RX_FIFO_EMPTY_RANGE                  9:9
#define UART_LSR_0_RX_FIFO_EMPTY_WOFFSET                        0x0
#define UART_LSR_0_RX_FIFO_EMPTY_DEFAULT                        _MK_MASK_CONST(0x1)
#define UART_LSR_0_RX_FIFO_EMPTY_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_LSR_0_RX_FIFO_EMPTY_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_LSR_0_RX_FIFO_EMPTY_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_LSR_0_RX_FIFO_EMPTY_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_RX_FIFO_EMPTY_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_LSR_0_RX_FIFO_EMPTY_NOT_EMPTY                      _MK_ENUM_CONST(0)
#define UART_LSR_0_RX_FIFO_EMPTY_EMPTY                  _MK_ENUM_CONST(1)

#define UART_LSR_0_TX_FIFO_FULL_SHIFT                   _MK_SHIFT_CONST(8)
#define UART_LSR_0_TX_FIFO_FULL_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_TX_FIFO_FULL_SHIFT)
#define UART_LSR_0_TX_FIFO_FULL_RANGE                   8:8
#define UART_LSR_0_TX_FIFO_FULL_WOFFSET                 0x0
#define UART_LSR_0_TX_FIFO_FULL_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_TX_FIFO_FULL_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_TX_FIFO_FULL_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_TX_FIFO_FULL_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_TX_FIFO_FULL_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_TX_FIFO_FULL_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_TX_FIFO_FULL_NOT_FULL                        _MK_ENUM_CONST(0)
#define UART_LSR_0_TX_FIFO_FULL_FULL                    _MK_ENUM_CONST(1)

#define UART_LSR_0_FIFOE_SHIFT                  _MK_SHIFT_CONST(7)
#define UART_LSR_0_FIFOE_FIELD                  _MK_FIELD_CONST(0x1, UART_LSR_0_FIFOE_SHIFT)
#define UART_LSR_0_FIFOE_RANGE                  7:7
#define UART_LSR_0_FIFOE_WOFFSET                        0x0
#define UART_LSR_0_FIFOE_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_LSR_0_FIFOE_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_LSR_0_FIFOE_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_LSR_0_FIFOE_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_LSR_0_FIFOE_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_FIFOE_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_LSR_0_FIFOE_NO_ERR                 _MK_ENUM_CONST(0)
#define UART_LSR_0_FIFOE_ERR                    _MK_ENUM_CONST(1)

#define UART_LSR_0_TMTY_SHIFT                   _MK_SHIFT_CONST(6)
#define UART_LSR_0_TMTY_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_TMTY_SHIFT)
#define UART_LSR_0_TMTY_RANGE                   6:6
#define UART_LSR_0_TMTY_WOFFSET                 0x0
#define UART_LSR_0_TMTY_DEFAULT                 _MK_MASK_CONST(0x1)
#define UART_LSR_0_TMTY_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_TMTY_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_TMTY_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_TMTY_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_TMTY_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_TMTY_NO_EMPTY                        _MK_ENUM_CONST(0)
#define UART_LSR_0_TMTY_EMPTY                   _MK_ENUM_CONST(1)

#define UART_LSR_0_THRE_SHIFT                   _MK_SHIFT_CONST(5)
#define UART_LSR_0_THRE_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_THRE_SHIFT)
#define UART_LSR_0_THRE_RANGE                   5:5
#define UART_LSR_0_THRE_WOFFSET                 0x0
#define UART_LSR_0_THRE_DEFAULT                 _MK_MASK_CONST(0x1)
#define UART_LSR_0_THRE_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_THRE_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_THRE_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_THRE_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_THRE_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_THRE_FULL                    _MK_ENUM_CONST(0)
#define UART_LSR_0_THRE_EMPTY                   _MK_ENUM_CONST(1)

#define UART_LSR_0_BRK_SHIFT                    _MK_SHIFT_CONST(4)
#define UART_LSR_0_BRK_FIELD                    _MK_FIELD_CONST(0x1, UART_LSR_0_BRK_SHIFT)
#define UART_LSR_0_BRK_RANGE                    4:4
#define UART_LSR_0_BRK_WOFFSET                  0x0
#define UART_LSR_0_BRK_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_LSR_0_BRK_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_LSR_0_BRK_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_BRK_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_LSR_0_BRK_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_LSR_0_BRK_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_LSR_0_BRK_NO_BREAK                 _MK_ENUM_CONST(0)
#define UART_LSR_0_BRK_BREAK                    _MK_ENUM_CONST(1)

#define UART_LSR_0_FERR_SHIFT                   _MK_SHIFT_CONST(3)
#define UART_LSR_0_FERR_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_FERR_SHIFT)
#define UART_LSR_0_FERR_RANGE                   3:3
#define UART_LSR_0_FERR_WOFFSET                 0x0
#define UART_LSR_0_FERR_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_FERR_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_FERR_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_FERR_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_FERR_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_FERR_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_FERR_NO_FRAME_ERR                    _MK_ENUM_CONST(0)
#define UART_LSR_0_FERR_FRAME_ERR                       _MK_ENUM_CONST(1)

#define UART_LSR_0_PERR_SHIFT                   _MK_SHIFT_CONST(2)
#define UART_LSR_0_PERR_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_PERR_SHIFT)
#define UART_LSR_0_PERR_RANGE                   2:2
#define UART_LSR_0_PERR_WOFFSET                 0x0
#define UART_LSR_0_PERR_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_PERR_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_PERR_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_PERR_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_PERR_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_PERR_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_PERR_NO_PARITY_ERR                   _MK_ENUM_CONST(0)
#define UART_LSR_0_PERR_PARITY_ERR                      _MK_ENUM_CONST(1)

#define UART_LSR_0_OVRF_SHIFT                   _MK_SHIFT_CONST(1)
#define UART_LSR_0_OVRF_FIELD                   _MK_FIELD_CONST(0x1, UART_LSR_0_OVRF_SHIFT)
#define UART_LSR_0_OVRF_RANGE                   1:1
#define UART_LSR_0_OVRF_WOFFSET                 0x0
#define UART_LSR_0_OVRF_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_OVRF_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_LSR_0_OVRF_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_LSR_0_OVRF_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_LSR_0_OVRF_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_OVRF_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_LSR_0_OVRF_NO_OVERRUN_ERROR                        _MK_ENUM_CONST(0)
#define UART_LSR_0_OVRF_OVERRUN_ERROR                   _MK_ENUM_CONST(1)

#define UART_LSR_0_RDR_SHIFT                    _MK_SHIFT_CONST(0)
#define UART_LSR_0_RDR_FIELD                    _MK_FIELD_CONST(0x1, UART_LSR_0_RDR_SHIFT)
#define UART_LSR_0_RDR_RANGE                    0:0
#define UART_LSR_0_RDR_WOFFSET                  0x0
#define UART_LSR_0_RDR_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_LSR_0_RDR_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_LSR_0_RDR_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_LSR_0_RDR_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_LSR_0_RDR_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_LSR_0_RDR_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_LSR_0_RDR_NO_DATA_IN_FIFO                  _MK_ENUM_CONST(0)
#define UART_LSR_0_RDR_DATA_IN_FIFO                     _MK_ENUM_CONST(1)


// Register UART_MSR_0
#define UART_MSR_0                      _MK_ADDR_CONST(0x18)
#define UART_MSR_0_SECURE                       0x0
#define UART_MSR_0_DUAL                         0x0
#define UART_MSR_0_SCR                  0
#define UART_MSR_0_WORD_COUNT                   0x1
#define UART_MSR_0_RESET_VAL                    _MK_MASK_CONST(0x0)
#define UART_MSR_0_RESET_MASK                   _MK_MASK_CONST(0xff)
#define UART_MSR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_MSR_0_READ_MASK                    _MK_MASK_CONST(0xff)
#define UART_MSR_0_WRITE_MASK                   _MK_MASK_CONST(0xff)
#define UART_MSR_0_CD_SHIFT                     _MK_SHIFT_CONST(7)
#define UART_MSR_0_CD_FIELD                     _MK_FIELD_CONST(0x1, UART_MSR_0_CD_SHIFT)
#define UART_MSR_0_CD_RANGE                     7:7
#define UART_MSR_0_CD_WOFFSET                   0x0
#define UART_MSR_0_CD_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_MSR_0_CD_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_MSR_0_CD_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_CD_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_MSR_0_CD_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_CD_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_MSR_0_CD_DISABLE                   _MK_ENUM_CONST(0)
#define UART_MSR_0_CD_ENABLE                    _MK_ENUM_CONST(1)

#define UART_MSR_0_RI_SHIFT                     _MK_SHIFT_CONST(6)
#define UART_MSR_0_RI_FIELD                     _MK_FIELD_CONST(0x1, UART_MSR_0_RI_SHIFT)
#define UART_MSR_0_RI_RANGE                     6:6
#define UART_MSR_0_RI_WOFFSET                   0x0
#define UART_MSR_0_RI_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_MSR_0_RI_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_MSR_0_RI_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_RI_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_MSR_0_RI_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_RI_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_MSR_0_RI_DISABLE                   _MK_ENUM_CONST(0)
#define UART_MSR_0_RI_ENABLE                    _MK_ENUM_CONST(1)

#define UART_MSR_0_DSR_SHIFT                    _MK_SHIFT_CONST(5)
#define UART_MSR_0_DSR_FIELD                    _MK_FIELD_CONST(0x1, UART_MSR_0_DSR_SHIFT)
#define UART_MSR_0_DSR_RANGE                    5:5
#define UART_MSR_0_DSR_WOFFSET                  0x0
#define UART_MSR_0_DSR_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DSR_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MSR_0_DSR_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_DSR_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DSR_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_DSR_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MSR_0_DSR_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MSR_0_DSR_ENABLE                   _MK_ENUM_CONST(1)

#define UART_MSR_0_CTS_SHIFT                    _MK_SHIFT_CONST(4)
#define UART_MSR_0_CTS_FIELD                    _MK_FIELD_CONST(0x1, UART_MSR_0_CTS_SHIFT)
#define UART_MSR_0_CTS_RANGE                    4:4
#define UART_MSR_0_CTS_WOFFSET                  0x0
#define UART_MSR_0_CTS_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_CTS_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MSR_0_CTS_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_CTS_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_CTS_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_CTS_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MSR_0_CTS_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MSR_0_CTS_ENABLE                   _MK_ENUM_CONST(1)

#define UART_MSR_0_DCD_SHIFT                    _MK_SHIFT_CONST(3)
#define UART_MSR_0_DCD_FIELD                    _MK_FIELD_CONST(0x1, UART_MSR_0_DCD_SHIFT)
#define UART_MSR_0_DCD_RANGE                    3:3
#define UART_MSR_0_DCD_WOFFSET                  0x0
#define UART_MSR_0_DCD_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCD_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MSR_0_DCD_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCD_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCD_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCD_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MSR_0_DCD_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MSR_0_DCD_ENABLE                   _MK_ENUM_CONST(1)

#define UART_MSR_0_DRI_SHIFT                    _MK_SHIFT_CONST(2)
#define UART_MSR_0_DRI_FIELD                    _MK_FIELD_CONST(0x1, UART_MSR_0_DRI_SHIFT)
#define UART_MSR_0_DRI_RANGE                    2:2
#define UART_MSR_0_DRI_WOFFSET                  0x0
#define UART_MSR_0_DRI_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DRI_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MSR_0_DRI_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_DRI_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MSR_0_DRI_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MSR_0_DRI_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MSR_0_DRI_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MSR_0_DRI_ENABLE                   _MK_ENUM_CONST(1)

#define UART_MSR_0_DDSR_SHIFT                   _MK_SHIFT_CONST(1)
#define UART_MSR_0_DDSR_FIELD                   _MK_FIELD_CONST(0x1, UART_MSR_0_DDSR_SHIFT)
#define UART_MSR_0_DDSR_RANGE                   1:1
#define UART_MSR_0_DDSR_WOFFSET                 0x0
#define UART_MSR_0_DDSR_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_DDSR_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_MSR_0_DDSR_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_MSR_0_DDSR_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_DDSR_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_DDSR_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_MSR_0_DDSR_DISABLE                 _MK_ENUM_CONST(0)
#define UART_MSR_0_DDSR_ENABLE                  _MK_ENUM_CONST(1)

#define UART_MSR_0_DCTS_SHIFT                   _MK_SHIFT_CONST(0)
#define UART_MSR_0_DCTS_FIELD                   _MK_FIELD_CONST(0x1, UART_MSR_0_DCTS_SHIFT)
#define UART_MSR_0_DCTS_RANGE                   0:0
#define UART_MSR_0_DCTS_WOFFSET                 0x0
#define UART_MSR_0_DCTS_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCTS_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_MSR_0_DCTS_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCTS_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCTS_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_MSR_0_DCTS_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_MSR_0_DCTS_DISABLE                 _MK_ENUM_CONST(0)
#define UART_MSR_0_DCTS_ENABLE                  _MK_ENUM_CONST(1)


// Register UART_SPR_0
#define UART_SPR_0                      _MK_ADDR_CONST(0x1c)
#define UART_SPR_0_SECURE                       0x0
#define UART_SPR_0_DUAL                         0x0
#define UART_SPR_0_SCR                  0
#define UART_SPR_0_WORD_COUNT                   0x1
#define UART_SPR_0_RESET_VAL                    _MK_MASK_CONST(0x0)
#define UART_SPR_0_RESET_MASK                   _MK_MASK_CONST(0xff)
#define UART_SPR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_SPR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_SPR_0_READ_MASK                    _MK_MASK_CONST(0xff)
#define UART_SPR_0_WRITE_MASK                   _MK_MASK_CONST(0xff)
#define UART_SPR_0_SPR_A_SHIFT                  _MK_SHIFT_CONST(0)
#define UART_SPR_0_SPR_A_FIELD                  _MK_FIELD_CONST(0xff, UART_SPR_0_SPR_A_SHIFT)
#define UART_SPR_0_SPR_A_RANGE                  7:0
#define UART_SPR_0_SPR_A_WOFFSET                        0x0
#define UART_SPR_0_SPR_A_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_SPR_0_SPR_A_DEFAULT_MASK                   _MK_MASK_CONST(0xff)
#define UART_SPR_0_SPR_A_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_SPR_0_SPR_A_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_SPR_0_SPR_A_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_SPR_0_SPR_A_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)


// Register UART_IRDA_CSR_0
#define UART_IRDA_CSR_0                 _MK_ADDR_CONST(0x20)
#define UART_IRDA_CSR_0_SECURE                  0x0
#define UART_IRDA_CSR_0_DUAL                    0x0
#define UART_IRDA_CSR_0_SCR                     0
#define UART_IRDA_CSR_0_WORD_COUNT                      0x1
#define UART_IRDA_CSR_0_RESET_VAL                       _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_RESET_MASK                      _MK_MASK_CONST(0xcf)
#define UART_IRDA_CSR_0_SW_DEFAULT_VAL                  _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_SW_DEFAULT_MASK                         _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_READ_MASK                       _MK_MASK_CONST(0xcf)
#define UART_IRDA_CSR_0_WRITE_MASK                      _MK_MASK_CONST(0xcf)
#define UART_IRDA_CSR_0_SIR_A_SHIFT                     _MK_SHIFT_CONST(7)
#define UART_IRDA_CSR_0_SIR_A_FIELD                     _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_SIR_A_SHIFT)
#define UART_IRDA_CSR_0_SIR_A_RANGE                     7:7
#define UART_IRDA_CSR_0_SIR_A_WOFFSET                   0x0
#define UART_IRDA_CSR_0_SIR_A_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_SIR_A_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_SIR_A_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_SIR_A_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_SIR_A_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_SIR_A_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_SIR_A_DISABLE                   _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_SIR_A_ENABLE                    _MK_ENUM_CONST(1)

#define UART_IRDA_CSR_0_PWT_A_SHIFT                     _MK_SHIFT_CONST(6)
#define UART_IRDA_CSR_0_PWT_A_FIELD                     _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_PWT_A_SHIFT)
#define UART_IRDA_CSR_0_PWT_A_RANGE                     6:6
#define UART_IRDA_CSR_0_PWT_A_WOFFSET                   0x0
#define UART_IRDA_CSR_0_PWT_A_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_PWT_A_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_PWT_A_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_PWT_A_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_PWT_A_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_PWT_A_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_PWT_A_BAUD_PULSE_3_14                   _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_PWT_A_BAUD_PULSE_4_14                   _MK_ENUM_CONST(1)

#define UART_IRDA_CSR_0_INVERT_RTS_SHIFT                        _MK_SHIFT_CONST(3)
#define UART_IRDA_CSR_0_INVERT_RTS_FIELD                        _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_INVERT_RTS_SHIFT)
#define UART_IRDA_CSR_0_INVERT_RTS_RANGE                        3:3
#define UART_IRDA_CSR_0_INVERT_RTS_WOFFSET                      0x0
#define UART_IRDA_CSR_0_INVERT_RTS_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RTS_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_RTS_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RTS_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RTS_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RTS_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_RTS_DISABLE                      _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_INVERT_RTS_ENABLE                       _MK_ENUM_CONST(1)

#define UART_IRDA_CSR_0_INVERT_CTS_SHIFT                        _MK_SHIFT_CONST(2)
#define UART_IRDA_CSR_0_INVERT_CTS_FIELD                        _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_INVERT_CTS_SHIFT)
#define UART_IRDA_CSR_0_INVERT_CTS_RANGE                        2:2
#define UART_IRDA_CSR_0_INVERT_CTS_WOFFSET                      0x0
#define UART_IRDA_CSR_0_INVERT_CTS_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_CTS_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_CTS_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_CTS_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_CTS_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_CTS_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_CTS_DISABLE                      _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_INVERT_CTS_ENABLE                       _MK_ENUM_CONST(1)

#define UART_IRDA_CSR_0_INVERT_TXD_SHIFT                        _MK_SHIFT_CONST(1)
#define UART_IRDA_CSR_0_INVERT_TXD_FIELD                        _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_INVERT_TXD_SHIFT)
#define UART_IRDA_CSR_0_INVERT_TXD_RANGE                        1:1
#define UART_IRDA_CSR_0_INVERT_TXD_WOFFSET                      0x0
#define UART_IRDA_CSR_0_INVERT_TXD_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_TXD_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_TXD_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_TXD_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_TXD_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_TXD_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_TXD_DISABLE                      _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_INVERT_TXD_ENABLE                       _MK_ENUM_CONST(1)

#define UART_IRDA_CSR_0_INVERT_RXD_SHIFT                        _MK_SHIFT_CONST(0)
#define UART_IRDA_CSR_0_INVERT_RXD_FIELD                        _MK_FIELD_CONST(0x1, UART_IRDA_CSR_0_INVERT_RXD_SHIFT)
#define UART_IRDA_CSR_0_INVERT_RXD_RANGE                        0:0
#define UART_IRDA_CSR_0_INVERT_RXD_WOFFSET                      0x0
#define UART_IRDA_CSR_0_INVERT_RXD_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RXD_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_RXD_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RXD_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RXD_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_IRDA_CSR_0_INVERT_RXD_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_IRDA_CSR_0_INVERT_RXD_DISABLE                      _MK_ENUM_CONST(0)
#define UART_IRDA_CSR_0_INVERT_RXD_ENABLE                       _MK_ENUM_CONST(1)


// Register UART_RX_FIFO_CFG_0
#define UART_RX_FIFO_CFG_0                      _MK_ADDR_CONST(0x24)
#define UART_RX_FIFO_CFG_0_SECURE                       0x0
#define UART_RX_FIFO_CFG_0_DUAL                         0x0
#define UART_RX_FIFO_CFG_0_SCR                  0
#define UART_RX_FIFO_CFG_0_WORD_COUNT                   0x1
#define UART_RX_FIFO_CFG_0_RESET_VAL                    _MK_MASK_CONST(0x1)
#define UART_RX_FIFO_CFG_0_RESET_MASK                   _MK_MASK_CONST(0xbf)
#define UART_RX_FIFO_CFG_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_READ_MASK                    _MK_MASK_CONST(0xbf)
#define UART_RX_FIFO_CFG_0_WRITE_MASK                   _MK_MASK_CONST(0xbf)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_SHIFT                        _MK_SHIFT_CONST(7)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_FIELD                        _MK_FIELD_CONST(0x1, UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_SHIFT)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_RANGE                        7:7
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_WOFFSET                      0x0
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_DISABLE                      _MK_ENUM_CONST(0)
#define UART_RX_FIFO_CFG_0_EN_RX_FIFO_TRIG_ENABLE                       _MK_ENUM_CONST(1)

#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_SHIFT                   _MK_SHIFT_CONST(0)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_FIELD                   _MK_FIELD_CONST(0x3f, UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_SHIFT)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_RANGE                   5:0
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_WOFFSET                 0x0
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_DEFAULT                 _MK_MASK_CONST(0x1)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_DEFAULT_MASK                    _MK_MASK_CONST(0x3f)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_RX_FIFO_CFG_0_RX_FIFO_TRIG_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)


// Register UART_MIE_0
#define UART_MIE_0                      _MK_ADDR_CONST(0x28)
#define UART_MIE_0_SECURE                       0x0
#define UART_MIE_0_DUAL                         0x0
#define UART_MIE_0_SCR                  0
#define UART_MIE_0_WORD_COUNT                   0x1
#define UART_MIE_0_RESET_VAL                    _MK_MASK_CONST(0xf)
#define UART_MIE_0_RESET_MASK                   _MK_MASK_CONST(0xf)
#define UART_MIE_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_MIE_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_MIE_0_READ_MASK                    _MK_MASK_CONST(0xf)
#define UART_MIE_0_WRITE_MASK                   _MK_MASK_CONST(0xf)
#define UART_MIE_0_DCD_INT_EN_SHIFT                     _MK_SHIFT_CONST(3)
#define UART_MIE_0_DCD_INT_EN_FIELD                     _MK_FIELD_CONST(0x1, UART_MIE_0_DCD_INT_EN_SHIFT)
#define UART_MIE_0_DCD_INT_EN_RANGE                     3:3
#define UART_MIE_0_DCD_INT_EN_WOFFSET                   0x0
#define UART_MIE_0_DCD_INT_EN_DEFAULT                   _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCD_INT_EN_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCD_INT_EN_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCD_INT_EN_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCD_INT_EN_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCD_INT_EN_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCD_INT_EN_DISABLE                   _MK_ENUM_CONST(0)
#define UART_MIE_0_DCD_INT_EN_ENABLE                    _MK_ENUM_CONST(1)

#define UART_MIE_0_DRI_INT_EN_SHIFT                     _MK_SHIFT_CONST(2)
#define UART_MIE_0_DRI_INT_EN_FIELD                     _MK_FIELD_CONST(0x1, UART_MIE_0_DRI_INT_EN_SHIFT)
#define UART_MIE_0_DRI_INT_EN_RANGE                     2:2
#define UART_MIE_0_DRI_INT_EN_WOFFSET                   0x0
#define UART_MIE_0_DRI_INT_EN_DEFAULT                   _MK_MASK_CONST(0x1)
#define UART_MIE_0_DRI_INT_EN_DEFAULT_MASK                      _MK_MASK_CONST(0x1)
#define UART_MIE_0_DRI_INT_EN_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_MIE_0_DRI_INT_EN_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define UART_MIE_0_DRI_INT_EN_PARITY_PROTECTION                 _MK_MASK_CONST(0x0)
#define UART_MIE_0_DRI_INT_EN_PLATFORM_DEPENDENT                        _MK_MASK_CONST(0x1)
#define UART_MIE_0_DRI_INT_EN_DISABLE                   _MK_ENUM_CONST(0)
#define UART_MIE_0_DRI_INT_EN_ENABLE                    _MK_ENUM_CONST(1)

#define UART_MIE_0_DDSR_INT_EN_SHIFT                    _MK_SHIFT_CONST(1)
#define UART_MIE_0_DDSR_INT_EN_FIELD                    _MK_FIELD_CONST(0x1, UART_MIE_0_DDSR_INT_EN_SHIFT)
#define UART_MIE_0_DDSR_INT_EN_RANGE                    1:1
#define UART_MIE_0_DDSR_INT_EN_WOFFSET                  0x0
#define UART_MIE_0_DDSR_INT_EN_DEFAULT                  _MK_MASK_CONST(0x1)
#define UART_MIE_0_DDSR_INT_EN_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MIE_0_DDSR_INT_EN_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MIE_0_DDSR_INT_EN_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MIE_0_DDSR_INT_EN_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MIE_0_DDSR_INT_EN_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MIE_0_DDSR_INT_EN_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MIE_0_DDSR_INT_EN_ENABLE                   _MK_ENUM_CONST(1)

#define UART_MIE_0_DCTS_INT_EN_SHIFT                    _MK_SHIFT_CONST(0)
#define UART_MIE_0_DCTS_INT_EN_FIELD                    _MK_FIELD_CONST(0x1, UART_MIE_0_DCTS_INT_EN_SHIFT)
#define UART_MIE_0_DCTS_INT_EN_RANGE                    0:0
#define UART_MIE_0_DCTS_INT_EN_WOFFSET                  0x0
#define UART_MIE_0_DCTS_INT_EN_DEFAULT                  _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCTS_INT_EN_DEFAULT_MASK                     _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCTS_INT_EN_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCTS_INT_EN_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCTS_INT_EN_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_MIE_0_DCTS_INT_EN_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)
#define UART_MIE_0_DCTS_INT_EN_DISABLE                  _MK_ENUM_CONST(0)
#define UART_MIE_0_DCTS_INT_EN_ENABLE                   _MK_ENUM_CONST(1)


// Register UART_VENDOR_STATUS_0_0
#define UART_VENDOR_STATUS_0_0                  _MK_ADDR_CONST(0x2c)
#define UART_VENDOR_STATUS_0_0_SECURE                   0x0
#define UART_VENDOR_STATUS_0_0_DUAL                     0x0
#define UART_VENDOR_STATUS_0_0_SCR                      0
#define UART_VENDOR_STATUS_0_0_WORD_COUNT                       0x1
#define UART_VENDOR_STATUS_0_0_RESET_VAL                        _MK_MASK_CONST(0x3)
#define UART_VENDOR_STATUS_0_0_RESET_MASK                       _MK_MASK_CONST(0x3f3f000f)
#define UART_VENDOR_STATUS_0_0_SW_DEFAULT_VAL                   _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_READ_MASK                        _MK_MASK_CONST(0x3f3f000f)
#define UART_VENDOR_STATUS_0_0_WRITE_MASK                       _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_SHIFT                    _MK_SHIFT_CONST(24)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_FIELD                    _MK_FIELD_CONST(0x3f, UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_SHIFT)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_RANGE                    29:24
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_WOFFSET                  0x0
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_DEFAULT_MASK                     _MK_MASK_CONST(0x3f)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_FIFO_COUNTER_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)

#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_SHIFT                    _MK_SHIFT_CONST(16)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_FIELD                    _MK_FIELD_CONST(0x3f, UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_SHIFT)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_RANGE                    21:16
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_WOFFSET                  0x0
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_DEFAULT_MASK                     _MK_MASK_CONST(0x3f)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_PARITY_PROTECTION                        _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_FIFO_COUNTER_PLATFORM_DEPENDENT                       _MK_MASK_CONST(0x1)

#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_SHIFT                 _MK_SHIFT_CONST(3)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_FIELD                 _MK_FIELD_CONST(0x1, UART_VENDOR_STATUS_0_0_TX_OVERRUN_SHIFT)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_RANGE                 3:3
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_WOFFSET                       0x0
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_DEFAULT                       _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_DEFAULT_MASK                  _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_PARITY_PROTECTION                     _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_PLATFORM_DEPENDENT                    _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_NO_OVERRUN                    _MK_ENUM_CONST(0)
#define UART_VENDOR_STATUS_0_0_TX_OVERRUN_OVERRUN                       _MK_ENUM_CONST(1)

#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_SHIFT                        _MK_SHIFT_CONST(2)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_FIELD                        _MK_FIELD_CONST(0x1, UART_VENDOR_STATUS_0_0_RX_UNDERRUN_SHIFT)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_RANGE                        2:2
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_WOFFSET                      0x0
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_DEFAULT_MASK                 _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_NO_UNDERRUN                  _MK_ENUM_CONST(0)
#define UART_VENDOR_STATUS_0_0_RX_UNDERRUN_UNDERRUN                     _MK_ENUM_CONST(1)

#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_SHIFT                       _MK_SHIFT_CONST(1)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_FIELD                       _MK_FIELD_CONST(0x1, UART_VENDOR_STATUS_0_0_UART_RX_IDLE_SHIFT)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_RANGE                       1:1
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_WOFFSET                     0x0
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_DEFAULT                     _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_DEFAULT_MASK                        _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_SW_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_SW_DEFAULT_MASK                     _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_PARITY_PROTECTION                   _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_PLATFORM_DEPENDENT                  _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_BUSY                        _MK_ENUM_CONST(0)
#define UART_VENDOR_STATUS_0_0_UART_RX_IDLE_IDLE                        _MK_ENUM_CONST(1)

#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_SHIFT                       _MK_SHIFT_CONST(0)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_FIELD                       _MK_FIELD_CONST(0x1, UART_VENDOR_STATUS_0_0_UART_TX_IDLE_SHIFT)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_RANGE                       0:0
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_WOFFSET                     0x0
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_DEFAULT                     _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_DEFAULT_MASK                        _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_SW_DEFAULT                  _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_SW_DEFAULT_MASK                     _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_PARITY_PROTECTION                   _MK_MASK_CONST(0x0)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_PLATFORM_DEPENDENT                  _MK_MASK_CONST(0x1)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_BUSY                        _MK_ENUM_CONST(0)
#define UART_VENDOR_STATUS_0_0_UART_TX_IDLE_IDLE                        _MK_ENUM_CONST(1)


// Reserved address 0x30

// Reserved address 0x34

// Reserved address 0x38

// Register UART_ASR_0
#define UART_ASR_0                      _MK_ADDR_CONST(0x3c)
#define UART_ASR_0_SECURE                       0x0
#define UART_ASR_0_DUAL                         0x0
#define UART_ASR_0_SCR                  0
#define UART_ASR_0_WORD_COUNT                   0x1
#define UART_ASR_0_RESET_VAL                    _MK_MASK_CONST(0x0)
#define UART_ASR_0_RESET_MASK                   _MK_MASK_CONST(0xc000ffff)
#define UART_ASR_0_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define UART_ASR_0_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_READ_MASK                    _MK_MASK_CONST(0xc000ffff)
#define UART_ASR_0_WRITE_MASK                   _MK_MASK_CONST(0xc000ffff)
#define UART_ASR_0_VALID_SHIFT                  _MK_SHIFT_CONST(31)
#define UART_ASR_0_VALID_FIELD                  _MK_FIELD_CONST(0x1, UART_ASR_0_VALID_SHIFT)
#define UART_ASR_0_VALID_RANGE                  31:31
#define UART_ASR_0_VALID_WOFFSET                        0x0
#define UART_ASR_0_VALID_DEFAULT                        _MK_MASK_CONST(0x0)
#define UART_ASR_0_VALID_DEFAULT_MASK                   _MK_MASK_CONST(0x1)
#define UART_ASR_0_VALID_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define UART_ASR_0_VALID_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)
#define UART_ASR_0_VALID_PARITY_PROTECTION                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_VALID_PLATFORM_DEPENDENT                     _MK_MASK_CONST(0x1)
#define UART_ASR_0_VALID_UN_SET                 _MK_ENUM_CONST(0)
#define UART_ASR_0_VALID_SET                    _MK_ENUM_CONST(1)

#define UART_ASR_0_BUSY_SHIFT                   _MK_SHIFT_CONST(30)
#define UART_ASR_0_BUSY_FIELD                   _MK_FIELD_CONST(0x1, UART_ASR_0_BUSY_SHIFT)
#define UART_ASR_0_BUSY_RANGE                   30:30
#define UART_ASR_0_BUSY_WOFFSET                 0x0
#define UART_ASR_0_BUSY_DEFAULT                 _MK_MASK_CONST(0x0)
#define UART_ASR_0_BUSY_DEFAULT_MASK                    _MK_MASK_CONST(0x1)
#define UART_ASR_0_BUSY_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_BUSY_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define UART_ASR_0_BUSY_PARITY_PROTECTION                       _MK_MASK_CONST(0x0)
#define UART_ASR_0_BUSY_PLATFORM_DEPENDENT                      _MK_MASK_CONST(0x1)
#define UART_ASR_0_BUSY_NO_BUSY                 _MK_ENUM_CONST(0)
#define UART_ASR_0_BUSY_BUSY                    _MK_ENUM_CONST(1)

#define UART_ASR_0_RX_RATE_SENSE_H_SHIFT                        _MK_SHIFT_CONST(8)
#define UART_ASR_0_RX_RATE_SENSE_H_FIELD                        _MK_FIELD_CONST(0xff, UART_ASR_0_RX_RATE_SENSE_H_SHIFT)
#define UART_ASR_0_RX_RATE_SENSE_H_RANGE                        15:8
#define UART_ASR_0_RX_RATE_SENSE_H_WOFFSET                      0x0
#define UART_ASR_0_RX_RATE_SENSE_H_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_H_DEFAULT_MASK                 _MK_MASK_CONST(0xff)
#define UART_ASR_0_RX_RATE_SENSE_H_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_H_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_H_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_H_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)

#define UART_ASR_0_RX_RATE_SENSE_L_SHIFT                        _MK_SHIFT_CONST(0)
#define UART_ASR_0_RX_RATE_SENSE_L_FIELD                        _MK_FIELD_CONST(0xff, UART_ASR_0_RX_RATE_SENSE_L_SHIFT)
#define UART_ASR_0_RX_RATE_SENSE_L_RANGE                        7:0
#define UART_ASR_0_RX_RATE_SENSE_L_WOFFSET                      0x0
#define UART_ASR_0_RX_RATE_SENSE_L_DEFAULT                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_L_DEFAULT_MASK                 _MK_MASK_CONST(0xff)
#define UART_ASR_0_RX_RATE_SENSE_L_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_L_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_L_PARITY_PROTECTION                    _MK_MASK_CONST(0x0)
#define UART_ASR_0_RX_RATE_SENSE_L_PLATFORM_DEPENDENT                   _MK_MASK_CONST(0x1)


//
// REGISTER LIST
//
#define LIST_ARUART_REGS(_op_) \
_op_(UART_THR_DLAB_0_0) \
_op_(UART_IER_DLAB_0_0) \
_op_(UART_IIR_FCR_0) \
_op_(UART_LCR_0) \
_op_(UART_MCR_0) \
_op_(UART_LSR_0) \
_op_(UART_MSR_0) \
_op_(UART_SPR_0) \
_op_(UART_IRDA_CSR_0) \
_op_(UART_RX_FIFO_CFG_0) \
_op_(UART_MIE_0) \
_op_(UART_VENDOR_STATUS_0_0) \
_op_(UART_ASR_0)


//
// ADDRESS SPACES
//

#define BASE_ADDRESS_UART       0x00000000

//
// ARUART REGISTER BANKS
//

#define UART0_FIRST_REG 0x0000 // UART_THR_DLAB_0_0
#define UART0_LAST_REG 0x002c // UART_VENDOR_STATUS_0_0
#define UART1_FIRST_REG 0x003c // UART_ASR_0
#define UART1_LAST_REG 0x003c // UART_ASR_0

// To satisfy various compilers and platforms,
// we let users control the types and syntax of certain constants, using macros.
#ifndef _MK_SHIFT_CONST
  #define _MK_SHIFT_CONST(_constant_) _constant_
#endif
#ifndef _MK_MASK_CONST
  #define _MK_MASK_CONST(_constant_) _constant_
#endif
#ifndef _MK_ENUM_CONST
  #define _MK_ENUM_CONST(_constant_) (_constant_ ## UL)
#endif
#ifndef _MK_ADDR_CONST
  #define _MK_ADDR_CONST(_constant_) _constant_
#endif
#ifndef _MK_FIELD_CONST
  #define _MK_FIELD_CONST(_mask_, _shift_) (_MK_MASK_CONST(_mask_) << _MK_SHIFT_CONST(_shift_))
#endif

#define TEGRA_UART_LCR_DLAB		(UART_LCR_0_DLAB_ENABLE << UART_LCR_0_DLAB_SHIFT)
#define TEGRA_UART_IER_THRE		(UART_IER_DLAB_0_0_IE_THR_ENABLE << UART_IER_DLAB_0_0_IE_THR_SHIFT)
#define TEGRA_UART_LSR_RDY		(UART_LSR_0_RDR_DATA_IN_FIFO << UART_LSR_0_RDR_SHIFT)
#define TEGRA_UART_LSR_TX_FIFO_FULL	(UART_LSR_0_TX_FIFO_FULL_FULL << UART_LSR_0_TX_FIFO_FULL_SHIFT)
#define TEGRA_UART_LSR_THRE_EMPTY	(UART_LSR_0_THRE_EMPTY << UART_LSR_0_THRE_SHIFT)
#define TEGRA_UART_LSR_TX_SHIFT_EMPTY	(UART_LSR_0_TMTY_EMPTY << UART_LSR_0_TMTY_SHIFT)
#define TEGRA_UART_IIR_NO_INT		(UART_IIR_FCR_0_IS_STA_NO_INTR_PEND << UART_IIR_FCR_0_IS_STA_SHIFT)

#endif // ifndef ___ARUART_H_INC_
