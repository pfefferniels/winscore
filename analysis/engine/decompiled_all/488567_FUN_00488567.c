// FUN_00488567 @ 00488567 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00488567(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if ((DAT_009ae2bc & 0xffff) == 0x7e7e) {
    if ((DAT_009ae2bc >> 0x10 & 0xff) == 0x52) {
      *param_1 = 1;
      return;
    }
    if ((DAT_009ae2bc >> 0x10 & 0xff) == 0x57) {
      DAT_0078b4e4 = 0x41;
      thunk_FUN_0053ec10();
      *param_1 = 2;
      return;
    }
    iVar1 = 3;
    bVar7 = false;
    pcVar3 = (char *)((int)&DAT_009ae2bc + 2);
    pcVar5 = "037";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar7 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar7);
    if (bVar7) {
      puVar2 = &stack0xfffffffc;
      if (DAT_01b12e10 == 0) goto LAB_00488a50;
      if (0 < DAT_01b12e10) {
        DAT_01b12e10 = DAT_01b12e10 + -1;
      }
    }
    else {
      iVar1 = 3;
      pcVar3 = (char *)((int)&DAT_009ae2bc + 2);
      pcVar5 = "039";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (bVar7) {
        puVar2 = &stack0xfffffffc;
        if (DAT_01b12e14 == 0) goto LAB_00488a50;
        if (DAT_01b12e10 < DAT_01b12e14) {
          DAT_01b12e10 = DAT_01b12e10 + 1;
        }
      }
      else {
        iVar1 = 3;
        pcVar3 = (char *)((int)&DAT_009ae2bc + 2);
        pcVar5 = "046";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar7 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar7);
        if ((bVar7) && (bVar7 = DAT_01b12e10 == DAT_01b12e14, DAT_01b12e10 < DAT_01b12e14)) {
          DAT_01b12e14 = DAT_01b12e14 + -1;
          DAT_00828fa4 = DAT_01b12e10 + 1;
          for (iVar1 = (DAT_01b12e14 - DAT_00828fa4) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
            (&DAT_020b8e9f)[DAT_00828fa4] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00828fa4);
            DAT_00828fa4 = DAT_00828fa4 + 1;
          }
          *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01b12e14) = 0x20;
          DAT_00828fa0 = 8;
        }
        else {
          iVar1 = 3;
          pcVar3 = (char *)((int)&DAT_009ae2bc + 2);
          pcVar5 = "035";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar7 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            puVar2 = &stack0xfffffffc;
            if (DAT_01b12e10 != 0) {
              if (DAT_01b12e14 != 0) {
                DAT_01b12e10 = DAT_01b12e14;
                goto LAB_00488a00;
              }
              puVar2 = &stack0xfffffffc;
              if (DAT_00828f9c == 0) {
                *param_1 = 5;
                return;
              }
            }
            goto LAB_00488a50;
          }
          iVar1 = 3;
          bVar7 = false;
          pcVar3 = (char *)((int)&DAT_009ae2bc + 2);
          pcVar5 = "036";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar7 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            DAT_01b12e10 = 0;
          }
          else {
            puVar2 = &stack0xfffffffc;
            if ((DAT_009ae2bc >> 0x10 & 0xff) != 0x7e) goto LAB_00488a50;
            if ((undefined *)(DAT_009ae2bc & 0xffffff) == &DAT_007e7e7e) {
              if (DAT_00828f9c != 0) {
                FUN_0048ecfb();
              }
              DAT_00828fa0 = DAT_009ae2bc >> 0x18;
              if (DAT_00828fa0 == 8) {
                if ((DAT_01b12e14 == 0) && (DAT_01b12e10 == 0)) {
                  DAT_00828fa0 = 0;
                  FUN_005f33c9(&stack0xfffffffc,0x48887f);
                  FUN_005f34d1(puVar8,0x48889a);
                  *(undefined4 *)(puVar8 + -0x20) = 0;
                  puVar2 = puVar8;
                  goto LAB_00488a50;
                }
                if (0 < DAT_01b12e10) {
                  DAT_01b12e10 = DAT_01b12e10 + -1;
                }
                DAT_00828fa4 = DAT_01b12e10 + 1;
                for (iVar1 = (DAT_01b12e14 - DAT_00828fa4) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
                  (&DAT_020b8e9f)[DAT_00828fa4] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00828fa4)
                  ;
                  DAT_00828fa4 = DAT_00828fa4 + 1;
                }
                (&DAT_020b8e9f)[DAT_01b12e14] = 0;
                DAT_01b12e14 = DAT_01b12e14 + -1;
              }
              else {
                DAT_01b12e10 = DAT_01b12e10 + 1;
                DAT_01b12e14 = DAT_01b12e14 + 1;
                if (DAT_01b12e14 != DAT_01b12e10) {
                  iVar1 = DAT_01b12e10 - DAT_01b12e14;
                  *param_1 = DAT_01b12e14;
                  for (iVar1 = (iVar1 + -1) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
                    (&DAT_020b8e9f)[*param_1] = (&DAT_020b8e9e)[*param_1];
                    *param_1 = *param_1 + -1;
                  }
                }
                (&DAT_020b8e9f)[DAT_01b12e10] = (char)(DAT_009ae2bc >> 0x18);
                if (DAT_00828fa0 == 0xd) {
                  puVar4 = (undefined4 *)&DAT_020b8ea0;
                  puVar6 = &DAT_009ae2bc;
                  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
                    *puVar6 = *puVar4;
                    puVar4 = puVar4 + 1;
                    puVar6 = puVar6 + 1;
                  }
                  DAT_01b12e10 = 0;
                  DAT_01b12e14 = 0;
                  FUN_005f34d1(&stack0xfffffffc,0x488a4c);
                  puVar2 = puVar9;
                  goto LAB_00488a50;
                }
              }
            }
          }
        }
      }
    }
LAB_00488a00:
    *param_1 = 3;
    return;
  }
LAB_00488a50:
  **(undefined4 **)(puVar2 + 8) = 4;
  *(undefined4 *)(puVar2 + -8) = 0;
  return;
}


