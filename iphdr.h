#pragma once

#include <arpa/inet.h>

struct Ip final {
    uint8_t ip_[4];

    Ip() {}
    Ip(const uint8_t *ip) { memcpy(this->ip_, ip, sizeof(this->ip_)); }
    Ip(const char *ip);

    operator uint8_t*() { return ip_; }
    operator const uint8_t*() const { return ip_; }
};

struct IpHdr final {
    uint8_t vhl_;
    uint8_t tos_;
    uint16_t len_;
    uint16_t id_;
    uint16_t off_;
    uint8_t ttl_;
    uint8_t p_;
    uint16_t checksum_;
    Ip sip_;
    Ip dip_;

    uint8_t hdrLen() const { return (vhl_ & 0xf) << 2; }
    uint16_t len() const { return ntohs(len_); }
    uint8_t protocol() const { return p_; }

    uint16_t checksum() {
        // Calculate checksum here and return
    }
};

