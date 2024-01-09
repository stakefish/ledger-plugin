#include "plugin.h"

static void handle_collect_reward(ethPluginProvideParameter_t *msg, context_t *context) {
    switch (context->next_param) {
        case GOERLI_COLLECT_REWARD:  
            copy_address(context->beneficiary, msg->parameter, sizeof(context->beneficiary));
            context->next_param = AMOUNT_REQUESTED;
            break;
        case AMOUNT_REQUESTED: 
            copy_parameter(
                context->amount_requested,
                msg->parameter,
                sizeof(context->amount_requested)
            );
            break;
        // Keep this
        default:
            PRINTF("Param not supported: %d\n", context->next_param);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_provide_parameter(ethPluginProvideParameter_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    // We use `%.*H`: it's a utility function to print bytes. You first give
    // the number of bytes you wish to print (in this case, `PARAMETER_LENGTH`) and then
    // the address (here `msg->parameter`).
    PRINTF("plugin provide parameter: offset %d\nBytes: %.*H\n",
           msg->parameterOffset,
           PARAMETER_LENGTH,
           msg->parameter);

    msg->result = ETH_PLUGIN_RESULT_OK;

    // EDIT THIS: adapt the cases and the names of the functions.
    switch (context->selectorIndex) {
        case GOERLI_BATCH_DEPOSIT:
            break;
        case GOERLI_BATCH_CLAIM:
            break;
        case GOERLI_MINT:
            copy_parameter(
                context->nfts,
                msg->parameter,
                sizeof(context->nfts)
            );
            break;
        case GOERLI_REQUEST_EXIT:
            break;
        case GOERLI_COLLECT_REWARD:
            handle_collect_reward(msg, context);
            break;
        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}
