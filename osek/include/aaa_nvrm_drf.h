#ifndef INCLUDED_NVRM_DRF_H
#define INCLUDED_NVRM_DRF_H

#define NV_FIELD_LOWBIT(x)      ((0 != 0)?x)
#define NV_FIELD_HIGHBIT(x)     ((0 == 0)?x)
#define NV_FIELD_SIZE(x)        ((uint32_t)(NV_FIELD_HIGHBIT(x)-NV_FIELD_LOWBIT(x)+1))
#define NV_FIELD_SHIFT(x)       ((uint32_t)((0 != 0)?x)%32U)
#define NV_FIELD_MASK(x)        (0xFFFFFFFFUL>>(31U-((uint32_t)((0 == 0)?x)%32U)+\
                                                        ((uint32_t)((0 != 0)?x)%32U)))
#define NV_FIELD_BITS(val, x)   (((val) & NV_FIELD_MASK(x))<<NV_FIELD_SHIFT(x))
#define NV_FIELD_SHIFTMASK(x)   (NV_FIELD_MASK(x)<< (NV_FIELD_SHIFT(x)))

/*
 * The NV_FIELD64_* macros are helper macros for the public NV_DRF64_* macros.
 */
#define NV_FIELD64_SHIFT(x) ((0?x)%64)
#define NV_FIELD64_MASK(x)  (0xFFFFFFFFFFFFFFFFULL>>(63-((1?x)%64)+((0?x)%64)))


/** NV_DRF_DEF - define a new register value.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
    @param f register field
    @param c defined value for the field
 */
#define NV_DRF_DEF(d,r,f,c) \
    ((uint32_t)(d##_##r##_0_##f##_##c) << NV_FIELD_SHIFT(d##_##r##_0_##f##_RANGE))

/** NV_DRF_NUM - define a new register value.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
    @param f register field
    @param n numeric value for the field
 */
#define NV_DRF_NUM(d,r,f,n) \
    (((uint32_t)(n)& NV_FIELD_MASK(d##_##r##_0_##f##_RANGE)) << \
        NV_FIELD_SHIFT(d##_##r##_0_##f##_RANGE))

/** NV_DRF_VAL - read a field from a register.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
    @param f register field
    @param v register value
 */
#define NV_DRF_VAL(d,r,f,v) \
    (((v)>> NV_FIELD_SHIFT(d##_##r##_0_##f##_RANGE)) & \
        NV_FIELD_MASK(d##_##r##_0_##f##_RANGE))

/** NV_FLD_SET_DRF_NUM - modify a register field.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
    @param f register field
    @param n numeric field value
    @param v register value
 */
#define NV_FLD_SET_DRF_NUM(d,r,f,n,v) \
    ((v & ~NV_FIELD_SHIFTMASK(d##_##r##_0_##f##_RANGE)) | NV_DRF_NUM(d,r,f,n))

/** NV_FLD_SET_DRF_DEF - modify a register field.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
    @param f register field
    @param c defined field value
    @param v register value
 */
#define NV_FLD_SET_DRF_DEF(d,r,f,c,v) \
    (((v) & ~NV_FIELD_SHIFTMASK(d##_##r##_0_##f##_RANGE)) | \
        NV_DRF_DEF(d,r,f,c))

/** NV_RESETVAL - get the reset value for a register.

    @ingroup nvrm_drf

    @param d register domain (hardware block)
    @param r register name
 */
#define NV_RESETVAL(d,r)    (d##_##r##_0_RESET_VAL)


/** NV_DRF64_NUM - define a new 64-bit register value.

    @ingroup nvrm_drf

    @param d register domain
    @param r register name
    @param f register field
    @param n numeric value for the field
 */
#define NV_DRF64_NUM(d,r,f,n) \
    (((n)& NV_FIELD64_MASK(d##_##r##_0_##f##_RANGE)) << \
        NV_FIELD64_SHIFT(d##_##r##_0_##f##_RANGE))

#endif // INCLUDED_NVRM_DRF_H
