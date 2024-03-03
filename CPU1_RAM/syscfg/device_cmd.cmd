#ifdef generic_ram_lnk

MEMORY
{

    RAMM0_BEGIN               : origin = 0x000000, length = 0x000002
    RAMM0                     : origin = 0x0000F6, length = 0x00030A
    RAMM1                     : origin = 0x000400, length = 0x0003F8
    CLATOCPU_MSGRAM           : origin = 0x001480, length = 0x000080
    CPUTOCLA_MSGRAM           : origin = 0x001500, length = 0x000080
    RAMLS0                    : origin = 0x008000, length = 0x000800
    RAMLS1                    : origin = 0x008800, length = 0x000800
    RAMLS2                    : origin = 0x009000, length = 0x000800
    RAMLS3                    : origin = 0x009800, length = 0x000800
    RAMLS4                    : origin = 0x00A000, length = 0x000800
    RAMLS5                    : origin = 0x00A800, length = 0x000800
    RAMLS6                    : origin = 0x00B000, length = 0x000800
    RAMLS7                    : origin = 0x00B800, length = 0x000800
    RAMGS0                    : origin = 0x00C000, length = 0x002000
    RAMGS1                    : origin = 0x00E000, length = 0x002000
    RAMGS2                    : origin = 0x010000, length = 0x002000
    RAMGS3                    : origin = 0x012000, length = 0x001FF8
    FLASH_BANK0_SEC0          : origin = 0x080000, length = 0x001000
    FLASH_BANK0_SEC1          : origin = 0x081000, length = 0x001000
    FLASH_BANK0_SEC2          : origin = 0x082000, length = 0x001000
    FLASH_BANK0_SEC3          : origin = 0x083000, length = 0x001000
    FLASH_BANK0_SEC4          : origin = 0x084000, length = 0x001000
    FLASH_BANK0_SEC5          : origin = 0x085000, length = 0x001000
    FLASH_BANK0_SEC6          : origin = 0x086000, length = 0x001000
    FLASH_BANK0_SEC7          : origin = 0x087000, length = 0x001000
    FLASH_BANK0_SEC8          : origin = 0x088000, length = 0x001000
    FLASH_BANK0_SEC9          : origin = 0x089000, length = 0x001000
    FLASH_BANK0_SEC10         : origin = 0x08A000, length = 0x001000
    FLASH_BANK0_SEC11         : origin = 0x08B000, length = 0x001000
    FLASH_BANK0_SEC12         : origin = 0x08C000, length = 0x001000
    FLASH_BANK0_SEC13         : origin = 0x08D000, length = 0x001000
    FLASH_BANK0_SEC14         : origin = 0x08E000, length = 0x001000
    FLASH_BANK0_SEC15         : origin = 0x08F000, length = 0x001000
    FLASH_BANK1_SEC0          : origin = 0x090000, length = 0x001000
    FLASH_BANK1_SEC1          : origin = 0x091000, length = 0x001000
    FLASH_BANK1_SEC2          : origin = 0x092000, length = 0x001000
    FLASH_BANK1_SEC3          : origin = 0x093000, length = 0x001000
    FLASH_BANK1_SEC4          : origin = 0x094000, length = 0x001000
    FLASH_BANK1_SEC5          : origin = 0x095000, length = 0x001000
    FLASH_BANK1_SEC6          : origin = 0x096000, length = 0x001000
    FLASH_BANK1_SEC7          : origin = 0x097000, length = 0x001000
    FLASH_BANK1_SEC8          : origin = 0x098000, length = 0x001000
    FLASH_BANK1_SEC9          : origin = 0x099000, length = 0x001000
    FLASH_BANK1_SEC10         : origin = 0x09A000, length = 0x001000
    FLASH_BANK1_SEC11         : origin = 0x09B000, length = 0x001000
    FLASH_BANK1_SEC12         : origin = 0x09C000, length = 0x001000
    FLASH_BANK1_SEC13         : origin = 0x09D000, length = 0x001000
    FLASH_BANK1_SEC14         : origin = 0x09E000, length = 0x001000
    FLASH_BANK1_SEC15         : origin = 0x09F000, length = 0x000FF0
    RESET                     : origin = 0x3FFFC0, length = 0x000002
}


SECTIONS
{
    //
    // C28x Sections
    //
    .reset               : >  RESET, TYPE = DSECT /* not used, */
    codestart            : >  0x000000
    .text                : >> RAMGS0 | RAMLS4 | RAMLS5 | RAMLS6 | RAMLS7
    .TI.ramfunc          : >  RAMM0
    .cinit               : >  RAMM0
    .stack               : >  RAMM1
    .init_array          : >  RAMM0
    .bss                 : >  RAMLS4
    .const               : >  RAMLS4
    .data                : >  RAMLS4
    .switch              : >  RAMM0
    .sysmem              : >  RAMLS4

}

#endif
#ifdef generic_flash_lnk

MEMORY
{

    RAMM0                     : origin = 0x0000F6, length = 0x00030A
    RAMM1                     : origin = 0x000400, length = 0x0003F8
    CLATOCPU_MSGRAM           : origin = 0x001480, length = 0x000080
    CPUTOCLA_MSGRAM           : origin = 0x001500, length = 0x000080
    RAMLS0                    : origin = 0x008000, length = 0x000800
    RAMLS1                    : origin = 0x008800, length = 0x000800
    RAMLS2                    : origin = 0x009000, length = 0x000800
    RAMLS3                    : origin = 0x009800, length = 0x000800
    RAMLS4                    : origin = 0x00A000, length = 0x000800
    RAMLS5                    : origin = 0x00A800, length = 0x000800
    RAMLS6                    : origin = 0x00B000, length = 0x000800
    RAMLS7                    : origin = 0x00B800, length = 0x000800
    RAMGS0                    : origin = 0x00C000, length = 0x002000
    RAMGS1                    : origin = 0x00E000, length = 0x002000
    RAMGS2                    : origin = 0x010000, length = 0x002000
    RAMGS3                    : origin = 0x012000, length = 0x001FF8
    FLASH_BANK0_SEC0          : origin = 0x080000, length = 0x001000
    FLASH_BANK0_SEC1          : origin = 0x081000, length = 0x001000
    FLASH_BANK0_SEC2          : origin = 0x082000, length = 0x001000
    FLASH_BANK0_SEC3          : origin = 0x083000, length = 0x001000
    FLASH_BANK0_SEC4          : origin = 0x084000, length = 0x001000
    FLASH_BANK0_SEC5          : origin = 0x085000, length = 0x001000
    FLASH_BANK0_SEC6          : origin = 0x086000, length = 0x001000
    FLASH_BANK0_SEC7          : origin = 0x087000, length = 0x001000
    FLASH_BANK0_SEC8          : origin = 0x088000, length = 0x001000
    FLASH_BANK0_SEC9          : origin = 0x089000, length = 0x001000
    FLASH_BANK0_SEC10         : origin = 0x08A000, length = 0x001000
    FLASH_BANK0_SEC11         : origin = 0x08B000, length = 0x001000
    FLASH_BANK0_SEC12         : origin = 0x08C000, length = 0x001000
    FLASH_BANK0_SEC13         : origin = 0x08D000, length = 0x001000
    FLASH_BANK0_SEC14         : origin = 0x08E000, length = 0x001000
    FLASH_BANK0_SEC15         : origin = 0x08F000, length = 0x001000
    FLASH_BANK1_SEC0          : origin = 0x090000, length = 0x001000
    FLASH_BANK1_SEC1          : origin = 0x091000, length = 0x001000
    FLASH_BANK1_SEC2          : origin = 0x092000, length = 0x001000
    FLASH_BANK1_SEC3          : origin = 0x093000, length = 0x001000
    FLASH_BANK1_SEC4          : origin = 0x094000, length = 0x001000
    FLASH_BANK1_SEC5          : origin = 0x095000, length = 0x001000
    FLASH_BANK1_SEC6          : origin = 0x096000, length = 0x001000
    FLASH_BANK1_SEC7          : origin = 0x097000, length = 0x001000
    FLASH_BANK1_SEC8          : origin = 0x098000, length = 0x001000
    FLASH_BANK1_SEC9          : origin = 0x099000, length = 0x001000
    FLASH_BANK1_SEC10         : origin = 0x09A000, length = 0x001000
    FLASH_BANK1_SEC11         : origin = 0x09B000, length = 0x001000
    FLASH_BANK1_SEC12         : origin = 0x09C000, length = 0x001000
    FLASH_BANK1_SEC13         : origin = 0x09D000, length = 0x001000
    FLASH_BANK1_SEC14         : origin = 0x09E000, length = 0x001000
    FLASH_BANK1_SEC15         : origin = 0x09F000, length = 0x000FF0
    RESET                     : origin = 0x3FFFC0, length = 0x000002
}


SECTIONS
{
    //
    // C28x Sections
    //
    .reset               : >  RESET, TYPE = DSECT /* not used, */
    codestart            : >  0x080000
    .text                : >> FLASH_BANK0_SEC2 | FLASH_BANK0_SEC3 | FLASH_BANK0_SEC4,
                              ALIGN(8)
    .TI.ramfunc          : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .binit               : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .ovly                : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .cinit               : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .stack               : >  RAMM1
    .init_array          : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .bss                 : >  RAMLS5
    .const               : >  FLASH_BANK0_SEC4,
                              ALIGN(8)
    .data                : >  RAMLS5
    .switch              : >  FLASH_BANK0_SEC1,
                              ALIGN(8)
    .sysmem              : >  RAMLS5

}

#endif

/*
//===========================================================================
// End of file.
//===========================================================================
*/
