// FUN_005344ba @ 005344ba (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005344ba(float *param_1,float *param_2,float *param_3,int *param_4)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar2;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 extraout_ST1_07;
  undefined4 *local_4c;
  undefined4 *local_48;
  int local_44;
  undefined4 local_40 [9];
  undefined4 local_1c;
  undefined4 local_14;
  
  if ((DAT_01a9f364 == 0) || (-1 < DAT_02091cfc)) {
    DAT_0099a790 = *param_4;
    DAT_01eae1b8 = 0;
    DAT_0078cd44 = 1;
    for (iVar1 = DAT_01eae1b0; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (DAT_0099a790 == *(int *)(&DAT_01eae00c + DAT_0078cd44 * 4)) {
        local_1c = 0;
        _DAT_01cf8ee0 = f_6_25;
        if (0x31 < DAT_0099a790) {
          _DAT_01cf8ee0 = f_25;
        }
        _DAT_01cf8ee0 = (STEP * *param_3) / _DAT_01cf8ee0;
        DAT_0078b6bc = 1;
        ffree(in_ST1);
        ffree(in_ST0);
        FUN_00534859();
        DAT_0078cd48 = (int)ROUND(*param_1);
        if (200 < IP2) {
          DAT_0078cd48 = DAT_0078cd48 + 0x8502;
        }
        local_48 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        DAT_0078cd4c = (int)ROUND(*param_2);
        DAT_01a1c814 = IP10;
        if (0x31 < DAT_0099a790) {
          DAT_01a1c814 = IP10 + -1;
        }
        if (DAT_01a1c814 < 0) {
          DAT_01a1c814 = 0;
        }
        fVar2 = (float10)DAT_01a1c814 * (float10)_DAT_01aae320 + (float10)DAT_01aae324;
        fVar3 = (float10)_DAT_01cf8ee0;
        DAT_01aae32c = (float)(fVar2 / ABS(fVar3));
        if ((int)DAT_01aae32c < 0) {
          DAT_01aae32c = 0.0;
        }
        local_44 = DAT_0078cd4c;
        if (DAT_01aae324 == DAT_01aae32c) {
          local_40[0] = 0;
          local_4c = &DAT_0078cd48;
          ffree(fVar3);
          ffree(fVar2);
          Var4 = FUN_005fc330(local_40,0x18,0x784ff00,&DAT_0076886c,&local_4c,&DAT_00797268);
          local_4c = &DAT_0078cd4c;
          ffree(extraout_ST1_04);
          ffree(Var4);
          Var4 = FUN_005fc980(local_40,&DAT_0076886c,&local_4c);
          local_4c = (undefined4 *)&DAT_01cf8ee0;
          ffree(extraout_ST1_05);
          ffree(Var4);
          Var4 = FUN_005fc980(local_40,&DAT_00768870,&local_4c);
          local_4c = (undefined4 *)0x3;
          local_48 = &DAT_0078cd50;
          ffree(extraout_ST1_06);
          ffree(Var4);
          in_ST0 = FUN_005fc980(local_40,&DAT_0076885c,&local_4c);
          in_ST1 = extraout_ST1_07;
        }
        else {
          local_14 = 0;
          local_40[0] = 0;
          local_4c = &DAT_01aae32c;
          ffree(fVar3);
          ffree(fVar2);
          Var4 = FUN_005fc330(local_40,0x18,0x784ff00,&DAT_00768870,&local_4c,&DAT_007972ac);
          local_4c = &DAT_0078cd48;
          ffree(extraout_ST1);
          ffree(Var4);
          Var4 = FUN_005fc980(local_40,&DAT_0076886c,&local_4c);
          local_4c = &DAT_0078cd4c;
          ffree(extraout_ST1_00);
          ffree(Var4);
          Var4 = FUN_005fc980(local_40,&DAT_0076886c,&local_4c);
          local_4c = (undefined4 *)&DAT_01cf8ee0;
          ffree(extraout_ST1_01);
          ffree(Var4);
          Var4 = FUN_005fc980(local_40,&DAT_00768870,&local_4c);
          local_4c = (undefined4 *)0x3;
          local_48 = &DAT_0078cd50;
          ffree(extraout_ST1_02);
          ffree(Var4);
          in_ST0 = FUN_005fc980(local_40,&DAT_0076885c,&local_4c);
          in_ST1 = extraout_ST1_03;
        }
        goto LAB_0053484d;
      }
      DAT_0078cd44 = DAT_0078cd44 + 1;
    }
  }
  DAT_01eae1b8 = 1;
  DAT_0078b6bc = 0;
LAB_0053484d:
  ffree(in_ST1);
  ffree(in_ST0);
  return;
}


