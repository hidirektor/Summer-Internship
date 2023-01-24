#include <stdio.h>
#include <stdlib.h>

void checkEEPROMData(uint8_t acilStop1T, uint8_t acilStop2T, uint8_t acilStop3T, uint8_t calismaSekliT,
                     uint8_t eCercevesiT, uint8_t yavaslamaLimitT, uint8_t altLimitT, uint8_t basincSalterT,
                     uint8_t kapiSiviciT, uint8_t kapi1TipT, uint8_t kapi1acsureT, uint8_t kapi2TipT,
                     uint8_t kapi2acsureT, uint8_t kapitablaTipT, uint8_t kapiTablaSureT,
                     uint8_t yukariYavaslamaT, uint8_t devirmeYuruyusSecimT, uint8_t devirmeYukariIleriLimitT,
                     uint8_t devirmeAsagiLimitT, uint8_t devirmeSilindirTipiT, uint8_t platformSilindirTipiT,
                     uint8_t yukarivalfDurusSuresiT, uint8_t asagivalfDurusSuresiT,
                     uint8_t devirmevalfDurusSuresiT, uint8_t devirme2valfDurusSuresiT,
                     uint8_t makineCalismaTmrT, uint8_t buzzerT, uint8_t dilSecimiT, uint8_t kaydedilenDegerT,
                     uint8_t demoModT) {
    if(acilStop1T != eepromData[0]) {
        eepromData[0] = acilStop1T;
        acilStop1 = eepromData[0];
    }
    if(acilStop2T != eepromData[1]) {
        eepromData[1] = acilStop2T;
        acilStop2 = eepromData[1];
    }
    if(acilStop3T != eepromData[2]) {
        eepromData[2] = acilStop3T;
        acilStop3 = eepromData[2];
    }
    if(calismaSekliT != eepromData[3]) {
        eepromData[3] = calismaSekliT;
        calismaSekli = eepromData[3];
    }
    if(eCercevesiT != eepromData[4]) {
       eepromData[4] = eCercevesiT;
       eCercevesi = eepromData[4];
    }
    if(yavaslamaLimitT != eepromData[5]) {
        eepromData[5] = yavaslamaLimitT;
        yavaslamaLimit = eepromData[5];
    }
    if(altLimitT != eepromData[6]) {
        eepromData[6] = altLimitT;
        altLimit = eepromData[6];
    }
    if(basincSalterT != eepromData[7]) {
        eepromData[7] = basincSalterT;
        basincSalter = eepromData[7];
    }
    if(kapiSiviciT != eepromData[8]) {
        eepromData[8] = kapiSiviciT;
        kapiSivici = eepromData[8];
    }
    if(kapi1TipT != eepromData[9]) {
        eepromData[9] = kapi1TipT;
        kapi1Tip = eepromData[9];
    }
    if(kapi1acsureT != eepromData[10]) {
        eepromData[10] = kapi1acsureT;
        kapi1acsure = eepromData[10];
    }
    if(kapi2TipT != eepromData[11]) {
        eepromData[11] = kapi2TipT;
        kapi2Tip = eepromData[11];
    }
    if(kapi2acsureT != eepromData[12]) {
        eepromData[12] = kapi2acsureT;
        kapi2acsure = eepromData[12];
    }
    if(kapitablaTipT != eepromData[13]) {
        eepromData[13] = kapitablaTipT;
        kapitablaTip = eepromData[13];
    }
    if(kapiTablaSureT != eepromData[14]) {
        eepromData[14] = kapiTablaSureT;
        kapiTablaSure = eepromData[14];
    }
    if(yukariYavaslamaT != eepromData[15]) {
        eepromData[15] = yukariYavaslamaT;
        yukariYavaslama = eepromData[15];
    }
    if(devirmeYuruyusSecimT != eepromData[16]) {
        eepromData[16] = devirmeYuruyusSecimT;
        devirmeYuruyusSecim = eepromData[16];
    }
    if(devirmeYukariIleriLimitT != eepromData[17]) {
        eepromData[17] = devirmeYukariIleriLimitT;
        devirmeYukariIleriLimit = eepromData[17];
    }
    if(devirmeAsagiLimitT != eepromData[18]) {
        eepromData[18] = devirmeAsagiLimitT;
        devirmeAsagiLimit = eepromData[18];
    }
    if(devirmeSilindirTipiT != eepromData[19]) {
        eepromData[19] = devirmeSilindirTipiT;
        devirmeSilindirTipi = eepromData[19];
    }
    if(platformSilindirTipiT != eepromData[20]) {
        eepromData[20] = platformSilindirTipiT;
        platformSilindirTipi = eepromData[20];
    }
    if(yukarivalfDurusSuresiT != eepromData[21]) {
        eepromData[21] = platformSilindirTipiT;
        platformSilindirTipi = eepromData[21];
    }
    if(asagivalfDurusSuresiT != eepromData[22]) {
        eepromData[22] = asagivalfDurusSuresiT;
        asagivalfDurusSuresi = eepromData[22];
    }
    if(devirmevalfDurusSuresiT != eepromData[23]) {
        eepromData[23] = devirmevalfDurusSuresiT;
        devirmevalfDurusSuresi = eepromData[23];
    }
    if(devirme2valfDurusSuresiT != eepromData[24]) {
        eepromData[24] = devirme2valfDurusSuresiT;
        devirme2valfDurusSuresi = eepromData[24];
    }
    if(makineCalismaTmrT != eepromData[25]) {
        eepromData[25] = makineCalismaTmrT;
        makineCalismaTmr = eepromData[25];
    }
    if(buzzerT != eepromData[26]) {
        eepromData[26] = buzzerT;
        buzzer = eepromData[26];
    }
    if(dilSecimiT != eepromData[27]) {
        eepromData[27] = dilSecimiT;
        dilSecimi = eepromData[27];
    }
    if(kaydedilenDegerT != eepromData[28]) {
        eepromData[28] = kaydedilenDegerT;
        kaydedilenDeger = eepromData[28];
    }
    if(demoModT != eepromData[29]) {
        eepromData[29] = demoModT;
        demoMod = eepromData[29];
    }
}


Satır 307 ve sonrası:
if(menuSayac==2) {
    if(dilSecimi == 0) {
        lcd_print(1,1,"ACIL STOP2");
    } else {
        lcd_print(1,1,"EMERGENCY STOP2");
    }
    if(acilStop2 == 0 && dilSecimi == 0) {
        lcd_print(2,1,"PASIF ");
    } else if(acilStop2 == 1 && dilSecimi == 0) {
        lcd_print(2,1,"INACTIVE");
    }
    if(acilStop2 == 1 && dilSecimi == 0) {
        lcd_print(2,1,"AKTIF");
    } else if(acilStop2 == 1 && dilSecimi == 1) {
        lcd_print(2,1,"ACTIVE");
    }
}

Satır 341 ve sonrası:
if(menuSayac==3) {
    if(dilSecimi == 0) {
        lcd_print(1,1,"ACIL STOP3");
    } else {
        lcd_print(1,1,"EMERGENCY STOP3");
    }
    if(acilStop3 == 0 && dilSecimi == 0) {
        lcd_print(2,1,"PASIF");
    } else if(acilStop3 == 1 && dilSecimi == 0) {
        lcd_print(2,1,"INACTIVE");
    }
    if(acilStop3 == 1 && dilSecimi == 0) {
        lcd_print(2,1,"AKTIF");
    } else if(acilStop3 == 1 && dilSecimi == 1) {
        lcd_print(2,1,"ACTIVE");
    }
}

Satır 482 ve sonrası:
if(menuSayac == 6) {
    if(dilSecimi == 0) {
        lcd_print(1,1,"YAVASLAMA LIMIT");
    } else {
        lcd_print(1,1,"DECLERATION LIM");
    }
    if(yavaslamaLimit == 0 && dilSecim == 0) {
        lcd_print(2,1,"PASIF");
    } else if(yavaslamaLimit == 0 && dilSecim == 1) {
        lcd_print(2,1,"INACTIVE");
    }
    if(yavaslamaLimit == 1 && dilSecim == 0) {
        lcd_print(2,1,"AKTIF");
    } else if(yavaslamaLimit == 1 && dilSecim == 1) {
        lcd_print(2,1,"ACTIVE");
    }
}

Satır 515 ve sonrası:
if(menuSayac == 7) {
    if(dilSecimi == 0) {
        lcd_print(1,1,"ALT LIMIT");
    } else {
        lcd_print(1,1,"LOWER LIMIT");
    }
    if(altLimit == 0 && dilSecim == 0) {
        lcd_print(2,1,"PASIF");
    } else if(altLimit == 0 && dilSecim == 1) {
        lcd_print(2,1,"INACTIVE");
    }
    if(altLimit == 1 && dilSecim == 0) {
        lcd_print(2,1,"AKTIF");
    } else if(altLimit == 1 && dilSecim == 1) {
        lcd_print(2,1,"ACTIVE");
    }
}

Satur 549 ve sonrası:
if(menuSayac == 8) {
    if(dilSecimi == 0) {
        lcd_print(1,1,"BASINC SALTER");
    } else {
        lcd_print(1,1,"PRESSURE SWITCH");
    }
    if(basincSalter == 0 && dilSecimi == 0) {
        lcd_print(2,1,"PASIF");
    } else if(basincSalter == 0 && dilSecimi == 1) {
        lcd_print(2,1,"INACTIVE");
    }
    if(basincSalter == 1 && dilSecimi == 0) {
        lcd_print(2,1,"AKTIF");
    } else if(basincSalter == 1 && dilSecimi == 1) {
        lcd_print(2,1,"ACTIVE");
    }
}

manuel itoa fonksiyonu:
void convert2Ascii(uint8_t num, char* str) {
    uint8_t i = 0, j, rem;
    while(num > 0) {
        rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }
    str[i] = '\0';
    for(i = 0, j < strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

itoa alternatif 2:
satır 316 için:
itoa(acilStop2, snum, 10); -> sprintf(snum,'%d',acilStop2);