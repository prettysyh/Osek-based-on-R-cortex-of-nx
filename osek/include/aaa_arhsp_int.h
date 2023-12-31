#ifndef ___ARHSP_INT_H_INC_
#define ___ARHSP_INT_H_INC_

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

// Register HSP_INT_IE_0
#define HSP_INT_IE_0                    _MK_ADDR_CONST(0x100)
#define HSP_INT_IE_0_SECURE                     0x0
#define HSP_INT_IE_0_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_0_WORD_COUNT                         0x1
#define HSP_INT_IE_0_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_0_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_0_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_0_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_0_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_0_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_0_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_0_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_0_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_0_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_0_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_0_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_0_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_0_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_0_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_0_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_0_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_0_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_0_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_0_dbell_enable_SHIFT)
#define HSP_INT_IE_0_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_0_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_0_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_0_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_0_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_0_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_0_mbox_full_enable_SHIFT)
#define HSP_INT_IE_0_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_0_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_0_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_0_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_0_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_0_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_0_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_0_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_0_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_0_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_0_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_0_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE
#define HSP_INT_IE                      _MK_ADDR_CONST(0x100)
#define HSP_INT_IE_SECURE                       0x0
#define HSP_INT_IE_SCR                  SCR_C0_REG_0
#define HSP_INT_IE_WORD_COUNT                   0x1
#define HSP_INT_IE_RESET_VAL                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_RESET_MASK                   _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_SW_DEFAULT_VAL                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)
#define HSP_INT_IE_READ_MASK                    _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_WRITE_MASK                   _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_smp1_gnt_enable_SHIFT                        _MK_SHIFT_CONST(28)
#define HSP_INT_IE_smp1_gnt_enable_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_IE_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_smp1_gnt_enable_RANGE                        31:28
#define HSP_INT_IE_smp1_gnt_enable_WOFFSET                      0x0
#define HSP_INT_IE_smp1_gnt_enable_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_IE_smp1_gnt_enable_DEFAULT_MASK                 _MK_MASK_CONST(0xf)
#define HSP_INT_IE_smp1_gnt_enable_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_smp1_gnt_enable_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_IE_smp0_gnt_enable_SHIFT                        _MK_SHIFT_CONST(24)
#define HSP_INT_IE_smp0_gnt_enable_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_IE_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_smp0_gnt_enable_RANGE                        27:24
#define HSP_INT_IE_smp0_gnt_enable_WOFFSET                      0x0
#define HSP_INT_IE_smp0_gnt_enable_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_IE_smp0_gnt_enable_DEFAULT_MASK                 _MK_MASK_CONST(0xf)
#define HSP_INT_IE_smp0_gnt_enable_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_smp0_gnt_enable_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_IE_dbell_enable_SHIFT                   _MK_SHIFT_CONST(16)
#define HSP_INT_IE_dbell_enable_FIELD                   _MK_FIELD_CONST(0xff, HSP_INT_IE_dbell_enable_SHIFT)
#define HSP_INT_IE_dbell_enable_RANGE                   23:16
#define HSP_INT_IE_dbell_enable_WOFFSET                 0x0
#define HSP_INT_IE_dbell_enable_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_dbell_enable_DEFAULT_MASK                    _MK_MASK_CONST(0xff)
#define HSP_INT_IE_dbell_enable_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_IE_dbell_enable_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)

#define HSP_INT_IE_mbox_full_enable_SHIFT                       _MK_SHIFT_CONST(8)
#define HSP_INT_IE_mbox_full_enable_FIELD                       _MK_FIELD_CONST(0xff, HSP_INT_IE_mbox_full_enable_SHIFT)
#define HSP_INT_IE_mbox_full_enable_RANGE                       15:8
#define HSP_INT_IE_mbox_full_enable_WOFFSET                     0x0
#define HSP_INT_IE_mbox_full_enable_DEFAULT                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_mbox_full_enable_DEFAULT_MASK                        _MK_MASK_CONST(0xff)
#define HSP_INT_IE_mbox_full_enable_SW_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_mbox_full_enable_SW_DEFAULT_MASK                     _MK_MASK_CONST(0x0)

#define HSP_INT_IE_mbox_empty_enable_SHIFT                      _MK_SHIFT_CONST(0)
#define HSP_INT_IE_mbox_empty_enable_FIELD                      _MK_FIELD_CONST(0xff, HSP_INT_IE_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_mbox_empty_enable_RANGE                      7:0
#define HSP_INT_IE_mbox_empty_enable_WOFFSET                    0x0
#define HSP_INT_IE_mbox_empty_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_mbox_empty_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xff)
#define HSP_INT_IE_mbox_empty_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_mbox_empty_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_1
#define HSP_INT_IE_1                    _MK_ADDR_CONST(0x104)
#define HSP_INT_IE_1_SECURE                     0x0
#define HSP_INT_IE_1_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_1_WORD_COUNT                         0x1
#define HSP_INT_IE_1_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_1_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_1_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_1_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_1_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_1_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_1_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_1_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_1_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_1_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_1_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_1_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_1_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_1_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_1_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_1_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_1_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_1_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_1_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_1_dbell_enable_SHIFT)
#define HSP_INT_IE_1_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_1_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_1_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_1_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_1_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_1_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_1_mbox_full_enable_SHIFT)
#define HSP_INT_IE_1_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_1_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_1_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_1_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_1_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_1_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_1_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_1_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_1_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_1_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_1_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_1_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_2
#define HSP_INT_IE_2                    _MK_ADDR_CONST(0x108)
#define HSP_INT_IE_2_SECURE                     0x0
#define HSP_INT_IE_2_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_2_WORD_COUNT                         0x1
#define HSP_INT_IE_2_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_2_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_2_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_2_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_2_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_2_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_2_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_2_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_2_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_2_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_2_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_2_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_2_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_2_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_2_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_2_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_2_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_2_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_2_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_2_dbell_enable_SHIFT)
#define HSP_INT_IE_2_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_2_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_2_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_2_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_2_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_2_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_2_mbox_full_enable_SHIFT)
#define HSP_INT_IE_2_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_2_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_2_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_2_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_2_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_2_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_2_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_2_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_2_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_2_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_2_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_2_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_3
#define HSP_INT_IE_3                    _MK_ADDR_CONST(0x10c)
#define HSP_INT_IE_3_SECURE                     0x0
#define HSP_INT_IE_3_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_3_WORD_COUNT                         0x1
#define HSP_INT_IE_3_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_3_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_3_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_3_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_3_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_3_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_3_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_3_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_3_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_3_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_3_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_3_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_3_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_3_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_3_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_3_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_3_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_3_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_3_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_3_dbell_enable_SHIFT)
#define HSP_INT_IE_3_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_3_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_3_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_3_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_3_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_3_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_3_mbox_full_enable_SHIFT)
#define HSP_INT_IE_3_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_3_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_3_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_3_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_3_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_3_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_3_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_3_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_3_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_3_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_3_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_3_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_4
#define HSP_INT_IE_4                    _MK_ADDR_CONST(0x110)
#define HSP_INT_IE_4_SECURE                     0x0
#define HSP_INT_IE_4_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_4_WORD_COUNT                         0x1
#define HSP_INT_IE_4_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_4_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_4_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_4_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_4_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_4_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_4_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_4_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_4_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_4_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_4_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_4_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_4_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_4_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_4_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_4_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_4_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_4_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_4_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_4_dbell_enable_SHIFT)
#define HSP_INT_IE_4_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_4_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_4_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_4_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_4_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_4_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_4_mbox_full_enable_SHIFT)
#define HSP_INT_IE_4_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_4_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_4_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_4_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_4_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_4_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_4_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_4_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_4_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_4_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_4_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_4_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_5
#define HSP_INT_IE_5                    _MK_ADDR_CONST(0x114)
#define HSP_INT_IE_5_SECURE                     0x0
#define HSP_INT_IE_5_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_5_WORD_COUNT                         0x1
#define HSP_INT_IE_5_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_5_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_5_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_5_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_5_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_5_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_5_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_5_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_5_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_5_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_5_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_5_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_5_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_5_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_5_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_5_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_5_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_5_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_5_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_5_dbell_enable_SHIFT)
#define HSP_INT_IE_5_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_5_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_5_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_5_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_5_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_5_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_5_mbox_full_enable_SHIFT)
#define HSP_INT_IE_5_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_5_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_5_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_5_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_5_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_5_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_5_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_5_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_5_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_5_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_5_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_5_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_6
#define HSP_INT_IE_6                    _MK_ADDR_CONST(0x118)
#define HSP_INT_IE_6_SECURE                     0x0
#define HSP_INT_IE_6_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_6_WORD_COUNT                         0x1
#define HSP_INT_IE_6_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_6_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_6_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_6_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_6_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_6_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_6_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_6_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_6_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_6_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_6_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_6_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_6_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_6_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_6_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_6_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_6_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_6_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_6_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_6_dbell_enable_SHIFT)
#define HSP_INT_IE_6_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_6_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_6_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_6_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_6_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_6_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_6_mbox_full_enable_SHIFT)
#define HSP_INT_IE_6_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_6_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_6_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_6_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_6_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_6_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_6_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_6_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_6_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_6_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_6_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_6_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IE_7
#define HSP_INT_IE_7                    _MK_ADDR_CONST(0x11c)
#define HSP_INT_IE_7_SECURE                     0x0
#define HSP_INT_IE_7_SCR                        SCR_C0_REG_0
#define HSP_INT_IE_7_WORD_COUNT                         0x1
#define HSP_INT_IE_7_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_7_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_7_WRITE_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IE_7_smp1_gnt_enable_SHIFT                      _MK_SHIFT_CONST(28)
#define HSP_INT_IE_7_smp1_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_7_smp1_gnt_enable_SHIFT)
#define HSP_INT_IE_7_smp1_gnt_enable_RANGE                      31:28
#define HSP_INT_IE_7_smp1_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_7_smp1_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_smp1_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_7_smp1_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_smp1_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_7_smp0_gnt_enable_SHIFT                      _MK_SHIFT_CONST(24)
#define HSP_INT_IE_7_smp0_gnt_enable_FIELD                      _MK_FIELD_CONST(0xf, HSP_INT_IE_7_smp0_gnt_enable_SHIFT)
#define HSP_INT_IE_7_smp0_gnt_enable_RANGE                      27:24
#define HSP_INT_IE_7_smp0_gnt_enable_WOFFSET                    0x0
#define HSP_INT_IE_7_smp0_gnt_enable_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_smp0_gnt_enable_DEFAULT_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_IE_7_smp0_gnt_enable_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_smp0_gnt_enable_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)

#define HSP_INT_IE_7_dbell_enable_SHIFT                 _MK_SHIFT_CONST(16)
#define HSP_INT_IE_7_dbell_enable_FIELD                 _MK_FIELD_CONST(0xff, HSP_INT_IE_7_dbell_enable_SHIFT)
#define HSP_INT_IE_7_dbell_enable_RANGE                 23:16
#define HSP_INT_IE_7_dbell_enable_WOFFSET                       0x0
#define HSP_INT_IE_7_dbell_enable_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_dbell_enable_DEFAULT_MASK                  _MK_MASK_CONST(0xff)
#define HSP_INT_IE_7_dbell_enable_SW_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_dbell_enable_SW_DEFAULT_MASK                       _MK_MASK_CONST(0x0)

#define HSP_INT_IE_7_mbox_full_enable_SHIFT                     _MK_SHIFT_CONST(8)
#define HSP_INT_IE_7_mbox_full_enable_FIELD                     _MK_FIELD_CONST(0xff, HSP_INT_IE_7_mbox_full_enable_SHIFT)
#define HSP_INT_IE_7_mbox_full_enable_RANGE                     15:8
#define HSP_INT_IE_7_mbox_full_enable_WOFFSET                   0x0
#define HSP_INT_IE_7_mbox_full_enable_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_mbox_full_enable_DEFAULT_MASK                      _MK_MASK_CONST(0xff)
#define HSP_INT_IE_7_mbox_full_enable_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_mbox_full_enable_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)

#define HSP_INT_IE_7_mbox_empty_enable_SHIFT                    _MK_SHIFT_CONST(0)
#define HSP_INT_IE_7_mbox_empty_enable_FIELD                    _MK_FIELD_CONST(0xff, HSP_INT_IE_7_mbox_empty_enable_SHIFT)
#define HSP_INT_IE_7_mbox_empty_enable_RANGE                    7:0
#define HSP_INT_IE_7_mbox_empty_enable_WOFFSET                  0x0
#define HSP_INT_IE_7_mbox_empty_enable_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_mbox_empty_enable_DEFAULT_MASK                     _MK_MASK_CONST(0xff)
#define HSP_INT_IE_7_mbox_empty_enable_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IE_7_mbox_empty_enable_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)


// Register HSP_INT_IV_0
#define HSP_INT_IV_0                    _MK_ADDR_CONST(0x300)
#define HSP_INT_IV_0_SECURE                     0x0
#define HSP_INT_IV_0_SCR                        SCR_C0_REG_0
#define HSP_INT_IV_0_WORD_COUNT                         0x1
#define HSP_INT_IV_0_RESET_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IV_0_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IV_0_WRITE_MASK                         _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_Valid_SHIFT                        _MK_SHIFT_CONST(0)
#define HSP_INT_IV_0_Valid_FIELD                        _MK_FIELD_CONST(0xffffffff, HSP_INT_IV_0_Valid_SHIFT)
#define HSP_INT_IV_0_Valid_RANGE                        31:0
#define HSP_INT_IV_0_Valid_WOFFSET                      0x0
#define HSP_INT_IV_0_Valid_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_Valid_DEFAULT_MASK                 _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IV_0_Valid_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_IV_0_Valid_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)


// Register HSP_INT_IR_0
#define HSP_INT_IR_0                    _MK_ADDR_CONST(0x304)
#define HSP_INT_IR_0_SECURE                     0x0
#define HSP_INT_IR_0_SCR                        SCR_C0_REG_0
#define HSP_INT_IR_0_WORD_COUNT                         0x1
#define HSP_INT_IR_0_RESET_VAL                  _MK_MASK_CONST(0xff)
#define HSP_INT_IR_0_RESET_MASK                         _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IR_0_SW_DEFAULT_VAL                     _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_READ_MASK                  _MK_MASK_CONST(0xffffffff)
#define HSP_INT_IR_0_WRITE_MASK                         _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_smp1_gnt_asserted_SHIFT                    _MK_SHIFT_CONST(28)
#define HSP_INT_IR_0_smp1_gnt_asserted_FIELD                    _MK_FIELD_CONST(0xf, HSP_INT_IR_0_smp1_gnt_asserted_SHIFT)
#define HSP_INT_IR_0_smp1_gnt_asserted_RANGE                    31:28
#define HSP_INT_IR_0_smp1_gnt_asserted_WOFFSET                  0x0
#define HSP_INT_IR_0_smp1_gnt_asserted_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_smp1_gnt_asserted_DEFAULT_MASK                     _MK_MASK_CONST(0xf)
#define HSP_INT_IR_0_smp1_gnt_asserted_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_smp1_gnt_asserted_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)

#define HSP_INT_IR_0_smp0_gnt_asserted_SHIFT                    _MK_SHIFT_CONST(24)
#define HSP_INT_IR_0_smp0_gnt_asserted_FIELD                    _MK_FIELD_CONST(0xf, HSP_INT_IR_0_smp0_gnt_asserted_SHIFT)
#define HSP_INT_IR_0_smp0_gnt_asserted_RANGE                    27:24
#define HSP_INT_IR_0_smp0_gnt_asserted_WOFFSET                  0x0
#define HSP_INT_IR_0_smp0_gnt_asserted_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_smp0_gnt_asserted_DEFAULT_MASK                     _MK_MASK_CONST(0xf)
#define HSP_INT_IR_0_smp0_gnt_asserted_SW_DEFAULT                       _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_smp0_gnt_asserted_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)

#define HSP_INT_IR_0_dbell_asserted_SHIFT                       _MK_SHIFT_CONST(16)
#define HSP_INT_IR_0_dbell_asserted_FIELD                       _MK_FIELD_CONST(0xff, HSP_INT_IR_0_dbell_asserted_SHIFT)
#define HSP_INT_IR_0_dbell_asserted_RANGE                       23:16
#define HSP_INT_IR_0_dbell_asserted_WOFFSET                     0x0
#define HSP_INT_IR_0_dbell_asserted_DEFAULT                     _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_dbell_asserted_DEFAULT_MASK                        _MK_MASK_CONST(0xff)
#define HSP_INT_IR_0_dbell_asserted_SW_DEFAULT                  _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_dbell_asserted_SW_DEFAULT_MASK                     _MK_MASK_CONST(0x0)

#define HSP_INT_IR_0_mbox_full_asserted_SHIFT                   _MK_SHIFT_CONST(8)
#define HSP_INT_IR_0_mbox_full_asserted_FIELD                   _MK_FIELD_CONST(0xff, HSP_INT_IR_0_mbox_full_asserted_SHIFT)
#define HSP_INT_IR_0_mbox_full_asserted_RANGE                   15:8
#define HSP_INT_IR_0_mbox_full_asserted_WOFFSET                 0x0
#define HSP_INT_IR_0_mbox_full_asserted_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_mbox_full_asserted_DEFAULT_MASK                    _MK_MASK_CONST(0xff)
#define HSP_INT_IR_0_mbox_full_asserted_SW_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_mbox_full_asserted_SW_DEFAULT_MASK                 _MK_MASK_CONST(0x0)

#define HSP_INT_IR_0_mbox_empty_asserted_SHIFT                  _MK_SHIFT_CONST(0)
#define HSP_INT_IR_0_mbox_empty_asserted_FIELD                  _MK_FIELD_CONST(0xff, HSP_INT_IR_0_mbox_empty_asserted_SHIFT)
#define HSP_INT_IR_0_mbox_empty_asserted_RANGE                  7:0
#define HSP_INT_IR_0_mbox_empty_asserted_WOFFSET                        0x0
#define HSP_INT_IR_0_mbox_empty_asserted_DEFAULT                        _MK_MASK_CONST(0xff)
#define HSP_INT_IR_0_mbox_empty_asserted_DEFAULT_MASK                   _MK_MASK_CONST(0xff)
#define HSP_INT_IR_0_mbox_empty_asserted_SW_DEFAULT                     _MK_MASK_CONST(0x0)
#define HSP_INT_IR_0_mbox_empty_asserted_SW_DEFAULT_MASK                        _MK_MASK_CONST(0x0)


// Register HSP_INT_SPARE_0
#define HSP_INT_SPARE_0                 _MK_ADDR_CONST(0x308)
#define HSP_INT_SPARE_0_SECURE                  0x0
#define HSP_INT_SPARE_0_SCR                     0
#define HSP_INT_SPARE_0_WORD_COUNT                      0x1
#define HSP_INT_SPARE_0_RESET_VAL                       _MK_MASK_CONST(0x0)
#define HSP_INT_SPARE_0_RESET_MASK                      _MK_MASK_CONST(0xf)
#define HSP_INT_SPARE_0_SW_DEFAULT_VAL                  _MK_MASK_CONST(0x0)
#define HSP_INT_SPARE_0_SW_DEFAULT_MASK                         _MK_MASK_CONST(0x0)
#define HSP_INT_SPARE_0_READ_MASK                       _MK_MASK_CONST(0xf)
#define HSP_INT_SPARE_0_WRITE_MASK                      _MK_MASK_CONST(0xf)
#define HSP_INT_SPARE_0_spare_SHIFT                     _MK_SHIFT_CONST(0)
#define HSP_INT_SPARE_0_spare_FIELD                     _MK_FIELD_CONST(0xf, HSP_INT_SPARE_0_spare_SHIFT)
#define HSP_INT_SPARE_0_spare_RANGE                     3:0
#define HSP_INT_SPARE_0_spare_WOFFSET                   0x0
#define HSP_INT_SPARE_0_spare_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_SPARE_0_spare_DEFAULT_MASK                      _MK_MASK_CONST(0xf)
#define HSP_INT_SPARE_0_spare_SW_DEFAULT                        _MK_MASK_CONST(0x0)
#define HSP_INT_SPARE_0_spare_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)


// Register HSP_INT_HSP_CLK_OVR_0
#define HSP_INT_HSP_CLK_OVR_0                   _MK_ADDR_CONST(0x30c)
#define HSP_INT_HSP_CLK_OVR_0_SECURE                    0x0
#define HSP_INT_HSP_CLK_OVR_0_SCR                       0
#define HSP_INT_HSP_CLK_OVR_0_WORD_COUNT                        0x1
#define HSP_INT_HSP_CLK_OVR_0_RESET_VAL                         _MK_MASK_CONST(0x0)
#define HSP_INT_HSP_CLK_OVR_0_RESET_MASK                        _MK_MASK_CONST(0x1)
#define HSP_INT_HSP_CLK_OVR_0_SW_DEFAULT_VAL                    _MK_MASK_CONST(0x0)
#define HSP_INT_HSP_CLK_OVR_0_SW_DEFAULT_MASK                   _MK_MASK_CONST(0x0)
#define HSP_INT_HSP_CLK_OVR_0_READ_MASK                         _MK_MASK_CONST(0x1)
#define HSP_INT_HSP_CLK_OVR_0_WRITE_MASK                        _MK_MASK_CONST(0x1)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_SHIFT                      _MK_SHIFT_CONST(0)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_FIELD                      _MK_FIELD_CONST(0x1, HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_SHIFT)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_RANGE                      0:0
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_WOFFSET                    0x0
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_DEFAULT                    _MK_MASK_CONST(0x0)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_DEFAULT_MASK                       _MK_MASK_CONST(0x1)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_SW_DEFAULT                 _MK_MASK_CONST(0x0)
#define HSP_INT_HSP_CLK_OVR_0_hsp_clk_ovr_on_SW_DEFAULT_MASK                    _MK_MASK_CONST(0x0)


// Register HSP_INT_DIMENSIONING_0
#define HSP_INT_DIMENSIONING_0                  _MK_ADDR_CONST(0x380)
#define HSP_INT_DIMENSIONING_0_SECURE                   0x0
#define HSP_INT_DIMENSIONING_0_SCR                      0
#define HSP_INT_DIMENSIONING_0_WORD_COUNT                       0x1
#define HSP_INT_DIMENSIONING_0_RESET_VAL                        _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_RESET_MASK                       _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_SW_DEFAULT_VAL                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_SW_DEFAULT_MASK                  _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_READ_MASK                        _MK_MASK_CONST(0xfffff)
#define HSP_INT_DIMENSIONING_0_WRITE_MASK                       _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSI_SHIFT                        _MK_SHIFT_CONST(16)
#define HSP_INT_DIMENSIONING_0_nSI_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_DIMENSIONING_0_nSI_SHIFT)
#define HSP_INT_DIMENSIONING_0_nSI_RANGE                        19:16
#define HSP_INT_DIMENSIONING_0_nSI_WOFFSET                      0x0
#define HSP_INT_DIMENSIONING_0_nSI_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSI_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSI_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSI_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_DIMENSIONING_0_nDB_SHIFT                        _MK_SHIFT_CONST(12)
#define HSP_INT_DIMENSIONING_0_nDB_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_DIMENSIONING_0_nDB_SHIFT)
#define HSP_INT_DIMENSIONING_0_nDB_RANGE                        15:12
#define HSP_INT_DIMENSIONING_0_nDB_WOFFSET                      0x0
#define HSP_INT_DIMENSIONING_0_nDB_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nDB_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nDB_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nDB_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_DIMENSIONING_0_nAS_SHIFT                        _MK_SHIFT_CONST(8)
#define HSP_INT_DIMENSIONING_0_nAS_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_DIMENSIONING_0_nAS_SHIFT)
#define HSP_INT_DIMENSIONING_0_nAS_RANGE                        11:8
#define HSP_INT_DIMENSIONING_0_nAS_WOFFSET                      0x0
#define HSP_INT_DIMENSIONING_0_nAS_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nAS_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nAS_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nAS_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_DIMENSIONING_0_nSS_SHIFT                        _MK_SHIFT_CONST(4)
#define HSP_INT_DIMENSIONING_0_nSS_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_DIMENSIONING_0_nSS_SHIFT)
#define HSP_INT_DIMENSIONING_0_nSS_RANGE                        7:4
#define HSP_INT_DIMENSIONING_0_nSS_WOFFSET                      0x0
#define HSP_INT_DIMENSIONING_0_nSS_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSS_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSS_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSS_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)

#define HSP_INT_DIMENSIONING_0_nSM_SHIFT                        _MK_SHIFT_CONST(0)
#define HSP_INT_DIMENSIONING_0_nSM_FIELD                        _MK_FIELD_CONST(0xf, HSP_INT_DIMENSIONING_0_nSM_SHIFT)
#define HSP_INT_DIMENSIONING_0_nSM_RANGE                        3:0
#define HSP_INT_DIMENSIONING_0_nSM_WOFFSET                      0x0
#define HSP_INT_DIMENSIONING_0_nSM_DEFAULT                      _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSM_DEFAULT_MASK                 _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSM_SW_DEFAULT                   _MK_MASK_CONST(0x0)
#define HSP_INT_DIMENSIONING_0_nSM_SW_DEFAULT_MASK                      _MK_MASK_CONST(0x0)


//
// REGISTER LIST
//
#define LIST_ARHSP_INT_REGS(_op_) \
_op_(HSP_INT_IE_0) \
_op_(HSP_INT_IE) \
_op_(HSP_INT_IE_1) \
_op_(HSP_INT_IE_2) \
_op_(HSP_INT_IE_3) \
_op_(HSP_INT_IE_4) \
_op_(HSP_INT_IE_5) \
_op_(HSP_INT_IE_6) \
_op_(HSP_INT_IE_7) \
_op_(HSP_INT_IV_0) \
_op_(HSP_INT_IR_0) \
_op_(HSP_INT_SPARE_0) \
_op_(HSP_INT_HSP_CLK_OVR_0) \
_op_(HSP_INT_DIMENSIONING_0)


//
// ADDRESS SPACES
//

#define BASE_ADDRESS_HSP_INT    0x00000100

//
// ARHSP_INT REGISTER BANKS
//

#define HSP_INT0_FIRST_REG 0x0100 // HSP_INT_IE_0
#define HSP_INT0_LAST_REG 0x011c // HSP_INT_IE_7
#define HSP_INT1_FIRST_REG 0x0300 // HSP_INT_IV_0
#define HSP_INT1_LAST_REG 0x030c // HSP_INT_HSP_CLK_OVR_0
#define HSP_INT2_FIRST_REG 0x0380 // HSP_INT_DIMENSIONING_0
#define HSP_INT2_LAST_REG 0x0380 // HSP_INT_DIMENSIONING_0

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

#endif // ifndef ___ARHSP_INT_H_INC_
