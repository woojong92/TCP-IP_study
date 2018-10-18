#include <stdio.h>
#include <stdint.h>

typedef struct packet1 {
	uint8_t header;
	uint32_t payload;
	uint16_t tailer;
}packet1;

typedef struct packet2 {
    uint16_t tailer;
	uint8_t header;
    uint32_t payload;
}packet2;


typedef struct packet3 {
	uint8_t header;
    uint32_t payload;
    uint16_t tailer;
}__attribute__((packed))packet3;



int main() {
	printf("packet1 size: %d packet2 size: %d  packet3 size: %d\n",
			sizeof(packet1),sizeof(packet2),sizeof(packet3));
	return 0;
}
