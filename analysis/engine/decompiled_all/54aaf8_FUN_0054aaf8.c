// FUN_0054aaf8 @ 0054aaf8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054aaf8(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined2 in_FPUControlWord;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar5 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  if (DAT_020b8ea0._1_1_ == 'N') {
    FUN_0054e79e();
  }
  else if (DAT_020b8ea0._1_1_ == 'B') {
    DAT_009a2110 = DAT_0078d890;
    DAT_009a210c = DAT_0078b4e4;
    if (DAT_0078d890 != 0) {
      FUN_005f33c9(&stack0xfffffffc,0x54ab8b);
      puVar3 = puVar5;
      FUN_005f34d1(puVar5,0x54aba6);
      DAT_0078b4e4 = 0x43;
      thunk_FUN_0053ec10();
    }
    fit_view(&DAT_0076937c,&DAT_009a2108,&DAT_009a2104,&DAT_009a2100,&DAT_009a20fc);
    DAT_009a20f8 = (DAT_009a2100 - VIEW_DX) + 0x960;
    DAT_009a20f0 = (DAT_009a20fc - VIEW_DX) + 0x960;
    DAT_009a20f4 = DAT_009a2104;
    DAT_009a20ec = DAT_009a2108;
    DAT_01fbb784 = DAT_009a2104;
    DAT_01fbb78c = DAT_009a2108;
    DAT_009a20fc = DAT_009a20f0;
    DAT_009a2100 = DAT_009a20f8;
    DAT_01fbb780 = DAT_009a20f8;
    DAT_01fbb788 = DAT_009a20f0;
    while( true ) {
      thunk_FUN_00413608(&DAT_009a2100,&DAT_009a2104,&DAT_009a20fc,&DAT_009a2108);
      *(undefined4 *)(puVar3 + -0x14) = 0;
      DAT_0078b4e4 = DAT_009a210c;
      DAT_0078d890 = DAT_009a2110;
      if (DAT_009a210c == 0x52) break;
      for (iVar2 = 1; iVar2 < 0x19; iVar2 = iVar2 + 1) {
        (&DAT_009a2128)[iVar2] = (int)f_0;
      }
      DAT_009a21dc = DAT_0079d6dc;
      _DAT_009a20c8 = *(float *)(&DAT_0079d6e0 + DAT_0079d6dc * 4);
      *(int *)(puVar3 + -0x74) = DAT_009a2100 + -400;
      _DAT_009a217c = (float)*(int *)(puVar3 + -0x74);
      *(int *)(puVar3 + -0x74) = DAT_009a2104 + 0x69aa;
      _DAT_009a2180 = (float)*(int *)(puVar3 + -0x74);
      *(int *)(puVar3 + -0x74) = DAT_009a20fc + -400;
      _DAT_009a2184 = (float)*(int *)(puVar3 + -0x74);
      *(int *)(puVar3 + -0x74) = DAT_009a2108 + 0x69aa;
      _DAT_009a2188 = (float)*(int *)(puVar3 + -0x74);
      DAT_009a2128 = thunk_FUN_00599a70(&DAT_009a218c,&DAT_009a212c);
      if (DAT_009a2128 == 2) {
        *(undefined4 *)(puVar3 + -0xc) = 0;
        draw_items();
        return;
      }
      DAT_0079d6dc = DAT_009a21dc;
      _DAT_009a20c8 = *(float *)(&DAT_0079d6e0 + DAT_009a21dc * 4);
      *(undefined2 *)(puVar3 + -0x78) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
      *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_009a20c8 * _DAT_009a217c + f_400);
      DAT_009a2100 = *(int *)(puVar3 + -0x74);
      *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
      *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
      *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_009a20c8 * _DAT_009a2180 - f_27050);
      DAT_009a2104 = *(int *)(puVar3 + -0x74);
      *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
      *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
      *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_009a20c8 * _DAT_009a2184 + f_400);
      DAT_009a20fc = *(int *)(puVar3 + -0x74);
      *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
      *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
      *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_009a20c8 * _DAT_009a2188 - f_27050);
      DAT_009a2108 = *(int *)(puVar3 + -0x74);
      *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
      *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
      *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_009a20c4);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x78);
      VEC_N = *(int *)(puVar3 + -0x74);
      if (DAT_019c5ca8 == -2) {
        DAT_009a2100 = DAT_009a20f8;
        DAT_009a2104 = DAT_009a20f4;
        DAT_009a20fc = DAT_009a20f0;
        DAT_009a2108 = DAT_009a20ec;
        *(undefined4 *)(puVar3 + -4) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -8) = 0;
      }
    }
    *(undefined4 *)(puVar3 + -0x10) = 0;
  }
  else {
    if (DAT_020b8ea0._1_1_ == 'E') {
      if (P2 == f_0) {
        DAT_01fbb8a8 = 1;
        DAT_01fbb8a0 = 8;
        DAT_01fbb8a4 = 0x58;
        FUN_005f33c9(&stack0xfffffffc,0x54b1ca);
        FUN_005f34d1(puVar6,0x54b1e5);
        thunk_FUN_0041b68a();
        *(undefined4 *)(puVar6 + -0x40) = 0;
        return;
      }
      DAT_009a2120 = (int)ROUND(P2);
    }
    else {
      if (DAT_01fbb8a4 != 0x58) {
        return;
      }
      puVar4 = &stack0xfffffffc;
      FUN_005f34d1(&stack0xfffffffc,0x54af6f);
      DAT_009a2124 = VEC_N;
      if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
        DAT_020b90a0 = DAT_00769370;
        thunk_FUN_0041b011();
        *(undefined4 *)(puVar4 + -0x34) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0x38) = 0;
        thunk_FUN_00518448();
        if ((P1 == f_0) && (P3 == f_0)) {
          *(undefined4 *)(puVar4 + -0x30) = 0;
          return;
        }
      }
      *(undefined4 *)(puVar4 + -0x2c) = 0;
      *(undefined2 *)(puVar4 + -0x78) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x76) = (ushort)*(undefined4 *)(puVar4 + -0x78) | 0xc00;
      *(int *)(puVar4 + -0x74) = (int)ROUND(P1);
      fVar1 = P4;
      DAT_009a2120 = *(int *)(puVar4 + -0x74);
      *(undefined2 *)(puVar4 + -0x78) = *(undefined2 *)(puVar4 + -0x78);
      *(ushort *)(puVar4 + -0x76) = (ushort)*(undefined4 *)(puVar4 + -0x78) | 0xc00;
      *(int *)(puVar4 + -0x74) = (int)ROUND(fVar1);
      fVar1 = P2;
      _DAT_009a211c = *(int *)(puVar4 + -0x74);
      P1 = P2;
      P2 = P3;
      if (fVar1 < f_0) {
        P1 = f_0;
      }
      if (DAT_01fbb8b8 < P3) {
        P2 = DAT_01fbb8b8;
      }
      FUN_0054946a(&DAT_00769150,1);
      VEC_N = DAT_009a2124;
      *(undefined4 *)(puVar4 + -0x28) = 0;
    }
    DAT_0078b4e4 = 0;
    thunk_FUN_004f7808();
    _DAT_009a211c = DAT_009a2120;
    _DAT_009a2118 = f_0;
    _DAT_009a2114 = DAT_01fbb8b8;
    DAT_01fbb8a4 = 99;
    thunk_FUN_004c9510(&DAT_009a2120,&DAT_009a211c,&DAT_009a2118,&DAT_009a2114);
    DAT_01fbb8a4 = 0x58;
    *(undefined4 *)(puVar4 + -0x24) = 0;
  }
  return;
}


