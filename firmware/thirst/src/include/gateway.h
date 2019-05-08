#ifndef GATEWAY_H
#define GATEWAY_H

#define GATEWAY_PORT 443
#define GATEWAY_HOST "api.sendgrid.com"

#define GATEWAY_TLS_BUFFER_SIZE  8192
#define GATEWAY_SIZE_SEND_BUFFER 4096

#define GATEWAY_HTTP_CODE_ACCEPTED 202

#ifndef GATEWAY_KEY
	#define GATEWAY_KEY "" // Defined at compile time.
#endif

#define GATEWAY_FMT_NOTIFICATION_HTTP_HEADER \
"POST /v3/mail/send HTTP/1.1\r\n\
Host: %s\r\n\
Accept: application/json; charset=utf-8\r\n\
Content-Type: application/json; charset=utf-8\r\n\
Content-Length: %d\r\n\
Cache-Control: no-cache\r\n\
Authorization: Bearer %s\r\n\
\r\n\
%s"

#define GATEWAY_FMT_NOTIFICATION_HTTP_DATA_JSON \
"{\
\"personalizations\":\
[\
{\
\"to\":\
[\
{\
\"email\":\"%s\"\
}\
],\
\"subject\":\"%s\"\
}\
],\
\"from\":\
{\
\"email\":\"notifications@thirst.v3\",\
\"name\":\"%s\"\
},\
\"content\":\
[\
{\
\"type\":\"text/plain\",\
\"value\":\"%s\"\
}\
]\
}"

void ICACHE_FLASH_ATTR
gateway_cb_sock_rx(
	void* arg,
	char* data,
	unsigned short length
);

void ICACHE_FLASH_ATTR
gateway_cb_dns_resolved(
	const char* hostname,
	ip_addr_t* ip_resolved,
	void* arg
);

void ICACHE_FLASH_ATTR
gateway_cb_timeout_rx(void);

void ICACHE_FLASH_ATTR
gateway_cb_sock_tx(void* arg);

void ICACHE_FLASH_ATTR
gateway_cb_sock_connect(void* arg);

void ICACHE_FLASH_ATTR
gateway_cb_sock_disconnect(void* arg);

#endif // GATEWAY_H