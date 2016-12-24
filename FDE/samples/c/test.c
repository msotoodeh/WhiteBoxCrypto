/*
  Copyright (C) 2013 KryptoLogik.com.  All rights reserved.

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

 */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------------------------
// Include the key named 'abc'
// Accepts cerdit card style inputs (encoding decimal digits)
// Packed size is 16 (number of digits in plain/cipher text)
// Non-decimal inputs are taken as formatting characters
#include "kplus_fde_abc_encrypt.h"
#include "kplus_fde_abc_decrypt.h"
// --------------------------------------------------------------------------

int fde_d2_Test(const char *pt, const char *ct)
{
    int rc = 0;
    char tt[80];

    printf("\nPT: %s", pt);
    printf("\nCT: %s", kplus_fde_abc_encrypt(pt, tt));
    if (ct && strcmp(tt, ct) != 0)
    {
        printf(" -- FAIL (KAT)");
        rc++;
    }
    printf("\nPT? %s", kplus_fde_abc_decrypt(tt, tt));
    rc += (strcmp(tt, pt) == 0) ? 0 : 1;
    printf(" -- %s\n", rc ? "FAIL" : "PASS");
    return rc;
}

int main (int argc, char ** argv)
{
    int rc = 0;

    if (argc > 1)
        return fde_d2_Test(argv[1], 0);

    rc += fde_d2_Test("1234-5678-9012-3456","6364-9193-8641-7518");
    rc += fde_d2_Test("0000.0000.0000.0000","5973.0207.8184.2608");
    rc += fde_d2_Test("0000.0001.0000.0001","8138.0777.0929.3461");
    rc += fde_d2_Test("0000.0000.1000.0000","2581.9159.0195.6384");
    rc += fde_d2_Test("0000.0010.0000.0000","1583.2907.4641.3480");
    rc += fde_d2_Test("1111-1111-1111-1111","4948-3447-7236-5824");
    rc += fde_d2_Test("1110-1111-1111-1111","3499-0663-3295-3279");
    rc += fde_d2_Test("9999/9999/9999/9999","7859/6241/7785/7984");
    return rc;
}
