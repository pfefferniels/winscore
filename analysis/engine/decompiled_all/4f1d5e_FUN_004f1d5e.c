// FUN_004f1d5e @ 004f1d5e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f1d5e(float *param_1)

{
  DAT_01a9f30c = IP6;
  if (IP6 < 0) {
    DAT_01a9f30c = -IP6;
  }
  DAT_01a9f318 = DAT_01f95ce0;
  if (DAT_01a9f30c < 0x18) {
    push_words(&DAT_00766534,&P1);
    push_words(&DAT_00766534,&IP1);
    if (DAT_01a9f30c == 0x15) {
      IP4 = IP4 + -5;
    }
    if (DAT_01a9f30c == 0x16) {
      IP4 = IP4 + 1;
    }
    if (DAT_01a9f30c == 0x17) {
      IP4 = IP4 + -1;
    }
    P5 = (float)((IP4 + 0x47) % 7 + 0x3e9);
    P1 = f_10;
    P3 = DAT_01a9f318 * f_0_022 + _DAT_01a9f32c + P22;
    P4 = (P4 - *param_1 * f_0_72) + P23;
    if (P24 == f_0) {
      P24 = f_1;
    }
    P6 = *param_1 * f_0_45 * P24;
    P7 = f_1005;
    if (P21 != f_0) {
      P7 = P21 + f_1000;
    }
    if (0 < IP6) {
      P26 = f_0_99;
    }
    P8 = f_0;
    push_words(&DAT_00766534,&DAT_020b9440);
    draw_item();
    pop_words(&DAT_00766534,&DAT_020b9440);
    pop_words(&DAT_00766534,&IP1);
    pop_words(&DAT_00766534,&P1);
    if (-1 < OUTPUT_MODE) {
      DAT_01b11790 = 0;
    }
  }
  return;
}


