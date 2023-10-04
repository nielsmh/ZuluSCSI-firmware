/*
 * Copyright (c) 2023 joshua stein <jcs@jcs.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#ifdef ZULUSCSI_NETWORK

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

struct __attribute__((packed)) wifi_network_entry {
	char ssid[64];
	char bssid[6];
	int8_t rssi;
	uint8_t channel;
	uint8_t flags;
	uint8_t _padding;
#define WIFI_NETWORK_FLAGS_AUTH 0x1
};

#define WIFI_NETWORK_LIST_ENTRY_COUNT 10
extern struct wifi_network_entry wifi_network_list[WIFI_NETWORK_LIST_ENTRY_COUNT];

struct __attribute__((packed)) wifi_join_request {
	char ssid[64];
	char key[64];
	uint8_t channel;
	uint8_t _padding;
};

bool platform_network_supported();
void platform_network_poll();
int platform_network_init(char *mac);
void platform_network_add_multicast_address(uint8_t *mac);
bool platform_network_wifi_join(char *ssid, char *password);
int platform_network_wifi_start_scan();
int platform_network_wifi_scan_finished();
void platform_network_wifi_dump_scan_list();
int platform_network_wifi_rssi();
char * platform_network_wifi_ssid();
char * platform_network_wifi_bssid();
int platform_network_wifi_channel();

# ifdef __cplusplus
}
# endif

#endif // ZULUSCSI_NETWORK