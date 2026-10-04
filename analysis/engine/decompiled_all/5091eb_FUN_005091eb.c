// FUN_005091eb @ 005091eb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005091eb(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_a4;
  int *local_a0;
  undefined4 local_9c;
  char *local_98;
  undefined4 *local_94;
  int local_90;
  undefined4 local_8c [9];
  int local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((DAT_019c66ec == 2) || (*param_2 != 0)) {
    local_8c[0] = 0;
    local_9c = 8;
    local_98 = "midilist";
    local_94 = (undefined4 *)0x2;
    local_90 = 4;
    local_68 = FUN_005f6540(local_8c,3,0x784ff01,&DAT_00766fe0,&local_9c);
    if (local_68 == 0) {
      if (DAT_019c66ec == 2) {
        local_64 = 0;
LAB_00509299:
        while( true ) {
          local_8c[0] = 0;
          local_9c = 0x200;
          local_98 = (char *)&DAT_020b8ea0;
          local_94 = (undefined4 *)0x1;
          local_28 = FUN_005fdbd0(local_8c,3,0x784ff01,&DAT_00766fdc,&local_9c,&DAT_00795768);
          if (local_28 != 0) break;
          DAT_019c66ec = 0;
          thunk_FUN_00518448();
          local_24 = 4;
          DAT_00940428 = 1;
          do {
            if ((*(uint *)((int)&DAT_00795780 + DAT_00940428 * 3 + 1) & 0xffffff) ==
                (_DAT_020b8ea0 & 0xffffff)) {
              local_20 = 0;
              DAT_00940420 = (char *)0x2;
              iVar1 = 0x10;
              DAT_00940424 = 1;
              goto LAB_0050938c;
            }
            DAT_00940428 = DAT_00940428 + 1;
            local_24 = local_24 + -1;
          } while (0 < local_24);
          if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_004b5254) {
            local_1c = 0;
            DAT_00940420 = (char *)(int)ROUND(P2);
            iVar1 = 0x10;
            DAT_00940424 = 1;
            do {
              local_90 = (int)ROUND((&P2)[DAT_00940424]);
              param_2[(int)DAT_00940420 * 0x10 + DAT_00940424 + -0x11] = local_90;
              DAT_00940424 = DAT_00940424 + 1;
              iVar1 = iVar1 + -1;
            } while (0 < iVar1);
            local_14 = 0;
          }
          else {
            if ((_DAT_020b8ea0 & 0xffffff) == 0x504d54) {
              DAT_019c66f0 = (int)ROUND(P2);
              local_90 = DAT_019c66f0;
            }
            local_18 = 0;
          }
        }
      }
      else {
        local_60 = 0x10;
        DAT_00940428 = 1;
        do {
          if (param_2[DAT_00940428 * 0x10 + -0x10] == 0) {
            local_5c = 0;
          }
          else {
            local_58 = 0xf;
            DAT_00940424 = 2;
            do {
              if (param_2[DAT_00940424 + DAT_00940428 * 0x10 + -0x11] == 0) {
                local_54 = 0;
                break;
              }
              DAT_00940424 = DAT_00940424 + 1;
              local_58 = local_58 + -1;
            } while (0 < local_58);
            local_8c[0] = 0;
            local_94 = &DAT_00940428;
            FUN_005fc330(local_8c,3,0x784ff00,&DAT_00766fd8,&local_94,&DAT_00795710);
            local_a0 = param_2 + DAT_00940428 * 0x10 + -0x10;
            local_98 = (char *)(DAT_00940424 + -1);
            if ((int)local_98 < 0) {
              local_98 = (char *)0x0;
            }
            DAT_00940420 = local_98 + 1;
            local_a4 = 1;
            local_9c = 1;
            local_94 = (undefined4 *)0x4;
            FUN_005fc980(local_8c,&DAT_00766fd4,&local_a4);
          }
          local_4c = 0;
          DAT_00940428 = DAT_00940428 + 1;
          local_60 = local_60 + -1;
        } while (0 < local_60);
        local_48 = 4;
        DAT_0094041c = 1;
        do {
          DAT_00940428 = 1;
          local_44 = 0x10;
          DAT_00940424 = 1;
          do {
            (&IP1)[DAT_00940428] =
                 *(int *)(DAT_00940424 * 0x10 + DAT_0094041c * 4 + param_1 + -0x14);
            if (param_2[DAT_00940424 * 0x10 + -0x10] == 0) {
              local_40 = 0;
            }
            else {
              *(int *)(&IP0 + DAT_00940428 * 4) = DAT_00940424;
              DAT_00940428 = DAT_00940428 + 2;
            }
            local_3c = 0;
            DAT_00940424 = DAT_00940424 + 1;
            local_44 = local_44 + -1;
          } while (0 < local_44);
          local_98 = (char *)(DAT_0094041c * 3 + 0x795781);
          local_8c[0] = 0;
          local_9c = 3;
          local_94 = (undefined4 *)0x3;
          FUN_005fc330(local_8c,3,0x784ff00,&DAT_00766fd0,&local_9c,&DAT_0079572c);
          local_a0 = &IP1;
          local_98 = (char *)(DAT_00940428 + -1);
          if ((int)local_98 < 0) {
            local_98 = (char *)0x0;
          }
          DAT_00940420 = local_98 + 1;
          local_a4 = 1;
          local_9c = 1;
          local_94 = (undefined4 *)0x4;
          FUN_005fc980(local_8c,&DAT_00766fd4,&local_a4);
          local_34 = 0;
          DAT_0094041c = DAT_0094041c + 1;
          local_48 = local_48 + -1;
        } while (0 < local_48);
        local_8c[0] = 0;
        local_94 = &DAT_019c66f0;
        FUN_005fc330(local_8c,3,0x784ff00,&DAT_00766fcc,&local_94,&DAT_0079574c);
        local_2c = 0;
      }
    }
    local_8c[0] = 0;
    FUN_005f7950(local_8c,3,0x784ff00,&DAT_00766fc8,0);
  }
  return;
  while( true ) {
    local_90 = (int)ROUND((&P1)[(int)DAT_00940420]);
    *(int *)(DAT_00940418 * 0x10 + DAT_00940428 * 4 + param_1 + -0x14) = local_90;
    DAT_00940420 = DAT_00940420 + 2;
    DAT_00940424 = DAT_00940424 + 1;
    iVar1 = iVar1 + -1;
    if (iVar1 < 1) break;
LAB_0050938c:
    DAT_00940418 = (int)ROUND(*(float *)(&P0 + (int)DAT_00940420 * 4));
    if (DAT_00940418 == 0) {
      local_10 = 0;
      local_90 = 0;
      goto LAB_00509299;
    }
  }
  local_c = 0;
  goto LAB_00509299;
}


