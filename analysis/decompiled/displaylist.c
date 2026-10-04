// ===== FUN_005a4900 @ 005a4900 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a4900(HWND param_1)

{
  CWinApp *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_a4 [16];
  CDC *local_64;
  CRect local_60 [16];
  CPoint local_50 [8];
  CPoint local_48 [8];
  CView *local_40;
  CFrameWnd *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar3 = local_a4;
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_2c = DAT_01576460 + _DAT_0157645c;
  local_28 = DAT_01576460;
  DAT_01576454 = 0;
  DAT_01576450 = 0;
  local_30 = 0;
  local_20 = 0;
  do {
    if (local_2c <= local_28) {
      DAT_00d97cd8 = 0;
      pCVar1 = AfxGetApp();
      local_38 = *(int **)(pCVar1 + 0x20);
      (**(code **)(*local_38 + 200))();
      local_3c = (CFrameWnd *)FUN_005ed37c();
      local_40 = CFrameWnd::GetActiveView(local_3c);
      CPoint::CPoint(local_48);
      CPoint::CPoint(local_50);
      CRect::CRect(local_60);
      local_64 = CWnd::GetDC((CWnd *)local_40);
      (**(code **)(*(int *)local_64 + 0x3c))(5);
      FUN_005ed37c();
      thunk_FUN_005a42e0(local_64);
      InvalidateRect(param_1,(RECT *)0x0,1);
      FUN_005ed37c();
      UpdateWindow(param_1);
      FUN_005ed37c();
      local_c = 0x5a4c1c;
      FUN_005ed37c();
      return;
    }
    local_24 = 0;
    local_18 = local_28;
    local_c = DAT_01576454;
    local_10 = local_20;
    local_14 = 0;
    (&DAT_0156c110)[DAT_01576454] = local_20;
    (&DAT_01561dd0)[DAT_01576454] = (&DAT_009c73e0)[local_28];
    (&DAT_01557a90)[DAT_01576454] = local_30;
    local_1c = 0;
    while( true ) {
      do {
        for (; ((&DAT_009c73e0)[local_28] & 0xff000000) == 0xff000000; local_28 = local_28 + 3) {
        }
        local_34 = (&DAT_009c73d8)[local_28] * DAT_007a0a80 >> 8;
        if (((&DAT_009c73d8)[local_28] * DAT_007a0a80 & 0x80U) != 0) {
          local_34 = local_34 + 1;
        }
        *(int *)(&DAT_00db6890 + local_30 * 8) = local_34;
        local_8 = *(int *)(&DAT_009c73dc + local_28 * 4) * DAT_007a0a80 & 0x80;
        local_34 = *(int *)(&DAT_009c73dc + local_28 * 4) * DAT_007a0a80 >> 8;
        if (local_8 != 0) {
          local_34 = local_34 + 1;
        }
        *(int *)(&DAT_00db6894 + local_30 * 8) = local_34;
        local_30 = local_30 + 1;
        local_1c = local_1c + 1;
        local_28 = local_28 + 3;
        if (local_2c <= local_28) goto LAB_005a4afc;
      } while (((&DAT_009c73e0)[local_28] & 0xff000000) == 0);
      if (((&DAT_009c73e0)[local_28] & 0xff000000) != 0x3000000) break;
      *(int *)(&DAT_00da2210 + local_20 * 4) = local_1c;
      local_20 = local_20 + 1;
      local_24 = local_24 + 1;
      local_1c = 0;
    }
LAB_005a4afc:
    *(int *)(&DAT_00da2210 + local_20 * 4) = local_1c;
    local_20 = local_20 + 1;
    local_24 = local_24 + 1;
    (&DAT_00dac550)[DAT_01576450] = local_24;
    DAT_01576450 = DAT_01576450 + 1;
    (&DAT_00d97ed0)[DAT_01576454] = local_1c;
    DAT_01576454 = DAT_01576454 + 1;
  } while( true );
}


// ===== FUN_005a4570 @ 005a4570 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a4570(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_68 [16];
  int local_28;
  undefined4 *local_24;
  float *local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = DAT_01576464;
  puVar4 = local_68;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = DAT_01576464;
  local_14 = 0;
  DAT_016fb378 = 0;
  while (local_14 < iVar2) {
    (&DAT_017031fc)[DAT_016fb378] = local_14;
    iVar3 = local_14;
    do {
      local_14 = iVar3;
      iVar3 = local_14 + 1;
    } while ((&DAT_015e9c34)[local_14] != '\0');
    local_10 = 0;
    if (0xfa < DAT_016fb378) {
      local_1c = local_14 + 1;
    }
    (&DAT_01664ff4)[DAT_016fb378] = *(undefined4 *)(&DAT_015e9c35 + local_14);
    local_20 = (float *)(local_14 + 0x15e9c39);
    (&DAT_0165d174)[DAT_016fb378] = *local_20 / (float)_DAT_0076d9a0;
    (&DAT_016f34f8)[DAT_016fb378] = *(undefined4 *)(&DAT_015e9c3d + local_14);
    (&DAT_016e37f8)[DAT_016fb378] = *(undefined4 *)(local_14 + 0x15e9c41);
    (&DAT_0166ce88)[DAT_016fb378 * 0xf] = *(undefined4 *)(local_14 + 0x15e9c45);
    (&DAT_0166ce8c)[DAT_016fb378 * 0x3c] = *(undefined1 *)(local_14 + 0x15e9c49);
    (&DAT_0166ce8d)[DAT_016fb378 * 0x3c] = *(undefined1 *)(local_14 + 0x15e9c4d);
    local_24 = (undefined4 *)(local_14 + 0x15e9c51);
    (&DAT_016eb678)[DAT_016fb378] = *local_24;
    local_14 = local_14 + 0x21;
    (&DAT_016fb37c)[DAT_016fb378] = local_14;
    for (local_28 = 0; local_28 < (int)(&DAT_016eb678)[DAT_016fb378]; local_28 = local_28 + 1) {
      local_14 = local_14 + 8;
      do {
        pcVar1 = &DAT_015e9c34 + local_14;
        local_14 = local_14 + 1;
      } while (*pcVar1 != '\0');
    }
    DAT_016fb378 = DAT_016fb378 + 1;
  }
  for (local_8 = 2; local_8 < DAT_01576468 + -3; local_8 = local_8 + 3) {
    local_c = local_8 + 3;
    if ((((&DAT_009c73d8)[local_8] & 0xff000000) != 0) &&
       (((&DAT_009c73d8)[local_c] & 0xff000000) != 0)) {
      (&DAT_009c73d8)[local_8] = (&DAT_009c73d8)[local_8] | 0xff000000;
    }
  }
  _DAT_01576458 = 0;
  DAT_01576460 = 0;
  _DAT_0157645c = DAT_01576468;
  thunk_FUN_005a4900(param_1);
  local_8 = 0x5a483e;
  FUN_005ed37c();
  return;
}


