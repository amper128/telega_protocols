/**
 * @file vesc_proto.h
 * @author Алексей Хохлов <root@amper.me>
 * @copyright WTFPL License
 * @date 2021
 * @brief Описание протокола обмена по CAN-шине с контроллером VESC
 */

#pragma once

#include <stdint.h>

/**
 * @brief Типы сообщений в протоколе VESC с дополнениями
 */
typedef enum {
	VESC_CAN_PACKET_SET_DUTY = 0,
	VESC_CAN_PACKET_SET_CURRENT = 1,
	VESC_CAN_PACKET_SET_CURRENT_BRAKE = 2,
	VESC_CAN_PACKET_SET_RPM = 3,
	VESC_CAN_PACKET_SET_POS = 4,
	VESC_CAN_PACKET_FILL_RX_BUFFER = 5,
	VESC_CAN_PACKET_FILL_RX_BUFFER_LONG = 6,
	VESC_CAN_PACKET_PROCESS_RX_BUFFER = 7,
	VESC_CAN_PACKET_PROCESS_SHORT_BUFFER = 8,
	VESC_CAN_PACKET_STATUS = 9,
	VESC_CAN_PACKET_SET_CURRENT_REL = 10,
	VESC_CAN_PACKET_SET_CURRENT_BRAKE_REL = 11,
	VESC_CAN_PACKET_SET_CURRENT_HANDBRAKE = 12,
	VESC_CAN_PACKET_SET_CURRENT_HANDBRAKE_REL = 13,
	VESC_CAN_PACKET_STATUS_2 = 14,
	VESC_CAN_PACKET_STATUS_3 = 15,
	VESC_CAN_PACKET_STATUS_4 = 16,
	VESC_CAN_PACKET_PING = 17,
	VESC_CAN_PACKET_PONG = 18,
	VESC_CAN_PACKET_DETECT_APPLY_ALL_FOC = 19,
	VESC_CAN_PACKET_DETECT_APPLY_ALL_FOC_RES = 20,
	VESC_CAN_PACKET_CONF_CURRENT_LIMITS = 21,
	VESC_CAN_PACKET_CONF_STORE_CURRENT_LIMITS = 22,
	VESC_CAN_PACKET_CONF_CURRENT_LIMITS_IN = 23,
	VESC_CAN_PACKET_CONF_STORE_CURRENT_LIMITS_IN = 24,
	VESC_CAN_PACKET_CONF_FOC_ERPMS = 25,
	VESC_CAN_PACKET_CONF_STORE_FOC_ERPMS = 26,
	VESC_CAN_PACKET_STATUS_5 = 27,

	/* дополнения протокола для управления светом */
	LIGHT_CAN_PACKET_SYNC = 100,
	LIGHT_CAN_PACKET_SET_MODE = 101,
	LIGHT_CAN_PACKET_SET_COLOR = 102,
	LIGHT_CAN_PACKET_SET_BRIGHTNESS = 103,
	LIGHT_CAN_PACKET_SET_PERIOD = 104
} vesc_msg_type_t;

/**
 * @brief Режимы работы света
 */
typedef enum {
	LEDS_MODE_FADING = 0,
	LEDS_MODE_STATIC_COLOR = 1,
	LEDS_MODE_RUNNING_SHAPE = 2,
	LEDS_MODE_BLINKING = 3,
	LEDS_MODE_FLASHING = 4,
	LEDS_MODE_POLICE = 5,
	LEDS_MODE_MAX
} leds_mode_t;

/**
 * @brief Структура заголовка CAN пакета
 */
typedef struct {
	uint8_t id;		/**< @brief адрес получателя */
	uint8_t cmd;		/**< @brief id команды @vesc_msg_type_t */
	uint8_t __reserved[2U]; /**< @brief не используется */
} __attribute__((packed)) can_hdr_t;
