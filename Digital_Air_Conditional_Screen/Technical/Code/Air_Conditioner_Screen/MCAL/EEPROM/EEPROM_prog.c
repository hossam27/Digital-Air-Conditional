#include "types.h"
#include "util.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"

/*Comment!: initialize EEPROM*/
extern void EEPROM_voidInit(void)
{

	return;
}


/*Comment!: Write byte to EEPROM*/
extern void EEPROM_voidWriteByte(u8 Copy_u8Data, u16 Copy_u16Addresss)
{
	while( GETBIT(EEPROM_u8EECR,EEPROM_EECR_EEWE) );

/*Comment!:Set address*/
	ASSIGNREG(EEPROM_u16EEAR,Copy_u16Addresss);

/*Comment!:enable writing operation*/
	ASSIGNREG(EEPROM_u8EEDR,Copy_u8Data);

	SETBIT(EEPROM_u8EECR,EEPROM_EECR_EEMWE);
	SETBIT(EEPROM_u8EECR,EEPROM_EECR_EEWE);
	return;
}


/*Comment!: Read byte from EEPROM*/
extern u8 EEPROM_u8ReadByte(u16 Copy_u16Address)
{
	u8 local_u8EEPROMDATA;

/*Comment!:Set address*/
	ASSIGNREG(EEPROM_u16EEAR,Copy_u16Address);

/*Comment!:Enable read flag*/
	SETBIT(EEPROM_u8EECR,EEPROM_EECR_EERE);
	local_u8EEPROMDATA=EEPROM_u8EEDR;

	return local_u8EEPROMDATA;
}

