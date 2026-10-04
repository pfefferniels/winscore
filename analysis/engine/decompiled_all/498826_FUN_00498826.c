// FUN_00498826 @ 00498826 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00498826(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4,
                 int *param_5)

{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined4 local_44;
  undefined *local_40;
  char *local_3c;
  undefined4 local_38;
  undefined4 local_34 [12];
  
  if ((*param_5 == 1) || (*param_5 != 2)) {
    local_40 = &DAT_007916dd + *param_4 * 7;
    local_34[0] = 0;
    local_4c = 0x80;
    local_48 = (undefined *)param_1;
    local_44 = 7;
    local_3c = (char *)0x7;
    local_38 = 2;
    iVar1 = FUN_005f6540(local_34,*param_3,0x784ff01,&DAT_007632c8,&local_4c);
  }
  else {
    local_48 = &DAT_007916dd + *param_4 * 7;
    local_34[0] = 0;
    local_54 = 0x80;
    local_50 = param_1;
    local_4c = 7;
    local_44 = 7;
    local_40 = (undefined *)0x6;
    local_3c = "binary";
    local_38 = 2;
    iVar1 = FUN_005f6540(local_34,*param_3,0x784ff01,&DAT_007632d8,&local_54);
  }
  if (iVar1 != 0) {
    *param_3 = 0xffffffff;
  }
  return;
}


