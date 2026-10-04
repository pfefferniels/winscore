// emit_points @ 0054a69c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void emit_points(void)

{
  DAT_01a1c360 = 99999;
  _DAT_01a1c364 = 99999;
  DAT_01a1c368 = 99999;
  DAT_01a1c36c = 99999;
  DAT_01a1c370 = -99999;
  DAT_01a1c374 = -99999;
  if (((P26 == f_0) && (-1 < EDIT_ITEM)) && ((COLOR = 0, EDIT_ITEM != 0 || (DAT_01e66cb0 != 0)))) {
    COLOR = 0xff;
  }
  DAT_009a20c0 = VIEW_DX;
  if (f_199 < P2) {
    DAT_009a20c0 = VIEW_DX + 0x8502;
  }
  DAT_009a20bc = 1;
  while (NPT = NPT + -1, 0 < NPT) {
    DAT_009a20b8 = (&PT_X0)[DAT_009a20bc] + DAT_009a20c0;
    DAT_009a20b4 = (int)*(short *)((int)&DAT_01fbb8dc + DAT_009a20bc * 2 + 2);
    if ((DAT_009a20b4 != 0) && (VEC_LAST_PEN != 0)) {
      VEC_N = VEC_N + -3;
    }
    DAT_009a20b0 = COLOR;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) = DAT_009a20b8;
    DAT_009a20ac = (&PT_Y0)[DAT_009a20bc] - VIEW_DY;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) = DAT_009a20ac;
    DAT_009a20b4 = DAT_009a20b4 * 0x1000000;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
         DAT_009a20b0 + DAT_009a20b4;
    VEC_N = VEC_N + 3;
    if (EDIT_ITEM != 0) {
      if (DAT_009a20b8 < DAT_01a1c368) {
        DAT_01a1c368 = DAT_009a20b8;
      }
      if (DAT_01a1c370 < DAT_009a20b8) {
        DAT_01a1c370 = DAT_009a20b8;
      }
      if (DAT_009a20ac < DAT_01a1c36c) {
        DAT_01a1c36c = DAT_009a20ac;
      }
      if (DAT_01a1c374 < DAT_009a20ac) {
        DAT_01a1c374 = DAT_009a20ac;
      }
    }
    DAT_009a20bc = DAT_009a20bc + 1;
    VEC_LAST_PEN = DAT_009a20b4;
  }
  NPT = 1;
  return;
}


