// FUN_0058a2ff @ 0058a2ff (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058a2ff(int *param_1,int param_2)

{
  int iVar1;
  int local_64;
  int local_38;
  
  if (*param_1 == 0) {
    *param_1 = 1;
  }
  else if (DAT_01a9f348 != 0) {
    DAT_009a9304 = 1;
LAB_0058a34c:
    DAT_009a9300 = DAT_009a9304;
    local_64 = (*param_1 - DAT_009a9304) + 1;
    DAT_009a92fc = DAT_009a9304;
    if (0 < local_64) {
      while (*(char *)(param_2 + -1 + DAT_009a92fc) != '/') {
        DAT_009a92fc = DAT_009a92fc + 1;
        local_64 = local_64 + -1;
        if (local_64 < 1) goto LAB_0058a54d;
      }
      if (DAT_009a92fc != *param_1) {
        DAT_01a9f330 = DAT_009a92fc + 1;
        do {
          DAT_01f95c84 = DAT_009a9300;
          DAT_009a92f8 = DAT_01a9f330;
          for (iVar1 = (*param_1 - DAT_01a9f330) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
            if (*(char *)(param_2 + -1 + DAT_01f95c84) != *(char *)(param_2 + -1 + DAT_009a92f8)) {
              DAT_009a9304 = DAT_01a9f330;
              goto LAB_0058a34c;
            }
            DAT_01f95c84 = DAT_01f95c84 + 1;
            if (*(char *)(param_2 + -1 + DAT_009a92f8) == '/') break;
            DAT_009a92f8 = DAT_009a92f8 + 1;
          }
          DAT_009a92f8 = DAT_009a92f8 - DAT_01a9f330;
          DAT_009a9304 = DAT_01a9f330;
          for (iVar1 = (*param_1 - DAT_01a9f330) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
            *(undefined1 *)(param_2 + -1 + DAT_009a9304) =
                 *(undefined1 *)(param_2 + -1 + DAT_009a92f8 + DAT_009a9304);
            DAT_009a9304 = DAT_009a9304 + 1;
          }
          *param_1 = *param_1 - DAT_009a92f8;
          DAT_01a9f330 = DAT_01a9f330 + 1;
        } while (DAT_01a9f330 < *param_1);
      }
    }
LAB_0058a54d:
    DAT_009a9304 = 2;
LAB_0058a558:
    local_38 = (*param_1 - DAT_009a9304) + 1;
    DAT_009a92fc = DAT_009a9304;
    if (0 < local_38) {
      do {
        if (*(char *)(param_2 + -1 + DAT_009a92fc) == '/') {
          DAT_01f95c84 = 0;
          DAT_01a9f330 = DAT_009a92fc + 1;
          iVar1 = (*param_1 - DAT_01a9f330) + 1;
          for (; (0 < iVar1 && (*(char *)(param_2 + -1 + DAT_01a9f330) == '/'));
              DAT_01a9f330 = DAT_01a9f330 + 1) {
            iVar1 = iVar1 + -1;
            DAT_01f95c84 = DAT_01f95c84 + 1;
          }
          DAT_01f95c84 = DAT_01f95c84 + 1;
          if (3 < DAT_01f95c84) goto LAB_0058a66b;
        }
        DAT_009a92fc = DAT_009a92fc + 1;
        local_38 = local_38 + -1;
        if (local_38 < 1) break;
      } while( true );
    }
  }
  *(undefined1 *)(param_2 + -1 + *param_1) = 0x3b;
  DAT_009a9304 = *param_1 + 1;
  for (iVar1 = 0x181 - DAT_009a9304; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)(param_2 + -1 + DAT_009a9304) = 0x20;
    DAT_009a9304 = DAT_009a9304 + 1;
  }
  return;
LAB_0058a66b:
  *(undefined1 *)(param_2 + -1 + DAT_009a92fc) = 0x58;
  DAT_01a9f330 = DAT_009a92fc + 1;
  DAT_009a92f8._0_1_ = (char)DAT_01f95c84;
  if (9 < DAT_01f95c84) {
    *(char *)(param_2 + -1 + DAT_01a9f330) = (char)(DAT_01f95c84 / 10) + '0';
    DAT_009a92f8._0_1_ = (char)(DAT_01f95c84 % 10);
    DAT_01a9f330 = DAT_01a9f330 + 1;
  }
  *(char *)(param_2 + -1 + DAT_01a9f330) = (char)DAT_009a92f8 + '0';
  DAT_009a92f8 = 3;
  if (9 < DAT_01f95c84) {
    DAT_009a92f8 = 4;
  }
  DAT_01f95c84 = DAT_01f95c84 - DAT_009a92f8;
  *param_1 = *param_1 - DAT_01f95c84;
  DAT_009a9300 = DAT_009a92f8 + DAT_009a92fc + -1;
  DAT_009a9304 = DAT_009a9300;
  for (iVar1 = (*param_1 - DAT_009a9300) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)(param_2 + -1 + DAT_009a9300) =
         *(undefined1 *)(param_2 + -1 + DAT_01f95c84 + DAT_009a9300);
    DAT_009a9300 = DAT_009a9300 + 1;
  }
  DAT_009a9304 = DAT_009a9304 + 1;
  goto LAB_0058a558;
}


