// Copyright (c) 2013 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  This file is automatically generated
//               These definitions are tied to a particular hardware layout


#ifndef _PS_POLL_RESPONSE_H_
#define _PS_POLL_RESPONSE_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	valid_ps_poll_queue_bitmap[9:0], datanull_resp_required[10], rr_qid_selection[11], fes_control_mode[13:12], reserved_0[31:14]
//	1	resp_mpdu_queue0[13:0], reserved_1a[15:14], resp_mpdu_queue1[29:16], reserved_1b[31:30]
//	2	resp_mpdu_queue2[13:0], reserved_2a[15:14], resp_mpdu_queue3[29:16], reserved_2b[31:30]
//	3	resp_mpdu_queue4[13:0], reserved_3a[15:14], resp_mpdu_queue5[29:16], reserved_3b[31:30]
//	4	resp_mpdu_queue6[13:0], reserved_4a[15:14], resp_mpdu_queue7[29:16], reserved_4b[31:30]
//	5	resp_mpdu_queue8[13:0], reserved_5a[15:14], resp_mpdu_queue9[29:16], reserved_5b[31:30]
//	6	scheduler_tlv_ptr[31:0]
//	7	next_q_bitmap_id_to_evaluate[3:0], reserved_7[31:4]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_PS_POLL_RESPONSE 8

struct ps_poll_response {
    volatile uint32_t valid_ps_poll_queue_bitmap      : 10, //[9:0]
                      datanull_resp_required          :  1, //[10]
                      rr_qid_selection                :  1, //[11]
                      fes_control_mode                :  2, //[13:12]
                      reserved_0                      : 18; //[31:14]
    volatile uint32_t resp_mpdu_queue0                : 14, //[13:0]
                      reserved_1a                     :  2, //[15:14]
                      resp_mpdu_queue1                : 14, //[29:16]
                      reserved_1b                     :  2; //[31:30]
    volatile uint32_t resp_mpdu_queue2                : 14, //[13:0]
                      reserved_2a                     :  2, //[15:14]
                      resp_mpdu_queue3                : 14, //[29:16]
                      reserved_2b                     :  2; //[31:30]
    volatile uint32_t resp_mpdu_queue4                : 14, //[13:0]
                      reserved_3a                     :  2, //[15:14]
                      resp_mpdu_queue5                : 14, //[29:16]
                      reserved_3b                     :  2; //[31:30]
    volatile uint32_t resp_mpdu_queue6                : 14, //[13:0]
                      reserved_4a                     :  2, //[15:14]
                      resp_mpdu_queue7                : 14, //[29:16]
                      reserved_4b                     :  2; //[31:30]
    volatile uint32_t resp_mpdu_queue8                : 14, //[13:0]
                      reserved_5a                     :  2, //[15:14]
                      resp_mpdu_queue9                : 14, //[29:16]
                      reserved_5b                     :  2; //[31:30]
    volatile uint32_t scheduler_tlv_ptr               : 32; //[31:0]
    volatile uint32_t next_q_bitmap_id_to_evaluate    :  4, //[3:0]
                      reserved_7                      : 28; //[31:4]
};

/*

valid_ps_poll_queue_bitmap
			
			Valid response queue bitmap in case a PS-POLL frame was
			received.
			
			
			
			The bitmap indicates which of the following QIDs are
			valid and a PSPOLL response data frame is allowed to be
			fetched from this queue.
			
			
			
			The scheduler will evaluate the valid MPDU queues one at
			a time (starting from Resp_mpdu_queue0) and data will be
			transmitted from the first queue found that has data. 
			
			If RR_qid_selection is set, the search for a queue with
			data will start from queue_bitmap indicated by
			Next_q_bitmap_id_to_evaluate, and walk through all the QID.
			This allows for a Round Robin queue assignment mechanism.
			
			
			
			The scheduler will also check if the other valid data
			queues have some data and if so, set the
			other_queues_more_data bit in the PDG setup TLV. This info
			is needed by the PCU to determine what the setting for the
			More data bit in the FC field of the transmitted frame needs
			to be.
			
			
			
			When all queues are empty, no data will be sent back.
			Depending on the setting of DataNull_resp_required, only a
			Data Null frame will be sent instead.
			
			
			
			When transmitting data from a queue, and
			RR_qid_selection is set, the scheduler will update the field
			Next_q_bitmap_id_to_evaluate field at the end of a
			successful transmission, to ensure that on reception of the
			next PS-poll frame, the scheduler starts the search from the
			next queue_bitmap entry.
			
			 <legal all>

datanull_resp_required
			
			0: No action
			
			1: Transmit a Data Null frame when all enabled response
			mpdu queues are empty.
			
			The QID used the transmit command will be the first
			valid QID.
			
			<legal all>

rr_qid_selection
			
			Round Robin QueueID selection
			
			When set, the Scheduler will transmit from queues in a
			Round Robin method, always remembering that after
			transmission from a queue, the scheduler should try and
			transmit from the next queue first.
			
			For this it updates the Next_q_bitmap_id_to_evaluate
			field after each successful transmission.
			
			<legal all>

fes_control_mode
			
			1-0: Reserved
			
			2: SW initiated transmission (initiated by SIFS response
			table) For this setting the scheduler will NOT perform any
			checks with the QM. SW has preprogrammed the entire response
			(data frames or a NULL frame) in the scheduling command.
			
			3: HW initiated transmission (initiated by SIFS response
			table) For this setting the scheduler will perform all the
			MPDU queue checks with the QM. Based on the result of those
			checks and other settings in this descriptor, the scheduler
			might initiate a data transmission, null transmission or not
			initiate a transmission at all.
			
			<legal 3-2>

reserved_0
			
			<legal 0>

resp_mpdu_queue0
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_1a
			
			<legal 0>

resp_mpdu_queue1
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_1b
			
			<legal 0>

resp_mpdu_queue2
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_2a
			
			<legal 0>

resp_mpdu_queue3
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_2b
			
			<legal 0>

resp_mpdu_queue4
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_3a
			
			<legal 0>

resp_mpdu_queue5
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_3b
			
			<legal 0>

resp_mpdu_queue6
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_4a
			
			<legal 0>

resp_mpdu_queue7
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_4b
			
			<legal 0>

resp_mpdu_queue8
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_5a
			
			<legal 0>

resp_mpdu_queue9
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>

reserved_5b
			
			<legal 0>

scheduler_tlv_ptr
			
			The address location for the transmit TLVs.
			
			These TLVs get read/interpreted by the scheduler and
			when applicable pushed down the transmit chain to the other
			transmit modules. 
			
			<legal all>

next_q_bitmap_id_to_evaluate
			
			Only valid when RR_qid_selection is set.
			
			
			
			This field indicates the next queue bitmap id from which
			the scheduler should try to transmit first on reception of a
			new PS-POLL frame.
			
			
			
			This field is put in a separate word, as HW will update
			this field on regular basis.
			
			<legal 9-0>

reserved_7
			
			<legal 0>
*/


/* Description		PS_POLL_RESPONSE_0_VALID_PS_POLL_QUEUE_BITMAP
			
			Valid response queue bitmap in case a PS-POLL frame was
			received.
			
			
			
			The bitmap indicates which of the following QIDs are
			valid and a PSPOLL response data frame is allowed to be
			fetched from this queue.
			
			
			
			The scheduler will evaluate the valid MPDU queues one at
			a time (starting from Resp_mpdu_queue0) and data will be
			transmitted from the first queue found that has data. 
			
			If RR_qid_selection is set, the search for a queue with
			data will start from queue_bitmap indicated by
			Next_q_bitmap_id_to_evaluate, and walk through all the QID.
			This allows for a Round Robin queue assignment mechanism.
			
			
			
			The scheduler will also check if the other valid data
			queues have some data and if so, set the
			other_queues_more_data bit in the PDG setup TLV. This info
			is needed by the PCU to determine what the setting for the
			More data bit in the FC field of the transmitted frame needs
			to be.
			
			
			
			When all queues are empty, no data will be sent back.
			Depending on the setting of DataNull_resp_required, only a
			Data Null frame will be sent instead.
			
			
			
			When transmitting data from a queue, and
			RR_qid_selection is set, the scheduler will update the field
			Next_q_bitmap_id_to_evaluate field at the end of a
			successful transmission, to ensure that on reception of the
			next PS-poll frame, the scheduler starts the search from the
			next queue_bitmap entry.
			
			 <legal all>
*/
#define PS_POLL_RESPONSE_0_VALID_PS_POLL_QUEUE_BITMAP_OFFSET         0x00000000
#define PS_POLL_RESPONSE_0_VALID_PS_POLL_QUEUE_BITMAP_LSB            0
#define PS_POLL_RESPONSE_0_VALID_PS_POLL_QUEUE_BITMAP_MASK           0x000003ff

/* Description		PS_POLL_RESPONSE_0_DATANULL_RESP_REQUIRED
			
			0: No action
			
			1: Transmit a Data Null frame when all enabled response
			mpdu queues are empty.
			
			The QID used the transmit command will be the first
			valid QID.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_0_DATANULL_RESP_REQUIRED_OFFSET             0x00000000
#define PS_POLL_RESPONSE_0_DATANULL_RESP_REQUIRED_LSB                10
#define PS_POLL_RESPONSE_0_DATANULL_RESP_REQUIRED_MASK               0x00000400

/* Description		PS_POLL_RESPONSE_0_RR_QID_SELECTION
			
			Round Robin QueueID selection
			
			When set, the Scheduler will transmit from queues in a
			Round Robin method, always remembering that after
			transmission from a queue, the scheduler should try and
			transmit from the next queue first.
			
			For this it updates the Next_q_bitmap_id_to_evaluate
			field after each successful transmission.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_0_RR_QID_SELECTION_OFFSET                   0x00000000
#define PS_POLL_RESPONSE_0_RR_QID_SELECTION_LSB                      11
#define PS_POLL_RESPONSE_0_RR_QID_SELECTION_MASK                     0x00000800

/* Description		PS_POLL_RESPONSE_0_FES_CONTROL_MODE
			
			1-0: Reserved
			
			2: SW initiated transmission (initiated by SIFS response
			table) For this setting the scheduler will NOT perform any
			checks with the QM. SW has preprogrammed the entire response
			(data frames or a NULL frame) in the scheduling command.
			
			3: HW initiated transmission (initiated by SIFS response
			table) For this setting the scheduler will perform all the
			MPDU queue checks with the QM. Based on the result of those
			checks and other settings in this descriptor, the scheduler
			might initiate a data transmission, null transmission or not
			initiate a transmission at all.
			
			<legal 3-2>
*/
#define PS_POLL_RESPONSE_0_FES_CONTROL_MODE_OFFSET                   0x00000000
#define PS_POLL_RESPONSE_0_FES_CONTROL_MODE_LSB                      12
#define PS_POLL_RESPONSE_0_FES_CONTROL_MODE_MASK                     0x00003000

/* Description		PS_POLL_RESPONSE_0_RESERVED_0
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_0_RESERVED_0_OFFSET                         0x00000000
#define PS_POLL_RESPONSE_0_RESERVED_0_LSB                            14
#define PS_POLL_RESPONSE_0_RESERVED_0_MASK                           0xffffc000

/* Description		PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE0
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE0_OFFSET                   0x00000004
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE0_LSB                      0
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE0_MASK                     0x00003fff

/* Description		PS_POLL_RESPONSE_1_RESERVED_1A
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_1_RESERVED_1A_OFFSET                        0x00000004
#define PS_POLL_RESPONSE_1_RESERVED_1A_LSB                           14
#define PS_POLL_RESPONSE_1_RESERVED_1A_MASK                          0x0000c000

/* Description		PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE1
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE1_OFFSET                   0x00000004
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE1_LSB                      16
#define PS_POLL_RESPONSE_1_RESP_MPDU_QUEUE1_MASK                     0x3fff0000

/* Description		PS_POLL_RESPONSE_1_RESERVED_1B
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_1_RESERVED_1B_OFFSET                        0x00000004
#define PS_POLL_RESPONSE_1_RESERVED_1B_LSB                           30
#define PS_POLL_RESPONSE_1_RESERVED_1B_MASK                          0xc0000000

/* Description		PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE2
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE2_OFFSET                   0x00000008
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE2_LSB                      0
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE2_MASK                     0x00003fff

/* Description		PS_POLL_RESPONSE_2_RESERVED_2A
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_2_RESERVED_2A_OFFSET                        0x00000008
#define PS_POLL_RESPONSE_2_RESERVED_2A_LSB                           14
#define PS_POLL_RESPONSE_2_RESERVED_2A_MASK                          0x0000c000

/* Description		PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE3
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE3_OFFSET                   0x00000008
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE3_LSB                      16
#define PS_POLL_RESPONSE_2_RESP_MPDU_QUEUE3_MASK                     0x3fff0000

/* Description		PS_POLL_RESPONSE_2_RESERVED_2B
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_2_RESERVED_2B_OFFSET                        0x00000008
#define PS_POLL_RESPONSE_2_RESERVED_2B_LSB                           30
#define PS_POLL_RESPONSE_2_RESERVED_2B_MASK                          0xc0000000

/* Description		PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE4
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE4_OFFSET                   0x0000000c
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE4_LSB                      0
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE4_MASK                     0x00003fff

/* Description		PS_POLL_RESPONSE_3_RESERVED_3A
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_3_RESERVED_3A_OFFSET                        0x0000000c
#define PS_POLL_RESPONSE_3_RESERVED_3A_LSB                           14
#define PS_POLL_RESPONSE_3_RESERVED_3A_MASK                          0x0000c000

/* Description		PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE5
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE5_OFFSET                   0x0000000c
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE5_LSB                      16
#define PS_POLL_RESPONSE_3_RESP_MPDU_QUEUE5_MASK                     0x3fff0000

/* Description		PS_POLL_RESPONSE_3_RESERVED_3B
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_3_RESERVED_3B_OFFSET                        0x0000000c
#define PS_POLL_RESPONSE_3_RESERVED_3B_LSB                           30
#define PS_POLL_RESPONSE_3_RESERVED_3B_MASK                          0xc0000000

/* Description		PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE6
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE6_OFFSET                   0x00000010
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE6_LSB                      0
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE6_MASK                     0x00003fff

/* Description		PS_POLL_RESPONSE_4_RESERVED_4A
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_4_RESERVED_4A_OFFSET                        0x00000010
#define PS_POLL_RESPONSE_4_RESERVED_4A_LSB                           14
#define PS_POLL_RESPONSE_4_RESERVED_4A_MASK                          0x0000c000

/* Description		PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE7
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE7_OFFSET                   0x00000010
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE7_LSB                      16
#define PS_POLL_RESPONSE_4_RESP_MPDU_QUEUE7_MASK                     0x3fff0000

/* Description		PS_POLL_RESPONSE_4_RESERVED_4B
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_4_RESERVED_4B_OFFSET                        0x00000010
#define PS_POLL_RESPONSE_4_RESERVED_4B_LSB                           30
#define PS_POLL_RESPONSE_4_RESERVED_4B_MASK                          0xc0000000

/* Description		PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE8
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE8_OFFSET                   0x00000014
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE8_LSB                      0
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE8_MASK                     0x00003fff

/* Description		PS_POLL_RESPONSE_5_RESERVED_5A
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_5_RESERVED_5A_OFFSET                        0x00000014
#define PS_POLL_RESPONSE_5_RESERVED_5A_LSB                           14
#define PS_POLL_RESPONSE_5_RESERVED_5A_MASK                          0x0000c000

/* Description		PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE9
			
			
			
			
			The QID of an MPDU queue from which PS-POLL response
			data can be sent.
			
			<legal all>
*/
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE9_OFFSET                   0x00000014
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE9_LSB                      16
#define PS_POLL_RESPONSE_5_RESP_MPDU_QUEUE9_MASK                     0x3fff0000

/* Description		PS_POLL_RESPONSE_5_RESERVED_5B
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_5_RESERVED_5B_OFFSET                        0x00000014
#define PS_POLL_RESPONSE_5_RESERVED_5B_LSB                           30
#define PS_POLL_RESPONSE_5_RESERVED_5B_MASK                          0xc0000000

/* Description		PS_POLL_RESPONSE_6_SCHEDULER_TLV_PTR
			
			The address location for the transmit TLVs.
			
			These TLVs get read/interpreted by the scheduler and
			when applicable pushed down the transmit chain to the other
			transmit modules. 
			
			<legal all>
*/
#define PS_POLL_RESPONSE_6_SCHEDULER_TLV_PTR_OFFSET                  0x00000018
#define PS_POLL_RESPONSE_6_SCHEDULER_TLV_PTR_LSB                     0
#define PS_POLL_RESPONSE_6_SCHEDULER_TLV_PTR_MASK                    0xffffffff

/* Description		PS_POLL_RESPONSE_7_NEXT_Q_BITMAP_ID_TO_EVALUATE
			
			Only valid when RR_qid_selection is set.
			
			
			
			This field indicates the next queue bitmap id from which
			the scheduler should try to transmit first on reception of a
			new PS-POLL frame.
			
			
			
			This field is put in a separate word, as HW will update
			this field on regular basis.
			
			<legal 9-0>
*/
#define PS_POLL_RESPONSE_7_NEXT_Q_BITMAP_ID_TO_EVALUATE_OFFSET       0x0000001c
#define PS_POLL_RESPONSE_7_NEXT_Q_BITMAP_ID_TO_EVALUATE_LSB          0
#define PS_POLL_RESPONSE_7_NEXT_Q_BITMAP_ID_TO_EVALUATE_MASK         0x0000000f

/* Description		PS_POLL_RESPONSE_7_RESERVED_7
			
			<legal 0>
*/
#define PS_POLL_RESPONSE_7_RESERVED_7_OFFSET                         0x0000001c
#define PS_POLL_RESPONSE_7_RESERVED_7_LSB                            4
#define PS_POLL_RESPONSE_7_RESERVED_7_MASK                           0xfffffff0


#endif // _PS_POLL_RESPONSE_H_
