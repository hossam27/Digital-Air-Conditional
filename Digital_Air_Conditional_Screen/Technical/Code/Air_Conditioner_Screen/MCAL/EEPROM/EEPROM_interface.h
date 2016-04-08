#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/*Comment!: initialize EEPROM*/
extern void EEPROM_voidInit(void);

/*Comment!: Read byte from EEPROM*/
extern u8 EEPROM_u8ReadByte(u16 Copy_u16Address,u8* Copy_u8Data);

/*Comment!: Write byte to EEPROM*/
extern void EEPROM_voidWriteByte(u8 Copy_u8Data, u16 Copy_u16Addresss);

#endif
