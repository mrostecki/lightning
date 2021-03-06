/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_GOSSIPD_GOSSIPD_PEERD_WIREGEN_H
#define LIGHTNING_GOSSIPD_GOSSIPD_PEERD_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <bitcoin/short_channel_id.h>
#include <common/amount.h>
#include <common/node_id.h>

enum gossipd_peerd_wire {
        /*  Channel daemon can ask for updates for a specific channel */
        /*  errors. */
        WIRE_GOSSIPD_GET_UPDATE = 3501,
        /*  If channel isn't known */
        WIRE_GOSSIPD_GET_UPDATE_REPLY = 3601,
        /*  Both sides have seen the funding tx being locked */
        /*  yet reached the announcement depth. So we add the channel locally so */
        /*  we (and peer) can update it already. */
        WIRE_GOSSIPD_LOCAL_ADD_CHANNEL = 3503,
        /*  Send this channel_update. */
        WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE = 3504,
        /*  Update your gossip_store fd: + gossip_store_fd */
        WIRE_GOSSIPD_NEW_STORE_FD = 3505,
        /*  Send this channel_announcement */
        WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT = 3506,
};

const char *gossipd_peerd_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool gossipd_peerd_wire_is_defined(u16 type);


/* WIRE: GOSSIPD_GET_UPDATE */
/*  Channel daemon can ask for updates for a specific channel */
/*  errors. */
u8 *towire_gossipd_get_update(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_get_update(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_GET_UPDATE_REPLY */
/*  If channel isn't known */
u8 *towire_gossipd_get_update_reply(const tal_t *ctx, const u8 *update);
bool fromwire_gossipd_get_update_reply(const tal_t *ctx, const void *p, u8 **update);

/* WIRE: GOSSIPD_LOCAL_ADD_CHANNEL */
/*  Both sides have seen the funding tx being locked */
/*  yet reached the announcement depth. So we add the channel locally so */
/*  we (and peer) can update it already. */
u8 *towire_gossipd_local_add_channel(const tal_t *ctx, const struct short_channel_id *short_channel_id, const struct node_id *remote_node_id, struct amount_sat satoshis, const u8 *features);
bool fromwire_gossipd_local_add_channel(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct node_id *remote_node_id, struct amount_sat *satoshis, u8 **features);

/* WIRE: GOSSIPD_LOCAL_CHANNEL_UPDATE */
/*  Send this channel_update. */
u8 *towire_gossipd_local_channel_update(const tal_t *ctx, const struct short_channel_id *short_channel_id, bool disable, u16 cltv_expiry_delta, struct amount_msat htlc_minimum_msat, u32 fee_base_msat, u32 fee_proportional_millionths, struct amount_msat htlc_maximum_msat);
bool fromwire_gossipd_local_channel_update(const void *p, struct short_channel_id *short_channel_id, bool *disable, u16 *cltv_expiry_delta, struct amount_msat *htlc_minimum_msat, u32 *fee_base_msat, u32 *fee_proportional_millionths, struct amount_msat *htlc_maximum_msat);

/* WIRE: GOSSIPD_NEW_STORE_FD */
/*  Update your gossip_store fd: + gossip_store_fd */
u8 *towire_gossipd_new_store_fd(const tal_t *ctx, u64 offset_shorter);
bool fromwire_gossipd_new_store_fd(const void *p, u64 *offset_shorter);

/* WIRE: GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT */
/*  Send this channel_announcement */
u8 *towire_gossipd_local_channel_announcement(const tal_t *ctx, const u8 *cannount);
bool fromwire_gossipd_local_channel_announcement(const tal_t *ctx, const void *p, u8 **cannount);


#endif /* LIGHTNING_GOSSIPD_GOSSIPD_PEERD_WIREGEN_H */
// SHA256STAMP:4a051b84f9c7bf5033cce47837e80b64aad358218b02a2b5f8e93f52e8c41423
