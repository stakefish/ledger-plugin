#include "plugin.h"

// Sets the first screen to display.
void handle_query_contract_id(ethQueryContractID_t *msg) {
    const context_t *context = (const context_t *) msg->pluginContext;
    // msg->name will be the upper sentence displayed on the screen.
    // msg->version will be the lower sentence displayed on the screen.

    // For the first screen, display the plugin name.
    strlcpy(msg->name, APPNAME, msg->nameLength);

    // EDIT THIS: Adapt the cases by modifying the strings you pass to `strlcpy`.
    switch (context->selectorIndex) {
        case GOERLI_BATCH_DEPOSIT:
            strlcpy(msg->version, "Stake", msg->versionLength);
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        case GOERLI_BATCH_CLAIM:
            strlcpy(msg->version, "Claim", msg->versionLength);
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        case GOERLI_MINT:
            strlcpy(msg->version, "Mint", msg->versionLength);
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        default:
            PRINTF("Selector index: %d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
}
