// FUN_0056daa0 @ 0056daa0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056daa0(void)

{
  char *pcVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined2 in_FPUControlWord;
  
  puVar6 = &stack0xfffffffc;
  if (DAT_01cadcfc == 0) {
    puVar6 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x56dad2);
  }
  iVar3 = **(int **)(puVar6 + 8);
  if (iVar3 == 1) goto LAB_0056dd8a;
  if (iVar3 == 2) {
    if ((DAT_01cadce4 < 0x84) || (0x8c < DAT_01cadce4)) {
      *(undefined4 *)(puVar6 + -0x90) = 0;
      if ((DAT_01cadce4 != 0x91) && (DAT_01cadce4 != 0x93)) {
        *(undefined4 *)(puVar6 + -0x84) = 0;
        goto LAB_0056dced;
      }
      DAT_01cadce4 = (DAT_01cadce4 + -0x91) / 2 + 0x54;
      *(undefined4 *)(puVar6 + -0x80) = 0;
    }
    else {
      if ((DAT_01cadce4 == 0x88) || (DAT_01cadce4 == 0x89)) {
        *(undefined4 *)(puVar6 + -0x8c) = 0;
LAB_0056dced:
        DAT_01a2770c = *(int *)(&DAT_0079fd7c + DAT_01cadce4 * 4) / 100 + 0x30;
        DAT_01a27718 = *(int *)(&DAT_0079fd7c + DAT_01cadce4 * 4) % 100;
        *(undefined4 *)(puVar6 + -0x7c) = 0;
        goto LAB_0056dd36;
      }
      DAT_01cadce4 = DAT_01cadce4 + -0x34;
      *(undefined4 *)(puVar6 + -0x88) = 0;
    }
LAB_0056dd8a:
    thunk_FUN_0056ae1c();
    if (((DAT_01cadce4 == 800) || (DAT_01cadce4 == 0x26)) || (DAT_01cadce4 == 0x27)) {
      if (DAT_0078b6a0 == 99) {
        *(undefined4 *)(puVar6 + -0xa0) = 0;
      }
      else {
        (&DAT_01caf69f)[DAT_01cadcfc] = (char)DAT_0079fef4;
        if (DAT_01cadce4 == 800) {
          *(undefined4 *)(puVar6 + -0x9c) = 0;
          goto LAB_0056de2b;
        }
        DAT_01cadcfc = DAT_01cadcfc + 1;
      }
    }
    else {
      *(undefined4 *)(puVar6 + -0xa4) = 0;
    }
    iVar3 = DAT_01cadcfc;
    uVar2 = FUN_0056f324(&DAT_01cadce4);
    (&DAT_01caf69f)[iVar3] = uVar2;
LAB_0056de2b:
    if (DAT_01cadce0 < DAT_01cb1068) {
      *(undefined4 *)(puVar6 + -0xc4) = 1;
      *(undefined4 *)(puVar6 + -0x94) = 0;
      goto LAB_0056eabb;
    }
    *(undefined4 *)(puVar6 + -0x98) = 0;
  }
  else if (iVar3 == 3) {
    if (DAT_01a27710 != 0) {
      FUN_0056ebb4();
LAB_0056dd36:
      DAT_009a81ec = P14;
      FUN_0056eaca();
      P14 = DAT_009a81ec;
      *(undefined4 *)(puVar6 + -0xb8) = 0;
      goto LAB_0056de2b;
    }
    *(undefined4 *)(puVar6 + -0xbc) = 0;
    if ((DAT_01cadce4 < 0x50) || (0x5c < DAT_01cadce4)) {
      if ((DAT_01cadce4 < 0xa2) || (DAT_01cadce4 == 800)) {
        if (-1 < DAT_01cadce4) {
          *(undefined4 *)(puVar6 + -0xac) = 0;
          goto LAB_0056dd8a;
        }
        thunk_FUN_0056ae1c();
        (&DAT_01caf69f)[DAT_01cadcfc] = 0x5c;
        pcVar1 = (char *)((int)&DAT_01caf6a0 + DAT_01cadcfc);
        DAT_01cadcfc = DAT_01cadcfc + 1;
        *pcVar1 = '0' - (char)(DAT_01cadce4 / 100);
        pcVar1 = (char *)((int)&DAT_01caf6a0 + DAT_01cadcfc);
        DAT_01cadcfc = DAT_01cadcfc + 1;
        *pcVar1 = '0' - (char)((DAT_01cadce4 % 100) / 10);
        pcVar1 = (char *)((int)&DAT_01caf6a0 + DAT_01cadcfc);
        DAT_01cadcfc = DAT_01cadcfc + 1;
        *pcVar1 = '0' - (char)(DAT_01cadce4 % 10);
        *(undefined4 *)(puVar6 + -0xa8) = 0;
        goto LAB_0056de2b;
      }
      *(undefined4 *)(puVar6 + -0xb0) = 0;
    }
    else {
      *(undefined4 *)(puVar6 + -0xb4) = 0;
    }
    DAT_01a1c848 = 1;
  }
  else {
    DAT_01a1c848 = -1;
    *(undefined4 *)(puVar6 + -0xc0) = 0;
  }
  if (DAT_01cadcfc == 0) {
    *(undefined4 *)(puVar6 + -0x78) = 0;
LAB_0056ea41:
    DAT_01cadcfc = 0;
    _DAT_01cadcf8 = 0;
    if (DAT_01a1c848 == 0) {
      DAT_01cadce0 = 999;
      *(undefined4 *)(puVar6 + -0xc4) = 1;
      *(undefined4 *)(puVar6 + -4) = 0;
    }
    else if (DAT_01a1c848 < 1) {
      *(undefined4 *)(puVar6 + -0xc4) = 2;
      *(undefined4 *)(puVar6 + -0xc) = 0;
    }
    else {
      *(undefined4 *)(puVar6 + -0xc4) = 3;
      *(undefined4 *)(puVar6 + -8) = 0;
    }
  }
  else {
    if (DAT_0078b6a0 == 99) {
      *(undefined4 *)(puVar6 + -0x74) = 0;
      *(undefined4 *)(puVar6 + -0xe4) = 0;
      iVar3 = FUN_005fc330(puVar6 + -0xe4,0x18,0x784ff01,&DAT_0076a394,0,&DAT_0079fc60);
      *(int *)(puVar6 + -0x60) = iVar3;
      if (iVar3 == 0) {
        _DAT_01cadcf8 = 1;
        for (iVar3 = DAT_01cadcfc; 0 < iVar3; iVar3 = iVar3 + -1) {
          *(undefined4 *)(puVar6 + -0xf8) = 1;
          *(undefined **)(puVar6 + -0xf4) = &DAT_01caf69f + _DAT_01cadcf8;
          *(undefined4 *)(puVar6 + -0xf0) = 1;
          iVar4 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a390,puVar6 + -0xf8);
          *(int *)(puVar6 + -0x60) = iVar4;
          if (iVar4 != 0) goto LAB_0056df5d;
          _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
        }
        uVar5 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a38c,0);
        *(undefined4 *)(puVar6 + -0x60) = uVar5;
      }
LAB_0056df5d:
      if (*(int *)(puVar6 + -0x60) == 0) {
        *(undefined4 *)(puVar6 + -0x5c) = 0;
        goto LAB_0056ea41;
      }
    }
    else {
      thunk_FUN_0056ae1c();
      if ((_DAT_01cadd24 == f_0) && (_DAT_01cadd20 == f_0)) {
        *(undefined4 *)(puVar6 + -0x70) = 0;
LAB_0056dfbb:
        if (OUTPUT_MODE != -1) {
          if (DAT_01cadcfc < 2) {
            *(undefined4 *)(puVar6 + -0x58) = 0;
          }
          else {
            if (DAT_00791448 < 2) {
              DAT_00791448 = 2;
            }
            thunk_FUN_0054cb15(&DAT_01cac242 + DAT_00791440 * 0x1e,0x1e,&DAT_009a81e8,&DAT_0076a380)
            ;
            *(int *)(puVar6 + -0x54) = DAT_009a81e8;
            DAT_009a81e4 = 1;
            iVar3 = DAT_009a81e8;
            while (0 < iVar3) {
              *DAT_01fbb844 = *DAT_01fbb844 + 1;
              *(undefined *)
               ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                   (&DAT_01cac242)[DAT_009a81e4 + -1 + DAT_00791440 * 0x1e];
              DAT_009a81e4 = DAT_009a81e4 + 1;
              *(int *)(puVar6 + -0x54) = *(int *)(puVar6 + -0x54) + -1;
              iVar3 = *(int *)(puVar6 + -0x54);
            }
            *DAT_01fbb844 = *DAT_01fbb844 + 1;
            *(undefined1 *)
             ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) = 0;
            _DAT_009a81e0 = DAT_01a9f308 * f_1_937;
            *(undefined4 *)(puVar6 + -0xe4) = 0;
            *(undefined4 *)(puVar6 + -0xf8) = 0x1c;
            *(undefined1 **)(puVar6 + -0xf4) = &DAT_009a81f0;
            *(undefined **)(puVar6 + -0xf0) = &DAT_009a81e0;
            FUN_005f34f0(puVar6 + -0xe4,0x784ff00,&DAT_0076a374,puVar6 + -0xf8,&DAT_0079fc7c);
            DAT_009a81fe = 0;
            *(undefined4 *)(puVar6 + -0x4c) = 0xf;
            DAT_009a81dc = 1;
            do {
              *DAT_01fbb844 = *DAT_01fbb844 + 1;
              *(undefined1 *)
               ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                   *(undefined1 *)((int)&DAT_009a81ec + DAT_009a81dc + 3);
              DAT_009a81dc = DAT_009a81dc + 1;
              *(int *)(puVar6 + -0x4c) = *(int *)(puVar6 + -0x4c) + -1;
            } while (0 < *(int *)(puVar6 + -0x4c));
            *(undefined2 *)(puVar6 + -0xec) = in_FPUControlWord;
            *(ushort *)(puVar6 + -0xea) = (ushort)*(undefined4 *)(puVar6 + -0xec) | 0xc00;
            *(int *)(puVar6 + -0xe8) = (int)ROUND(P9 * f_10);
            DAT_009a81d8 = *(int *)(puVar6 + -0xe8);
            *(undefined4 *)(puVar6 + -0xe4) = 0;
            *(undefined4 *)(puVar6 + -0xf8) = 0x1c;
            *(undefined1 **)(puVar6 + -0xf4) = &DAT_009a81f0;
            *(int **)(puVar6 + -0xf0) = &DAT_009a81d8;
            FUN_005f34f0(puVar6 + -0xe4,0x784ff00,&DAT_0076a368,puVar6 + -0xf8,&DAT_0079fc9c);
            DAT_009a81fd = 0;
            *(undefined4 *)(puVar6 + -0x44) = 0xe;
            DAT_009a81dc = 1;
            do {
              *DAT_01fbb844 = *DAT_01fbb844 + 1;
              *(undefined1 *)
               ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                   *(undefined1 *)((int)&DAT_009a81ec + DAT_009a81dc + 3);
              DAT_009a81dc = DAT_009a81dc + 1;
              *(int *)(puVar6 + -0x44) = *(int *)(puVar6 + -0x44) + -1;
            } while (0 < *(int *)(puVar6 + -0x44));
            DAT_009a81d4 = 0;
            DAT_01a9f304 = DAT_009a81d0 + -1;
            *(undefined4 *)(puVar6 + -0xe4) = 0;
            *(undefined4 *)(puVar6 + -0xf8) = 0x1c;
            *(undefined1 **)(puVar6 + -0xf4) = &DAT_009a81f0;
            *(undefined **)(puVar6 + -0xf0) = &DAT_009a81cc;
            FUN_005f34f0(puVar6 + -0xe4,0x784ff00,&DAT_0076a368,puVar6 + -0xf8,&DAT_0079fcbc);
            DAT_009a81fa = 0;
            *(undefined4 *)(puVar6 + -0x3c) = 0xb;
            DAT_009a81dc = 1;
            do {
              *DAT_01fbb844 = *DAT_01fbb844 + 1;
              *(undefined1 *)
               ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                   *(undefined1 *)((int)&DAT_009a81ec + DAT_009a81dc + 3);
              DAT_009a81dc = DAT_009a81dc + 1;
              *(int *)(puVar6 + -0x3c) = *(int *)(puVar6 + -0x3c) + -1;
            } while (0 < *(int *)(puVar6 + -0x3c));
            if (DAT_009a81d8 == 0) {
              *(undefined4 *)(puVar6 + -0x38) = 0;
            }
            else {
              text_rotate(&DAT_009a81dc,&DAT_01cafac0,&DAT_01cb02c0,&P9);
            }
            *(int *)(puVar6 + -0x34) = DAT_009a81d0;
            DAT_009a81d4 = 1;
            iVar3 = DAT_009a81d0;
            while (0 < iVar3) {
              if ((&DAT_01caf69f)[DAT_009a81d4] == ' ') {
                *(undefined4 *)(puVar6 + -0x30) = 0;
              }
              else {
                *(undefined4 *)(puVar6 + -0xe4) = 0;
                *(undefined4 *)(puVar6 + -0xf8) = 0x1c;
                *(undefined1 **)(puVar6 + -0xf4) = &DAT_009a81f0;
                *(undefined4 *)(puVar6 + -0xf0) = 4;
                *(undefined **)(puVar6 + -0xec) = &DAT_01cafabc + DAT_009a81d4 * 4;
                FUN_005f34f0(puVar6 + -0xe4,0x784ff00,&DAT_0076a360,puVar6 + -0xf8,&DAT_0079fcdc);
                *(undefined4 *)(puVar6 + -0xf0) = 4;
                *(undefined **)(puVar6 + -0xec) = &DAT_01cb02bc + DAT_009a81d4 * 4;
                FUN_005f3960(puVar6 + -0xe4,&DAT_0076a35c,puVar6 + -0xf0);
                DAT_009a8200 = 0;
                *(undefined4 *)(puVar6 + -0x28) = 0x11;
                DAT_009a81dc = 1;
                do {
                  *DAT_01fbb844 = *DAT_01fbb844 + 1;
                  *(undefined1 *)
                   ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                       *(undefined1 *)((int)&DAT_009a81ec + DAT_009a81dc + 3);
                  DAT_009a81dc = DAT_009a81dc + 1;
                  *(int *)(puVar6 + -0x28) = *(int *)(puVar6 + -0x28) + -1;
                } while (0 < *(int *)(puVar6 + -0x28));
                *DAT_01fbb844 = *DAT_01fbb844 + 1;
                *(undefined *)
                 ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
                     (&DAT_01caf69f)[DAT_009a81d4];
                *DAT_01fbb844 = *DAT_01fbb844 + 1;
                *(undefined1 *)
                 ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) = 0;
              }
              *(undefined4 *)(puVar6 + -0x24) = 0;
              DAT_009a81d4 = DAT_009a81d4 + 1;
              *(int *)(puVar6 + -0x34) = *(int *)(puVar6 + -0x34) + -1;
              iVar3 = *(int *)(puVar6 + -0x34);
            }
            if (DAT_01cadce0 < DAT_01cb1068) {
              *(undefined4 *)(puVar6 + -0x1c) = 0;
            }
            else {
              *(undefined4 *)(puVar6 + -0x20) = 0;
            }
          }
          goto LAB_0056ea41;
        }
        FUN_0056ece5(&DAT_01caf69f + DAT_01cadcfc,1,&DAT_01cadcfc,&DAT_01a9f350);
        *(undefined4 *)(puVar6 + -0x18) = 0;
        *(undefined4 *)(puVar6 + -0xe4) = 0;
        *(undefined4 **)(puVar6 + -0xf0) = &DAT_01a27704;
        iVar3 = FUN_005fc330(puVar6 + -0xe4,0x18,0x784ff01,&DAT_0076a384,puVar6 + -0xf0,
                             &DAT_0079fbd8);
        *(int *)(puVar6 + -0x14) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 **)(puVar6 + -0xf0) = &DAT_01a27708;
          iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a384,puVar6 + -0xf0);
          *(int *)(puVar6 + -0x14) = iVar3;
          if (iVar3 == 0) {
            iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a394,0);
            *(int *)(puVar6 + -0x14) = iVar3;
            if (iVar3 == 0) {
              _DAT_01cadcf8 = 1;
              for (iVar3 = DAT_01cadcfc; 0 < iVar3; iVar3 = iVar3 + -1) {
                *(undefined4 *)(puVar6 + -0xf8) = 1;
                *(undefined **)(puVar6 + -0xf4) = &DAT_01caf69f + _DAT_01cadcf8;
                *(undefined4 *)(puVar6 + -0xf0) = 1;
                iVar4 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a390,puVar6 + -0xf8);
                *(int *)(puVar6 + -0x14) = iVar4;
                if (iVar4 != 0) goto LAB_0056e155;
                _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
              }
              uVar5 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a38c,0);
              *(undefined4 *)(puVar6 + -0x14) = uVar5;
            }
          }
        }
LAB_0056e155:
        if (*(int *)(puVar6 + -0x14) != 0) goto LAB_0056eaa0;
      }
      else {
        if (OUTPUT_MODE != -1) {
          *(undefined4 *)(puVar6 + -0x6c) = 0;
          goto LAB_0056dfbb;
        }
        FUN_0056ecc3(&DAT_01caf69f + DAT_01cadcfc,1);
        *(undefined4 *)(puVar6 + -0xe4) = 0;
        *(undefined4 **)(puVar6 + -0xf0) = &DAT_01a27704;
        iVar3 = FUN_005fc330(puVar6 + -0xe4,0x18,0x784ff01,&DAT_0076a384,puVar6 + -0xf0,
                             &DAT_0079fc08);
        *(int *)(puVar6 + -0x68) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 **)(puVar6 + -0xf0) = &DAT_01a27708;
          iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a384,puVar6 + -0xf0);
          *(int *)(puVar6 + -0x68) = iVar3;
          if (iVar3 == 0) {
            *(undefined **)(puVar6 + -0xf0) = &DAT_01cadd24;
            iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a358,puVar6 + -0xf0);
            *(int *)(puVar6 + -0x68) = iVar3;
            if (iVar3 == 0) {
              *(undefined **)(puVar6 + -0xf0) = &DAT_01cadd20;
              iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a358,puVar6 + -0xf0);
              *(int *)(puVar6 + -0x68) = iVar3;
              if (iVar3 == 0) {
                iVar3 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a394,0);
                *(int *)(puVar6 + -0x68) = iVar3;
                if (iVar3 == 0) {
                  _DAT_01cadcf8 = 1;
                  for (iVar3 = DAT_01cadcfc + 3; 0 < iVar3; iVar3 = iVar3 + -1) {
                    *(undefined4 *)(puVar6 + -0xf8) = 1;
                    *(undefined **)(puVar6 + -0xf4) = &DAT_01caf69f + _DAT_01cadcf8;
                    *(undefined4 *)(puVar6 + -0xf0) = 1;
                    iVar4 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a390,puVar6 + -0xf8);
                    *(int *)(puVar6 + -0x68) = iVar4;
                    if (iVar4 != 0) goto LAB_0056e9ee;
                    _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
                  }
                  uVar5 = FUN_005fc980(puVar6 + -0xe4,&DAT_0076a38c,0);
                  *(undefined4 *)(puVar6 + -0x68) = uVar5;
                }
              }
            }
          }
        }
LAB_0056e9ee:
        if (*(int *)(puVar6 + -0x68) != 0) goto LAB_0056eaa0;
        *(undefined4 *)(puVar6 + -100) = 0;
      }
      *(undefined4 *)(puVar6 + -0xe4) = 0;
      uVar5 = FUN_005fc330(puVar6 + -0xe4,0x18,0x784ff01,&DAT_0076a38c,0,&DAT_0079fcf0);
      *(undefined4 *)(puVar6 + -0x10) = uVar5;
      if (*(int *)(puVar6 + -0x10) == 0) goto LAB_0056ea41;
    }
LAB_0056eaa0:
    thunk_FUN_004cf1c2();
  }
LAB_0056eabb:
  return *(undefined4 *)(puVar6 + -0xc4);
}


