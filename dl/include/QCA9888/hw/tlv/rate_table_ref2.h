// Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  This file is automatically generated
//               These definitions are tied to a particular hardware layout


#ifndef _RATE_TABLE_REF2_H_
#define _RATE_TABLE_REF2_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	rate_table_address[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RATE_TABLE_REF2 1

struct rate_table_ref2 {
    volatile uint32_t rate_table_address              : 32; //[31:0]
};

/*

rate_table_address
			
			The physical address of the rate table in memory.
*/


/* Description		RATE_TABLE_REF2_0_RATE_TABLE_ADDRESS
			
			The physical address of the rate table in memory.
*/
#define RATE_TABLE_REF2_0_RATE_TABLE_ADDRESS_OFFSET                  0x00000000
#define RATE_TABLE_REF2_0_RATE_TABLE_ADDRESS_LSB                     0
#define RATE_TABLE_REF2_0_RATE_TABLE_ADDRESS_MASK                    0xffffffff


#endif // _RATE_TABLE_REF2_H_
