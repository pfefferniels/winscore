// FUN_004d9ae0 @ 004d9ae0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004d9bf2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d9ae0(void)

{
  undefined1 *puVar1;
  undefined2 in_FPUControlWord;
  float10 fVar2;
  
  puVar1 = &stack0xfffffffc;
  DAT_01fb9630 = 1;
  _DAT_008a05dc = 0;
  _DAT_008a05d8 = 1;
  DAT_01fb9634 = 0;
  DAT_008a05e4 = DAT_007658a4;
  DAT_00794830 = 0;
  _DAT_008a05d4 = 0;
  DAT_0171b230 = 1;
LAB_004d9b3c:
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          FUN_005f34d1(puVar1,0x4d9b59);
          _DAT_008a05d0 = DAT_009c48f4;
          thunk_FUN_00597550(&IP1);
          _DAT_008a05d8 = IP1;
          _DAT_008a05cc = IP1 & 0xff;
          DAT_01ade7c0 = IP2 & 0xff;
          if (DAT_01ade7c0 == 0x90) break;
          *(undefined4 *)(puVar1 + -0x30) = 0;
        }
        DAT_01ade7ec = (uint)IP2 >> 8 & 0xff;
        DAT_01ade7f0 = (uint)IP2 >> 0x10;
        if ((DAT_01ade7ec < 0x79) && (0xb < DAT_01ade7ec)) break;
        *(undefined4 *)(puVar1 + -0x28) = 0;
      }
      if (DAT_01ade7f0 == 0) break;
      *(undefined4 *)(puVar1 + -0x24) = 0;
      *(undefined4 *)(puVar1 + -0x58) = DAT_008a05c0;
      fVar2 = (float10)FUN_00604db0(puVar1 + -0x58);
      _DAT_008a05c8 = (float)fVar2;
      *(undefined4 *)(puVar1 + -4) = 0;
    }
    (&DAT_01aad7f0)[DAT_01ade7ec] = 0;
    DAT_01ade7e0 = 1;
    if (_DAT_008a05c8 == f_9999) {
      *(undefined4 *)(puVar1 + -0x20) = 0;
LAB_004d9d2a:
      DAT_01ade7f8 = DAT_008a05e8 - DAT_008a05bc;
      (&DAT_020b909f)[DAT_008a05bc] = 0x2f;
      DAT_008a05bc = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0x58) = DAT_008a05c0;
      fVar2 = (float10)FUN_00604db0(puVar1 + -0x58);
      _DAT_008a05c4 = (float)fVar2;
      *(undefined2 *)(puVar1 + -0x58) = in_FPUControlWord;
      *(ushort *)(puVar1 + -0x56) = (ushort)*(undefined4 *)(puVar1 + -0x58) | 0xc00;
      *(int *)(puVar1 + -0x54) = (int)ROUND((_DAT_008a05c4 - _DAT_008a05c8) * f_100);
      in_FPUControlWord = *(undefined2 *)(puVar1 + -0x58);
      DAT_008a05ec = *(int *)(puVar1 + -0x54);
      if (DAT_008a05ec < 0) {
        DAT_008a05ec = DAT_008a05ec + 6000;
      }
      if (((DAT_008a05ec < 0xf) && (DAT_008a05bc != 0)) && ((&DAT_020b909f)[DAT_008a05bc] == ':'))
      goto LAB_004d9d2a;
      *(undefined4 *)(puVar1 + -0x1c) = 0;
    }
    *(undefined4 *)(puVar1 + -0x18) = 0x6d;
    DAT_008a05ec = 0xc;
    do {
      if ((&DAT_01aad7f0)[DAT_008a05ec] != 0) {
        DAT_01ade7e0 = 0;
        *(undefined4 *)(puVar1 + -0x10) = 0;
        goto LAB_004d9b3c;
      }
      *(undefined4 *)(puVar1 + -0x14) = 0;
      *(undefined4 *)(puVar1 + -0xc) = 0;
      DAT_008a05ec = DAT_008a05ec + 1;
      *(int *)(puVar1 + -0x18) = *(int *)(puVar1 + -0x18) + -1;
    } while (0 < *(int *)(puVar1 + -0x18));
    *(undefined4 *)(puVar1 + -8) = 0;
  } while( true );
}


