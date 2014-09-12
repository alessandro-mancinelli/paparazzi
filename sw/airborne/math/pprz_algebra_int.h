/*
 * Copyright (C) 2008-2014 The Paparazzi Team
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file pprz_algebra_int.h
 * @brief Paparazzi fixed point algebra.
 *
 */

#ifndef PPRZ_ALGEBRA_INT_H
#define PPRZ_ALGEBRA_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "std.h"
#include "math/pprz_algebra.h"
#include "math/pprz_trig_int.h"
#include <stdlib.h>


struct Uint8Vect3 {
  uint8_t x;
  uint8_t y;
  uint8_t z;
};

struct Int8Vect3 {
  int8_t x;
  int8_t y;
  int8_t z;
};

struct Uint16Vect3 {
  uint16_t x;
  uint16_t y;
  uint16_t z;
};

struct Int16Vect3 {
  int16_t x;
  int16_t y;
  int16_t z;
};

#define INT32_POS_FRAC 8
#define INT32_POS_OF_CM 2.56
#define INT32_POS_OF_CM_NUM 64
#define INT32_POS_OF_CM_DEN 25

#define INT32_SPEED_FRAC 19
#define INT32_SPEED_OF_CM_S 5242.88
#define INT32_SPEED_OF_CM_S_NUM 41943
#define INT32_SPEED_OF_CM_S_DEN 8

#define INT32_ACCEL_FRAC 10
#define INT32_MAG_FRAC 11

#define INT32_PERCENTAGE_FRAC 10

struct Int32Vect2 {
  int32_t x;
  int32_t y;
};

struct Int32Vect3 {
  int32_t x;
  int32_t y;
  int32_t z;
};

/* Rotation quaternions                         */
#define INT32_QUAT_FRAC 15
/**
 * @brief Rotation quaternion
 * @details Units: BFP with #INT32_QUAT_FRAC */
struct Int32Quat {
  int32_t qi;
  int32_t qx;
  int32_t qy;
  int32_t qz;
};


struct Int64Quat {
  int64_t qi;
  int64_t qx;
  int64_t qy;
  int64_t qz;
};


/* Euler angles                                 */
#define INT32_ANGLE_FRAC 12
#define INT32_RATE_FRAC 12
#define INT32_ANGLE_PI_4   (int32_t)ANGLE_BFP_OF_REAL(   0.7853981633974483096156608458198757)
#define INT32_ANGLE_PI_2   (int32_t)ANGLE_BFP_OF_REAL(   1.5707963267948966192313216916397514)
#define INT32_ANGLE_PI     (int32_t)ANGLE_BFP_OF_REAL(   3.1415926535897932384626433832795029)
#define INT32_ANGLE_2_PI   (int32_t)ANGLE_BFP_OF_REAL(2.*3.1415926535897932384626433832795029)

#define INT32_RAD_OF_DEG(_deg) (int32_t)(((int64_t)(_deg) * 14964008)/857374503)
#define INT32_DEG_OF_RAD(_rad) (int32_t)(((int64_t)(_rad) * 857374503)/14964008)

#define INT32_ANGLE_NORMALIZE(_a) {             \
    while ((_a) > INT32_ANGLE_PI)  (_a) -= INT32_ANGLE_2_PI;    \
    while ((_a) < -INT32_ANGLE_PI) (_a) += INT32_ANGLE_2_PI;    \
  }

#define INT32_COURSE_NORMALIZE(_a) {                \
    while ((_a) < 0) (_a) += INT32_ANGLE_2_PI;                  \
    while ((_a) >= INT32_ANGLE_2_PI)  (_a) -= INT32_ANGLE_2_PI; \
  }


struct Int16Eulers {
  int16_t phi;
  int16_t theta;
  int16_t psi;
};

/**
 * @brief euler angles
 * @details Units: rad in BFP with #INT32_ANGLE_FRAC */
struct Int32Eulers {
  int32_t phi;   ///< in rad with #INT32_ANGLE_FRAC
  int32_t theta; ///< in rad with #INT32_ANGLE_FRAC
  int32_t psi;   ///< in rad with #INT32_ANGLE_FRAC
};


/* Rotation matrix. */
#define INT32_TRIG_FRAC 14

/**
 * @brief rotation matrix
 * @details Units: rad in BFP with #INT32_TRIG_FRAC */
struct Int32RMat {
  int32_t m[3 * 3];
};

/* 3x3 matrix                                    */
struct Int32Mat33 {
  int32_t m[3 * 3];
};

/* Rotational speed                              */
struct Int16Rates {
  int16_t p;
  int16_t q;
  int16_t r;
};

/* Rotational speed                              */
/**
 * @brief angular rates
 * @details Units: rad/s in BFP with #INT32_RATE_FRAC */
struct Int32Rates {
  int32_t p; ///< in rad/s with #INT32_RATE_FRAC
  int32_t q; ///< in rad/s with #INT32_RATE_FRAC
  int32_t r; ///< in rad/s with #INT32_RATE_FRAC
};

struct Int64Rates {
  int64_t p;
  int64_t q;
  int64_t r;
};


struct Int64Vect2 {
  int64_t x;
  int64_t y;
};

struct Int64Vect3 {
  int64_t x;
  int64_t y;
  int64_t z;
};


// Real (floating point) ->  Binary Fixed Point  (int)
#define BFP_OF_REAL(_vr, _frac)    ((_vr)*(1<<(_frac)))
#define FLOAT_OF_BFP(_vbfp, _frac) ((float)(_vbfp)/(1<<(_frac)))
#define DOUBLE_OF_BFP(_vbfp, _frac) ((double)(_vbfp)/(1<<(_frac)))
#define RATE_BFP_OF_REAL(_af)   BFP_OF_REAL((_af), INT32_RATE_FRAC)
#define RATE_FLOAT_OF_BFP(_ai)  FLOAT_OF_BFP((_ai), INT32_RATE_FRAC)
#define ANGLE_BFP_OF_REAL(_af)  BFP_OF_REAL((_af), INT32_ANGLE_FRAC)
#define ANGLE_FLOAT_OF_BFP(_ai) FLOAT_OF_BFP((_ai), INT32_ANGLE_FRAC)
#define QUAT1_BFP_OF_REAL(_qf)  BFP_OF_REAL((_qf), INT32_QUAT_FRAC)
#define QUAT1_FLOAT_OF_BFP(_qi) FLOAT_OF_BFP((_qi), INT32_QUAT_FRAC)
#define TRIG_BFP_OF_REAL(_tf)   BFP_OF_REAL((_tf), INT32_TRIG_FRAC)
#define TRIG_FLOAT_OF_BFP(_ti)  FLOAT_OF_BFP((_ti),INT32_TRIG_FRAC)
#define POS_BFP_OF_REAL(_af)    BFP_OF_REAL((_af), INT32_POS_FRAC)
#define POS_FLOAT_OF_BFP(_ai)   FLOAT_OF_BFP((_ai), INT32_POS_FRAC)
#define SPEED_BFP_OF_REAL(_af)  BFP_OF_REAL((_af), INT32_SPEED_FRAC)
#define SPEED_FLOAT_OF_BFP(_ai) FLOAT_OF_BFP((_ai), INT32_SPEED_FRAC)
#define ACCEL_BFP_OF_REAL(_af)  BFP_OF_REAL((_af), INT32_ACCEL_FRAC)
#define ACCEL_FLOAT_OF_BFP(_ai) FLOAT_OF_BFP((_ai), INT32_ACCEL_FRAC)
#define MAG_BFP_OF_REAL(_af)    BFP_OF_REAL((_af), INT32_MAG_FRAC)
#define MAG_FLOAT_OF_BFP(_ai)   FLOAT_OF_BFP((_ai), INT32_MAG_FRAC)

#define INT_MULT_RSHIFT(_a, _b, _r) (((_a)*(_b))>>(_r))


extern int32_t int32_sqrt(int32_t in);
#define INT32_SQRT(_out,_in) { _out = int32_sqrt(_in); }


/*
 * Dimension 2 Vectors
 */

#define INT_VECT2_ZERO(_v) VECT2_ASSIGN(_v, 0, 0)

/* macros also usable if _v is not a Int32Vect2, but a different struct with x,y members */
#define INT32_VECT2_NORM(_v) int32_sqrt(VECT2_NORM2(_v))

static inline uint32_t int32_vect2_norm2(struct Int32Vect2* v)
{
  return v->x * v->x + v->y * v->y;
}

static inline uint32_t int32_vect2_norm(struct Int32Vect2* v)
{
  return int32_sqrt(int32_vect2_norm2(v));
}

static inline void int32_vect2_normalize(struct Int32Vect2* v, uint8_t frac)
{
  const uint32_t f = BFP_OF_REAL((1.), frac);
  const uint32_t n = int32_vect2_norm(v);
  if (n > 0) {
    v->x = v->x * f / n;
    v->y = v->y * f / n;
  }
}

#define INT32_VECT2_NORMALIZE(_v,_frac) int32_vect2_normalize(&(_v), _frac)


#define INT32_VECT2_RSHIFT(_o, _i, _r) { \
    (_o).x = ((_i).x >> (_r)); \
    (_o).y = ((_i).y >> (_r)); \
  }

#define INT32_VECT2_LSHIFT(_o, _i, _l) { \
    (_o).x = ((_i).x << (_l)); \
    (_o).y = ((_i).y << (_l)); \
  }

#define INT32_VECT2_SCALE_2(_a, _b, _num, _den) {   \
    (_a).x = ((_b).x * (_num)) / (_den);        \
    (_a).y = ((_b).y * (_num)) / (_den);        \
  }

/*
 * Dimension 3 Vectors
 */

#define INT_VECT3_ZERO(_v) VECT3_ASSIGN(_v, 0, 0, 0)
#define INT32_VECT3_ZERO(_v) VECT3_ASSIGN(_v, 0, 0, 0)

#define INT32_VECT3_SCALE_2(_a, _b, _num, _den) {   \
    (_a).x = ((_b).x * (_num)) / (_den);        \
    (_a).y = ((_b).y * (_num)) / (_den);        \
    (_a).z = ((_b).z * (_num)) / (_den);        \
  }

#define INT32_VECT3_NORM(_v) int32_sqrt(VECT3_NORM2(_v))

#define INT32_VECT3_RSHIFT(_o, _i, _r) { \
    (_o).x = ((_i).x >> (_r));       \
    (_o).y = ((_i).y >> (_r));       \
    (_o).z = ((_i).z >> (_r));       \
  }

#define INT32_VECT3_LSHIFT(_o, _i, _l) { \
    (_o).x = ((_i).x << (_l));       \
    (_o).y = ((_i).y << (_l));       \
    (_o).z = ((_i).z << (_l));       \
  }



/*
 * 3x3 Matrices
 */
#define INT32_MAT33_ZERO(_m) {                      \
    MAT33_ELMT((_m), 0, 0) = 0;                     \
    MAT33_ELMT((_m), 0, 1) = 0;                     \
    MAT33_ELMT((_m), 0, 2) = 0;                     \
    MAT33_ELMT((_m), 1, 0) = 0;                     \
    MAT33_ELMT((_m), 1, 1) = 0;                     \
    MAT33_ELMT((_m), 1, 2) = 0;                     \
    MAT33_ELMT((_m), 2, 0) = 0;                     \
    MAT33_ELMT((_m), 2, 1) = 0;                     \
    MAT33_ELMT((_m), 2, 2) = 0;                     \
  }

#define INT32_MAT33_DIAG(_m, _d00, _d11, _d22) {    \
    MAT33_ELMT((_m), 0, 0) = (_d00);                \
    MAT33_ELMT((_m), 0, 1) = 0;                     \
    MAT33_ELMT((_m), 0, 2) = 0;                     \
    MAT33_ELMT((_m), 1, 0) = 0;                     \
    MAT33_ELMT((_m), 1, 1) = (_d11);                \
    MAT33_ELMT((_m), 1, 2) = 0;                     \
    MAT33_ELMT((_m), 2, 0) = 0;                     \
    MAT33_ELMT((_m), 2, 1) = 0;                     \
    MAT33_ELMT((_m), 2, 2) = (_d22);                \
  }



/*
 * Rotation matrices
 */

/** initialises a rotation matrix to identity */
static inline void int32_rmat_identity(struct Int32RMat* rm)
{
  INT32_MAT33_DIAG(*rm, TRIG_BFP_OF_REAL(1.), TRIG_BFP_OF_REAL(1.), TRIG_BFP_OF_REAL(1.));
}

/* _m_a2c = _m_a2b comp _m_b2c , aka  _m_a2c = _m_b2c * _m_a2b */
extern void int32_rmat_comp(struct Int32RMat* m_a2c, struct Int32RMat* m_a2b, struct Int32RMat* m_b2c);

/* _m_a2b = _m_a2c comp_inv _m_b2c , aka  _m_a2b = inv(_m_b2c) * _m_a2c */
extern void int32_rmat_comp_inv(struct Int32RMat* m_a2b, struct Int32RMat* m_a2c, struct Int32RMat* m_b2c);

/* vb = m_a2b * va */
extern void int32_rmat_vmult(struct Int32Vect3* vb, struct Int32RMat* m_a2b, struct Int32Vect3* va);

/* vb = m_b2a * va */
extern void int32_rmat_transp_vmult(struct Int32Vect3* vb, struct Int32RMat* m_b2a, struct Int32Vect3* va);

extern void int32_rmat_ratemult(struct Int32Rates* rb, struct Int32RMat* m_a2b, struct Int32Rates* ra);
extern void int32_rmat_transp_ratemult(struct Int32Rates* rb, struct Int32RMat* m_b2a, struct Int32Rates* ra);

/** Convert unit quaternion to rotation matrix.
 * http://www.mathworks.com/access/helpdesk_r13/help/toolbox/aeroblks/quaternionstodirectioncosinematrix.html
 */
extern void int32_rmat_of_quat(struct Int32RMat* rm, struct Int32Quat* q);

/*
 * http://www.mathworks.com/access/helpdesk_r13/help/toolbox/aeroblks/euleranglestodirectioncosinematrix.html
 */
extern void int32_rmat_of_eulers_321(struct Int32RMat* rm, struct Int32Eulers* e);
extern void int32_rmat_of_eulers_312(struct Int32RMat* rm, struct Int32Eulers* e);

#define int32_rmat_of_eulers int32_rmat_of_eulers_321

/* defines for backwards compatibility */
#define INT32_RMAT_COMP(_m_a2c, _m_a2b, _m_b2c) int32_rmat_comp(&(_m_a2c), &(_m_a2b), &(_m_b2c))
#define INT32_RMAT_COMP_INV(_m_a2b, _m_a2c, _m_b2c) int32_rmat_comp_inv(&(_m_a2b), &(_m_a2c), &(_m_b2c))
#define INT32_RMAT_VMULT(_vb, _m_a2b, _va) int32_rmat_vmult(&(_vb), &(_m_a2b), &(_va))
#define INT32_RMAT_TRANSP_VMULT(_vb, _m_b2a, _va) int32_rmat_transp_vmult(&(_vb), &(_m_b2a), &(_va))
#define INT32_RMAT_RATEMULT(_rb, _m_a2b, _ra) int32_rmat_ratemult(&(_rb), &(_m_a2b), &(_ra))
#define INT32_RMAT_TRANSP_RATEMULT(_rb, _m_b2a, _ra) int32_rmat_ratemult(&(_rb), &(_m_b2a), &(_ra))

#define INT32_RMAT_OF_QUAT(_rm, _q) int32_rmat_of_quat(&(_rm), &(_q))
#define INT32_RMAT_OF_EULERS(_rm, _e) int32_rmat_of_eulers_321(&(_rm), &(_e))
#define INT32_RMAT_OF_EULERS_321(_rm, _e) int32_rmat_of_eulers_321(&(_rm), &(_e))
#define INT32_RMAT_OF_EULERS_312(_rm, _e) int32_rmat_of_eulers_312(&(_rm), &(_e))


/*
 *
 * Quaternions
 *
 */

/** initialises a quaternion to identity */
static inline void int32_quat_identity(struct Int32Quat* q)
{
  q->qi = QUAT1_BFP_OF_REAL(1);
  q->qx = 0;
  q->qy = 0;
  q->qz = 0;
}

static inline int32_t int32_quat_norm(struct Int32Quat* q)
{
  int32_t n2 = q->qi * q->qi + q->qx * q->qx + q->qy * q->qy + q->qz * q->qz;
  return int32_sqrt(n2);
}

static inline void int32_quat_wrap_shortest(struct Int32Quat* q)
{
  if (q->qi < 0) {
    QUAT_EXPLEMENTARY(*q, *q);
  }
}

static inline void int32_quat_normalize(struct Int32Quat* q)
{
  int32_t n = int32_quat_norm(q);
  if (n > 0) {
    q->qi = q->qi * QUAT1_BFP_OF_REAL(1) / n;
    q->qx = q->qx * QUAT1_BFP_OF_REAL(1) / n;
    q->qy = q->qy * QUAT1_BFP_OF_REAL(1) / n;
    q->qz = q->qz * QUAT1_BFP_OF_REAL(1) / n;
  }
}

/* _a2c = _a2b comp _b2c , aka  _a2c = _a2b * _b2c */
extern void int32_quat_comp(struct Int32Quat* a2c, struct Int32Quat* a2b, struct Int32Quat* b2c);

/* _a2b = _a2c comp_inv _b2c , aka  _a2b = _a2c * inv(_b2c) */
extern void int32_quat_comp_inv(struct Int32Quat* a2b, struct Int32Quat* a2c, struct Int32Quat* b2c);

/* _b2c = _a2b inv_comp _a2c , aka  _b2c = inv(_a2b) * _a2c */
extern void int32_quat_inv_comp(struct Int32Quat* b2c, struct Int32Quat* a2b, struct Int32Quat* a2c);

/* _a2c = _a2b comp _b2c , aka  _a2c = _a2b * _b2c */
extern void int32_quat_comp_norm_shortest(struct Int32Quat* a2c, struct Int32Quat* a2b, struct Int32Quat* b2c);

/* _a2b = _a2c comp_inv _b2c , aka  _a2b = _a2c * inv(_b2c) */
extern void int32_quat_comp_inv_norm_shortest(struct Int32Quat* a2b, struct Int32Quat* a2c, struct Int32Quat* b2c);

/* _b2c = _a2b inv_comp _a2c , aka  _b2c = inv(_a2b) * _a2c */
extern void int32_quat_inv_comp_norm_shortest(struct Int32Quat* b2c, struct Int32Quat* a2b, struct Int32Quat* a2c);

/** Quaternion derivative from rotational velocity.
 * qd = -0.5*omega(r) * q
 * mult with 0.5 is done by shifting one more bit to the right
 */
extern void int32_quat_derivative(struct Int32Quat* qd, const struct Int32Rates* r, struct Int32Quat* q);

/** in place quaternion first order integration with constant rotational velocity. */
extern void int32_quat_integrate_fi(struct Int32Quat* q, struct Int64Quat* hr, struct Int32Rates* omega, int freq);

extern void int32_quat_vmult(struct Int32Vect3* v_out, struct Int32Quat* q, struct Int32Vect3* v_in);
extern void int32_quat_of_eulers(struct Int32Quat* q, struct Int32Eulers* e);
extern void int32_quat_of_axis_angle(struct Int32Quat* q, struct Int32Vect3* uv, int32_t angle);
extern void int32_quat_of_rmat(struct Int32Quat* q, struct Int32RMat* r);

/* defines for backwards compatibility */
#define INT32_QUAT_ZERO(_q) int32_quat_identity(&(_q))
#define INT32_QUAT_NORM(n, q) { n = int32_quat_norm(&(q)); }
#define INT32_QUAT_WRAP_SHORTEST(q) int32_quat_wrap_shortest(&(q))
#define INT32_QUAT_NORMALIZE(q) int32_quat_normalize(&(q))
#define INT32_QUAT_COMP(_a2c, _a2b, _b2c) int32_quat_comp(&(_a2c), &(_a2b), &(_b2c))
#define INT32_QUAT_COMP_INV(_a2b, _a2c, _b2c) int32_quat_comp_inv(&(_a2b), &(_a2c), &(_b2c))
#define INT32_QUAT_INV_COMP(_b2c, _a2b, _a2c) int32_quat_inv_comp(&(_b2c), &(_a2b), &(_a2c))
#define INT32_QUAT_COMP_NORM_SHORTEST(_a2c, _a2b, _b2c) int32_quat_comp_norm_shortest(&(_a2c), &(_a2b), &(_b2c))
#define INT32_QUAT_INV_COMP_NORM_SHORTEST(_b2c, _a2b, _a2c) int32_quat_inv_comp_norm_shortest(&(_b2c), &(_a2b), &(_a2c))
#define INT32_QUAT_DERIVATIVE(_qd, _r, _q) int32_quat_derivative(&(_qd), &(_r), &(_q))
#define INT32_QUAT_INTEGRATE_FI(_q, _hr, _omega, _f) int32_quat_integrate_fi(&(_q), &(_hr), &(_omega), _f)
#define INT32_QUAT_VMULT(v_out, q, v_in) int32_quat_vmult(&(v_out), &(q), &(v_in))
#define INT32_QUAT_OF_EULERS(_q, _e) int32_quat_of_eulers(&(_q), &(_e))
#define INT32_QUAT_OF_AXIS_ANGLE(_q, _uv, _an) int32_quat_of_axis_angle(&(_q), &(_uv), _an)
#define INT32_QUAT_OF_RMAT(_q, _r) int32_quat_of_rmat(&(_q), &(_r))


/*
 *
 * Euler angles
 *
 */

#define INT_EULERS_ZERO(_e) EULERS_ASSIGN(_e, 0, 0, 0)

extern void int32_eulers_of_rmat(struct Int32Eulers* e, struct Int32RMat* rm);
extern void int32_eulers_of_quat(struct Int32Eulers* e, struct Int32Quat* q);

/* defines for backwards compatibility */
#define INT32_EULERS_OF_RMAT(_e, _rm) int32_eulers_of_rmat(&(_e), &(_rm))
#define INT32_EULERS_OF_QUAT(_e, _q) int32_eulers_of_quat(&(_e), &(_q))

#define INT32_EULERS_LSHIFT(_o, _i, _r) {  \
    (_o).phi   = ((_i).phi   << (_r));     \
    (_o).theta = ((_i).theta << (_r));     \
    (_o).psi   = ((_i).psi   << (_r));     \
  }

#define INT32_EULERS_RSHIFT(_o, _i, _r) {  \
    (_o).phi   = ((_i).phi   >> (_r));     \
    (_o).theta = ((_i).theta >> (_r));     \
    (_o).psi   = ((_i).psi   >> (_r));     \
  }


/*
 * Rotational speeds
 */

#define INT_RATES_ZERO(_e) RATES_ASSIGN(_e, 0, 0, 0)

#define INT_RATES_RSHIFT(_o, _i, _r) {   \
    (_o).p = ((_i).p >> (_r));       \
    (_o).q = ((_i).q >> (_r));       \
    (_o).r = ((_i).r >> (_r));       \
  }

#define INT_RATES_LSHIFT(_o, _i, _r) {   \
    (_o).p = ((_i).p << (_r));       \
    (_o).q = ((_i).q << (_r));       \
    (_o).r = ((_i).r << (_r));       \
  }


extern void int32_rates_of_eulers_dot_321(struct Int32Rates* r, struct Int32Eulers* e, struct Int32Eulers* ed);
extern void int32_eulers_dot_321_of_rates(struct Int32Eulers* ed, struct Int32Eulers* e, struct Int32Rates* r);

#define int32_eulers_dot_of_rates int32_eulers_dot_321_of_rates

/* defines for backwards compatibility */
#define INT32_RATES_OF_EULERS_DOT_321(_r, _e, _ed) int32_rates_of_eulers_dot_321(&(_r), &(_e), &(_ed))
#define INT32_RATES_OF_EULERS_DOT(_r, _e, _ed)     int32_rates_of_eulers_dot_321(&(_r), &(_e), &(_ed))
#define INT32_EULERS_DOT_321_OF_RATES(_ed, _e, _r) int32_eulers_dot_321_of_rates(&(_ed), &(_e), &(_r))
#define INT32_EULERS_DOT_OF_RATES(_ed, _e, _r)     int32_eulers_dot_321_of_rates(&(_ed), &(_e), &(_r))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PPRZ_ALGEBRA_INT_H */
