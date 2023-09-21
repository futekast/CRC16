
//------------------------------------------------------------------------------ 
// 	Function Name:		CRC16 Table
// 	Description: 		This subroutine contains the crc table required
//						for the crc16 calculation.
// 	Parameters:	 		Width: 		16
//						Poly:  		0x8005 (x^16 + x^15 + x^2 + 1)
//						Init:  		0 
// 	Returns: 			None
//------------------------------------------------------------------------------
extern uint16_t const crcTable[256];


//------------------------------------------------------------------------------ 
// 	Function Name:		CRC16 Function
// 	Description: 		This subroutine computes the CRC-16 for the data buffer.
// 	Parameters:	 		crc:		Previous CRC value
// 						buffer:		Data pointer
//						length:		Number of bytes in the buffer 	
// 	Returns: 			The updated CRC value
//------------------------------------------------------------------------------
uint16_t crc16(uint16_t crc, const uint8_t *buffer, size_t length);

static inline uint16_t crc16Byte(uint16_t crc, const uint8_t data)
{
    return (crc >> 8) ^ crcTable[(crc^data) & 0xFF];
}
