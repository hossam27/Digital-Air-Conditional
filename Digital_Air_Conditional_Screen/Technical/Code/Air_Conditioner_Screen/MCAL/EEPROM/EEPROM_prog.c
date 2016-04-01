#include "../../BSW/Shared library/Types.h"
#include "../../BSW/Shared library/util.h"
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
	while( GET_BIT(EEPROM_u8EECR,EEPROM_EECR_EEWE) );

/*Comment!:Set address*/
	ASSIGN_REG(EEPROM_u16EEAR,Copy_u16Addresss);

/*Comment!:enable writing operation*/
	ASSIGN_REG(EEPROM_u8EEDR,Copy_u8Data);

	SET_BIT(EEPROM_u8EECR,EEPROM_EECR_EEMWE);
	SET_BIT(EEPROM_u8EECR,EEPROM_EECR_EEWE);
	return;
}


/*Comment!: Read byte from EEPROM*/
extern u8 EEPROM_u8ReadByte(u16 Copy_u16Address)
{
	u8 local_u8EEPROMDATA;

/*Comment!:Set address*/
	ASSIGN_REG(EEPROM_u16EEAR,Copy_u16Address);

/*Comment!:Enable read flag*/
	SET_BIT(EEPROM_u8EECR,EEPROM_EECR_EERE);
	local_u8EEPROMDATA=EEPROM_u8EEDR;

	return local_u8EEPROMDATA;
}

