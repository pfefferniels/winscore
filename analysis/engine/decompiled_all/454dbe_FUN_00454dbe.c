// FUN_00454dbe @ 00454dbe (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454dbe(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (*param_1 != 0) {
    _DAT_007feb84 = thunk_FUN_00450b9c(param_2);
    switch(*param_1) {
    case 0x21:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454e2a);
      puVar2 = puVar3;
      FUN_005f34d1(puVar3,&LAB_00454e45);
      *(undefined4 *)(puVar2 + -0x28) = 0;
      break;
    case 0x22:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454e73);
      puVar2 = puVar4;
      FUN_005f34d1(puVar4,&LAB_00454e8e);
      *(undefined4 *)(puVar2 + -0x24) = 0;
      break;
    case 0x23:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454ebc);
      puVar2 = puVar5;
      FUN_005f34d1(puVar5,&LAB_00454ed7);
      *(undefined4 *)(puVar2 + -0x20) = 0;
      break;
    case 0x24:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454f05);
      puVar2 = puVar6;
      FUN_005f34d1(puVar6,&LAB_00454f20);
      *(undefined4 *)(puVar2 + -0x1c) = 0;
      break;
    case 0x25:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454f4e);
      puVar2 = puVar7;
      FUN_005f34d1(puVar7,&LAB_00454f69);
      *(undefined4 *)(puVar2 + -0x18) = 0;
      break;
    case 0x26:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454f97);
      puVar2 = puVar8;
      FUN_005f34d1(puVar8,&LAB_00454fb2);
      *(undefined4 *)(puVar2 + -0x14) = 0;
      break;
    case 0x27:
      FUN_005f33c9(&stack0xfffffffc,&LAB_00454fe0);
      puVar2 = puVar9;
      FUN_005f34d1(puVar9,&LAB_00454ffb);
      *(undefined4 *)(puVar2 + -0x10) = 0;
      break;
    case 0x28:
      FUN_005f33c9(&stack0xfffffffc,&UNK_00455026);
      FUN_005f34d1(puVar2,&UNK_00455041);
      break;
    default:
      if (*param_1 != 0x2e) {
        return;
      }
      if (*param_3 == 1) {
        return;
      }
      *param_3 = *param_3 + -1;
      *DAT_01fbb7c0 = *DAT_01fbb7c0 + -3;
      VEC_N = VEC_N + -3;
      _DAT_01c25e58 = *param_3;
      if (*param_3 < *param_2) {
        *param_2 = 1;
        return;
      }
      DAT_007feb78 = *param_2 * 3 + 0x16;
      DAT_007feb74 = *param_2;
      for (iVar1 = (*param_3 - DAT_007feb74) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&PT_X0)[DAT_007feb74] = (&DAT_01fd3f80)[DAT_007feb74];
        (&PT_Y0)[DAT_007feb74] = (&DAT_02004cc0)[DAT_007feb74];
        if (1 < DAT_007feb74) {
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007feb74 * 2 + 2) = (&DAT_01fbb8e0)[DAT_007feb74]
          ;
        }
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007feb78 * VEC_STRIDE) =
             *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb78 + 3) * VEC_STRIDE)
        ;
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb78 + 1) * VEC_STRIDE) =
             *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb78 + 4) * VEC_STRIDE)
        ;
        if (1 < DAT_007feb74) {
          *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb78 + 2) * VEC_STRIDE) =
               *(undefined4 *)
                ((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb78 + 5) * VEC_STRIDE);
        }
        DAT_007feb78 = DAT_007feb78 + 3;
        DAT_007feb74 = DAT_007feb74 + 1;
      }
      return;
    }
    **(undefined4 **)(puVar2 + 8) = **(undefined4 **)(puVar2 + 0xc);
    if (**(int **)(puVar2 + 0x14) == 0) {
      **(undefined4 **)(puVar2 + 8) = **(undefined4 **)(puVar2 + 0x10);
    }
    FUN_004552cc(*(undefined4 *)(puVar2 + 8),*(undefined4 *)(puVar2 + 0x14),&DAT_007feb80,
                 &DAT_007feb7c);
    *(undefined4 *)(puVar2 + -0xc) = 0;
  }
  return;
}


