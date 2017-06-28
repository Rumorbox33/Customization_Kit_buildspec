/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/
#ifndef _NAND_UTIL_FUNC_H_
#define _NAND_UTIL_FUNC_H_

#include "sys/types.h"
#include "error_code.h"
#include "nand_dev_tbl.h"
#include "main_nand.h"

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// GPIO                                                 
//------------------------------------------------------------------------------

#define GPIO_WRITE32(addr,data)		(*(volatile uint32*)(addr) = (uint32)(data))
#define GPIO_READ32(addr)			(*(volatile uint32*)(addr))

#define IOCFG_LT_BASE				(0x10002000)
#define GPIO_BASE					(0x10005000)

#define GPIO_BANK					(GPIO_BASE + 0x06F0)
#define TRAP_BOOT					(0x3 << 13)
#define BOOT_TLC					(0x2 << 13) // [14:13]=2'b10
#define BOOT_SLC					(0x3 << 13) // [14:13]=2'b11

#define GPIO_MODE0					(GPIO_BASE + 0x0300)
#define GPIO_MODE4					(GPIO_BASE + 0x0340)
#define GPIO_MODE5					(GPIO_BASE + 0x0350)
#define GPIO_MODE6					(GPIO_BASE + 0x0360)

#define IOCFG_DRV_CFG0				(IOCFG_LT_BASE)
#define IOCFG_DRV_CFG1				(IOCFG_LT_BASE + 0x10)
#define IOCFG_DRV_CFG2				(IOCFG_LT_BASE + 0x20)

#define IOCFG_PUPD_CFG0				(IOCFG_LT_BASE + 0x40)
#define IOCFG_R0_CFG0				(IOCFG_LT_BASE + 0x50)
#define IOCFG_R1_CFG0				(IOCFG_LT_BASE + 0x60)

//------------------------------------------------------------------------------
// NFI                                                
//------------------------------------------------------------------------------
#define	FTL_PAGE_SIZE				(16384)
#define	FTL_OOB_SIZE				(32)

#define NUTL_PPAGE_EN 				128
#define NUTL_READ_PPAGE_EN 			NUTL_PPAGE_EN

#define NUTL_DEFAULT_TIMEOUT		0x00FFFFFF

#define NFI_Wait(condition_expression, timeout)	while( (condition_expression) && (--timeout) )
//------------------------------------------------------------------------------
// Device Spec. Reference Macro                                                 
//------------------------------------------------------------------------------
#define NUTL_MAKER_CODE()						(g_pNandInfo->m_dev->m_hw_info.m_id.m_maker_code)
#define NUTL_DEVICE_CODE()						(g_pNandInfo->m_dev->m_hw_info.m_id.m_device_code)
#define NUTL_IDENTIFY_CODE(p_nand)				(g_pNandInfo->m_dev->m_hw_info.m_id.m_identify_code)
#define NUTL_FEATURE_CODE(p_nand)				(g_pNandInfo->m_dev->m_hw_info.m_id.m_feature_code)
#define NUTL_PLANE_CODE(p_nand)					(g_pNandInfo->m_dev->m_hw_info.m_id.m_plane_code)

#define NUTL_EXT_CODE4()						(g_pNandInfo->m_dev->m_hw_info.m_id.ext_code4)
#define NUTL_EXT_CODE5()						(g_pNandInfo->m_dev->m_hw_info.m_id.ext_code5)

#define NUTL_NAND_TYPE()						(g_pNandInfo->m_dev->m_nand_type)

#define NUTL_TOTAL_SIZE()						((g_pNandInfo->m_dev->m_nand_type == NAND_FLASH_TLC)?(g_pNandInfo->m_dev->m_hw_info.m_total_size):(((U64)(g_pNandInfo->m_dev->m_hw_info.m_total_size))<<20))
#define NUTL_PAGES_PER_BLOCK()					((g_pNandInfo->m_dev->m_nand_type == NAND_FLASH_TLC)?(g_pNandInfo->m_dev->m_hw_info.m_pages_per_block*( g_pNandInfo->m_dev->m_tlc_setting->slcopmodeEn?1:3)):(g_pNandInfo->m_dev->m_hw_info.m_pages_per_block))

#define NUTL_BLOCK_SIZE()						(g_pNandInfo->m_block_size)
#define NUTL_PAGE_SIZE()						(g_pNandInfo->m_dev->m_hw_info.m_page_size)
#define NUTL_SECTOR_SIZE()						(g_pNandInfo->m_dev->m_hw_info.m_sector_size)
#define NUTL_SPARE_PER_SEC_SIZE()				(g_pNandInfo->m_dev->m_hw_info.m_spare_size_per_sector)
#define NUTL_SPARE_SIZE()						(g_pNandInfo->m_spare_size)
#define NUTL_TOTAL_PAGE_COUNT()					(g_pNandInfo->m_total_pages)
#define NUTL_TOTAL_BLOCK_COUNT()				(g_pNandInfo->m_total_blocks)
#define NUTL_PAGE_ADDR_SHIFT_BITS()				(g_pNandInfo->m_page_addr_shift_bits)
#define NUTL_BLOCK_ADDR_SHIFT_BITS()			(g_pNandInfo->m_block_addr_shift_bits)
#define NUTL_ADDR_CYCLE()						(g_pNandInfo->m_dev->m_hw_info.m_addr_cycle)
#define NUTL_IO_INTERFACE()						(g_pNandInfo->m_dev->m_hw_info.m_io_interface&NAND_IO_BITS_MASK)
#define NUTL_IO_INTERFACE_SYNC()				(g_pNandInfo->m_dev->m_hw_info.m_io_interface)
#define NUTL_PPAGE_VALID()						(g_pNandInfo->m_dev->m_mlc_setting)
#define NUTL_DEVICE_MLC()						(g_pNandInfo->m_dev->m_mlc_setting)
#define NUTL_PPAGE_TRANSLATE(x)					(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->m_ppage_tbl.table[x].low_page: x)
#define NUTL_PPAGE_HIGH_PAGE(x)					(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->m_ppage_tbl.table[x].high_page: x)
#define NUTL_DEVICE_TLC()						((g_pNandInfo->m_dev->m_tlc_setting) && (g_pNandInfo->m_dev->m_nand_type == NAND_FLASH_TLC))
#define NUTL_SET_FEATURE()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->set_feature: 			g_pNandInfo->m_dev->m_tlc_setting->set_feature)
#define NUTL_GET_FEATURE()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->get_feature: 			g_pNandInfo->m_dev->m_tlc_setting->get_feature)
#define NUTL_READ_RETRY_NUM()					(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->read_retry_num: 		0xFF)
#define NUTL_READ_RETRY_DEFAULT()				(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->read_retry_default: 	0xFF)
#define NUTL_READ_RETRY_ADDRESS()				(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->read_retry_address: 	0xFF)
#define NUTL_SYNC_ACCCON()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->acccon: 				g_pNandInfo->m_dev->m_tlc_setting->acccon)
#define NUTL_SYNC_ACCCON1()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->acccon1: 				g_pNandInfo->m_dev->m_tlc_setting->acccon1)
#define NUTL_SYNC_ADDR()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->interface_address: 	g_pNandInfo->m_dev->m_tlc_setting->interface_address)
#define NUTL_SYNC_VALUE()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->interface_sync: 		g_pNandInfo->m_dev->m_tlc_setting->interface_sync)
#define NUTL_ASYNC_VALUE()						(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->interface_async: 		g_pNandInfo->m_dev->m_tlc_setting->interface_async)
#define NUTL_DLY_MUX()							(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->dqs_mux: 				g_pNandInfo->m_dev->m_tlc_setting->dqs_mux)
#define NUTL_DLY_CTRL()							(g_pNandInfo->m_dev->m_mlc_setting != NULL?g_pNandInfo->m_dev->m_mlc_setting->dqs_ctrl: 			g_pNandInfo->m_dev->m_tlc_setting->dqs_ctrl)
#define NUTL_DEVICE_NAME()						(g_pNandInfo->m_dev->m_id)
#define NUTL_CELL_OFFSET()						((g_pNandInfo->m_dev->m_nand_type == NAND_FLASH_TLC)?3:2)
#define NUTL_CELL_ADJUST()						((g_pNandInfo->m_dev->m_nand_type == NAND_FLASH_TLC)?3:1)
#define NUTL_TLC_PSLC_MODE(x)					(g_pNandInfo->m_dev->m_tlc_setting->slcopmodeEn = x)

//------------------------------------------------------------------------------
// Row Address to Block Row Address                                             
//------------------------------------------------------------------------------
#define NUTL_RowAddrToBlockAddr(ra)				((ra)/NUTL_PAGES_PER_BLOCK()*NUTL_PAGES_PER_BLOCK())
#define NUTL_RowAddrToNextBlockAddr(ra)			(((ra)/NUTL_PAGES_PER_BLOCK()+1)*NUTL_PAGES_PER_BLOCK())
#define NUTL_RowAddrToCarryNextBlockAddr(ra)	((((ra)+NUTL_PAGES_PER_BLOCK()-1)/NUTL_PAGES_PER_BLOCK())*NUTL_PAGES_PER_BLOCK())

//------------------------------------------------------------------------------
// Absolute Address to Block Row Address                                        
//------------------------------------------------------------------------------
#define NUTL_AbsAddrToBlockAddr(abs_addr)			((abs_addr)/NUTL_BLOCK_SIZE()*NUTL_PAGES_PER_BLOCK())
#define NUTL_AbsAddrToNextBlockAddr(abs_addr)		(((abs_addr)/NUTL_BLOCK_SIZE()+1)*NUTL_PAGES_PER_BLOCK())
#define NUTL_AbsAddrToCarryNextBlockAddr(abs_addr)	((((abs_addr)+NUTL_BLOCK_SIZE()-1)/NUTL_BLOCK_SIZE())*NUTL_PAGES_PER_BLOCK())

//------------------------------------------------------------------------------
// NFI Initialization                                                           
//------------------------------------------------------------------------------
status_t  NUTL_NFI_Init(uint32  nfi_acccon, bool bEnableCS1);

//------------------------------------------------------------------------------
// NFI Enable Chip Select 1                                                     
//------------------------------------------------------------------------------
status_t  NUTL_NFI_SelectCS(bool bEnableCS1);

//------------------------------------------------------------------------------
// Set NFI Page Format                                                                 
//------------------------------------------------------------------------------
void  NUTL_NFI_SetPageFormat(void);

//------------------------------------------------------------------------------
// Check Device
//------------------------------------------------------------------------------
status_t  NUTL_CheckDevice(struct nand_info_struct* info);

//------------------------------------------------------------------------------
// Set NFI Parameter and Check BMT
//------------------------------------------------------------------------------
status_t  NUTL_NFI_Setting(struct nand_info_struct* info);

//------------------------------------------------------------------------------
// Find Good Block                                                              
//------------------------------------------------------------------------------
status_t  NUTL_FindGoodBlock(
			const uint32	c_timeout,
			uint32  		*p_row_addr
			);

//------------------------------------------------------------------------------
// Block Erase                                                                  
//------------------------------------------------------------------------------
status_t  NUTL_BlockErase(
			const uint32		c_timeout,
			const uint32		row_addr,
			nand_format_level	level
			);

status_t  NUTL_BlockEraseEx(
			const uint32		start_block,
			const uint32		last_block,
			uint32				*final_block
			);

//------------------------------------------------------------------------------
// Spare Area Compose/Decompose Related Function                                
//------------------------------------------------------------------------------
status_t  NUTL_SpareCompose(
			const uint32	ecc_parity_from_reg[8],
			uint32			*p_spare32 				/* MUST be 32bits alignment addr */
			);

status_t  NUTL_SpareDecompose(
			const uint32	*p_spare32, 		/* MUST be 32bits alignment addr */
			uint32			ecc_parity_from_spare[8]
			);

//------------------------------------------------------------------------------
// ECC Correction                                                               
//------------------------------------------------------------------------------
status_t  NUTL_ECC_Correction(
			const uint32	ecc_block_size,
			const uint32	ecc_parity_from_reg[8],
			const uint32	ecc_parity_from_spare[8],
			uint32			*p_data32 				/* MUST be 32bits alignment addr */
			);

//------------------------------------------------------------------------------
// Page Read                                                                    
//------------------------------------------------------------------------------
status_t  NUTL_PageRead(
			const uint32	c_timeout,
			const uint32	row_addr,
			uint32			*p_data32, 				/* MUST be 32bits alignment addr */
			uint32			*p_spare32, 				/* MUST be 32bits alignment addr */
			uint32			*ecc_parity_from_reg,
			uint32			*ecc_parity_from_spare,
			operation_type	flag
			);

//------------------------------------------------------------------------------
// Page Program Related Callback Function                                       
//------------------------------------------------------------------------------
status_t  NUTL_PageProgram(
			const uint32	c_timeout,
			const uint32	row_addr,
			const uint32	*p_data32, 		/* MUST be 32bits alignment addr */
			uint32			*p_spare32, 				/* MUST be 32bits alignment addr */
			uint32			ecc_parity_from_reg[8],
			uint32			ecc_parity_from_spare[8],
			NUTL_ProgramFlag_E	flag
			);

//------------------------------------------------------------------------------
// CopyBack                                                                     
//------------------------------------------------------------------------------
status_t  NUTL_CopyBack(
			const uint32	c_timeout,
			const uint32	src_row_addr,
			const uint32	dest_row_addr
			);

//------------------------------------------------------------------------------
// Block Replacement                                                            
//------------------------------------------------------------------------------
status_t  NUTL_BlockReplacement(
			const uint32	c_timeout,
			const uint32	src_row_addr, /* any row_addr within source block */
			const uint32	dest_row_addr, /* any row_addr within destination block */
			const uint32	err_page_index, /* page index within block, 1st page index is 0 */
			const uint32	*p_err_page_data32 /* MUST be 32bits alignment addr */
			);

status_t  NUTL_BlockCopy(
			const uint32	c_timeout,
			const uint32	src_row_addr, /* any row_addr within source block */
			const uint32 	dest_row_addr /* any row_addr within destination block */
			);

//------------------------------------------------------------------------------
// Range Validation                                                             
//------------------------------------------------------------------------------
status_t  NUTL_CheckRange(
			const uint64			absolute_addr,
			const uint64			length,
			const nand_addr_type	addr_type
			);

//------------------------------------------------------------------------------
//  ADD TTT
//------------------------------------------------------------------------------
status_t  NUTL_InitGlobalBuf(void);

status_t  NFB_BL_ECC_Encode(uint32* buff_ptr, uint8* parity_buff);

void  NUTL_NFI_GPIO_INIT(void);

status_t NUTL_DrvReset(const uint32  c_timeout);
status_t NUTL_DrvBlockCharge(const uint32 row_addr);

status_t NUTL_NFIv5_Randomizer_Config(bool use);
status_t NUTL_NFIv3_BadBlock_Check(
			const uint32		c_timeout,
			const uint32		row_addr
			);
status_t  NUTL_NFIv3_BlockErase(
			const uint32  		c_timeout,
			const uint32 		row_addr,
			nand_format_level	level
			);
status_t  NUTL_BlockProgram(
			const uint32		c_timeout,
			const uint32		row_addr,
			const uint32		*p_data32,
			uint32				*p_spare32,
			uint32				ecc_parity_from_reg[8],
			uint32				ecc_parity_from_spare[8],
			NUTL_ProgramFlag_E	flag
			);

status_t NUTL_Logic_BlockErase(
			const uint32		c_timeout,
			const uint32		row_addr,
			nand_format_level	level
			);

status_t NUTL_Logic_BlockProgram(
			const uint32		c_timeout,
			const uint32		row_addr,
			const uint32		*p_data32, /* MUST be 32bits alignment addr */
			uint32				*p_spare32, /* MUST be 32bits alignment addr */
			uint32				ecc_parity_from_reg[8],
			uint32				ecc_parity_from_spare[8],
			NUTL_ProgramFlag_E	flag
			);

status_t NUTL_Logic_PageProgram(
			const uint32		c_timeout,
			const uint32		row_addr,
			const uint32		*p_data32, /* MUST be 32bits alignment addr */
			uint32				*p_spare32, /* MUST be 32bits alignment addr */
			uint32				*ecc_parity_from_reg,
			uint32				*ecc_parity_from_spare,
			NUTL_ProgramFlag_E	flag
			);

status_t NUTL_Logic_PageRead(
			const uint32		c_timeout,
			const uint32		row_addr,
			uint32				*p_data32, /* MUST be 32bits alignment addr */
			uint32				*p_spare32, /* MUST be 32bits alignment addr */
			uint32				*ecc_parity_from_reg,
			uint32				*ecc_parity_from_spare,
			operation_type		op_type
			);


void NUTL_FLUSH_BMT();

//------------------------------------------------------------------------------
// Read/Erase/Write Blocks for SEC_RO, FLASHTOOL_CFG, CUST_PARA                                               
//------------------------------------------------------------------------------
extern status_t  NUTL_ReadBlocks(
				const uint32 len,
				const uint32 base_block,
				uint8 *p_buf
				);

extern status_t  NUTL_EraseBlocks(
				const uint32 len,
				const uint32 base_block
				);

extern status_t  NUTL_WriteBlocks(
				const uint32 len,
				const uint32 base_block,
				uint8 *p_buf
				);

extern status_t  NUTL_FindImageList(
				BOOTL_HEADER * p_bloader_header, 
				BOOTL_HEADER2 * p_bloader_header2, 
				NMAIN_ImageList_S * p_image_list
				);

extern status_t  NUTL_FindLastAvailableBlockAmongImages(
				bool bSecureMAUI,
				uint32 *p_lastblock
				);

extern status_t  NUTL_FindLastAvailableBlockAmongSecure(
				bool bSecureMAUI,
				uint32 *p_lastblock
				);

extern void NUTL_SetPageBuf8 (NAND_PageBuffer_U * p_pagebuf, uint8  **pp_page, uint8  **pp_spare);
extern void NUTL_SetPageBuf32(NAND_PageBuffer_U * p_pagebuf, uint32 **pp_page, uint32 **pp_spare);

extern status_t  NUTL_RandomRead(uint32 row_addr, uint32 col_addr, uint32 * output_buffer, uint32 read_size);
extern uint32	 NUTL_PageCopy(uint32 row_addr, uint32 * p_buf, uint32 buf_size);
extern uint32	 NUTL_PageCopy_Ex(uint32 row_addr, uint32 col_addr, uint32 * p_buf, uint32 buf_size);


extern NUTL_InternalTempBuf_S*		g_pPageRead_Var;
extern NUTL_InternalTempBuf_S*		g_pPageProgram_Var;

#ifdef __cplusplus
}
#endif

#endif