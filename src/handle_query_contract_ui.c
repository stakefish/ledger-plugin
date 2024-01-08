#include "plugin.h"

static bool set_ui(ethQueryContractUI_t *msg, context_t *context) {
    switch (context->selectorIndex) {
        case GOERLI_BATCH_DEPOSIT: 
            strlcpy(msg->title, "Staking Type", msg->titleLength);
            strlcpy(msg->msg, "Classic", msg->msgLength);
            break;
        case GOERLI_BATCH_CLAIM:
            strlcpy(msg->title, "Collect", msg->titleLength);
            strlcpy(msg->msg, "Rewards", msg->msgLength);
            break;
        default:
            strlcpy(msg->title, "Method not", msg->titleLength);
            strlcpy(msg->msg, "supported", msg->msgLength);
    }
    return true;
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
            ret = set_ui(msg, context);
            break;
        // Keep this
        default:
            PRINTF("Received an invalid screenIndex\n");
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}
