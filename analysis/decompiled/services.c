// ===== FUN_00597d30 @ 00597d30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597d30(char *param_1,ulong *param_2)

{
  tagSIZE tVar1;
  tagPOINT tVar2;
  tagPOINT tVar3;
  CView *pCVar4;
  CDC *pCVar5;
  BOOL BVar6;
  ulong uVar7;
  tagSIZE *ptVar8;
  tagSIZE *ptVar9;
  tagSIZE *ptVar10;
  int *piVar11;
  tagRECT *ptVar12;
  undefined4 *puVar13;
  LONG *pLVar14;
  CWinApp *pCVar15;
  CWnd *pCVar16;
  CFrameWnd *pCVar17;
  int iVar18;
  uint uVar19;
  undefined1 *puVar20;
  LONG LVar21;
  char *pcVar22;
  HICON__ *dwNewLong;
  undefined4 uVar23;
  CHAR *pCVar24;
  undefined4 local_60c [16];
  CFrameWnd *pCStack_5cc;
  CDocument *pCStack_5c8;
  CFrameWnd *pCStack_5c4;
  CFrameWnd *pCStack_5c0;
  CFrameWnd *pCStack_5bc;
  CDocument *pCStack_5b8;
  CFrameWnd *pCStack_5b4;
  CDocument *pCStack_5b0;
  CFrameWnd *pCStack_5ac;
  undefined4 uStack_5a8;
  CFrameWnd *pCStack_5a4;
  CDocument *pCStack_5a0;
  CFrameWnd *pCStack_59c;
  CDocument *pCStack_598;
  CFrameWnd *pCStack_594;
  CDocument *pCStack_590;
  CFrameWnd *pCStack_58c;
  CFrameWnd *pCStack_588;
  int iStack_584;
  CFrameWnd *pCStack_580;
  int local_57c;
  int iStack_578;
  undefined4 uStack_574;
  LONG LStack_570;
  LONG LStack_56c;
  undefined1 auStack_568 [8];
  LONG LStack_560;
  undefined4 uStack_55c;
  undefined1 auStack_558 [8];
  CSize aCStack_550 [8];
  LONG LStack_548;
  LONG LStack_544;
  CSize aCStack_540 [8];
  CSize aCStack_538 [8];
  undefined1 auStack_530 [8];
  int iStack_528;
  int iStack_524;
  LONG LStack_520;
  LONG LStack_51c;
  undefined4 uStack_518;
  undefined4 uStack_514;
  undefined1 auStack_510 [8];
  undefined1 auStack_508 [8];
  CSize aCStack_500 [8];
  LONG LStack_4f8;
  LONG LStack_4f4;
  CSize aCStack_4f0 [8];
  CSize aCStack_4e8 [8];
  undefined1 auStack_4e0 [8];
  tagPOINT tStack_4d8;
  CDC *pCStack_4d0;
  CView *pCStack_4cc;
  tagRECT *ptStack_4c8;
  tagRECT tStack_4c4;
  CView *pCStack_4b4;
  CView *pCStack_408;
  int iStack_404;
  int iStack_400;
  CDC *pCStack_3fc;
  CView *pCStack_3f8;
  CFrameWnd *pCStack_3f4;
  int *piStack_3f0;
  int iStack_3ec;
  int iStack_3e8;
  int iStack_3e4;
  int iStack_3e0;
  CView *pCStack_3dc;
  CColorDialog aCStack_3d8 [132];
  ulong uStack_354;
  CView *pCStack_350;
  CView *pCStack_34c;
  undefined4 uStack_348;
  CView *pCStack_344;
  LONG LStack_340;
  undefined4 uStack_33c;
  CRect aCStack_338 [16];
  float fStack_328;
  int iStack_324;
  CView *pCStack_320;
  CFrameWnd *pCStack_31c;
  int *piStack_318;
  int iStack_314;
  int iStack_310;
  CDC *pCStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  tagPOINT tStack_300;
  CHAR aCStack_2f8 [32];
  size_t sStack_2d8;
  int iStack_2d4;
  int iStack_2d0;
  int iStack_2cc;
  ulong uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  CView *pCStack_2b4;
  CFrameWnd *pCStack_2b0;
  int *piStack_2ac;
  CView *pCStack_2a8;
  CView *pCStack_2a4;
  int iStack_2a0;
  CView *pCStack_29c;
  CFrameWnd *pCStack_298;
  int *piStack_294;
  CHOOSEFONTA CStack_290;
  HDC pHStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  CView *pCStack_248;
  char *pcStack_244;
  HICON__ *pHStack_240;
  ulong uStack_23c;
  ulong uStack_238;
  ulong uStack_234;
  CDC *pCStack_230;
  CWnd *pCStack_22c;
  CFrameWnd *pCStack_228;
  int *piStack_224;
  tagPOINT atStack_220 [64];
  CView *pCStack_1c;
  ulong local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar13 = local_60c;
  for (iVar18 = 0x182; iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar13 = 0xcccccccc;
    puVar13 = puVar13 + 1;
  }
  local_8 = (int)*param_1;
  local_c = (int)param_1[1];
  local_10 = (int)param_1[2];
  local_14 = (int)param_1[3];
  local_18 = *param_2;
  local_57c = local_c + -0x61;
  switch(local_57c) {
  case 0:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_580 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_580 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_1c = CFrameWnd::GetActiveView(pCVar17);
    pCVar16 = AfxGetMainWnd();
    func_0x0062acd2(0,0,0,0,0,pCVar16);
    func_0x0062accc();
    FUN_005ed790(&DAT_009ae2bc,param_1);
    thunk_FUN_0053ec10();
    *param_1 = '\0';
    func_0x00402270();
    break;
  case 1:
    pCVar15 = AfxGetApp();
    piStack_224 = *(int **)(pCVar15 + 0x20);
    (**(code **)(*piStack_224 + 200))();
    pCStack_228 = (CFrameWnd *)FUN_005ed37c();
    pCStack_22c = (CWnd *)CFrameWnd::GetActiveView(pCStack_228);
    puVar20 = auStack_4e0;
    piVar11 = (int *)CScrollView::GetDeviceScrollPosition((CScrollView *)pCStack_22c);
    atStack_220[0].x = *piVar11;
    atStack_220[0].y = piVar11[1];
    pCStack_230 = CWnd::GetDC(pCStack_22c);
    (**(code **)(*(int *)pCStack_230 + 0x3c))(5,puVar20);
    FUN_005ed37c();
    CDC::DPtoLP(pCStack_230,atStack_220,1);
    uStack_238 = (atStack_220[0].x << 8) / (int)DAT_007a0a80;
    uStack_23c = (atStack_220[0].y << 8) / (int)DAT_007a0a80;
    *param_2 = uStack_238;
    param_2[1] = uStack_23c;
    uStack_234 = uStack_23c;
    break;
  case 2:
    if ((int)local_18 < 0x10) {
      iStack_584 = local_18 - 1;
      switch(iStack_584) {
      case 0:
        pcStack_244 = (char *)0x7f01;
        break;
      case 1:
        pcStack_244 = (char *)0x7f02;
        break;
      case 2:
        pcStack_244 = (char *)0x7f03;
        break;
      case 3:
        pcStack_244 = (char *)0x7f04;
        break;
      case 4:
        pcStack_244 = (char *)0x7f86;
        break;
      case 5:
        pcStack_244 = (char *)0x7f82;
        break;
      case 6:
        pcStack_244 = (char *)0x7f83;
        break;
      case 7:
        pcStack_244 = (char *)0x7f84;
        break;
      case 8:
        pcStack_244 = (char *)0x7f85;
        break;
      default:
        pcStack_244 = (char *)0x7f00;
      }
      pcVar22 = pcStack_244;
      pCVar15 = AfxGetApp();
      pHStack_240 = CWinApp::LoadStandardCursor(pCVar15,pcVar22);
    }
    else {
      uVar23 = 0x130;
      AfxGetApp();
      pHStack_240 = (HICON__ *)func_0x0062acae(uVar23);
    }
    AfxGetMainWnd();
    iVar18 = -0xc;
    dwNewLong = pHStack_240;
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_588 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_588 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCVar4 = CFrameWnd::GetActiveView(pCVar17);
    SetClassLongA(*(HWND *)(pCVar4 + 0x20),iVar18,(LONG)dwNewLong);
    FUN_005ed37c();
    *param_1 = '\0';
    break;
  case 3:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_58c = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_58c + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_248 = CFrameWnd::GetActiveView(pCVar17);
    pCStack_590 = CView::GetDocument(pCStack_248);
    (**(code **)(*(int *)pCStack_590 + 0x98))();
    uVar7 = FUN_005ed37c();
    *param_2 = uVar7;
    *param_1 = '\0';
    break;
  case 4:
    pCVar15 = AfxGetApp();
    uStack_24c = *(undefined4 *)(pCVar15 + 0x20);
    func_0x00403ad5();
    break;
  case 5:
    uStack_250 = 0;
    _memset(&CStack_290,0,0x3c);
    CStack_290.lStructSize = 0x3c;
    pCVar15 = AfxGetApp();
    piStack_294 = *(int **)(pCVar15 + 0x20);
    (**(code **)(*piStack_294 + 200))();
    pCStack_298 = (CFrameWnd *)FUN_005ed37c();
    pCStack_29c = CFrameWnd::GetActiveView(pCStack_298);
    pCVar16 = CWnd::GetActiveWindow();
    pCVar5 = CWnd::GetDC(pCVar16);
    CStack_290.hDC = *(HDC *)(pCVar5 + 4);
    pHStack_254 = CStack_290.hDC;
    pCVar16 = AfxGetMainWnd();
    CStack_290.hwndOwner = *(HWND *)(pCVar16 + 0x20);
    CStack_290.lpLogFont = (LPLOGFONTA)&uRam009c48b8;
    CStack_290.rgbColors = CRam009c48b4;
    CStack_290.Flags = 0x101;
    BVar6 = ChooseFontA(&CStack_290);
    if (BVar6 == 1) {
      DAT_00d97cf0 = uRam009c48b8;
      DAT_009c4f9c = uRam009c48b8;
      DAT_00d97cf4 = uRam009c48bc;
      DAT_009c4fa0 = uRam009c48bc;
      DAT_00d97cf8 = uRam009c48c0;
      DAT_009c4fa4 = uRam009c48c0;
      DAT_00d97cfc = uRam009c48c4;
      DAT_009c4fa8 = uRam009c48c4;
      DAT_00d97d07 = bRam009c48cf;
      DAT_009c4fac = (uint)bRam009c48cf;
      DAT_00d97d04 = bRam009c48cc;
      DAT_009c4fb0 = (uint)bRam009c48cc;
      DAT_00d97d00 = uRam009c48c8;
      DAT_00d97d05 = uRam009c48cd;
      DAT_00d97d08 = uRam009c48d0;
      DAT_00d97d09 = uRam009c48d1;
      DAT_00d97d0a = uRam009c48d2;
      DAT_00d97d0b = uRam009c48d3;
      for (iStack_2a0 = 0; iStack_2a0 < 0x20; iStack_2a0 = iStack_2a0 + 1) {
        (&DAT_00d97d0c)[iStack_2a0] = *(undefined1 *)(iStack_2a0 + 0x9c48d4);
        (&DAT_007a0b7c)[iStack_2a0] = (&DAT_00d97d0c)[iStack_2a0];
      }
      *param_2 = (ulong)&DAT_00d97cf0;
      *param_1 = '\0';
    }
    else {
      AfxMessageBox("error",0,0);
    }
    break;
  default:
    *param_1 = *param_1;
    break;
  case 7:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_594 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_594 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_2a4 = CFrameWnd::GetActiveView(pCVar17);
    uVar23 = 1;
    pCStack_598 = CView::GetDocument(pCStack_2a4);
    (**(code **)(*(int *)pCStack_598 + 0x5c))(param_2,uVar23);
    FUN_005ed37c();
    *param_1 = '\0';
    break;
  case 8:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_59c = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_59c + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_2a8 = CFrameWnd::GetActiveView(pCVar17);
    pCStack_5a0 = CView::GetDocument(pCStack_2a8);
    (**(code **)(*(int *)pCStack_5a0 + 0x60))();
    uVar7 = FUN_005ed37c();
    *param_2 = uVar7;
    *param_1 = '\0';
    break;
  case 9:
    DAT_009c4a84 = 3;
    break;
  case 10:
    pCVar15 = AfxGetApp();
    piStack_2ac = *(int **)(pCVar15 + 0x20);
    (**(code **)(*piStack_2ac + 200))();
    pCStack_2b0 = (CFrameWnd *)FUN_005ed37c();
    pCStack_2b4 = CFrameWnd::GetActiveView(pCStack_2b0);
    CPoint::CPoint((CPoint *)&uStack_2bc);
    uStack_2bc = 100;
    uStack_2b8 = 100;
    uStack_2c4 = 100;
    uStack_2c0 = 100;
    DAT_009c6c2c = 0;
    DAT_009c6c2d = 0;
    DAT_009c6c28 = 0;
    DAT_009c6c60 = 100;
    DAT_009c6c64 = 100;
    uStack_2c8 = DAT_007a0a80;
    if ((param_2[1] == 0) && (DAT_007a0a80 != 0x40)) {
      DAT_007a0a80 = 0x40;
    }
    else {
      DAT_007a0a80 = param_2[1];
      if (DAT_007a0a80 == 0) {
        DAT_007a0a80 = 0x80;
      }
    }
    DAT_01a14950 = 0x6400 / (int)DAT_007a0a80;
    DAT_01a1494c = 0x6400 / (int)DAT_007a0a80;
    sStack_2d8 = (int)(DAT_007a0a80 * 100) >> 6;
    iStack_2d4 = DAT_01a1494c;
    iStack_2d0 = DAT_01a1494c;
    iStack_2cc = DAT_01a14950;
    wsprintfA(aCStack_2f8,"%d",sStack_2d8);
    FUN_005ed37c();
    sStack_2d8 = _strlen(aCStack_2f8);
    aCStack_2f8[sStack_2d8] = '%';
    aCStack_2f8[sStack_2d8 + 1] = ' ';
    aCStack_2f8[sStack_2d8 + 2] = ' ';
    aCStack_2f8[sStack_2d8 + 3] = ' ';
    aCStack_2f8[sStack_2d8 + 4] = ' ';
    aCStack_2f8[sStack_2d8 + 5] = '0';
    pCVar24 = aCStack_2f8;
    pCVar16 = CWnd::GetDlgItem(DAT_00d97cdc,0x410);
    CWnd::SetWindowTextA(pCVar16,pCVar24);
    DAT_019c7b90 = 1;
    CPoint::CPoint((CPoint *)&tStack_300);
    CPoint::CPoint((CPoint *)&uStack_308);
    uStack_308 = uStack_2bc;
    uStack_304 = uStack_2b8;
    ptVar8 = (tagSIZE *)CSize::CSize(aCStack_4e8,DAT_009c6e98,DAT_009c6e9c);
    ptVar9 = (tagSIZE *)CSize::CSize(aCStack_4f0,DAT_009c6e90,DAT_009c6e94);
    ptVar10 = (tagSIZE *)CSize::CSize(aCStack_500,DAT_009c6e88,DAT_009c6e8c);
    LStack_4f8 = ptVar10->cx;
    LStack_4f4 = ptVar10->cy;
    CScrollView::SetScrollSizes((CScrollView *)pCStack_2b4,5,*ptVar10,ptVar9,ptVar8);
    pCStack_30c = CWnd::GetDC((CWnd *)pCStack_2b4);
    (**(code **)(*(int *)pCStack_30c + 0x3c))(5);
    FUN_005ed37c();
    puVar20 = auStack_508;
    piVar11 = (int *)CScrollView::GetDeviceScrollPosition((CScrollView *)pCStack_2b4);
    tStack_300.x = *piVar11;
    tStack_300.y = piVar11[1];
    iStack_310 = -tStack_300.x;
    iStack_314 = -tStack_300.y;
    (**(code **)(*(int *)pCStack_30c + 0x40))(auStack_510,iStack_310,iStack_314,puVar20);
    FUN_005ed37c();
    iStack_528 = tStack_300.x;
    iStack_524 = tStack_300.y;
    tVar3.y = tStack_300.x;
    tVar3.x = (LONG)auStack_530;
    LVar21 = tStack_300.y;
    ptVar8 = (tagSIZE *)CPoint::operator-((CPoint *)&uStack_308,tVar3);
    LStack_520 = ptVar8->cx;
    LStack_51c = ptVar8->cy;
    CPoint::CPoint((CPoint *)&uStack_518,*ptVar8);
    DAT_009c6c60 = uStack_518;
    DAT_009c6c64 = uStack_514;
    pCVar15 = AfxGetApp();
    piStack_318 = *(int **)(pCVar15 + 0x20);
    (**(code **)(*piStack_318 + 200))(LVar21);
    pCStack_31c = (CFrameWnd *)FUN_005ed37c();
    pCStack_320 = CFrameWnd::GetActiveView(pCStack_31c);
    fStack_328 = (float)(int)DAT_007a0a80 / (float)(int)uStack_2c8;
    for (iStack_324 = 0; iStack_324 < 6; iStack_324 = iStack_324 + 1) {
      iVar18 = __ftol();
      (&DAT_009c6e88)[iStack_324] = iVar18;
    }
    if (pCStack_320 != (CView *)0x0) {
      ptVar8 = (tagSIZE *)CSize::CSize(aCStack_538,DAT_009c6e98,DAT_009c6e9c);
      ptVar9 = (tagSIZE *)CSize::CSize(aCStack_540,DAT_009c6e90,DAT_009c6e94);
      ptVar10 = (tagSIZE *)CSize::CSize(aCStack_550,DAT_009c6e88,DAT_009c6e8c);
      LStack_548 = ptVar10->cx;
      LStack_544 = ptVar10->cy;
      CScrollView::SetScrollSizes((CScrollView *)pCStack_320,5,*ptVar10,ptVar9,ptVar8);
    }
    CRect::CRect(aCStack_338);
    ptVar12 = CRect::operator_struct_tagRECT_(aCStack_338);
    CWnd::GetClientRect((CWnd *)pCStack_320,ptVar12);
    CSize::CSize((CSize *)&LStack_340);
    puVar20 = auStack_558;
    puVar13 = (undefined4 *)CRect::Size(aCStack_338);
    LStack_340 = *puVar13;
    uStack_33c = puVar13[1];
    LStack_340 = __ftol(puVar20);
    uStack_33c = __ftol();
    DAT_009c6c60 = __ftol();
    DAT_009c6c64 = __ftol();
    LStack_560 = LStack_340;
    uStack_55c = uStack_33c;
    tVar1.cy = LStack_340;
    tVar1.cx = (LONG)auStack_568;
    uVar23 = uStack_33c;
    pLVar14 = (LONG *)CPoint::operator-((CPoint *)&DAT_009c6c60,tVar1);
    tStack_300.x = *pLVar14;
    tStack_300.y = pLVar14[1];
    CDC::DPtoLP(pCStack_30c,&tStack_300,1);
    LStack_570 = tStack_300.x;
    LStack_56c = tStack_300.y;
    tVar2.y = tStack_300.y;
    tVar2.x = tStack_300.x;
    CScrollView::ScrollToPosition((CScrollView *)pCStack_320,tVar2);
    (**(code **)(*piStack_318 + 200))(uVar23);
    iVar18 = FUN_005ed37c();
    thunk_FUN_005a4900(*(undefined4 *)(iVar18 + 0x20));
    pCVar16 = CWnd::GetDlgItem(DAT_00d97ce4,0x3e9);
    CWnd::SetFocus(pCVar16);
    *param_1 = '\0';
    break;
  case 0xb:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5a4 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5a4 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_344 = CFrameWnd::GetActiveView(pCVar17);
    iStack_578 = func_0x0062ac5a(0x188);
    if (iStack_578 == 0) {
      uStack_5a8 = 0;
    }
    else {
      uStack_5a8 = func_0x0062ac54();
    }
    uStack_574 = uStack_5a8;
    uStack_348 = uStack_5a8;
    iVar18 = func_0x0062ac4e(*param_2,param_2 + 2,&DAT_0076cfa0,param_2[1],0);
    if (iVar18 != 0) {
      *param_2 = 0;
    }
    *param_1 = '\0';
    break;
  case 0xc:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5ac = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5ac + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_34c = CFrameWnd::GetActiveView(pCVar17);
    uVar19 = (uint)(*param_2 != 0);
    pCStack_5b0 = CView::GetDocument(pCStack_34c);
    (**(code **)(*(int *)pCStack_5b0 + 100))(uVar19);
    FUN_005ed37c();
    *param_1 = '\0';
    break;
  case 0xd:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5b4 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5b4 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_350 = CFrameWnd::GetActiveView(pCVar17);
    pCStack_5b8 = CView::GetDocument(pCStack_350);
    (**(code **)(*(int *)pCStack_5b8 + 0x58))(param_2);
    FUN_005ed37c();
    *param_1 = '\0';
    break;
  case 0xe:
    uStack_354 = local_18;
    CColorDialog::CColorDialog(aCStack_3d8,local_18,0,(CWnd *)0x0);
    *param_2 = 0xffffffff;
    iVar18 = CColorDialog::DoModal(aCStack_3d8);
    if (iVar18 == 1) {
      uStack_354 = CColorDialog::GetColor(aCStack_3d8);
      *param_2 = uStack_354;
    }
    *param_1 = '\0';
    thunk_FUN_005997d0();
    break;
  case 0xf:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5bc = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5bc + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_3dc = CFrameWnd::GetActiveView(pCVar17);
    if (pCStack_3dc != (CView *)0x0) {
      iStack_3ec = (int)(*param_2 * DAT_007a0a80) >> 8;
      iStack_3e8 = (int)(param_2[1] * DAT_007a0a80) >> 8;
      iStack_3e4 = iStack_3e8;
      iStack_3e0 = iStack_3ec;
      pCVar15 = AfxGetApp();
      piStack_3f0 = *(int **)(pCVar15 + 0x20);
      (**(code **)(*piStack_3f0 + 200))();
      pCStack_3f4 = (CFrameWnd *)FUN_005ed37c();
      pCStack_3f8 = CFrameWnd::GetActiveView(pCStack_3f4);
      pCStack_3fc = CWnd::GetDC((CWnd *)pCStack_3f8);
      (**(code **)(*(int *)pCStack_3fc + 0x3c))(5);
      FUN_005ed37c();
      func_0x0062ac36(&iStack_3ec,1);
      CWnd::SetScrollPos((CWnd *)pCStack_3dc,0,iStack_3ec,1);
      CWnd::SetScrollPos((CWnd *)pCStack_3dc,1,iStack_3e8,1);
    }
    *param_1 = '\0';
    break;
  case 0x10:
    iStack_400 = _DAT_019c7b98;
    iStack_404 = _DAT_019c7b98;
    while (iStack_404 == _DAT_019c7b98) {
      AfxMessageBox("the test",0,0);
    }
    break;
  case 0x11:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5c0 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5c0 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_408 = CFrameWnd::GetActiveView(pCVar17);
    pCVar16 = AfxGetMainWnd();
    func_0x0062ac2a(*param_2,param_2[1],pCVar16);
    iVar18 = func_0x0062ac24();
    if (iVar18 == 1) {
      *param_2 = 0;
    }
    *param_1 = '\0';
    func_0x004024d2();
    break;
  case 0x12:
    func_0x0040127b(param_2);
    *param_1 = '\0';
    break;
  case 0x15:
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5c4 = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5c4 + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_4b4 = CFrameWnd::GetActiveView(pCVar17);
    pCStack_5c8 = CView::GetDocument(pCStack_4b4);
    (**(code **)(*(int *)pCStack_5c8 + 0x80))(param_2);
    FUN_005ed37c();
    *param_1 = '\0';
    break;
  case 0x19:
    ptStack_4c8 = &tStack_4c4;
    AfxGetMainWnd();
    pCVar16 = CWnd::GetActiveWindow();
    pCStack_5cc = CWnd::GetTopLevelFrame(pCVar16);
    (**(code **)(*(int *)pCStack_5cc + 200))();
    pCVar17 = (CFrameWnd *)FUN_005ed37c();
    pCStack_4cc = CFrameWnd::GetActiveView(pCVar17);
    pCStack_4d0 = CWnd::GetDC((CWnd *)pCStack_4cc);
    (**(code **)(*(int *)pCStack_4d0 + 0x3c))(5);
    FUN_005ed37c();
    CWnd::GetClientRect((CWnd *)pCStack_4cc,ptStack_4c8);
    CPoint::CPoint((CPoint *)&tStack_4d8);
    tStack_4d8.x = tStack_4c4.right;
    tStack_4d8.y = -tStack_4c4.bottom;
    CDC::DPtoLP(pCStack_4d0,&tStack_4d8,1);
    *param_2 = (tStack_4d8.x << 8) / (int)DAT_007a0a80;
    local_c = tStack_4d8.y << 8;
    param_2[1] = local_c / (int)DAT_007a0a80;
  }
  local_8 = 0x59916e;
  FUN_005ed37c();
  return;
}


// ===== FUN_005509e4 @ 005509e4 =====
