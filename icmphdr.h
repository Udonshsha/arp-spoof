#pragma once

#include <arpa/inet.h>

struct IcmpHdr final {
    uint8_t type_;
    uint8_t code_;
    uint16_t checksum_;
    uint16_t id_;
    uint16_t seq_;

    uint8_t type() const { return type_; }

    // Type constants
    enum: uint8_t {
        EchoReply = 0,
        EchoRequest = 8
    };

    uint16_t checksum() {
        // Calculate checksum here and return
    }
};
