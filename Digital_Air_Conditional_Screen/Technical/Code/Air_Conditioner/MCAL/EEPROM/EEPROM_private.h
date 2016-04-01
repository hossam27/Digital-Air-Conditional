#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEPROM_u8EEARH								( *((volatile u8*)(0x3F)) )
#define EEPROM_u8EEARL								( *((volatile u8*)(0x3E)) )

#define EEPROM_u16EEAR								( *((volatile u16*)(0x3E)) )

#define EEPROM_u8EEDR								( *((volatile u8*)(0x3D)) )
#define EEPROM_u8EECR								( *((volatile u8*)(0x3C)) )


/*Comment!: EEPROM EECR register */
#define EEPROM_EECR_EERE							0
#define EEPROM_EECR_EEWE							1
#define EEPROM_EECR_EEMWE							2
#define EEPROM_EECR_EERIE 							3



#endif
