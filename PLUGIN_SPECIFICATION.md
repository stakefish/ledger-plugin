# Technical Specification

## About

This plugin allows the use of the smart contracts of stakefish.

## Smart Contracts

Smart contracts covered by the plugin shall be described here:

| Network | Version | Smart Contract | Address                                      |
| ------- | ------- | -------------- | -------------------------------------------- |
| Mainnet | V1      | Batch Deposit  | `0x0194512e77d798e4871973d9cb9d7ddfc0ffd801` |
| Mainnet | V1      | NFT Manager    | `0xFFff2d93C83D4c613ed68CA887f057651135e089` |
| Mainnet | V1      | Rewards        | `0xfFEE087852cb4898e6c3532E776e68BC68b1143B` |
| Goerli  | V1      | Batch Deposit  | `0x0FA7C8350c8F028BC55899DBC1446eCD342958fE` |
| Goerli  | V1      | NFT Manager    | `0x5B41FFB9C448C02Ff3D0401b0374b67EFcB73C7E` |
| Goerli  | V1      | Rewards        | `0x51a80650305cdA7c74F40347E47d6e318a91dE9F` |
| Holesky | V1      | Batch Deposit  | `0xe876FF5DAe83cd04484Dd7d590b06E28Ac31F248` |
| Holesky | V1      | NFT Manager    | `0x958f1D3E202CA7E6E6AC7EFE1AB99F80237E9a32` |
| Holesky | V1      | Rewards        | `0xe876FF5DAe83cd04484Dd7d590b06E28Ac31F248` |

## Functions

For the smart contracts implemented, the functions covered by the plugin shall be described here:

| Contract      | Function            | Selector     | Displayed Parameters                                                                                                                                               |
| ------------- | ------------------- | ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Batch Deposit | batchDeposit        | `0xc82655b7` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| NFT Manager   | mint                | `0xa0712d68` | <table><tbody> <tr><td><code>NFT amount</code></td></tr> </tbody></table>                                                                                          |
| NFT Manager   | multicall           | `0x7f8e3b4e` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| Rewards       | batchCollectReward  | `0x3ec0c7b5` | <table><tbody> <tr><td><code>none</code></td></tr> </tbody></table>                                                                                                |
| Rewards       | collectReward       | `0x1bc1f6e1` | <table><tbody> <tr><td><code>Beneficiary</code></td></tr> <tr><td><code>Request amount</code></td></tr> </tbody></table>                                           |
| Rewards       | collectRewardForNFT | `0x58f2b964` | <table><tbody> <tr><td><code>Beneficiary</code></td></tr> <tr><td><code>NFT wallet</code></td></tr> <tr><td><code>Request amount</code></td></tr> </tbody></table> |
