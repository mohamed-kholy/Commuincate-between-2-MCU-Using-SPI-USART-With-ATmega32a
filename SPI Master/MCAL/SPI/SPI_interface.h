#ifndef		SPI_INTERFACE_H_
#define		SPI_INTERFACE_H_

void MSPI_voidSPIinit(void);
void MSPI_voidSPISendChar (u8 copy_u8Data);
u8 MSPI_u8SPIReceiveChar(void);
void MSPI_voidReceiveString (u8 *copy_u8PtrStr);
void MSPI_voidSPISendString (u8 *copy_u8PtrStr);


#endif