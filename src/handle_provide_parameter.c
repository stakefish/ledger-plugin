#include "plugin.h"

static void handle_collect_reward(ethPluginProvideParameter_t *msg, context_t *context) {
    switch (context->next_param) {
        case BENEFICIARY:  
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

static void handle_collect_reward_for_nft(ethPluginProvideParameter_t *msg, context_t *context) {
    switch (context->next_param) {
        case BENEFICIARY:  
            copy_address(context->beneficiary, msg->parameter, sizeof(context->beneficiary));
            context->next_param = NFT_WALLET;
            break;
        case NFT_WALLET:  
            copy_address(context->nft_wallet, msg->parameter, sizeof(context->nft_wallet));
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
        case BATCH_DEPOSIT:
            break;
        case BATCH_COLLECT_REWARD:
            break;
        case MINT:
            copy_parameter(
                context->nfts,
                msg->parameter,
                sizeof(context->nfts)
            );
            break;
        case COLLECT_REWARD:
            handle_collect_reward(msg, context);
            break;
        case COLLECT_REWARD_FOR_NFT:
            handle_collect_reward_for_nft(msg, context);
            break;
        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}
