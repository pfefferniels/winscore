// ===== FUN_005e5910 @ 005e5910 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e5910(CDC *param_1)

{
  char *pcVar1;
  CObject *pCVar2;
  tagSIZE *ptVar3;
  tagSIZE *ptVar4;
  tagSIZE *ptVar5;
  int *piVar6;
  tagRECT *ptVar7;
  CBrush *pCVar8;
  void *pvVar9;
  uint uVar10;
  CWnd *this;
  int iVar11;
  undefined4 *puVar12;
  undefined4 local_1124 [20];
  CSize local_10d4 [8];
  LONG local_10cc;
  LONG local_10c8;
  CSize local_10c4 [8];
  CSize local_10bc [8];
  int *local_10b4;
  int local_10b0;
  int local_10ac;
  int local_10a8;
  int local_10a4;
  int local_10a0;
  void *local_109c;
  int *local_1098;
  int local_1094;
  int local_1090;
  int local_108c;
  int local_1088;
  int local_1084;
  int local_1080;
  int local_107c;
  HBRUSH__ *local_1078;
  tagRECT local_1074;
  void *local_1064;
  int local_1060;
  int local_105c;
  undefined4 uStackY_64;
  
  FUN_005ed9e0();
  puVar12 = local_1124;
  for (iVar11 = 0x448; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = 0xcccccccc;
    puVar12 = puVar12 + 1;
  }
  pCVar2 = (CObject *)thunk_FUN_005e8220();
  AfxAssertValidObject(pCVar2,s_C__WS_WScoreView_cpp_007a14e8,DAT_007a15c4 + 2);
  (**(code **)(*(int *)param_1 + 0x34))();
  FUN_005ed37c();
  CDC::SetBkMode(param_1,1);
  CWnd::BeginPaint(this,(tagPAINTSTRUCT *)&stack0xffffffb4);
  iVar11 = CDC::IsPrinting(param_1);
  DAT_01a14c14 = iVar11 != 0;
  if ((DAT_01a14c15 != '\0') || ((bool)DAT_01a14c14)) {
    (**(code **)(*(int *)param_1 + 0x3c))();
    FUN_005ed37c();
    DAT_01a14bc0 = 0;
    DAT_01a14bc4 = 0;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x3c))();
    FUN_005ed37c();
    ptVar3 = (tagSIZE *)CSize::CSize(local_10bc,DAT_009c6e98,DAT_009c6e9c);
    ptVar4 = (tagSIZE *)CSize::CSize(local_10c4,DAT_009c6e90,DAT_009c6e94);
    ptVar5 = (tagSIZE *)CSize::CSize(local_10d4,DAT_009c6e88,DAT_009c6e8c);
    local_10cc = ptVar5->cx;
    local_10c8 = ptVar5->cy;
    CScrollView::SetScrollSizes((CScrollView *)this,5,*ptVar5,ptVar4,ptVar3);
    piVar6 = (int *)CScrollView::GetDeviceScrollPosition((CScrollView *)this);
    DAT_01a14bc0 = *piVar6;
    DAT_01a14bc4 = piVar6[1];
  }
  DAT_01a14c20 = -DAT_01a14bc0;
  DAT_01a14c1c = -DAT_01a14bc4;
  (**(code **)(*(int *)param_1 + 0x40))();
  FUN_005ed37c();
  CDC::SetPolyFillMode(param_1,1);
  if (DAT_00d97eb8 != 0xffffff) {
    CRect::CRect((CRect *)&local_1074);
    CreateSolidBrush(DAT_00d97eb8);
    local_1078 = (HBRUSH__ *)FUN_005ed37c();
    CDC::SelectObject(param_1,local_1078);
    ptVar7 = CRect::operator_struct_tagRECT_((CRect *)&local_1074);
    CWnd::GetClientRect(this,ptVar7);
    local_1074.right = local_1074.right - DAT_01a14c20;
    local_1074.left = local_1074.left - DAT_01a14c20;
    local_1074.bottom = local_1074.bottom - DAT_01a14c1c;
    local_1074.top = local_1074.top - DAT_01a14c1c;
    pCVar8 = CBrush::FromHandle(local_1078);
    CDC::FillRect(param_1,&local_1074,pCVar8);
    GetStockObject(4);
    pvVar9 = (void *)FUN_005ed37c();
    CDC::SelectObject(param_1,pvVar9);
    DeleteObject(local_1078);
    FUN_005ed37c();
  }
  if ((DAT_01a14c16 == '\0') && (DAT_01a14c14 == '\0')) {
    CreatePen(0,1,DAT_00d97ebc);
    DAT_01a14c04 = (void *)FUN_005ed37c();
    DAT_01a14bf8 = CDC::SelectObject(param_1,DAT_01a14c04);
    if (DAT_00d97ecc == 0) {
      CreatePen(0,1,DAT_00d97ec4);
      DAT_01a14c00 = (HGDIOBJ)FUN_005ed37c();
      for (local_105c = 0; local_105c < DAT_01576454; local_105c = local_105c + 1) {
        if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x1000000) {
          CDC::SelectObject(param_1,DAT_01a14c04);
          CDC::Polyline(param_1,(tagPOINT *)(&DAT_00db6890 + (&DAT_01557a90)[local_105c] * 8),
                        (&DAT_00d97ed0)[local_105c]);
        }
        else if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x2000000) {
          CDC::SelectObject(param_1,DAT_01a14c00);
          DAT_01a14c10 = (&DAT_01557a90)[local_105c];
          DAT_01a14c0c = (tagPOINT *)(&DAT_00db6890 + DAT_01a14c10 * 8);
          DAT_01a14c08 = (ulong *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4);
          CDC::PolyPolyline(param_1,DAT_01a14c0c,DAT_01a14c08,(&DAT_00dac550)[local_105c]);
        }
      }
      CDC::SelectObject(param_1,DAT_01a14bf8);
      DeleteObject(DAT_01a14c00);
      FUN_005ed37c();
    }
    else {
      for (local_105c = 0; local_105c < DAT_01576450; local_105c = local_105c + 1) {
        if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x1000000) {
          CreatePen(0,1,(&DAT_01561dd0)[local_105c] & 0xffffff);
          DAT_01a14bfc = (HGDIOBJ)FUN_005ed37c();
          CDC::SelectObject(param_1,DAT_01a14bfc);
          CDC::Polyline(param_1,(tagPOINT *)(&DAT_00db6890 + (&DAT_01557a90)[local_105c] * 8),
                        *(int *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4));
          CDC::SelectObject(param_1,DAT_01a14c04);
          DeleteObject(DAT_01a14bfc);
          FUN_005ed37c();
        }
        else {
          DAT_01a14c10 = (&DAT_01561dd0)[local_105c] & 0xffffff;
          if (DAT_01a14c10 == 0) {
            DAT_01a14c10 = DAT_00d97ec4;
          }
          CreateSolidBrush(DAT_01a14c10);
          local_1064 = (void *)FUN_005ed37c();
          CDC::SelectObject(param_1,local_1064);
          CreatePen(0,1,(&DAT_01561dd0)[local_105c] & 0xffffff);
          DAT_01a14bfc = (HGDIOBJ)FUN_005ed37c();
          CDC::SelectObject(param_1,DAT_01a14bfc);
          DAT_01a14c10 = (&DAT_01557a90)[local_105c];
          DAT_01a14c0c = (tagPOINT *)(&DAT_00db6890 + DAT_01a14c10 * 8);
          CDC::PolyPolygon(param_1,DAT_01a14c0c,
                           (int *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4),
                           (&DAT_00dac550)[local_105c]);
          GetStockObject(4);
          pvVar9 = (void *)FUN_005ed37c();
          CDC::SelectObject(param_1,pvVar9);
          DeleteObject(local_1064);
          FUN_005ed37c();
          CDC::SelectObject(param_1,DAT_01a14c04);
          DeleteObject(DAT_01a14bfc);
          FUN_005ed37c();
        }
      }
    }
    CDC::SelectObject(param_1,DAT_01a14bf8);
    DeleteObject(DAT_01a14c04);
    FUN_005ed37c();
    _DAT_01a14bf4 = 400;
    _DAT_01a14bf0 = 0;
    _DAT_01a14bec = 0;
    DAT_01a14be8 = 3;
    CDC::SetMapperFlags(param_1,0);
    SetTextColor(*(HDC *)(param_1 + 4),DAT_00d97ec0);
    FUN_005ed37c();
    _DAT_01a14be0 = (float)DAT_007a0a80;
    for (local_105c = 0; local_105c < DAT_016fb378; local_105c = local_105c + 1) {
      DAT_01a14be4 = __ftol();
      local_107c = __ftol();
      local_1060 = 0;
      do {
        s_Anastasia_007a1500[local_1060] = (&DAT_015e9c34)[local_1060 + (&DAT_017031fc)[local_105c]]
        ;
        pcVar1 = s_Anastasia_007a1500 + local_1060;
        local_1060 = local_1060 + 1;
      } while (*pcVar1 != '\0');
      local_1080 = (&DAT_016f34f8)[local_105c];
      uStackY_64 = 0x5e6185;
      CreateFontA(-DAT_01a14be4,local_107c,local_1080,local_1080,(&DAT_0166ce88)[local_105c * 0xf],
                  (uint)(byte)(&DAT_0166ce8c)[local_105c * 0x3c],
                  (uint)(byte)(&DAT_0166ce8d)[local_105c * 0x3c],0,DAT_01a14be8,3,2,1,0x50,
                  s_Anastasia_007a1500);
      DAT_01a14bdc = (HGDIOBJ)FUN_005ed37c();
      pvVar9 = CDC::SelectObject(param_1,DAT_01a14bdc);
      if (pvVar9 != (void *)0x0) {
        DAT_01a14c10 = DAT_00d97ec0;
        if (DAT_00d97ec0 == 0xffffff) {
          DAT_01a14c10 = (&DAT_016e37f8)[local_105c];
        }
        SetTextColor(*(HDC *)(param_1 + 4),DAT_01a14c10);
        FUN_005ed37c();
        local_1090 = (&DAT_016fb37c)[local_105c];
        for (local_1094 = 0; local_1094 < (int)(&DAT_016eb678)[local_105c];
            local_1094 = local_1094 + 1) {
          local_1088 = *(int *)(&DAT_015e9c34 + local_1090);
          local_1098 = (int *)(&DAT_015e9c38 + local_1090);
          local_108c = *local_1098;
          local_1090 = local_1090 + 8;
          DAT_01a14c10 = local_1088 * DAT_007a0a80 >> 8;
          if ((local_1088 * DAT_007a0a80 & 0x80U) != 0) {
            DAT_01a14c10 = DAT_01a14c10 + 1;
          }
          DAT_01a14bd8 = DAT_01a14c10;
          uVar10 = local_108c * DAT_007a0a80 + DAT_007a0a80 * 0x60;
          DAT_01a14bd0 = uVar10 & 0x80;
          DAT_01a14c10 = (int)uVar10 >> 8;
          if (DAT_01a14bd0 != 0) {
            DAT_01a14c10 = DAT_01a14c10 + 1;
          }
          DAT_01a14bd4 = DAT_01a14c10 + *(int *)(&DAT_01576570 + local_105c * 4);
          local_1084 = 0;
          do {
            s_Test_text_string__007a1520[local_1084] = (&DAT_015e9c34)[local_1090];
            pcVar1 = s_Test_text_string__007a1520 + local_1084;
            local_1084 = local_1084 + 1;
            local_1090 = local_1090 + 1;
          } while (*pcVar1 != '\0');
          lstrlenA(s_Test_text_string__007a1520);
          FUN_005ed37c();
          (**(code **)(*(int *)param_1 + 100))();
          FUN_005ed37c();
        }
        CDC::SelectObject(param_1,pvVar9);
      }
      DeleteObject(DAT_01a14bdc);
      FUN_005ed37c();
    }
    if (DAT_009c6c34 != 0) {
      uStackY_64 = 0x5e64c4;
      CreateFontA(DAT_00d97cf0,DAT_00d97cf4,DAT_00d97cf8,DAT_00d97cfc,DAT_00d97d00,
                  (uint)DAT_00d97d04,(uint)DAT_00d97d05,0,(uint)DAT_00d97d07,(uint)DAT_00d97d08,
                  (uint)DAT_00d97d09,(uint)DAT_00d97d0a,(uint)DAT_00d97d0b,&DAT_00d97d0c);
      DAT_01a14bdc = (HGDIOBJ)FUN_005ed37c();
      pvVar9 = CDC::SelectObject(param_1,DAT_01a14bdc);
      if (pvVar9 != (void *)0x0) {
        FUN_005ed790();
        lstrlenA(&DAT_00d97d34);
        FUN_005ed37c();
        (**(code **)(*(int *)param_1 + 100))();
        FUN_005ed37c();
        CDC::SelectObject(param_1,pvVar9);
      }
      DeleteObject(DAT_01a14bdc);
      FUN_005ed37c();
    }
  }
  else {
    if (DAT_00d97ecc == 0) {
      for (local_105c = 0; local_105c < DAT_01576454; local_105c = local_105c + 1) {
        if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x1000000) {
          CDC::SelectObject(param_1,DAT_01a14c04);
          CDC::Polyline(param_1,(tagPOINT *)(&DAT_00db6890 + (&DAT_01557a90)[local_105c] * 8),
                        (&DAT_00d97ed0)[local_105c]);
        }
        else if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x2000000) {
          CDC::SelectObject(param_1,DAT_01a14c00);
          DAT_01a14c10 = (&DAT_01557a90)[local_105c];
          DAT_01a14c0c = (tagPOINT *)(&DAT_00db6890 + DAT_01a14c10 * 8);
          DAT_01a14c08 = (ulong *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4);
          CDC::PolyPolyline(param_1,DAT_01a14c0c,DAT_01a14c08,(&DAT_00dac550)[local_105c]);
        }
        CDC::SelectObject(param_1,DAT_01a14bf8);
        DeleteObject(DAT_01a14c00);
        FUN_005ed37c();
        DeleteObject(DAT_01a14c04);
        FUN_005ed37c();
      }
    }
    else {
      CreatePen(0,1,DAT_00d97ebc);
      DAT_01a14c04 = (void *)FUN_005ed37c();
      CreatePen(0,1,DAT_00d97ec4);
      DAT_01a14c00 = (HGDIOBJ)FUN_005ed37c();
      for (local_105c = 0; local_105c < DAT_01576450; local_105c = local_105c + 1) {
        if (((&DAT_01561dd0)[local_105c] & 0xff000000) == 0x1000000) {
          CDC::Polyline(param_1,(tagPOINT *)(&DAT_00db6890 + (&DAT_01557a90)[local_105c] * 8),
                        *(int *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4));
        }
        else {
          (**(code **)(*(int *)param_1 + 0x2c))();
          FUN_005ed37c();
          DAT_01a14c10 = (&DAT_01557a90)[local_105c];
          DAT_01a14c0c = (tagPOINT *)(&DAT_00db6890 + DAT_01a14c10 * 8);
          CDC::PolyPolygon(param_1,DAT_01a14c0c,
                           (int *)(&DAT_00da2210 + (&DAT_0156c110)[local_105c] * 4),
                           (&DAT_00dac550)[local_105c]);
        }
      }
    }
    _DAT_01a14bf4 = 400;
    _DAT_01a14bf0 = 0;
    _DAT_01a14bec = 0;
    DAT_01a14be8 = 3;
    CDC::SetMapperFlags(param_1,0);
    SetTextColor(*(HDC *)(param_1 + 4),DAT_00d97ec0);
    FUN_005ed37c();
    _DAT_01a14be0 = (float)DAT_007a0a80;
    for (local_105c = 0; local_105c < DAT_016fb378; local_105c = local_105c + 1) {
      DAT_01a14be4 = __ftol();
      local_1060 = 0;
      do {
        s_Anastasia_007a1500[local_1060] = (&DAT_015e9c34)[local_1060 + (&DAT_017031fc)[local_105c]]
        ;
        pcVar1 = s_Anastasia_007a1500 + local_1060;
        local_1060 = local_1060 + 1;
      } while (*pcVar1 != '\0');
      local_109c = (void *)(&DAT_016f34f8)[local_105c];
      uStackY_64 = 0x5e6963;
      pvVar9 = local_109c;
      CreateFontA(-DAT_01a14be4,0,(int)local_109c,(int)local_109c,(&DAT_0166ce88)[local_105c * 0xf],
                  (uint)(byte)(&DAT_0166ce8c)[local_105c * 0x3c],
                  (uint)(byte)(&DAT_0166ce8d)[local_105c * 0x3c],0,DAT_01a14be8,0,0,0,0,
                  s_Anastasia_007a1500);
      DAT_01a14bdc = (HGDIOBJ)FUN_005ed37c();
      if (DAT_01a14c16 == '\0') {
        pvVar9 = CDC::SelectObject(param_1,DAT_01a14bdc);
      }
      if ((DAT_01a14c16 != '\0') || (pvVar9 != (void *)0x0)) {
        DAT_01a14c10 = DAT_00d97ec0;
        if (DAT_00d97ec0 == 0xffffff) {
          DAT_01a14c10 = (&DAT_016e37f8)[local_105c];
        }
        SetTextColor(*(HDC *)(param_1 + 4),DAT_01a14c10);
        FUN_005ed37c();
        local_10ac = (&DAT_016fb37c)[local_105c];
        for (local_10b0 = 0; local_10b0 < (int)(&DAT_016eb678)[local_105c];
            local_10b0 = local_10b0 + 1) {
          local_10a4 = *(int *)(&DAT_015e9c34 + local_10ac);
          local_10b4 = (int *)(&DAT_015e9c38 + local_10ac);
          local_10a8 = *local_10b4;
          local_10ac = local_10ac + 8;
          DAT_01a14c10 = local_10a4 * DAT_007a0a80 >> 8;
          if ((local_10a4 * DAT_007a0a80 & 0x80U) != 0) {
            DAT_01a14c10 = DAT_01a14c10 + 1;
          }
          DAT_01a14bd8 = DAT_01a14c10;
          uVar10 = local_10a8 * DAT_007a0a80 + DAT_007a0a80 * 0x60;
          DAT_01a14bd0 = uVar10 & 0x80;
          DAT_01a14c10 = (int)uVar10 >> 8;
          if (DAT_01a14bd0 != 0) {
            DAT_01a14c10 = DAT_01a14c10 + 1;
          }
          DAT_01a14bd4 = DAT_01a14c10 + *(int *)(&DAT_01576570 + local_105c * 4);
          local_10a0 = 0;
          do {
            s_Test_text_string__007a1520[local_10a0] = (&DAT_015e9c34)[local_10ac];
            pcVar1 = s_Test_text_string__007a1520 + local_10a0;
            local_10a0 = local_10a0 + 1;
            local_10ac = local_10ac + 1;
          } while (*pcVar1 != '\0');
          lstrlenA(s_Test_text_string__007a1520);
          FUN_005ed37c();
          (**(code **)(*(int *)param_1 + 100))();
          FUN_005ed37c();
        }
      }
      DeleteObject(DAT_01a14bdc);
      FUN_005ed37c();
    }
  }
  CWnd::EndPaint(this,(tagPAINTSTRUCT *)&stack0xffffffb4);
  FUN_005ed37c();
  return;
}


// ===== FUN_005e5010 @ 005e5010 =====

void FUN_005e5010(void)

{
  CWinApp *pCVar1;
  CWnd *pCVar2;
  CDC *pCVar3;
  BOOL BVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_134 [16];
  CHAR local_f4 [132];
  void *local_70;
  void *local_6c;
  CDC *local_68;
  int local_64;
  CView *local_60;
  CFrameWnd *local_5c;
  int *local_58;
  CHOOSEFONTA local_48;
  HDC local_c;
  undefined4 local_8;
  
  puVar7 = local_134;
  for (iVar6 = 0x4c; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  _memset(&local_48,0,0x3c);
  local_48.lStructSize = 0x3c;
  pCVar1 = AfxGetApp();
  local_58 = *(int **)(pCVar1 + 0x20);
  (**(code **)(*local_58 + 200))();
  local_5c = (CFrameWnd *)FUN_005ed37c();
  local_60 = CFrameWnd::GetActiveView(local_5c);
  pCVar2 = CWnd::GetActiveWindow();
  pCVar3 = CWnd::GetDC(pCVar2);
  local_48.hDC = *(HDC *)(pCVar3 + 4);
  local_c = local_48.hDC;
  pCVar2 = AfxGetMainWnd();
  local_48.hwndOwner = *(HWND *)(pCVar2 + 0x20);
  local_48.lpLogFont = (LPLOGFONTA)&DAT_019c7f50;
  local_48.rgbColors = DAT_019c7f48;
  local_48.Flags = 0x101;
  BVar4 = ChooseFontA(&local_48);
  if (BVar4 == 1) {
    DAT_00d97cf0 = DAT_019c7f50;
    DAT_00d97cf4 = DAT_019c7f54;
    DAT_00d97cf8 = DAT_019c7f58;
    DAT_00d97cfc = DAT_019c7f5c;
    DAT_00d97d07 = DAT_019c7f67;
    DAT_00d97d08 = DAT_019c7f68;
    DAT_00d97d09 = DAT_019c7f69;
    DAT_00d97d0a = DAT_019c7f6a;
    DAT_00d97d0b = DAT_019c7f6b;
    for (local_64 = 0; local_64 < 0x20; local_64 = local_64 + 1) {
      (&DAT_00d97d0c)[local_64] = (&DAT_019c7f6c)[local_64];
    }
    pCVar2 = CWnd::GetActiveWindow();
    local_68 = CWnd::GetDC(pCVar2);
    CDC::SetBkMode(local_68,1);
    CDC::SetMapperFlags(local_68,0);
    SetTextColor(*(HDC *)(local_68 + 4),DAT_00d97ec8);
    FUN_005ed37c();
    CreateFontA(DAT_019c7f50,DAT_019c7f54,DAT_019c7f58,DAT_019c7f5c,DAT_019c7f60,(uint)DAT_019c7f64,
                (uint)DAT_019c7f65,0,(uint)DAT_019c7f67,(uint)DAT_019c7f68,(uint)DAT_019c7f69,
                (uint)DAT_019c7f6a,(uint)DAT_019c7f6b,&DAT_019c7f6c);
    local_6c = (void *)FUN_005ed37c();
    local_70 = CDC::SelectObject(local_68,local_6c);
    if (local_70 != (void *)0x0) {
      FUN_005ed790(local_f4,"Font Test");
      lstrlenA(local_f4);
      uVar5 = FUN_005ed37c();
      (**(code **)(*(int *)local_68 + 100))(200,200,local_f4,uVar5);
      FUN_005ed37c();
      CDC::SelectObject(local_68,local_70);
    }
    DeleteObject(local_6c);
    FUN_005ed37c();
  }
  else {
    AfxMessageBox("error",0,0);
  }
  local_8 = 0x5e52b3;
  FUN_005ed37c();
  return;
}


// ===== FUN_005a42e0 @ 005a42e0 =====

void FUN_005a42e0(CDC *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d4 [17];
  tagTEXTMETRICA local_90 [4];
  undefined4 local_8c;
  int local_58;
  void *local_54;
  void *local_50;
  CHAR local_4c [32];
  int local_2c;
  int local_28;
  DWORD local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  local_18 = 400;
  local_1c = 0;
  local_20 = 0;
  local_24 = 3;
  CDC::SetMapperFlags(param_1,0);
  local_14 = (float)DAT_007a0a80;
  for (local_c = 0; local_c < DAT_016fb378; local_c = local_c + 1) {
    local_28 = __ftol();
    local_10 = 0;
    do {
      local_4c[local_10] = (&DAT_015e9c34)[local_10 + (&DAT_017031fc)[local_c]];
      pcVar1 = local_4c + local_10;
      local_10 = local_10 + 1;
    } while (*pcVar1 != '\0');
    local_58 = (&DAT_016f34f8)[local_c];
    local_28 = __ftol();
    local_2c = __ftol();
    CreateFontA(-local_28,local_2c,local_58,local_58,(&DAT_0166ce88)[local_c * 0xf],
                (uint)(byte)(&DAT_0166ce8c)[local_c * 0x3c],
                (uint)(byte)(&DAT_0166ce8d)[local_c * 0x3c],0,local_24,3,2,1,0x50,local_4c);
    local_50 = (void *)FUN_005ed37c();
    local_54 = CDC::SelectObject(param_1,local_50);
    if (local_54 != (void *)0x0) {
      iVar2 = CDC::GetTextMetricsA(param_1,local_90);
      if (iVar2 == 0) {
        if (local_8 == 0) {
          AfxMessageBox("Text metrics error!",0,0);
        }
        local_8 = 1;
      }
      *(undefined4 *)(&DAT_01576570 + local_c * 4) = local_8c;
    }
    CDC::SelectObject(param_1,local_54);
    DeleteObject(local_50);
    FUN_005ed37c();
  }
  local_8 = 0x5a44e0;
  FUN_005ed37c();
  return;
}


