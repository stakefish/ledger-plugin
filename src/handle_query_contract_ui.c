#include "plugin.h"

static bool set_main_ui(ethQueryContractUI_t *msg, context_t *context) {
    switch (context->selectorIndex) {
        case BATCH_DEPOSIT: 
            strlcpy(msg->title, "Classic Staking", msg->titleLength);
            
            const uint8_t *eth_amount = msg->pluginSharedRO->txContent->value.value;
            uint8_t eth_amount_size = msg->pluginSharedRO->txContent->value.length;

            // Converts the uint256 number located in `eth_amount` to its string representation and
            // copies this to `msg->msg`.
            return amountToString(
                eth_amount,
                eth_amount_size,
                WEI_TO_ETHER,
                "ETH",
                msg->msg,
                msg->msgLength
            );
            break;
        case BATCH_COLLECT_REWARD:
            strlcpy(msg->title, "Collect", msg->titleLength);
            strlcpy(msg->msg, "Rewards", msg->msgLength);
            break;
        case MINT:
            strlcpy(msg->title, "Mint NFTs", msg->titleLength);
            return amountToString(
                context->nfts,
                sizeof(context->nfts),
                0,
                "Amount:",
                msg->msg,
                msg->msgLength
            );
            break;
        case REQUEST_EXIT:
            strlcpy(msg->title, "Request", msg->titleLength);
            strlcpy(msg->msg, "exit", msg->msgLength);
            break;
        case COLLECT_REWARD:
            strlcpy(msg->title, "Beneficiary", msg->titleLength);

            // Prefix the address with `0x`.
            msg->msg[0] = '0';
            msg->msg[1] = 'x';

            // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
            // Setting it to `0` will make it work with every chainID :)
            uint64_t chainid = 0;

            // Get the string representation of the address stored in `context->beneficiary`. Put it in
            // `msg->msg`.
            return getEthAddressStringFromBinary(
                context->beneficiary,
                msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
                msg->pluginSharedRW->sha3,
                chainid);
            break;
        case COLLECT_REWARD_FOR_NFT:
            strlcpy(msg->title, "Beneficiary", msg->titleLength);

            // Prefix the address with `0x`.
            msg->msg[0] = '0';
            msg->msg[1] = 'x';

            // Get the string representation of the address stored in `context->beneficiary`. Put it in
            // `msg->msg`.
            return getEthAddressStringFromBinary(
                context->beneficiary,
                msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
                msg->pluginSharedRW->sha3,
                0
            );
            break;
        default:
            strlcpy(msg->title, "Method not", msg->titleLength);
            strlcpy(msg->msg, "supported", msg->msgLength);
    }
    return true;
}

static bool set_second_screen_ui(ethQueryContractUI_t *msg, const context_t *context) {
    switch (context->selectorIndex) {
        case COLLECT_REWARD:
            strlcpy(msg->title, "Requested", msg->titleLength);
            return amountToString(
                context->amount_requested,
                sizeof(context->amount_requested),
                0,
                "",
                msg->msg,
                msg->msgLength
            );
            break;
        case COLLECT_REWARD_FOR_NFT:
            strlcpy(msg->title, "NFT Wallet", msg->titleLength);

            // Prefix the address with `0x`.
            msg->msg[0] = '0';
            msg->msg[1] = 'x';

            // Get the string representation of the address stored in `context->beneficiary`. Put it in
            // `msg->msg`.
            return getEthAddressStringFromBinary(
                context->nft_wallet,
                msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
                msg->pluginSharedRW->sha3,
                0
            );
            break;
        default:
            strlcpy(msg->title, "Method not", msg->titleLength);
            strlcpy(msg->msg, "supported", msg->msgLength);
    }
    return true;
}

static bool set_third_screen_ui(ethQueryContractUI_t *msg, const context_t *context) {
    strlcpy(msg->title, "Requested", msg->titleLength);
    return amountToString(
        context->amount_requested,
        sizeof(context->amount_requested),
        0,
        "",
        msg->msg,
        msg->msgLength
    );
}


void handle_query_contract_ui(ethQueryContractUI_t *msg) {
    bool ret = false;
    context_t *context = (context_t *) msg->pluginContext;

    // msg->title is the upper line displayed on the device.
    // msg->msg is the lower line displayed on the device.

    // Clean the display fields.
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);

    // EDIT THIS: Adapt the cases for the screens you'd like to display.
    switch (msg->screenIndex) {
        case 0:
            ret = set_main_ui(msg, context);
            break;
        case 1:
            ret = set_second_screen_ui(msg, context);
            break;
        case 2:
            ret = set_third_screen_ui(msg, context);
            break;
        // Keep this
        default:
            PRINTF("Received an invalid screenIndex\n");
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}
