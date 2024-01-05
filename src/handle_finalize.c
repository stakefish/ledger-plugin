#include "plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    msg->uiType = ETH_UI_TYPE_GENERIC;

    // EDIT THIS: Set the total number of screen you will need.
    msg->numScreens = 1;

    msg->result = ETH_PLUGIN_RESULT_OK;
}
