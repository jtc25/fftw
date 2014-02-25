#define SIMD_HEADER "simd-avx.h"
/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Nov 25 07:39:19 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 32 -name t3bv_32 -include t3b.h -sign 1 */

/*
 * This function contains 244 FP additions, 214 FP multiplications,
 * (or, 146 additions, 116 multiplications, 98 fused multiply/add),
 * 120 stack variables, 7 constants, and 64 memory accesses
 */
#include "t3b.h"

static void t3bv_32(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DVK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DVK(KP668178637, +0.668178637919298919997757686523080761552472251);
     DVK(KP198912367, +0.198912367379658006911597622644676228597850501);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V T2B, T2A, T2F, T2N, T2H, T2z, T2P, T2L, T2C, T2M;
	       {
		    V T2, T5, T3, T7;
		    T2 = LDW(&(W[0]));
		    T5 = LDW(&(W[TWVL * 4]));
		    T3 = LDW(&(W[TWVL * 2]));
		    T7 = LDW(&(W[TWVL * 6]));
		    {
			 V T24, Tb, T3x, T2T, T3K, T2W, T25, Tr, T3z, T3j, T28, TX, T3y, T3g, T27;
			 V TG, T37, T3F, T3G, T3a, T2Y, T15, T1p, T2Z, T2w, T1V, T2v, T1N, T32, T1h;
			 V T17, T1a;
			 {
			      V T1, Tz, TT, T4, TC, Tv, T12, T1D, T1w, T18, T1t, T1O, TK, TP, T1c;
			      V T1m, Tf, T6, Te, TL, TQ, T2S, Tp, TU, Ti, Ta, TM, TR, Tm, TJ;
			      V T22, T9, T1Z;
			      T1 = LD(&(x[0]), ms, &(x[0]));
			      T22 = LD(&(x[WS(rs, 24)]), ms, &(x[0]));
			      T9 = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			      T1Z = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			      {
				   V Tn, TH, Tk, To, Th, Tg, T8, Tl, T20, T23, TI;
				   {
					V Td, T1C, Tc, T21;
					Td = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
					Tz = VZMUL(T2, T5);
					T1C = VZMULJ(T2, T5);
					Tn = VZMUL(T3, T5);
					TT = VZMULJ(T3, T5);
					Tc = VZMUL(T2, T3);
					T4 = VZMULJ(T2, T3);
					TH = VZMUL(T3, T7);
					T21 = VZMULJ(T3, T7);
					Tk = VZMUL(T2, T7);
					TC = VZMULJ(T2, T7);
					Tv = VZMULJ(T5, T7);
					T12 = VZMULJ(Tz, T7);
					T20 = VZMUL(T1C, T1Z);
					T1D = VZMULJ(T1C, T7);
					T1w = VZMULJ(Tn, T7);
					T18 = VZMULJ(TT, T7);
					T1t = VZMUL(Tc, T7);
					T1O = VZMULJ(Tc, T7);
					TK = VZMUL(Tc, T5);
					TP = VZMULJ(Tc, T5);
					T1c = VZMUL(T4, T7);
					T1m = VZMULJ(T4, T7);
					Tf = VZMULJ(T4, T5);
					T6 = VZMUL(T4, T5);
					T23 = VZMUL(T21, T22);
					Te = VZMUL(Tc, Td);
				   }
				   TL = VZMULJ(TK, T7);
				   TQ = VZMULJ(TP, T7);
				   To = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
				   Th = LD(&(x[WS(rs, 20)]), ms, &(x[0]));
				   Tg = VZMULJ(Tf, T7);
				   T8 = VZMULJ(T6, T7);
				   T2S = VADD(T20, T23);
				   T24 = VSUB(T20, T23);
				   Tl = LD(&(x[WS(rs, 28)]), ms, &(x[0]));
				   TI = LD(&(x[WS(rs, 30)]), ms, &(x[0]));
				   Tp = VZMUL(Tn, To);
				   TU = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
				   Ti = VZMUL(Tg, Th);
				   Ta = VZMUL(T8, T9);
				   TM = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
				   TR = LD(&(x[WS(rs, 22)]), ms, &(x[0]));
				   Tm = VZMUL(Tk, Tl);
				   TJ = VZMUL(TH, TI);
			      }
			      {
				   V Tu, TE, Tw, TA;
				   {
					V T3h, TO, T3i, TW;
					{
					     V TV, T2U, Tj, T2R, TN, TS, T2V, Tq, Tt, TD;
					     Tt = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
					     TV = VZMUL(TT, TU);
					     T2U = VADD(Te, Ti);
					     Tj = VSUB(Te, Ti);
					     T2R = VADD(T1, Ta);
					     Tb = VSUB(T1, Ta);
					     TN = VZMUL(TL, TM);
					     TS = VZMUL(TQ, TR);
					     T2V = VADD(Tm, Tp);
					     Tq = VSUB(Tm, Tp);
					     Tu = VZMUL(T4, Tt);
					     TD = LD(&(x[WS(rs, 26)]), ms, &(x[0]));
					     T3x = VSUB(T2R, T2S);
					     T2T = VADD(T2R, T2S);
					     T3h = VADD(TJ, TN);
					     TO = VSUB(TJ, TN);
					     T3i = VADD(TV, TS);
					     TW = VSUB(TS, TV);
					     T3K = VSUB(T2U, T2V);
					     T2W = VADD(T2U, T2V);
					     T25 = VSUB(Tj, Tq);
					     Tr = VADD(Tj, Tq);
					     TE = VZMUL(TC, TD);
					}
					Tw = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
					T3z = VSUB(T3h, T3i);
					T3j = VADD(T3h, T3i);
					T28 = VFMA(LDK(KP414213562), TO, TW);
					TX = VFNMS(LDK(KP414213562), TW, TO);
					TA = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
				   }
				   {
					V T35, T1z, T1T, T36, T39, T1L, T1B, T1F;
					{
					     V T1v, T1y, Ty, T3e, T1S, T1Q, T1I, T3f, TF, T1K, T1A, T1E;
					     {
						  V T1u, T1x, Tx, T1R;
						  T1u = LD(&(x[WS(rs, 31)]), ms, &(x[WS(rs, 1)]));
						  T1x = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
						  Tx = VZMUL(Tv, Tw);
						  T1R = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
						  {
						       V T1P, T1H, T1J, TB;
						       T1P = LD(&(x[WS(rs, 23)]), ms, &(x[WS(rs, 1)]));
						       T1H = LD(&(x[WS(rs, 27)]), ms, &(x[WS(rs, 1)]));
						       T1J = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
						       TB = VZMUL(Tz, TA);
						       T1v = VZMUL(T1t, T1u);
						       T1y = VZMUL(T1w, T1x);
						       Ty = VSUB(Tu, Tx);
						       T3e = VADD(Tu, Tx);
						       T1S = VZMUL(Tf, T1R);
						       T1Q = VZMUL(T1O, T1P);
						       T1I = VZMUL(T7, T1H);
						       T3f = VADD(TB, TE);
						       TF = VSUB(TB, TE);
						       T1K = VZMUL(T6, T1J);
						       T1A = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
						       T1E = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
						  }
					     }
					     T35 = VADD(T1v, T1y);
					     T1z = VSUB(T1v, T1y);
					     T1T = VSUB(T1Q, T1S);
					     T36 = VADD(T1S, T1Q);
					     T3y = VSUB(T3e, T3f);
					     T3g = VADD(T3e, T3f);
					     T27 = VFMA(LDK(KP414213562), Ty, TF);
					     TG = VFNMS(LDK(KP414213562), TF, Ty);
					     T39 = VADD(T1I, T1K);
					     T1L = VSUB(T1I, T1K);
					     T1B = VZMUL(T3, T1A);
					     T1F = VZMUL(T1D, T1E);
					}
					{
					     V T11, T14, T1o, T1l, T1e, T1U, T1M, T1g, T16, T19;
					     {
						  V T10, T13, T1n, T1k;
						  T10 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
						  T13 = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
						  T1n = LD(&(x[WS(rs, 25)]), ms, &(x[WS(rs, 1)]));
						  T1k = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
						  {
						       V T1d, T1f, T1G, T38;
						       T1d = LD(&(x[WS(rs, 29)]), ms, &(x[WS(rs, 1)]));
						       T1f = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
						       T1G = VSUB(T1B, T1F);
						       T38 = VADD(T1B, T1F);
						       T37 = VADD(T35, T36);
						       T3F = VSUB(T35, T36);
						       T11 = VZMUL(T2, T10);
						       T14 = VZMUL(T12, T13);
						       T1o = VZMUL(T1m, T1n);
						       T1l = VZMUL(T5, T1k);
						       T1e = VZMUL(T1c, T1d);
						       T3G = VSUB(T39, T38);
						       T3a = VADD(T38, T39);
						       T1U = VSUB(T1L, T1G);
						       T1M = VADD(T1G, T1L);
						       T1g = VZMUL(TK, T1f);
						  }
						  T16 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
						  T19 = LD(&(x[WS(rs, 21)]), ms, &(x[WS(rs, 1)]));
					     }
					     T2Y = VADD(T11, T14);
					     T15 = VSUB(T11, T14);
					     T1p = VSUB(T1l, T1o);
					     T2Z = VADD(T1l, T1o);
					     T2w = VFNMS(LDK(KP707106781), T1U, T1T);
					     T1V = VFMA(LDK(KP707106781), T1U, T1T);
					     T2v = VFNMS(LDK(KP707106781), T1M, T1z);
					     T1N = VFMA(LDK(KP707106781), T1M, T1z);
					     T32 = VADD(T1e, T1g);
					     T1h = VSUB(T1e, T1g);
					     T17 = VZMUL(TP, T16);
					     T1a = VZMUL(T18, T19);
					}
				   }
			      }
			 }
			 {
			      V T2X, T3k, T3b, T3t, T1b, T31, T30, T3C, T3r, T3v, T3p, T3q;
			      T2X = VSUB(T2T, T2W);
			      T3p = VADD(T2T, T2W);
			      T3q = VADD(T3g, T3j);
			      T3k = VSUB(T3g, T3j);
			      T3b = VSUB(T37, T3a);
			      T3t = VADD(T37, T3a);
			      T1b = VSUB(T17, T1a);
			      T31 = VADD(T17, T1a);
			      T30 = VADD(T2Y, T2Z);
			      T3C = VSUB(T2Y, T2Z);
			      T3r = VSUB(T3p, T3q);
			      T3v = VADD(T3p, T3q);
			      {
				   V T1r, T2t, T1j, T2s, T3S, T3Y, T3R, T3V;
				   {
					V T3B, T3T, T3M, T3W, T3U, T3P, T3X, T3I, T3l, T3c, T3w, T3u;
					{
					     V T3L, T3A, T33, T3D, T1i, T1q, T3O, T3H;
					     T3L = VSUB(T3y, T3z);
					     T3A = VADD(T3y, T3z);
					     T33 = VADD(T31, T32);
					     T3D = VSUB(T31, T32);
					     T1i = VADD(T1b, T1h);
					     T1q = VSUB(T1b, T1h);
					     T3O = VFMA(LDK(KP414213562), T3F, T3G);
					     T3H = VFNMS(LDK(KP414213562), T3G, T3F);
					     T3B = VFMA(LDK(KP707106781), T3A, T3x);
					     T3T = VFNMS(LDK(KP707106781), T3A, T3x);
					     T3M = VFMA(LDK(KP707106781), T3L, T3K);
					     T3W = VFNMS(LDK(KP707106781), T3L, T3K);
					     {
						  V T3E, T3N, T3s, T34;
						  T3E = VFNMS(LDK(KP414213562), T3D, T3C);
						  T3N = VFMA(LDK(KP414213562), T3C, T3D);
						  T3s = VADD(T30, T33);
						  T34 = VSUB(T30, T33);
						  T1r = VFMA(LDK(KP707106781), T1q, T1p);
						  T2t = VFNMS(LDK(KP707106781), T1q, T1p);
						  T1j = VFMA(LDK(KP707106781), T1i, T15);
						  T2s = VFNMS(LDK(KP707106781), T1i, T15);
						  T3U = VADD(T3N, T3O);
						  T3P = VSUB(T3N, T3O);
						  T3X = VSUB(T3E, T3H);
						  T3I = VADD(T3E, T3H);
						  T3l = VSUB(T34, T3b);
						  T3c = VADD(T34, T3b);
						  T3w = VADD(T3s, T3t);
						  T3u = VSUB(T3s, T3t);
					     }
					}
					{
					     V T40, T3Z, T3Q, T3J;
					     T3S = VFMA(LDK(KP923879532), T3P, T3M);
					     T3Q = VFNMS(LDK(KP923879532), T3P, T3M);
					     T40 = VFNMS(LDK(KP923879532), T3X, T3W);
					     T3Y = VFMA(LDK(KP923879532), T3X, T3W);
					     T3R = VFMA(LDK(KP923879532), T3I, T3B);
					     T3J = VFNMS(LDK(KP923879532), T3I, T3B);
					     {
						  V T3o, T3m, T3n, T3d;
						  T3o = VFMA(LDK(KP707106781), T3l, T3k);
						  T3m = VFNMS(LDK(KP707106781), T3l, T3k);
						  T3n = VFMA(LDK(KP707106781), T3c, T2X);
						  T3d = VFNMS(LDK(KP707106781), T3c, T2X);
						  ST(&(x[WS(rs, 16)]), VSUB(T3v, T3w), ms, &(x[0]));
						  ST(&(x[0]), VADD(T3v, T3w), ms, &(x[0]));
						  ST(&(x[WS(rs, 8)]), VFMAI(T3u, T3r), ms, &(x[0]));
						  ST(&(x[WS(rs, 24)]), VFNMSI(T3u, T3r), ms, &(x[0]));
						  T3Z = VFMA(LDK(KP923879532), T3U, T3T);
						  T3V = VFNMS(LDK(KP923879532), T3U, T3T);
						  ST(&(x[WS(rs, 18)]), VFMAI(T3Q, T3J), ms, &(x[0]));
						  ST(&(x[WS(rs, 14)]), VFNMSI(T3Q, T3J), ms, &(x[0]));
						  ST(&(x[WS(rs, 28)]), VFNMSI(T3o, T3n), ms, &(x[0]));
						  ST(&(x[WS(rs, 4)]), VFMAI(T3o, T3n), ms, &(x[0]));
						  ST(&(x[WS(rs, 20)]), VFMAI(T3m, T3d), ms, &(x[0]));
						  ST(&(x[WS(rs, 12)]), VFNMSI(T3m, T3d), ms, &(x[0]));
					     }
					     ST(&(x[WS(rs, 26)]), VFMAI(T40, T3Z), ms, &(x[0]));
					     ST(&(x[WS(rs, 6)]), VFNMSI(T40, T3Z), ms, &(x[0]));
					}
				   }
				   {
					V T2p, T1s, T1W, T2h, TZ, T2i, T2d, T26, T29, T2q;
					{
					     V Ts, TY, T2b, T2c;
					     T2p = VFNMS(LDK(KP707106781), Tr, Tb);
					     Ts = VFMA(LDK(KP707106781), Tr, Tb);
					     TY = VADD(TG, TX);
					     T2B = VSUB(TG, TX);
					     T1s = VFNMS(LDK(KP198912367), T1r, T1j);
					     T2b = VFMA(LDK(KP198912367), T1j, T1r);
					     T2c = VFMA(LDK(KP198912367), T1N, T1V);
					     T1W = VFNMS(LDK(KP198912367), T1V, T1N);
					     ST(&(x[WS(rs, 2)]), VFMAI(T3S, T3R), ms, &(x[0]));
					     ST(&(x[WS(rs, 30)]), VFNMSI(T3S, T3R), ms, &(x[0]));
					     ST(&(x[WS(rs, 22)]), VFNMSI(T3Y, T3V), ms, &(x[0]));
					     ST(&(x[WS(rs, 10)]), VFMAI(T3Y, T3V), ms, &(x[0]));
					     T2h = VFNMS(LDK(KP923879532), TY, Ts);
					     TZ = VFMA(LDK(KP923879532), TY, Ts);
					     T2i = VADD(T2b, T2c);
					     T2d = VSUB(T2b, T2c);
					     T2A = VFNMS(LDK(KP707106781), T25, T24);
					     T26 = VFMA(LDK(KP707106781), T25, T24);
					     T29 = VSUB(T27, T28);
					     T2q = VADD(T27, T28);
					}
					{
					     V T2J, T2r, T2K, T2y;
					     {
						  V T2u, T2D, T2j, T2n, T2l, T1X, T2k, T2a, T2E, T2x;
						  T2u = VFMA(LDK(KP668178637), T2t, T2s);
						  T2D = VFNMS(LDK(KP668178637), T2s, T2t);
						  T2j = VFNMS(LDK(KP980785280), T2i, T2h);
						  T2n = VFMA(LDK(KP980785280), T2i, T2h);
						  T2l = VSUB(T1s, T1W);
						  T1X = VADD(T1s, T1W);
						  T2k = VFNMS(LDK(KP923879532), T29, T26);
						  T2a = VFMA(LDK(KP923879532), T29, T26);
						  T2J = VFNMS(LDK(KP923879532), T2q, T2p);
						  T2r = VFMA(LDK(KP923879532), T2q, T2p);
						  T2E = VFNMS(LDK(KP668178637), T2v, T2w);
						  T2x = VFMA(LDK(KP668178637), T2w, T2v);
						  {
						       V T1Y, T2f, T2o, T2m, T2e, T2g;
						       T1Y = VFNMS(LDK(KP980785280), T1X, TZ);
						       T2f = VFMA(LDK(KP980785280), T1X, TZ);
						       T2o = VFNMS(LDK(KP980785280), T2l, T2k);
						       T2m = VFMA(LDK(KP980785280), T2l, T2k);
						       T2e = VFNMS(LDK(KP980785280), T2d, T2a);
						       T2g = VFMA(LDK(KP980785280), T2d, T2a);
						       T2F = VSUB(T2D, T2E);
						       T2K = VADD(T2D, T2E);
						       T2N = VSUB(T2u, T2x);
						       T2y = VADD(T2u, T2x);
						       ST(&(x[WS(rs, 23)]), VFNMSI(T2m, T2j), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 9)]), VFMAI(T2m, T2j), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 25)]), VFMAI(T2o, T2n), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 7)]), VFNMSI(T2o, T2n), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 1)]), VFMAI(T2g, T2f), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 31)]), VFNMSI(T2g, T2f), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 17)]), VFMAI(T2e, T1Y), ms, &(x[WS(rs, 1)]));
						       ST(&(x[WS(rs, 15)]), VFNMSI(T2e, T1Y), ms, &(x[WS(rs, 1)]));
						  }
					     }
					     T2H = VFMA(LDK(KP831469612), T2y, T2r);
					     T2z = VFNMS(LDK(KP831469612), T2y, T2r);
					     T2P = VFNMS(LDK(KP831469612), T2K, T2J);
					     T2L = VFMA(LDK(KP831469612), T2K, T2J);
					}
				   }
			      }
			 }
		    }
	       }
	       T2C = VFNMS(LDK(KP923879532), T2B, T2A);
	       T2M = VFMA(LDK(KP923879532), T2B, T2A);
	       {
		    V T2Q, T2O, T2G, T2I;
		    T2Q = VFMA(LDK(KP831469612), T2N, T2M);
		    T2O = VFNMS(LDK(KP831469612), T2N, T2M);
		    T2G = VFNMS(LDK(KP831469612), T2F, T2C);
		    T2I = VFMA(LDK(KP831469612), T2F, T2C);
		    ST(&(x[WS(rs, 21)]), VFMAI(T2O, T2L), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 11)]), VFNMSI(T2O, T2L), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 27)]), VFNMSI(T2Q, T2P), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 5)]), VFMAI(T2Q, T2P), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 29)]), VFMAI(T2I, T2H), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VFNMSI(T2I, T2H), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 13)]), VFMAI(T2G, T2z), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 19)]), VFNMSI(T2G, T2z), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 27),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 32, XSIMD_STRING("t3bv_32"), twinstr, &GENUS, {146, 116, 98, 0}, 0, 0, 0 };

void XSIMD(codelet_t3bv_32) (planner *p) {
     X(kdft_dit_register) (p, t3bv_32, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 32 -name t3bv_32 -include t3b.h -sign 1 */

/*
 * This function contains 244 FP additions, 158 FP multiplications,
 * (or, 228 additions, 142 multiplications, 16 fused multiply/add),
 * 90 stack variables, 7 constants, and 64 memory accesses
 */
#include "t3b.h"

static void t3bv_32(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP195090322, +0.195090322016128267848284868477022240927691618);
     DVK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DVK(KP555570233, +0.555570233019602224742830813948532874374937191);
     DVK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V T2, T5, T3, T4, Tc, T1v, TH, Tz, Tn, T6, TS, Tf, TK, T7, T8;
	       V Tv, T1I, T25, Tg, Tk, T1N, T1Q, TC, T16, T12, T1w, TL, TP, TT, T1m;
	       V T1f;
	       T2 = LDW(&(W[0]));
	       T5 = LDW(&(W[TWVL * 4]));
	       T3 = LDW(&(W[TWVL * 2]));
	       T4 = VZMULJ(T2, T3);
	       Tc = VZMUL(T2, T3);
	       T1v = VZMULJ(T2, T5);
	       TH = VZMULJ(T3, T5);
	       Tz = VZMUL(T2, T5);
	       Tn = VZMUL(T3, T5);
	       T6 = VZMUL(T4, T5);
	       TS = VZMUL(Tc, T5);
	       Tf = VZMULJ(T4, T5);
	       TK = VZMULJ(Tc, T5);
	       T7 = LDW(&(W[TWVL * 6]));
	       T8 = VZMULJ(T6, T7);
	       Tv = VZMULJ(T5, T7);
	       T1I = VZMULJ(Tc, T7);
	       T25 = VZMULJ(T3, T7);
	       Tg = VZMULJ(Tf, T7);
	       Tk = VZMUL(T2, T7);
	       T1N = VZMUL(Tc, T7);
	       T1Q = VZMULJ(Tn, T7);
	       TC = VZMULJ(T2, T7);
	       T16 = VZMUL(T4, T7);
	       T12 = VZMULJ(TH, T7);
	       T1w = VZMULJ(T1v, T7);
	       TL = VZMULJ(TK, T7);
	       TP = VZMUL(T3, T7);
	       TT = VZMULJ(TS, T7);
	       T1m = VZMULJ(Tz, T7);
	       T1f = VZMULJ(T4, T7);
	       {
		    V Tb, T28, T3k, T3M, Tr, T22, T3f, T3N, TX, T20, T3b, T3J, TG, T1Z, T38;
		    V T3I, T1M, T2v, T33, T3F, T1V, T2w, T30, T3E, T1j, T2s, T2W, T3C, T1r, T2t;
		    V T2T, T3B;
		    {
			 V T1, T27, Ta, T24, T26, T9, T23, T3i, T3j;
			 T1 = LD(&(x[0]), ms, &(x[0]));
			 T26 = LD(&(x[WS(rs, 24)]), ms, &(x[0]));
			 T27 = VZMUL(T25, T26);
			 T9 = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			 Ta = VZMUL(T8, T9);
			 T23 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 T24 = VZMUL(T1v, T23);
			 Tb = VSUB(T1, Ta);
			 T28 = VSUB(T24, T27);
			 T3i = VADD(T1, Ta);
			 T3j = VADD(T24, T27);
			 T3k = VSUB(T3i, T3j);
			 T3M = VADD(T3i, T3j);
		    }
		    {
			 V Te, Tp, Ti, Tm;
			 {
			      V Td, To, Th, Tl;
			      Td = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			      Te = VZMUL(Tc, Td);
			      To = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			      Tp = VZMUL(Tn, To);
			      Th = LD(&(x[WS(rs, 20)]), ms, &(x[0]));
			      Ti = VZMUL(Tg, Th);
			      Tl = LD(&(x[WS(rs, 28)]), ms, &(x[0]));
			      Tm = VZMUL(Tk, Tl);
			 }
			 {
			      V Tj, Tq, T3d, T3e;
			      Tj = VSUB(Te, Ti);
			      Tq = VSUB(Tm, Tp);
			      Tr = VMUL(LDK(KP707106781), VADD(Tj, Tq));
			      T22 = VMUL(LDK(KP707106781), VSUB(Tj, Tq));
			      T3d = VADD(Te, Ti);
			      T3e = VADD(Tm, Tp);
			      T3f = VSUB(T3d, T3e);
			      T3N = VADD(T3d, T3e);
			 }
		    }
		    {
			 V TJ, TV, TN, TR;
			 {
			      V TI, TU, TM, TQ;
			      TI = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			      TJ = VZMUL(TH, TI);
			      TU = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			      TV = VZMUL(TT, TU);
			      TM = LD(&(x[WS(rs, 22)]), ms, &(x[0]));
			      TN = VZMUL(TL, TM);
			      TQ = LD(&(x[WS(rs, 30)]), ms, &(x[0]));
			      TR = VZMUL(TP, TQ);
			 }
			 {
			      V TO, TW, T39, T3a;
			      TO = VSUB(TJ, TN);
			      TW = VSUB(TR, TV);
			      TX = VFNMS(LDK(KP382683432), TW, VMUL(LDK(KP923879532), TO));
			      T20 = VFMA(LDK(KP923879532), TW, VMUL(LDK(KP382683432), TO));
			      T39 = VADD(TR, TV);
			      T3a = VADD(TJ, TN);
			      T3b = VSUB(T39, T3a);
			      T3J = VADD(T39, T3a);
			 }
		    }
		    {
			 V Tu, TE, Tx, TB;
			 {
			      V Tt, TD, Tw, TA;
			      Tt = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      Tu = VZMUL(T4, Tt);
			      TD = LD(&(x[WS(rs, 26)]), ms, &(x[0]));
			      TE = VZMUL(TC, TD);
			      Tw = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			      Tx = VZMUL(Tv, Tw);
			      TA = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			      TB = VZMUL(Tz, TA);
			 }
			 {
			      V Ty, TF, T36, T37;
			      Ty = VSUB(Tu, Tx);
			      TF = VSUB(TB, TE);
			      TG = VFMA(LDK(KP382683432), Ty, VMUL(LDK(KP923879532), TF));
			      T1Z = VFNMS(LDK(KP382683432), TF, VMUL(LDK(KP923879532), Ty));
			      T36 = VADD(Tu, Tx);
			      T37 = VADD(TB, TE);
			      T38 = VSUB(T36, T37);
			      T3I = VADD(T36, T37);
			 }
		    }
		    {
			 V T1H, T1K, T1S, T1P, T1B, T1D, T1E, T1u, T1y, T1z;
			 {
			      V T1G, T1J, T1R, T1O;
			      T1G = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			      T1H = VZMUL(Tf, T1G);
			      T1J = LD(&(x[WS(rs, 23)]), ms, &(x[WS(rs, 1)]));
			      T1K = VZMUL(T1I, T1J);
			      T1R = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			      T1S = VZMUL(T1Q, T1R);
			      T1O = LD(&(x[WS(rs, 31)]), ms, &(x[WS(rs, 1)]));
			      T1P = VZMUL(T1N, T1O);
			      {
				   V T1A, T1C, T1t, T1x;
				   T1A = LD(&(x[WS(rs, 27)]), ms, &(x[WS(rs, 1)]));
				   T1B = VZMUL(T7, T1A);
				   T1C = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
				   T1D = VZMUL(T6, T1C);
				   T1E = VSUB(T1B, T1D);
				   T1t = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
				   T1u = VZMUL(T3, T1t);
				   T1x = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
				   T1y = VZMUL(T1w, T1x);
				   T1z = VSUB(T1u, T1y);
			      }
			 }
			 {
			      V T1F, T1L, T31, T32;
			      T1F = VMUL(LDK(KP707106781), VSUB(T1z, T1E));
			      T1L = VSUB(T1H, T1K);
			      T1M = VSUB(T1F, T1L);
			      T2v = VADD(T1L, T1F);
			      T31 = VADD(T1u, T1y);
			      T32 = VADD(T1B, T1D);
			      T33 = VSUB(T31, T32);
			      T3F = VADD(T31, T32);
			 }
			 {
			      V T1T, T1U, T2Y, T2Z;
			      T1T = VSUB(T1P, T1S);
			      T1U = VMUL(LDK(KP707106781), VADD(T1z, T1E));
			      T1V = VSUB(T1T, T1U);
			      T2w = VADD(T1T, T1U);
			      T2Y = VADD(T1P, T1S);
			      T2Z = VADD(T1H, T1K);
			      T30 = VSUB(T2Y, T2Z);
			      T3E = VADD(T2Y, T2Z);
			 }
		    }
		    {
			 V T1e, T1h, T1o, T1l, T18, T1a, T1b, T11, T14, T15;
			 {
			      V T1d, T1g, T1n, T1k;
			      T1d = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			      T1e = VZMUL(T5, T1d);
			      T1g = LD(&(x[WS(rs, 25)]), ms, &(x[WS(rs, 1)]));
			      T1h = VZMUL(T1f, T1g);
			      T1n = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			      T1o = VZMUL(T1m, T1n);
			      T1k = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			      T1l = VZMUL(T2, T1k);
			      {
				   V T17, T19, T10, T13;
				   T17 = LD(&(x[WS(rs, 29)]), ms, &(x[WS(rs, 1)]));
				   T18 = VZMUL(T16, T17);
				   T19 = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
				   T1a = VZMUL(TS, T19);
				   T1b = VSUB(T18, T1a);
				   T10 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
				   T11 = VZMUL(TK, T10);
				   T13 = LD(&(x[WS(rs, 21)]), ms, &(x[WS(rs, 1)]));
				   T14 = VZMUL(T12, T13);
				   T15 = VSUB(T11, T14);
			      }
			 }
			 {
			      V T1c, T1i, T2U, T2V;
			      T1c = VMUL(LDK(KP707106781), VSUB(T15, T1b));
			      T1i = VSUB(T1e, T1h);
			      T1j = VSUB(T1c, T1i);
			      T2s = VADD(T1i, T1c);
			      T2U = VADD(T11, T14);
			      T2V = VADD(T18, T1a);
			      T2W = VSUB(T2U, T2V);
			      T3C = VADD(T2U, T2V);
			 }
			 {
			      V T1p, T1q, T2R, T2S;
			      T1p = VSUB(T1l, T1o);
			      T1q = VMUL(LDK(KP707106781), VADD(T15, T1b));
			      T1r = VSUB(T1p, T1q);
			      T2t = VADD(T1p, T1q);
			      T2R = VADD(T1l, T1o);
			      T2S = VADD(T1e, T1h);
			      T2T = VSUB(T2R, T2S);
			      T3B = VADD(T2R, T2S);
			 }
		    }
		    {
			 V T3V, T3Z, T3Y, T40;
			 {
			      V T3T, T3U, T3W, T3X;
			      T3T = VADD(T3M, T3N);
			      T3U = VADD(T3I, T3J);
			      T3V = VSUB(T3T, T3U);
			      T3Z = VADD(T3T, T3U);
			      T3W = VADD(T3B, T3C);
			      T3X = VADD(T3E, T3F);
			      T3Y = VBYI(VSUB(T3W, T3X));
			      T40 = VADD(T3W, T3X);
			 }
			 ST(&(x[WS(rs, 24)]), VSUB(T3V, T3Y), ms, &(x[0]));
			 ST(&(x[0]), VADD(T3Z, T40), ms, &(x[0]));
			 ST(&(x[WS(rs, 8)]), VADD(T3V, T3Y), ms, &(x[0]));
			 ST(&(x[WS(rs, 16)]), VSUB(T3Z, T40), ms, &(x[0]));
		    }
		    {
			 V T3K, T3O, T3H, T3P, T3D, T3G;
			 T3K = VSUB(T3I, T3J);
			 T3O = VSUB(T3M, T3N);
			 T3D = VSUB(T3B, T3C);
			 T3G = VSUB(T3E, T3F);
			 T3H = VMUL(LDK(KP707106781), VSUB(T3D, T3G));
			 T3P = VMUL(LDK(KP707106781), VADD(T3D, T3G));
			 {
			      V T3L, T3Q, T3R, T3S;
			      T3L = VBYI(VSUB(T3H, T3K));
			      T3Q = VSUB(T3O, T3P);
			      ST(&(x[WS(rs, 12)]), VADD(T3L, T3Q), ms, &(x[0]));
			      ST(&(x[WS(rs, 20)]), VSUB(T3Q, T3L), ms, &(x[0]));
			      T3R = VBYI(VADD(T3K, T3H));
			      T3S = VADD(T3O, T3P);
			      ST(&(x[WS(rs, 4)]), VADD(T3R, T3S), ms, &(x[0]));
			      ST(&(x[WS(rs, 28)]), VSUB(T3S, T3R), ms, &(x[0]));
			 }
		    }
		    {
			 V T3g, T3w, T3m, T3t, T35, T3u, T3p, T3x, T3c, T3l;
			 T3c = VMUL(LDK(KP707106781), VSUB(T38, T3b));
			 T3g = VSUB(T3c, T3f);
			 T3w = VADD(T3f, T3c);
			 T3l = VMUL(LDK(KP707106781), VADD(T38, T3b));
			 T3m = VSUB(T3k, T3l);
			 T3t = VADD(T3k, T3l);
			 {
			      V T2X, T34, T3n, T3o;
			      T2X = VFNMS(LDK(KP382683432), T2W, VMUL(LDK(KP923879532), T2T));
			      T34 = VFMA(LDK(KP923879532), T30, VMUL(LDK(KP382683432), T33));
			      T35 = VSUB(T2X, T34);
			      T3u = VADD(T2X, T34);
			      T3n = VFMA(LDK(KP382683432), T2T, VMUL(LDK(KP923879532), T2W));
			      T3o = VFNMS(LDK(KP382683432), T30, VMUL(LDK(KP923879532), T33));
			      T3p = VSUB(T3n, T3o);
			      T3x = VADD(T3n, T3o);
			 }
			 {
			      V T3h, T3q, T3z, T3A;
			      T3h = VBYI(VSUB(T35, T3g));
			      T3q = VSUB(T3m, T3p);
			      ST(&(x[WS(rs, 10)]), VADD(T3h, T3q), ms, &(x[0]));
			      ST(&(x[WS(rs, 22)]), VSUB(T3q, T3h), ms, &(x[0]));
			      T3z = VSUB(T3t, T3u);
			      T3A = VBYI(VSUB(T3x, T3w));
			      ST(&(x[WS(rs, 18)]), VSUB(T3z, T3A), ms, &(x[0]));
			      ST(&(x[WS(rs, 14)]), VADD(T3z, T3A), ms, &(x[0]));
			 }
			 {
			      V T3r, T3s, T3v, T3y;
			      T3r = VBYI(VADD(T3g, T35));
			      T3s = VADD(T3m, T3p);
			      ST(&(x[WS(rs, 6)]), VADD(T3r, T3s), ms, &(x[0]));
			      ST(&(x[WS(rs, 26)]), VSUB(T3s, T3r), ms, &(x[0]));
			      T3v = VADD(T3t, T3u);
			      T3y = VBYI(VADD(T3w, T3x));
			      ST(&(x[WS(rs, 30)]), VSUB(T3v, T3y), ms, &(x[0]));
			      ST(&(x[WS(rs, 2)]), VADD(T3v, T3y), ms, &(x[0]));
			 }
		    }
		    {
			 V TZ, T2k, T2d, T2l, T1X, T2h, T2a, T2i;
			 {
			      V Ts, TY, T2b, T2c;
			      Ts = VSUB(Tb, Tr);
			      TY = VSUB(TG, TX);
			      TZ = VSUB(Ts, TY);
			      T2k = VADD(Ts, TY);
			      T2b = VFNMS(LDK(KP555570233), T1j, VMUL(LDK(KP831469612), T1r));
			      T2c = VFMA(LDK(KP555570233), T1M, VMUL(LDK(KP831469612), T1V));
			      T2d = VSUB(T2b, T2c);
			      T2l = VADD(T2b, T2c);
			 }
			 {
			      V T1s, T1W, T21, T29;
			      T1s = VFMA(LDK(KP831469612), T1j, VMUL(LDK(KP555570233), T1r));
			      T1W = VFNMS(LDK(KP555570233), T1V, VMUL(LDK(KP831469612), T1M));
			      T1X = VSUB(T1s, T1W);
			      T2h = VADD(T1s, T1W);
			      T21 = VSUB(T1Z, T20);
			      T29 = VSUB(T22, T28);
			      T2a = VSUB(T21, T29);
			      T2i = VADD(T29, T21);
			 }
			 {
			      V T1Y, T2e, T2n, T2o;
			      T1Y = VADD(TZ, T1X);
			      T2e = VBYI(VADD(T2a, T2d));
			      ST(&(x[WS(rs, 27)]), VSUB(T1Y, T2e), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 5)]), VADD(T1Y, T2e), ms, &(x[WS(rs, 1)]));
			      T2n = VBYI(VADD(T2i, T2h));
			      T2o = VADD(T2k, T2l);
			      ST(&(x[WS(rs, 3)]), VADD(T2n, T2o), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 29)]), VSUB(T2o, T2n), ms, &(x[WS(rs, 1)]));
			 }
			 {
			      V T2f, T2g, T2j, T2m;
			      T2f = VSUB(TZ, T1X);
			      T2g = VBYI(VSUB(T2d, T2a));
			      ST(&(x[WS(rs, 21)]), VSUB(T2f, T2g), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 11)]), VADD(T2f, T2g), ms, &(x[WS(rs, 1)]));
			      T2j = VBYI(VSUB(T2h, T2i));
			      T2m = VSUB(T2k, T2l);
			      ST(&(x[WS(rs, 13)]), VADD(T2j, T2m), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 19)]), VSUB(T2m, T2j), ms, &(x[WS(rs, 1)]));
			 }
		    }
		    {
			 V T2r, T2M, T2F, T2N, T2y, T2J, T2C, T2K;
			 {
			      V T2p, T2q, T2D, T2E;
			      T2p = VADD(Tb, Tr);
			      T2q = VADD(T1Z, T20);
			      T2r = VSUB(T2p, T2q);
			      T2M = VADD(T2p, T2q);
			      T2D = VFNMS(LDK(KP195090322), T2s, VMUL(LDK(KP980785280), T2t));
			      T2E = VFMA(LDK(KP195090322), T2v, VMUL(LDK(KP980785280), T2w));
			      T2F = VSUB(T2D, T2E);
			      T2N = VADD(T2D, T2E);
			 }
			 {
			      V T2u, T2x, T2A, T2B;
			      T2u = VFMA(LDK(KP980785280), T2s, VMUL(LDK(KP195090322), T2t));
			      T2x = VFNMS(LDK(KP195090322), T2w, VMUL(LDK(KP980785280), T2v));
			      T2y = VSUB(T2u, T2x);
			      T2J = VADD(T2u, T2x);
			      T2A = VADD(TG, TX);
			      T2B = VADD(T28, T22);
			      T2C = VSUB(T2A, T2B);
			      T2K = VADD(T2B, T2A);
			 }
			 {
			      V T2z, T2G, T2P, T2Q;
			      T2z = VADD(T2r, T2y);
			      T2G = VBYI(VADD(T2C, T2F));
			      ST(&(x[WS(rs, 25)]), VSUB(T2z, T2G), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 7)]), VADD(T2z, T2G), ms, &(x[WS(rs, 1)]));
			      T2P = VBYI(VADD(T2K, T2J));
			      T2Q = VADD(T2M, T2N);
			      ST(&(x[WS(rs, 1)]), VADD(T2P, T2Q), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 31)]), VSUB(T2Q, T2P), ms, &(x[WS(rs, 1)]));
			 }
			 {
			      V T2H, T2I, T2L, T2O;
			      T2H = VSUB(T2r, T2y);
			      T2I = VBYI(VSUB(T2F, T2C));
			      ST(&(x[WS(rs, 23)]), VSUB(T2H, T2I), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 9)]), VADD(T2H, T2I), ms, &(x[WS(rs, 1)]));
			      T2L = VBYI(VSUB(T2J, T2K));
			      T2O = VSUB(T2M, T2N);
			      ST(&(x[WS(rs, 15)]), VADD(T2L, T2O), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 17)]), VSUB(T2O, T2L), ms, &(x[WS(rs, 1)]));
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 27),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 32, XSIMD_STRING("t3bv_32"), twinstr, &GENUS, {228, 142, 16, 0}, 0, 0, 0 };

void XSIMD(codelet_t3bv_32) (planner *p) {
     X(kdft_dit_register) (p, t3bv_32, &desc);
}
#endif				/* HAVE_FMA */
