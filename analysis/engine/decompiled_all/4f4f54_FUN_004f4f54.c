// FUN_004f4f54 @ 004f4f54 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_004f4f54(char *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if ((*param_4 == 1) &&
     (((0 < *param_3 && (*param_1 == '9' || *param_1 == 'Z')) ||
      ((*param_3 < 0 && (puVar1 = &stack0xfffffffc, *param_1 == '0' || *param_1 == 'A')))))) {
LAB_004f524a:
    *(float *)(puVar1 + -0x30) = f_1;
    puVar2 = puVar1;
  }
  else {
    if (*param_4 < 3) {
      if (*param_4 == 2) {
        FUN_005f46bc(&stack0xfffffffc,0x4f5182);
        puVar2 = puVar4;
        FUN_005f34d1(puVar4,0x4f5198);
        puVar1 = puVar2;
        if (**(int **)(puVar2 + 0x10) < 0) {
          *(undefined4 *)(puVar2 + -0x14) = 4;
          DAT_008d1c00 = 1;
          do {
            if (*(short *)(s_ZZZ9999ZAAA0000AZZZZZ9Z9999999Z9_00794f80 + DAT_008d1c00 * 2 + 6) ==
                DAT_008d1c04) {
              *(undefined4 *)(puVar2 + -0x10) = 0;
              goto LAB_004f524a;
            }
            DAT_008d1c00 = DAT_008d1c00 + 1;
            *(int *)(puVar2 + -0x14) = *(int *)(puVar2 + -0x14) + -1;
          } while (0 < *(int *)(puVar2 + -0x14));
        }
        else {
          *(undefined4 *)(puVar2 + -0xc) = 4;
          DAT_008d1c00 = 1;
          do {
            if (*(short *)(DAT_008d1c00 * 2 + 0x794f7e) == DAT_008d1c04) {
              *(undefined4 *)(puVar2 + -8) = 0;
              goto LAB_004f524a;
            }
            DAT_008d1c00 = DAT_008d1c00 + 1;
            *(int *)(puVar2 + -0xc) = *(int *)(puVar2 + -0xc) + -1;
          } while (0 < *(int *)(puVar2 + -0xc));
        }
      }
    }
    else {
      FUN_005f46bc(&stack0xfffffffc,0x4f5057);
      puVar2 = puVar3;
      FUN_005f34d1(puVar3,0x4f506d);
      puVar1 = puVar2;
      if (**(int **)(puVar2 + 0x10) < 0) {
        *(undefined4 *)(puVar2 + -0x24) = 8;
        DAT_008d1c00 = 1;
        do {
          if ((*(uint *)(s_ZZZ9999ZAAA0000AZZZZZ9Z9999999Z9_00794f80 + DAT_008d1c00 * 3 + 0x25) &
              0xffffff) == (DAT_008d1c08 & 0xffffff)) {
            *(undefined4 *)(puVar2 + -0x20) = 0;
            goto LAB_004f524a;
          }
          DAT_008d1c00 = DAT_008d1c00 + 1;
          *(int *)(puVar2 + -0x24) = *(int *)(puVar2 + -0x24) + -1;
        } while (0 < *(int *)(puVar2 + -0x24));
      }
      else {
        *(undefined4 *)(puVar2 + -0x1c) = 8;
        DAT_008d1c00 = 1;
        do {
          if ((*(uint *)(s_ZZZ9999ZAAA0000AZZZZZ9Z9999999Z9_00794f80 + DAT_008d1c00 * 3 + 0xd) &
              0xffffff) == (DAT_008d1c08 & 0xffffff)) {
            *(undefined4 *)(puVar2 + -0x18) = 0;
            goto LAB_004f524a;
          }
          DAT_008d1c00 = DAT_008d1c00 + 1;
          *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
        } while (0 < *(int *)(puVar2 + -0x1c));
      }
    }
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  return (float10)*(float *)(puVar2 + -0x30);
}


