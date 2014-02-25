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
/* Generated on Sun Nov 25 07:38:49 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 8 -name t3fv_8 -include t3f.h */

/*
 * This function contains 37 FP additions, 32 FP multiplications,
 * (or, 27 additions, 22 multiplications, 10 fused multiply/add),
 * 43 stack variables, 1 constants, and 16 memory accesses
 */
#include "t3f.h"

static void t3fv_8(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(8, rs)) {
	       V T2, T3, Tb, T1, T5, Tn, Tq, T8, Td, T4, Ta, Tp, Tg, Ti, T9;
	       T2 = LDW(&(W[0]));
	       T3 = LDW(&(W[TWVL * 2]));
	       Tb = LDW(&(W[TWVL * 4]));
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
	       Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
	       Tq = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
	       T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       Td = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
	       T4 = VZMUL(T2, T3);
	       Ta = VZMULJ(T2, T3);
	       Tp = VZMULJ(T2, Tb);
	       Tg = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
	       Ti = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
	       T9 = VZMULJ(T2, T8);
	       {
		    V T6, To, Tc, Tr, Th, Tj;
		    T6 = VZMULJ(T4, T5);
		    To = VZMULJ(Ta, Tn);
		    Tc = VZMULJ(Ta, Tb);
		    Tr = VZMULJ(Tp, Tq);
		    Th = VZMULJ(Tb, Tg);
		    Tj = VZMULJ(T3, Ti);
		    {
			 V Tx, T7, Te, Ts, Ty, Tk, TB;
			 Tx = VADD(T1, T6);
			 T7 = VSUB(T1, T6);
			 Te = VZMULJ(Tc, Td);
			 Ts = VSUB(To, Tr);
			 Ty = VADD(To, Tr);
			 Tk = VSUB(Th, Tj);
			 TB = VADD(Th, Tj);
			 {
			      V Tf, TA, Tz, TD;
			      Tf = VSUB(T9, Te);
			      TA = VADD(T9, Te);
			      Tz = VADD(Tx, Ty);
			      TD = VSUB(Tx, Ty);
			      {
				   V TC, TE, Tl, Tt;
				   TC = VADD(TA, TB);
				   TE = VSUB(TB, TA);
				   Tl = VADD(Tf, Tk);
				   Tt = VSUB(Tk, Tf);
				   {
					V Tu, Tw, Tm, Tv;
					ST(&(x[WS(rs, 2)]), VFMAI(TE, TD), ms, &(x[0]));
					ST(&(x[WS(rs, 6)]), VFNMSI(TE, TD), ms, &(x[0]));
					ST(&(x[0]), VADD(Tz, TC), ms, &(x[0]));
					ST(&(x[WS(rs, 4)]), VSUB(Tz, TC), ms, &(x[0]));
					Tu = VFNMS(LDK(KP707106781), Tt, Ts);
					Tw = VFMA(LDK(KP707106781), Tt, Ts);
					Tm = VFMA(LDK(KP707106781), Tl, T7);
					Tv = VFNMS(LDK(KP707106781), Tl, T7);
					ST(&(x[WS(rs, 5)]), VFNMSI(Tw, Tv), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 3)]), VFMAI(Tw, Tv), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 7)]), VFMAI(Tu, Tm), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 1)]), VFNMSI(Tu, Tm), ms, &(x[WS(rs, 1)]));
				   }
			      }
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
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("t3fv_8"), twinstr, &GENUS, {27, 22, 10, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_8) (planner *p) {
     X(kdft_dit_register) (p, t3fv_8, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 8 -name t3fv_8 -include t3f.h */

/*
 * This function contains 37 FP additions, 24 FP multiplications,
 * (or, 37 additions, 24 multiplications, 0 fused multiply/add),
 * 31 stack variables, 1 constants, and 16 memory accesses
 */
#include "t3f.h"

static void t3fv_8(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(8, rs)) {
	       V T2, T3, Ta, T4, Tb, Tc, Tq;
	       T2 = LDW(&(W[0]));
	       T3 = LDW(&(W[TWVL * 2]));
	       Ta = VZMULJ(T2, T3);
	       T4 = VZMUL(T2, T3);
	       Tb = LDW(&(W[TWVL * 4]));
	       Tc = VZMULJ(Ta, Tb);
	       Tq = VZMULJ(T2, Tb);
	       {
		    V T7, Tx, Tt, Ty, Tf, TA, Tk, TB, T1, T6, T5;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    T6 = VZMULJ(T4, T5);
		    T7 = VSUB(T1, T6);
		    Tx = VADD(T1, T6);
		    {
			 V Tp, Ts, To, Tr;
			 To = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Tp = VZMULJ(Ta, To);
			 Tr = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Ts = VZMULJ(Tq, Tr);
			 Tt = VSUB(Tp, Ts);
			 Ty = VADD(Tp, Ts);
		    }
		    {
			 V T9, Te, T8, Td;
			 T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 T9 = VZMULJ(T2, T8);
			 Td = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Te = VZMULJ(Tc, Td);
			 Tf = VSUB(T9, Te);
			 TA = VADD(T9, Te);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Th = VZMULJ(Tb, Tg);
			 Ti = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Tj = VZMULJ(T3, Ti);
			 Tk = VSUB(Th, Tj);
			 TB = VADD(Th, Tj);
		    }
		    {
			 V Tz, TC, TD, TE;
			 Tz = VADD(Tx, Ty);
			 TC = VADD(TA, TB);
			 ST(&(x[WS(rs, 4)]), VSUB(Tz, TC), ms, &(x[0]));
			 ST(&(x[0]), VADD(Tz, TC), ms, &(x[0]));
			 TD = VSUB(Tx, Ty);
			 TE = VBYI(VSUB(TB, TA));
			 ST(&(x[WS(rs, 6)]), VSUB(TD, TE), ms, &(x[0]));
			 ST(&(x[WS(rs, 2)]), VADD(TD, TE), ms, &(x[0]));
			 {
			      V Tm, Tv, Tu, Tw, Tl, Tn;
			      Tl = VMUL(LDK(KP707106781), VADD(Tf, Tk));
			      Tm = VADD(T7, Tl);
			      Tv = VSUB(T7, Tl);
			      Tn = VMUL(LDK(KP707106781), VSUB(Tk, Tf));
			      Tu = VBYI(VSUB(Tn, Tt));
			      Tw = VBYI(VADD(Tt, Tn));
			      ST(&(x[WS(rs, 7)]), VSUB(Tm, Tu), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 3)]), VADD(Tv, Tw), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 1)]), VADD(Tm, Tu), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 5)]), VSUB(Tv, Tw), ms, &(x[WS(rs, 1)]));
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
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("t3fv_8"), twinstr, &GENUS, {37, 24, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_8) (planner *p) {
     X(kdft_dit_register) (p, t3fv_8, &desc);
}
#endif				/* HAVE_FMA */
