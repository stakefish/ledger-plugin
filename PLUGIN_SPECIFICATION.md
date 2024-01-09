# Technical Specification

## About

This plugin allows the use of the smart contracts of stakefish.

## Smart Contracts

Smart contracts covered by the plugin shall be described here:

| Network | Version | Smart Contract | Address                                      |
| ------- | ------- | -------------- | -------------------------------------------- |
| Goerli  | V1      | Batch Deposit  | `0x0fa7c8350c8f028bc55899dbc1446ecd342958fe` |
| Goerli  | V1      | Mint           | `0x5B41FFB9C448C02Ff3D0401b0374b67EFcB73C7E` |
| Goerli  | V1      | Request Exit   | `0xC57beAe054B45Bb49B65b42C49c6f4b010f976e5` |
| Goerli  | V1      | Rewards        | `0x51a80650305cdA7c74F40347E47d6e318a91dE9F` |
| Goerli  | V1      | Rewards        | `0x51a80650305cdA7c74F40347E47d6e318a91dE9F` |
| Goerli  | V1      | Rewards        | `0x51a80650305cdA7c74F40347E47d6e318a91dE9F` |

## Functions

For the smart contracts implemented, the functions covered by the plugin shall be described here:

| Contract      | Function            | Selector     | Displayed Parameters                                                                                                                                               |
| ------------- | ------------------- | ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Batch Deposit | batchDeposit        | `0xc82655b7` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| Mint          | mint                | `0xa0712d68` | <table><tbody> <tr><td><code>NFT amount</code></td></tr> </tbody></table>                                                                                          |
| Request Exit  | requestExit         | `0x7f8e3b4e` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| Rewards       | batchCollectReward  | `0x3ec0c7b5` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| Rewards       | collectReward       | `0x1bc1f6e1` | <table><tbody> <tr><td><code>Beneficiary</code></td></tr> <tr><td><code>Request amount</code></td></tr> </tbody></table>                                           |
| Rewards       | collectRewardForNFT | `0x58f2b964` | <table><tbody> <tr><td><code>Beneficiary</code></td></tr> <tr><td><code>NFT wallet</code></td></tr> <tr><td><code>Request amount</code></td></tr> </tbody></table> |
