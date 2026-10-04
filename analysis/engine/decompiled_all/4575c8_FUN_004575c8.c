// FUN_004575c8 @ 004575c8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004575c8(undefined4 param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 in_FPUControlWord;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  DAT_007fec9c = *param_2;
  DAT_007fec98 = *param_3;
  if (DAT_007fec98 - DAT_007fec9c < 0x32) {
    FUN_005f33c9(&stack0xfffffffc,0x457621);
    FUN_005f34d1(puVar8,0x45763c);
    DAT_02091d04 = 0xfffffb2e;
    thunk_FUN_00571f5d("Number of points per segment?",0x1e);
    FUN_005f34d1(puVar8,0x457679);
    uVar6 = (byte)DAT_020b8ea0 < 2;
    uVar7 = (byte)DAT_020b8ea0 == 2;
    if ((bool)uVar7) {
      *(undefined4 *)(puVar8 + -0x44) = 0;
    }
    else {
      thunk_FUN_00518448();
      fVar1 = P1;
      iVar2 = 1;
      pbVar3 = (byte *)&DAT_020b8ea0;
      pbVar5 = &DAT_007613a0;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        uVar6 = *pbVar3 < *pbVar5;
        uVar7 = *pbVar3 == *pbVar5;
        pbVar3 = pbVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while ((bool)uVar7);
      if ((bool)uVar6 || (bool)uVar7) {
        *(undefined2 *)(puVar8 + -0x74) = in_FPUControlWord;
        *(ushort *)(puVar8 + -0x72) = (ushort)*(undefined4 *)(puVar8 + -0x74) | 0xc00;
        *(int *)(puVar8 + -0x70) = (int)ROUND(fVar1);
        DAT_01c23744 = *(int *)(puVar8 + -0x70);
        if (DAT_01c23744 == 0) {
          DAT_01c23744 = 0x14;
        }
        iVar2 = **(int **)(puVar8 + 8);
        *(int *)(puVar8 + -0x3c) = iVar2;
        DAT_007fec94 = 1;
        DAT_007fec90 = DAT_01fd3f80;
        DAT_007fec8c = DAT_02004cc0;
        while (DAT_01fd3f80 = DAT_007fec90, DAT_02004cc0 = DAT_007fec8c, 0 < iVar2) {
          (&PT_X0)[DAT_007fec94] = ((&PT_X0)[DAT_007fec94] + -8000) / 100;
          (&PT_Y0)[DAT_007fec94] = ((&PT_Y0)[DAT_007fec94] + 19000) / 100;
          DAT_007fec94 = DAT_007fec94 + 1;
          *(int *)(puVar8 + -0x3c) = *(int *)(puVar8 + -0x3c) + -1;
          DAT_007fec90 = DAT_01fd3f80;
          DAT_007fec8c = DAT_02004cc0;
          iVar2 = *(int *)(puVar8 + -0x3c);
        }
        DAT_007fec94 = 1;
        while( true ) {
          iVar2 = DAT_007fec94 + 1;
          DAT_007fec88 = (&PT_X0)[iVar2];
          DAT_007fec84 = (&PT_Y0)[iVar2];
          if ((DAT_007fec88 == DAT_007fec90) && (DAT_007fec84 == DAT_007fec8c)) {
            DAT_007fec80 = iVar2;
            if (*(short *)((int)&DAT_01fbb8dc + iVar2 * 2 + 2) != 0) {
              DAT_007fec80 = DAT_007fec94;
            }
            iVar4 = DAT_007fec80;
            DAT_007fec94 = iVar2;
            *(int *)(puVar8 + -0x78) = **(int **)(puVar8 + 8) - DAT_007fec80;
            thunk_FUN_0054c4c6(&DAT_01fd3f80 + iVar4,&PT_X0 + iVar4,puVar8 + -0x78);
            iVar2 = DAT_007fec80;
            *(int *)(puVar8 + -0x78) = **(int **)(puVar8 + 8) - DAT_007fec80;
            thunk_FUN_0054c4c6(&DAT_02004cc0 + iVar2,&PT_Y0 + iVar2,puVar8 + -0x78);
            iVar2 = DAT_007fec80;
            iVar4 = DAT_007fec80 * 2;
            *(int *)(puVar8 + -0x78) = (**(int **)(puVar8 + 8) - DAT_007fec80) / 2;
            thunk_FUN_0054c4c6(&DAT_01fbb8e0 + iVar2,iVar4 + 0x1fbb8de,puVar8 + -0x78);
            **(int **)(puVar8 + 8) = **(int **)(puVar8 + 8) + -1;
            if (DAT_007fec94 <= DAT_007fec98) {
              DAT_007fec98 = DAT_007fec98 + -1;
            }
            if (DAT_007fec94 <= DAT_007fec9c) {
              DAT_007fec9c = DAT_007fec9c + -1;
            }
            DAT_007fec94 = DAT_007fec94 + -1;
            *(undefined4 *)(puVar8 + -0x34) = 0;
          }
          else {
            DAT_007fec94 = iVar2;
            *(undefined4 *)(puVar8 + -0x38) = 0;
            DAT_007fec90 = DAT_007fec88;
            DAT_007fec8c = DAT_007fec84;
          }
          if (**(int **)(puVar8 + 8) <= DAT_007fec94) break;
          *(undefined4 *)(puVar8 + -0x2c) = 0;
        }
        *(undefined4 *)(puVar8 + -0x30) = 0;
        if (DAT_007fec98 - DAT_007fec9c < 2) {
          thunk_FUN_0054946a("*** Must have more than 2 points.",0x22);
          *(undefined4 *)(puVar8 + -0x24) = 0;
        }
        else {
          *(undefined4 *)(puVar8 + -0x28) = 0;
          DAT_007fec94 = DAT_007fec9c;
          DAT_007fec90 = 0;
          DAT_007fec84 = 0;
          iVar2 = (DAT_007fec98 - DAT_007fec9c) + 1;
          *(int *)(puVar8 + -0x1c) = iVar2;
          iVar4 = DAT_007fec90;
          while (0 < iVar2) {
            DAT_007fec90 = iVar4 + 1;
            iVar2 = (&PT_X0)[DAT_007fec94];
            iVar4 = iVar2;
            if (iVar2 < 0) {
              iVar4 = -iVar2;
            }
            if (DAT_007fec84 < iVar4) {
              DAT_007fec84 = iVar4;
            }
            *(int *)(&DAT_01c23680 + DAT_007fec90 * 200) = iVar2;
            iVar2 = (&PT_Y0)[DAT_007fec94];
            DAT_007fec7c = iVar2;
            if (iVar2 < 0) {
              DAT_007fec7c = -iVar2;
            }
            if (DAT_007fec84 < DAT_007fec7c) {
              DAT_007fec84 = DAT_007fec7c;
            }
            *(int *)(&DAT_01c23684 + DAT_007fec90 * 200) = iVar2;
            DAT_007fec94 = DAT_007fec94 + 1;
            *(int *)(puVar8 + -0x1c) = *(int *)(puVar8 + -0x1c) + -1;
            iVar4 = DAT_007fec90;
            iVar2 = *(int *)(puVar8 + -0x1c);
          }
          DAT_007feca0 = 10;
          if (0x640 < DAT_007fec7c) {
            DAT_007feca0 = (int)(16000 / (longlong)DAT_007fec7c);
          }
          DAT_007fec90 = iVar4;
          *(int *)(puVar8 + -0x18) = iVar4;
          DAT_007fec94 = 1;
          while (0 < iVar4) {
            *(int *)(&DAT_01c23680 + DAT_007fec94 * 200) =
                 *(int *)(&DAT_01c23680 + DAT_007fec94 * 200) * DAT_007feca0;
            *(int *)(&DAT_01c23684 + DAT_007fec94 * 200) =
                 *(int *)(&DAT_01c23684 + DAT_007fec94 * 200) * DAT_007feca0;
            DAT_007fec94 = DAT_007fec94 + 1;
            *(int *)(puVar8 + -0x18) = *(int *)(puVar8 + -0x18) + -1;
            iVar4 = *(int *)(puVar8 + -0x18);
          }
          _DAT_007fec78 = 0;
          DAT_01c23740 = DAT_007fec90;
          FUN_00458c2a(&DAT_007fec78,&DAT_007feca0,*(undefined4 *)(puVar8 + 0xc));
          FUN_004588e0(&DAT_007fec78,&DAT_007feca0);
          if (DAT_007fec98 == **(int **)(puVar8 + 8)) {
            **(int **)(puVar8 + 8) = DAT_007fec9c + DAT_007feca0 + -1;
            *(undefined4 *)(puVar8 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar8 + -0x14) = 0;
            DAT_007fec8c = DAT_007feca0 + DAT_007fec9c;
            DAT_007fec88 = (**(int **)(puVar8 + 8) - DAT_007fec98) + DAT_007fec8c + -1;
            DAT_007fec74 = **(int **)(puVar8 + 8) + 1;
            iVar2 = -(**(int **)(puVar8 + 8) - DAT_007fec98) / -1;
            DAT_007fec90 = DAT_007fec88;
            *(int *)(puVar8 + -0xc) = iVar2;
            while (0 < iVar2) {
              DAT_007fec74 = DAT_007fec74 + -1;
              (&PT_X0)[DAT_007fec88] = (&PT_X0)[DAT_007fec74];
              (&PT_Y0)[DAT_007fec88] = (&PT_Y0)[DAT_007fec74];
              *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fec88 * 2 + 2) =
                   *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fec74 * 2 + 2);
              DAT_007fec88 = DAT_007fec88 + -1;
              *(int *)(puVar8 + -0xc) = *(int *)(puVar8 + -0xc) + -1;
              iVar2 = *(int *)(puVar8 + -0xc);
            }
            **(int **)(puVar8 + 8) = DAT_007fec90;
          }
          iVar2 = DAT_007feca0;
          DAT_007fec90 = DAT_007fec9c + -1;
          DAT_007fec7c = (int)*(short *)((int)&DAT_01fbb8dc + DAT_007fec9c * 2 + 2);
          if (DAT_007fec7c == 0) {
            DAT_007fec7c = -2;
          }
          *(int *)(puVar8 + -8) = DAT_007feca0;
          DAT_007fec94 = 1;
          while (0 < iVar2) {
            DAT_007fec90 = DAT_007fec90 + 1;
            DAT_007fec84 = 0;
            DAT_007fec8c = (&DAT_01c1e900)[DAT_007fec94 * 2];
            if (DAT_007fec8c < 10000) {
              *(undefined4 *)(puVar8 + -4) = 0;
            }
            else {
              DAT_007fec8c = DAT_007fec8c + -20000;
              DAT_007fec84 = -1;
            }
            (&PT_X0)[DAT_007fec90] = DAT_007fec8c;
            (&PT_Y0)[DAT_007fec90] = (&DAT_01c1e904)[DAT_007fec94 * 2];
            *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fec90 * 2 + 2) = (undefined2)DAT_007fec84;
            DAT_007fec94 = DAT_007fec94 + 1;
            *(int *)(puVar8 + -8) = *(int *)(puVar8 + -8) + -1;
            iVar2 = *(int *)(puVar8 + -8);
          }
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fec9c * 2 + 2) = (undefined2)DAT_007fec7c;
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fec90 * 2 + 2) = 0xfffd;
          FUN_00457f60(*(undefined4 *)(puVar8 + 8));
          FUN_00457e7f(&DAT_0076139c);
          FUN_0045a585(*(undefined4 *)(puVar8 + 8));
        }
      }
      else {
        *(undefined4 *)(puVar8 + -0x40) = 0;
      }
    }
  }
  else {
    thunk_FUN_0054946a("*** Too many points. Limit=50",0x1e);
  }
  return;
}


