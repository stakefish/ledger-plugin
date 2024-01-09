from pathlib import Path
import json
import os

import datetime

from web3 import Web3
from eth_typing import ChainId

from ledger_app_clients.ethereum.client import EthAppClient, StatusWord
from ledger_app_clients.ethereum.utils import get_selector_from_data
from ragger.navigator import NavInsID

from .utils import get_appname_from_makefile


ROOT_SCREENSHOT_PATH = Path(__file__).parent
ABIS_FOLDER = "%s/abis" % (os.path.dirname(__file__))

PLUGIN_NAME = get_appname_from_makefile()

with open("%s/0x51a80650305cdA7c74F40347E47d6e318a91dE9F.abi.json" % (ABIS_FOLDER)) as file:
    contract = Web3().eth.contract(
        abi=json.load(file),
        # Get address from filename
        address=bytes.fromhex(os.path.basename(file.name).split(".")[0].split("x")[-1])
    )

def test_batch_collect_reward(backend, firmware, navigator, test_name):
    client = EthAppClient(backend)

    # values taken from https://goerli.etherscan.io/tx/0x535fac3576648e7eeb266dc1af497367578b187857b29b6720d7b42d3d0c0e39
    data = contract.encodeABI(
        fn_name="batchCollectReward",
        args=[
            "0x0d12e640610a915B405345De0Df2655782A5e588",
            [
                "0x0d12e640610a915B405345De0Df2655782A5e588",
                "0x02e8d9309C81119b0C4066a5bA2340A9E4852441"
            ],
            [
                136903509674576,
                136903509674576
            ]
        ],
    )

    # first setup the external plugin
    with client.set_external_plugin(PLUGIN_NAME,
                                    contract.address,
                                    # Extract function selector from the encoded data
                                    get_selector_from_data(data)):
        pass

    # send the transaction
    with client.sign("m/44'/60'/1'/0/0", {
             "nonce": 20,
             "maxFeePerGas": Web3.to_wei(145, "gwei"),
             "maxPriorityFeePerGas": Web3.to_wei(1.5, "gwei"),
             "gas": 173290,
             "to": contract.address,
             "value": Web3.to_wei(0, "ether"),
             "chainId": ChainId.GOR,
             "data": data
         }):

        # Validate the on-screen request by performing the navigation appropriate for this device
        if firmware.device.startswith("nano"):
            navigator.navigate_until_text_and_compare(NavInsID.RIGHT_CLICK,
                                                      [NavInsID.BOTH_CLICK],
                                                      "Accept",
                                                      ROOT_SCREENSHOT_PATH,
                                                      test_name)
        else:
            navigator.navigate_until_text_and_compare(NavInsID.USE_CASE_REVIEW_TAP,
                                                      [NavInsID.USE_CASE_REVIEW_CONFIRM,
                                                       NavInsID.USE_CASE_STATUS_DISMISS],
                                                      "Hold to sign",
                                                      ROOT_SCREENSHOT_PATH,
                                                      test_name)

def test_collect_reward(backend, firmware, navigator, test_name):
    client = EthAppClient(backend)

    # values taken from https://goerli.etherscan.io/tx/0x535fac3576648e7eeb266dc1af497367578b187857b29b6720d7b42d3d0c0e39
    data = contract.encodeABI(
        fn_name="collectReward",
        args=[
            "0x9308245A3Ca756b506fa1D3a1962b5a563F92470",
            12
        ],
    )

    # first setup the external plugin
    with client.set_external_plugin(PLUGIN_NAME,
                                    contract.address,
                                    # Extract function selector from the encoded data
                                    get_selector_from_data(data)):
        pass

    # send the transaction
    with client.sign("m/44'/60'/1'/0/0", {
             "nonce": 20,
             "maxFeePerGas": Web3.to_wei(145, "gwei"),
             "maxPriorityFeePerGas": Web3.to_wei(1.5, "gwei"),
             "gas": 173290,
             "to": contract.address,
             "value": Web3.to_wei(0, "ether"),
             "chainId": ChainId.GOR,
             "data": data
         }):

        # Validate the on-screen request by performing the navigation appropriate for this device
        if firmware.device.startswith("nano"):
            navigator.navigate_until_text_and_compare(NavInsID.RIGHT_CLICK,
                                                      [NavInsID.BOTH_CLICK],
                                                      "Accept",
                                                      ROOT_SCREENSHOT_PATH,
                                                      test_name)
        else:
            navigator.navigate_until_text_and_compare(NavInsID.USE_CASE_REVIEW_TAP,
                                                      [NavInsID.USE_CASE_REVIEW_CONFIRM,
                                                       NavInsID.USE_CASE_STATUS_DISMISS],
                                                      "Hold to sign",
                                                      ROOT_SCREENSHOT_PATH,
                                                      test_name)