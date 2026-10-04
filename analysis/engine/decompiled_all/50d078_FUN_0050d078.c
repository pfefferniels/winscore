// FUN_0050d078 @ 0050d078 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050d078(float *param_1)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 in_FPUControlWord;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_01fbb8a0 == 0) {
    if (ITEM_I != 0) {
      IP21 = DAT_0078b4e0;
      IP22 = DAT_0078b4e4;
      DAT_01fbb870 = *param_1;
      if (DAT_02052748 != DAT_02052740) goto LAB_0050d179;
      DAT_01fbb890 = 0;
      switch(*param_1) {
      default:
        thunk_FUN_0054956b("Enter lowest staff # of system and how many staves in system.",0x3e,
                           &DAT_007672c8);
        puVar4 = &stack0xfffffffc;
        goto LAB_0050d179;
      case 2.8026e-45:
      case 5.60519e-45:
        goto code_r0x0050d52c;
      case 4.2039e-45:
      case 7.00649e-45:
        thunk_FUN_0054956b("Enter Staff#, Left pos., Right pos., [Code#, Upper Staff# -- or Draw Box."
                           ,0x4a,&DAT_007672c8);
        puVar4 = &stack0xfffffffc;
        goto LAB_0050d179;
      }
    }
    DAT_01fbb7f8 = 0x46;
    IP11 = 1;
    fVar1 = P5;
  }
  else {
    do {
      puVar5 = puVar2;
      DAT_01fbb8a0 = 0;
      DAT_01fbb870 = P4;
      DAT_0078b4e4 = 0;
      if (P2 == f_m99) {
        *(undefined4 *)(puVar5 + -0x7c) = 0;
      }
      else {
        if (**(int **)(puVar5 + 8) == 1) {
          if (IP22 != 0x54) {
            push_words(&DAT_00767230,&P1);
            P5 = (P2 + P1) - f_1;
            if (P2 == f_0) {
              P5 = P1;
            }
            P2 = f_0;
            P3 = f_200;
            *(undefined4 *)(puVar5 + -0x74) = 0;
LAB_0050d32a:
            *(undefined4 *)(puVar5 + -100) = 0;
            pop_words(&DAT_00767230,&P1);
            *(undefined4 *)(puVar5 + -0x60) = 0;
            goto LAB_0050d34b;
          }
          *(undefined4 *)(puVar5 + -0x78) = 0;
          fVar1 = P5;
          goto LAB_0050d6ca;
        }
        if ((P2 != f_0) || (P3 != f_0)) {
          *(undefined4 *)(puVar5 + -0x70) = 0;
          push_words(&DAT_00767230,&P1);
          goto LAB_0050d32a;
        }
        P2 = f_m10;
        P3 = f_220;
        if (**(int **)(puVar5 + 8) == 4) {
          P2 = f_0;
          P3 = f_200;
          *(undefined4 *)(puVar5 + -0x68) = 0;
        }
        else {
          *(undefined4 *)(puVar5 + -0x6c) = 0;
        }
      }
      while( true ) {
        while( true ) {
          DAT_01fbb870 = P4;
          if ((IP21 != 0x41) || (P4 != f_0)) {
            *(undefined2 *)(puVar5 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0xc2) = (ushort)*(undefined4 *)(puVar5 + -0xc4) | 0xc00;
            *(int *)(puVar5 + -0xc0) = (int)ROUND(P1);
            DAT_01fbb860 = *(int *)(puVar5 + -0xc0);
            *(undefined2 *)(puVar5 + -0xc4) = *(undefined2 *)(puVar5 + -0xc4);
            *(ushort *)(puVar5 + -0xc2) = (ushort)*(undefined4 *)(puVar5 + -0xc4) | 0xc00;
            *(int *)(puVar5 + -0xc0) = (int)ROUND(P5);
            DAT_01fbb864 = *(int *)(puVar5 + -0xc0);
            if (DAT_01fbb860 < 1) {
              DAT_01fbb860 = 1;
            }
            DAT_01fbb88c = DAT_01fbb860;
            DAT_01fbb868 = P2;
            DAT_01fbb86c = P3;
            if (P3 == f_0) {
              DAT_01fbb86c = f_220;
            }
            if (MAX_STAFF < DAT_01fbb860) {
              DAT_01fbb860 = 1;
              DAT_01fbb864 = MAX_STAFF;
            }
            else {
              *(undefined4 *)(puVar5 + -4) = 0;
            }
            fVar1 = P5;
            if (DAT_01fbb864 < DAT_01fbb860) {
              DAT_01fbb864 = DAT_01fbb860;
            }
            goto LAB_0050d6ca;
          }
          *(undefined4 *)(puVar5 + -8) = 0;
          push_words(&DAT_00767230,&P1);
          FUN_005f33c9(puVar5,0x50d3ce);
          if (IP21 == 0x41) {
            *(undefined4 *)(puVar5 + -0x24) = 0;
          }
          else {
            *(undefined4 *)(puVar5 + -0x28) = 0;
            P5._2_2_ = (undefined2)s_0___all__007671f8._0_4_;
            P6._0_2_ = SUB42(s_0___all__007671f8._0_4_,2);
            P6._2_1_ = s_0___all__007671f8[4];
            P6._3_1_ = s_0___all__007671f8[5];
            P7._0_1_ = s_0___all__007671f8[6];
            P7._1_1_ = s_0___all__007671f8[7];
            P7._2_1_ = s_0___all__007671f8[8];
          }
          DAT_01fbb870 = P1;
          DAT_0078b4e0 = 0;
          _DAT_00940dfc = 0;
          DAT_01fbb88c = 0;
          if (DAT_01fbb7e4 == 0) {
            *(undefined4 *)(puVar5 + -0x20) = 0;
          }
          else {
            if (DAT_01fbb7ec < 0x1cc) {
              *(undefined4 *)(puVar5 + -0x1c) = 0;
            }
            iVar3 = (DAT_01fbb7e8 + 3) / 0x20;
            DAT_01fbb88c = iVar3 + 1;
            if (0xc < DAT_01fbb88c) {
              DAT_01fbb88c = iVar3 + 2;
            }
            if (DAT_01fbb88c == 0x13) {
              DAT_01fbb88c = 0;
            }
            DAT_01fbb870 = (float)DAT_01fbb88c;
          }
          pop_words(&DAT_00767230,&P1);
          if ((DAT_01fbb7e4 == 0) || (0x1cb < DAT_01fbb7ec)) break;
          *(undefined4 *)(puVar5 + -0x18) = 0;
LAB_0050d34b:
          DAT_01fbb870 = P4;
          if (**(int **)(puVar5 + 8) != 3) {
            *(undefined4 *)(puVar5 + -0x34) = 0;
            fVar1 = P5;
            goto LAB_0050d6ca;
          }
          *(undefined4 *)(puVar5 + -0x30) = 0;
        }
        if ((0x13 < DAT_01fbb88c) || (DAT_01fbb7fc == 0x1b)) break;
        *(undefined4 *)(puVar5 + -0x14) = 0;
        P4 = DAT_01fbb870;
        if (DAT_02052748 != DAT_02052740) {
          *(undefined4 *)(puVar5 + -0xc) = 0;
        }
      }
      *(undefined4 *)(puVar5 + -0x10) = 0;
code_r0x0050d52c:
      thunk_FUN_0054956b("Enter Staff number, Left position, Right position or draw box.",0x3f,
                         &DAT_007672c8);
      *(undefined4 *)(puVar5 + -0x8c) = 0;
      puVar4 = puVar5;
LAB_0050d179:
      DAT_01fbb7f8 = 0;
      IP11 = 0;
      thunk_FUN_00518448();
      if ((char)DAT_020b8ea0 == 'M') {
        DAT_01fbb8a0 = 1;
        FUN_005f33c9(puVar4,0x50d6a1);
        FUN_005f34d1(puVar4,0x50d6bc);
        *(undefined4 *)(puVar4 + -0x84) = 0;
        fVar1 = P5;
        goto LAB_0050d6ca;
      }
      *(undefined4 *)(puVar4 + -0x88) = 0;
      puVar2 = puVar4;
    } while (P1 != f_0);
    FUN_0050d706();
    *(undefined4 *)(puVar4 + -0x80) = 0;
    fVar1 = P5;
  }
LAB_0050d6ca:
  P5._2_2_ = (undefined2)((uint)fVar1 >> 0x10);
  P5._0_2_ = SUB42(fVar1,0);
  return;
}


