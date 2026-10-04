// FUN_0049095a @ 0049095a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049095a(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  puVar4 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if ((char)DAT_020b8ea0 == '[') {
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(&stack0xfffffffc,0x490b6d);
      puVar3 = puVar5;
      FUN_005f34d1(puVar5,0x490b88);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar3,0x490bd4);
      FUN_005f34d1(puVar3,0x490bef);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar3,0x490c3b);
      FUN_005f34d1(puVar3,0x490c56);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar3,0x490ca2);
      FUN_005f34d1(puVar3,0x490cbd);
    }
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  else {
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(&stack0xfffffffc,0x4909c8);
      puVar2 = puVar4;
      FUN_005f34d1(puVar4,0x4909e3);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x490a2f);
      FUN_005f34d1(puVar2,0x490a4a);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x490a96);
      FUN_005f34d1(puVar2,0x490ab1);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x490b01);
      FUN_005f34d1(puVar2,0x490b1c);
    }
  }
  return;
}


