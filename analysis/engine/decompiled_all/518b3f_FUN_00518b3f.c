// FUN_00518b3f @ 00518b3f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518b3f(int *param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  float10 fVar11;
  
  thunk_FUN_0054c419(&P1,&DAT_00767808);
  if ((DAT_0078b4e4 != 0x20) || ((DAT_0078b4e0 != 0x2d && (DAT_0078b4e0 != 0x2b)))) {
    iVar5 = *param_1;
    iVar4 = (1 - iVar5) / -1;
    for (; (0 < iVar4 && ((&DAT_020b8e9f)[iVar5] != ' ')); iVar5 = iVar5 + -1) {
      iVar4 = iVar4 + -1;
    }
    if (EDIT_ITEM != 0) {
      iVar5 = *param_1;
      DAT_0094e1dc = 2;
      while (iVar5 = iVar5 + -1, 0 < iVar5) {
        DAT_0094e1c8 = (&DAT_020b8e9f)[DAT_0094e1dc];
        if ((((DAT_0094e1c8 != ',') && (')' < DAT_0094e1c8)) && (DAT_0094e1c8 < '0')) &&
           (DAT_0094e1c8 == *(char *)((int)&DAT_020b8ea0 + DAT_0094e1dc))) {
          if (DAT_0094e1c8 == '.') {
            (&DAT_020b8e9f)[DAT_0094e1dc] = 0x4d;
          }
          if (DAT_0094e1c8 == '-') {
            (&DAT_020b8e9f)[DAT_0094e1dc] = 0x53;
          }
          *(undefined1 *)((int)&DAT_020b8ea0 + DAT_0094e1dc) = 0x20;
        }
        DAT_0094e1dc = DAT_0094e1dc + 1;
      }
    }
    DAT_0094e1dc = -1;
    _DAT_0094e1c8 = 0;
    DAT_0094e1d8 = 0;
    DAT_0094e1e0 = 1;
    do {
      bVar3 = (&DAT_020b8e9f)[DAT_0094e1e0];
      _DAT_0094e1e4 = CONCAT31(DAT_0094e1e4_1,bVar3);
      if ((bVar3 == 0x20) || (bVar8 = bVar3 < 0x20, bVar3 == 0x20)) {
        DAT_0094e1dc = 1;
      }
      else {
        iVar5 = 1;
        bVar10 = false;
        pbVar6 = &DAT_0094e1e4;
        pbVar7 = &DAT_00767804;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar8 = *pbVar6 < *pbVar7;
          bVar10 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar10);
        if (bVar8) {
LAB_00518d77:
          if (bVar3 == 0x2e) {
            iVar5 = 1;
            bVar8 = true;
            bVar10 = false;
            pbVar6 = &DAT_020b8e9e + DAT_0094e1e0;
            pbVar7 = &DAT_00767800;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar10 = *pbVar6 < *pbVar7;
              bVar8 = *pbVar6 == *pbVar7;
              pbVar6 = pbVar6 + 1;
              pbVar7 = pbVar7 + 1;
            } while (bVar8);
            if (bVar10 || bVar8) {
              bVar10 = DAT_0094e1e0 == 0;
              bVar8 = DAT_0094e1e0 == 1;
              if (1 < DAT_0094e1e0) {
                iVar5 = 1;
                pbVar6 = &DAT_020b8e9e + DAT_0094e1e0;
                pbVar7 = &DAT_00767804;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar10 = *pbVar6 < *pbVar7;
                  bVar8 = *pbVar6 == *pbVar7;
                  pbVar6 = pbVar6 + 1;
                  pbVar7 = pbVar7 + 1;
                } while (bVar8);
                if (!bVar10) goto LAB_00518ed9;
              }
            }
            iVar5 = 1;
            pbVar6 = (byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0);
            pbVar7 = &DAT_00767804;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar10 = *pbVar6 < *pbVar7;
              bVar8 = *pbVar6 == *pbVar7;
              pbVar6 = pbVar6 + 1;
              pbVar7 = pbVar7 + 1;
            } while (bVar8);
            if (!bVar10) {
              iVar5 = 1;
              pbVar6 = (byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0);
              pbVar7 = &DAT_00767800;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar10 = *pbVar6 < *pbVar7;
                bVar8 = *pbVar6 == *pbVar7;
                pbVar6 = pbVar6 + 1;
                pbVar7 = pbVar7 + 1;
              } while (bVar8);
              if (bVar10 || bVar8) goto LAB_00518ed9;
            }
          }
          if (bVar3 == 0x2d) {
            bVar8 = *(byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0) < 0x2e;
            if (*(byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0) != 0x2e) {
              iVar5 = 1;
              pbVar6 = (byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0);
              pbVar7 = &DAT_00767804;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar2 = *pbVar7;
                bVar3 = *pbVar6;
                bVar8 = bVar3 < bVar2;
                pbVar6 = pbVar6 + 1;
                pbVar7 = pbVar7 + 1;
              } while (bVar3 == bVar2);
              bVar8 = !bVar8;
              bVar10 = !bVar8;
              iVar5 = 1;
              pbVar6 = (byte *)((int)&DAT_020b8ea0 + DAT_0094e1e0);
              pbVar7 = &DAT_00767800;
              bVar9 = bVar8;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar9 = *pbVar6 < *pbVar7;
                bVar10 = *pbVar6 == *pbVar7;
                pbVar6 = pbVar6 + 1;
                pbVar7 = pbVar7 + 1;
              } while (bVar10);
              if (!bVar9 && !bVar10 || !bVar8) goto LAB_00518ea3;
            }
            goto LAB_00518ed9;
          }
LAB_00518ea3:
          if (DAT_0094e1dc < 0) goto LAB_005190f5;
          if (DAT_0094e1dc != 0) {
            _DAT_0094e1e4 = CONCAT31(DAT_0094e1e4_1,DAT_007677d0);
            goto LAB_005190fd;
          }
        }
        else {
          iVar5 = 1;
          bVar8 = false;
          pbVar6 = &DAT_0094e1e4;
          pbVar7 = &DAT_00767800;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar8 = *pbVar6 < *pbVar7;
            bVar10 = *pbVar6 == *pbVar7;
            pbVar6 = pbVar6 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar10);
          if (!bVar8 && !bVar10) goto LAB_00518d77;
LAB_00518ed9:
          DAT_0094e1d8 = DAT_0094e1d8 + 1;
          DAT_0094e1dc = -1;
          DAT_0094e1d0 = DAT_0094e1e0 + 1;
          for (iVar5 = (*param_1 - DAT_0094e1d0) + 1; 0 < iVar5; iVar5 = iVar5 + -1) {
            if (((((&DAT_020b8e9f)[DAT_0094e1d0] == '-') || ((&DAT_020b8e9f)[DAT_0094e1d0] == '+'))
                || (((&DAT_020b8e9f)[DAT_0094e1d0] == '<' ||
                    (((((&DAT_020b8e9f)[DAT_0094e1d0] == '>' ||
                       ((&DAT_020b8e9f)[DAT_0094e1d0] == '*')) ||
                      ((&DAT_020b8e9f)[DAT_0094e1d0] == '/')) ||
                     (((&DAT_020b8e9f)[DAT_0094e1d0] == '=' ||
                      ((&DAT_020b8e9f)[DAT_0094e1d0] == ' ')))))))) ||
               ((&DAT_020b8e9f)[DAT_0094e1d0] == ',')) goto LAB_00519035;
            DAT_0094e1d0 = DAT_0094e1d0 + 1;
          }
          DAT_0094e1d0 = *param_1 + 1;
LAB_00519035:
          _DAT_0094e1d4 = DAT_0094e1d0 - DAT_0094e1e0;
          DAT_0094e1d0 = DAT_0094e1d0 + -1;
          iVar5 = DAT_0094e1d8 * 4;
          fVar11 = (float10)FUN_005191dc(&DAT_0094e1e0,&DAT_0094e1d0);
          *(float *)(&P0 + iVar5) = (float)fVar11;
          _DAT_0094e1e4 = CONCAT31(DAT_0094e1e4_1,DAT_007677d0);
        }
        while( true ) {
          if (DAT_0094e1d8 == 0x2d) {
            DAT_0094e1d8 = 0x2c;
          }
          puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + _DAT_0094e1c8);
          _DAT_0094e1c8 = _DAT_0094e1c8 + 1;
          *puVar1 = (char)_DAT_0094e1e4;
          if (DAT_0094e1dc < 1) break;
          _DAT_0094e1e4 = CONCAT31(DAT_0094e1e4_1,(&DAT_020b8e9f)[DAT_0094e1e0]);
LAB_005190f5:
          DAT_0094e1dc = 0;
LAB_005190fd:
          DAT_0094e1d8 = DAT_0094e1d8 + 1;
          *(int *)(&P0 + DAT_0094e1d8 * 4) = i_0;
        }
      }
      DAT_0094e1e0 = DAT_0094e1e0 + 1;
    } while (DAT_0094e1e0 <= *param_1);
    if (_DAT_0094e1c8 != *param_1) {
      DAT_0094e1e0 = _DAT_0094e1c8 + 1;
      for (iVar5 = (*param_1 - DAT_0094e1e0) + 1; 0 < iVar5; iVar5 = iVar5 + -1) {
        (&DAT_020b8e9f)[DAT_0094e1e0] = 0x20;
        DAT_0094e1e0 = DAT_0094e1e0 + 1;
      }
    }
  }
  return;
}


