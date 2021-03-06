/* x86/k8 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000-2011, 2014 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 32
#define GMP_LIMB_BYTES 4

/* 2500 MHz K8 Brisbane */
/* FFT tuning limit = 67,000,000 */
/* Generated by tuneup.c, 2019-10-20, gcc 8.3 */

#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD         11
#define MOD_1U_TO_MOD_1_1_THRESHOLD          4
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        12
#define MOD_1_2_TO_MOD_1_4_THRESHOLD         0  /* never mpn_mod_1s_2p */
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     21
#define USE_PREINV_DIVREM_1                  1  /* native */
#define DIV_QR_1N_PI1_METHOD                 1  /* 36.85% faster than 2 */
#define DIV_QR_1_NORM_THRESHOLD              3
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           44

#define DIV_1_VS_MUL_1_PERCENT             251

#define MUL_TOOM22_THRESHOLD                26
#define MUL_TOOM33_THRESHOLD                78
#define MUL_TOOM44_THRESHOLD               136
#define MUL_TOOM6H_THRESHOLD               270
#define MUL_TOOM8H_THRESHOLD               430

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      85
#define MUL_TOOM32_TO_TOOM53_THRESHOLD      91
#define MUL_TOOM42_TO_TOOM53_THRESHOLD      89
#define MUL_TOOM42_TO_TOOM63_THRESHOLD      96
#define MUL_TOOM43_TO_TOOM54_THRESHOLD     121

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 46
#define SQR_TOOM3_THRESHOLD                 81
#define SQR_TOOM4_THRESHOLD                202
#define SQR_TOOM6_THRESHOLD                300
#define SQR_TOOM8_THRESHOLD                430

#define MULMID_TOOM42_THRESHOLD             50

#define MULMOD_BNM1_THRESHOLD               18
#define SQRMOD_BNM1_THRESHOLD               22

#define MUL_FFT_MODF_THRESHOLD             606  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    606, 5}, {     27, 6}, {     15, 5}, {     31, 6}, \
    {     25, 7}, {     13, 6}, {     29, 7}, {     15, 6}, \
    {     33, 7}, {     17, 6}, {     35, 7}, {     19, 6}, \
    {     39, 7}, {     23, 6}, {     47, 7}, {     35, 8}, \
    {     19, 7}, {     41, 8}, {     23, 7}, {     47, 8}, \
    {     31, 7}, {     63, 8}, {     39, 9}, {     23, 8}, \
    {     55, 9}, {     31, 8}, {     67, 9}, {     39, 8}, \
    {     79, 9}, {     47, 8}, {     95, 9}, {     55,10}, \
    {     31, 9}, {     79,10}, {     47, 9}, {    103,11}, \
    {     31,10}, {     63, 9}, {    135,10}, {     79, 9}, \
    {    167,10}, {     95, 9}, {    191,10}, {    111,11}, \
    {     63,10}, {    159,11}, {     95,10}, {    191,12}, \
    {     63,11}, {    127,10}, {    255, 9}, {    511,10}, \
    {    271, 9}, {    543,10}, {    287,11}, {    159,10}, \
    {    319, 9}, {    639,10}, {    335, 9}, {    671,11}, \
    {    191,10}, {    383, 9}, {    767,10}, {    399, 9}, \
    {    799,11}, {    223,12}, {    127,11}, {    255,10}, \
    {    511, 9}, {   1023,10}, {    543,11}, {    287,10}, \
    {    607,11}, {    319,10}, {    671,11}, {    351,12}, \
    {    191,11}, {    383,10}, {    799,11}, {    415,13}, \
    {    127,12}, {    255,11}, {    511,10}, {   1023,11}, \
    {    543,10}, {   1087,11}, {    607,12}, {    319,11}, \
    {    671,10}, {   1343,11}, {    735,10}, {   1471,12}, \
    {    383,11}, {    799,10}, {   1599,11}, {    863,12}, \
    {    447,11}, {    927,13}, {    255,12}, {    511,11}, \
    {   1087,12}, {    575,11}, {   1215,12}, {    639,11}, \
    {   1343,12}, {    703,11}, {   1471,13}, {    383,12}, \
    {    767,11}, {   1599,12}, {    831,11}, {   1727,12}, \
    {    895,11}, {   1791,12}, {    959,14}, {    255,13}, \
    {    511,12}, {   1087,11}, {   2239,12}, {   1215,13}, \
    {    639,12}, {   1471,13}, {    767,12}, {   1727,13}, \
    {    895,12}, {   1919,14}, {    511,13}, {   1023,12}, \
    {   2239,13}, {   1151,12}, {   2431,13}, {   1279,12}, \
    {   2623,13}, {   1407,12}, {   2943,14}, {    767,13}, \
    {   1663,12}, {   3455,13}, {   1919,15}, {    511,14}, \
    {   1023,13}, {   2175,12}, {   4351,13}, {   2431,14}, \
    {   1279,13}, {   2943,14}, {   1535,13}, {   3455,14}, \
    {   1791,13}, {   3967,15}, {   1023,14}, {   2047,13}, \
    {   4351,14}, {   2303,13}, {   4991,14}, {   2815,15}, \
    {   1535,14}, {   3839,16} }
#define MUL_FFT_TABLE3_SIZE 158
#define MUL_FFT_THRESHOLD                 7296

#define SQR_FFT_MODF_THRESHOLD             500  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    500, 5}, {     25, 6}, {     13, 5}, {     27, 6}, \
    {     25, 7}, {     13, 6}, {     29, 7}, {     15, 6}, \
    {     32, 7}, {     17, 6}, {     35, 7}, {     19, 6}, \
    {     39, 7}, {     29, 8}, {     15, 7}, {     35, 8}, \
    {     19, 7}, {     41, 8}, {     23, 7}, {     47, 8}, \
    {     27, 9}, {     15, 8}, {     31, 7}, {     63, 8}, \
    {     39, 9}, {     23, 8}, {     51, 9}, {     31, 8}, \
    {     67, 9}, {     39, 8}, {     79, 9}, {     47, 8}, \
    {     95,10}, {     31, 9}, {     79,10}, {     47, 9}, \
    {     95,11}, {     31,10}, {     63, 9}, {    135,10}, \
    {     79, 9}, {    159,10}, {     95, 9}, {    191,10}, \
    {    111,11}, {     63,10}, {    127, 9}, {    255,10}, \
    {    143, 9}, {    287, 8}, {    575,10}, {    159,11}, \
    {     95,10}, {    191,12}, {     63,11}, {    127,10}, \
    {    255, 9}, {    511,10}, {    271, 9}, {    543,10}, \
    {    287,11}, {    159,10}, {    319, 9}, {    639,10}, \
    {    335, 9}, {    671,10}, {    351,11}, {    191,10}, \
    {    383, 9}, {    767,10}, {    399, 9}, {    799,10}, \
    {    415,11}, {    223,12}, {    127,11}, {    255,10}, \
    {    511, 9}, {   1023,10}, {    543,11}, {    287,10}, \
    {    607, 9}, {   1215,11}, {    319,10}, {    671,11}, \
    {    351,10}, {    703,12}, {    191,11}, {    383,10}, \
    {    799,11}, {    415,10}, {    831,13}, {    127,12}, \
    {    255,11}, {    511,10}, {   1023,11}, {    543,10}, \
    {   1087,11}, {    607,12}, {    319,11}, {    671,10}, \
    {   1343,11}, {    735,10}, {   1471,12}, {    383,11}, \
    {    799,10}, {   1599,11}, {    863,12}, {    447,11}, \
    {    959,13}, {    255,12}, {    511,11}, {   1087,12}, \
    {    575,11}, {   1215,10}, {   2431,12}, {    639,11}, \
    {   1343,12}, {    703,11}, {   1471,13}, {    383,12}, \
    {    767,11}, {   1599,12}, {    831,11}, {   1727,12}, \
    {    959,14}, {    255,13}, {    511,12}, {   1087,11}, \
    {   2239,12}, {   1215,11}, {   2431,13}, {    639,12}, \
    {   1471,13}, {    767,12}, {   1727,13}, {    895,12}, \
    {   1919,14}, {    511,13}, {   1023,12}, {   2239,13}, \
    {   1151,12}, {   2431,13}, {   1279,12}, {   2623,13}, \
    {   1407,12}, {   2943,14}, {    767,13}, {   1663,12}, \
    {   3455,13}, {   1919,15}, {    511,14}, {   1023,13}, \
    {   2431,14}, {   1279,13}, {   2943,14}, {   1535,13}, \
    {   3455,14}, {   1791,13}, {   3839,15}, {   1023,14}, \
    {   2047,13}, {   4223,14}, {   2303,13}, {   4863,14}, \
    {   2815,15}, {   1535,14}, {   3839,16} }
#define SQR_FFT_TABLE3_SIZE 167
#define SQR_FFT_THRESHOLD                 5504

#define MULLO_BASECASE_THRESHOLD             4
#define MULLO_DC_THRESHOLD                  29
#define MULLO_MUL_N_THRESHOLD            14281
#define SQRLO_BASECASE_THRESHOLD             6
#define SQRLO_DC_THRESHOLD                 193
#define SQRLO_SQR_THRESHOLD              10704

#define DC_DIV_QR_THRESHOLD                 84
#define DC_DIVAPPR_Q_THRESHOLD             278
#define DC_BDIV_QR_THRESHOLD                87
#define DC_BDIV_Q_THRESHOLD                216

#define INV_MULMOD_BNM1_THRESHOLD           50
#define INV_NEWTON_THRESHOLD               268
#define INV_APPR_THRESHOLD                 268

#define BINV_NEWTON_THRESHOLD              276
#define REDC_1_TO_REDC_N_THRESHOLD          78

#define MU_DIV_QR_THRESHOLD               1652
#define MU_DIVAPPR_Q_THRESHOLD            1528
#define MUPI_DIV_QR_THRESHOLD              114
#define MU_BDIV_QR_THRESHOLD              1442
#define MU_BDIV_Q_THRESHOLD               1466

#define POWM_SEC_TABLE  1,22,102,452,1357

#define GET_STR_DC_THRESHOLD                14
#define GET_STR_PRECOMPUTE_THRESHOLD        24
#define SET_STR_DC_THRESHOLD               270
#define SET_STR_PRECOMPUTE_THRESHOLD      1149

#define FAC_DSC_THRESHOLD                  208
#define FAC_ODD_THRESHOLD                   48

#define MATRIX22_STRASSEN_THRESHOLD         16
#define HGCD2_DIV1_METHOD                    3  /* 4.69% faster than 1 */
#define HGCD_THRESHOLD                     139
#define HGCD_APPR_THRESHOLD                174
#define HGCD_REDUCE_THRESHOLD             3389
#define GCD_DC_THRESHOLD                   599
#define GCDEXT_DC_THRESHOLD                419
#define JACOBI_BASE_METHOD                   1  /* 1.57% faster than 4 */

/* Tuneup completed successfully, took 83851 seconds */
