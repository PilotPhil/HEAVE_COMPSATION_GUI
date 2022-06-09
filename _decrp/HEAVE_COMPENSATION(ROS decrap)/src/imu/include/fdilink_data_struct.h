#ifndef FDILINK_DATA_STRUCT_H_
#define FDILINK_DATA_STRUCT_H_

#include <iostream>
namespace FDILink
{
#pragma pack(1)
	struct fdilink_header
	{
		uint8_t header_start;
		uint8_t data_type;
		uint8_t data_size;
		uint8_t serial_num;
		uint8_t header_crc8;
		uint8_t header_crc16_h;
		uint8_t header_crc16_l;
	};
#pragma pack()


#pragma pack(1)
	struct BODY_VEL_Packet_t
	{
		float vel_x;
		float vel_y;
		float vel_z;
	};
#pragma pack()


#pragma pack(1)
	struct read_body_vel_struct
	{
		fdilink_header header; //7
		
		union data
		{
			BODY_VEL_Packet_t data_pack; // 12
			u_int8_t data_buff[12];
		} data;

		uint8_t frame_end;//1
	};

	struct read_body_vel_tmp
	{
		uint8_t frame_header[7];
		uint8_t read_msg[13];
	};

	union body_vel_frame_read
	{
		struct read_body_vel_struct frame;
		read_body_vel_tmp read_buf;
		uint8_t read_tmp[20];
	};

#pragma pack()
} // namespace FDILink
#endif // FDILINK_DATA_STRUCT_H_
