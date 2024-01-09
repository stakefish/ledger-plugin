#include "plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;

    // EDIT THIS: Set the total number of screen you will need.
    msg->numScreens = 1;
    if (context->selectorIndex == GOERLI_COLLECT_REWARD) {
        msg->numScreens = 2;
    }
    if (context->selectorIndex == GOERLI_COLLECT_REWARD_FOR_NFT) {
        msg->numScreens = 3;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
