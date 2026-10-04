// interpret @ 0047ec50 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 interpret(int param_1,int *param_2,int param_3,int *param_4,undefined4 *param_5)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  char *pcVar20;
  short *psVar21;
  int *piVar22;
  undefined4 *puVar23;
  byte *pbVar24;
  char *pcVar25;
  short *psVar26;
  int *piVar27;
  bool bVar28;
  bool bVar29;
  undefined1 uVar30;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  unkbyte10 Var31;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 extraout_ST0_09;
  unkbyte10 extraout_ST0_10;
  unkbyte10 extraout_ST0_11;
  unkbyte10 extraout_ST0_12;
  float10 extraout_ST0_13;
  undefined1 *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  
  puVar16 = &stack0xfffffffc;
  puVar13 = &stack0xfffffffc;
  puVar32 = &stack0xfffffffc;
  puVar33 = &stack0xfffffffc;
  puVar34 = &stack0xfffffffc;
  puVar35 = &stack0xfffffffc;
  puVar36 = &stack0xfffffffc;
  puVar14 = &stack0xfffffffc;
  puVar15 = &stack0xfffffffc;
  uVar17 = (uint)DAT_01fbb7ac >> 8;
  _DAT_01fbb7a4 = 4;
  _DAT_01fbb7b0 = 1;
  VEC_STRIDE = 4;
  VEC_LBOUND = 1;
  DAT_01fbb7b4 = 100000;
  VEC_BASE = param_1;
  _DAT_01fbb7a8 = 0xfffffffc;
  DAT_01fbb7ac = CONCAT31(((uint3)uVar17 | 0xff0000) ^ 0xfc0000,1);
  DAT_01fbb7c0 = param_2;
  uVar17 = (uint)DAT_01fbb830 >> 8;
  _DAT_01fbb828 = 1;
  _DAT_01fbb834 = 1;
  DAT_01fbb83c = 1;
  DAT_01fbb840 = 1;
  _DAT_01fbb838 = 20000;
  DAT_01fbb824 = param_3;
  _DAT_01fbb82c = 0xffffffff;
  DAT_01fbb830 = CONCAT31(((uint3)uVar17 | 0xff0000) ^ 0xfe0000,1);
  DAT_01fbb844 = param_4;
  DAT_00828558 = param_5;
  if ((DAT_009bb1cc == 99) && (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) != 0x747e)) {
    _DAT_020b90a0 = CONCAT12(DAT_007629ac,_DAT_020b90a0);
    P2 = f_0;
    ffree(in_ST0);
    thunk_FUN_00488a8d();
    DAT_009bb1cc = 0;
    _DAT_008285a8 = 0;
    FUN_005f34d1(&stack0xfffffffc,0x47edbe);
    in_ST0 = (float10)FUN_005f34d1(puVar16,0x47eddf);
    *(undefined4 *)(puVar16 + -0x694) = 0;
    goto LAB_004861ab;
  }
  if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x617e) {
    if (DAT_007a0b7e != 0x7a) {
      if (DAT_007a0b7e == 0x78) {
        DAT_0078dc45 = 0;
        puVar13 = &stack0xfffffffc;
        Var31 = FUN_005f34d1(&stack0xfffffffc,0x47ee97);
        *(undefined4 *)(puVar13 + -0x68c) = 0;
      }
      else {
        DAT_008285a4 = DAT_0078dc45;
        DAT_0078dc45 = DAT_007a0b7e - 0x30;
        Var31 = FUN_005f34d1(&stack0xfffffffc,0x47eee4);
        if (DAT_008285a4 == 1) {
          DAT_0078dc45 = DAT_0078dc45 + 10;
        }
      }
      ffree(Var31);
      in_ST0 = (float10)thunk_FUN_0048ecfb();
      *(undefined4 *)(puVar13 + -0x688) = 0;
      puVar16 = puVar13;
      goto LAB_004861ab;
    }
    DAT_0078dc3d = f_1;
    DAT_0078d840 = f_1;
    puVar14 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x47ee50);
    *(undefined4 *)(puVar14 + -0x690) = 0;
LAB_00483280:
    FUN_005f33c9(puVar14,0x48329e);
    Var31 = FUN_005f34d1(puVar14,0x4832b9);
    ffree(Var31);
    Var31 = thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_00762740,&DAT_00762744,"(1f7.2)",7,
                               &DAT_0078dc3d);
    ffree(Var31);
    in_ST0 = (float10)thunk_FUN_0048ecfb();
    DAT_0078b4e4 = 0;
    *(undefined4 *)(puVar14 + -900) = 0;
  }
  else {
    if ((CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x737e) ||
       (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x747e)) {
      if (EDIT_ITEM == 0) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0049177a(&DAT_008285a8);
        puVar16 = &stack0xfffffffc;
        goto LAB_004861ab;
      }
      _DAT_008285a8 = 0;
      DAT_007a0b7c = (char)DAT_0076299c;
      DAT_007a0b7d = (char)((ushort)DAT_0076299c >> 8);
    }
    if ((DAT_01fbb8a0 < 0x1f) || (0x27 < DAT_01fbb8a0)) {
      DAT_0078b4e4 = 0;
      if (DAT_009ae2bc == 0x7e7e7e7e) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0059d020();
        puVar14 = &stack0xfffffffc;
      }
      else {
        DAT_008285a0 = 0;
        puVar14 = &stack0xfffffffc;
        if ((DAT_009ae2bc & 0xffff) != 0x7e7e) goto LAB_0047f78d;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0059d020();
        puVar14 = &stack0xfffffffc;
        if ((DAT_009ae2bc >> 0x10 & 0xff) == 0x52) goto LAB_00484a3a;
        if ((DAT_009ae2bc >> 0x10 & 0xff) == 0x57) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00496aee();
          puVar15 = &stack0xfffffffc;
          goto LAB_004807d0;
        }
        iVar11 = 3;
        bVar28 = false;
        pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
        pcVar25 = "037";
        do {
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          bVar28 = *pcVar20 == *pcVar25;
          pcVar20 = pcVar20 + 1;
          pcVar25 = pcVar25 + 1;
        } while (bVar28);
        if (bVar28) {
          puVar14 = &stack0xfffffffc;
          if (DAT_00791194 == 0) goto LAB_0047f78d;
          if (0 < (int)DAT_00791194) {
            DAT_00791194 = DAT_00791194 - 1;
          }
LAB_0047f677:
          DAT_00791178 = DAT_00791194;
          DAT_00791460 = DAT_00791194;
          uVar17 = DAT_00791190;
          if ((int)DAT_00791190 < 0) {
            uVar17 = 0;
          }
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00549508(&DAT_020b8ea0,uVar17,&DAT_00791190,&DAT_00791178,
                                               &DAT_00791460);
          DAT_00791178 = DAT_00791194;
          puVar14 = &stack0xfffffffc;
LAB_0047f78d:
          *(undefined4 *)(puVar14 + -0x600) = 0;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0059d020();
          if ((DAT_01fbb8a0 != 0x3ea) || (DAT_008285a0 != 0xd)) {
            if ((0 < (int)DAT_00791190) || (DAT_008285a0 == 8)) {
              *(undefined4 *)(puVar14 + -0x5f8) = 0;
              goto LAB_00486181;
            }
            puVar15 = puVar14;
            if (EDIT_ITEM == 0) {
              *(undefined4 *)(puVar14 + -0x5f4) = 0;
              if (999 < DAT_01fbb8a0) {
                if (DAT_008285a0 == 0xd) {
                  FUN_005f33c9(puVar14,0x47f835);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47f850);
                }
                if ((CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x767e) ||
                   (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x787e)) {
                  *(undefined4 *)(puVar14 + -0x5d4) = 0;
                }
                else if (DAT_01fbb8a0 == 0x3eb) {
                  if ((DAT_009ae2bc & 0xff) == 0x7c) {
                    *(undefined4 *)(puVar14 + -0x5cc) = 0;
                    puVar15 = puVar14;
                    goto LAB_004807d0;
                  }
                }
                else {
                  *(undefined4 *)(puVar14 + -0x5d0) = 0;
                }
                goto LAB_0047f8bc;
              }
              *(undefined4 *)(puVar14 + -0x5d8) = 0;
            }
            else {
              if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x767e) {
                if (DAT_01be6d6c == 0) {
                  *(undefined4 *)(puVar14 + -0x5ec) = 0;
                  ffree(in_ST0);
                  in_ST0 = (float10)drag_move();
                  *(undefined4 *)(puVar14 + -0x5e4) = 0;
                }
                else {
                  ffree(in_ST0);
                  in_ST0 = (float10)thunk_FUN_0048fd5c(&DAT_01b9d620);
                  *(undefined4 *)(puVar14 + -0x5e8) = 0;
                }
                goto LAB_004807d0;
              }
              *(undefined4 *)(puVar14 + -0x5f0) = 0;
              if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x787e) {
                _DAT_01b9d620 = 0;
                in_ST0 = (float10)FUN_005f34d1(puVar14,0x48074b);
                *(undefined4 *)(puVar14 + -0x5dc) = 0;
                puVar15 = puVar14;
                goto LAB_004807d0;
              }
              *(undefined4 *)(puVar14 + -0x5e0) = 0;
            }
            iVar11 = FUN_005f4660(0x20);
            in_ST0 = extraout_ST0;
            if (((iVar11 == 0) || (EDIT_ITEM != 0)) ||
               (iVar11 = FUN_005f4660(0x20), in_ST0 = extraout_ST0_00, iVar11 == 0)) {
              *(undefined4 *)(puVar14 + -0x5c4) = 0;
            }
            else if (DAT_01be6d6c != 0) {
              FUN_005f34d1(puVar14,0x47f9bf);
              Var31 = FUN_005f34d1(puVar14,0x47f9e0);
              goto LAB_00485b9a;
            }
            if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x767e) {
              *(undefined4 *)(puVar14 + -0x5bc) = 0;
              goto LAB_004807d0;
            }
            ffree(in_ST0);
            DAT_008285a4 = thunk_FUN_00549449();
            if ((DAT_008285a4 != 0) && ((DAT_009ae2bc & 0xffff) == 0x7e7e)) {
              *(undefined4 *)(puVar14 + -0x5b8) = 0;
              in_ST0 = extraout_ST0_01;
              goto LAB_004807d0;
            }
            ffree(extraout_ST0_01);
            in_ST0 = (float10)thunk_FUN_0054943a();
            if (DAT_01fbb8a0 < 0) {
              *(undefined4 *)(puVar14 + -0x5b4) = 0;
              goto LAB_004807d0;
            }
            if (DAT_01fbb700 != 0) {
              *(undefined4 *)(puVar14 + -0x5b0) = 0;
              goto LAB_004807d0;
            }
            if (DAT_009ae4bc != 0) {
              *(undefined4 *)(puVar14 + -0x5ac) = 0;
              goto LAB_004807d0;
            }
            *DAT_00828558 = 0xffffffff;
            DAT_01be6cd8 = 0xffffffff;
            *DAT_01fbb7c0 = VEC_N + -1;
            DAT_02052740 = 0;
            *(undefined4 *)(puVar14 + -0x5a8) = 0;
            if (DAT_00791448 == 0) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_004a7da8();
            }
            if (DAT_00791198 != 0) {
              *(undefined4 *)(puVar14 + -0x594) = 0;
              goto LAB_00484442;
            }
            if (DAT_007a0b7c != ' ') {
              if (EDIT_ITEM != 0) {
                bVar28 = CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x4a4c;
                if (bVar28) {
                  FUN_005f33c9(puVar14,0x47fb51);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fb6c);
                }
                bVar28 = bVar28 && &stack0x00000000 == (undefined1 *)0x8e4;
                iVar11 = 5;
                pcVar20 = &DAT_007a0b7c;
                pcVar25 = "RESTO";
                do {
                  if (iVar11 == 0) break;
                  iVar11 = iVar11 + -1;
                  bVar28 = *pcVar20 == *pcVar25;
                  pcVar20 = pcVar20 + 1;
                  pcVar25 = pcVar25 + 1;
                } while (bVar28);
                if (bVar28) {
                  FUN_005f33c9(puVar14,0x47fba3);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fbbe);
                }
                if (CONCAT12(DAT_007a0b7e,CONCAT11(DAT_007a0b7d,DAT_007a0b7c)) == 0x444e55) {
                  FUN_005f33c9(puVar14,0x47fbf7);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fc12);
                }
                if (CONCAT12(DAT_007a0b7e,CONCAT11(DAT_007a0b7d,DAT_007a0b7c)) == 0x444552) {
                  FUN_005f33c9(puVar14,0x47fc4b);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fc66);
                }
                if ((IP1 == 0x10) && (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x5254)) {
                  FUN_005f33c9(puVar14,0x47fca3);
                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fcbe);
                }
                if (CONCAT13(DAT_007a0b7f,CONCAT12(DAT_007a0b7e,CONCAT11(DAT_007a0b7d,DAT_007a0b7c))
                            ) == 0x5453414c) {
                  *(undefined4 *)(puVar14 + -0x590) = 0;
                  puVar16 = puVar14;
                  goto LAB_004861ab;
                }
                FUN_005f33c9(puVar14,0x47fd00);
                FUN_005f34d1(puVar14,0x47fd1b);
              }
              FUN_005f34d1(puVar14,0x47fd3c);
              puVar18 = (undefined4 *)&DAT_007a0b7c;
              puVar23 = &DAT_009ae2bc;
              for (iVar11 = 0x20; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar23 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar23 = puVar23 + 1;
              }
              in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fd70);
            }
            puVar15 = puVar14;
            if ((DAT_009ae2bc & 0xffff) == 0x7171) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_0054e3b1(&DAT_00828bc0,0x200);
              *(undefined4 *)(puVar14 + -0x58c) = 0;
LAB_004807d0:
              DAT_01be6d80 = 0;
              puVar14 = puVar15;
              if (DAT_02052740 != 0) {
                *(undefined4 *)(puVar15 + -0x10) = 0;
LAB_004807ec:
                ffree(in_ST0);
                in_ST0 = (float10)thunk_FUN_00518448();
                if (EDIT_ITEM == 0) {
LAB_0048083c:
                  if (EDIT_ITEM != 0) goto LAB_00480854;
                  *(undefined4 *)(puVar14 + -0x4f4) = 0;
LAB_004824fc:
                  if ((_DAT_020b8ea0 & 0xffffff) == 0x204153) {
                    in_ST0 = (float10)FUN_005f33c9(puVar14,0x482531);
                    *(undefined4 *)(puVar14 + -0x48c) = 0;
                    goto LAB_004831ce;
                  }
                  if ((DAT_009ae2bc & 0xffff) == 0x5151) {
                    *(undefined4 *)(puVar14 + -0x6b8) = 0;
                    *(undefined4 *)(puVar14 + -0x6c8) = 3;
                    *(undefined4 *)(puVar14 + -0x6c4) = 0x9ae2be;
                    *(uint **)(puVar14 + -0x6c0) = &DAT_008285a4;
                    ffree(in_ST0);
                    Var31 = FUN_005f9240(puVar14 + -0x6b8,0x784ff00,&DAT_007628fc,puVar14 + -0x6c8,
                                         &DAT_00791124);
                    if (((DAT_020b8e50 == 5) && (DAT_008285a4 == 0)) &&
                       (DAT_008285a4 = 0xa2, 0 < DAT_0078dc30)) {
                      DAT_008285a4 = DAT_0078dc30 + 0xdb;
                    }
                    ffree(Var31);
                    thunk_FUN_00468df8(&DAT_008285a4);
                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482e44);
                    *(undefined4 *)(puVar14 + -0x480) = 0;
                    puVar15 = puVar14;
                  }
                  else {
                    *(undefined4 *)(puVar14 + -0x488) = 0;
LAB_00482564:
                    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_0054464c) {
                      *(undefined4 *)(puVar14 + -0x404) = 0;
                      goto LAB_00482589;
                    }
                    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544752) {
                      *(undefined4 *)(puVar14 + -0x400) = 0;
                      goto LAB_00482624;
                    }
                    if ((DAT_008285a4 == 0x7a) || ((_DAT_020b8ea0 & 0xff) == 0x5b)) {
                      ffree(in_ST0);
                      thunk_FUN_00535d00(&DAT_007628d4);
                      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482d67);
                      DAT_008285a4 = 0;
                      *(undefined4 *)(puVar14 + -0x3fc) = 0;
                      puVar15 = puVar14;
                      goto LAB_004807d0;
                    }
                    if ((DAT_008285a4 == 0x7b) || ((_DAT_020b8ea0 & 0xff) == 0x5d)) {
                      ffree(in_ST0);
                      thunk_FUN_00535d00(&DAT_007628d0);
                      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482d1b);
                      DAT_008285a4 = 0;
                      *(undefined4 *)(puVar14 + -0x3f8) = 0;
                      puVar15 = puVar14;
                      goto LAB_004807d0;
                    }
                    if ((_DAT_020b8ea0 & 0xff) == 0x7e) {
                      if (DAT_01fbb8a0 != 0) {
                        _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007627f0);
                        *(undefined4 *)(puVar14 + -0x3f0) = 0;
                        goto LAB_00483355;
                      }
                      DAT_01fbb8a0 = 0;
                      if (EDIT_ITEM != 0) {
                        *(undefined4 *)(puVar14 + -0x3ec) = 0;
                        goto LAB_00485edd;
                      }
                      _DAT_00828584 = DAT_01a1494c;
LAB_00482b67:
                      DAT_0078de20 = 8;
                      if (DAT_009bb1d0 != 0) {
                        DAT_009bb1d0 = 0;
                        *(undefined4 *)(puVar14 + -0x3e4) = 0;
                        puVar16 = puVar14;
                        goto LAB_004861ab;
                      }
                      *(undefined4 *)(puVar14 + -1000) = 0;
                      ffree(in_ST0);
                      in_ST0 = (float10)select_nearest();
                      if (EDIT_ITEM == 0) {
                        *(undefined4 *)(puVar14 + -0x3e0) = 0;
                        goto LAB_00485edd;
                      }
                      DAT_0078de20 = 0;
                      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482bcd);
                      if (DAT_01fbb8a4 != 0x4d) {
                        *(undefined4 *)(puVar14 + -0x3d8) = 0;
                        goto LAB_00485c38;
                      }
                      *(undefined4 *)(puVar14 + -0x3dc) = 0;
                      DAT_00791178 = (&ITEM_PTR0)[EDIT_ITEM];
                      fVar1 = (float)(&ITEM_P2)[DAT_00791178];
                      *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                      *(ushort *)(puVar14 + -0x6be) =
                           (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                      *(int *)(puVar14 + -0x6bc) = (int)ROUND(fVar1);
                      DAT_01fbb7e0 = *(undefined4 *)(puVar14 + -0x6bc);
                      DAT_01fbb7e4 = (&ITEM_P4)[DAT_00791178];
                      DAT_01fbb8a8 = 1;
                      DAT_01fbb8a0 = 8;
                      _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,DAT_007627e8);
                      EDIT_ITEM = 0;
                      ffree(in_ST0);
                      in_ST0 = (float10)thunk_FUN_004a1240(&DAT_007627e4);
                      DAT_01b9d628 = 0;
                      *(undefined4 *)(puVar14 + -0x5c) = 0;
                      goto LAB_00486181;
                    }
                    *(undefined4 *)(puVar14 + -0x3f4) = 0;
                    if (DAT_01fbb8a0 != 0) {
                      *(undefined4 *)(puVar14 + -0x3d4) = 0;
                      goto LAB_00483355;
                    }
                    if ((_DAT_020b8ea0 & 0xff) == 0x7c) {
                      if (DAT_01b9d628 == 0) {
                        *(undefined4 *)(puVar14 + -0x3cc) = 0;
                        goto LAB_00482b67;
                      }
                      Var31 = FUN_005f34d1(puVar14,0x482aea);
                      ffree(Var31);
                      in_ST0 = (float10)region_select();
                      DAT_01fbb8a0 = DAT_01fbb8a0 + 100;
                      *(undefined4 *)(puVar14 + -0x3c8) = 0;
                      goto LAB_00483355;
                    }
                    *(undefined4 *)(puVar14 + -0x3d0) = 0;
                    iVar11 = FUN_005f4660(0x20);
                    if (iVar11 != 0) {
                      *(undefined4 *)(puVar14 + -0x3c4) = 0;
                      in_ST0 = extraout_ST0_03;
                      goto LAB_00482968;
                    }
                    if ((EDIT_ITEM != 0) && ((DAT_009ae2bc & 0xffffff) == 0x444e55)) {
                      ffree(extraout_ST0_03);
                      thunk_FUN_0054d831("Cannot do UNDELETE while still in Edit Mode.",0x2d);
                      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482a93);
                      *(undefined4 *)(puVar14 + -0x3bc) = 0;
                      puVar15 = puVar14;
                      goto LAB_004807d0;
                    }
                    *(undefined4 *)(puVar14 + -0x3c0) = 0;
LAB_00482ed2:
                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482eef);
                    if (EDIT_ITEM == 0) {
                      if ((_DAT_020b8ea0 & 0xff) == 0x58) {
                        _DAT_009c6ad4 = f_0;
                        ffree(in_ST0);
                        thunk_FUN_00468df8(&DAT_007627bc);
                        FUN_005f33c9(puVar14,0x482f5c);
                        Var31 = FUN_005f34d1(puVar14,0x482f77);
                        ffree(Var31);
                        in_ST0 = (float10)thunk_FUN_00536adc();
                        if (DAT_02052740 != 0) {
                          *(undefined4 *)(puVar14 + -0x3b4) = 0;
                          goto LAB_004807ec;
                        }
                        *(undefined4 *)(puVar14 + -0x3b0) = 0;
                        puVar16 = puVar14;
                        goto LAB_004861ab;
                      }
                      *(undefined4 *)(puVar14 + -0x3ac) = 0;
                    }
                    else {
                      *(undefined4 *)(puVar14 + -0x3b8) = 0;
                    }
LAB_00482fb3:
                    if (EDIT_ITEM == 0) {
LAB_004831ce:
                      if ((char)DAT_020b8ea0 == ' ') {
                        *(undefined4 *)(puVar14 + -0x304) = 0;
                        puVar15 = puVar14;
                        goto LAB_004807d0;
                      }
                      if (DAT_01fbb700 != 0) {
                        DAT_009a9490 = DAT_01fbb700;
                        ffree(in_ST0);
                        in_ST0 = (float10)input_main();
                        *(undefined4 *)(puVar14 + -0x2fc) = 0;
                        goto LAB_00485ebc;
                      }
                      *(undefined4 *)(puVar14 + -0x300) = 0;
LAB_004831fd:
                      if (DAT_02052740 == 0) {
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00518448();
                      }
                      if (((_DAT_020b8ea0 & 0xffffff) == 0x434e49) &&
                         (_DAT_020b8ea0 >> 0x18 != 0x48)) {
                        *(undefined4 *)(puVar14 + -0x2f8) = 0;
LAB_00483249:
                        if (P2 == f_0) {
                          P2 = f_1;
                        }
                        DAT_0078dc3d = P2;
                        DAT_0078d840 = P2;
                        goto LAB_00483280;
                      }
                      if ((_DAT_020b8ea0 & 0xffff) == 0x2254) {
                        *(undefined4 *)(puVar14 + -0x2f4) = 0;
                        DAT_0078b4e4 = 0;
LAB_004852b4:
                        DAT_00828568 = DAT_02052740;
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_005644b8();
                        if ((_DAT_020b8ea0 & 0xff) == 0x49) {
                          *(undefined4 *)(puVar14 + -0x114) = 0;
                          goto LAB_00485aa9;
                        }
                        if ((_DAT_020b8ea0 & 0xff) == 0x5a) {
                          *(undefined4 *)(puVar14 + -0x110) = 0;
                          goto LAB_004857a3;
                        }
                        if ((_DAT_020b8ea0 >> 8 & 0xff) != 0x50) {
                          FUN_005f33c9(puVar14,0x485334);
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x48534f);
                        }
                        DAT_02052740 = DAT_00828568;
                        if (DAT_01fbb8a0 == -99) {
                          FUN_005f33c9(puVar14,0x48538a);
                          Var31 = FUN_005f34d1(puVar14,0x4853a5);
                          ffree(Var31);
                          in_ST0 = (float10)thunk_FUN_0054943a();
                          _DAT_020b8ea0 = CONCAT12(DAT_0076260a,DAT_00762608);
                          DAT_01fbb8a0 = 0;
                          P2 = (float)ITEM_I;
                          DAT_0078b4e0 = 0;
                          if (DAT_02052740 == 0) {
                            *(undefined4 *)(puVar14 + -0x10c) = 0;
                            goto LAB_00485c38;
                          }
                        }
                        DAT_01fbb8a0 = 0;
                        *(undefined4 *)(puVar14 + -0x108) = 0;
                        goto LAB_00485edd;
                      }
                      if (DAT_01fbb8a0 != 0) {
                        *(undefined4 *)(puVar14 + -0x2f0) = 0;
                        goto LAB_00483355;
                      }
                      puVar15 = puVar14;
                      if ((_DAT_020b8ea0 & 0xffff) == 0x4945) {
                        *(undefined4 *)(puVar14 + -0x2ec) = 0;
                        DAT_01b9d624 = -DAT_01b9d624;
                        if (0 < DAT_01b9d624) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_0054d831("New items will go direct to edit.",
                                                               0x22);
                        }
                        if (DAT_01b9d624 < 0) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_0054d831(
                                                  "New items will NOT go direct to edit.",0x26);
                        }
                        *(undefined4 *)(puVar14 + -0x78) = 0;
                        goto LAB_004807d0;
                      }
                      if (((DAT_020b8e60 & 0xffff) == 0x2050) || ((DAT_020b8e60 & 0xffff) == 0x2046)
                         ) {
                        DAT_020b8e60._0_3_ = CONCAT12(0x20,(undefined2)DAT_020b8e60);
                      }
                      if (_DAT_020b8ea0 == 0x49564e49) {
                        *(undefined4 *)(puVar14 + -0x2e8) = 0;
                        goto LAB_00485c38;
                      }
                      *(undefined4 *)(puVar14 + -0x2e4) = 0x60;
                      DAT_00791460 = 1;
                      do {
                        if ((DAT_00791460 == 0x1d || DAT_00791460 == 0x20) &&
                           ((*(uint *)(s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc +
                                      DAT_00791460 * 3 + 0x2d) & 0xffffff) ==
                            (DAT_020b8e60 & 0xffffff))) {
                          *(undefined4 *)(puVar14 + -0x2e0) = 0;
LAB_00483a14:
                          ffree(in_ST0);
                          in_ST0 = (float10)create_by_mnemonic(&DAT_00791460);
                          if (DAT_00791460 == 0xffffff9d) {
                            *(undefined4 *)(puVar14 + -0x2d4) = 0;
                            goto LAB_004807d0;
                          }
                          if (-1 < (int)DAT_00791460) {
                            *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                            *(ushort *)(puVar14 + -0x6be) =
                                 (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                            *(int *)(puVar14 + -0x6bc) = (int)ROUND(P1);
                            in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
                            IP1 = *(int *)(puVar14 + -0x6bc);
                            *(undefined4 *)(puVar14 + -0x2cc) = 0;
                            goto LAB_00485a81;
                          }
                          *(undefined4 *)(puVar14 + -0x2d0) = 0;
                          break;
                        }
                        if ((*(uint *)(s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc +
                                      DAT_00791460 * 3 + 0x2d) & 0xffffff) ==
                            (DAT_020b8e60 & 0xffffff)) {
                          if ((DAT_00791460 != 2) || (_DAT_020b8ea0 >> 0x18 == 0x54))
                          goto LAB_00483a14;
                          *(undefined4 *)(puVar14 + -0x2d8) = 0;
                          break;
                        }
                        *(undefined4 *)(puVar14 + -0x2dc) = 0;
                        *(undefined4 *)(puVar14 + -0x2c8) = 0;
                        DAT_00791460 = DAT_00791460 + 1;
                        *(int *)(puVar14 + -0x2e4) = *(int *)(puVar14 + -0x2e4) + -1;
                      } while (0 < *(int *)(puVar14 + -0x2e4));
                      *(undefined4 *)(puVar14 + -0x2c4) = 0;
                      DAT_00791470 = 0;
                      if ((int)DAT_0078b4e0 < 0x21) {
                        *(undefined4 *)(puVar14 + -0x2c0) = 0;
                        goto LAB_004807d0;
                      }
                      if (DAT_01be6d80 == 1) {
                        *(undefined4 *)(puVar14 + -0x74) = 0;
                        goto LAB_004807d0;
                      }
                      if (DAT_01be6d80 == 2) {
                        *(undefined4 *)(puVar14 + -0x70) = 0;
                        goto LAB_004807d0;
                      }
                      if (DAT_01be6d80 == 3) {
                        if ((_DAT_020b8ea0 & 0xff) == 0x59) {
                          *(undefined4 *)(puVar14 + -0x6b8) = 0;
                          *(undefined4 *)(puVar14 + -0x6c8) = 0x3c;
                          *(undefined **)(puVar14 + -0x6c4) = &DAT_01be6d84;
                          *(undefined4 *)(puVar14 + -0x6c0) = 2;
                          *(undefined4 *)(puVar14 + -0x6bc) = 4;
                          ffree(in_ST0);
                          Var31 = FUN_005f6540(puVar14 + -0x6b8,0x2b,0x784ff00,&DAT_007625ec,
                                               puVar14 + -0x6c8);
                          *(undefined4 *)(puVar14 + -0x6b8) = 0;
                          *(undefined4 *)(puVar14 + -0x6c0) = 6;
                          *(char **)(puVar14 + -0x6bc) = "delete";
                          ffree(Var31);
                          in_ST0 = (float10)FUN_005f7950(puVar14 + -0x6b8,0x2b,0x784ff00,
                                                         &DAT_007625dc,puVar14 + -0x6c0);
                          *(undefined4 *)(puVar14 + -0x60) = 0;
                        }
                        else {
                          *(undefined4 *)(puVar14 + -0x6c) = 0;
                        }
                        goto LAB_004807d0;
                      }
                      if (0x19 < DAT_0078b4e0 - 0x41) {
                        if (P1 != f_0) goto LAB_00485a81;
                        *(undefined4 *)(puVar14 + -700) = 0;
                        goto LAB_004858db;
                      }
                      bVar28 = DAT_0078b4e0 < 0x41;
                      puVar16 = puVar14;
                      switch(DAT_0078b4e0) {
                      case 0x41:
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_0040f003();
                        *(undefined4 *)(puVar14 + -0x2ac) = 0;
                        goto LAB_00485edd;
                      case 0x42:
                        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f42) {
                          *(undefined4 *)(puVar14 + -0x2a8) = 0;
                          goto code_r0x004857ea;
                        }
                        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) {
                          *(undefined4 *)(puVar14 + -0x2a4) = 0;
                          goto LAB_004858db;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_0054aaf8();
                        *(undefined4 *)(puVar14 + -0x2a0) = 0;
                        goto LAB_00485edd;
                      case 0x43:
                        if (EDIT_ITEM != 0) {
                          *(undefined4 *)(puVar14 + -0x27c) = 7;
                          DAT_00791460 = 1;
                          goto code_r0x00483d06;
                        }
                        if ((_DAT_020b8ea0 & 0xffff) == 0x5343) {
                          *(undefined4 *)(puVar14 + -0x29c) = 0;
                          goto code_r0x004855bf;
                        }
                        if (((_DAT_020b8ea0 & 0xffff) == 0x5643) ||
                           ((_DAT_020b8ea0 & 0xffffff) == 0x4e4f43)) {
                          *(undefined4 *)(puVar14 + -0x298) = 0;
                          goto code_r0x00485ddb;
                        }
                        if ((_DAT_020b8ea0 & 0xffff) != 0x5443) {
                          if ((_DAT_020b8ea0 & 0xffffff) != 0x455543) {
                            *(undefined4 *)(puVar14 + -0x28c) = 0;
                            *(undefined4 *)(puVar14 + -0x284) = 0x10;
                            DAT_00791460 = 1;
                            goto code_r0x00483c32;
                          }
                          FUN_005f33c9(puVar14,&UNK_00483cad);
                          Var31 = FUN_005f34d1(puVar14,&UNK_00483cc8);
                          ffree(Var31);
                          in_ST0 = (float10)thunk_FUN_004a217d();
                          *(undefined4 *)(puVar14 + -0x288) = 0;
                          puVar16 = puVar14;
                          goto LAB_004861ab;
                        }
                        if (((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x4e) &&
                           ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x58)) {
                          *(undefined4 *)(puVar14 + -0x290) = 0;
                          goto code_r0x00485ddb;
                        }
                        *(undefined4 *)(puVar14 + -0x294) = 0;
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00404525();
                        *(undefined4 *)(puVar14 + -0x264) = 0;
                        goto LAB_00485edd;
                      case 0x44:
                        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) {
                          DAT_0078b4e4 = 0x45;
                          *(undefined4 *)(puVar14 + -0x260) = 0;
                        }
                        else {
                          if ((_DAT_020b8ea0 & 0xffff) == 0x5244) {
                            ffree(in_ST0);
                            Var31 = thunk_FUN_00473cdd(&DAT_007626d8);
                            ffree(Var31);
                            in_ST0 = (float10)thunk_FUN_0044b928();
                            *(undefined4 *)(puVar14 + -600) = 0;
                            goto LAB_00485edd;
                          }
                          *(undefined4 *)(puVar14 + -0x25c) = 0;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00404ac5();
                        if (DAT_0078b4e0 != 0xffffffff) {
                          *(undefined4 *)(puVar14 + -0x250) = 0;
                          goto LAB_00485dfa;
                        }
                        *(undefined4 *)(puVar14 + -0x254) = 0;
                        goto code_r0x00484fa6;
                      case 0x45:
                        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00504445) {
                          *(undefined4 *)(puVar14 + -0x24c) = 0;
                        }
                        else if (((DAT_020b8e60 & 0xffff) == 0x4445) &&
                                ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x49)) {
                          *(undefined4 *)(puVar14 + -0x248) = 0;
                          goto LAB_00481b58;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00473a90();
                        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x49) {
                          *(undefined4 *)(puVar14 + -0x244) = 0;
                          goto LAB_00483e8c;
                        }
                        *(undefined4 *)(puVar14 + -0x240) = 0;
                        goto LAB_00485ebc;
                      case 0x46:
                        if (DAT_020b8ea4 == 'Z' && _DAT_020b8ea0 == 0x45455246) {
LAB_00483f9b:
                          DAT_00791480 = -DAT_00791480;
                          if (DAT_00791480 < 0) {
                            FUN_005f33c9(puVar14,0x483fd0);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x483feb);
                          }
                          else {
                            FUN_005f33c9(puVar14,0x48400f);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x48402a);
                          }
                          *(undefined4 *)(puVar14 + -0x23c) = 0;
                        }
                        else {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_00493e10();
                          *(undefined4 *)(puVar14 + -0x238) = 0;
                        }
                        goto LAB_00485edd;
                      case 0x47:
                        goto DAT_00484053;
                      case 0x49:
                        goto LAB_00485c38;
                      case 0x4a:
                        goto code_r0x004840e1;
                      case 0x4b:
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00401f46();
                        *(undefined4 *)(puVar14 + -0x1dc) = 0;
                        goto LAB_004861ab;
                      case 0x4c:
                        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) {
                          *(undefined4 *)(puVar14 + -0x1d0) = 0;
                          goto LAB_004858db;
                        }
                        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_0059414c) {
                          *(undefined4 *)(puVar14 + -0x1cc) = 0;
                          goto DAT_0048441d;
                        }
                        bVar28 = false;
                        if (P2 == f_0) {
                          *(undefined4 *)(puVar14 + -0x1c8) = 0;
code_r0x004840e1:
                          iVar11 = 1;
                          pbVar19 = (byte *)((int)&DAT_020b8ea0 + 1);
                          pbVar24 = &UNK_007626a0;
                          goto code_r0x004840f2;
                        }
                        ffree(in_ST0);
                        Var31 = thunk_FUN_005725fa();
                        DAT_0078b4e4 = _DAT_020b8ea0 >> 8 & 0xff;
                        DAT_0078b4e0 = 0x4c;
                        *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                        *(ushort *)(puVar14 + -0x6be) =
                             (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                        *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
                        iRam00828570 = *(int *)(puVar14 + -0x6bc);
                        *(undefined2 *)(puVar14 + -0x6c0) = *(undefined2 *)(puVar14 + -0x6c0);
                        *(ushort *)(puVar14 + -0x6be) =
                             (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                        *(int *)(puVar14 + -0x6bc) = (int)ROUND(P3);
                        in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
                        iRam0082856c = *(int *)(puVar14 + -0x6bc);
                        if (*(int *)(puVar14 + -0x6bc) == 0) {
                          iRam0082856c = iRam00828570;
                        }
                        ffree(Var31);
                        Var31 = lineup_pass(0x828570,0x82856c,&f_0,&UNK_0076269c);
                        ffree(Var31);
                        Var31 = draw_items();
                        ffree(Var31);
                        in_ST0 = (float10)thunk_FUN_00549422();
                        *(undefined4 *)(puVar14 + -0x1c4) = 0;
                        goto LAB_00485edd;
                      case 0x4d:
                        goto code_r0x004854b7;
                      case 0x4e:
                        goto code_r0x00484a12;
                      case 0x4f:
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_004f7808();
                        *(undefined4 *)(puVar14 + -0x198) = 0;
                        goto LAB_00485edd;
                      case 0x50:
DAT_0048441d:
                        if ((_DAT_020b8ea0 & 0xffffff) == 0x414c50) {
                          *(undefined4 *)(puVar14 + -0x194) = 0;
                          goto LAB_00484442;
                        }
                        if (_DAT_020b8ea0 == 0x48544150) {
                          *(undefined4 *)(puVar14 + -400) = 0;
                        }
                        else {
                          if ((_DAT_020b8ea0 & 0xffff) == 0x4150) {
                            ffree(in_ST0);
                            in_ST0 = (float10)func_0x00401807();
                            *(undefined4 *)(puVar14 + -0x188) = 0;
                            goto LAB_004861ab;
                          }
                          *(undefined4 *)(puVar14 + -0x18c) = 0;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00510b90();
                        _DAT_009c6ad4 = f_0;
                        if (ITEM_WORDS < 0) {
                          DAT_01fbb8a0 = 0;
                          DAT_00791448 = 0;
                          ITEM_I = 0;
                          ITEM_WORDS = 0;
                          *(undefined4 *)(puVar14 + -0x184) = 0;
                          goto LAB_00486181;
                        }
                        iVar11 = FUN_005f4660(0x20);
                        if (iVar11 != 0) {
                          ffree(extraout_ST0_08);
                          in_ST0 = (float10)thunk_FUN_00488a8d();
                          if (DAT_02052740 != 0) {
                            *(undefined4 *)(puVar14 + -0x180) = 0;
                            goto LAB_004807ec;
                          }
                          *(undefined4 *)(puVar14 + -0x17c) = 0;
                          goto LAB_00486181;
                        }
                        if ((_DAT_020b8ea0 & 0xffffff) == 0x545350) {
                          in_ST0 = (float10)FUN_005f34d1(puVar14,&UNK_00484dd4);
                          *(undefined4 *)(puVar14 + -0x178) = 0;
                        }
                        else if (((_DAT_020b8ea0 & 0xffffff) == 0x584d50) ||
                                ((_DAT_020b8ea0 & 0xff) == 0x58)) {
                          *(undefined4 *)(puVar14 + -0x174) = 0;
                          in_ST0 = extraout_ST0_08;
                        }
                        else {
                          DAT_01fbb8a0 = 0;
                          iVar11 = FUN_005f4660(0x20);
                          if (iVar11 == 0) {
                            in_ST0 = (float10)FUN_005f34d1(puVar14,&UNK_00484e70);
                            *(undefined4 *)(puVar14 + -0x16c) = 0;
                          }
                          else {
                            *(undefined4 *)(puVar14 + -0x170) = 0;
                            in_ST0 = extraout_ST0_09;
                          }
                        }
                        goto LAB_00485edd;
                      case 0x51:
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00401f46();
                        *(undefined4 *)(puVar14 + -0x168) = 0;
                        goto LAB_00485edd;
                      case 0x53:
LAB_004850c9:
                        if (((((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x53) &&
                             ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x4d)) &&
                            ((_DAT_020b8ea0 & 0xffff) == 0x5453)) &&
                           ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x55)) {
                          *(undefined4 *)(puVar14 + -0x144) = 0;
                          goto LAB_00481b58;
                        }
                        if ((undefined **)(_DAT_020b8ea0 & 0xffffff) != &PTR_DAT_00464353) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_0053ec10();
                          DAT_00791178 = DAT_009af5c4;
                          DAT_00791460 = DAT_009af5c0;
                          *(undefined4 *)(puVar14 + -0x13c) = 0;
                          goto LAB_00485edd;
                        }
                        *(undefined4 *)(puVar14 + -0x140) = 0;
                      case 0x48:
                        *(undefined4 *)(puVar14 + -0x20c) = 0;
                        iVar11 = FUN_005f4660(0x20);
                        Var31 = extraout_ST0_10;
                        if ((iVar11 == 0) &&
                           (iVar11 = FUN_005f4660(0x20), Var31 = extraout_ST0_11, iVar11 == 0)) {
                          ffree(extraout_ST0_11);
                          in_ST0 = (float10)thunk_FUN_0054b1fc(&DAT_00828578);
                          *(undefined4 *)(puVar14 + -0x204) = 0;
                        }
                        else {
                          *(undefined4 *)(puVar14 + -0x208) = 0;
                          ffree(Var31);
                          in_ST0 = (float10)thunk_FUN_0054b1fc(&DAT_00828578);
                          *DAT_00828558 = 0;
                          *(undefined4 *)(puVar14 + -0x200) = 0;
                        }
                        goto LAB_00485edd;
                      case 0x54:
                        if (DAT_020b8ea4 != ' ' || _DAT_020b8ea0 != 0x42505954) {
                          *(undefined4 *)(puVar14 + -0x138) = 0;
                          if ((_DAT_020b8ea0 & 0xffff) != 0x5254) {
                            *(undefined4 *)(puVar14 + -0x130) = 0;
                            if ((_DAT_020b8ea0 & 0xffffff) != 0x504f54) {
                              *(undefined4 *)(puVar14 + -0x118) = 0;
                              goto LAB_004852b4;
                            }
                            *(undefined4 *)(puVar14 + -0x11c) = 0;
                            goto code_r0x004857ea;
                          }
                          if (P2 == f_0) {
                            *(undefined4 *)(puVar14 + -300) = 0;
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_004a1240(&DAT_007627e4);
                            *(undefined4 *)(puVar14 + -0x120) = 0;
                            goto LAB_00485edd;
                          }
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_0055b1f8();
                          if (DAT_02052740 != 0) {
                            *(undefined4 *)(puVar14 + -0x128) = 0;
                            goto LAB_004807ec;
                          }
                          *(undefined4 *)(puVar14 + -0x124) = 0;
                          goto LAB_00485edd;
                        }
                        _DAT_020b8ea0 = _UNK_00762600;
                        DAT_020b8ea4 = UNK_00762604;
                        DAT_0078b4e0 = 0x4d;
                        DAT_0078b4e4 = 0x20;
                        *(undefined4 *)(puVar14 + -0x134) = 0;
code_r0x004854b7:
                        if ((_DAT_020b8ea0 & 0xffff) == 0x534d) {
                          *(undefined4 *)(puVar14 + -0x1c0) = 0;
                        }
                        else {
                          if ((_DAT_020b8ea0 & 0xffff) == 0x584d) {
                            DAT_01fbb8a0 = 0;
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_004a217d();
                            _DAT_020b90a0 = CONCAT12(DAT_020b90a2,_UNK_007625fc);
                            *(undefined4 *)(puVar14 + -0x1bc) = 0;
                            goto LAB_004861ab;
                          }
                          if (((((_DAT_020b8ea0 >> 8 & 0xff) == 0x44) ||
                               ((_DAT_020b8ea0 >> 8 & 0xff) == 0x55)) ||
                              ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20)) ||
                             ((_DAT_020b8ea0 >> 8 & 0xff) == 0x53)) {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_004a1240(&DAT_007627e4);
                            goto code_r0x00485e1c;
                          }
                          *(undefined4 *)(puVar14 + -0x1b8) = 0;
                          if ((_DAT_020b8ea0 & 0xffffff) == 0x204d4d) {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_00468df8(&DAT_007627bc);
                            *(undefined4 *)(puVar14 + -0x1ac) = 0;
                            goto LAB_00485edd;
                          }
                          *(undefined4 *)(puVar14 + -0x1b0) = 0;
                          if ((_DAT_020b8ea0 & 0xffffff) == 0x44494d) {
                            *(undefined4 *)(puVar14 + -0x1a8) = 0;
                            goto code_r0x004857ea;
                          }
                        }
code_r0x004855bf:
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00404b0b();
                        *(undefined4 *)(puVar14 + -0x1a4) = 0;
                        goto LAB_00485edd;
                      case 0x55:
                        if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) ||
                           ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a)) {
                          ffree(in_ST0);
                          in_ST0 = (float10)func_0x00405d1c();
                          *(undefined4 *)(puVar14 + -0x104) = 0;
                          goto LAB_00486181;
                        }
                        if ((_DAT_020b8ea0 & 0xffffff) == 0x444e55) {
                          ffree(in_ST0);
                          in_ST0 = (float10)func_0x00401fcd();
                          if (DAT_0078b4e0 == 0x49) {
                            *(undefined4 *)(puVar14 + -0x100) = 0;
                            goto LAB_00485c38;
                          }
                        }
                        else {
                          ffree(in_ST0);
                          in_ST0 = (float10)func_0x00401fff();
                        }
                        *(undefined4 *)(puVar14 + -0xfc) = 0;
                        goto LAB_00485edd;
                      case 0x56:
                        if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) ||
                           ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a)) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_00536adc();
                          *(undefined4 *)(puVar14 + -0xf4) = 0;
                          goto LAB_004861ab;
                        }
                        *(undefined4 *)(puVar14 + -0xf8) = 0;
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00575e58();
                        if (DAT_02052740 != 0) {
                          *(undefined4 *)(puVar14 + -0xf0) = 0;
                          goto LAB_004807ec;
                        }
                        *(undefined4 *)(puVar14 + -0xec) = 0;
                        goto LAB_00485edd;
                      case 0x57:
                        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) {
                          *(undefined4 *)(puVar14 + -0xe8) = 0;
                          goto LAB_004858db;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00401f5a();
                        *(undefined4 *)(puVar14 + -0xe4) = 0;
                        goto LAB_00485edd;
                      case 0x58:
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00536adc();
                        if (DAT_02052740 != 0) {
                          *(undefined4 *)(puVar14 + -0xe0) = 0;
                          goto LAB_004807ec;
                        }
                        *(undefined4 *)(puVar14 + -0xdc) = 0;
                        goto LAB_004861ab;
                      case 0x59:
                        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) {
                          *(undefined4 *)(puVar14 + -0xd8) = 0;
                          goto LAB_00485edd;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)func_0x00401d61();
                        *(undefined4 *)(puVar14 + -0xd4) = 0;
                        goto LAB_004861ab;
                      case 0x5a:
                        goto LAB_004857a3;
                      }
                      if (DAT_020b90a1 == 'r') {
                        if (DAT_020b90a2 == 'y') {
                          *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                          *(ushort *)(puVar14 + -0x6be) =
                               (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                          *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
                          DAT_009af5c4 = *(uint *)(puVar14 + -0x6bc);
                          *(undefined2 *)(puVar14 + -0x6c0) = *(undefined2 *)(puVar14 + -0x6c0);
                          *(ushort *)(puVar14 + -0x6be) =
                               (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                          *(int *)(puVar14 + -0x6bc) = (int)ROUND(P3);
                          in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
                          DAT_009af5c0 = *(uint *)(puVar14 + -0x6bc);
                          *(undefined4 *)(puVar14 + -0x160) = 0;
                          goto LAB_00485edd;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00488a8d();
                        *(undefined4 *)(puVar14 + -0x15c) = 0;
                        goto LAB_00486181;
                      }
                      *(undefined4 *)(puVar14 + -0x164) = 0;
LAB_00484edf:
                      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00584552) {
                        ffree(in_ST0);
                        in_ST0 = (float10)FUN_00486214();
                        *(undefined4 *)(puVar14 + -0x158) = 0;
                        goto LAB_0048083c;
                      }
                      ffree(in_ST0);
                      in_ST0 = (float10)thunk_FUN_00522bd8();
                      _DAT_009c6ad4 = f_0;
                      if ((_DAT_020b8ea0 & 0xffff) == 0x2a49) {
                        *(undefined4 *)(puVar14 + -0x154) = 0;
                        goto LAB_00485c38;
                      }
                      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x55) {
                        *(undefined4 *)(puVar14 + -0x150) = 0;
LAB_00485a81:
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00449b86();
                        if ((IP1 == 0xb) && (IP13 == 99)) {
                          *(undefined4 *)(puVar14 + -0x2b8) = 0;
                        }
                        else {
LAB_00485aa9:
                          if ((DAT_02052740 == 0) && (-1 < DAT_01b9d624)) {
                            _DAT_020b8ea0 = CONCAT12(DAT_0076260a,DAT_00762608);
                            DAT_0078b4e4 = 0;
                            P2 = (float)ITEM_I;
                            *(undefined4 *)(puVar14 + -0x2b0) = 0;
                            goto LAB_00485c38;
                          }
                          *(undefined4 *)(puVar14 + -0x2b4) = 0;
                        }
                      }
                      else {
                        if (((DAT_02052740 == 0) && (ITEM_I == 0)) && (DAT_0078b4e4 != 0x45)) {
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x484fa2);
code_r0x00484fa6:
                          DAT_01a14bb0 = 0;
                          _DAT_020b90a0 = _DAT_020b90a0 & 0xffff00;
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_00579770(&DAT_00762614,1,&DAT_020b90a0);
                          *DAT_01fbb7c0 = 0;
                          *DAT_01fbb844 = 0;
                          DAT_00791448 = 0;
                          *(undefined4 *)(puVar14 + -0x148) = 0;
                          goto LAB_00485edd;
                        }
                        *(undefined4 *)(puVar14 + -0x14c) = 0;
                      }
                      goto LAB_00485edd;
                    }
                    puVar15 = puVar14;
                    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_0054464c) {
                      if (DAT_0078dc30 == 1) {
                        *(undefined4 *)(puVar14 + -0x394) = 0;
LAB_004830c3:
                        DAT_0078dc30 = 0;
                        DAT_01be6d60 = 2;
                        FUN_005f33c9(puVar14,0x4830f4);
                        Var31 = FUN_005f34d1(puVar14,0x48310f);
                        if ((3 < DAT_020b8e50) && (DAT_020b8e50 < 9)) {
                          pcVar20 = "Move All ";
                          puVar18 = &DAT_01a14954;
                          for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
                            *puVar18 = *(undefined4 *)pcVar20;
                            pcVar20 = pcVar20 + 4;
                            puVar18 = puVar18 + 1;
                          }
                        }
                        ffree(Var31);
                        in_ST0 = (float10)thunk_FUN_0054de6b();
                        *(undefined4 *)(puVar14 + -0x38c) = 0;
                        puVar15 = puVar14;
                      }
                      else {
                        DAT_0078dc30 = 1;
                        DAT_01be6d60 = 0;
                        pcVar20 = "Move Left End -- P3/P4";
                        puVar18 = &DAT_01a14954;
                        for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
                          *puVar18 = *(undefined4 *)pcVar20;
                          pcVar20 = pcVar20 + 4;
                          puVar18 = puVar18 + 1;
                        }
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_0054de6b();
                        *(undefined4 *)(puVar14 + -0x398) = 0;
                      }
                    }
                    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544752) {
                      if (DAT_0078dc30 == 2) goto LAB_004830c3;
                      DAT_0078dc30 = 2;
                      DAT_01be6d60 = 1;
                      pcVar20 = "Move Right End -- P5/P6";
                      puVar18 = &DAT_01a14954;
                      for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
                        *puVar18 = *(undefined4 *)pcVar20;
                        pcVar20 = pcVar20 + 4;
                        puVar18 = puVar18 + 1;
                      }
                      ffree(in_ST0);
                      in_ST0 = (float10)thunk_FUN_0054de6b();
                      *(undefined4 *)(puVar14 + -0x390) = 0;
                    }
                    else {
                      if (DAT_020b8ea4 == ' ' && _DAT_020b8ea0 == 0x564d524e) {
                        *(undefined4 *)(puVar14 + -0x388) = 0;
                        goto LAB_004830c3;
                      }
                      DAT_01a14bb4 = EDIT_ITEM;
                      if ((char)DAT_020b8ea0 < '!') {
                        FUN_005f33c9(puVar14,0x483185);
                        in_ST0 = (float10)FUN_005f34d1(puVar14,0x4831a0);
                        if (DAT_0078b370 < 0) {
                          _DAT_020b8ea0 = CONCAT12(DAT_0076276a,DAT_00762768);
                        }
                      }
LAB_0048186b:
                      if (DAT_02052740 == 0) {
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00518448();
                      }
                      if (((_DAT_020b8ea0 & 0xffffff) == 0x434e49) &&
                         (_DAT_020b8ea0 >> 0x18 != 0x48)) goto LAB_00483249;
                      if ((_DAT_020b8ea0 & 0xffff) != 0x4d50) {
                        *(undefined4 *)(puVar14 + -0x380) = 0;
                        *DAT_01fbb7c0 = DAT_00791474;
                        if ((_DAT_020b8ea0 & 0xffff) == 0x4649) {
                          *(undefined4 *)(puVar14 + -0x36c) = 0;
                          goto LAB_00486181;
                        }
LAB_00481928:
                        if ((_DAT_020b8ea0 & 0xffff) == 0x4353) {
                          *(undefined4 *)(puVar14 + -0x368) = 0;
                          goto LAB_004850c9;
                        }
                        if (((DAT_020b90a3 == '=') || (DAT_020b90a1 == '=')) ||
                           (DAT_020b90a2 == '=')) {
                          if (P2 == f_0) {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_0054c669(&P2,&P3);
                          }
                          *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                          *(ushort *)(puVar14 + -0x6be) =
                               (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                          *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
                          in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
                          P2 = *(float *)(&DAT_020b943c + *(int *)(puVar14 + -0x6bc) * 4);
                        }
                        if ((P1 == f_0) && ((_DAT_020b8ea0 & 0xffff) != 0x4d50)) goto LAB_00481b58;
                        *(undefined4 *)(puVar14 + -0x364) = 0;
                        goto LAB_00481a9d;
                      }
                      if (((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x20) &&
                         ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x2a)) {
                        *(undefined4 *)(puVar14 + -0x37c) = 0;
                        goto LAB_00481928;
                      }
                      Var31 = FUN_005f34d1(puVar14,0x481a3d);
                      ffree(Var31);
                      in_ST0 = (float10)thunk_FUN_0046f81d(&DAT_00791178);
                      if ((char)DAT_020b8ea0 < '!') {
                        *DAT_01fbb7c0 = DAT_00791474;
                        if ((int)DAT_00791178 < 2) {
                          *(undefined4 *)(puVar14 + -0x374) = 0;
                          goto LAB_00485edd;
                        }
                        *(undefined4 *)(puVar14 + -0x370) = 0;
                        goto LAB_00481a9d;
                      }
                      *(undefined4 *)(puVar14 + -0x378) = 0;
LAB_00480854:
                      if ((_DAT_020b8ea0 & 0xff) != 0x2c) {
                        DAT_009c66c8 = DAT_020b8e50;
                        if (DAT_020b8e50 == 7) {
                          if (DAT_020b9458 == f_0) {
                            DAT_009c66c8 = 8;
                          }
                          if ((f_20 <= DAT_020b9458) && (DAT_020b9458 < f_23)) {
                            DAT_009c66c8 = 9;
                          }
                        }
                        if ((_DAT_020b8ea0 & 0xffff) != 0x7e7e) goto LAB_004817fd;
                        *(undefined4 *)(puVar14 + -0x4e0) = 0;
LAB_00480aab:
                        *(undefined4 *)(puVar14 + -0x6b8) = 0;
                        *(undefined4 *)(puVar14 + -0x6c8) = 3;
                        *(undefined1 **)(puVar14 + -0x6c4) = &DAT_020b8ea2;
                        *(uint **)(puVar14 + -0x6c0) = &DAT_008285a4;
                        ffree(in_ST0);
                        in_ST0 = (float10)FUN_005f9240(puVar14 + -0x6b8,0x784ff00,&DAT_007628fc,
                                                       puVar14 + -0x6c8,&DAT_00791138);
                        DAT_020b8ea5 = '\0';
                        if (EDIT_ITEM == 0) {
                          if (DAT_008285a4 == 0x71) {
                            FUN_005f33c9(puVar14,0x480b3f);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480b5a);
                          }
                          if (DAT_008285a4 == 0x72) {
                            FUN_005f33c9(puVar14,0x480b85);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480ba0);
                          }
                          if (DAT_008285a4 == 0x73) {
                            *(undefined4 *)(puVar14 + -0x478) = 0;
                            goto LAB_00483f9b;
                          }
                          if (DAT_008285a4 == 0x75) {
                            FUN_005f33c9(puVar14,0x480be3);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480bfe);
                          }
                          if (DAT_008285a4 == 0x79) {
                            FUN_005f33c9(puVar14,0x480c29);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480c44);
                          }
                          if (DAT_008285a4 == 0x7c) {
                            FUN_005f33c9(puVar14,0x480c6f);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480c8a);
                          }
                          if (DAT_008285a4 == 0x76) {
                            FUN_005f33c9(puVar14,0x480cb5);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480cd0);
                          }
                          if (DAT_008285a4 == 0x77) {
                            FUN_005f33c9(puVar14,0x480cfb);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480d16);
                          }
                          if (DAT_008285a4 == 0x78) {
                            FUN_005f33c9(puVar14,0x480d41);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480d5c);
                          }
                          if (DAT_008285a4 == 0x7b) {
                            FUN_005f33c9(puVar14,0x480d87);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480da2);
                            DAT_008285a4 = 0;
                          }
                          if (DAT_008285a4 == 0x7a) {
                            FUN_005f33c9(puVar14,0x480dd5);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480df0);
                            DAT_008285a4 = 0;
                          }
                          puVar15 = puVar14;
                          if (DAT_008285a4 == 0x74) {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_00468df8(&DAT_007628d8);
                            *(undefined4 *)(puVar14 + -0x474) = 0;
                            goto LAB_004807d0;
                          }
                          if (DAT_008285a4 == 0x28) {
                            ffree(in_ST0);
                            thunk_FUN_00535d00(&DAT_007628d4);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480e62);
                            DAT_008285a4 = 0;
                            *(undefined4 *)(puVar14 + -0x470) = 0;
                            puVar15 = puVar14;
                            goto LAB_004807d0;
                          }
                          if (DAT_008285a4 == 0x26) {
                            ffree(in_ST0);
                            thunk_FUN_00535d00(&DAT_007628d0);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480eb7);
                            DAT_008285a4 = 0;
                            *(undefined4 *)(puVar14 + -0x46c) = 0;
                            puVar15 = puVar14;
                            goto LAB_004807d0;
                          }
                          if ((DAT_008285a4 == 0x25) || (DAT_008285a4 == 0x27)) {
                            *(undefined4 *)(puVar14 + -0x468) = 0;
                            goto LAB_004807d0;
                          }
                          if (DAT_008285a4 == 0x78) {
                            FUN_005f33c9(puVar14,0x480f0f);
                            in_ST0 = (float10)FUN_005f34d1(puVar14,0x480f2a);
                          }
                          goto LAB_00482564;
                        }
                        if (DAT_008285a4 == 0x21) {
                          FUN_005f33c9(puVar14,0x480f69);
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x480f84);
                          *(undefined4 *)(puVar14 + -0x464) = 0;
                        }
                        else if (DAT_008285a4 == 0x22) {
                          FUN_005f33c9(puVar14,0x480fbe);
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x480fd9);
                          *(undefined4 *)(puVar14 + -0x460) = 0;
                        }
                        else {
                          if (DAT_008285a4 != 0x23) {
                            if (DAT_008285a4 == 0x24) {
                              FUN_005f33c9(puVar14,0x481068);
                              in_ST0 = (float10)FUN_005f34d1(puVar14,0x481083);
                              *(undefined4 *)(puVar14 + -0x458) = 0;
                              goto LAB_0048186b;
                            }
                            if (DAT_008285a4 == 0x25) {
                              FUN_005f33c9(puVar14,0x4810bd);
                              in_ST0 = (float10)FUN_005f34d1(puVar14,0x4810d8);
                              *(undefined4 *)(puVar14 + -0x454) = 0;
                            }
                            else if (DAT_008285a4 == 0x26) {
                              FUN_005f33c9(puVar14,0x481112);
                              in_ST0 = (float10)FUN_005f34d1(puVar14,0x48112d);
                              *(undefined4 *)(puVar14 + -0x450) = 0;
                            }
                            else if (DAT_008285a4 == 0x27) {
                              FUN_005f33c9(puVar14,0x481167);
                              in_ST0 = (float10)FUN_005f34d1(puVar14,0x481182);
                              *(undefined4 *)(puVar14 + -0x44c) = 0;
                            }
                            else {
                              if (DAT_008285a4 != 0x28) {
                                if (DAT_008285a4 == 0x2e) {
                                  FUN_005f33c9(puVar14,0x481355);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x481370);
                                  *(undefined4 *)(puVar14 + -0x444) = 0;
                                }
                                else if (DAT_008285a4 == 0x71) {
                                  FUN_005f33c9(puVar14,0x4813aa);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x4813c5);
                                  *(undefined4 *)(puVar14 + -0x440) = 0;
                                }
                                else if (DAT_008285a4 == 0x72) {
                                  FUN_005f33c9(puVar14,0x4813ff);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x48141a);
                                  *(undefined4 *)(puVar14 + -0x43c) = 0;
                                }
                                else if (DAT_008285a4 == 0x75) {
                                  if (DAT_020b8e50 == 2) {
                                    FUN_005f33c9(puVar14,0x481461);
                                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x48147c);
                                  }
                                  else if (DAT_020b8e50 == 8) {
                                    FUN_005f33c9(puVar14,0x4814ac);
                                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4814c7);
                                  }
                                  else if (DAT_020b8e50 == 0xe) {
                                    FUN_005f33c9(puVar14,0x4814f7);
                                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x481512);
                                  }
                                  else {
                                    if (DAT_020b8e50 != 0xf) {
                                      *(undefined4 *)(puVar14 + -0x438) = 0;
                                      goto LAB_004816a0;
                                    }
                                    FUN_005f33c9(puVar14,0x48153f);
                                    in_ST0 = (float10)FUN_005f34d1(puVar14,0x48155a);
                                  }
                                  *(undefined4 *)(puVar14 + -0x434) = 0;
                                }
                                else if ((DAT_008285a4 == 0x7a) && (DAT_020b8e50 == 0xb)) {
                                  FUN_005f33c9(puVar14,0x4815ac);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x4815c7);
                                  *(undefined4 *)(puVar14 + -0x430) = 0;
                                }
                                else if ((DAT_008285a4 == 0x76) && (DAT_020b8e50 == 10)) {
                                  FUN_005f33c9(puVar14,0x48160a);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x481625);
                                  *(undefined4 *)(puVar14 + -0x42c) = 0;
                                }
                                else {
                                  if ((DAT_008285a4 != 0x79) || (DAT_020b8e50 != 10))
                                  goto LAB_00481696;
                                  FUN_005f33c9(puVar14,0x481668);
                                  in_ST0 = (float10)FUN_005f34d1(puVar14,0x481683);
                                  *(undefined4 *)(puVar14 + -0x428) = 0;
                                }
                                goto LAB_0048186b;
                              }
                              FUN_005f33c9(puVar14,0x4811bd);
                              in_ST0 = (float10)FUN_005f34d1(puVar14,0x4811d8);
                              *(undefined4 *)(puVar14 + -0x448) = 0;
                            }
                            if (DAT_0078dc45 != 0) {
                              if (((_DAT_020b8ea0 & 0xff) != 0x72) &&
                                 ((_DAT_020b8ea0 & 0xff) != 0x6c)) {
                                for (iVar11 = 1; iVar11 < 0x33; iVar11 = iVar11 + 1) {
                                  *(float *)(&P0 + iVar11 * 4) = f_0;
                                }
                                in_ST0 = (float10)FUN_005f34d1(puVar14,0x481267);
                                DAT_0078b4e0 = 0;
                                *(uint *)(puVar14 + -0x6bc) = DAT_0078dc45 * 100;
                                P1 = (float)*(int *)(puVar14 + -0x6bc);
                                P2 = DAT_0078dc3d;
                                if ((DAT_008285a4 == 0x25) || (DAT_008285a4 == 0x28)) {
                                  in_ST0 = (float10)DAT_0078dc3d;
                                  P2 = (float)-in_ST0;
                                }
                                *(undefined4 *)(puVar14 + -0x418) = 0;
                                goto LAB_00481a9d;
                              }
                              *(undefined4 *)(puVar14 + -0x41c) = 0;
                              _DAT_008285e8 = f_0_1;
                              if ((_DAT_020b8ea0 & 0xff) == 0x6c) {
                                in_ST0 = (float10)f_0_1;
                                _DAT_008285e8 = (float)-in_ST0;
                              }
                              DAT_0078dc3d = _DAT_008285e8 + DAT_0078dc3d;
                              ffree(in_ST0);
                              in_ST0 = (float10)thunk_FUN_0048ecfb();
                              *(undefined4 *)(puVar14 + -0x414) = 0;
                              puVar16 = puVar14;
                              goto LAB_004861ab;
                            }
                            *(undefined4 *)(puVar14 + -0x420) = 0;
                            goto LAB_0048186b;
                          }
                          FUN_005f33c9(puVar14,0x481013);
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x48102e);
                          *(undefined4 *)(puVar14 + -0x45c) = 0;
                        }
                        goto LAB_0048186b;
                      }
                      DAT_008285a4 = 0;
                      for (iVar11 = 1; iVar11 < 0x41; iVar11 = iVar11 + 1) {
                        *(float *)(iVar11 * 4 + 0x8288bc) = f_0;
                      }
                      ffree(in_ST0);
                      Var31 = thunk_FUN_00518448();
                      ffree(Var31);
                      Var31 = thunk_FUN_0054c8e5(&DAT_020b8ea0,1,&DAT_0082858c);
                      *(int *)(puVar14 + -0x4f0) = DAT_0082858c;
                      DAT_00791460 = 1;
                      iVar11 = DAT_0082858c;
                      while (0 < iVar11) {
                        bVar29 = iVar11 == 0;
                        bVar28 = false;
                        iVar11 = 1;
                        pbVar19 = &DAT_020b909f + DAT_00791460;
                        pbVar24 = &DAT_0076290c;
                        do {
                          if (iVar11 == 0) break;
                          iVar11 = iVar11 + -1;
                          bVar28 = *pbVar19 < *pbVar24;
                          bVar29 = *pbVar19 == *pbVar24;
                          pbVar19 = pbVar19 + 1;
                          pbVar24 = pbVar24 + 1;
                        } while (bVar29);
                        if (!bVar28 && !bVar29) {
                          *(undefined4 *)(puVar14 + -0x4ec) = 0;
                          break;
                        }
                        if ((&DAT_020b909f)[DAT_00791460] == ',') {
                          DAT_008285a4 = DAT_008285a4 + 1;
                        }
                        DAT_00791460 = DAT_00791460 + 1;
                        *(int *)(puVar14 + -0x4f0) = *(int *)(puVar14 + -0x4f0) + -1;
                        iVar11 = *(int *)(puVar14 + -0x4f0);
                      }
                      DAT_00791178 = 1;
                      DAT_008285e4 = 2;
                      DAT_00791460 = DAT_008285a4 + 1;
                      iVar11 = (DAT_0082858c - DAT_00791460) + 1;
                      *(int *)(puVar14 + -0x4e8) = iVar11;
                      while (0 < iVar11) {
                        *(float *)(DAT_00791178 * 4 + 0x8288bc) = (float)(int)DAT_00791460;
                        (&DAT_008288c0)[DAT_00791178] = *(undefined4 *)(&P0 + DAT_008285e4 * 4);
                        DAT_00791178 = DAT_00791178 + 2;
                        DAT_008285e4 = DAT_008285e4 + 1;
                        DAT_00791460 = DAT_00791460 + 1;
                        *(int *)(puVar14 + -0x4e8) = *(int *)(puVar14 + -0x4e8) + -1;
                        iVar11 = *(int *)(puVar14 + -0x4e8);
                      }
                      ffree(Var31);
                      in_ST0 = (float10)thunk_FUN_0054c590(&DAT_008288c0,&P1,&DAT_00791178);
                      *(undefined4 *)(puVar14 + -0x4e4) = 0;
LAB_00481a9d:
                      ffree(in_ST0);
                      in_ST0 = (float10)edit_params();
                      if ((IP13 == 99) && (DAT_020b8e50 == 0xf || DAT_020b8e50 == 0xb)) {
                        IP13 = 0;
                        FUN_005f33c9(puVar14,0x481b01);
                        Var31 = FUN_005f34d1(puVar14,0x481b1c);
                        ffree(Var31);
                        in_ST0 = (float10)edit_letters();
                        *(undefined4 *)(puVar14 + -0x318) = 0;
                        puVar16 = puVar14;
                        goto LAB_004861ab;
                      }
                      if (DAT_0078b4e0 != 0xffffffff) {
                        if (DAT_0205274c == -1) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_00473454();
                          DAT_0205274c = 0;
                          *(undefined4 *)(puVar14 + -0x30c) = 0;
                          goto LAB_00485ebc;
                        }
                        *(undefined4 *)(puVar14 + -0x310) = 0;
                        uVar30 = (_DAT_020b8ea0 & 0xffff) == 0x4d50;
                        if (!(bool)uVar30) {
                          ffree(in_ST0);
                          in_ST0 = (float10)thunk_FUN_0048ecfb();
                        }
                        iVar11 = 3;
                        psVar21 = &DAT_020b8ea0;
                        psVar26 = (short *)0x7625d0;
                        goto code_r0x00485e70;
                      }
                      DAT_0078b4e0 = 0x49;
                      *(undefined4 *)(puVar14 + -0x314) = 0;
LAB_00481b58:
                      if ((_DAT_020b8ea0 & 0xff) == 0x5a) {
                        *(undefined4 *)(puVar14 + -0x360) = 0;
                        goto LAB_004857a3;
                      }
                      if (((((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x41) ||
                           ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e)) ||
                          ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4d)) ||
                         (((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x50 ||
                          ((_DAT_020b8ea0 & 0xffff) != 0x4445 && (_DAT_020b8ea0 & 0xffff) != 0x5453)
                          ))) {
                        if ((DAT_0205274c == 0) && (DAT_020b8e50 == 0x10)) goto LAB_00481d10;
                        *(undefined4 *)(puVar14 + -0x358) = 0;
                      }
                      else {
                        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x42) {
                          P3 = f_1;
                          P4 = f_2;
                          DAT_00828580 = 1;
                          _DAT_020b8ea0 = CONCAT12(DAT_00762978,DAT_020b8ea0);
                        }
                        if (DAT_0205274c < 1) {
LAB_00481d10:
                          if ((((_DAT_020b8ea0 & 0xff) == 0x42) || ((_DAT_020b8ea0 & 0xff) == 0x58))
                             || ((_DAT_020b8ea0 & 0xff) == 0x4e)) {
                            *(undefined4 *)(puVar14 + -0x354) = 0;
                          }
                          else {
                            _DAT_01c26198 = EDIT_ITEM;
                            DAT_0082857c = (&ITEM_PTR0)[EDIT_ITEM];
                            DAT_00828578 = EDIT_ITEM + 1;
                            DAT_00828574 = (&ITEM_PTR0)[DAT_00828578] - DAT_0082857c;
                            ffree(in_ST0);
                            DAT_01c26194 = DAT_00828574;
                            in_ST0 = (float10)thunk_FUN_0054c590(&ITEM_LEN + DAT_0082857c,
                                                                 &DAT_01c25fa0,&DAT_01c26194);
                          }
                        }
                        else {
                          ffree(in_ST0);
                          Var31 = push_words(&DAT_0076286c,&P1);
                          puVar18 = (undefined4 *)&DAT_020b8ea0;
                          puVar23 = &DAT_00828614;
                          for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
                            *puVar23 = *puVar18;
                            puVar18 = puVar18 + 1;
                            puVar23 = puVar23 + 1;
                          }
                          ffree(Var31);
                          Var31 = thunk_FUN_00473228(&EDIT_ITEM);
                          DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
                          ffree(Var31);
                          Var31 = thunk_FUN_00476628();
                          ffree(Var31);
                          in_ST0 = (float10)pop_words(&DAT_0076286c,&P1);
                          puVar18 = &DAT_00828614;
                          puVar23 = (undefined4 *)&DAT_020b8ea0;
                          for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
                            *puVar23 = *puVar18;
                            puVar18 = puVar18 + 1;
                            puVar23 = puVar23 + 1;
                          }
                          DAT_0205274c = 0;
                          EDIT_ITEM = 0;
                          *(undefined4 *)(puVar14 + -0x35c) = 0;
                        }
                      }
LAB_00481de1:
                      if ((_DAT_020b8ea0 & 0xffff) == 0x4552) {
                        *(undefined4 *)(puVar14 + -0x350) = 0;
                        goto LAB_00484edf;
                      }
                      if (EDIT_ITEM == 0) {
                        *(undefined4 *)(puVar14 + -0x34c) = 0;
LAB_00485bb7:
                        ffree(in_ST0);
                        in_ST0 = (float10)edit_letters();
                        if (DAT_00828580 != 0) {
                          if ((EDIT_ITEM != 0) && ((_DAT_020b8ea0 & 0xff) != 0x58)) {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_00410400(&DAT_00828580);
                            *(undefined4 *)(puVar14 + -0x340) = 0;
                            puVar16 = puVar14;
                            goto LAB_004861ab;
                          }
                          DAT_00828580 = 0;
                          *(undefined4 *)(puVar14 + -0x344) = 0;
                        }
                        if (_DAT_020b90a0 == 0x5843) {
                          *(undefined4 *)(puVar14 + -0x33c) = 0;
                          goto LAB_00485c38;
                        }
                        if (_DAT_020b90a0 == 0x5858) {
                          DAT_01a149ac = f_0;
                          DAT_020b8ea0 = CONCAT11(0x58,(char)DAT_020b8ea0);
                          *(undefined4 *)(puVar14 + -0x334) = 0;
                          goto code_r0x00485ddb;
                        }
                        *(undefined4 *)(puVar14 + -0x338) = 0;
                        if (DAT_0078b4e0 == 9999) {
                          *(undefined4 *)(puVar14 + -0x330) = 0;
                          goto LAB_00485edd;
                        }
                        if (DAT_0078b4e0 == 0xffffffff) {
                          if (EDIT_ITEM == 0) {
                            DAT_01a149ac = f_0;
                            *(undefined4 *)(puVar14 + -0x328) = 0;
                          }
                          else {
                            ffree(in_ST0);
                            in_ST0 = (float10)thunk_FUN_0048ecfb();
                            *(undefined4 *)(puVar14 + -0x324) = 0;
                          }
                          goto LAB_00485edd;
                        }
                        *(undefined4 *)(puVar14 + -0x32c) = 0;
                        if (EDIT_ITEM != 0) {
                          *(undefined4 *)(puVar14 + -800) = 0;
                          goto LAB_00481a9d;
                        }
                        DAT_01a149ac = f_0;
                        *(undefined4 *)(puVar14 + -0x31c) = 0;
                        goto LAB_00485edd;
                      }
                      if (((P2 == f_0) || ((_DAT_020b8ea0 & 0xff) != 0x50)) ||
                         ((_DAT_020b8ea0 >> 8 & 0xff) != 0x2a)) goto LAB_00485bb7;
                      FUN_005f33c9(puVar14,0x481e75);
                      in_ST0 = (float10)FUN_005f34d1(puVar14,0x481e90);
                      DAT_009ae2bc = CONCAT22(_DAT_020b90a1,(undefined2)DAT_009ae2bc);
                      if (DAT_01be6d60 == 2) {
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_00468df8(&DAT_00762868);
                      }
                      *(undefined4 *)(puVar14 + -0x348) = 0;
LAB_00481ecd:
                      if ((DAT_009ae2bc & 0xffff) == 0x5051) {
                        FUN_005f34d1(puVar14,0x481f00);
                        FUN_005f33c9(puVar14,0x481f22);
                        Var31 = FUN_005f33c9(puVar14,0x481f3e);
                        ffree(Var31);
                        Var31 = thunk_FUN_0054946a(puVar14 + -0x8d0,0x207);
                        *(undefined4 *)(puVar14 + -0x6b8) = 0;
                        *(undefined4 *)(puVar14 + -0x6c8) = 2;
                        *(undefined4 *)(puVar14 + -0x6c4) = 0x9ae2be;
                        *(int **)(puVar14 + -0x6c0) = &DAT_01be6d60;
                        ffree(Var31);
                        in_ST0 = (float10)FUN_005f9240(puVar14 + -0x6b8,0x784ff00,&DAT_007628fc,
                                                       puVar14 + -0x6c8,&DAT_00791110);
                        if (DAT_01be6d6c == 0) {
                          if (DAT_01be6d60 == 2) {
                            DAT_008285a4 = 0xd8;
                            if ((8 < DAT_020b8e50) || (DAT_020b8e50 == 7 && DAT_020b9458 == f_1)) {
                              DAT_008285a4 = 0xd9;
                            }
                            ffree(in_ST0);
                            thunk_FUN_00468df8(&DAT_008285a4);
                          }
                          else {
                            *(undefined4 *)(puVar14 + -0x4d0) = 0;
                          }
                          DAT_009a9494 = 1;
                          DAT_01be6d6c = 1;
                          in_ST0 = (float10)FUN_005f34d1(puVar14,0x482078);
                          *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                          *(ushort *)(puVar14 + -0x6be) =
                               (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                          *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
                          in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
                          _DAT_00828588 = *(undefined4 *)(puVar14 + -0x6bc);
                          DAT_01be6d74 = (&DAT_02035a00)[ITEM_I];
                          DAT_01be6d70 = (&DAT_020a55a0)[ITEM_I] + -1;
                          *(undefined4 *)(puVar14 + -0x4cc) = 0;
                          puVar15 = puVar14;
                        }
                        else {
                          *(undefined4 *)(puVar14 + -0x4d4) = 0;
                          puVar15 = puVar14;
                        }
                        goto LAB_004807d0;
                      }
                      if ((_DAT_020b8ea0 == 0x6e727472) || (_DAT_020b8ea0 == 0x4e525452)) {
                        DAT_01be6d60 = 2;
                        DAT_009a9494 = 0;
                        FUN_005f34d1(puVar14,0x485b57);
                        Var31 = FUN_005f34d1(puVar14,0x485b78);
                        ffree(Var31);
                        Var31 = thunk_FUN_00468df8(&DAT_007626d8);
                        *(undefined4 *)(puVar14 + -0x4c8) = 0;
LAB_00485b9a:
                        ffree(Var31);
                        Var31 = thunk_FUN_0048ecfb();
                        ffree(Var31);
                        in_ST0 = (float10)thunk_FUN_00549422();
                        *(undefined4 *)(puVar14 + -0x5c0) = 0;
                        puVar15 = puVar14;
                      }
                      else {
                        iVar11 = 3;
                        bVar28 = false;
                        psVar21 = (short *)&DAT_009ae2bc;
                        psVar26 = (short *)&DAT_00762858;
                        do {
                          if (iVar11 == 0) break;
                          iVar11 = iVar11 + -1;
                          bVar28 = *psVar21 == *psVar26;
                          psVar21 = psVar21 + 1;
                          psVar26 = psVar26 + 1;
                        } while (bVar28);
                        if (!bVar28) goto LAB_00482142;
                        *(undefined4 *)(puVar14 + -0x4c4) = 0;
LAB_00482e57:
                        FUN_005f33c9(puVar14,0x482e75);
                        in_ST0 = (float10)FUN_005f34d1(puVar14,0x482e90);
                        DAT_01be6d60 = -1;
                        *(undefined4 *)(puVar14 + -0x490) = 0;
                        puVar15 = puVar14;
                      }
                    }
                  }
                  goto LAB_004807d0;
                }
                iVar11 = 5;
                bVar28 = false;
                pcVar20 = (char *)&DAT_020b8ea0;
                pcVar25 = "     ";
                do {
                  if (iVar11 == 0) break;
                  iVar11 = iVar11 + -1;
                  bVar28 = *pcVar20 == *pcVar25;
                  pcVar20 = pcVar20 + 1;
                  pcVar25 = pcVar25 + 1;
                } while (bVar28);
                if (!bVar28) goto LAB_0048083c;
                ffree(in_ST0);
                Var31 = thunk_FUN_00549b5b();
                ffree(Var31);
                Var31 = thunk_FUN_00473454();
                ffree(Var31);
                Var31 = thunk_FUN_0054de6b();
                ffree(Var31);
                in_ST0 = (float10)thunk_FUN_0048ecfb();
                *(undefined4 *)(puVar14 + -0x4f8) = 0;
                goto LAB_00485edd;
              }
              iVar11 = FUN_005f4660(0x20);
              in_ST0 = extraout_ST0_13;
              if (iVar11 != 0) {
                FUN_005f33c9(puVar15,0x485f9a);
                puVar14 = puVar15;
                in_ST0 = (float10)FUN_005f34d1(puVar15,0x485fb5);
                if (DAT_0078b370 == 1) {
                  DAT_009ae2c8._0_1_ = s___>_Forward_Direction___STRING_007625b8[0];
                  DAT_009ae2c8._1_1_ = s___>_Forward_Direction___STRING_007625b8[1];
                  DAT_009ae2c8._2_1_ = s___>_Forward_Direction___STRING_007625b8[2];
                  DAT_009ae2c8._3_1_ = s___>_Forward_Direction___STRING_007625b8[3];
                  DAT_009ae2cc._0_1_ = s___>_Forward_Direction___STRING_007625b8[4];
                  DAT_009ae2cc._1_1_ = s___>_Forward_Direction___STRING_007625b8[5];
                  DAT_009ae2cc._2_1_ = s___>_Forward_Direction___STRING_007625b8[6];
                  DAT_009ae2cc._3_1_ = s___>_Forward_Direction___STRING_007625b8[7];
                  DAT_009ae2d0 = s___>_Forward_Direction___STRING_007625b8[8];
                  DAT_009ae2d1._0_1_ = s___>_Forward_Direction___STRING_007625b8[9];
                  DAT_009ae2d1._1_1_ = s___>_Forward_Direction___STRING_007625b8[10];
                  DAT_009ae2d1._2_1_ = s___>_Forward_Direction___STRING_007625b8[0xb];
                }
                else {
                  DAT_009ae2c8._0_1_ = s_<___Back_007625ac[0];
                  DAT_009ae2c8._1_1_ = s_<___Back_007625ac[1];
                  DAT_009ae2c8._2_1_ = s_<___Back_007625ac[2];
                  DAT_009ae2c8._3_1_ = s_<___Back_007625ac[3];
                  DAT_009ae2cc._0_1_ = s_<___Back_007625ac[4];
                  DAT_009ae2cc._1_1_ = s_<___Back_007625ac[5];
                  DAT_009ae2cc._2_1_ = s_<___Back_007625ac[6];
                  DAT_009ae2cc._3_1_ = s_<___Back_007625ac[7];
                  DAT_009ae2d0 = s_<___Back_007625ac[8];
                }
              }
              if (EDIT_ITEM == 0) {
                DAT_009a9464._0_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x150];
                DAT_009a9464._1_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x151];
                DAT_009a9464._2_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x152];
                DAT_009a9464._3_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x153];
                DAT_009a9468._0_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x154];
                DAT_009a9468._1_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x155];
                DAT_009a9468._2_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x156];
                DAT_009a9468._3_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x157];
                DAT_009a946c._0_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x158];
                DAT_009a946c._1_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x159];
                DAT_009a946c._2_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15a];
                DAT_009a946c._3_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15b];
                DAT_009a9470._0_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15c];
                DAT_009a9470._1_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15d];
                DAT_009a9470._2_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15e];
                DAT_009a9470._3_1_ = s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc[0x15f];
                if (DAT_00791184 <= DAT_00791188) {
                  ffree(in_ST0);
                  in_ST0 = (float10)thunk_FUN_0049712c();
                  DAT_00791188 = 0;
                }
              }
              else {
                *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
                *(ushort *)(puVar14 + -0x6be) = (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
                *(int *)(puVar14 + -0x6bc) = (int)ROUND(DAT_020b9440 + f_1);
                iVar11 = *(int *)(puVar14 + -0x6bc) * 0x10;
                DAT_009a9464 = *(undefined4 *)
                                (s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc + iVar11 + 0x140);
                DAT_009a9468 = *(undefined4 *)
                                (s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc + iVar11 + 0x144);
                DAT_009a946c = *(undefined4 *)
                                (s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc + iVar11 + 0x148);
                DAT_009a9470 = *(undefined4 *)
                                (s_C_CUECDACD_CD_COMCRVCS_CS_CT_CT__007911bc + iVar11 + 0x14c);
              }
              if ((DAT_0205274c != 0) && (DAT_0078b4f0 == 1)) {
                DAT_00791188 = DAT_00791188 + 1;
              }
              **(undefined4 **)(puVar14 + 0x18) = DAT_01be6cd8;
              if ((DAT_009ae2bc & 0xffff) == 0x3d42) {
                FUN_005f33c9(puVar14,0x486104);
                FUN_005f33c9(puVar14,0x486120);
                in_ST0 = (float10)FUN_005f34d1(puVar14,0x48613b);
              }
              if (((EDIT_ITEM == 0) && (DAT_01fbb8a0 == 0)) && (DAT_0078b4f0 != 0)) {
                IP1 = 1;
                ffree(in_ST0);
                in_ST0 = (float10)thunk_FUN_00495d4f(&DAT_0078b510,0x80);
              }
              else {
                *(undefined4 *)(puVar14 + -0xc) = 0;
              }
              goto LAB_00486181;
            }
            if (((DAT_009ae2bc & 0xff) == 0x71) || ((DAT_009ae2bc & 0xffff) == 0x2051)) {
              if ((DAT_009ae2bc >> 8 & 0xff) == 0x70) {
                DAT_009ae2bc = CONCAT22(DAT_009ae2bc._2_2_,DAT_00762950);
                *(undefined4 *)(puVar14 + -0x588) = 0;
                goto LAB_00481ecd;
              }
              puVar18 = &DAT_00828bc0;
              puVar23 = (undefined4 *)&DAT_020b8ea0;
              for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar23 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar23 = puVar23 + 1;
              }
              DAT_0082859c = 2;
              ffree(in_ST0);
              thunk_FUN_00470ea5(&DAT_0082859c);
              if (DAT_0082859c == 0) {
                FUN_005f33c9(puVar14,0x47fe5a);
                in_ST0 = (float10)FUN_005f34d1(puVar14,0x47fe75);
                *(undefined4 *)(puVar14 + -0x584) = 0;
                puVar15 = puVar14;
                goto LAB_004807d0;
              }
              puVar18 = (undefined4 *)&DAT_020b8ea0;
              puVar23 = &DAT_009ae2bc;
              for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar23 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar23 = puVar23 + 1;
              }
            }
            iVar11 = FUN_005f4660(0x20);
            in_ST0 = extraout_ST0_02;
            if (iVar11 == 0) {
              ffree(extraout_ST0_02);
              in_ST0 = (float10)thunk_FUN_0054e2a1(&DAT_009ae2bc,0x200,&DAT_00828bc0,0x200);
            }
            if (DAT_01fb9630 != 0) {
              *(undefined4 *)(puVar14 + -0x580) = 0;
              goto LAB_004807d0;
            }
            if ((EDIT_ITEM != 0) && ((DAT_009ae2bc & 0xffff) == 0x7c7c)) {
              ffree(in_ST0);
              thunk_FUN_00476628();
              FUN_005f33c9(puVar14,0x47ff39);
              in_ST0 = (float10)FUN_005f34d1(puVar14,0x47ff54);
              EDIT_ITEM = 0;
              *(undefined4 *)(puVar14 + -0x57c) = 0;
              goto LAB_00482b67;
            }
            if ((DAT_01fbb8a0 == 0) && ((DAT_009ae2bc & 0xff) == 0x7c)) {
              DAT_009ae2bc = CONCAT31(DAT_009ae2bc._1_3_,0x7e);
            }
            if ((EDIT_ITEM != 0) && ((DAT_009ae2bc & 0xff) == 0x7c)) {
              DAT_009ae2bc = CONCAT31(DAT_009ae2bc._1_3_,0x7e);
            }
            puVar18 = &DAT_009ae2bc;
            puVar23 = (undefined4 *)&DAT_020b8ea0;
            for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar23 = *puVar18;
              puVar18 = puVar18 + 1;
              puVar23 = puVar23 + 1;
            }
            if (DAT_01fbb8a0 == 3) {
              *(undefined4 *)(puVar14 + -0x578) = 0;
            }
            else if ((_DAT_020b8ea0 & 0xff) == 0x2d) {
              bVar28 = (EDIT_ITEM == 0) != 0;
              iVar11 = -(uint)(EDIT_ITEM == 0);
              bVar29 = iVar11 == 0;
              *(int *)(puVar14 + -0x6bc) = iVar11;
              iVar11 = 1;
              pbVar19 = (byte *)((int)&DAT_020b8ea0 + 1);
              pbVar24 = &DAT_00762978;
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar28 = *pbVar19 < *pbVar24;
                bVar29 = *pbVar19 == *pbVar24;
                pbVar19 = pbVar19 + 1;
                pbVar24 = pbVar24 + 1;
              } while (bVar29);
              if (((-(uint)(bVar28 || bVar29) | *(uint *)(puVar14 + -0x6bc)) & 1) != 0) {
                *(undefined4 *)(puVar14 + -0x574) = 0;
                goto LAB_004858db;
              }
            }
            if ((EDIT_ITEM != 0) && ((_DAT_020b8ea0 & 0xffff) == 0x7e7e)) {
              *(undefined4 *)(puVar14 + -0x570) = 0;
              goto LAB_00480aab;
            }
            _DAT_00828598 = 1;
            bVar28 = DAT_020b8ea5 == 'x';
            if (bVar28) {
              _DAT_00828598 = 2;
            }
            iVar11 = 3;
            pcVar20 = &DAT_020b8ea2;
            pcVar25 = "038";
            do {
              if (iVar11 == 0) break;
              iVar11 = iVar11 + -1;
              bVar28 = *pcVar20 == *pcVar25;
              pcVar20 = pcVar20 + 1;
              pcVar25 = pcVar25 + 1;
            } while (bVar28);
            if (bVar28) {
              DAT_009c6ae0 = 1;
            }
            else {
              iVar11 = 3;
              pcVar20 = &DAT_020b8ea2;
              pcVar25 = "040";
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar28 = *pcVar20 == *pcVar25;
                pcVar20 = pcVar20 + 1;
                pcVar25 = pcVar25 + 1;
              } while (bVar28);
              if (bVar28) {
                DAT_009c6ae0 = 2;
                *(undefined4 *)(puVar14 + -0x568) = 0;
              }
              else {
                iVar11 = 3;
                pcVar20 = &DAT_020b8ea2;
                pcVar25 = "033";
                do {
                  if (iVar11 == 0) break;
                  iVar11 = iVar11 + -1;
                  bVar28 = *pcVar20 == *pcVar25;
                  pcVar20 = pcVar20 + 1;
                  pcVar25 = pcVar25 + 1;
                } while (bVar28);
                if (bVar28) {
                  DAT_009c6ae0 = 5;
                  *(undefined4 *)(puVar14 + -0x564) = 0;
                }
                else {
                  iVar11 = 3;
                  pcVar20 = &DAT_020b8ea2;
                  pcVar25 = "034";
                  do {
                    if (iVar11 == 0) break;
                    iVar11 = iVar11 + -1;
                    bVar28 = *pcVar20 == *pcVar25;
                    pcVar20 = pcVar20 + 1;
                    pcVar25 = pcVar25 + 1;
                  } while (bVar28);
                  if (bVar28) {
                    DAT_009c6ae0 = 6;
                    *(undefined4 *)(puVar14 + -0x560) = 0;
                  }
                  else {
                    iVar11 = 3;
                    pcVar20 = &DAT_020b8ea2;
                    pcVar25 = "037";
                    do {
                      if (iVar11 == 0) break;
                      iVar11 = iVar11 + -1;
                      bVar28 = *pcVar20 == *pcVar25;
                      pcVar20 = pcVar20 + 1;
                      pcVar25 = pcVar25 + 1;
                    } while (bVar28);
                    if (bVar28) {
                      DAT_009c6ae0 = 3;
                      *(undefined4 *)(puVar14 + -0x55c) = 0;
                    }
                    else {
                      iVar11 = 3;
                      pcVar20 = &DAT_020b8ea2;
                      pcVar25 = "039";
                      do {
                        if (iVar11 == 0) break;
                        iVar11 = iVar11 + -1;
                        bVar28 = *pcVar20 == *pcVar25;
                        pcVar20 = pcVar20 + 1;
                        pcVar25 = pcVar25 + 1;
                      } while (bVar28);
                      if (bVar28) {
                        DAT_009c6ae0 = 4;
                        *(undefined4 *)(puVar14 + -0x558) = 0;
                      }
                      else {
                        iVar11 = 3;
                        pcVar20 = &DAT_020b8ea2;
                        pcVar25 = "036";
                        do {
                          if (iVar11 == 0) break;
                          iVar11 = iVar11 + -1;
                          bVar28 = *pcVar20 == *pcVar25;
                          pcVar20 = pcVar20 + 1;
                          pcVar25 = pcVar25 + 1;
                        } while (bVar28);
                        if (bVar28) {
                          DAT_009c6ae0 = 7;
                          *(undefined4 *)(puVar14 + -0x554) = 0;
                        }
                        else {
                          iVar11 = 3;
                          pcVar20 = &DAT_020b8ea2;
                          pcVar25 = "035";
                          do {
                            if (iVar11 == 0) break;
                            iVar11 = iVar11 + -1;
                            bVar28 = *pcVar20 == *pcVar25;
                            pcVar20 = pcVar20 + 1;
                            pcVar25 = pcVar25 + 1;
                          } while (bVar28);
                          if (!bVar28) {
                            iVar11 = 5;
                            pcVar20 = (char *)&DAT_020b8ea0;
                            pcVar25 = "~~999";
                            do {
                              if (iVar11 == 0) break;
                              iVar11 = iVar11 + -1;
                              bVar28 = *pcVar20 == *pcVar25;
                              pcVar20 = pcVar20 + 1;
                              pcVar25 = pcVar25 + 1;
                            } while (bVar28);
                            if (bVar28) {
                              DAT_008285a4 = 0x11;
                              *(undefined4 *)(puVar14 + -0x54c) = 0;
                              goto LAB_0048586a;
                            }
                            *(undefined4 *)(puVar14 + -0x548) = 0;
                            _DAT_00828598 = 2000;
                            bVar28 = DAT_020b8ea5 == 'x';
                            if (bVar28) {
                              _DAT_00828598 = 4000;
                            }
                            iVar11 = 3;
                            pcVar20 = &DAT_020b8ea2;
                            pcVar25 = "038";
                            do {
                              if (iVar11 == 0) break;
                              iVar11 = iVar11 + -1;
                              bVar28 = *pcVar20 == *pcVar25;
                              pcVar20 = pcVar20 + 1;
                              pcVar25 = pcVar25 + 1;
                            } while (bVar28);
                            if (bVar28) {
                              DAT_008285a4 = 9;
                              VIEW_DY = DAT_01b9d630 + VIEW_DY;
                              *(undefined4 *)(puVar14 + -0x544) = 0;
                            }
                            else {
                              iVar11 = 3;
                              pcVar20 = &DAT_020b8ea2;
                              pcVar25 = "034";
                              do {
                                if (iVar11 == 0) break;
                                iVar11 = iVar11 + -1;
                                bVar28 = *pcVar20 == *pcVar25;
                                pcVar20 = pcVar20 + 1;
                                pcVar25 = pcVar25 + 1;
                              } while (bVar28);
                              if (bVar28) {
                                DAT_008285a4 = 10;
                                VIEW_DY = VIEW_DY + DAT_01b9d630 * -3;
                                *(undefined4 *)(puVar14 + -0x540) = 0;
                              }
                              else {
                                iVar11 = 3;
                                pcVar20 = &DAT_020b8ea2;
                                pcVar25 = "040";
                                do {
                                  if (iVar11 == 0) break;
                                  iVar11 = iVar11 + -1;
                                  bVar28 = *pcVar20 == *pcVar25;
                                  pcVar20 = pcVar20 + 1;
                                  pcVar25 = pcVar25 + 1;
                                } while (bVar28);
                                if (bVar28) {
                                  DAT_008285a4 = 0xb;
                                  VIEW_DY = VIEW_DY - DAT_01b9d630;
                                  *(undefined4 *)(puVar14 + -0x53c) = 0;
                                }
                                else {
                                  iVar11 = 3;
                                  pcVar20 = &DAT_020b8ea2;
                                  pcVar25 = "033";
                                  do {
                                    if (iVar11 == 0) break;
                                    iVar11 = iVar11 + -1;
                                    bVar28 = *pcVar20 == *pcVar25;
                                    pcVar20 = pcVar20 + 1;
                                    pcVar25 = pcVar25 + 1;
                                  } while (bVar28);
                                  if (bVar28) {
                                    DAT_008285a4 = 0xc;
                                    VIEW_DY = DAT_01b9d630 * 3 + VIEW_DY;
                                    *(undefined4 *)(puVar14 + -0x538) = 0;
                                  }
                                  else {
                                    iVar11 = 3;
                                    pcVar20 = &DAT_020b8ea2;
                                    pcVar25 = "037";
                                    do {
                                      if (iVar11 == 0) break;
                                      iVar11 = iVar11 + -1;
                                      bVar28 = *pcVar20 == *pcVar25;
                                      pcVar20 = pcVar20 + 1;
                                      pcVar25 = pcVar25 + 1;
                                    } while (bVar28);
                                    if (bVar28) {
                                      DAT_008285a4 = 0xd;
                                      VIEW_DX = DAT_01b9d630 / 2 + VIEW_DX;
                                      *(undefined4 *)(puVar14 + -0x534) = 0;
                                    }
                                    else {
                                      iVar11 = 3;
                                      pcVar20 = &DAT_020b8ea2;
                                      pcVar25 = "036";
                                      do {
                                        if (iVar11 == 0) break;
                                        iVar11 = iVar11 + -1;
                                        bVar28 = *pcVar20 == *pcVar25;
                                        pcVar20 = pcVar20 + 1;
                                        pcVar25 = pcVar25 + 1;
                                      } while (bVar28);
                                      if (bVar28) {
                                        DAT_008285a4 = 0xe;
                                        VIEW_DX = DAT_01b9d630 * 3 + VIEW_DX;
                                        *(undefined4 *)(puVar14 + -0x530) = 0;
                                      }
                                      else {
                                        iVar11 = 3;
                                        pcVar20 = &DAT_020b8ea2;
                                        pcVar25 = "039";
                                        do {
                                          if (iVar11 == 0) break;
                                          iVar11 = iVar11 + -1;
                                          bVar28 = *pcVar20 == *pcVar25;
                                          pcVar20 = pcVar20 + 1;
                                          pcVar25 = pcVar25 + 1;
                                        } while (bVar28);
                                        if (bVar28) {
                                          DAT_008285a4 = 0xf;
                                          VIEW_DX = VIEW_DX - DAT_01b9d630 / 2;
                                          *(undefined4 *)(puVar14 + -0x52c) = 0;
                                        }
                                        else {
                                          iVar11 = 3;
                                          pcVar20 = &DAT_020b8ea2;
                                          pcVar25 = "035";
                                          do {
                                            if (iVar11 == 0) break;
                                            iVar11 = iVar11 + -1;
                                            bVar28 = *pcVar20 == *pcVar25;
                                            pcVar20 = pcVar20 + 1;
                                            pcVar25 = pcVar25 + 1;
                                          } while (bVar28);
                                          if (bVar28) {
                                            DAT_008285a4 = 0x10;
                                            VIEW_DX = VIEW_DX + DAT_01b9d630 * -3;
                                            *(undefined4 *)(puVar14 + -0x528) = 0;
                                          }
                                          else {
                                            iVar11 = 5;
                                            pcVar20 = (char *)&DAT_020b8ea0;
                                            pcVar25 = "~~999";
                                            do {
                                              if (iVar11 == 0) break;
                                              iVar11 = iVar11 + -1;
                                              bVar28 = *pcVar20 == *pcVar25;
                                              pcVar20 = pcVar20 + 1;
                                              pcVar25 = pcVar25 + 1;
                                            } while (bVar28);
                                            if (bVar28) {
                                              DAT_008285a4 = 0x11;
                                              *(undefined4 *)(puVar14 + -0x524) = 0;
                                              goto LAB_0048586a;
                                            }
                                            iVar11 = 5;
                                            bVar28 = false;
                                            pcVar20 = (char *)&DAT_020b8ea0;
                                            pcVar25 = "~~998";
                                            do {
                                              if (iVar11 == 0) break;
                                              iVar11 = iVar11 + -1;
                                              bVar28 = *pcVar20 == *pcVar25;
                                              pcVar20 = pcVar20 + 1;
                                              pcVar25 = pcVar25 + 1;
                                            } while (bVar28);
                                            if (!bVar28) {
                                              if ((EDIT_ITEM == 0) &&
                                                 ((_DAT_020b8ea0 & 0xffff) == 0x7e7e)) {
                                                *(undefined4 *)(puVar14 + -0x51c) = 0;
                                                goto LAB_00480aab;
                                              }
                                              *(undefined4 *)(puVar14 + -0x518) = 0x200;
                                              DAT_00791460 = 1;
                                              while ('\x1f' < (char)(&DAT_020b8e9f)[DAT_00791460]) {
                                                *(undefined4 *)(puVar14 + -0x514) = 0;
                                                *(undefined4 *)(puVar14 + -0x508) = 0;
                                                DAT_00791460 = DAT_00791460 + 1;
                                                *(int *)(puVar14 + -0x518) =
                                                     *(int *)(puVar14 + -0x518) + -1;
                                                if (*(int *)(puVar14 + -0x518) < 1)
                                                goto LAB_00480693;
                                              }
                                              iVar11 = 0x201 - DAT_00791460;
                                              *(int *)(puVar14 + -0x510) = iVar11;
                                              DAT_00791178 = DAT_00791460;
                                              while (0 < iVar11) {
                                                (&DAT_020b8e9f)[DAT_00791178] = 0x20;
                                                DAT_00791178 = DAT_00791178 + 1;
                                                *(int *)(puVar14 + -0x510) =
                                                     *(int *)(puVar14 + -0x510) + -1;
                                                iVar11 = *(int *)(puVar14 + -0x510);
                                              }
                                              *(undefined4 *)(puVar14 + -0x50c) = 0;
LAB_00480693:
                                              if ((_DAT_020b8ea0 & 0xff) == 0x60) {
                                                *(undefined4 *)(puVar14 + -0x504) = 0;
                                                goto LAB_004831fd;
                                              }
                                              if ((_DAT_020b8ea0 & 0xff) == 0x71) {
                                                *(undefined4 *)(puVar14 + -0x500) = 0x200;
                                                DAT_00791460 = 1;
                                                do {
                                                  (&DAT_020b8e9f)[DAT_00791460] =
                                                       (&DAT_020b909f)[DAT_00791460];
                                                  DAT_00791460 = DAT_00791460 + 1;
                                                  *(int *)(puVar14 + -0x500) =
                                                       *(int *)(puVar14 + -0x500) + -1;
                                                } while (0 < *(int *)(puVar14 + -0x500));
                                              }
                                              *(undefined4 *)(puVar14 + -0x4fc) = 0;
                                              goto LAB_0048083c;
                                            }
                                            P2 = f_38000;
                                            ffree(in_ST0);
                                            Var31 = thunk_FUN_00579770(&DAT_0076291c,1,&IP1);
                                            IP2 = 0;
                                            ffree(Var31);
                                            in_ST0 = (float10)thunk_FUN_00579770(&DAT_00762918,1,
                                                                                 &IP1);
                                            VIEW_DX = 0x960;
                                            VIEW_DY = DAT_00828590;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            if (0 < ITEM_I) {
                              ffree(in_ST0);
                              in_ST0 = (float10)draw_items();
                            }
                            *(undefined4 *)(puVar14 + -0x520) = 0;
                            goto LAB_004807d0;
                          }
                          DAT_009c6ae0 = 8;
                          *(undefined4 *)(puVar14 + -0x550) = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
            ffree(in_ST0);
            _DAT_00828594 = thunk_FUN_0052fef6();
            FUN_005f34d1(puVar14,0x48021e);
            in_ST0 = (float10)FUN_005f34d1(puVar14,0x48023f);
            *(undefined4 *)(puVar14 + -0x56c) = 0;
            puVar16 = puVar14;
            goto LAB_004861ab;
          }
          *(undefined4 *)(puVar14 + -0x5fc) = 0;
        }
        else {
          iVar11 = 3;
          bVar28 = false;
          pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
          pcVar25 = "039";
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar28 = *pcVar20 == *pcVar25;
            pcVar20 = pcVar20 + 1;
            pcVar25 = pcVar25 + 1;
          } while (bVar28);
          if (bVar28) {
            puVar14 = &stack0xfffffffc;
            if (DAT_00791190 == 0) goto LAB_0047f78d;
            if ((int)DAT_00791194 < (int)DAT_00791190) {
              DAT_00791194 = DAT_00791194 + 1;
            }
            goto LAB_0047f677;
          }
          iVar11 = 3;
          bVar28 = false;
          pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
          pcVar25 = "046";
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar28 = *pcVar20 == *pcVar25;
            pcVar20 = pcVar20 + 1;
            pcVar25 = pcVar25 + 1;
          } while (bVar28);
          bVar29 = false;
          if ((bVar28) &&
             (bVar29 = DAT_00791194 == DAT_00791190, (int)DAT_00791194 < (int)DAT_00791190)) {
            DAT_00791190 = DAT_00791190 - 1;
            DAT_00791460 = DAT_00791194 + 1;
            for (iVar11 = (DAT_00791190 - DAT_00791460) + 1; 0 < iVar11; iVar11 = iVar11 + -1) {
              (&DAT_020b8e9f)[DAT_00791460] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00791460);
              DAT_00791460 = DAT_00791460 + 1;
            }
            *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00791190) = 0x20;
            DAT_008285a0 = 8;
            goto LAB_0047f677;
          }
          iVar11 = 3;
          pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
          pcVar25 = "035";
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar29 = *pcVar20 == *pcVar25;
            pcVar20 = pcVar20 + 1;
            pcVar25 = pcVar25 + 1;
          } while (bVar29);
          if (bVar29) {
            puVar14 = &stack0xfffffffc;
            if (DAT_00791194 != 0) {
              if (DAT_00791190 != 0) {
                DAT_00791194 = DAT_00791190;
                goto LAB_0047f677;
              }
              puVar14 = &stack0xfffffffc;
              if (EDIT_ITEM == 0) goto LAB_004807d0;
            }
            goto LAB_0047f78d;
          }
          bVar28 = DAT_00791194 == 0;
          if (!bVar28) {
            iVar11 = 3;
            pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
            pcVar25 = "036";
            do {
              if (iVar11 == 0) break;
              iVar11 = iVar11 + -1;
              bVar28 = *pcVar20 == *pcVar25;
              pcVar20 = pcVar20 + 1;
              pcVar25 = pcVar25 + 1;
            } while (bVar28);
            if (bVar28) {
              DAT_00791194 = 0;
              goto LAB_0047f677;
            }
          }
          puVar14 = &stack0xfffffffc;
          if ((DAT_009ae2bc >> 0x10 & 0xff) != 0x7e) goto LAB_0047f78d;
          if ((undefined *)(DAT_009ae2bc & 0xffffff) != &DAT_007e7e7e) goto LAB_0047f677;
          if (EDIT_ITEM != 0) {
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_0048ecfb();
          }
          DAT_008285a0 = DAT_009ae2bc >> 0x18;
          if (DAT_008285a0 == 8) {
            if ((DAT_00791190 == 0) && (DAT_00791194 == 0)) {
              DAT_008285a0 = 0;
              FUN_005f33c9(&stack0xfffffffc,0x47f362);
              in_ST0 = (float10)FUN_005f34d1(puVar33,0x47f37d);
              *(undefined4 *)(puVar33 + -0x62c) = 0;
              puVar14 = puVar33;
              goto LAB_0047f78d;
            }
            if (0 < (int)DAT_00791194) {
              DAT_00791194 = DAT_00791194 - 1;
            }
            DAT_00791460 = DAT_00791194 + 1;
            for (iVar11 = (DAT_00791190 - DAT_00791460) + 1; 0 < iVar11; iVar11 = iVar11 + -1) {
              (&DAT_020b8e9f)[DAT_00791460] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00791460);
              DAT_00791460 = DAT_00791460 + 1;
            }
            (&DAT_020b8e9f)[DAT_00791190] = 0;
            DAT_00791190 = DAT_00791190 - 1;
            goto LAB_0047f677;
          }
          if (DAT_008285a0 != 0x1b) {
LAB_0047f553:
            puVar16 = &stack0xfffffffc;
            if (((((DAT_008285a0 == 0x7f) || (puVar16 = &stack0xfffffffc, DAT_008285a0 == 0x1d)) ||
                 (puVar16 = &stack0xfffffffc, DAT_008285a0 == 0x1c)) ||
                ((puVar16 = &stack0xfffffffc, DAT_008285a0 == 0x17 ||
                 (puVar16 = &stack0xfffffffc, DAT_008285a0 == 7)))) ||
               (puVar16 = &stack0xfffffffc, DAT_008285a0 == 0xb)) goto LAB_004861ab;
            DAT_00791194 = DAT_00791194 + 1;
            DAT_00791190 = DAT_00791190 + 1;
            if (DAT_00791190 != DAT_00791194) {
              DAT_008285a4 = DAT_00791190;
              for (iVar11 = (int)((DAT_00791194 - DAT_00791190) + -1) / -1; 0 < iVar11;
                  iVar11 = iVar11 + -1) {
                (&DAT_020b8e9f)[DAT_008285a4] = (&DAT_020b8e9e)[DAT_008285a4];
                DAT_008285a4 = DAT_008285a4 - 1;
              }
            }
            (&DAT_020b8e9f)[DAT_00791194] = (char)(DAT_009ae2bc >> 0x18);
            if (DAT_008285a0 == 0xd) {
              FUN_005f46bc(&stack0xfffffffc,0x47f712);
              FUN_005f34d1(puVar36,0x47f728);
              puVar18 = (undefined4 *)&DAT_020b8ea0;
              puVar23 = &DAT_009ae2bc;
              for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar23 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar23 = puVar23 + 1;
              }
              DAT_00791194 = 0;
              DAT_00791190 = 0;
              in_ST0 = (float10)FUN_005f34d1(puVar36,0x47f76c);
              puVar18 = &DAT_009ae2bc;
              puVar23 = (undefined4 *)&DAT_007a0b7c;
              for (iVar11 = 0x20; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar23 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar23 = puVar23 + 1;
              }
              *(undefined4 *)(puVar36 + -0x604) = 0;
              puVar14 = puVar36;
              goto LAB_0047f78d;
            }
            goto LAB_0047f677;
          }
          if (EDIT_ITEM != 0) {
            P2 = f_0;
            FUN_005f34d1(&stack0xfffffffc,0x47f47d);
            FUN_005f33c9(puVar34,0x47f49f);
            puVar14 = puVar34;
            in_ST0 = (float10)FUN_005f34d1(puVar34,0x47f4ba);
            DAT_0078b4e0 = 0x58;
            *(undefined4 *)(puVar14 + -0x620) = 0;
            goto LAB_00481de1;
          }
          if (DAT_01fbb8a0 < 1000) {
            if (DAT_01fbb8a0 < 1000) {
              DAT_008285a0 = 0xd;
            }
            goto LAB_0047f553;
          }
          FUN_005f33c9(&stack0xfffffffc,0x47f525);
          puVar14 = puVar35;
          in_ST0 = (float10)FUN_005f34d1(puVar35,0x47f540);
          *(undefined4 *)(puVar14 + -0x618) = 0;
        }
LAB_0047f8bc:
        ffree(in_ST0);
        thunk_FUN_0044b928();
        in_ST0 = (float10)FUN_005f34d1(puVar14,0x47f8e0);
        **(undefined4 **)(puVar14 + 0x18) = 1;
        *(undefined4 *)(puVar14 + -0x5c8) = 0;
      }
    }
    else if ((DAT_01fbb8a0 != 0x20) || (DAT_007a0b7d != 'v')) {
      ffree(in_ST0);
      thunk_FUN_00445fff();
      in_ST0 = (float10)FUN_005f34d1(&stack0xfffffffc,0x47efe1);
      *(undefined4 *)(puVar32 + -0x67c) = 0;
      puVar14 = puVar32;
    }
  }
LAB_00486181:
  *(undefined4 *)(puVar14 + -8) = 0;
  puVar16 = puVar14;
  if (DAT_00828560 == ITEM_I) {
    *(undefined4 *)(puVar14 + -4) = 0;
  }
  else {
    DAT_00828560 = ITEM_I;
  }
LAB_004861ab:
  ffree(in_ST0);
  return (float10)*(float *)(puVar16 + -0x698);
LAB_00483355:
  if ((0x27 < DAT_01fbb8a0) && (DAT_01fbb8a0 < 0x32)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0045bf90();
    *(undefined4 *)(puVar14 + -0xc4) = 0;
    goto LAB_00486181;
  }
  if ((0x31 < DAT_01fbb8a0) && (DAT_01fbb8a0 < 0x3c)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0040f003();
    _DAT_009c6ad4 = f_0;
    *(undefined4 *)(puVar14 + -0xc0) = 0;
    goto LAB_00486181;
  }
  iVar11 = FUN_005f4660(0x20);
  if (iVar11 == 0) {
    _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,CONCAT11(DAT_007a0b7d,DAT_007a0b7c));
  }
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x76) {
    *(undefined4 *)(puVar14 + -0xbc) = 0;
    puVar15 = puVar14;
    in_ST0 = extraout_ST0_04;
    goto LAB_004807d0;
  }
  ffree(extraout_ST0_04);
  Var31 = thunk_FUN_0054c768(&DAT_020b8ea0);
  ffree(Var31);
  Var31 = thunk_FUN_0054c768(0x20b8ea1);
  if ((DAT_01fbb8a0 != 0) &&
     (((_DAT_020b8ea0 & 0xffff) == 0x4241 || (_DAT_020b8ea0 & 0xff) == 0x58) ||
      (_DAT_020b8ea0 & 0xff) == 0x49)) {
    if (DAT_01fbb8a0 != 5) {
      ffree(Var31);
      thunk_FUN_0054d831("Leaving Group Edit.",0x13);
    }
LAB_0048378f:
    DAT_01fbb8a0 = 0;
    FUN_005f33c9(puVar14,0x4837b5);
    FUN_005f34d1(puVar14,0x4837d0);
    Var31 = FUN_005f34d1(puVar14,0x4837f1);
    ffree(Var31);
    Var31 = thunk_FUN_00468df8(&DAT_007627bc);
    VEC_N = DAT_01fbb7f8;
    *DAT_01fbb7c0 = DAT_01fbb7f8 + -1;
    ffree(Var31);
    Var31 = draw_items();
    ffree(Var31);
    in_ST0 = (float10)thunk_FUN_00549422();
    DAT_01b9d628 = -1;
    *(undefined4 *)(puVar14 + -0xb8) = 0;
    goto LAB_00483f06;
  }
  iVar11 = FUN_005f4660(0x20);
  if (iVar11 == 0) {
    FUN_005f33c9(puVar14,0x483496);
    FUN_005f34d1(puVar14,0x4834b1);
  }
  in_ST0 = (float10)FUN_005f34d1(puVar14,0x4834d2);
  if (DAT_01fbb8a0 < 0) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00494302();
  }
  else {
    if ((DAT_01fbb8a0 == 9) || (DAT_01fbb8a0 == 10)) {
      ffree(in_ST0);
      thunk_FUN_004e7f79();
      iVar11 = FUN_005f4660(0x20);
      if (iVar11 != 0) {
        *(undefined4 *)(puVar14 + -0xb4) = 0;
        goto LAB_0048378f;
      }
      *(undefined4 *)(puVar14 + -0xb0) = 0;
      in_ST0 = extraout_ST0_05;
      goto LAB_00486181;
    }
    if (DAT_01fbb8a0 == 5) {
LAB_00483531:
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_004e7380();
      if ((_DAT_020b8ea0 & 0xff) == 0x58) goto code_r0x0048354f;
    }
    else if (DAT_01fbb8a0 == 6) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_004a217d();
      if (DAT_01fbb8a0 == 5) {
        *(undefined4 *)(puVar14 + -0xa8) = 0;
        goto LAB_00483531;
      }
    }
    else if (DAT_01fbb8a0 == 8) {
      if (DAT_01fbb8a4 == 0x59) {
        _DAT_020b90a0 = CONCAT21(_DAT_020b90a1,DAT_0076296c);
        ffree(in_ST0);
        region_select();
        P2 = P1;
        DAT_01fbb8a0 = 0;
        DAT_01fbb8a4 = 0;
        FUN_005f33c9(puVar14,0x483641);
        in_ST0 = (float10)FUN_005f34d1(puVar14,0x48365c);
        DAT_0078b4e4 = 0x4e;
        *(undefined4 *)(puVar14 + -0xa4) = 0;
LAB_00485c38:
        ffree(in_ST0);
        in_ST0 = (float10)cmd_I();
        DAT_01fb9630 = 0;
        ITEM_COUNT_SAVE = ITEM_WORDS;
        DAT_01a14bb0 = ITEM_I;
        if ((EDIT_ITEM == 0) || (DAT_02052740 != 0)) {
          if ((_DAT_020b8ea0 & 0xffff) == 0x4649) {
            FUN_005f33c9(puVar14,0x485cc6);
            in_ST0 = (float10)FUN_005f34d1(puVar14,0x485ce1);
            *(undefined4 *)(puVar14 + -500) = 0;
          }
          else {
            *(undefined4 *)(puVar14 + -0x1f8) = 0;
LAB_00485ebc:
            if (EDIT_ITEM < 0) {
              EDIT_ITEM = -EDIT_ITEM;
            }
            *(undefined4 *)(puVar14 + -0x1f0) = 0;
          }
        }
        else {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0048ecfb();
          *(undefined4 *)(puVar14 + -0x1fc) = 0;
        }
        goto LAB_00485edd;
      }
      if (DAT_01fbb8a4 != 0x58) {
        ffree(in_ST0);
        in_ST0 = (float10)lineup_answer();
      }
      if (DAT_01fbb8a4 == 0x58) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0054aaf8();
      }
    }
    else {
      if (DAT_01fbb8a0 != 0x11) {
        if (DAT_01fbb8a0 == 0xf) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_005770d8();
          *(undefined4 *)(puVar14 + -0xa0) = 0;
          goto LAB_00486181;
        }
        if (DAT_01fbb8a0 == 0x12) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_004b041d();
          *(undefined4 *)(puVar14 + -0x9c) = 0;
          goto LAB_00486181;
        }
        if (DAT_01fbb8a0 == 600) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00510430();
          *(undefined4 *)(puVar14 + -0x98) = 0;
        }
        else {
          if (DAT_01fbb8a0 != 0x13) goto LAB_00483e8c;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00536adc();
          DAT_01fbb8a0 = 0;
          *(undefined4 *)(puVar14 + -0x94) = 0;
        }
        goto LAB_00485edd;
      }
      if (DAT_01fbb8a4 != 9) goto LAB_00483ec6;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00445143();
    }
  }
  goto LAB_00483ee2;
code_r0x0048354f:
  *(undefined4 *)(puVar14 + -0xac) = 0;
  goto LAB_00483355;
LAB_00484442:
  if ((_DAT_020b8ea0 & 0xffffff) == 0x414c50) goto LAB_00484b34;
  bVar28 = (DAT_009ae2bc & 0xffff) == 0x7e7e;
  if (!bVar28) goto LAB_0048460e;
  iVar11 = 3;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "114";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_009ae2bc._0_3_ = CONCAT12(DAT_0076263e,DAT_0076263c);
    *(undefined4 *)(puVar14 + -0x54) = 0;
    goto LAB_00484845;
  }
  iVar11 = 3;
  bVar28 = false;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "113";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_009ae2bc._0_3_ =
         CONCAT12(s_ALL_PAUSSTOPPLAYEXITNB_00762624[0x16],s_ALL_PAUSSTOPPLAYEXITNB_00762624._20_2_);
    *(undefined4 *)(puVar14 + -0x50) = 0;
    goto LAB_00484845;
  }
  iVar11 = 3;
  bVar28 = false;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "115";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_007a0b7e = (byte)i_541871169;
    DAT_007a0b7f = (char)((uint)i_541871169 >> 8);
    DAT_007a0b80._0_1_ = (char)((uint)i_541871169 >> 0x10);
    DAT_007a0b80._1_1_ = (char)((uint)i_541871169 >> 0x18);
    DAT_007a0b80._2_1_ = DAT_0076266c;
  }
  iVar11 = 3;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "118";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_007a0b7e = (byte)i_1497451600;
    DAT_007a0b7f = (char)((uint)i_1497451600 >> 8);
    DAT_007a0b80._0_1_ = (char)((uint)i_1497451600 >> 0x10);
    DAT_007a0b80._1_1_ = (char)((uint)i_1497451600 >> 0x18);
    DAT_007a0b80._2_1_ = DAT_00762660;
  }
  cVar10 = DAT_007a0b80._1_1_;
  cVar9 = (char)DAT_007a0b80;
  cVar8 = DAT_007a0b7f;
  bVar2 = DAT_007a0b7e;
  iVar11 = 3;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "119";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  DAT_007a0b7e = (byte)s_PAUS_00762650._0_4_;
  bVar3 = DAT_007a0b7e;
  DAT_007a0b7f = SUB41(s_PAUS_00762650._0_4_,1);
  cVar4 = DAT_007a0b7f;
  DAT_007a0b80._0_1_ = SUB41(s_PAUS_00762650._0_4_,2);
  cVar5 = (char)DAT_007a0b80;
  DAT_007a0b80._1_1_ = SUB41(s_PAUS_00762650._0_4_,3);
  cVar6 = DAT_007a0b80._1_1_;
  if (bVar28) {
    DAT_007a0b80._2_1_ = s_PAUS_00762650[4];
    bVar2 = DAT_007a0b7e;
    cVar8 = DAT_007a0b7f;
    cVar9 = (char)DAT_007a0b80;
    cVar10 = DAT_007a0b80._1_1_;
  }
  DAT_007a0b80._1_1_ = cVar10;
  DAT_007a0b80._0_1_ = cVar9;
  DAT_007a0b7f = cVar8;
  DAT_007a0b7e = bVar2;
  iVar11 = 3;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "121";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_007a0b7e = (byte)i_1347376211;
    DAT_007a0b7f = (char)((uint)i_1347376211 >> 8);
    DAT_007a0b80._0_1_ = (char)((uint)i_1347376211 >> 0x10);
    DAT_007a0b80._1_1_ = (char)((uint)i_1347376211 >> 0x18);
    DAT_007a0b80._2_1_ = DAT_00762648;
  }
  iVar11 = 3;
  pcVar20 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar25 = "122";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *pcVar20 == *pcVar25;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  } while (bVar28);
  if (bVar28) {
    DAT_007a0b80._2_1_ = s_PAUS_00762650[4];
    DAT_007a0b7e = bVar3;
    DAT_007a0b7f = cVar4;
    DAT_007a0b80._0_1_ = cVar5;
    DAT_007a0b80._1_1_ = cVar6;
  }
  FUN_005f33c9(puVar14,0x48459b);
  in_ST0 = (float10)FUN_005f34d1(puVar14,0x4845b6);
  *(undefined4 *)(puVar14 + -0x4c) = 0;
  goto LAB_00484442;
LAB_0048460e:
  if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x584e) {
    *(undefined4 *)(puVar14 + -0x48) = 0;
    goto LAB_00484963;
  }
  if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x424e) {
    *(undefined4 *)(puVar14 + -0x44) = 0;
    goto LAB_00484924;
  }
  if (((DAT_009ae2bc & 0xff) != 0x58) && (DAT_008285a0 != 0xd)) {
    iVar11 = 1;
    bVar28 = false;
    piVar22 = (int *)&DAT_007a0b7e;
    piVar27 = (int *)0x762634;
    do {
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      bVar28 = *piVar22 == *piVar27;
      piVar22 = piVar22 + 1;
      piVar27 = piVar27 + 1;
    } while (bVar28);
    if ((!bVar28) && ((DAT_009ae2bc & 0xff) != 0x78)) {
      iVar11 = 1;
      bVar28 = false;
      piVar22 = (int *)&DAT_007a0b7e;
      piVar27 = (int *)0x762630;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        bVar28 = *piVar22 == *piVar27;
        piVar22 = piVar22 + 1;
        piVar27 = piVar27 + 1;
      } while (bVar28);
      if (bVar28) {
        ffree(in_ST0);
        thunk_FUN_00597ad0(1);
        *(undefined4 *)(puVar14 + -0x34) = 0;
      }
      else {
        iVar11 = 1;
        bVar28 = false;
        piVar22 = (int *)&DAT_007a0b7e;
        piVar27 = (int *)0x76262c;
        do {
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          bVar28 = *piVar22 == *piVar27;
          piVar22 = piVar22 + 1;
          piVar27 = piVar27 + 1;
        } while (bVar28);
        if (bVar28) {
          ffree(in_ST0);
          thunk_FUN_00597ad0(2);
        }
        else {
          iVar11 = 1;
          bVar28 = false;
          piVar22 = (int *)&DAT_007a0b7e;
          piVar27 = (int *)0x762628;
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar28 = *piVar22 == *piVar27;
            piVar22 = piVar22 + 1;
            piVar27 = piVar27 + 1;
          } while (bVar28);
          if (!bVar28) {
            if (CONCAT11(DAT_007a0b7d,DAT_007a0b7c) == 0x4d4d) {
              *(undefined4 *)(puVar14 + -0x6b8) = 0;
              *(undefined4 *)(puVar14 + -0x6c8) = 3;
              *(byte **)(puVar14 + -0x6c4) = &DAT_007a0b7e;
              *(undefined **)(puVar14 + -0x6c0) = &DAT_00828564;
              ffree(in_ST0);
              Var31 = FUN_005f9240(puVar14 + -0x6b8,0x784ff00,&DAT_007628fc,puVar14 + -0x6c8,
                                   &DAT_0079114c);
              *(undefined4 *)(puVar14 + -0x24) = 0;
              goto LAB_00484b67;
            }
            iVar11 = 1;
            bVar28 = false;
            piVar22 = (int *)&DAT_007a0b7e;
            piVar27 = (int *)"ALL PAUSSTOPPLAYEXITNB ";
            do {
              if (iVar11 == 0) break;
              iVar11 = iVar11 + -1;
              bVar28 = *piVar22 == *piVar27;
              piVar22 = piVar22 + 1;
              piVar27 = piVar27 + 1;
            } while (bVar28);
            if (bVar28) {
              ffree(in_ST0);
              Var31 = thunk_FUN_00597ad0(2);
              goto LAB_00484b67;
            }
            goto LAB_004858db;
          }
          ffree(in_ST0);
          thunk_FUN_00597ad0(3);
          *(undefined4 *)(puVar14 + -0x2c) = 0;
        }
      }
      FUN_005f33c9(puVar14,0x484740);
      FUN_005f34d1(puVar14,0x48475b);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x48477c);
      *(undefined4 *)(puVar14 + -0x30) = 0;
      puVar16 = puVar14;
      goto LAB_004861ab;
    }
  }
  ffree(in_ST0);
  thunk_FUN_00597ad0(2);
  goto LAB_00484845;
  while( true ) {
    iVar11 = iVar11 + -1;
    bVar3 = *pbVar24;
    bVar2 = *pbVar19;
    bVar28 = bVar2 < bVar3;
    pbVar19 = pbVar19 + 1;
    pbVar24 = pbVar24 + 1;
    if (bVar2 != bVar3) break;
code_r0x004840f2:
    if (iVar11 == 0) break;
  }
  if ((bVar28) && (iVar11 = FUN_005f4660(0x20), in_ST0 = extraout_ST0_06, iVar11 == 0)) {
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a) {
      ffree(extraout_ST0_06);
      Var31 = thunk_FUN_005725fa();
      *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
      *(ushort *)(puVar14 + -0x6be) = (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
      *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
      iRam00828570 = *(int *)(puVar14 + -0x6bc);
      *(undefined2 *)(puVar14 + -0x6c0) = *(undefined2 *)(puVar14 + -0x6c0);
      *(ushort *)(puVar14 + -0x6be) = (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
      *(int *)(puVar14 + -0x6bc) = (int)ROUND(P3);
      in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
      iRam0082856c = *(int *)(puVar14 + -0x6bc);
      if (*(int *)(puVar14 + -0x6bc) == 0) {
        iRam0082856c = iRam00828570;
      }
      P1 = P4;
      P2 = P5;
      if (P5 == f_0) {
        P2 = _UNK_0076269c;
      }
      ffree(Var31);
      in_ST0 = (float10)lineup_pass(0x828570,0x82856c,&P1,&P2);
      *(undefined4 *)(puVar14 + -0x1e8) = 0;
    }
    else {
      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2e) {
        VIEW_DY = 0x4000;
      }
      FUN_005f33c9(puVar14,&UNK_00484277);
      Var31 = FUN_005f34d1(puVar14,&UNK_00484292);
      ffree(Var31);
      in_ST0 = (float10)thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&UNK_0076267c,&UNK_00762680,"(1i5)",5
                                           ,&VIEW_DY);
      P2 = f_0;
      *(undefined4 *)(puVar14 + -0x1e4) = 0;
LAB_004857a3:
      if ((_DAT_020b8ea0 >> 8 & 0xff) != 0x5a) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0058c344();
        if (EDIT_ITEM != 0) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00585d20();
          *(undefined4 *)(puVar14 + -0xcc) = 0;
          puVar16 = puVar14;
          goto LAB_004861ab;
        }
        *(undefined4 *)(puVar14 + -0xd0) = 0;
code_r0x004857ea:
        DAT_008285a4 = (uint)((_DAT_020b8ea0 & 0xff) != 0x42);
        if ((_DAT_020b8ea0 & 0xff) == 0x4d) {
          DAT_008285a4 = 2;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x52) {
          DAT_008285a4 = DAT_008285a4 + 3;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
          DAT_008285a4 = DAT_008285a4 + 6;
        }
LAB_0048586a:
        ffree(in_ST0);
        thunk_FUN_00535d00(&DAT_008285a4);
        in_ST0 = (float10)FUN_005f34d1(puVar14,0x48589b);
        puVar15 = puVar14;
        goto LAB_004807d0;
      }
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00585d20();
      *(undefined4 *)(puVar14 + -200) = 0;
    }
  }
  else {
    *(undefined4 *)(puVar14 + -0x1ec) = 0;
    DAT_01fbb8a8 = 0;
    ffree(in_ST0);
    in_ST0 = (float10)cmd_lineup();
    *(undefined4 *)(puVar14 + -0x1e0) = 0;
  }
LAB_00485edd:
  if (DAT_00791470 == 0) {
    *(undefined4 *)(puVar14 + -0x84) = 0;
  }
  else {
    DAT_00791470 = 0;
  }
  if (0 < DAT_02052740) {
    *(undefined4 *)(puVar14 + -0x80) = 0;
    goto LAB_004807ec;
  }
  *DAT_00828558 = DAT_01be6cd8;
  DAT_01a14bb0 = ITEM_I;
  DAT_01a14bb4 = EDIT_ITEM;
  DAT_00791194 = 0;
  DAT_00791190 = 0;
  *(undefined4 *)(puVar14 + -0x7c) = 0;
  puVar15 = puVar14;
  goto LAB_004807d0;
DAT_00484053:
  *(undefined4 *)(puVar14 + -0x218) = 0;
LAB_00484a3a:
  while( true ) {
    *DAT_01fbb7c0 = 0;
    iVar7 = DAT_01fbb824;
    VEC_N = 1;
    *(int *)(puVar14 + -0x6bc) = DAT_01fbb83c;
    iVar11 = *DAT_01fbb844;
    if (iVar11 < 0) {
      iVar11 = 0;
    }
    *(int *)(puVar14 + -0x6c0) = iVar11;
    *(int *)(puVar14 + -0x6c4) = DAT_01fbb83c * DAT_01fbb840;
    iVar12 = 1;
    for (iVar11 = 1; iVar11 <= *(int *)(puVar14 + -0x6c0); iVar11 = iVar11 + 1) {
      *(undefined1 *)((iVar7 - *(int *)(puVar14 + -0x6c4)) + *(int *)(puVar14 + -0x6bc) * iVar12) =
           0;
      iVar12 = iVar12 + 1;
    }
    *DAT_01fbb844 = 0;
    ffree(in_ST0);
    in_ST0 = (float10)cmd_get();
    if (DAT_0078b4e0 == 0xffffff9d) {
      ffree(in_ST0);
      Var31 = draw_items();
      ffree(Var31);
      Var31 = draw_items();
      ffree(Var31);
      in_ST0 = (float10)thunk_FUN_00549422();
      *(undefined4 *)(puVar14 + -0x22c) = 0;
      puVar16 = puVar14;
      goto LAB_004861ab;
    }
    if (DAT_02052740 != 0) break;
    if (DAT_0079118c == 0) {
      ffree(in_ST0);
      thunk_FUN_0048ecfb();
      iVar11 = FUN_005f4660(0x20);
      if (iVar11 == 0) {
        Var31 = FUN_005f34d1(puVar14,0x484c18);
        if (((_DAT_020b8ea0 & 0xffffff) == 0x504f54) ||
           ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f42)) {
          puVar18 = (undefined4 *)&DAT_020b90a0;
          puVar23 = &DAT_009ae2bc;
          for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar23 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar23 = puVar23 + 1;
          }
        }
        DAT_009ae2c0._0_1_ = 0x3d;
        ffree(Var31);
        in_ST0 = (float10)thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_0076261c,&DAT_00762620,"(1i5)"
                                             ,5,&DAT_020527f8);
        *(undefined4 *)(puVar14 + -0x21c) = 0;
      }
      else {
        *(undefined4 *)(puVar14 + -0x220) = 0;
        in_ST0 = extraout_ST0_07;
      }
      goto LAB_00485edd;
    }
    ffree(in_ST0);
    thunk_FUN_00549422();
    *(undefined4 *)(puVar14 + -0x224) = 0;
LAB_00484b34:
    DAT_00791198 = 1;
    Var31 = FUN_005f34d1(puVar14,0x484b5c);
    *(undefined4 *)(puVar14 + -0x58) = 0;
LAB_00484b67:
    ffree(Var31);
    in_ST0 = (float10)thunk_FUN_005069a0(&DAT_0079118c,&DAT_00828564);
    DAT_0079118c = 0;
    if (DAT_01b9d5c0 != -999) {
      puVar18 = (undefined4 *)&DAT_020b90a0;
      puVar23 = &DAT_009ae2bc;
      for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar23 = *puVar18;
        puVar18 = puVar18 + 1;
        puVar23 = puVar23 + 1;
      }
      *(undefined4 *)(puVar14 + -0x1c) = 0;
      puVar16 = puVar14;
      goto LAB_004861ab;
    }
    *(undefined4 *)(puVar14 + -0x20) = 0;
LAB_00484845:
    if (((DAT_009ae2bc & 0xffff) == 0x584e) || ((DAT_009ae2bc & 0xffff) == 0x786e)) {
LAB_00484963:
      FUN_005f33c9(puVar14,0x484981);
      FUN_005f34d1(puVar14,0x48499c);
      *(undefined4 *)(puVar14 + -0x40) = 0;
    }
    else {
      if (((DAT_009ae2bc & 0xffff) != 0x424e) && ((DAT_009ae2bc & 0xffff) != 0x626e)) {
        FUN_005f33c9(puVar14,0x4848bc);
        Var31 = FUN_005f34d1(puVar14,0x4848d7);
        DAT_00791198 = 0;
        ffree(Var31);
        thunk_FUN_00468df8(&DAT_007627bc);
        in_ST0 = (float10)FUN_005f34d1(puVar14,0x484914);
        *(undefined4 *)(puVar14 + -0x38) = 0;
        puVar16 = puVar14;
        goto LAB_004861ab;
      }
LAB_00484924:
      FUN_005f33c9(puVar14,0x484942);
      FUN_005f34d1(puVar14,0x48495d);
    }
    DAT_0079118c = 1;
    FUN_005f33c9(puVar14,0x4849d0);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4849eb);
    DAT_00791198 = 0;
    P2 = f_0;
    DAT_0078b4e4 = 0;
    *(undefined4 *)(puVar14 + -0x3c) = 0;
code_r0x00484a12:
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_004f3db0();
    if ((_DAT_020b8ea0 & 0xff) != 0x7e) {
      *(undefined4 *)(puVar14 + -0x19c) = 0;
      goto LAB_00485ebc;
    }
    *(undefined4 *)(puVar14 + -0x1a0) = 0;
  }
  *(undefined4 *)(puVar14 + -0x228) = 0;
  goto LAB_00482fb3;
LAB_00483e8c:
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_004a1240(&DAT_01fbb8a0);
  if ((DAT_01fbb8a4 == 9) && ((DAT_009ae2bc & 0xff) != 0x45)) {
    *(undefined4 *)(puVar14 + -0x90) = 0;
LAB_00483ec6:
    DAT_00791460 = 0;
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00442800(&DAT_00791460);
  }
LAB_00483ee2:
  DAT_01b9d628 = -1;
  if ((DAT_0078b4e0 == 0xffffffff) && (DAT_01fbb8a0 == 3)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00473a90();
  }
LAB_00483f06:
  if (DAT_01fbb8a0 != 0) {
    *(undefined4 *)(puVar14 + -0x8c) = 0;
    goto LAB_00486181;
  }
  DAT_01b9d628 = 0;
  _DAT_009c6ad4 = f_0;
  if (DAT_0078d890 == 0) {
    *(undefined4 *)(puVar14 + -0x88) = 0;
  }
  else {
    ffree(in_ST0);
    Var31 = draw_page_frame();
    ffree(Var31);
    in_ST0 = (float10)thunk_FUN_00549422();
  }
  goto LAB_00485edd;
  while( true ) {
    DAT_00791460 = DAT_00791460 + 1;
    *(int *)(puVar14 + -0x27c) = *(int *)(puVar14 + -0x27c) + -1;
    if (*(int *)(puVar14 + -0x27c) < 1) break;
code_r0x00483d06:
    if ((*(uint *)(s__MUSCD_CN_CTNCTXCRVCT_CW_007911a0 + DAT_00791460 * 3 + 1) & 0xffffff) ==
        (_DAT_020b8ea0 & 0xffffff)) {
      *(undefined4 *)(puVar14 + -0x278) = 0;
      goto code_r0x00485ddb;
    }
  }
code_r0x00483d60:
  *(undefined4 *)(puVar14 + -0x274) = 0;
LAB_004858db:
  iVar11 = FUN_005f4660(0x20);
  if (iVar11 != 0) {
    puVar18 = (undefined4 *)&DAT_020b8ea0;
    puVar23 = &DAT_009ae2bc;
    for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar23 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar23 = puVar23 + 1;
    }
  }
  ffree(extraout_ST0_12);
  in_ST0 = (float10)thunk_FUN_0054d7d4(&DAT_009ae2bc,0x200);
  if (DAT_02052740 == 0) {
    *(undefined4 *)(puVar14 + -0x14) = 0;
    puVar16 = puVar14;
    goto LAB_004861ab;
  }
  *(undefined4 *)(puVar14 + -0x18) = 0;
  goto LAB_004807ec;
code_r0x00483c32:
  if ((*(uint *)(s__MUSCD_CN_CTNCTXCRVCT_CW_007911a0 + DAT_00791460 * 3 + 0x19) & 0xffffff) !=
      (_DAT_020b8ea0 & 0xffffff)) goto code_r0x00483c54;
  *(undefined4 *)(puVar14 + -0x280) = 0;
code_r0x00485ddb:
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_00443b70();
  if (DAT_02052740 == 0) {
LAB_00485dfa:
    if (DAT_01fbb8a4 == 0) {
      *(undefined4 *)(puVar14 + -0x26c) = 0;
    }
    else {
      *(undefined4 *)(puVar14 + -0x268) = 0;
code_r0x00485e1c:
      DAT_01b9d628 = 0;
      *(undefined4 *)(puVar14 + -0x1b4) = 0;
    }
    goto LAB_00485edd;
  }
  *(undefined4 *)(puVar14 + -0x270) = 0;
  goto LAB_004807ec;
code_r0x00483c54:
  DAT_00791460 = DAT_00791460 + 1;
  *(int *)(puVar14 + -0x284) = *(int *)(puVar14 + -0x284) + -1;
  if (*(int *)(puVar14 + -0x284) < 1) goto code_r0x00483d60;
  goto code_r0x00483c32;
LAB_004817fd:
  if (((_DAT_020b8ea0 & 0xff) != 0x5b) && ((_DAT_020b8ea0 & 0xff) != 0x5d)) {
    if ((_DAT_020b8ea0 & 0xffff) != 0x6261) goto LAB_00481ecd;
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0054c83c(&DAT_020b8ea0,3,&DAT_00762874);
    goto LAB_00481ecd;
  }
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_0049095a();
  *(undefined4 *)(puVar14 + -0x4dc) = 0;
  goto LAB_0048186b;
LAB_00481696:
  *(undefined4 *)(puVar14 + -0x424) = 0;
LAB_004816a0:
  if (DAT_008285a4 == 0x76) {
    if (((DAT_020b8e50 == 0xb) || (DAT_020b8e50 == 1)) || (DAT_020b8e50 == 9)) {
      FUN_005f33c9(puVar14,0x4816e6);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x481701);
    }
    if (DAT_020b8e50 == 0x10) {
      FUN_005f33c9(puVar14,0x48172c);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x481747);
    }
    if ((3 < DAT_020b8e50) && (DAT_020b8e50 < 8)) {
LAB_00482589:
      if (DAT_009c66c8 == 0) {
        DAT_009c66c8 = DAT_020b8e50;
      }
      ffree(in_ST0);
      thunk_FUN_00595820(0,DAT_009c66c8);
      FUN_005f33c9(puVar14,0x4825d1);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x4825ec);
      *(undefined4 *)(puVar14 + -0x410) = 0;
      goto LAB_00482968;
    }
    if (((DAT_020b8e50 != 0x10) && (DAT_020b8e50 != 0xb)) &&
       ((DAT_020b8e50 != 1 && (DAT_020b8e50 != 9)))) {
      *(undefined4 *)(puVar14 + -0x40c) = 0;
      puVar15 = puVar14;
      goto LAB_004807d0;
    }
  }
  if (DAT_008285a4 == 0x77) {
    FUN_005f33c9(puVar14,0x4817bf);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4817da);
    if ((3 < DAT_020b8e50) && (DAT_020b8e50 < 9)) {
LAB_00482624:
      if (DAT_009c66c8 == 0) {
        DAT_009c66c8 = DAT_020b8e50;
      }
      ffree(in_ST0);
      thunk_FUN_00595820(1,DAT_009c66c8);
      FUN_005f33c9(puVar14,0x48266c);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482687);
    }
  }
  if (DAT_008285a4 == 0x73) {
    FUN_005f33c9(puVar14,0x4826b2);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4826cd);
  }
  if (DAT_008285a4 == 0x74) {
    FUN_005f33c9(puVar14,0x4826f8);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482713);
  }
  if ((DAT_008285a4 == 0x77) && (DAT_020b8e50 == 0xe)) {
    FUN_005f33c9(puVar14,0x482747);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482762);
  }
  if (DAT_008285a4 == 0x78) {
    FUN_005f33c9(puVar14,0x48278d);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4827a8);
  }
  if (DAT_008285a4 == 0x7a) {
    FUN_005f33c9(puVar14,0x4827d3);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4827ee);
  }
  if (DAT_008285a4 == 0x7b) {
    FUN_005f33c9(puVar14,0x482819);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482834);
  }
  DAT_020b8ea6 = 0;
  if ((DAT_008285a4 == 0x75) && (EDIT_ITEM == 0)) {
    FUN_005f33c9(puVar14,0x48286f);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x48288a);
  }
  *(undefined4 *)(puVar14 + -0x408) = 0;
LAB_00482968:
  *(undefined4 *)(puVar14 + -0x3a8) = 0x200;
  DAT_00791178 = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_00791178] == '\r') {
      *(undefined4 *)(puVar14 + -0x3a4) = 0;
LAB_004829f3:
      FUN_005f46bc(puVar14,0x482a15);
      in_ST0 = (float10)FUN_005f34d1(puVar14,0x482a2b);
      goto LAB_00482fb3;
    }
    if ((&DAT_020b8e9f)[DAT_00791178] == '\0') {
      *(undefined4 *)(puVar14 + -0x3a0) = 0;
      goto LAB_004829f3;
    }
    DAT_00791178 = DAT_00791178 + 1;
    *(int *)(puVar14 + -0x3a8) = *(int *)(puVar14 + -0x3a8) + -1;
  } while (0 < *(int *)(puVar14 + -0x3a8));
  *(undefined4 *)(puVar14 + -0x39c) = 0;
  goto LAB_00482fb3;
  while( true ) {
    iVar11 = iVar11 + -1;
    uVar30 = *psVar21 == *psVar26;
    psVar21 = psVar21 + 1;
    psVar26 = psVar26 + 1;
    if (!(bool)uVar30) break;
code_r0x00485e70:
    if (iVar11 == 0) break;
  }
  if ((!(bool)uVar30) && ((DAT_009ae2bc & 0xff) != 0x50)) {
    puVar18 = &DAT_01c4c860;
    puVar23 = &DAT_009ae2bc;
    for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar23 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar23 = puVar23 + 1;
    }
  }
  *(undefined4 *)(puVar14 + -0x308) = 0;
  goto LAB_00485edd;
LAB_00482142:
  if (((((_DAT_020b8ea0 >> 8 & 0xff) != 0x44) && ((_DAT_020b8ea0 >> 8 & 0xff) != 0x54)) &&
      ((DAT_009ae2bc & 0xff) == 0x43)) && ((_DAT_020b8ea0 >> 8 & 0xff) != 0x48)) {
    _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,(undefined2)DAT_009ae2bc);
    *(undefined4 *)(puVar14 + -0x4c0) = 0;
LAB_00482eb6:
    *(undefined4 *)(puVar14 + -0x4bc) = 0;
    DAT_01be6d6c = 0;
    *(undefined4 *)(puVar14 + -0x4b8) = 0;
    goto LAB_00482ed2;
  }
  DAT_00791460 = DAT_009ae2bc & 0xff;
  if (0x60 < DAT_00791460) {
    DAT_00791460 = DAT_00791460 - 0x20;
  }
  if (((DAT_00791460 == 0x42) || (DAT_00791460 == 0x4e)) ||
     ((DAT_00791460 == 0x58 || (DAT_009ae2bc == 0x4e525452)))) {
    DAT_01be6d60 = 0;
    goto LAB_00482eb6;
  }
  if ((DAT_009ae2bc == 0x53444c53) && ((byte)DAT_009ae2c0 != 0x48)) {
    _DAT_01be6d64 = f_1000;
    *(undefined4 *)(puVar14 + -0x4b4) = 0;
LAB_0048228a:
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x4822a7);
    *(undefined4 *)(puVar14 + -0x4ac) = 0;
    puVar15 = puVar14;
    goto LAB_004807d0;
  }
  if (DAT_009ae2bc == 0x42444c53) {
    _DAT_01be6d64 = f_80;
    *(undefined4 *)(puVar14 + -0x4b0) = 0;
    goto LAB_0048228a;
  }
  if (DAT_009ae2bc == 0x46444e52) {
    DAT_01be6d68 = (byte)DAT_009ae2c0 - 0x30;
    goto LAB_0048228a;
  }
  if (0 < DAT_01be6d60) {
    bVar28 = (DAT_009ae2bc & 0xffff) < 0x5051;
    if ((DAT_009ae2bc & 0xffff) == 0x5051) {
      *(undefined4 *)(puVar14 + -0x4a8) = 0;
      goto LAB_00482432;
    }
    iVar11 = 5;
    bVar29 = false;
    pbVar19 = (byte *)&DAT_009ae2bc;
    pbVar24 = &DAT_00762848;
    do {
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      bVar28 = *pbVar19 < *pbVar24;
      bVar29 = *pbVar19 == *pbVar24;
      pbVar19 = pbVar19 + 1;
      pbVar24 = pbVar24 + 1;
    } while (bVar29);
    if (bVar29) goto code_r0x004822fd;
    iVar11 = 1;
    pbVar19 = (byte *)&DAT_020b8ea0;
    pbVar24 = &DAT_00762844;
    do {
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      bVar3 = *pbVar24;
      bVar2 = *pbVar19;
      bVar28 = bVar2 < bVar3;
      pbVar19 = pbVar19 + 1;
      pbVar24 = pbVar24 + 1;
    } while (bVar2 == bVar3);
    if (bVar28) {
      FUN_005f34d1(puVar14,0x482372);
      *(undefined4 *)(puVar14 + -0x4a0) = 0;
      goto LAB_00482eb6;
    }
    if (((_DAT_020b8ea0 & 0xff) != 0x78) && (bVar28 = (_DAT_020b8ea0 & 0xff) == 0x58, !bVar28))
    goto LAB_004824d8;
    *(undefined4 *)(puVar14 + -0x49c) = 0;
    goto LAB_00481b58;
  }
  if ((DAT_009ae2bc & 0xffff) != 0x5051) {
    bVar28 = DAT_01be6d60 == 0;
    if (-1 < DAT_01be6d60) goto LAB_004824d8;
    FUN_005f33c9(puVar14,0x4823f7);
    in_ST0 = (float10)FUN_005f34d1(puVar14,0x482412);
    DAT_009ae2bc = CONCAT22(DAT_020b8ea0,(undefined2)DAT_009ae2bc);
    *(undefined4 *)(puVar14 + -0x498) = 0;
  }
LAB_00482432:
  puVar18 = &DAT_009ae2bc;
  puVar23 = (undefined4 *)&DAT_020b8ea0;
  for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar23 = *puVar18;
    puVar18 = puVar18 + 1;
    puVar23 = puVar23 + 1;
  }
  ffree(in_ST0);
  thunk_FUN_00518448();
  *(undefined2 *)(puVar14 + -0x6c0) = in_FPUControlWord;
  *(ushort *)(puVar14 + -0x6be) = (ushort)*(undefined4 *)(puVar14 + -0x6c0) | 0xc00;
  *(int *)(puVar14 + -0x6bc) = (int)ROUND(P2);
  in_FPUControlWord = *(undefined2 *)(puVar14 + -0x6c0);
  DAT_01be6d60 = *(int *)(puVar14 + -0x6bc);
  FUN_005f33c9(puVar14,0x4824a9);
  in_ST0 = (float10)FUN_005f34d1(puVar14,0x4824c4);
  bVar28 = &stack0x00000000 == (undefined1 *)0x8e4;
  DAT_009ae2c4 = CONCAT13((char)DAT_007a0b80,
                          CONCAT12(DAT_007a0b7f,CONCAT11(DAT_007a0b7e,DAT_007a0b7d)));
LAB_004824d8:
  iVar11 = 3;
  psVar21 = (short *)&DAT_009ae2bc;
  psVar26 = (short *)&DAT_00762858;
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar28 = *psVar21 == *psVar26;
    psVar21 = psVar21 + 1;
    psVar26 = psVar26 + 1;
  } while (bVar28);
  if (bVar28) goto LAB_00482e57;
  *(undefined4 *)(puVar14 + -0x494) = 0;
  goto LAB_004824fc;
code_r0x004822fd:
  ffree(in_ST0);
  thunk_FUN_0054dc2b(&DAT_009ae2bc,7);
  in_ST0 = (float10)FUN_005f34d1(puVar14,0x48232d);
  *(undefined4 *)(puVar14 + -0x4a4) = 0;
  goto LAB_00481a9d;
}


